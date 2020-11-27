# Huffman Coding

This is a small project which contains my implementation of the Huffman coding algorithm in C++.

## Prerequisites

The [GNU](https://gcc.gnu.org) C++ compiler (Or any other C++ compiler which supports C++11 and makefiles). The project also includes tests written with the Boost UTF library, and so this is required if the program is to be tested.

## How To Use

To build the entire project (including the test), run the following command:

```
make all
```

Alternatively, specific executables can be compiled:

```
make huffman
make huffman_tests
```

To include this work in another project, simply include the [huffman.h](headers/huffman.h) and [huffman.cpp](src/huffman.cpp) files within the project. The algorithm is implemented as a class, which is initialised by:

```c++
#include "huffman.h"

...

Huff obj_name(string_char_or_int_here);
```

### Testing

To test the project build the test suite as detailed above, and then run the executable `huffman_tests`.

## License

This project is licensed under the terms of the [Creative Commons Attribution 4.0 International Public license](License.md).
