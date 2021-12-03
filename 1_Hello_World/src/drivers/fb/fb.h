/**
*   This file is part of assembly_for_raspberry_pi_bare_metal
*   (https://github.com/RomanLabsIO/assembly_for_raspberry_pi_bare_metal).
*
*   Copyright (c) 2021 RomanLabs I/O
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
**/

/**
 * 
 * CC0-1.0 License
 * https://github.com/isometimes/rpi4-osdev
 *  
 **/

#ifndef FB_H
#define FB_H

void fb_init();
void fb_draw_pixel_raw(int raw_pos, unsigned int colour);

#endif