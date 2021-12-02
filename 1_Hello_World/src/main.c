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