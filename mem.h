#define WORDSZ 4

int load(unsigned int addr, char *dest);
int store(const char *src, unsigned int addr);
void print_mem();
void set_mem(char a);
int valid(int addr);
