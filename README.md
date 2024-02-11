# printf
# Custom printf Implementation in C

This project is an implementation of the `printf` function in C, customized to support a subset of the format specifiers provided by the standard `printf` function. The primary goal is to understand how `printf` works internally and to implement a simplified version of it.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Supported Format Specifiers](#supported-format-specifiers)
- [Building](#building)
- [Contributing](#contributing)
- [License](#license)

## Features

- Custom `printf` implementation supporting a subset of format specifiers.
- Supports formatting of integers, floating-point numbers, characters, and strings.
- Basic width and precision formatting options are available.

## Usage

To use the custom `printf` function, include `custom_printf.h` in your C file:

```c
#include "custom_printf.h"
```

Then, call `custom_printf` in a manner similar to the standard `printf` function:

```c
custom_printf("Hello, %s! You are %d years old.\n", "Alice", 30);
```

## Supported Format Specifiers

- `%d` - for printing integers
- `%f` - for printing floating-point numbers
- `%c` - for printing characters
- `%s` - for printing strings
- and many others!

## Building

To build the project, clone the repository and compile the source files:

```bash
git clone https://github.com/sarah-kamall/printf.git
cd custom-printf
gcc -o main main.c custom_printf.c
```


