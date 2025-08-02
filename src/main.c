#include <stdio.h>
#include <stddef.h>

#include "gpio.h"
#include "led.h"
#include "push_button.h"

int main(void) {
    
    #if 0
        setvbuf(stdout, NULL, _IONBF, 0);
        printf("Hello from STM32!\n");
    #endif

    while (1) {
        // Toggle a pin or just loop
    }
}


/* 
 * Initalize the system
 */
void MAIN_vInit(void) {
    GPIO_vInit();
    LED_vInit();
    PUSH_vInit();
}

// void SystemInit(void) {
//     // Clock setup would go here
// }