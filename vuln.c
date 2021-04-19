#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bof(char *str)
{
  char buffer[12];
	strcpy(buffer,str);
}

int main(int argc, char *argv[])
{
	bof(argv[1]);
	printf("Returned Properly\n");
	return 1;
}
