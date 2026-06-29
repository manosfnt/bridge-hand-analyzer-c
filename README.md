# Bridge Hand Analyzer in C

A command-line C application for analyzing Bridge hands.

## Features

- Reads Bridge hands from keyboard input
- Reads hands from text files
- Displays cards by suit
- Calculates High Card Points (HCP)
- Calculates declarer points
- Checks whether a hand has a balanced distribution
- Suggests an opening bid
- Saves formatted hand data to a text file

## Project Structure
- `bridge_file_operations.c` – Function and data structures 
- `data/` – Sample input files

## Input Format

The first line contains the number of hands.

Each following line contains 13 cards, for example:

```text
4
6H 5H 4H 3H 2H 4S 3S 2S 5D 4D 3D AC KC# bridge-hand-analyzer-c
