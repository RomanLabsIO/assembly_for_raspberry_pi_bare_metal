### Lab 1 -  Hello World

**NOTE: Don't worry too much about all the additional code (uart.c, uart.h, main.c, gpio.h, etc). This will be covered later in detail. For now these are used to get an output to the screen.**

#### Objectives 

After completion of this lab, the student will be able to:

1. Describe what bare metal software is
2. Run a makefile to compile bare metal code to produce a binary for the Raspberry Pi
3. Test the binary produced on QEMU
4. Test the binary produced on the PI
5. Identify an assembly program when seeing one

#### Instructions 

1. In `hello_world.s` change the line `mov r0, r0, 1` for `mov r0, r0, 7`, build the code to generate the binary `output/kernel8.img`. 

2. Test `output/kernel8.img` in both QEMU and the PI. 

3. In your favourite browser look for answers to the following questions:
    - What is a Makefile?
    - What's the relationship between the command `make` and a Makefile?
    - What does the extension `.s` denotes?

### Resources on the WEB
- [What is a makefile?](http://www.sis.pitt.edu/mbsclass/tutorial/advanced/makefile/whatis.htm)
- [Makefile origin](https://en.wikipedia.org/wiki/Make_(software)#Origin)
- [What are .S files?](https://stackoverflow.com/questions/10285410/what-are-s-files)

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