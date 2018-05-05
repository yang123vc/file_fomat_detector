#include "file.h"

//WMV 0x30 + 0x26 + 0xB2 + 0x75 + 0x8E + 0x66 + 0xCF + 0x11
//WMV2 0xA6 + 0xD9 + 0x00 + 0xAA + 0x00 + 0x62 + 0xCE + 0x6C

int		wmv(FILE *file)
{
	unsigned char	buffer[8];
	int				flag;

	flag = 0;
	rewind(file);
	fread(buffer, 1, 8, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] == 0x30)
		flag = 1;
	else if (buffer[0] == 0xA6)
		flag = 2;
	else 
		return (0);
	if (flag == 1 && buffer[1] != 0x26)
		return (0);
	else if (flag == 2 && buffer[1] != 0xD9)
		return (0);
	if (flag == 1 && buffer[2] != 0xB2)
		return (0);
	else if (flag == 2 && buffer[2] != 0x00)
		return (0);
	if (flag == 1 && buffer[3] != 0x75)
		return (0);
	else if (flag == 2 && buffer[3] != 0xAA)
		return (0);
	if (flag == 1 && buffer[4] != 0x8E)
		return (0);
	else if (flag == 2 && buffer[4] != 0x00)
		return (0);
	if (flag == 1 && buffer[5] != 0x66)
		return (0);
	else if (flag == 2 && buffer[5] != 0x62)
		return (0);
	if (flag == 1 && buffer[6] != 0xCF)
		return (0);
	else if (flag == 2 && buffer[6] != 0xCE)
		return (0);
	if (flag == 1 && buffer[7] != 0x00)
		return (0);
	else if (flag == 2 && buffer[7] != 0x6C)
		return (0);
	printf("WMV file\n");
	return (1);
}
