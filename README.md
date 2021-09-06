# (non newline) Character Counter with C Programming Language

Program to count the (non newline) characters in any file using two library functions:

Mapping.c: Counts the amount of characters in a file by mmaping the file to
memory and operating on the resulting array

Reading.c:  multiple pagesize chuncks ( determined with sysconf() ) and counting the new-lines in them.

