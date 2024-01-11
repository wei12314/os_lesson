#include <stdio.h>

int main(int argc, char *argv[])
{
	char str[20] = "\0";
	gets(str);
	puts(str);
	return 0;
}
