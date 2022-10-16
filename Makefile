all: build

spice_display_kernel: spice_display/kernel/objects/spice
	cp $< "$@"
	
build:
	make -C spice_display/kernel

release: mrproper
	make RELEASE=1 -C spice_display/kernel
clean:
	make -C spice_display/kernel clean


.PHONY: build release clean
