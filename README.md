<p align="center">
  <img src="https://github.com/qingqingqingli/readme_images/blob/master/codam_logo.png" height='200'>
</p>

## get_next_line
***The aim of this project is to code a function that returns a line ending with a newline, read from a file descriptor.***

This project also introduces the concept of static variables in C programming.

## Technical considerations

- Allowed functions: *malloc*, *free*, *write*
- All heap allocated memory space must be properly freed when necessary

## How to test
> Run the following commands

```shell
$ git clone https://github.com/qingqingqingli/get_next_line.git
$ cd get_next_line
$ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 -o get_next_line main.c get_next_line.c get_next_line_utils.c
$ ./get_next_line test.txt
```
