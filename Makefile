obj-m := hello_world.o		# module to be built from hello_world.o

# symbolic link /lib/modules/$(shell uname -r)/build points to the running linux kernel source tree 
# -C option changes the directory
# M=$(PWD) enables the higher-level Makefile in linux kernel source tree to move to the hello_world module source directory.

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
