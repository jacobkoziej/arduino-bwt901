/*
 * process.cpp -- BWT901 data processing
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

#include "constants.h"
#include "process.h"

#include <Arduino.h>


inline int16_t BWT901_process::deserialize(uint8_t in[2])
{
	int16_t tmp;

	// low byte is always first
	tmp   = in[0];
	tmp <<= 8;
	tmp  |= in[1];

	return tmp;
}


inline float BWT901_process::angle(int16_t in)
{
	float tmp;

	tmp  = in;
	tmp *= BWT901_CONSTANT_ANGLE_SCALAR;

	return tmp;
}
