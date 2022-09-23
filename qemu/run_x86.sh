#!/bin/bash

# QEMU Virtual CPU version 2.5+
sudo qemu-system-x86_64 -nographic -drive format=raw,file=x86.img -no-reboot
