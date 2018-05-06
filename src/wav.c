#include "file.h"

//WAV 0x52 + 0x49 + 0x46 + 0x46 
//WAV2 0x57 + 0x41 + 0x56 + 0x45 

int		wav(FILE *file)
{
	unsigned char	buffer[4];
	int				flag;

	flag = 0;
	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] == 0x52)
		flag = 1;
	else if (buffer[0] == 0x57)
		flag = 2;
	else
		return (0);
	if (flag == 1 && buffer[1] != 0x49)
		return (0);
	else if (flag == 2 && buffer[1] != 0x41)
		return (0);
	if (flag == 1 && buffer[2] != 0x46)
		return (0);
	else if (flag == 2 && buffer[2] != 0x56)
		return (0);
	if (flag == 1 && buffer[3] != 0x46)
		return (0);
	else if (flag == 2 && buffer[3] != 0x45)
		return (0);
	printf("WAV file\n");
	return (1);
}

