#include <stdio.h>
#include <string.h>
#include "mem.h"

static char mem[WORDSZ*100];

void set_mem(char a) {
	memset(mem, a, WORDSZ*100);
}

static char *get_memp(unsigned int addr) {
	if (addr > 99) {
		return NULL;
	}
	return &mem[WORDSZ*addr];
}

/* Note: load and store convert endianness of words. */
int load(unsigned int addr, char *dest) {
	void *src;

	src = get_memp(addr);
	if (src == NULL) {
		fprintf(stderr, "load: invalid address %d\n", addr);
		return -1;
	}
	memcpy(dest, src, WORDSZ);
	return 0;
}

int store(const char *src, unsigned int addr)
{
	char *dest;

	dest = get_memp(addr);
	if (dest == NULL) {
		fprintf(stderr, "store: invalid address %d\n", addr);
		return -1;
	}

	memcpy(dest, src, WORDSZ);
	return 0;
}

void print_mem()
{
	int i,j;
	char *p;

	for (i=0; i<100; i++) {
		printf("%02d ", i);
		for (j=0; j<9; j++, i++) {
			p = get_memp(i);
			printf("%c%c%c%c ", p[0], p[1], p[2], p[3]);
		}
		p=get_memp(i);
		printf("%c%c%c%c\n", p[0], p[1], p[2], p[3]);
	}
}	