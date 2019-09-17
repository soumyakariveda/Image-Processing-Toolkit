#include "Pixel.h"
#include "Image.h"
#include "Colour.h"
#include "generate_holes.h"
#include <cmath>
Image* generate_holes :: generate_image1(Image *ii)
{
    int w=ii->get_w();
    int h=ii->get_h();
	int xc,yc;
    // xc=x-cordinate of circle centre
		// yc=y-cordinate of circle centre
    Image *ig=new Image(w,h);
    xc=floor(w*0.5);
    yc=floor(h*0.5);
    	float r=min((float)xc*0.25,(float)yc*0.25);
      for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
        		if(check(r,j,i,xc,yc))
				{	// fill white color
        			Colour c(255,255,255);
                    (*ig).get_p()[i][j].set_colour(c);
        		}
				else
				{   // fill black color
                    Colour c(0,0,0);
                    (*ig).get_p()[i][j].set_colour(c);
                }
        	}
		}
        return (ig);
}

void generate_holes ::generate_image(int n,int m,Image *ii)
{
	int xc,yc;
    int w=ii->get_w();
    int h=ii->get_h();
		// xc=x-cordinate of circle centre
		// yc=y-cordinate of circle centre
		//. (-1,1)    (1,1)
		//	(-1,-1)   (1,-1)
		xc=floor(w*0.5+n*0.25*w);
		yc=floor(h*0.5+m*0.25*h);
        float r=min((2*xc/(n+2))*0.25,(2*yc/(m+2))*0.25);
		for(int i=h*0.25*(m+1);i<(h/2)+h*0.25*(m+1);i++)
		{
			for(int j=w*0.25*(n+1);j<(w/2)+w*0.25*(n+1);j++)
			{
				if(check(r,j,i,xc,yc))
				{
					// fill white color
                    Colour c(255,255,255);
                    (*ii).get_p()[i][j].set_colour(c);
				}
			}
		}

  }
// checking if (i,j) lies inside the circle
bool generate_holes :: check(float r,int i,int j,int xc,int yc)
{
    if(r > sqrt(pow(xc-i,2)+pow(yc-j,2)))
    {
        return true;// lies inside the circle
    }
    else
    {
        return false;// lies outside the circle
    }
}

