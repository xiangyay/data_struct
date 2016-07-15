CC = $(ARCH)gcc
CXX = $(ARCH)g++
AS = $(ARCH)as
LD = $(ARCH)ld
AR = $(ARCH)ar

all : $(CONFIG_FILE)
	cd src/ && $(MAKE)

clean :
	$(RM) $(CONFIG_FILE)
	cd src/ && $(MAKE) clean