/*
 * types.h -- BWT901 types
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

#ifndef _BWT901_TYPES_H
#define _BWT901_TYPES_H

#include <Arduino.h>


typedef struct bwt901_time_s {
	unsigned int year        : 12;
	unsigned int month       : 4;
	unsigned int day         : 5;
	unsigned int minute      : 6;
	unsigned int hour        : 5;
	unsigned int second      : 6;
	unsigned int millisecond : 10;
} bwt901_time_t;

typedef struct bwt901_acceleration_s {
	float x;
	float y;
	float z;
} bwt901_acceleration_t;

typedef struct bwt901_angular_velocity_s {
	float x;
	float y;
	float z;
} bwt901_angular_velocity_t;

typedef struct bwt901_angle_s {
	float x;  // roll
	float y;  // pitch
	float z;  // yaw
} bwt901_angle_t;

typedef struct bwt901_magnetic_s {
	float x;
	float y;
	float z;
} bwt901_magnetic_t;

typedef struct bwt901_port_status_s {
	int16_t d0;
	int16_t d1;
	int16_t d2;
	int16_t d3;
} bwt901_port_status_t;

typedef struct bwt901_quaternion_s {
	float q0;
	float q1;
	float q2;
	float q3;
} bwt901_quaternion_t;

typedef struct bwt901_s {
	bwt901_time_t             time;
	bwt901_acceleration_t     acceleration;
	bwt901_angular_velocity_t angular_velocity;
	bwt901_angle_t            angle;
	bwt901_magnetic_t         magnetic;
	bwt901_port_status_t      port_status;
	bwt901_quaternion_t       quaternion;
} bwt901_t;


#endif /* _BWT901_TYPES_H */
