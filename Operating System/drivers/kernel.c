#include <starlib.h>
#include <display.h>
#include <interrupts.h>
#include <pic.h>
#include <pit.h>
#include "helloworld.h"

void k_main()
{
	// initiate interrupt descriptor table and drivers
	idt_init(IDT);            // set id table
	pic_initialize();         // intialize the pic
	set_interval_size(1000);   // count every 1000 ticks
	pit_initialize(1000);      // start timer ticking every ms
	__asm__("sti");          // enable interrupts
	clear_screen();
	hide_cursor();

	hello_world();
}