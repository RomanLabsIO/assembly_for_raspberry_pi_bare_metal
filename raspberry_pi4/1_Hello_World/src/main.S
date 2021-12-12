.section ".text"
.align 2

.equ VideoColourGreen, 0x0000FF00

.global main
main:     
    ldr x5, =video_init         //video_init()
    blr x5

    mov x0, 0                   //video_put_pixel_linear(0, VideoColourGreen)
    ldr x1, =VideoColourGreen 
    ldr x5, =video_put_pixel_linear
    blr x5
