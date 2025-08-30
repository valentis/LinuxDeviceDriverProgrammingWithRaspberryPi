obj-m += hello_kernel.o

KDIR ?= /lib/modules/$(shell uname -r)/build M=$(PWD)

all:
	make -C $(KDIR) $(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
