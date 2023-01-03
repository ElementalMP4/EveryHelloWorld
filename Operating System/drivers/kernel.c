#include <starlib.h>
#include <display.h>
#include <interrupts.h>
#include <pic.h>
#include <pit.h>

static INPUT_HNDLR input_f = default_input;

void k_main()
{
	// initiate interrupt descriptor table and drivers
	idt_init(IDT);            // set id table
	pic_initialize();         // intialize the pic
	set_interval_size(1000);   // count every 1000 ticks
	pit_initialize(1000);      // start timer ticking every ms
	kbd_initialize();         // enable keyboard
	__asm__("sti");          // enable interrupts
	clear_screen();
	hide_cursor();

	println("Hello World!");
}