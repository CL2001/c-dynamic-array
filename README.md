# C Vector (std::vector-like Implementation)

## Overview
This project implements a dynamic array in C that mimics the behavior of C++'s `std::vector`.

The goal is to provide:
- Automatic resizing
- Contiguous memory storage
- Efficient push/pop operations
- Generic usage via `void*`

---

## Features
- Dynamic resizing (capacity doubles when full)
- Push back (`vector_push_back`)
- Pop back (`vector_pop_back`)
- Random access (`vector_get`, `vector_set`)
- Size and capacity tracking
- Memory management (`vector_free`)

---

## Project Structure

.
├── include/
│   └── vector.h
├── src/
│   └── vector.c
├── main.c
├── Makefile
└── build/

---

## Build Instructions

To compile the project:

```bash
make
```

This will:
- Compile all source files
- Place the final binary in the `build/` directory

---

## Run the Program

```bash
./build/main
```

---

## Clean Build Files

```bash
make clean
```

---

## Design Notes

- Uses `void*` to support generic data types
- Stores element size to compute offsets
- Grows capacity exponentially (typically x2)
- Minimizes realloc calls for performance
