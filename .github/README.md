# Step-by-Step Guide to Documenting a GNL Project Roadmap

A comprehensive documentation roadmap for a project outlines a structured plan to document each phase, from initiation to presentation to evaluators. 
It ensures thorough documentation of proposals, plans, progress, and performance, culminating in a detailed report for review. 
This roadmap enhances transparency, accountability, and project success, facilitating smooth execution and evaluation.

Table of contents

## 1. Read the Subject


## 1. Read the Subject

Understand the Requirements: Carefully read the project guidelines and objectives. Make sure you understand the expected outcomes, the scope of the project, and any specific requirements.

### Mandatory Part Requirements:
- Function Name: get_next_line
- Prototype: char *get_next_line(int fd);
- Files to Submit: get_next_line.c, get_next_line_utils.c, get_next_line.h
- Parameters: fd: The file descriptor from which to read.
- Return Value:
  - On success: The line that has been read.
  - On failure or when the reading has completed: NULL.
- Authorized Functions: read, malloc, free.
- Description: Write a function that returns a line read from a file descriptor.

- Additional considerations include:

  - Repeatedly calling your get_next_line function in a loop allows you to read the content of the file pointed to by the file descriptor line by line until the end.
  - The function should return the line that has just been read. If there is nothing more to read or an error occurs, it should return NULL.
  - Ensure your function behaves properly when reading from a file and when reading from stdin.
  - The returned line must end with a newline character ('\n'), except if it is the end of the file and this does not end with a newline character.
  - In the header get_next_line.h, you must have at least the prototype of the get_next_line function.
  - Add all the helper functions you need in the file get_next_line_utils.c.
  - Your program must compile with the flag -D BUFFER_SIZE=xx, which will be used to determine the buffer size for your get_next_line(). This parameter will be modified by your evaluators and Moulinette to test your program. You must be able to compile your project with and without the -D BUFFER_SIZE flag along with the usual flags. You can choose the default value you prefer.
  - Compilation example (using a buffer size of 42 as an example): cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <files>.c.
  get_next_line() is considered to have undefined behavior if the file pointed to by the fd has changed since the last call unless read() has reached the end of the file.
  - Reading from a binary file is considered undefined behavior for get_next_line(), but you may implement a logical workaround for this issue if you wish.
  - Your get_next_line function should attempt to read as little as possible each time it is called. If you find a newline, you should return the current line. Do not read the entire file and then process each line.

### Prohibited:
  - Usage of your libft in this project.
  - Usage of lseek.
  - Usage of global variables.

Any doubts?
- New concept --> static variables

## 2. Main objetive

The primary goal of the get_next_line function is to **read and return the next available line of text from a file specified by a file descriptor (fd)**. This is done by reading the file line by line. Here are some key points about the purpose and operation of get_next_line:

- **Read Line by Line**: It allows programs that use it to read a text file line by line, which is especially useful for large files or for reading from standard input (stdin), where it is not desirable or efficient to read the entire file at once.

- **Efficiency in Reading**: It is designed to be efficient by trying to read the smallest amount of data possible on each call, which helps to reduce memory usage and processing time, especially with large files.

- **Buffer Use**: The function uses a buffer size defined by BUFFER_SIZE to read data from the file. This buffer is a crucial part of how get_next_line manages data reading, allowing flexibility in the amount of data read in each read operation.

- **Flexibility**: The ability to compile the program with different values for BUFFER_SIZE offers flexibility, allowing the function to be adjusted to optimize reading efficiency based on the specific needs of the application or system resources.

- **Practical Applications**: get_next_line is useful in a variety of situations, such as reading configuration files line by line, processing log files, reading user input in interactive programs, or as part of more complex text processing tools.

In summary, get_next_line is a versatile and efficient tool for reading text files line by line, providing a solid foundation for a wide range of applications that require linear text processing.






