#include "file.h"


//MP4_1	0x66 + 0x74 + 0x79 + 0x70 + 0x4D + 0x53 + 0x4E + 0x56
//MP4_2 0x66 + 0x74 + 0x79 + 0x70 + 0x69 + 0x73 + 0x6F + 0x6D
//MP4_3 0x66 + 0x74 + 0x79 + 0x70 + 0x6D + 0x70 + 0x34 + 0x32
//4 Bytes offset

int		mp4(FILE *file)
{
	unsigned char	buffer[11];
	int				flag;

	flag = 0;
	fseek(file, 4, SEEK_SET);
	fread(buffer, 1, 8, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x66)
		return (0);
	if (buffer[1] != 0x74)
		return (0);
	if (buffer[2] != 0x79)
		return (0);
	if (buffer[3] != 0x70)
		return (0);
	if (buffer[4] == 0x4D)
		flag = 1;
	else if (buffer[4] == 0x69)
		flag = 2;
	else if (buffer[4] == 0x6D)
		flag = 3;
	else
		return (0);
	if (flag == 1 && buffer[5] != 0x53)
		return (0);
	else if (flag == 2 && buffer[5] != 0x73)
		return (0);
	else if (flag == 3 && buffer[5] != 0x70)
		return (0);
	if (flag == 1 && buffer[6] != 0x4E)
		return (0);
	else if (flag == 2 && buffer[6] != 0x6F)
		return (0);
	else if (flag == 3 && buffer[6] != 0x34)
		return (0);
	if (flag == 1 && buffer[7] != 0x56)
		return (0);
	else if (flag == 2 && buffer[7] != 0x6D)
		return (0);
	else if (flag == 3 && buffer[7] != 0x32)
		return (0);
	printf("MP4 file\n");
	return (1);
}

