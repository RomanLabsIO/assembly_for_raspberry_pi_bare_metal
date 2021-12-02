QEMU_BIN_PATH="/mnt/c/Program Files/qemu/qemu-system-aarch64.exe"
"$QEMU_BIN_PATH" -M raspi3 -kernel ./output/kernel8.img -serial stdio -serial null