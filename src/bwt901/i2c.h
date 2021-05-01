/*
 * i2c.h -- BWT901 I2C implementation
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

#ifndef _BWT901_I2C_H
#define _BWT901_I2C_H

#include <Arduino.h>
#include <Wire.h>


#define BWT901_DEFAULT_I2C_ADDR 0x50


class BWT901_i2c {
	private:
		TwoWire &wire;
		uint8_t i2c_addr;

	public:
		BWT901_i2c(void);
};


#endif /* _BWT901_I2C_H */
