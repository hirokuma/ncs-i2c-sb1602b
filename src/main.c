#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "drivers/led.h"
#include "drivers/sb1602b.h"

int main(void)
{
    int ret;

    ret = led_init();
    if (ret != 0) {
        printk("fail led_init(): ret=%d\n", ret);
        return -1;
    }

    for (int lp = 0; lp < 3; lp++) {
        led_set(1);
        k_msleep(1000);
        led_set(0);
        k_msleep(1000);
    }

    ret = sb1602b_init();
    if (ret != 0) {
        printk("fail sb1602b_init(): ret=%d\n", ret);
        return -1;
    }

    sb1602b_print("Hello, World!");
    printk("done.\n");

    return 0;
}
