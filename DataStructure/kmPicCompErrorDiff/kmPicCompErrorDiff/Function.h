#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include "PicHeader.h"
using namespace std;

void showPicInfo(string filename, BitMapFileHeader bmfh, BitMapInfoHeader bmih);
int rangeCounter(int x1, int y1, int z1, int x2, int y2, int z2);
int choosePoint(vector<Pallette> table[], Pallette pixnel);
Pallette countAvg(vector<Pallette> data);
#endif