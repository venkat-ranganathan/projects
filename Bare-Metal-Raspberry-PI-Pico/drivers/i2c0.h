#ifndef I2C0_H
#define I2C0_H

#include <stdbool.h>
#include <stdint.h>

void configure_i2c0();
void i2c0_set_target_address(uint8_t addr);
_Bool i2c0_receive_fifo_not_empty();
_Bool i2c0_transmit_fifo_not_full();
_Bool i2c0_is_busy();
_Bool i2c0_do_transaction(uint8_t addr, uint8_t len, uint16_t *data_cmd);
_Bool i2c0_get_data(uint16_t *data);

#define I2C_RESTART (1 << 10)
#define I2C_STOP (1 << 9)
#define I2C_READ (1 << 8)

#endif