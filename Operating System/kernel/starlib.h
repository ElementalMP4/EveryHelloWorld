// constants
#define RAND_MAX 32767

#define bool _Bool
#define true 1
#define false 0

// functions
void *mem_cpy(char *src, char *dest, int num_of_bytes);
int strlen(const char *str);
void base_convert(int num, int base);
void print_number(int num, int base);
void print_n(int num);
void print(char *str);
void print_c(char ch);
void slow_print(char *str, int delay);
int rand(void);
void srand(unsigned int seed);
int rand_range(int lower, int upper);
void sleep(unsigned int ms);
void halt(void);