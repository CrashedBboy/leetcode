# C/C++ Learning Points

## C

* Compilation process
* Memory sections: stack, heap, BSS, data, text
* Variable lifecycle: local, static, global
* `extern` and forward-declaration
* Marcos (`#define`)
* Preprocessor directives: `#if`, `#elif`, `#else`,`#endif`, `#ifdef`, `#ifndef`
* Include guard
* Pointer
* Function pointer / callback functions
* Assertions
* Bit operations
* Console IO / File IO
    - Console: `printf`, `scanf`, `puts`, `putchar`, `getchar`
    - File: `fopen`, `fclose`, `fgets`, `fprintf`, `fscanf`
    - Note: `gets()` is deprecated since it has no length check and may cause buffer-overflow
* Struct & Union, and their alignment & padding
* Enum
* typedef
* `volatile`
* `const`
* Memory manipulation:
    - allocation: malloc, realloc, calloc, free
    - byte-level: memcpy, memset,, memcmp
* String handling (in string.h)
    - manipulation: `strcpy`, `strncpy`, `strcat`, `strncat`
    - inspection: `strlen`, `strcmp`, `strncmp`
    - searching: `strchr`, `strrchr`, `strstr`
* Other standard library functions
    - `atoi`, `atof`, `abs`
* GDB debugging

## C++
* OOP
    - Inheritance, order of object construction/destruction
    - Diamond inheritance problem & virtual inheritance
    - Overriding
    - Overloading
    - Encapsulation: `public`, `protected`, `private`, default access specifier
    - Abstraction: pure virtual function
    - Runtime Polymorphism: virtual function
    - Good practice: virtual destructor of base class
    - `friend` specifier
    - constructor initializer
    - `final` specifier
* reference, pass-by-reference
* `nullptr`
* EnumClass
* template
* Smart pointers
* Lambda
* STL Containers
* string
* New/Delete vs. Malloc/free
* Exception
* IPC: pipe, shared memory, socket
* Multi-thread programming
    - thread create, join, detach
    - mutex
    - semaphore
    - spinlock
* Uniform Initialization
* `auto`, `decltype`
* `constexpr`
* Range-based for-loops (e.g. `for (auto& i : list) { ... }`)



## Reference
* [C 語言考古題](https://hackmd.io/@JJJJJJ/Sk4s24gIT)
* [C/C++ - 常見 C 語言觀念題目總整理（適合考試和面試） | Mr. Opengate ](https://www.mropengate.com/2017/08/cc-c.html)
* [A cheatsheet of modern C++ language and library features](https://github.com/CrashedBboy/modern-cpp-features)
