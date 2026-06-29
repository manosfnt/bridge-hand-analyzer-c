# Bridge Hand Helper Functions in C

This repository contains a collection of helper functions written in C for processing and analyzing Bridge hands.

The code was developed as part of a programming assignment and is intended to be used together with a separate `main()` program provided externally.

## Features

The implemented functions can:

- Read Bridge hands from user input
- Read Bridge hands from a text file
- Display cards grouped by suit
- Calculate High Card Points (HCP)
- Calculate declarer points
- Check whether a hand has a balanced distribution
- Suggest an opening bid
- Save formatted hand data to a text file

## Files

- `bridge_file_operations.c` – Contains the helper functions for Bridge hand processing and file operations.
- `a.txt` – Sample input file with Bridge hands.
- `b.txt` – Additional sample input file.

## Important Note

This repository does not include a `main()` function.

The functions are designed to be integrated into a larger C program that handles the program flow and user commands.

## Sample Input Format

The first line contains the number of Bridge hands. Each following line contains 13 cards.

```text
4
6H 5H 4H 3H 2H 4S 3S 2S 5D 4D 3D AC KC
