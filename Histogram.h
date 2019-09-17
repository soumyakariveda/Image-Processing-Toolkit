#ifndef Histogram_h_
#define Histogram_h_
#include "Image.h"

#include<iostream>
#include <fstream>
using namespace std;
class Histogram:public Image{
  private:
    int freq[256], c[6], count;
  public:
    Histogram(int a, int b);
    void set_freq();
    void change_image();
};
#endif
