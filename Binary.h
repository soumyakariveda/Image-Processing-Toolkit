#ifndef Binary_h_
#define Binary_h_
#include "Colour.h"
#include "Pixel.h"
#include "Image.h"
#include <bits/stdc++.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <fstream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
class Binary : public Image
{

  public:
    Binary();
    int brightness(int r,int g,int b);
    int get_median(vector<int> v);
    Image* binarize(Image *img);
};
#endif
