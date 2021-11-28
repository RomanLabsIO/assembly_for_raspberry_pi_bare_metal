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

#include <stdint.h>
#include <stdbool.h>
#include "video.h"
#include "fonts.h"
#include "fb.h"

#define SYSTEM_SCREEN_WIDTH      1024
#define SYSTEM_SCREEN_LENGTH     768

#define X_ORIGIN 	VIDEO_CHARACTER_WIDTH
#define Y_ORIGIN    VIDEO_CHARACTER_HEIGHT*3
uint32_t curr_x=X_ORIGIN;
uint32_t curr_y=Y_ORIGIN;

#define NULL 0

static inline void put_pixel_raw( uint32_t raw_pos, uint32_t color );
static inline uint32_t x_y_to_raw(uint32_t x, uint32_t y);
static void draw_character_raw( uint32_t x, uint32_t y, VideoFont* c, uint32_t size, VideoColor color );
static int32_t abs(int32_t v);

static uint32_t* fb; //Framebuffer pointer

/*
*  Video Init
*/
uint32_t video_init( void ){
    fb = fb_init();
    fonts_init();
}


/*
*  Video Puts
*
*/
void video_puts( uint8_t* string, uint32_t size, VideoColor color ){
		while(*string)
			video_putc( *string++, size, color );
}

/*
*  Video Putc
*
*/
uint8_t* continue_msg = "( Press any key to continue )";
#define CONTINUE_MSG_CHARACTER_SIZE 2
#define CONTINUE_MSG_HEIGHT (VIDEO_CHARACTER_HEIGHT*CONTINUE_MSG_CHARACTER_SIZE+VIDEO_CHARACTER_VERTICAL_SPACE*CONTINUE_MSG_CHARACTER_SIZE )
#define CONTINUE_MSG_WIDTH  340
void video_putc( uint8_t c, uint32_t size, VideoColor color  ){

	if( c == '\n' ){
			//Go new line
			curr_y = ( curr_y
							+ VIDEO_CHARACTER_HEIGHT*size
							+ VIDEO_CHARACTER_VERTICAL_SPACE );

			return;
	}
	else if( c == '\r' ){
			//carriage return
			curr_x = X_ORIGIN;
			return;
	}
	else{

			//Will the charatacer fit in the current line?
			if(  curr_x >= VIDEO_MAX_X - VIDEO_CHARACTER_WIDTH*size - VIDEO_CHARACTER_HORIZONTAL_SPACE ){
				//No. Go next line.
				video_putc( '\r', size, color );
				video_putc( '\n', size, color );
			}

			//Write the character
			video_putc_x_y( curr_x, curr_y, c, size, color );

			//Move X cursor
			curr_x = ( curr_x
							+ VIDEO_CHARACTER_WIDTH*size
							+ VIDEO_CHARACTER_HORIZONTAL_SPACE );
	}

}

uint8_t opt= ' ';

/*
*  Video Putc XY
*
*/
void video_putc_x_y( uint32_t x, uint32_t y, uint8_t c, uint32_t size, VideoColor color  ){
	draw_character_raw(x, y, fonts_char_to_font(c), size, color );
}

static void draw_character_raw( uint32_t x, uint32_t y, VideoFont* c, uint32_t size, VideoColor color ){

	//Draw as per specs
	VideoXY init, end;

	for( int i=0; i<c->num_lines; i++ ){
			//For all lines

			//Set up (x0,y0)*size
			init.x 	= x + c->lines[i].init.x * size;
			init.y 	= y + c->lines[i].init.y * size;

			//Set up (x1,y1)*size
			end.x 	= x + c->lines[i].end.x * size;
			end.y 	= y + c->lines[i].end.y * size;

			video_line( &init, &end, color );
	}

}


/*
*  Video Line
*
*  It used Brasenham's Line Algorithm (Developed at IBM in 1962!).
*
* Actual code from here:
*       https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
*
*/
void video_line( VideoXY* init, VideoXY* end, VideoColor color ){
	int32_t x0= init->x;
	int32_t y0= init->y;
	int32_t x1= end->x;
	int32_t y1= end->y;

	int32_t dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int32_t dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int32_t err = (dx>dy ? dx : -dy)/2, e2;

	VideoXY pos;

	for(;;){
		pos.x = x0;
		pos.y = y0;

		video_put_pixel( &pos, color);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

static int32_t abs(int32_t v){
		if(v<0) return v*(-1);
		else return v;
}

/*
*  IO Video PutPixel
*/
void video_put_pixel( VideoXY* pos, VideoColor color ){
    put_pixel_raw( x_y_to_raw(pos->x,pos->y), color );
}

void video_clear( void ){
	for( int y=0; y<VIDEO_MAX_Y; y++ ){
		for( int x=0; x<VIDEO_MAX_X; x++ ){
			put_pixel_raw(  x_y_to_raw(x,y), VIDEO_COLOR_BLACK );
		}
	}

    //go to origin
    curr_x = X_ORIGIN;
    curr_y = Y_ORIGIN;
}

static inline uint32_t x_y_to_raw(uint32_t x, uint32_t y){
	return y*VIDEO_MAX_X + x;
}

///////////////////////////////
/////// DRIVER INTERFACE
//////////////////////////////
static inline void put_pixel_raw( uint32_t raw_pos, uint32_t color ){
    *(fb + raw_pos) = color; //<<<-- Note that addition is pointer arithmetic!
}
