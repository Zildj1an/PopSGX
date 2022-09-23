#!/bin/bash

# ARM926EJ-S rev 5 (v5l)
qemu-system-arm -nographic -M versatilepb -kernel vmlinuz-2.6.32-5-versatile \
	-initrd initrd.img-2.6.32-5-versatile \
	-hda debian_squeeze_armel_standard.qcow2 \
	-append "root=/dev/sda1 -no-reboot"
