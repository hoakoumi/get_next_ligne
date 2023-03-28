                                                              # get_next_ligne
                                                                
The goal of this project is to create a function that returns a line read from a file descriptor using the read function and the concept of static variables.

                                                              # Static variable
A static variable is a variable that is declared using the static keyword inside a function or at the file level in a C or C++ program. When a variable is declared as static, it is allocated a fixed amount of memory that persists throughout the lifetime of the program. Static variables declared inside a function are different from local variables declared inside the function. Unlike local variables, static variables are not destroyed when the function exits. Instead, they retain their values across multiple function calls.

                                                              # Read function
The read function is a system call in Unix and Unix-like operating systems that is used to read data from a file descriptor. The function prototype for read is defined in the unistd.h header file and has the following form: 
                                            ssize_t read(int fd, void *buf, size_t count);
Here's what each of the parameters mean:

fd: The file descriptor to read from. This can be a file descriptor obtained by opening a file using open, or a file descriptor associated with a device, such as a terminal or network socket.

buf: A pointer to a buffer where the data read from the file will be stored.

count: The maximum number of bytes to read from the file.

The read function returns the number of bytes read from the file, or -1 if an error occurs. If the return value is 0, it means that the end of the file has been reached.
