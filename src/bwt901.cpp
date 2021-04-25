/*
 * arduino-bwt901.cpp -- BWT901 interface library
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

#include "bwt901.h"

#include <Arduino.h>


uint8_t bwt901_time(bwt901_time_t *in, uint8_t *raw)
{
	/*
	 * 0: YY
	 * 1: MM
	 * 2: DD
	 * 3: HH
	 * 4: MM
	 * 5: SS
	 * 6: MS (LOW)
	 * 7: MS (HIGH)
	 */

	// safety checks
	if (!in)  return 0;
	if (!raw) return 0;

	in->year   = raw[0] + 2000;  // year starts at 2000
	in->month  = raw[1];
	in->day    = raw[2];
	in->hour   = raw[3];
	in->minute = raw[4];
	in->second = raw[5];

	uint16_t millisecond;
	millisecond       = raw[7];
	millisecond     <<= 8;
	millisecond      |= raw[6];
	in->millisecond   = millisecond;

	return 1;
}
