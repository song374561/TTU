#ifndef PIC_H
#define PIC_H
#pragma pack(1)
typedef struct tagBitMapFileHeader
{
	char type[2];
	unsigned int size;
	unsigned short reserved1;
	unsigned short reserved2;
	unsigned int offBits;
} BitMapFileHeader;
#pragma pack()

#pragma pack(1)
typedef struct tagBitMapInfoHeader
{
	unsigned int size;
	unsigned int width;
	unsigned int height;
	unsigned short planes;
	unsigned short bitCount;
	unsigned int compression;
	unsigned int sizeImage;
	unsigned int XPelsPerMeter;
	unsigned int YPelsPerMeter;
	unsigned int clrUsed;
	unsigned int clrImportant;
} BitMapInfoHeader;
#pragma pack()

typedef struct tagPallette
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} Pallette;

#endif