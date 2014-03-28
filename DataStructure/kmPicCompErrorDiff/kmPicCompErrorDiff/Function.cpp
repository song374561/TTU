#include <string>
#include <iostream>
#include <vector>
#include "PicHeader.h"
using namespace std;

void showPicInfo(string filename, BitMapFileHeader bmfh, BitMapInfoHeader bmih)
{
	cout << endl;
	cout << "File Name\t\t: " << filename << endl;
	cout << "Type\t\t\t: " << bmfh.type[0] << bmfh.type[1] << endl;
	cout << "File Size\t\t: " << bmfh.size << endl;
	cout << "Res1\t\t\t: " << bmfh.reserved1 << endl;
	cout << "Res2\t\t\t: " << bmfh.reserved2 << endl;
	cout << "OffBits\t\t\t: " << bmfh.offBits << endl << endl;

	cout << "Header Size\t\t: " << bmih.size << endl;
	cout << "Width * Height\t\t: " << bmih.width << " * " << bmih.height << endl;
	cout << "Planes\t\t\t: " << bmih.planes << endl;
	cout << "BitCount\t\t: " << bmih.bitCount << endl;
	cout << "Compression\t\t: " << bmih.compression << endl;
	cout << "SizeImage\t\t: " << bmih.sizeImage << endl;
	cout << "XPels\t\t\t: " << bmih.XPelsPerMeter << endl;
	cout << "YPels\t\t\t: " << bmih.YPelsPerMeter << endl;
	printf("ClrUsed\t\t\t: %d\n", bmih.clrUsed ? bmih.clrUsed : 1 << bmih.bitCount);
	cout << "ClrImpor\t\t: " << bmih.clrImportant << endl;
	cout << endl << endl;
}

int rangeCounter(unsigned char x1, unsigned char y1, unsigned char z1, unsigned char x2, unsigned char y2, unsigned char z2)
{
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2);
}
int choosePoint(vector<Pallette> table[], Pallette pixnel)
{
	int flag = 0;
	int min = rangeCounter(table[0][0].blue, table[0][0].green, table[0][0].red, pixnel.blue, pixnel.green, pixnel.red);
	for (int i = 1; i < 216; i++)
	{
		int result = rangeCounter(table[i][0].blue, table[i][0].green, table[i][0].red, pixnel.blue, pixnel.green, pixnel.red);
		if (min > result)
		{
			min = result;
			flag = i;
		}
	}
	return flag;
}
Pallette countAvg(vector<Pallette> data)
{
	Pallette avg;
	int blue = 0;
	int green = 0;
	int red = 0;

	for (int i = 1; i < data.size(); i++)
	{
		blue += data[i].blue;
		green += data[i].green;
		red += data[i].red;
	}

	blue /= data.size();
	green /= data.size();
	red /= data.size();

	avg.blue = blue;
	avg.green = green;
	avg.red = red;

	return avg;
}