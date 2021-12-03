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

#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t VideoColour;

enum VideoColour{
    VideoColourBlack = 0x00000000,
    VideoColourWhite = 0xFFFFFFFF,
    VideoColourGreen = 0x0000FF00,
    VideoColourRed   = 0x00FF0000,
    VideoColourBlue  = 0x000000FF
};

uint32_t video_init( void );
void video_put_pixel_linear( uint32_t linear_pos, VideoColour colour );

#endif
