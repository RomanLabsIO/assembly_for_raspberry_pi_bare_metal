set -e

if [  -z "$SDCARD_DRIVE" ]; then 
    tput setaf 1
    echo "Env var SDCARD_DRIVE unset. Example: SDCARD_DRIVE=f ./kernel8_to_sdcard_wsl.sh"
    exit 1
fi

KERNEL_DIR=./output

echo "Mounting $SDCARD_DRIVE drive"
sudo mkdir -p /mnt/$SDCARD_DRIVE
sudo mount -t drvfs $SDCARD_DRIVE: /mnt/$SDCARD_DRIVE

if test -f /mnt/$SDCARD_DRIVE/kernel8.img; then
    PREV_KERNEL_SIZE=$(stat --printf="%s" /mnt/$SDCARD_DRIVE/kernel8.img)
else
    PREV_KERNEL_SIZE=0
fi

echo "Replacing kernel"
cp $KERNEL_DIR/kernel8.img /mnt/$SDCARD_DRIVE

NEW_KERNEL_SIZE=$(stat --printf="%s" /mnt/$SDCARD_DRIVE/kernel8.img)

echo "Wrote "$NEW_KERNEL_SIZE" bytes"

echo "Unmounting $SDCARD_DRIVE drive"
sudo umount /mnt/$SDCARD_DRIVE

if [ $PREV_KERNEL_SIZE == $NEW_KERNEL_SIZE ] ; then
    tput setaf 1; echo "WARNING: previous and current kernel are of the same size"
fi