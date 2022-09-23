#!/bin/bash

qemu-system-aarch64 \
    -smp 4 -m 4G -M virt -cpu cortex-a57 -nographic \
    -bios /usr/share/qemu-efi-aarch64/QEMU_EFI.fd \
    -device virtio-blk-device,drive=image -drive if=none,id=image,file=ubuntu.img \
    -device e1000,netdev=net0 -netdev user,id=net0,hostfwd=tcp:127.0.0.1:5556-:22

exit 0

qemu-system-aarch64 \
    -smp 2 -m 4G -M virt -cpu cortex-a57 -nographic \
    -bios /usr/share/qemu-efi-aarch64/QEMU_EFI.fd \
    -device virtio-blk-device,drive=image -drive if=none,id=image,file=ubuntu.img \
    -device virtio-blk-device,drive=cloud -drive if=none,id=cloud,file=user-data.img \
    -device e1000,netdev=net0 -netdev user,id=net0,hostfwd=tcp:127.0.0.1:5556-:22
