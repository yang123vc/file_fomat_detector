#include "file.h"

int		ten(int sum)
{
	if (sum == RAW)
	{
		printf("RAW file\n");
		return (1) ;
	}
	return (0);
}

int		eight(int sum)
{
	switch (sum)
	{
		case RAR2:
			printf("RAR file\n");
			return (1) ;
		case PNG:
			printf("PNG file\n");
			return (1) ;
		case WMV2:
			printf("WMV2 file\n");
			return (1) ;
		case WMV:
			printf("WMV file\n");
			return (1) ;
	}
	return (0);
}

int		seven(int sum)
{
	switch (sum)
	{
		case RAR:
			printf("RAR  file\n");
			return (1);
		case DEB:
			printf("DEB file\n");
			return (1);
	}
	return (0);
}

int		six(int sum)
{
	switch (sum)
	{
		case XML:
			printf("XML file\n");
			return (1);
		case GIF89a:
			printf("GIF file\n");
			return (1);
		case GIF87a:
			print("GIF file\n");
			return (1);
		case 3GP:
			printf("3GP file\n");
			return (1);
	}
	return (0);
}

int		four(int sum)
{
}
