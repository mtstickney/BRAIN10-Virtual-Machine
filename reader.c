#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

void loader(char *filename, char *memory); 	//Loads brain10 filename into memory
void intconvert(char *memory);			//Converts x1x2 characters in memory into ints

int main(){

	char filename[]="b10.txt";
	void *memory=calloc(100,4);
	char *cmemory=memory;

	loader(filename,memory);

	intconvert(memory);

return 0;
}

void loader(char *filename, char *memory){	//Loads brain10 filename into memory

	char bin[50];			//Input buffer
	FILE *fp;			//File pointer
	int i=0;			//Memory input counter

	fp=fopen(filename,"r");
	if (fp==NULL){			//Prints error and exits if file is not found
		printf("Cannot find file.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp,"%s",bin);		//Initializes string buffer with first string from file

	if(strcasecmp("BRAIN10",bin)){	//Checks for BRAIN10 header
		printf("\nIncorrect file header for BRAIN10.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp,"%s",bin);		//Reads next data string

	while(strcasecmp("DATA",bin)&&!feof(fp)){	//Stores commands up to DATA into memory
		if(i==400){				//Checks for full memory
			printf("Memory is full\n");
			exit(EXIT_FAILURE);
		}
		memory[i++]=bin[0];			//Stores first character of string
		memory[i++]=bin[1];			//Stores second character of string
		fscanf(fp,"%s",bin);			//Reads next string
	}
}

void intconvert(char *memory){		//Converts x1x2 characters in memory into ints
	int i;
	for(i=2;i<100;i=i+4){			//Subtracts 30 hex from every 3rd and 4th character
		memory[i]=memory[i]-0x30;
		memory[i+1]=memory[i+1]-0x30;
	}
}

	

