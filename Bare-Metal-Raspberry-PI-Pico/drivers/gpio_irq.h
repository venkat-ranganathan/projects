#ifndef GPIO_IRQ_H
#define GPIO_IRQ_H

#include <rp2040/resets.h>
#include <rp2040/io_bank0.h>
#include <rp2040/m0plus.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef NUM_GPIO_IRQ_CALLBACKS
#define NUM_GPIO_IRQ_CALLBACKS 32
#endif

static void(*callback[NUM_GPIO_IRQ_CALLBACKS])();
static uint8_t callback_gpio_loc[NUM_GPIO_IRQ_CALLBACKS];
static uint8_t num_registered_callbacks;

#define GPIO_IRQ_RESETS (RESETS_RESET_IO_BANK0_MASK)

#ifndef GPIO_IRQ_PRIO
#define GPIO_IRQ_PRIO 3 // set lowest driver priority
#endif

void register_gpio_irq_callback(uint8_t gpio, void (*pf) ());
static void __attribute__((isr)) gpio_irq_handler(); // ISR signature

#endif