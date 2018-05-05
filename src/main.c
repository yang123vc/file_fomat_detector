#include "file.h"

int					usage(void)
{
	printf("usage: ftype [-v] filename\n");
	return (0);
}

int					error(char *err)
{
	printf("%s: %s", err, strerror(errno));
	return (0);
}

int					main(int argc, char *argv[])
{
	FILE			*file;

	file = 0;
	if (argc < 2)
		return (usage());
	if ((file = fopen(argv[1], "rb")) == NULL)
		return (error("Cannot read file"));
	if (!analysis(file))
		printf("Probably a text file, or an unkown binary file format\n");
	return (0);
}
