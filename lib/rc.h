// all-c - rc.h

#ifndef RC_H
#define RC_H

#include <stdint.h>
#include <stdlib.h>

#define RC_VERSION "0.1.0"

typedef struct {
  void *val;
  void (*free_fn)(void *);
  size_t count;
} RcRaw;

/// A reference counted pointer. When taking a refernece to this type use
/// `rc_copy`.
typedef struct {
  RcRaw *raw;
} RcAny;

typedef void (*RcFreeFn)(void *);

#define Rc(TYPE) Rc_##TYPE

#define RC_DEFINE(TYPE) \
  typedef struct { \
    RcAny any; \
  } Rc(TYPE);

RC_DEFINE(char)
/*
RC_DEFINE(bool)
RC_DEFINE(size_t)
RC_DEFINE(ssize_t)
RC_DEFINE(int8_t)
RC_DEFINE(int16_t)
RC_DEFINE(int32_t)
RC_DEFINE(int64_t)
RC_DEFINE(uint8_t)
RC_DEFINE(uint16_t)
RC_DEFINE(uint32_t)
RC_DEFINE(uint64_t)
*/

#define rc_new(TYPE, VAL, FREE_FN) \
  (rc_from_any(TYPE, rc_any_new((void *)VAL, FREE_FN)))

#define rc_from_raw(TYPE, RAW) (rc_from_any(TYPE, rc_any_from_raw(RAW)))

#define rc_from_any(TYPE, ANY) ((Rc(TYPE)){.any = ANY})

#define rc_raw_val(RC) (rc_any_val((RC).any))

#define rc_val(TYPE, RC) (rc_any_as(TYPE, (RC).any))

#define rc_copy(RC) ((typeof(RC)){.any = rc_any_copy((RC).any)})

#define rc_copy_ref(RC_REF) \
  ((typeof(*(RC_REF))){.any = rc_any_copy((RC_REF)->any)})

#define rc_free(RC) (rc_any_free((RC).any))

#define rc_dec(RC) (rc_any_dec((RC).any))

/// Gets the value of `RC` as `TYPE`.
#define rc_any_as(TYPE, RC) ((TYPE *)rc_any_val(RC))

#define rc_any_from_raw(RAW) ((RcAny){.raw = RAW})

/// Gets the value of `RC`.
#define rc_any_val(RC) (RC.raw->val)

/// Makes a copy from a reference to an `RcAny`.
#define rc_any_copy_ref(RC_REF) rc_any_copy((RcAny){.raw = RC_REF->raw})

/// Creates a new `RcAny`.
RcAny rc_any_new(void *val, RcFreeFn free_fn);

/// Copys `rc` and increments its count.
RcAny rc_any_copy(RcAny rc);

/// Decrements the count of `rc` and frees it if the count hits 0.
void rc_any_free(RcAny rc);

/// Decrements the count of `rc` WITHOUT freeing it if the count hits 0. Use
/// carefully.
void rc_any_dec(RcAny rc);

#define RC_IMPL
#ifdef RC_IMPL

#include <string.h>

RcAny rc_any_new(void *val, void (*free_fn)(void *)) {
  RcRaw *raw = (RcRaw *)malloc(sizeof(RcRaw));
  memcpy(
    raw,
    &(RcRaw){
      .val = val,
      .free_fn = free_fn,
      .count = 1,
    },
    sizeof(RcRaw)
  );

  return (RcAny){.raw = raw};
}

RcAny rc_any_copy(RcAny rc) {
  rc.raw->count++;
  return rc;
}

void rc_any_free(RcAny rc) {
  rc_any_dec(rc);
  if (rc.raw->count == 0) {
    rc.raw->free_fn(rc.raw->val);
    free(rc.raw);
  }
}

void rc_any_dec(RcAny rc) {
  if (rc.raw->count) {
    rc.raw->count--;
  }
}

#endif
#endif
