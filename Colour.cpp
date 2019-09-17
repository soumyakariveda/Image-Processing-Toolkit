#include "Colour.h"
#include<iostream>
using namespace std;
Colour::Colour(float a, float b, float c){
	red=a;
	green=b;
	blue=c;
}
Colour::~Colour(){}
Colour::Colour(const Colour& c){
	red=c.get_red();
	green=c.get_green();
	blue=c.get_blue();
}
Colour Colour::scalar_mult(float f){
	(*this).red = (*this).red*f;
	(*this).green = (*this).green*f;
	(*this).blue = (*this).blue*f;
	return *this;
}
void Colour::vect_add(Colour c){
	(*this).red = (*this).red+c.red;
	(*this).green = (*this).green+c.green;
	(*this).blue = (*this).blue+c.blue;
}
ostream & operator << (ostream &os, const Colour &c){
	os<<c.get_red()<<" "<<c.get_green()<<" "<<c.get_blue()<<" ";
	return os;
}
istream & operator >> (istream &in, Colour& c){
	cin>>c.red>>c.green>>c.blue;
	return in;
}
