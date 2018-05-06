#include "file.h"

//RPM_PACKAGE 0xed + 0xab + 0xee + 0xdb

int		rpm_package(FILE *file)
{
	unsigned char	buffer[4];

	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0xed)
		return (0);
	if (buffer[1] != 0xab)
		return (0);
	if (buffer[2] != 0xee)
		return (0);
	if (buffer[3] != 0xdb)
		return (0);
	printf("RPM package\n");
	return (1);
}

