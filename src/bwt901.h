/*
 * bwt901.h -- BWT901 interface library
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

#ifndef _BWT901_H
#define _BWT901_H

#include "bwt901/types.h"

#include <Arduino.h>


/* numerical constants */
#define BWT901_CONSTANT_GRAVITY 9.80665  // m/s^2
#define BWT901_CONSTANT_SCALAR  32768.0

#define BWT901_CONSTANT_ACCELERATION_SCALAR     \
	((16.0  * BWT901_CONSTANT_GRAVITY) / BWT901_CONSTANT_SCALAR)

#define BWT901_CONSTANT_ANGULAR_VELOCITY_SCALAR \
	(2000.0 / BWT901_CONSTANT_SCALAR)

#define BWT901_CONSTANT_ANGLE_SCALAR            \
	(180.0  / BWT901_CONSTANT_SCALAR)


/* communication protocol */
#define BWT901_METADATA_HEADER             0x55
#define BWT901_METADATA_TIME               0x50
#define BWT901_METADATA_ACCELERATION       0x51
#define BWT901_METADATA_ANGULAR_VELOCITY   0x52
#define BWT901_METADATA_ANGLE              0x53
#define BWT901_METADATA_MAGNETIC           0x54
#define BWT901_METADATA_PORT_STATUS        0x55
#define BWT901_METADATA_QUATERNION         0x59

#define BWT901_PACKET_SIZ 11


/* prototypes */
uint8_t bwt901_request(uint8_t *buff, uint8_t addr);

uint8_t bwt901_time(bwt901_time_t *in, uint8_t *raw);
uint8_t bwt901_acceleration(bwt901_acceleration_t *in, uint8_t *raw);
uint8_t bwt901_angular_velocity(bwt901_angular_velocity_t *in, uint8_t *raw);
uint8_t bwt901_angle(bwt901_angle_t *in, uint8_t *raw);
uint8_t bwt901_magnetic(bwt901_magnetic_t *in, uint8_t *raw);
uint8_t bwt901_port_status(bwt901_port_status_t *in, uint8_t *raw);
uint8_t bwt901_quaternion(bwt901_quaternion_t *in, uint8_t *raw);

uint8_t bwt901_checksum(uint8_t *raw);
uint8_t bwt901_deserialize(uint16_t *out, uint8_t cnt, uint8_t *raw);


#endif /* _BWT901_H */
