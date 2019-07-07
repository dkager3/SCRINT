# SCRINT Documentation
Welcome! Please view the documentation for SCRINT down below.

## What is SCRINT?
SCRINT is the Screw Interpreter. Screw is a Turing Complete programming language that is very closely modeled after Brainf\*\*k. How Screw differs is that it it has some different symbols, has a generally larger cell capacity (set at 60,000 bytes by default), and has a termination character for the end of programs.

## How is Screw Interpreted?
Screw is interpreted through a program written in C. Screw files are saved with an extention of ".scw" and the interpreter will handle only those types of files. The file is read by the interpreter, reduced down to essential operations (ignoring all other non-essential characters), then each operation is handled one at a time and turned into C code to run behind the scene.

## Screw
Screw has nine (9) reserved symbols that are strictly for coding. These symbols may not be used in a file, except to perform an operation:
1. '+'
2. '-'
3. '{'
4. '}'
5. '?'
6. '.' 
7. '<'
8. '>'
9. '~'
