GPPFLAGS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASFLAGS = --32
LDFLAGS = -melf_i386

objs = loader.o kernel.o



mykernel.bin: linker.ld $(objs)
	ld $(LDFLAGS) -T $< -o $@ $(objs)

%.o: %.cpp
	g++ $(GPPFLAGS) -o $@ -c $<

%.o: %.s
	as $(ASFLAGS) -o $@ $<

install: mykernel.bin
	sudo cp $< /boot/mykernel.bin


