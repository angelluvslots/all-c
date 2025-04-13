# angelluvslots' c libs (all-c)

a collection of my header-only utility libraries i've made for various projects or for fun in c. i use c23 for everything by default, but that doesn't mean that most of it won't work on other versions of c.

## 📚 librarys

all libraries are located in `lib/` directory.

- **ansi.h:** ansi code formatting macros
- **rc.h:** simple, safe reference counting with generic type wrappers for safety and extendablility.
- **file.h:** file utilities. currently only has one function: `file_read_to_string`.

## ⭐ usage

if you're using a library that's just macros and type definitions, like `ansi.h`, all you have to do is `#include` it whereever you need, no extra steps need :3

otherwise, you need to define an implementation file for your all-c libraries, usually either `main.c` or a dedicated `all_c.c` file. it doesn't as long as it's a `.c` file and is included in your projects compilation.

in your selected file, include `all_c_impl.h` at the very top to mark this file as your implemenation file. under that, just include all of the all-c libraries you using, such as `file.h` or `rc.h`. aaand done! you can use your all-c libaries as much as you'd like >w<

### example
```c
// src/all_c.c
#include "all_c_impl.h"

#include "file.h"
#include "rc.h"
```

