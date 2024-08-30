# 24bits Integers Implementation

### Introduction

This project aims to provide an implementation for converting various data types into 3-byte (24-bit) integers.
The current implementation supports conversions from the following data types:

- **`char` (1 byte):** Converts a single-byte character into a 3-byte representation.
- **`short` (2 bytes):** Converts a 2-byte integer into a 3-byte representation.
- **`long` (4 bytes):** Converts a 4-byte integer into a 3-byte representation.
- **`long long` (8 bytes):** Converts an 8-byte integer into a 3-byte representation.

The project is organized as requested..

```

├── cli.sh (bash script to automate compile)
├── CMakeLists.txt
├── inc (Include directory)
│   └── byte_conversion_utils.h
├── README.md
├── src (Source directory)
│   ├── byte_conversion_utils.c
│   └── main.c
└── test (N/A)
```

Although  the bonus implementation and corresponding tests are mentioned , they have not yet been implemented

### How to: Build, compile & run

To build and run the application, a bash script named `cli.sh` was developed to automate operations such as building, running the application, and cleaning the project.

**Usage example for build and run application:**

```
./cli.sh build && ./cli.sh run
```

Use the following command to see more options :

```
./cli.sh help
```

### Example output 

To verify the implementation, an example application was created that converts specific values to 3 bytes integers. The output logs represent the hex format of each data type before and after the conversion.

```
========================================= 
Example Application for 3 Bytes Conversion 
========================================= 
For char conversion Hex format: 0xff:
3 bytes conversion Hex format : 0x0000FF
For short conversion Hex format: 0x3039:
3 bytes conversion Hex format : 0x003039
For long conversion Hex format: 0x499602d2:
3 bytes conversion Hex format : 0x000049
3 bytes conversion Hex format : 0x9602D2
For long long conversion Hex format: 0x7048860ddf79:
3 bytes conversion Hex format : 0x704886
3 bytes conversion Hex format : 0x0DDF79

```

