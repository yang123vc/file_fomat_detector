#include "file.h"

int		analysis(FILE *file)
{
	/*
	if (mp3(file))
		return (1);
	else if (bmp(file))
		return (1);
	else if (exe(file))
		return (1);
	else if (tarz(file))
		return (1);
	else if (tarz2)
		return (1);
	else if (zip(file))
		return (1);
	else if bzh(file)
		return (1);
	else if (tiff)
		return (1);
	else if (jpg(file))
		return (1);
	else if (pdf(file))
		return (1);
	else if (ico(file))
		return (1);
	else if (rmp_package(file))
		return (1);
	else if (wav(file))
		return (1);
	else if (avi(file))
		return (1);
	else if (java_class(file))
		return (1);
	else if (jar(file))
		return (1);
	else if (amazon_kindle(file))
		return (1);
	else if  lzip(file)
		return (1);
	*/
	if (gif(file))
		return (1);
	else if (_3pg(file))
		return (1);
	else if (rar(file))
		return (1);
	else if (deb(file))
		return (1);
	else if (wmv(file))
		return (1);
	else if (png(file))
		return (1);
	else if (raw(file))
		return (1);
	else if (mp4(file))
		return (1);
	else
		return (0);
}
