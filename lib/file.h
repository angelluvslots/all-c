// all-c - file.h

#ifndef FILE_H
#define FILE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_VERSION "0.1.0"

/// Attempts to read the contents of a file into a newly allocated string. Returns
/// `NULL` on failure.
char *file_read_to_string(const char *path);

// #define FILE_IMPL
#ifdef FILE_IMPL

char *file_read_to_string(const char *path) {
  FILE *file = fopen(path, "r");

  size_t cap = 256;
  size_t len = 0;
  char *result = NULL;

  if (file == NULL) {
    goto defer;
  }

  result = malloc(cap);
  if (result == NULL) {
    goto defer;
  };

  for (int ch = fgetc(file); ch != EOF; ch = fgetc(file)) {
    // Save an extra byte for '\0'
    if (len >= cap - 1) {
      cap *= 2;
      result = realloc(result, cap);
      if (result == NULL) {
        goto defer;
      }
    }
    result[len] = (char)ch;
    len++;
  }

  result[len] = 0;

defer:
  if (file != NULL) {
    fclose(file);
  }

  return result;
}

#endif
#endif
