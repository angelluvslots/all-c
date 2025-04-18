// all-c - ansi.h

#ifndef ANSI_H
#define ANSI_H

#define ANSI_VERSION "0.1.0"

#define ANSI_ESC "\x1b["
#define ANSI_RESET ANSI_ESC "m"
#define ANSI_SET(f) ANSI_ESC f "m"

#define ANSI_UP(n) ANSI_ESC #n "A"
#define ANSI_DOWN(n) ANSI_ESC #n "B"
#define ANSI_RIGHT(n) ANSI_ESC #n "C"
#define ANSI_LEFT(n) ANSI_ESC #n "D"

#define ANSI_POS(r, c) ANSI_ESC #r ";" #c "H"
#define ANSI_ROW(r) \
  ANSI_ESC #r ";" \
              "H"
#define ANSI_COL(c) ANSI_ESC ";" #c "H"
#define ANSI_POS_RESET \
  ANSI_ESC ";" \
           "H"

#define ANSI_CLEAR \
  ANSI_ESC "2" \
           "J"
#define ANSI_CLEAR \
  ANSI_ESC "2" \
           "J"

#define ANSI_BOLD ANSI_SET("1")
#define ANSI_ITALIC ANSI_SET("3")
#define ANSI_UNDERLINE ANSI_SET("4")
#define ANSI_STRIKETHROUGH ANSI_SET("9")

#define ANSI_NOT_BOLD ANSI_SET("22")
#define ANSI_NOT_ITALIC ANSI_SET("23")
#define ANSI_NOT_UNDERLINE ANSI_SET("24")
#define ANSI_NOT_STRIKETHROUGH ANSI_SET("29")

#define ANSI_BLACK ANSI_SET("30")
#define ANSI_RED ANSI_SET("31")
#define ANSI_GREEN ANSI_SET("32")
#define ANSI_YELLOW ANSI_SET("33")
#define ANSI_BLUE ANSI_SET("34")
#define ANSI_MAGENTA ANSI_SET("35")
#define ANSI_CYAN ANSI_SET("36")
#define ANSI_GRAY ANSI_SET("37")

#define ANSI_BG_BLACK ANSI_SET("40")
#define ANSI_BG_RED ANSI_SET("41")
#define ANSI_BG_GREEN ANSI_SET("42")
#define ANSI_BG_YELLOW ANSI_SET("43")
#define ANSI_BG_BLUE ANSI_SET("44")
#define ANSI_BG_MAGENTA ANSI_SET("45")
#define ANSI_BG_CYAN ANSI_SET("46")
#define ANSI_BG_GRAY ANSI_SET("47")

#define ANSI_DARK_GRAY ANSI_SET("90")
#define ANSI_BRIGHT_RED ANSI_SET("91")
#define ANSI_BRIGHT_GREEN ANSI_SET("92")
#define ANSI_BRIGHT_YELLOW ANSI_SET("93")
#define ANSI_BRIGHT_BLUE ANSI_SET("94")
#define ANSI_BRIGHT_MAGENTA ANSI_SET("95")
#define ANSI_BRIGHT_CYAN ANSI_SET("96")
#define ANSI_BRIGHT_WHITE ANSI_SET("97")

#define ANSI_BG_DARK_GRAY ANSI_SET("100")
#define ANSI_BG_BRIGHT_RED ANSI_SET("101")
#define ANSI_BG_BRIGHT_GREEN ANSI_SET("102")
#define ANSI_BG_BRIGHT_YELLOW ANSI_SET("103")
#define ANSI_BG_BRIGHT_BLUE ANSI_SET("104")
#define ANSI_BG_BRIGHT_MAGENTA ANSI_SET("105")
#define ANSI_BG_BRIGHT_CYAN ANSI_SET("106")
#define ANSI_BG_WHITE ANSI_SET("107")

#endif
