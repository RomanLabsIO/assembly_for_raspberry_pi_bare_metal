### Lab 1 -  Hello World

#### Objectives 

1. Get familiar with the process of compiling bare metal code with gcc
3. Get familiar with how we'll be visualizing tests in the screen
4. Learn the process of testing our code on QEMU
4. Learn the process of testing our code on the Pi

#### Instructions 

- In `hello_world.s` change the line 
```
mov r0, r0, 1
```
for
```
mov r0, r0, 7
```
that's it.

**NOTE:** Don't worry too much about all the additional code (uart.c, uart.h, main.c, gpio.h, etc). This will be covered later in detail. For now it's used for getting an output to the screen.

In your favourite browser look for answers to the following questions:

- What is a Makefile?
- What is the file extension for ARM assembly?
- What does the instruction `mov` do (in hello_world.s)?
- In what order instructions are executed?
- How many instructions per line can you have in assembly? 

### Resources on the WEB
- None

#### Build Binary

```
make
```

#### Run lab in QEMU

```
./run_on_qemu.sh
```

#### Run lab in Raspberry PI

missing