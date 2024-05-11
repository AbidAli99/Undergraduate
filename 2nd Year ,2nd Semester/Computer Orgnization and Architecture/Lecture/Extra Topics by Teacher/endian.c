#include "stdio.h"
#include "stdbool.h"

bool IsBig_Endian()
{
    unsigned short test = 0x1122;
    if(*( (unsigned char*) &test ) == 0x11)
    	return true;
    return false;
}

int main(int argc, char* argv[])
{
	if(IsBig_Endian() == true)
	{
		printf("Your machine is BIG endian.\n");
		return 0;
	}
	printf("Your machine is little endian.\n");
	return 0;
}