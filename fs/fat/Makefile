#
# Makefile for the Linux fat filesystem support.
#

ifdef CONFIG_CC_OPTIMIZE_ALOT
CFLAGS_dir.o += -Os
endif
ifdef CONFIG_CC_OPTIMIZE_SIZE
CFLAGS_dir.o += -Os 
endif
ifdef CONFIG_CC_OPTIMIZE_DEFAULT
CFLAGS_dir.o += -Os
endif

obj-$(CONFIG_FAT_FS) += fat.o
obj-$(CONFIG_VFAT_FS) += vfat.o
obj-$(CONFIG_MSDOS_FS) += msdos.o

fat-y := cache.o dir.o fatent.o file.o inode.o misc.o
vfat-y := namei_vfat.o
msdos-y := namei_msdos.o
