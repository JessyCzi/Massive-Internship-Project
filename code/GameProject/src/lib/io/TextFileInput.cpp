#include "TextFileInput.h"

#include <stdio.h>
#include <stdlib.h>


char * IO::C::ReadFile(const char * filename)
{
	/*FILE *f = fopen_s("textfile.txt", "rb");
	if (f == NULL)
		return NULL;*/
	FILE *f;
	if (fopen_s(&f, filename, "r") != 0)
		return NULL;


	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	//TODO c++ standard
	char *string = (char *)malloc(fsize + 1);
	long read = fread_s(string, fsize, sizeof(char), fsize,f);
	fclose(f);

	string[read] = '\0';
	return string;
}

