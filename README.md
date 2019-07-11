# SCRINT 2.0 Documentation
Welcome! Please view the documentation for SCRINT down below.

*Here is a link to the Screw [wiki](https://esolangs.org/wiki/Screw)**

## What is SCRINT?
SCRINT is the Screw Interpreter. Screw is a programming language that is closely modeled after Brainf\*\*k. How Screw differs is that it has some different symbols, extra features, and has a termination character for the end of programs.

## How is Screw Interpreted?
Screw is interpreted through a program written in C. Screw files are saved with an extention of ".scw" and the interpreter will handle only those types of files. The file is read by the interpreter, reduced down to essential operations (ignoring all other non-essential characters), then each operation is handled one at a time and turned into C code to run behind the scene.

## Screw Recognized Symbols
1.  '+'  :  Increment Cell by 1
2.  '-'  :  Decrement Cell by 1
3.  '{'  :  Begin Loop
4.  '}'  :  End Loop
5.  '?'  :  Input Char
6.  '.'   :  Output Char
7.  '<'  :  Shift One Cell Left
8.  '>'  :  Shift One Cell Right
9.  '\*'  : Cell Dump (See Features Below)
10. '^'  : Enumeration symbol (as in 0 to 5)
11. 0-9  : Numbers 0 through 9
12. 'A'  : Add Given Number to Current Cell
13. 'S'  : Subtract Given Number From Current Cell
12. ';'  : Comment
13. '~'  :  End File

## Screw Syntax
Screw's syntax is similar to Brainf\*\*k. You must have a tilda (~) at the end of your program and commenting is done with a semi-colon (;). For examples of Screw, you can check out the .scw files that I uploaded.

## Screw Features
- Screw has a feature known as "cell dump". This feature allows the user to output multiple adjacent cells by giving a lower bound and an upper bound. After that, each of the cells "dumped" are then wiped and reset to their default value (0). An example of cell dumping: **\*0^6** will output the contents of cells 0 through 6, then wipe the contents. **Note: Cell dumping only works for cells 0-9.**
- Screw has commenting. This feature allows only for single-line commenting and is done by using a semi-colon (;)
- Screw can add a given number to a cell. An example is: **A48** which adds 48 to the current cell.
- Screw can subtract a given number from a cell. An example is **S2** which subtracts 2 from the current cell.

## Running Screw Code
**NOTE: SCRINT was developed to be run on a bash terminal**

To run Screw you will have to download the main.c and make files from the "Interpreter" folder in this repo, then open your bash terminal in the same directory as the files you downloaded. Then type the following: 
**make**

Hit enter and then then you will have an executable named "scrint". Next make sure your Screw programs are in the same directory as your scrint exectubale. Then in bash, just type:                                                                                                 **./scrint <your_file_here>.scw**

There are sample Screw programs in the "Programs" folder of this repo.

This will run your file and that is it! You can view version information if you wish by typing:                                         **./scrint -v**
