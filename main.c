#include "file.h"

int					usage(void)
{
	printf("usage: ftype [-v] filename\n");
	return (0);
}

int					error(char *err)
{
	printf("%s", strerror(errno));
	return (0);
}

int					sum_magic(unsigned char *buffer)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (buffer[i])
		sum += buffer[i++];
	return (sum);
}

int				analyze(unsigned char *buffer, int bytes)
{
	int				res;
	int				sum;

	res = 0;
	sum = sum_magic(buffer);
	switch (bytes)
	{
		case 10 :
			res = ten(sum);
			break ;
		case 8 :
			res = nine(sum);
			break ;
		case 7 :
			res = seven(sum);
			break ;
		case 6 :
			res = six(sum);
			break ;
		case 4 :
			res = four(sum);
			break ;
		case 3 :
			res = three(sum);
			break ;
		case 2 :
			res = two(sum);
			break ;
	}
	if (res == 1)
		return (1);
	return (0);
}

int					read_magic(int file)
{
	size_t			i;
	unsigned char	buffer[11];
	int				ret;

	ret = 0;
	memset(buffer, 0, 11);
	for (i = 10; i > 0; i--)
	{
		ret = read(file, buffer, i);
		if (ret == -1)
			return (error("Cannot read file"));
		ret = analyze(buffer, i);
		if (ret == 1)
			return (1);
		ret = lskeek(file, SEEK_SET, 0);
		if (ret == -1)
			return (error("Cannot reposition file offset"));
		memset(buffer, 0, 11);
	}
	return (0);
}

int					main(int argc, char *argv[])
{
	int				file;

	file = 0;
	if (argc < 2)
		return (usage());
	if ((file = fopen(argv[1], "rb") == -1))
		return (error("Cannot read file"));
	if (!read_magic(file))
		printf("Cannot determine file type, use a real UNIX
				command instead\n");
	return (0);
}
