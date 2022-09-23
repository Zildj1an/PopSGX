#!/bin/bash

sudo qemu-system-aarch64 \
    -machine virt -cpu cortex-a57 -m 4096 -nographic \
    -drive id=root,if=none,media=disk,file=arm.img \
    -device virtio-blk-device,drive=root \
    -netdev type=tap,id=net0 \
    -device virtio-net-device,netdev=net0,mac=00:da:bc:de:02:11 \
    -kernel linux-arm/arch/arm64/boot/Image \
    -append "root=/dev/vda console=ttyAMA0"
