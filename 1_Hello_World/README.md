### Lab 1 -  Hello World

**NOTE: Don't worry too much about all the additional code (video.c, fb.c, etc). These are used so we can put pixels on the screen.**

#### Objectives 

After completion of this lab, the student will be able to:

1. Run a makefile to compile bare metal code to produce a binary for the Raspberry Pi
2. Test the binary produced on QEMU
3. Test the binary produced on the PI
4. Identify an ARM assembly file when seeing one

#### Instructions 

1. Currently `main.s` puts a single pixels on the screen:

<img src="https://github.com/RomanLabsIO/assembly_for_raspberry_pi_bare_metal/blob/master/1_Hello_World/images/output.png" width="620"/>

change it so it makes a line made of three pixels.

2. Generate `output/kernel8.img` and run it on the PI. 

3. In your favourite browser look for answers to the following questions:
    - What is a Makefile?
    - What's the relationship between the command `make` and a Makefile?
    - What does the extension `.s` denotes?

### Resources on the WEB
- [What is a Makefile?](http://www.sis.pitt.edu/mbsclass/tutorial/advanced/makefile/whatis.htm)
- [Makefile origin](https://en.wikipedia.org/wiki/Make_(software)#Origin)
- [What are .s files?](https://stackoverflow.com/questions/10285410/what-are-s-files)

#### Build Binary
```
make
```

#### Transfer kernel8.img to sd card 

**NOTE: Make sure you remove kernel7.img, kernel7l.img, and kernel.img from the sdcard**

##### (Windows Subsystem For Linux)
Set SDCARD_DRIVE to match your sd card drive letter (e.g. d,f,h, etc):
```
SDCARD_DRIVE=f ./kernel8_to_sdcard_wsl.sh
```
##### (Linux/MAC)
Replace kernel8.img in the boot drive of the SD Card. See kernel8_to_sdcard_wsl.sh for reference if you wish to write a script

#### Raspberry PI solution Output
missing