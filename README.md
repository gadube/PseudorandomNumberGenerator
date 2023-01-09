# NAS Pseudorandom Number Generator

This is a wrapper for the randlc function used by the NAS Parallel Benchmarks Suite.

## Installation

```
mkdir build && cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=/path/to/install
make 
make install
```

## Generating files

Usage: ./prng [-hb] [-n NUM_VALS] [-o OUTFILE]
       -h          show this help menu
       -b          generate binary file
       -n <NUM>    the number of values to create (default = 2^25)
       -o <FILE>   give name to output file (default = pseudorandomnumbers.txt

For example, to generate a text file called `foo.txt` with 2048 random floats, run:
```
./prng -n 2048 -o foo.txt
```
