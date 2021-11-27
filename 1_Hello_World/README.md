### Lab 1 -  Hello World

#### Objectives 

1. Get acquainted with the process of compiling bare metal code with gcc
2. Have a first look and feel at assembly
3. Get familiar with how we'll be visualizing tests in the screen

**NOTE:** Don't worry too much about all the additional code (uart.c, uart.h, main.c, gpio.h, etc). This will be covered later in detail. For now it's used for getting an output to the screen.

#### Instructions 

- In `hello_world.s` change the line 
```
mov r0, r0, 1
```
for
```
mov r0, r0, 7
```
and answer: 
- What changed? 
- Why did it change? Hint: have a look at `main.c`

In your favourite browser look for answers to the following questions:

- What is a Makefile?
- What is the file extension for ARM assembly?
- What does the instruction `mov` do (in hello_world.s)?
- In what order instructions are executed?
- How many instructions per line can you have in assembly? 

### Resources on the WEB
- None

#### Run lab in QEMU

```
make
QEMU_BIN_PATH=...
$QEMU_BIN_PATH 
```

#### Run lab in Raspberry PI

```
make

```