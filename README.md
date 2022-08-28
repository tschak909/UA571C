# UA571C

A recreation of the UA 571-C Remote Sentry Weapon System display from Aliens - Written in GRiD OS.

Well, I had to test the development environment, somehow!

(apologies for the audio, new filter chain, and I only had time to record this ONCE)

As part of @tr1nitr0n and myself rebuilding the GRiD Development Environment from batches of GRiD server hard drives, I needed something to test that the development environment that could compile Pascal, PL/M, Fortran, C and Assembler was working as expected. Then I thought about the sentry remote weapon system scenes that were cut from the theatrical release of James Cameron's Aliens (1986) film, which used GRiD Compass II 1129 laptops. GRiD had developed a set of working displays in GRiDBASIC for the film. These were never released, but now that the same tools are working again, I recreated them.

## What is here?

* INCS - The GRiD-OS Include files for Pascal and PL/M Development.
* LIBS - The GRiD-OS Libraries for Pascal and PL/M Development
* PROGRAMS - All of the native GRiD software needed for living in GRiD-OS, including the compilers and other development tools, and a complete set of GRiD user software.
* UA571C - The source code for the UA 571-C display program
* GRID.EXE - The InteGRiD Environment - This version supports the 400 line mode on GRiDCASE machines, Otherwise it runs in CGA 200 Line mode
* GRIDRAM.EXE - This one just runs in CGA 200 line mode.
* LICENSE - The GPL v3.0 License for UA 571-C only.
* InteGRiD.IMG - A 20 megabyte raw Hard disk image (615 cyl, 4 heads, 17 sectors/track) that can either be put on a real disk, or run from an emulator, such as [PCem](https://github.com/sarah-walker-pcem/pcem)

## InteGRiD Cheat Sheet

* CODE is Alt
* Confirm is Alt-Return
* Next field is Return
* CODE-? to get help
* CODE-Shift-? to get quick launch keys
* CODE-CTRL-? to get Window management keys

## UA 571-C Keys

* CODE-F Firing Panel
* CODE-O Options
* CONFIRM will also move from Options to firing panel.
* RETURN to Fire.

Enjoy, -Thom
