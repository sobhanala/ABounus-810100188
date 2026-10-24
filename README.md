# Farm Harvesting Refactoring Exercise

A C++ exercise in improving the structure and readability of a farm-harvesting program. The repository preserves three versions so the refactoring can be compared.

## Contents

- `Farm.cpp`: initial implementation.
- `Farm2.cpp`: intermediate revision.
- `Farm3.cpp`: separates input, row/column scoring, and harvesting into functions.

The final version reads the row and column counts followed by the grid values. It performs four greedy moves, choosing a row or column with the largest remaining sum, and prints the total harvested value. This is a greedy strategy; optimality is not established.

## Build and run

With a C++11-compatible compiler or newer:

```sh
g++ -std=c++11 -Wall -Wextra Farm3.cpp -o farm
./farm
```

On Windows, run `farm.exe`. Supply the dimensions and grid values on standard input. Compile each version separately because each is a standalone program.
