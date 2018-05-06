#include "file.h"

//MP3 0xFF + 0xFB
//MP3_2 0x49 + 0x44 +0x33

int		mp3(FILE *file)
{

	unsigned char	buffer[3];
	int				flag;

	flag = 0;
	rewind(file);
	fread(buffer, 1, 3, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] == 0xFF)
		flag = 1;
	else if (buffer[0] == 0x49)
		flag = 2;
	else
		return (0);
	if  (flag == 1 && buffer[1] == 0xFB)
		goto OK;
	else if (flag == 2 && buffer[1] != 0x44)
		return (0);
	else
		return (0);
	if (flag == 2 && buffer[2] != 0x33)
		return (0);
	OK: printf("MP3 file\n");
	return (1);
}
