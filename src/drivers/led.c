#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#include "led.h"

#define LED0_NODE               DT_ALIAS(led0)
#define LED1_NODE               DT_ALIAS(led1)
#define LED2_NODE               DT_ALIAS(led2)

static const struct gpio_dt_spec dev_led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int led_init(void)
{
	if (!device_is_ready(dev_led0.port)) {
		return -1;
	}

	int ret = gpio_pin_configure_dt(&dev_led0, GPIO_OUTPUT_INACTIVE);
	if (ret < 0) {
		return -1;
	}
	struct gpio_dt_spec dev_led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
	struct gpio_dt_spec dev_led2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
	gpio_pin_configure_dt(&dev_led1, GPIO_OUTPUT_INACTIVE);
	gpio_pin_configure_dt(&dev_led2, GPIO_OUTPUT_INACTIVE);

    return 0;
}

void led_set(int onoff)
{
    gpio_pin_set_dt(&dev_led0, onoff);
}
