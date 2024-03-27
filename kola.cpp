#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "flash_utils.h"


// Static Variables
#define GPIO_ON 1
#define GPIO_OFF 0

// Flags
bool VEND_1 = false;
bool VEND_2 = false;
bool VEND_3 = false;
bool VEND_4 = false;
bool VEND_5 = false;
bool VEND_6 = false;

int main()
{
    // Init Hardware
    stdio_init_all();
    if (cyw43_arch_init()) {
        return -1;
    }

    // Test and Dump Addresses of Persistent Flash Space
    char addr[80];
    sprintf(addr, "address = %x", getAddressPersistent());

    while(true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, GPIO_ON);
        sleep_ms(1000);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, GPIO_OFF);
        sleep_ms(1000);
    }
}