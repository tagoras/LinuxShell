# LinuxShell

This project aims to implement a program that acts as a standard linux shell. The purpose of the project is to familiarise with the Unix programming interface (especially linux programming), C++ programming and SOLID programming principles.

This project is my way of stepping into the world of Linux system programming with C++. It will get more complicated as I uncover further system programming concepts. It also serves as a way to learn operating system concepts.

# Implemented Commands

Here is a list of commands that are currently supported by my shell command (The list is continiuosly being updated). Please look at the implementation for further details:

- cat
- cd
- chgrp
- chmod
- chown
- cp
- echo
- ld
- ln
- mkdir
- mount
- mv
- rm
- setid
- stat
- umount
- ls
- sleep

In terms of the shell command implementation, certain commands are easy to implement (at least their simple versions) such as (cd, chgrp, chown, mkdir etc.) but may have hidden caviets (especially when it comes to permissions which might be influenced by processes umask, or the file system mount options depending on what you are working with). Other commands such as mv are more lengthy (for example to implement moving a file to another file system which requires to copy the whole file as opposed to change the directory entries).

# Folder Structure

The header folder consists of several parts. It contains the class header files for the classes that are related to the execution of the program (ApplicationRunner.h, CommandManager.h, CommandParser.h, CommandPicker.h, ErrorManager.h, ICommand.h, UtilityFunctions.h) and are not seperate shell commands. Declaration for shell commands can be found inside the headers/CommandHeaders folder (each file is a separate command implementation).

Similarly, Cpps folder is divided into 2 parts. It contains the c++ implementation files for the classes that are related to the execution of the program. Implementations for particular shell commands can be found inside the Cpps/CommandImplementations

# Class Structure

- The main.cpp file initialises and object of type ApplicationRunner and uses the run() method
- ApplicationRunner.cpp is a class that is responsible for the control flow of the program. To do so, it contains other classes such as CommandParser, CommandPicker and ErrorManager.
- CommandParser is responsible for taking a line of input and returning a pair object that contains a command name and a vector of string arguments
- CommandPicker is responsible for providing an ICommand (discussed below) object based on the command
- ErrorManager retrieves a correct error string in case a command fails

- CommandPicker, which retrieves an ICommand object also contains CommandManager object.
- CommandManager object is used to store all the commands that the application can run.

- ICommand is an abstract class that declares one function called execute() any class inheriting from it has to override it. ICommand is inherited by every shell command implementation. It allows storing different
  command objects using shared pointers.

  # Building the project

  The project was meant for Linux operating system. To build the project please type to shell:
  ./build.sh
