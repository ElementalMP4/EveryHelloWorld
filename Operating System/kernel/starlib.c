#include <starlib.h>
#include <display.h>
#include <pit.h>

const char TBL[] = "0123456789ABCDEF";
static unsigned int next = 1;

void *mem_cpy(char *src, char *dest, int num_of_bytes)
{	
	int i;	
	for (i = 0; i < num_of_bytes; ++i)
		*(dest + i) = *(src + i);
}

int strlen(const char *str)
{
	int i = 0;	
	while (str[i] != '\0')
		++i;
		
	return i;
}

void print_n(int num)
{	
	print_number(num, 10);
}

void print_number(int num, int base)
{
	if (num < 0)
	{
		print_c('-');
		__asm__ ("neg %%eax" : "=a"(num) : "a"(num));
	}
	else if (0 == num)
	{
		print_c('0');
		return;
	}
	
	base_convert(num, base);
}

void base_convert(int num, int base)
{
	if (num <= 0)
		return;
	
	base_convert(num / base, base);
	print_c(TBL[num % base]);
}

void print(char *str) 
{
	print_at(str, -1 , -1);
}

void print_c(char ch)
{
	print_char(ch, -1, -1);
}

void slow_print(char *str, int delay) {
	for (int i = 0; i < strlen(str); i++) {
		print_c(str[i]);
		sleep(delay);
	}
}

int rand(void)
{
	next = next * 1103515245 + 12345;
	return (next>>16) & RAND_MAX;
}

void srand(unsigned int seed)
{
	next = seed;
}

int rand_range(int lower, int upper) {
	return (rand() % (upper - lower + 1)) + lower;
}

void sleep(unsigned int ms)
{
	int i, j;
	j = 0;
	while (true)
	{
		i = get_ticks();	
		halt();
		if (i != get_ticks())
			++j;
		if (j >= ms)
			break;
	}
}

void halt(void)
{
	__asm__("hlt");
}

void append(char *s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
