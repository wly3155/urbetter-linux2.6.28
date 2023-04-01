# Makefile for Linux samples code

obj-$(CONFIG_SAMPLES)	+= markers/ kobject/ kprobes/ tracepoints/

$(warning KERNELRELEASE = $(KERNELRELEASE))
 
ifeq ($(KERNELRELEASE),)
KERNELDIR ?= /lib/modules/$(shell uname -r)/build  

PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
 
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions Module* modules*
 
.PHONY: modules  clean
 
else
       obj-m := test_platform_driver.o 
	
endif