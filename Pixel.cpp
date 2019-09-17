#include "Pixel.h"
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;
Pixel::Pixel(int m, int n){
	x=m;
	y=n;
}
Pixel::~Pixel(){}
Pixel::Pixel(const Pixel& p){
	x=p.get_x();
	y=p.get_y();
	c=p.get_c();
}
void Pixel::set_colour(int x, int y, int z)
{
	(*this).c = Colour(x,y,z);
}
void Pixel::set_x_and_y(int a,int b){  //new function added
	x=a;
	y=b;
}
void Pixel::set_colour(Colour c)
{
	(*this).c =c;
}
void Pixel::change_colour(Colour * cf, float alpha){
	(((*this).c).scalar_mult(1-alpha)).vect_add((*cf).scalar_mult(alpha));
}
void Pixel::change_colour(float a, float b){
	float k = ((*this).get_x()+(*this).get_y()+ (*this).get_c().get_red())*a*b;
	float s = ((float)(1.0 + sin(k))/(2.0))*255;
	(*this).set_colour(s,s,s);
}
ostream & operator << (ostream &os, const Pixel &p){
	os<<p.get_c();
	return os;
}
