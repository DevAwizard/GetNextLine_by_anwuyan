# GetNextLine

## Description

The "Get Next Line" project is a coding challenge designed for learning purposes, focusing on developing a function in C that reads a line from a file descriptor. This project not only adds a practical tool to the programmer's toolkit but also introduces the concept of static variables in C programming. It emphasizes memory management, error handling, and adhering to specific coding standards. The goal is to create a function that can read from files and standard inputs line by line, enhancing understanding of file handling and dynamic memory allocation in C.

## Objectives

- This project aims to enrich your C programming toolkit by introducing a useful function, get_next_line, and teaching the concept of static variables.

## General Instructions

- The project must be written in C and adhere to coding standards.
- It should handle memory efficiently, without leaks or unexpected terminations.
- A Makefile with specific rules is required for compilation with flags -Wall, -Werror, and -Wextra.

## Mandatory Part

- Implement get_next_line to read lines from a file descriptor.
- The function must handle files and stdin, properly dealing with the end of file and errors by returning NULL.
- Include a prototype in get_next_line.h and any helper functions in get_next_line_utils.c.
- Compile with the flag -D BUFFER_SIZE=xx to test with different buffer sizes.

## Restrictions

- Usage of the libft library, lseek, and global variables is prohibited.

## Submission

- Submit through your assigned Git repository, ensuring correct file naming and organization for evaluation.
- This structure provides a concise yet detailed overview suitable for a markdown format, ensuring clarity and organization in your documentation.
