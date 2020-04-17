# Simple_shell

Write a simple shell command line interpreter Unix in C

## Compile program

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Testing

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

## Output

Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh:
`$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$`

Same error with your program hsh:
`$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$`


## Files

### README.md
README file for project simple shell at Holberton School

### man_1_simple_shell
man page for simple shell project

### shell.h
Header file for simple shell program

### jw_shell.c
Program that runs simple shell included contain helper functions and built-ins

### _exit.c

### strtok.c

### built_int.c

### free_ptr.c

### env.c

### getline.c

### pr_prompt.c

### strcncat.c

### execve.c

### getpath.c

### _putchar.c

### str_functions.c

### AUTHORS
Contributors and authors for this project
* **Wilder Rincon** - *Initial work* - [wildcox80](https://github.com/wildcox80)
* **Jhonatan Angarita** - *Initial work*

### LICENSE
This project is licensed under the GPL License - see the [GPL 2.0](https://opensource.org/licenses/GPL-2.0) file for details

## tests
Folder contains all tests

