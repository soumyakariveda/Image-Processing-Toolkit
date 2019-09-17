#include "generate_holes.h"
#include "clipping.h"

clipping :: clipping(Image *i,int w,int h) :Image(w,h)
	{
		 this->w=(*i).get_w();
		 this->h=(*i).get_h();
	}

Image* clipping :: Clipping(Image *ii)
	{
		Image *ic=new Image(w,h);
        Image *ig;
        generate_holes *g=new generate_holes();
        ig=g->generate_image1(ii);
        g->generate_image(1,-1,ig);//quadrant 1
        g->generate_image(-1,-1,ig);// quadrant 2
        g->generate_image(-1,1,ig);// quadrant 3
        g->generate_image(1,1,ig);// quadrant 4
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if((*ig).get_p()[i][j].get_c().get_red()==255 && (*ig).get_p()[i][j].get_c().get_blue()==255 && (*ig).get_p()[i][j].get_c().get_green()==255)
                {
                      Colour c((ii->get_p()[i][j].get_c().get_red()),(ii)->get_p()[i][j].get_c().get_green(),(ii)->get_p()[i][j].get_c().get_blue());
                    (*ic).get_p()[i][j].set_colour(c);
                }
                else
                {
                    Colour c(255,255,255);
                    (*ic).get_p()[i][j].set_colour(c);
                }
            }
        }
        return ic;
	}

