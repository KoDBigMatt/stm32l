#include <sys/stat.h>
#include <unistd.h>

int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        // TODO: Replace this with UART_SendChar(ptr[i]) or similar
    }
    return len;
}

int _read(int file, char *ptr, int len) {
    return 0;
}

int _close(int file) { return -1; }
int _fstat(int file, struct stat *st) { return 0; }
int _lseek(int file, int ptr, int dir) { return 0; }
int _isatty(int file) { return 1; }

void* _sbrk(ptrdiff_t incr) {
    return (void*)-1;  // Return error
}







// This process can print out one character at a time, but does not work with the current setup
// extern int __io_putchar(int ch);

// int _write(int file, char *ptr, int len) {
//     for (int i = 0; i < len; i++) {
//         __io_putchar(ptr[i]);
//     }
//     return len;
// }

// int __io_putchar(int ch) {
//     asm volatile (
//         "mov r0, %0\n"
//         "mov r1, #0x04\n"
//         "bkpt #0xAB\n"
//         : : "r" (ch)
//     );
//     return ch;
// }