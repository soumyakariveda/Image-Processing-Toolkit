#ifndef ScaledImage_h_
#define ScaledImage_h_

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<math.h>
#include "Image.h"
using namespace std;
class ScaledImage: public Image
{
public:
  ScaledImage();
  ~ScaledImage();
  ScaledImage(int wt, int ht);
  void createPI(Image im);
  Pixel** getPI();
  friend ostream& operator<<(std :: ostream &os, ScaledImage &sim);

private:
  Pixel **pi;
};

#endif
