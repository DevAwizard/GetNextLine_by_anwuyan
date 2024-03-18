# Get next line (GNL) Documentation

<img src="https://img.shields.io/badge/42-%23000000.svg?&style=for-the-badge&logo=42&logoColor=white" />
<img src="https://img.shields.io/badge/c-%23A8B9CC.svg?&style=for-the-badge&logo=c&logoColor=black" />
<img src="https://img.shields.io/badge/markdown-%23000000.svg?&style=for-the-badge&logo=markdown&logoColor=white" />


# Table of Contents

1. [Introduction](#introduction)
   - [Purpose and significance of the GNL project](#purpose-and-significance-of-the-gnl-project)

2. [Project Overview](#project-overview)
   - [What GNL is and its role in the 42 curriculum](#what-gnl-is-and-its-role-in-the-42-curriculum)

3. [Compliance with 42 Norms](#compliance-with-42-norms)
   - [Importance of coding standards and preparation steps to ensure compliance](#importance-of-coding-standards-and-preparation-steps-to-ensure-compliance)

4. [Chronological Development Process](#chronological-development-process)
   - [Initial Planning: Research and setup](#initial-planning-research-and-setup)
   - [Development Phases: Detailed account of coding, testing, and debugging phases](#development-phases-detailed-account-of-coding-testing-and-debugging-phases)
   - [Challenges and Solutions: Specific challenges encountered and how they were addressed](#challenges-and-solutions-specific-challenges-encountered-and-how-they-were-addressed)

5. [Evaluation Preparation](#evaluation-preparation)
   - [Mandatory](#mandatory)
       - [Norminette Compliance](#norminette-compliance)
       - [Compilation](#compilation)
       - [Error Management](#error-management)
       - [Tests](#tests)
       - [Bonus](#bonus)

6. [Learning Outcomes](#learning-outcomes)
   - [Technical and personal growth experienced through the project](#technical-and-personal-growth-experienced-through-the-project)
     
7. [Conclusion](#conclusion)
   - [Reflection on the project and its impact](#reflection-on-the-project-and-its-impact)

8. [Appendices](#appendices)
   - [Additional resources, code snippets, and acknowledgments](#additional-resources-code-snippets-and-acknowledgments)

## 1 Introduction

The Get Next Line (GNL) project is an essential part of the 42 School curriculum designed to challenge students by requiring them to create a C function that reads any valid file, line by line, until the end. This project not only tests students' understanding of file descriptors and static variables in C but also serves as a cornerstone for more complex projects that involve file manipulation and data processing.

## 2 Project Overview

GNL is about developing a function that efficiently manages memory and reads from a file descriptor. It's a project that epitomizes the journey of learning, implementing, and mastering low-level programming nuances. Adhering to the 42 norms, the project pushes students to write clean, maintainable, and efficient code, laying a strong foundation for their future as software engineers.

### 3 Compliance with 42 Norms

The 42 School norms are a set of coding standards that emphasize clarity, organization, and memory management. From the outset, ensuring compliance with these norms was paramount. This involved regular use of the Norminette tool to check the code and adhering to strict naming conventions and file organization practices.

## 4 Chronological Development Process

### Initial Planning

The project began with an extensive research phase, focusing on understanding file descriptors, static variables, and buffer management. This phase was crucial for laying the groundwork for the project's structure and approach.

### Development Phases

The journey of developing the Get Next Line project was both challenging and rewarding, marked by several phases of planning, execution, and refinement. Here’s a closer look at each step:

### Initial Planning

**Research**: The first step was a deep dive into understanding how file descriptors work in Unix-like systems and the intricacies of static variables in C. This research phase was crucial for grasping the core concepts needed to tackle the project.

**Design**: With a solid understanding of the project requirements, the next step was to outline a design that would not only meet the functionality demands but also adhere to the 42 norms. This involved sketching out the function prototype, determining the necessary helper functions, and planning for memory management and error handling.

### Development Phases

**Basic Implementation**: The coding journey began with implementing a basic version of Get Next Line that could read from a file and handle simple inputs. This phase focused on getting a minimal viable product up and running.

**Incremental Enhancements**: After establishing a basic implementation, the focus shifted to enhancing the function's efficiency, handling edge cases, and ensuring robust error handling. Each enhancement went through a cycle of coding, testing, and reviewing.

**Memory Management**: A significant portion of the development process was dedicated to ensuring efficient and leak-free memory management. This involved meticulous testing and the use of tools like Valgrind to detect and resolve memory leaks.

## 5 Evaluation Preparation

### Mandatory

#### Norminette Compliance

Your code must pass the norminette check without errors. Non-compliance results in immediate termination of the evaluation.

#### Compilation

The project should compile with the usual flags and -D BUFFER_SIZE. It must compile with and without this flag while always maintaining the -Wall -Wextra -Werror flags.

#### Error Management

- Conduct tests for error handling by passing an arbitrary file descriptor that cannot be read (e.g., 42) to get_next_line, which should return NULL.

```c
string = get_next_line(fd); // Instead of fd write a 42
	printf("Primera llamada %s", string);
	free(string);
```

- Check error management for read and malloc where you use these two functions.


#### Tests

- Provide a main function that tests the return value of get_next_line. It must return NULL in case of an error, or the read line -with a \n at the end (except for the last line of a file if it doesn't end with a \n).

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

./a.out | cat -e
```

- Test with various BUFFER_SIZE values:

**large > 1024**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2000 get_next_line.c get_next_line_utils.c
```

**small < 8 and 1**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=6 get_next_line.c get_next_line_utils.c
```

**exactly the size of the line being read**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=Write_here_the_exact_size get_next_line.c get_next_line_utils.c
```

**variance of one byte (+/-) from the line size**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=Depend_of_the_previous_digit_Write_here_the_exact_size get_next_line.c get_next_line_utils.c
```

- Read from stdin and a file.
```c
string = get_next_line(fd); // Instead of fd write a 0
	printf("Primera llamada %s", string);
	free(string);
```

- Handle long lines (> 2000 characters), short lines (< 4 characters, including single characters), and empty lines.

#### Bonus

- The bonus part is evaluated only if the mandatory part is perfect, meaning it is complete and passes all tests, including edge cases and misuse scenarios.
- Bonus criteria include handling multiple file descriptors with get_next_line and ensuring only one static variable is used.


### Challenges and Solutions

**Handling Edge Cases**: One of the most challenging aspects was dealing with various edge cases, such as empty files or files with exceptionally long lines. Solutions involved thorough testing and iterative adjustments to the logic.

**Memory Leak Prevention**: Ensuring that the project was free from memory leaks required a disciplined approach to memory allocation and deallocation. The challenge was met by adopting a systematic testing regimen and leveraging debugging tools.

**Norm Compliance**: Staying compliant with the 42 norms throughout the development process was challenging but essential. This was addressed by regularly running the Norminette tool and refining the code as needed.

## Learning Outcomes

The development of Get Next Line was a comprehensive learning experience that enhanced my understanding of file reading operations, memory management, and the importance of coding standards. Each challenge faced was an opportunity for growth, pushing me to develop more robust and efficient code.

## Conclusion

The Get Next Line project stands as a testament to the learning journey at 42. Through this project, I have not only advanced my technical skills but also developed a meticulous approach to problem-solving and project development. This documentation serves as a record of the challenges overcome and the knowledge gained, showcasing my progression in the 42 curriculum.


---
