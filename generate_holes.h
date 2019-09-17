#ifndef generate_holes_h_
#define generate_holes_h_
#include "Pixel.h"
#include "Image.h"
#include "Colour.h"

class generate_holes
{
public:
    void generate_image(int n,int m,Image *ii);
	Image* generate_image1(Image *ii);
    bool check(float r,int i,int j,int xc,int yc);
};
#endif
