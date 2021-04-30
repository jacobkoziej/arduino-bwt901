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


/* registers addresses */
#define BWT901_REGISTER_SAVE     0x00  // save
#define BWT901_REGISTER_CALSW    0x01  // calibration
#define BWT901_REGISTER_RSW      0x02  // return data content
#define BWT901_REGISTER_RATE     0x03  // return data speed
#define BWT901_REGISTER_BAUD     0x04  // baud rate

#define BWT901_REGISTER_AXOFFSET 0x05  // x-axis acceleration bias
#define BWT901_REGISTER_AYOFFSET 0x06  // y-axis acceleration bias
#define BWT901_REGISTER_AZOFFSET 0x07  // z-axis acceleration bias

#define BWT901_REGISTER_GXOFFSET 0x08  // x-axis angular velocity bias
#define BWT901_REGISTER_GYOFFSET 0x09  // y-axis angular velocity bias
#define BWT901_REGISTER_GZOFFSET 0x0A  // z-axis angular velocity bias

#define BWT901_REGISTER_HXOFFSET 0x0B  // x-axis magnetic bias
#define BWT901_REGISTER_HYOFFSET 0x0C  // y-axis magnetic bias
#define BWT901_REGISTER_HZOFFSET 0x0D  // z-axis magnetic bias

#define BWT901_REGISTER_D0MODE   0x0E  // D0 mode
#define BWT901_REGISTER_D1MODE   0x0F  // D1 mode
#define BWT901_REGISTER_D2MODE   0x10  // D2 mode
#define BWT901_REGISTER_D3MODE   0x11  // D3 mode

#define BWT901_REGISTER_D0PWMH   0x12  // D0 PWM high-level width
#define BWT901_REGISTER_D1PWMH   0x13  // D1 PWM high-level width
#define BWT901_REGISTER_D2PWMH   0x14  // D2 PWM high-level width
#define BWT901_REGISTER_D3PWMH   0x15  // D3 PWM high-level width

#define BWT901_REGISTER_D0PWMT   0x16  // D0 PWM period
#define BWT901_REGISTER_D1PWMT   0x17  // D1 PWM period
#define BWT901_REGISTER_D2PWMT   0x18  // D2 PWM period
#define BWT901_REGISTER_D3PWMT   0x19  // D3 PWM period

#define BWT901_REGISTER_ICCADDR  0x1A  // IIC address
#define BWT901_REGISTER_LEDOFF   0x1B  // turn off LED
#define BWT901_REGISTER_GPSBAUD  0x1C  // GPS baud rate

#define BWT901_REGISTER_MMYY     0x30  // month, year
#define BWT901_REGISTER_HHDD     0x31  // hour, day
#define BWT901_REGISTER_SSMM     0x32  // second, minute
#define BWT901_REGISTER_MS       0x33  // millisecond

#define BWT901_REGISTER_AX       0x34  // x-axis acceleration
#define BWT901_REGISTER_AY       0x35  // y-axis acceleration
#define BWT901_REGISTER_AZ       0x36  // z-axis acceleration

#define BWT901_REGISTER_GX       0x37  // x-axis angular velocity
#define BWT901_REGISTER_GY       0x38  // y-axis angular velocity
#define BWT901_REGISTER_GZ       0x39  // z-axis angular velocity

#define BWT901_REGISTER_HX       0x3A  // x-axis magnetic
#define BWT901_REGISTER_HY       0x3B  // y-axis magnetic
#define BWT901_REGISTER_HZ       0x3C  // z-axis magnetic

#define BWT901_REGISTER_ROLL     0x3D  // x-axis angle
#define BWT901_REGISTER_PITCH    0x3E  // y-axis angle
#define BWT901_REGISTER_YAW      0x3F  // z-axis angle
#define BWT901_REGISTER_TEMP     0x40  // temperature

#define BWT901_REGISTER_D0STATUS 0x41  // D0 status
#define BWT901_REGISTER_D1STATUS 0x42  // D1 status
#define BWT901_REGISTER_D2STATUS 0x43  // D2 status
#define BWT901_REGISTER_D1STATUS 0x44  // D3 status

#define BWT901_REGISTER_Q0       0x51  // quaternion Q0
#define BWT901_REGISTER_Q1       0x52  // quaternion Q1
#define BWT901_REGISTER_Q2       0x53  // quaternion Q2
#define BWT901_REGISTER_Q3       0x54  // quaternion Q3


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
