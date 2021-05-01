/*
 * i2c.cpp -- BWT901 I2C implementation
 * Copyright (C) 2021  Jacob Koziej <jacobkoziej@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "i2c.h"

#include <Arduino.h>
#include <Wire.h>


void BWT901_i2c::request(uint8_t reg_addr, uint8_t *buff, uint8_t siz)
{
	wire->beginTransmission(i2c_addr);
	wire->write(reg_addr);
	wire->endTransmission(false);

	wire->requestFrom(i2c_addr, siz);
	while (wire->available() < siz);

	for (uint8_t i = 0; i < siz; i++) buff[i] = wire->read();

	// drop leftover data
	wire->endTransmission();
	while(wire->available()) wire->read();
}


BWT901_i2c::BWT901_i2c(void)
{
	i2c_addr = BWT901_DEFAULT_I2C_ADDR;
	wire     = &Wire;
}


void BWT901_i2c::address(uint8_t addr)
{
	i2c_addr = addr;
}

void BWT901_i2c::i2c_bus(TwoWire *in)
{
	wire = in;
}
