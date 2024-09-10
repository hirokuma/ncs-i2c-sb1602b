#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "drivers/led.h"
#include "drivers/sb1602b.h"

#if defined CONFIG_BOARD_SSCI086585_NRF5340_CPUAPP

#define MESSAGE "Hello,nRF5340!"

#elif defined CONFIG_BOARD_SSCI086585_NRF5340_CPUAPP_NS

#define MESSAGE "Hello,nRF5340ns!"

#else

#error "This configuration not supported."

#endif

static void startup(void);

int main(void)
{
    int ret;

    ret = led_init();
    if (ret != 0) {
        printk("fail led_init(): ret=%d\n", ret);
        return -1;
    }

    startup();

    ret = sb1602b_init();
    if (ret != 0) {
        printk("fail sb1602b_init(): ret=%d\n", ret);
        return -1;
    }
    k_msleep(1000); // LCDが消えている状態を目視したいので待たせる

    sb1602b_print(MESSAGE);
    printk("done.\n");

    return 0;
}

static void startup(void)
{
    for (int lp = 0; lp < 3; lp++) {
        led_set(1);
        k_msleep(500);
        led_set(0);
        k_msleep(500);
    }
}
