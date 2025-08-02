#include <stdio.h>
#include <stddef.h>

int main(void) {
    
    #if 0
        setvbuf(stdout, NULL, _IONBF, 0);
        printf("Hello from STM32!\n");
    #endif

    while (1) {
        // Toggle a pin or just loop
    }
}

// void SystemInit(void) {
//     // Clock setup would go here
// }