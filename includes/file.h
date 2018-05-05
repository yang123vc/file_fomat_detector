#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

/*
** magic numbers below are sorted by offset, then by length.
** That means the programm will first test magic numbers
** from the lowest to the biggest offset, and from here, test them  in the 
** increasing order of their length.
** This list has been used to determine magic numbers and
** offsets: https://www.garykessler.net/library/file_sigs.html
*/


/*
** 0 bytes offset
*/
#define MP3 0xFF + 0xFB
#define BMP 0x42 + 0x4D
#define EXE 0x4D + 0x5A
#define TARZ 0x1F + 0x9D
#define TARZ2 0x1F + 0xA0
#define ZIP 0x50 + 0x4B
#define BZH 0x42 + 0x5A + 0x68
#define TIFF_le2 0x49 + 0x20 + 0x49
#define MP3_2 0x49 + 0x44 +0x33
#define JPG 0xFF + 0xD8 + 0xFF
#define PDF 0x25 + 0x50 + 0x44 + 0x46
#define TIFF_be 0x4D + 0x4D + 0x00 + 0x2A
#define TIFF_be2 0x4D + 0x4D + 0x00 + 0x2B
#define TIFF_le 0x49 + 0x49 + 0x2A + 0x00
#define ICO 0x00 + 0x01 +  0x00 +  0x00
#define RPM_PACKAGE 0xed + 0xab + 0xee + 0xdb
#define WAV 0x52 + 0x49 + 0x46 + 0x46 
#define WAV2 0x57 + 0x41 + 0x56 + 0x45 
#define AVI 0x41 + 0x56 + 0x49 + 0x20
#define JAVA_CLASS 0xCA + 0xFE + 0xBA + 0xBE
#define JAR 0x50 + 0x4B + 0x03 + 0x04
#define AMAZON_KINDLE 0x53 + 0x50 + 0x30 + 0x31
#define LZIP 0x4C + 0x5A + 0x49 + 0x50
#define XML 0x3c + 0x3f + 0x78 + 0x6d + 0x6c + 0x20

#define GIF87a 0x47 + 0x49 + 0x46 + 0x38 + 0x37 + 0x61
#define GIF89a 0x47 + 0X49 + 0x46 + 0x38 +  0x39 + 0x61

#define _3GP 0x66 + 0x74 + 0x79 + 0x70 + 0x33 + 0x67
#define RAR 0x52 + 0x61 + 0x72 + 0x21 + 0x1A + 0x07 + 0x00
#define RAR2 0x52 + 0x61 + 0x72 + 0x21 + 0x1A + 0x07 + 0x01 + 0x00
#define DEB 0x21 + 0x3C + 0x61 + 0x72 + 0x63 + 0x68 + 0x3E
#define WMV 0x30 + 0x26 + 0xB2 + 0x75 + 0x8E + 0x66 + 0xCF + 0x11
#define WMV2 0xA6 + 0xD9 + 0x00 + 0xAA + 0x00 + 0x62 + 0xCE + 0x6C
#define PNG 0x89 + 0x50 + 0x4E + 0x47 + 0x0D + 0x0A + 0x1A + 0x0A
#define RAW 0x49 + 0x49 + 0x2A + 0x00 + 0x10 + 0x00 + 0x00 + 0x00 + 0x43 + 0x52

/*
** 4 bytes offset
*/
#define MP4 0x66 + 0x74 + 0x79 + 0x70 + 0x4D + 0x53 + 0x4E + 0x56
#define MP4_2 0x66 + 0x74 + 0x79 + 0x70 + 0x69 + 0x73 + 0x6F + 0x6D
#define MP4_3 0x66 + 0x74 + 0x79 + 0x70 + 0x6D + 0x70 + 0x34 + 0x32

#ifndef FILE_H
#define FILE_H

typedef struct	s_options
{
	int			verbosity;
}				t_options;

int		usage(void);
int		error(char *err);


int		analysis(FILE *file);
int		mp4(FILE *file);
int		raw(FILE *file);
int		png(FILE *file);
int		wmv(FILE *file);
int		deb(FILE *file);
int		rar(FILE *file);
int		_3pg(FILE *file);
int		gif(FILE *file);

#endif
