#ifndef Colour_h_
#define Colour_h_
#include<iostream>
using namespace std;
class Colour{
	private:
		float red,green,blue;
	public:
		Colour() {}
		Colour(float a, float b, float c);
		~Colour();
		Colour(const Colour& c);
		int get_red() const {return red;}
		int get_green() const {return green;}
		int get_blue() const {return blue;}
		Colour scalar_mult(float f);
		void vect_add(Colour c);
		friend ostream & operator << (ostream &os, const Colour &c);
		friend istream & operator >> (istream &in, Colour& c);
};
#endif
