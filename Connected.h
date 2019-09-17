#ifndef Connected_h_
#define Connected_h_
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
class Connected : public Image
{

  public:
    Connected(int w,int h);
    void dfs(int x,int y,int c,int w1,int h1);
    void colorize(Image *img);

};
#endif
