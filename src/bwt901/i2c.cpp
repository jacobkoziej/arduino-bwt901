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

void BWT901_i2c::write(uint8_t reg_addr, uint8_t data[2])
{
	wire->beginTransmission(i2c_addr);
	wire->write(0xFF);
	wire->write(0xAA);
	wire->write(reg_addr);
	wire->write(data, 2);
	wire->endTransmission();
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


void BWT901_i2c::cfg_save(bool save)
{
	// 0: SAVE -- (0 == save), (1 == default)
	// 1: PADDING

	uint8_t tmp[2];

	tmp[0] = !save;
	tmp[1] = 0x00;

	write(BWT901_REGISTER_SAVE, tmp);
}

void BWT901_i2c::cfg_frequency(float hz)
{
	// 0: FREQUENCY
	// 1: PADDING

	uint8_t tmp[2];

	if      (hz < 0.000) tmp[0] = 0x0C;  // single
	else if (hz < 0.100) tmp[0] = 0x0D;  // no output
	else if (hz < 0.350) tmp[0] = 0x01;  // 0.200Hz
	else if (hz < 0.750) tmp[0] = 0x02;  // 0.500Hz
	else if (hz < 1.500) tmp[0] = 0x03;  // 1.000Hz
	else if (hz < 3.500) tmp[0] = 0x04;  // 2.000Hz
	else if (hz < 7.500) tmp[0] = 0x05;  // 5.000Hz
	else if (hz < 15.00) tmp[0] = 0x06;  // 10.00Hz (default)
	else if (hz < 35.00) tmp[0] = 0x07;  // 20.00Hz
	else if (hz < 75.00) tmp[0] = 0x08;  // 50.00Hz
	else if (hz < 112.5) tmp[0] = 0x09;  // 100.0Hz
	else if (hz < 162.5) tmp[0] = 0x0A;  // 125.0Hz
	else                 tmp[0] = 0x0B;  // 200.0Hz

	tmp[1] = 0x00;

	write(BWT901_REGISTER_RATE, tmp);
}
