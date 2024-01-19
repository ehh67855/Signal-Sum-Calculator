# Signal Sum Calculator

This C program is designed to handle signals and process numerical input, accumulating a sum of the entered double values. It handles specific signals sent to the process and implements a timeout functionality.

## Features

- **Signal Handling**: Custom handling of UNIX signals (specifically signals 8, 10, and 12), along with an alarm signal.
- **Input Processing**: Accepts double values as input, either from the terminal or file redirection, and calculates their cumulative sum.
- **Timeout Functionality**: The program automatically terminates after 90 seconds using an alarm signal.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You need a C compiler (like GCC) installed on your system. You can check if GCC is installed by typing the following command in your terminal:

```bash
gcc --version
```

## Installing

Clone the repository to your local machine:

```bash
git clone https://github.com/ehh67855/Signal-Sum-Calculator.git
```
**Navigate to the cloned directory:**
```bash
cd SignalSumCalculator
```
**Use the provided Makefile to compile the program:**
```bash
make compile
```
## Usage
Run the program:

```bash
make run
```
You can then enter double values. The program will sum these values. To terminate the program, you can either:

Wait for 90 seconds for the program to auto-terminate.
Send one of the handled signals to the program using kill -signal_number process_id.
## Cleaning Up
To remove the compiled output, run:
```bash
make clean
```
