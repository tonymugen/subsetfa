# Overview

This is a small utility that extracts records from a FASTA file based on names provided in a list file. Depends only on a compiler that supports C++-14 and `cmake` version 3.21 or later.

# Download and install

Clone the repository

```sh
git clone https://github.com/tonymugen/subsetfa
```

Next, create a build directory

```sh
cd subsetfa
mkdir build
```

Run cmake

```sh
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
cmake --install .
```

Installation may require root privileges.

# Tests

Optionally, one can also build the unit tests. These require [Catch2](https://github.com/catchorg/Catch2), although its installation is taken care of by `cmake`. To build the tests, create a `build-Tests` directory, say, and run

```sh
cd build
cmake -DCMAKE_BUILD_TYPE=Test -DBUILD_TESTS=ON ..
cmake --build .
```

To run the tests from the build directory, simply run

```sh
./tests
```

# Run the tool

The binary is `subsetfa`. It requires a multi-sequence FASTA file and a list of FASTA headers for sequences to be extracted. Headers must match those in the target FASTA file exactly, those that do not match anything will be ignored. A name of the output FASTA file can also be provided. If not, the default name subset.fasta will be used. The order of records in the output will not necessarily be the same as in the original file. Running `subsetfa` without any arguments will print the command line flag syntax information. 

