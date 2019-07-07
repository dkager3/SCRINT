# SCRINT Documentation
Welcome! Please view the documentation for SCRINT down below.

## What is SCRINT?
SCRINT is the Screw Interpreter. Screw is a Turing Complete programming language that is very closely modeled after Brainf\*\*k. How Screw differs is that it it has some different symbols, has a generally larger cell capacity (set at 60,000 bytes by default), and has a termination character for the end of programs.

## How is Screw Interpreted?
Screw is interpreted through a program written in C. Screw files are saved with an extention of ".scw" and the interpreter will handle only those types of files. The file is read by the interpreter, reduced down to essential operations (ignoring all other non-essential characters), then each operation is handled one at a time and turned into C code to run behind the scene.

## Reserved Symbols
Screw has nine (9) reserved symbols that are strictly for coding. These symbols may not be used in a file, except to perform an operation:
1. '+' : Increment Cell by 1
2. '-' : Decrement Cell by 1
3. '{' : Begin Loop
4. '}' : End Loop
5. '?' : Input Char
6. '.' : Output Char
7. '<' : Shift One Cell Left
8. '>' : Shift One Cell Right
9. '~' : End File

## Syntax
Screw's syntax is near identical to Brainf\*\*k. The only real difference as of now is that you have to have a tilda (~) at the end of your program. For examples of Screw, you can check out the .scw files that I uploaded. The code is commented, however, a little difficult to follow since it the language is so low-level.

## Running Screw Code
**NOTE: SCRINT was developed to be run on a bash terminal**

To run Screw you will have to download the main.c file, then open your bash terminal and type the following: 
**gcc main.c -o scrint**

Hit enter and then then you will have an executable named scrint. Next make sure your Screw programs are in the same directory as your exectubale. Then in bash, just type:                                                                                                 **./scrint <your_file_here>.scw**

This will run your file and that is it! You can view version information if you wish by typing:                                         **./scrint -v**

## Future Work
