#include "custom_io.h"  /* Include the custom header file */
#include <unistd.h>     /* For read and write system calls */

/* Custom function to read an integer */
int custom_read_integer(void) {
    char buffer[12];  /* Max number of digits in a 32-bit integer + 1 for sign and 1 for null terminator */
    int index = 0;
    char c;

    /* Handle negative numbers */
    if (read(STDIN_FILENO, &c, 1) == 1 && c == '-') {
        write(STDOUT_FILENO, "-", 1);
    } else {
        lseek(STDIN_FILENO, -1, SEEK_CUR);  /* Rewind one character if not negative */
    }

    /* Read and parse digits */
    while (read(STDIN_FILENO, &c, 1) == 1 && c >= '0' && c <= '9') {
        buffer[index++] = c;
    }

    buffer[index] = '\0';
    /* Return the parsed integer */
    return atoi(buffer);
}

/* Custom function to print an integer */
void custom_print_integer(int number) {
    char buffer[12];  /* Max number of digits in a 32-bit integer + 1 for sign and 1 for null terminator */
    int index = 0;

    /* Handle negative numbers */
    if (number < 0) {
        write(STDOUT_FILENO, "-", 1);
        number = -number;
    }

    /* Handle the case where the number is zero */
    if (number == 0) {
        write(STDOUT_FILENO, "0", 1);
        return;
    }

    /* Extract and store digits in reverse order */
    while (number > 0) {
        buffer[index++] = '0' + (number % 10);
        number /= 10;
    }

    /* Print digits in reverse order */
    for (int i = index - 1; i >= 0; i--) {
        write(STDOUT_FILENO, &buffer[i], 1);
    }
}

int main(void) {
    int number;

    /* Prompt the user for input */
    write(STDOUT_FILENO, "Enter an integer: ", 18);

    /* Read the integer using custom function */
    number = custom_read_integer();

    /* Print the integer using custom function */
    custom_print_integer(number);

    write(STDOUT_FILENO, "\n", 1);  /* Add a newline character */

    return 0;
}
