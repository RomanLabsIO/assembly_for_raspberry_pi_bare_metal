### Lab 1 -  Hello World

**NOTE: Don't worry too much about all the additional code (uart.c, uart.h, main.c, gpio.h, etc). These are used so we can print to the screen. Everything will be covered later in detail**

#### Objectives 

After completion of this lab, the student will be able to:

1. Run a makefile to compile bare metal code to produce a binary for the Raspberry Pi
2. Test the binary produced on QEMU
3. Test the binary produced on the PI
4. Identify an ARM assembly file when seeing one

#### Instructions 

1. Currently `hello_world.s` displays `hey` on the screen (there's no lowercase letters):

<img src="https://github.com/RomanLabsIO/assembly_for_raspberry_pi_bare_metal/blob/master/1_Hello_World/images/qemu_output.png" width="620"/>

change it so it displays `hello`. 

2. Generate `output/kernel8.img` and it on both QEMU and the PI. 

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

#### Transfer kernel9.img to sd card (Windows Subsystem For Linux)
Set SDCARD_DRIVE to match your sd card drive letter (e.g. d,f,h, etc):
```
SDCARD_DRIVE=f ./kernel8_to_sdcard_wsl.sh
```

#### QEMU solution output
<img src="https://github.com/RomanLabsIO/assembly_for_raspberry_pi_bare_metal/blob/master/1_Hello_World/images/qemu_solution.png" width="620"/>


#### Raspberry PI solution Output
missing