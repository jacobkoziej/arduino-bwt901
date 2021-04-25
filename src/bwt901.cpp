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

uint8_t bwt901_acceleration(bwt901_acceleration_t *in, uint8_t *raw)
{
	/*
	 * 0: AX (LOW)
	 * 1: AX (HIGH)
	 * 2: AY (LOW)
	 * 3: AY (HIGH)
	 * 4: AZ (LOW)
	 * 5: AZ (HIGH)
	 * 6: V  (LOW)
	 * 7: V  (HIGH)
	 */

	// safety checks
	if (!in)  return 0;
	if (!raw) return 0;

	int16_t x, y, z;

	x   = raw[1];
	x <<= 8;
	x  |= raw[0];

	y   = raw[3];
	y <<= 8;
	y  |= raw[2];

	z   = raw[5];
	z <<= 8;
	z  |= raw[4];

	in->x = x;
	in->y = y;
	in->z = z;

	in->x *= ACCELERATION_SCALAR;
	in->y *= ACCELERATION_SCALAR;
	in->z *= ACCELERATION_SCALAR;

	// NOTE: temperature is disregarded

	return 1;
}

uint8_t bwt901_angular_velocity(bwt901_angular_velocity_t *in, uint8_t *raw)
{
	/*
	 * 0: WX (LOW)
	 * 1: WX (HIGH)
	 * 2: WY (LOW)
	 * 3: WY (HIGH)
	 * 4: WZ (LOW)
	 * 5: WZ (HIGH)
	 * 6: V  (LOW)
	 * 7: V  (HIGH)
	 */

	// safety checks
	if (!in)  return 0;
	if (!raw) return 0;

	int16_t x, y, z;

	x   = raw[1];
	x <<= 8;
	x  |= raw[0];

	y   = raw[3];
	y <<= 8;
	y  |= raw[2];

	z   = raw[5];
	z <<= 8;
	z  |= raw[4];

	in->x = x;
	in->y = y;
	in->z = z;

	in->x *= ANGULAR_VELOCITY_SCALAR;
	in->y *= ANGULAR_VELOCITY_SCALAR;
	in->z *= ANGULAR_VELOCITY_SCALAR;

	// NOTE: temperature is disregarded

	return 1;
}

uint8_t bwt901_angle(bwt901_angle_t *in, uint8_t *raw)
{
	/*
	 * 0: ROLL  (LOW)
	 * 1: ROLL  (HIGH)
	 * 2: PITCH (LOW)
	 * 3: PITCH (HIGH)
	 * 4: YAW   (LOW)
	 * 5: YAW   (HIGH)
	 * 6: V     (LOW)
	 * 7: V     (HIGH)
	 */

	// safety checks
	if (!in)  return 0;
	if (!raw) return 0;

	int16_t x, y, z;

	x   = raw[1];
	x <<= 8;
	x  |= raw[0];

	y   = raw[3];
	y <<= 8;
	y  |= raw[2];

	z   = raw[5];
	z <<= 8;
	z  |= raw[4];

	in->x = x;
	in->y = y;
	in->z = z;

	in->x *= ANGLE_SCALAR;
	in->y *= ANGLE_SCALAR;
	in->z *= ANGLE_SCALAR;

	// NOTE: version is disregarded

	return 1;
}

uint8_t bwt901_magnetic(bwt901_magnetic_t *in, uint8_t *raw)
{
	/*
	 * 0: HX (LOW)
	 * 1: HX (HIGH)
	 * 2: HY (LOW)
	 * 3: HY (HIGH)
	 * 4: HZ (LOW)
	 * 5: HZ (HIGH)
	 * 6: V  (LOW)
	 * 7: V  (HIGH)
	 */

	// safety checks
	if (!in)  return 0;
	if (!raw) return 0;

	int16_t x, y, z;

	x   = raw[1];
	x <<= 8;
	x  |= raw[0];

	y   = raw[3];
	y <<= 8;
	y  |= raw[2];

	z   = raw[5];
	z <<= 8;
	z  |= raw[4];

	in->x = x;
	in->y = y;
	in->z = z;

	// NOTE: temperature is disregarded

	return 1;
}
