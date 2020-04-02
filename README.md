# Simple_shell

Write a simple shell command line interpreter Unix in C

## Compile program

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Usage


### Interactive mode
`$ ./hsh
hsh$ /bin/ls
hsh main.c shell.c
hsh$
hsh$ exit
$ `

### Non-interactive mode
`$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
$`

## Files

### README.md
README file for project simple shell at Holberton School

### man_1_simple_shell
man page for simple shell project

### AUTHORS
Contributors and authors for this project

### shell.h
Header file for simple shell program

### shell.c
Program that runs simple shell included contain helper functions and built-ins

## `/tests`
Folder contains all tests

