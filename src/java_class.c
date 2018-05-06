#include "file.h"

//JAVA_CLASS 0xCA + 0xFE + 0xBA + 0xBE

int		java_class(FILE *file)
{
	unsigned char	buffer[4];

	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0xCA)
		return (0);
	if (buffer[1] != 0xFE)
		return (0);
	if (buffer[2] != 0xBA)
		return (0);
	if (buffer[3] != 0xBE)
		return (0);
	printf("JAVA_CLASS file\n");
	return (1);
}
