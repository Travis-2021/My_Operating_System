GPPFLAGS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASFLAGS = --32
LDFLAGS = -melf_i386

objs = loader.o gdt.o kernel.o



mykernel.bin: linker.ld $(objs)
	ld $(LDFLAGS) -T $< -o $@ $(objs)

%.o: %.cpp
	g++ $(GPPFLAGS) -o $@ -c $<

%.o: %.s
	as $(ASFLAGS) -o $@ $<

clean: $(objs)
	rm -rf $(objs)

install: mykernel.bin
	sudo cp $< /boot/mykernel.bin

mykernel.iso: mykernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System" {' >> iso/boot/grub/grub.cfg
	echo '	multiboot /boot/mykernel.bin' >> iso/boot/grub/grub.cfg
	echo '	boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso
	
run: mykernel.iso	# 用不上...
	(killall VirtualBox && sleep 1) || true
	VirtualBox --startvm "My Operating System" &




