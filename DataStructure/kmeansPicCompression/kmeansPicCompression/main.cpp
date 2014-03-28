#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include "PicHeader.h"
#include "Function.h"
using namespace std;



int main(int argc, char *argv[])
{
	BitMapFileHeader bmfh;
	BitMapInfoHeader bmih;
	FILE* inPic, *outPic;
	string sFilename;
	char *cFilename;
	int picSize,arrayCounter;
	unsigned char safeColor[6] = { 0, 51, 102, 153, 204, 255 };
	vector<Pallette> allPixnel;
	vector<Pallette> cltbl[216];
	int loopCount=0, maxLoop=40;

	
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
	inPic = fopen(cFilename,"rb");
	
	if (inPic == NULL)
	{
		cout << "File doesn't exist!" << endl;
		return 0;
	}

	fread(&bmfh, sizeof(BitMapFileHeader), 1, inPic);
	fread(&bmih, sizeof(BitMapInfoHeader), 1, inPic);
	showPicInfo(sFilename,bmfh,bmih);
	rewind(inPic);
	fseek(inPic, bmfh.offBits, SEEK_SET);
	picSize = bmih.width * bmih.height;
	for (int i = 0; i < picSize; i++)
	{
		Pallette pixnel;
		fread(&pixnel, sizeof(Pallette), 1, inPic);
		allPixnel.push_back(pixnel);
	}

	arrayCounter = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				Pallette choosedColor;
				choosedColor.blue = safeColor[i];
				choosedColor.green = safeColor[j];
				choosedColor.red = safeColor[k];
				cltbl[arrayCounter++].push_back(choosedColor);
			}
		}
	}

	for (int i = 0; i < picSize; i++)
	{
		int chooseResult = choosePoint(cltbl, allPixnel[i]);
		cltbl[chooseResult].push_back(allPixnel[i]);
	}
	do{
		for (int i = 0; i < 216; i++)
		{
			Pallette avg = countAvg(cltbl[i]);
			cltbl[i].clear();
			cltbl[i].push_back(avg);
		}
		for (int i = 0; i < picSize; i++)
		{
			int chooseResult = choosePoint(cltbl, allPixnel[i]);
			cltbl[chooseResult].push_back(allPixnel[i]);
		}
		cout << "loopCount = " << loopCount << endl;
	} while (loopCount++ < maxLoop);

	outPic = fopen("output.bmp", "wb+");
	fwrite(&bmfh, sizeof(BitMapFileHeader), 1, outPic);
	fwrite(&bmih, sizeof(BitMapInfoHeader), 1, outPic);
	for (int i = 0; i < 216; i++)
	{
		Pallette avg = countAvg(cltbl[i]);
		cltbl[i].clear();
		cltbl[i].push_back(avg);
	}
	for (int i = 0; i < picSize; i++)
	{
		int chooseResult = choosePoint(cltbl, allPixnel[i]);
		fwrite(&cltbl[chooseResult][0], sizeof(Pallette), 1, outPic);
	}
	
	fclose(inPic);
	fclose(outPic); 
	return 0;
}