# Get next line (GNL) Documentation

This documentation outlines the journey of developing the Get Next Line (GNL) project, a program designed to read a line from a file descriptor efficiently. The project focuses on memory management, efficient read operations, and adherence to specific functional and non-functional requirements.

<img src="https://img.shields.io/badge/42-%23000000.svg?&style=for-the-badge&logo=42&logoColor=white" /> <img src="https://img.shields.io/badge/c-%23A8B9CC.svg?&style=for-the-badge&logo=c&logoColor=black" /> <img src="https://img.shields.io/badge/markdown-%23000000.svg?&style=for-the-badge&logo=markdown&logoColor=white" />

## Main challenges
Manage memory and read operations efficiently


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

### Step 2: Underestand the pseudocode

#### Initial Setup:
- Room (File): A messy room with toys scattered all over the floor. Each toy represents a character in the file you're reading from.
- Box (Buffer): You have a box where you'll collect toys. This is akin to the buffer where you temporarily store characters until you find a newline character.
- Cleaning Process (Reading): You start at one end of the room and begin picking up toys, moving systematically until you've cleaned up a complete line.

Imagine we have a text file with the following content:

```bash
Hello, world!
This is a test.
End of file.
```

Now, let's visualize the process of reading this file using get_next_line.

## Step-by-Step Visualization:
1. Start Cleaning (Reading from File): You begin at the door, picking up toys (characters) one at a time.
2. Finding a Break (Newline Character): As you clean, you're looking for a specific toy (the newline character \n). This represents the end of a line in your file.
  - If you find this toy, you've completed cleaning a line. You put all the toys (characters) you've collected into a box (buffer), mark the spot, and prepare to return the box's contents.
  - If the room is clean (end of file) but you haven't found this specific toy, you still return all toys collected so far because it's the end of the file.
3. Returning the Box (Returning the Line): Once you've collected all toys up to the specific toy (newline) or reached the end of the room (file), you return the box (a string of characters/line) to outside the room (the caller of the function).
4. Preparing for the Next Round (Static Variable): You mark where you stopped cleaning so that next time you start cleaning (calling get_next_line again), you begin right where you left off. This ensures that you don't start from the beginning of the room (file) again or miss any toys (characters).
5. Repeat Until Clean (EOF): Continue this process, cleaning one line at a time, until the room is entirely clean (the file has been completely read).

## Visual example

### Initial State: Preparing to Clean (Read)

- File Content (Our Room):
```bash
Hello, world!
This is a test.
End of file.
```
- Buffer (Our Box): Empty
- Static Variable (Our Memory of Where We Left Off): Not used yet

### First Call to get_next_line
- Start reading characters (picking up toys) until we encounter a \n (a special toy indicating a line break).
- Reading: `H e l l o , w o r l d ! \n`
- Buffer after Reading: `Hello, world!\n`
- Returned Line: `"Hello, world!\n"`
- Static Variable: Remembers position after the `\n`, ready to start from `"This is a test."` next time.

### Room State After First Clean

```bash
This is a test.
End of file.
```
### Second Call to get_next_line
- Continue from where we left off, starting at `"This is a test."`
- Reading: `T h i s i s a t e s t . \n`
- Buffer after Reading: `This is a test.\n`
- Returned Line: `"This is a test.\n"`
- Static Variable: Now at the start of `"End of file."`

### Room State After Second Clean
```bash
End of file.
```

### Third Call to get_next_line
- Starting at `"End of file."`
- Reading: `E n d o f f i l e`.
- Buffer after Reading: `End of file`. (Note: No newline character at the end because it's the end of the file.)
- Returned Line: `"End of file."` (Without a newline character because it's the end.)
- Static Variable: Indicates there's nothing more to read.

### Room (File) Is Now Clean
All lines have been read and returned by get_next_line. The process is visualized as cleaning a room by picking up toys (characters) until the room is completely clean (the file is fully read).


In addition, I just made a fun video where I explain how reading a file line by line works in programming, using a cool example called get_next_line. Imagine your computer is cleaning up a messy room, where each piece of mess is a piece of text from a file. Each time it cleans, it picks up the mess line by line until the room is all tidy - that's basically what get_next_line does with reading files!

I've used simple illustrations and animations to show you this process, making it super easy and fun to understand, especially if you're just getting started with coding or if you love seeing ideas come to life visually. By the end of the video, you'll get how this neat function remembers where it stopped cleaning, so it can start right back up in the right spot next time.

So, if you're curious about how files are read by a program, or just love a good visual story, check out my video. I promise it'll make learning about coding a little bit more fun!

[![Video Thumbnail](https://media.istockphoto.com/id/953970566/photo/making-a-child-responsible.jpg?s=612x612&w=0&k=20&c=tJ0eNQWncIFEkiADgwtNle8u54cYIVq04NC2mVrCpTY=)](https://ai.invideo.io/watch/B7wehUMGnXB)

---



