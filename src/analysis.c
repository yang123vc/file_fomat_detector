#include "file.h"

int		analysis(FILE *file)
{
	if (mp3(file))// a tester
		return (1);
	else if (bmp(file))// a tester
		return (1);
	else if (exe(file))// a tester
		return (1);
	else if (tarz(file))// a tester
		return (1);
	else if (zip(file))
		return (1);
	else if (bzh(file))// a tester
		return (1);
	else if (tiff(file))// a tester
		return (1);
	else if (jpg(file))
		return (1);
	else if (pdf(file))
		return (1);
	else if (ico(file))// a tester
		return (1);
	else if (rpm_package(file))// a tester
		return (1);
	else if (wav(file))// a tester
		return (1);
	else if (avi(file))// a tester
		return (1);
	else if (java_class(file)) // a tester
		return (1);
	else if (jar(file)) // a tester
		return (1);
	else if (amazon_kindle(file)) // a tester
		return (1);
	else if (lzip(file)) // a tester
		return (1);
	else if (gif(file))
		return (1);
	else if (_3pg(file))
		return (1);
	else if (rar(file))
		return (1);
	else if (deb(file))
		return (1);
	else if (wmv(file))// a tester
		return (1);
	else if (png(file))
		return (1);
	else if (raw(file))// a tester
		return (1);
	else if (mp4(file))
		return (1);
	else
		return (0);
}
