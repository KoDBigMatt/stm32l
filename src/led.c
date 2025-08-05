
// Include standard libraries
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Include STM32L driver libraries
#include "stm32l4xx.h"
#include "stm32l4xx_hal_gpio.h"
#include "stm32l4xx_hal_rcc.h"

// Include module header
#include "led.h"

// Include all other customer headers


// Notes
// LD1 is used by the system to indicate status
// LD2 is available and controlled via PB13 (Pin 34, HIGH ON)
// LD3 is used by the system to indicate status

#define PB_LD2_PORT (GPIOA)
#define PB_LD2_PIN  (5)


/*
 * Initalize this module
 */
void LED_vInit(void) {
    GPIO_InitTypeDef gpio_init;
    memset((void*)&gpio_init, 0, sizeof(GPIO_InitTypeDef));

    gpio_init.Pin = PB_LD2_PIN;
    gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init.Pull = GPIO_NOPULL;
    gpio_init.Speed = GPIO_SPEED_FREQ_LOW;
    // gpio_init.Alternate = ;

    __HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_GPIO_Init(PB_LD2_PORT, &gpio_init);
    HAL_GPIO_WritePin(PB_LD2_PORT, PB_LD2_PIN, GPIO_PIN_SET);
} // LED_vInit

