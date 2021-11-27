### Lab 1 -  Hello World

#### Objectives 

1. Get familiar with the process of compiling bare metal code with gcc
3. Get familiar with how we'll be visualizing tests in the screen
4. Learn the process of testing our code on QEMU
4. Learn the process of testing our code on the Pi
5. Have a quick first encounter with assembly

#### Instructions 

1. In `hello_world.s` change the line `mov r0, r0, 1` for `mov r0, r0, 7`, build the code to generate and executable. Test it with both QEMU and onthe PI. 

    **NOTE: Don't worry too much about all the additional code (uart.c, uart.h, main.c, gpio.h, etc). This will be covered later in detail. For now it's used for getting an output to the screen.**

2. In your favourite browser look for answers to the following questions:

- What is a Makefile?
- What is the file extension for ARM assembly?
- What does the instruction `mov` does? 

### Resources on the WEB
- Makefile
- .s extension vs .S

#### Build Binary
```
make
```

#### Run lab in QEMU
```
./run_on_qemu.sh
```

#### Sample output in QEMU
missing

#### Sample output in Raspberry PI
missing