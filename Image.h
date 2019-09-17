#ifndef Image_h_
#define Image_h_
#include "Pixel.h"

#include<iostream>
#include <fstream>
using namespace std;
class Image{
	private:
		int w,h;
		Pixel** p;
	public:
		Image();
		Image(int a, int b);
		~Image();
		Image(const Image& i);
		void set_w(int a);
		void set_h(int a);
		int get_w() const {return w;}
		int get_h() const {return h;}
		void set_Pixelseries(Pixel ** r);
		Pixel** get_p() const {return p;}
		void populate_pixels(ifstream& f);
		void apply_filter(float a, float b);
		void apply_filter(Colour * cf, float alpha);
		friend ostream & operator << (ostream &os, const Image& i);
		friend istream & operator >> (istream &is,  Image& i);
};
#endif
