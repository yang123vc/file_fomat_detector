#include "file.h"

//TIFF_le 0x49 + 0x49 + 0x2A + 0x00
//TIFF_be 0x4D + 0x4D + 0x00 + 0x2A
//TIFF_be2 0x4D + 0x4D + 0x00 + 0x2B

int		tiff(FILE *file)
{
	unsigned char	buffer[4];
	int				flag;

	flag = 0;
	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] == 0x49)
		flag = 1;
	else if (buffer[0] == 0x4D)
		flag = 2;
	else
		return (0);
	if (flag == 1 && buffer[1] != 0x49)
		return (0);
	else if (flag == 2 && buffer[1] != 0x4D)
		return (0);
	if  (flag == 1 && buffer[2] != 0x2A)
		return (0);
	else if (flag == 1 && buffer[2] != 0x00)
		return (0);
	if (flag == 1 && buffer[3] != 0x00)
		return (0);
	else if (flag == 2 && buffer[3] != 0x2A && buffer[3] != 0x2B)
		return (0);
	printf ("TIFF file\n");
	return (1);
}
