SDCARD_DRIVE=f
KERNEL_DIR=./output

echo "Mounting $SDCARD_DRIVE drive"
sudo mkdir -p /mnt/$SDCARD_DRIVE
sudo mount -t drvfs $SDCARD_DRIVE: /mnt/$SDCARD_DRIVE

PREV_KERNEL_SIZE=$(stat --printf="%s" $KERNEL_DIR/kernel8.img)

echo "Replacing kernel"
cp $KERNEL_DIR/kernel8.img /mnt/$SDCARD_DRIVE

NEW_KERNEL_SIZE=$(stat --printf="%s" $KERNEL_DIR/kernel8.img)

echo "Unmounting $SDCARD_DRIVE drive"
sudo umount /mnt/$SDCARD_DRIVE

if [ $PREV_KERNEL_SIZE == $NEW_KERNEL_SIZE ] ; then
    tput setaf 1; echo "WARNING: previous and current kernel are of the same size"
fi