#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <string.h>
#include <cmath>
#include <ctime>
#include "PicHeader.h"
#include "Function.h"
using namespace std;

int main(int argc, char *argv[])
{
	BitMapFileHeader bmfh;
	BitMapInfoHeader bmih;
	FILE *inPic, *outPic, *outPic1;
	string sFilename;
	char *cFilename;
	int picSize;
	vector<Pallette> picture;
	vector<Pallette> comprssionedPic;
	vector<Pallette> colorTable[256];
	int loopCount = 0, maxLoop = 1000;

	cout << "Enter the picture name:";
	do
	{
		cin >> sFilename;
		if (sFilename.length() > 20)
		{
			cout << "The filename is to long!" << endl;
			cout << "Enter the picture name:";
		}
	} while (sFilename.length() > 20);
	cFilename = (char*)malloc(sFilename.length());
	strcpy(cFilename, sFilename.c_str());
	inPic = fopen(cFilename, "rb");

	if (inPic == NULL)
	{
		cout << "File doesn't exist!" << endl;
		return 0;
	}

	fread(&bmfh, sizeof(BitMapFileHeader), 1, inPic);
	fread(&bmih, sizeof(BitMapInfoHeader), 1, inPic);
	showPicInfo(sFilename, bmfh, bmih);
	rewind(inPic);
	fseek(inPic, bmfh.offBits, SEEK_SET);
	picSize = bmih.width * bmih.height;

	for (int i = 0; i < picSize; i++)
	{
		Pallette pixnel;
		fread(&pixnel, sizeof(Pallette), 1, inPic);
		picture.push_back(pixnel);
	}

//	srand(time(NULL));
	for (int i = 0; i < 256; i++)
	{
		int randNum = rand() % picSize;
		colorTable[i].push_back(picture[randNum]);
	}

	for (int i = 0; i < picSize; i++)
	{
		int chooseResult = choosePoint(colorTable, picture[i]);
		colorTable[chooseResult].push_back(picture[i]);
	}

	do
	{
		for (int i = 0; i < 256; i++)
		{
			Pallette avg = countAvg(colorTable[i]);
			colorTable[i].clear();
			colorTable[i].push_back(avg);
		}
		for (int i = 0; i < picSize; i++)
		{
			int chooseResult = choosePoint(colorTable, picture[i]);
			colorTable[chooseResult].push_back(picture[i]);
		}
		cout << "loopCount = " << loopCount++ << endl;
	} while (loopCount < maxLoop);

	for (int i = 0; i < 256; i++)
	{
		Pallette avg = countAvg(colorTable[i]);
		colorTable[i].clear();
		colorTable[i].push_back(avg);
	}

	outPic1 = fopen("output1.bmp", "wb+");
	fwrite(&bmfh, sizeof(BitMapFileHeader), 1, outPic1);
	fwrite(&bmih, sizeof(BitMapInfoHeader), 1, outPic1);

	for (int i = 0; i < picSize; i++)
	{
		int chooseResult = choosePoint(colorTable, picture[i]);
		comprssionedPic.push_back(colorTable[chooseResult][0]);
		fwrite(&colorTable[chooseResult][0], sizeof(Pallette), 1, outPic1);
	}

	for (int i = bmih.width+1; i < picSize-bmih.width; i++)
	{
		int eBlue, eGreen, eRed;
		eBlue = comprssionedPic[i].blue - picture[i].blue;
		eGreen = comprssionedPic[i].green - picture[i].green;
		eRed = comprssionedPic[i].red - picture[i].red;

		comprssionedPic[i + 1].blue += (unsigned char)(7 / 16 * eBlue);
		comprssionedPic[i + 1].green += (unsigned char)(7 / 16 * eGreen);
		comprssionedPic[i + 1].red += (unsigned char)(7 / 16 * eRed);
		comprssionedPic[i - bmih.width - 1].blue += (unsigned char)(3 / 16 * eBlue);
		comprssionedPic[i - bmih.width - 1].green += (unsigned char)(3 / 16 * eGreen);
		comprssionedPic[i - bmih.width - 1].red += (unsigned char)(3 / 16 * eRed);
		comprssionedPic[i - 1].blue += (unsigned char)(5 / 16 * eBlue);
		comprssionedPic[i - 1].green += (unsigned char)(5 / 16 * eGreen);
		comprssionedPic[i - 1].red += (unsigned char)(5 / 16 * eRed);
		comprssionedPic[i + bmih.width - 1].blue += (unsigned char)(1 / 16 * eBlue);
		comprssionedPic[i + bmih.width - 1].green += (unsigned char)(1 / 16 * eGreen);
		comprssionedPic[i + bmih.width - 1].red += (unsigned char)(1 / 16 * eRed);
	}
	
	outPic = fopen("output.bmp", "wb+");
	fwrite(&bmfh, sizeof(BitMapFileHeader), 1, outPic);
	fwrite(&bmih, sizeof(BitMapInfoHeader), 1, outPic);

	for (int i = 0; i < picSize; i++)
	{
		fwrite(&comprssionedPic[i], sizeof(Pallette), 1, outPic);
	}
	fclose(inPic);
	fclose(outPic);
	return 0;
}