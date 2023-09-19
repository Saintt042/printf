#ifndef CUSTOM_IO_H
#define CUSTOM_IO_H

#include <unistd.h>  /* For read and write system calls */

/* Function prototypes */
int custom_read_integer(void);
void custom_print_integer(int number);

#endif /* CUSTOM_IO_H */
