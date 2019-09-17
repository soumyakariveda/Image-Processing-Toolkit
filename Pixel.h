#ifndef Pixel_h_
#define Pixel_h_
#include "Colour.h"
#include<iostream>
using namespace std;
class Pixel{
	private:
		int x,y;
		Colour c;
	public:
		Pixel(int m, int n);
		Pixel(){};
		~Pixel();
		Pixel(const Pixel& p);
		void set_x_and_y(int a,int b);
		int get_x() const {return x;}
		int get_y() const {return y;};
		Colour get_c() const {return c;};
		void set_colour(int a, int b, int c);
		void set_colour(Colour c);
		void change_colour(Colour * cf, float alpha);
		void change_colour(float a, float b);
		friend ostream & operator << (ostream &os, const Pixel &p);
		friend istream & operator >> (istream &in, Pixel& p);
};
#endif
