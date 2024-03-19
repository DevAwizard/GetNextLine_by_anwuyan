# Get next line (GNL) Documentation

This documentation outlines the journey of developing the Get Next Line (GNL) project, a program designed to read a line from a file descriptor efficiently. The project focuses on memory management, efficient read operations, and adherence to specific functional and non-functional requirements.

<img src="https://img.shields.io/badge/42-%23000000.svg?&style=for-the-badge&logo=42&logoColor=white" /> <img src="https://img.shields.io/badge/c-%23A8B9CC.svg?&style=for-the-badge&logo=c&logoColor=black" /> <img src="https://img.shields.io/badge/markdown-%23000000.svg?&style=for-the-badge&logo=markdown&logoColor=white" />

## Main challenges
Manage memory and read operations efficiently

# Table of Contents



## 1. Project Understanding and Initial Planning

The journey commenced with downloading and meticulously reading the project subject to fully grasp its objectives and constraints. 
This initial step was crucial in highlighting the project's core challenge: developing a get_next_line function capable of efficiently reading lines from a file descriptor with meticulous buffer management and memory handling. 
Emphasis was placed on understanding the requirements for managing the buffer size dynamically and ensuring robust memory allocation and deallocation practices to prevent leaks and optimize performance.

### Mandatory Part Requirements:
- **Function Name**: `get_next_line`
- **Prototype**: `char *get_next_line(int fd)`;
- **Files to Submit**: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`
- **Parameters**: `fd`: The file descriptor from which to read.
- **Return Value**:
  - **On success**: The line that has been read.
  - **On failure or when the reading has completed**: `NULL`.
- **Authorized Functions**: `read`, `malloc`, `free`.
- **Description**: Write a function that returns a line read from a file descriptor.

- Additional considerations include:
  - Repeatedly calling your get_next_line function in a loop allows you to read the content of the file pointed to by the file descriptor line by line until the end.
  - The function should return the line that has just been read. If there is nothing more to read or an error occurs, it should return NULL.
  - Ensure your function behaves properly when reading from a file and when reading from stdin.
  - The returned line must end with a newline character ('\n'), except if it is the end of the file and this does not end with a newline character.
  - In the header get_next_line.h, you must have at least the prototype of the get_next_line function.
  - Add all the helper functions you need in the file `get_next_line_utils.c`.
  - Your program must compile with the flag -D BUFFER_SIZE=xx, which will be used to determine the buffer size for your get_next_line(). This parameter will be modified by your evaluators and Moulinette to test your program. You must be able to compile your project with and without the -D BUFFER_SIZE flag along with the usual flags. You can choose the default value you prefer.
  - Compilation example (using a buffer size of 42 as an example): `cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <files>.c`.
  get_next_line() is considered to have undefined behavior if the file pointed to by the fd has changed since the last call unless read() has reached the end of the file.
  - Reading from a binary file is considered undefined behavior for get_next_line(), but you may implement a logical workaround for this issue if you wish.
  - Your get_next_line function should attempt to read as little as possible each time it is called. If you find a newline, you should return the current line. Do not read the entire file and then process each line.

### Prohibited:
  - Usage of your libft in this project.
  - Usage of lseek.
  - Usage of global variables.


## 2. Environment Setup

### Tools and Environment

The initial step in setting up the environment involved creating the essential files required for the project: `get_next_line.c`, `get_next_line_utils.c`, and `get_next_line.h`. 
This setup was critical for organizing the project's codebase and ensuring that each component of the program was modular and manageable. 
Additionally, the development environment was prepared to facilitate efficient coding and testing. This preparation included configuring a development workspace, which, depending on the project's needs, might involve using a virtual machine, setting up a local development environment on a personal computer, or utilizing cloud-based development environments. 
Installing necessary compilers and ensuring the development tools were up to date were key steps in this process, setting the stage for seamless project development and testing.

### Compilation Flags

An essential aspect of this project's setup was the requirement to ensure that the code could compile with the -D BUFFER_SIZE=xx compilation flag, allowing the buffer size to be defined at compile time. 
The focus was not on creating Makefile rules or shell scripts for compilation but rather on structuring the code to be compatible with this compilation approach. 
This meant writing the get_next_line function in such a way that it could adapt to any buffer size specified through this flag, without the need for additional configuration files like a Makefile for this specific purpose.

Ensuring compatibility with the `-D BUFFER_SIZE=xx` flag was pivotal for assessing the function's adaptability and performance under various buffer sizes, directly impacting its ability to efficiently manage memory and process lines of varying lengths. 
This requirement underscored the importance of flexible and dynamic memory management within the get_next_line function. By testing the code with different buffer sizes, it was possible to rigorously evaluate and fine-tune the memory allocation and buffer management strategies, guaranteeing that the final implementation was not only flexible but also optimized for efficiency and reliability.


## 3. Designing get_next_line

### Step 1: Understanding the Function Prototype
Your function prototype, char *get_next_line(int fd), indicates that your function will take a file descriptor (fd) as an argument and return a string representing the next line read from that file descriptor, or NULL if there's nothing more to read or an error occurs.

![image](https://github.com/DevAwizard/GetNextLine_anwuyan/assets/153505451/8e74a918-4ed4-4ba1-b86d-857db2b4a3c7)


---

