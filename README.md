This is an interpreter for a scripting language called vtscript.

The language handles logic operation, arithmetic operations, creation and storage of variables, and conditional and sequential execution of functions.

The language is written in prefix notation with parentheses surrounding executional blocks.

Examples of inputs:

(+ 1 2 3)
result = 6

(if (5 >= 3) (True) (False))
result = True

(begin (define answer (+ 9 11)) (answer))
result = 20

(begin (define answer 42)
(answer))
result = 42

Commands are tokenized and parsed into an execution tree. The commands are then recursively evaluated to a final result. 
Variables are stored in an environment map for the duration of the execution.

The goal of this project was to gain mastery of advanced C++ data structures and function pointers.

ECE 3574 Project 1
