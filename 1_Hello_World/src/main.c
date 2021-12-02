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

#include "video.h"
#include "fb.h"

void main()
{
    video_init();

    drawPixel(250,250,VIDEO_COLOR_GREEN);
    drawLine(100,500,350,700,VIDEO_COLOR_RED);
    drawLine(200,600,450,800,VIDEO_COLOR_BLACK);
    drawLine(300,700,550,900,VIDEO_COLOR_WHITE);
    drawLine(400,800,650,1000,VIDEO_COLOR_BLUE);
    drawLine(500,900,750,1100,VIDEO_COLOR_GREEN);
}