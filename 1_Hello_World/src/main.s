.section ".text"
.align 2

.equ FONT_COLOR_GREEN, 0x0000FF00
.equ FONT_SIZE, 5

.global main
main:     
    ldr x5, =video_init     //video_init()
    blr x5

    mov x0, '\n'            //video_putc('\n', FONT_SIZE, FONT_COLOR_GREEN)
    mov x1, FONT_SIZE 
    ldr x2, =FONT_COLOR_GREEN
    ldr x5, =video_putc
    blr x5

    mov x0, 'h'             //video_putc('h', FONT_SIZE, FONT_COLOR_GREEN)
    mov x1, FONT_SIZE 
    ldr x2, =FONT_COLOR_GREEN
    ldr x5, =video_putc
    blr x5

    mov x0, 'e'             //video_putc('e', FONT_SIZE, FONT_COLOR_GREEN)
    mov x1, FONT_SIZE 
    ldr x2, =FONT_COLOR_GREEN
    ldr x5, =video_putc
    blr x5

    mov x0, 'y'             //video_putc('y', FONT_SIZE, FONT_COLOR_GREEN)
    mov x1, FONT_SIZE 
    ldr x2, =FONT_COLOR_GREEN
    ldr x5, =video_putc
    blr x5
