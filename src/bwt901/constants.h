/*
 * constants.h -- BWT901 constants
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

#ifndef _BWT901_CONSTANTS_H
#define _BWT901_CONSTANTS_H


#define BWT901_CONSTANT_GRAVITY 9.80665  // m/s^2
#define BWT901_CONSTANT_SCALAR  32768.0

#define BWT901_CONSTANT_ACCELERATION_SCALAR     \
	((16.0  * BWT901_CONSTANT_GRAVITY) / BWT901_CONSTANT_SCALAR)

#define BWT901_CONSTANT_ANGULAR_VELOCITY_SCALAR \
	(2000.0 / BWT901_CONSTANT_SCALAR)

#define BWT901_CONSTANT_ANGLE_SCALAR            \
	(180.0  / BWT901_CONSTANT_SCALAR)


#endif /* _BWT901_CONSTANTS_H */
