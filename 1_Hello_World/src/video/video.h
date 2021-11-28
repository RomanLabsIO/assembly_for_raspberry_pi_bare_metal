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

#ifndef HAL_H
#define HAL_H

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t VideoColor;

typedef struct{
  int32_t x;
  int32_t y;
}VideoXY;

typedef struct{
  VideoXY init;
  VideoXY end;
}VideoLine;

#define VIDEO_MAX_X     SYSTEM_SCREEN_WIDTH      //Pixels per line
#define VIDEO_MAX_Y     SYSTEM_SCREEN_LENGTH     //Num of lines

#define VIDEO_CHARACTER_WIDTH              4   //Unit Character dimensions
#define VIDEO_CHARACTER_HEIGHT             6   //(It's unit, because they all get
#define VIDEO_CHARACTER_HORIZONTAL_SPACE   3   // scaled by "size" when printing larger characters )
#define VIDEO_CHARACTER_VERTICAL_SPACE     5
#define VIDEO_CHARACTER_SPACE_BEFORE_END   2*VIDEO_CHARACTER_HEIGHT + VIDEO_CHARACTER_VERTICAL_SPACE

#define VIDEO_COLOR_BLACK   0x00000000
#define VIDEO_COLOR_WHITE   0xFFFFFFFF
#define VIDEO_COLOR_GREEN 	0x0000FF00
#define VIDEO_COLOR_BLUE    0x00FF0000
#define VIDEO_COLOR_RED     0x000000FF

uint32_t video_init( void );
void video_put_pixel( VideoXY*, VideoColor );
void video_clear( void );
void video_line( VideoXY*, VideoXY*, VideoColor );
void video_putc_x_y( uint32_t x, uint32_t y, uint8_t c, uint32_t size, VideoColor color );
void video_putc( uint8_t c, uint32_t size, VideoColor color  );
void video_puts( uint8_t*, uint32_t, VideoColor );

#endif
