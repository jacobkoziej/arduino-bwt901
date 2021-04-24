/*
 * arduino-bwt901.h -- BWT901 interface library
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

#include <Arduino.h>


/* registers addresses */
#define SAVE     0x00  // save
#define CALSW    0x01  // calibration
#define RSW      0x02  // return data content
#define RATE     0x03  // return data speed
#define BAUD     0x04  // baud rate

#define AXOFFSET 0x05  // x-axis acceleration bias
#define AYOFFSET 0x06  // y-axis acceleration bias
#define AZOFFSET 0x07  // z-axis acceleration bias

#define GXOFFSET 0x08  // x-axis angular velocity bias
#define GYOFFSET 0x09  // y-axis angular velocity bias
#define GZOFFSET 0x0A  // z-axis angular velocity bias

#define HXOFFSET 0x0B  // x-axis magnetic bias
#define HYOFFSET 0x0C  // y-axis magnetic bias
#define HZOFFSET 0x0D  // z-axis magnetic bias

#define D0MODE   0x0E  // D0 mode
#define D1MODE   0x0F  // D1 mode
#define D2MODE   0x10  // D2 mode
#define D3MODE   0x11  // D3 mode

#define D0PWMH   0x12  // D0 PWM high-level width
#define D1PWMH   0x13  // D1 PWM high-level width
#define D2PWMH   0x14  // D2 PWM high-level width
#define D3PWMH   0x15  // D3 PWM high-level width

#define D0PWMT   0x16  // D0 PWM period
#define D1PWMT   0x17  // D1 PWM period
#define D2PWMT   0x18  // D2 PWM period
#define D3PWMT   0x19  // D3 PWM period

#define ICCADDR  0x1A  // IIC address
#define LEDOFF   0x1B  // turn off LED
#define GPSBAUD  0x1C  // GPS baud rate

#define MMYY     0x30  // month, year
#define HHDD     0x31  // hour, day
#define SSMM     0x32  // second, minute
#define MS       0x33  // millisecond

#define AX       0x34  // x-axis acceleration
#define AY       0x35  // y-axis acceleration
#define AZ       0x36  // z-axis acceleration

#define GX       0x37  // x-axis angular acceleration
#define GY       0x38  // y-axis angular acceleration
#define GZ       0x39  // z-axis angular acceleration

#define HX       0x3A  // x-axis magnetic
#define HY       0x3B  // y-axis magnetic
#define HZ       0x3C  // z-axis magnetic

#define ROLL     0x3D  // x-axis angle
#define PITCH    0x3E  // y-axis angle
#define YAW      0x3F  // z-axis angle
#define TEMP     0x40  // temperature

#define D0STATUS 0x41  // D0 status
#define D1STATUS 0x42  // D1 status
#define D2STATUS 0x43  // D2 status
#define D1STATUS 0x44  // D3 status

#define Q0       0x51  // quaternion Q0
#define Q1       0x52  // quaternion Q1
#define Q2       0x53  // quaternion Q2
#define Q3       0x54  // quaternion Q3


#endif /* _BWT901_H */
