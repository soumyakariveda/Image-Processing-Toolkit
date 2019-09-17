#include <bits/stdc++.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Pixel.h"
#include "Image.h"
#include "Colour.h"
#include "clipping.h"
#include "stenciling.h"
#include "generate_holes.h"
#include "histogram.h"
#include "ScaledImage.h"
#include "Binary.h"
#include "Connected.h"
using namespace std;
Image* composite(float alpha,Image *i1,Image *i2)
{
    Image *img=new Image(i1->get_w(),i1->get_h());
    for(int i=0;i<(i1)->get_h();i++)
    {
        for(int j=0;j<(i1)->get_w();j++)
        {
            Colour c1=(i1)->get_p()[i][j].get_c();
            Colour c2=(i2)->get_p()[i][j].get_c();
            int r,g,b;
            r=(((1-alpha)*c1.get_red())+(alpha*c2.get_red()));
            g= (((1-alpha)*c1.get_green())+(alpha*c2.get_green()));
            b = (((1-alpha)*c1.get_blue())+(alpha*c2.get_blue()));
            Colour new_c(r,g,b);
            (img)->get_p()[i][j].set_colour(new_c);
        }
    }
    return img;
}
Image* reflection( Image* ii)
{
    Image *ir=new Image((*ii).get_w(),(*ii).get_h());
    int h=(*ii).get_h();
    int w=(*ii).get_w();
    for(int i=0;i<h;i++)
    {
        for(int j=w-1;j>=0;j--)
        {
            Colour *c=new Colour((ii->get_p()[i][j].get_c().get_red()),(ii)->get_p()[i][j].get_c().get_green(),(ii)->get_p()[i][j].get_c().get_blue());
            (*ir).get_p()[i][w-1-j].set_colour(*c);
        }
    }
    return ir;
}
int main(int argc,char *argv[])
{
  cout<<"Our group task ID combination is : ";
  string s;
  cin>>s;
  int n, l=s.length(), i;
  cout<<l;
  for(i=0;i<l;i+=2){
    n=(int)s[i]-48;
    cout<<n<<endl;
    switch(n){
      case 1:{
        ifstream input;
        ofstream output3;
        input.open(argv[1]);
        string type;
        int w,h,max;
        input>>type;
        input>>w>>h;
        input>>max;
        Image *img1 = new Image(w,h);
        Image *img2;
        input>>(*img1);
        img2=reflection(img1);
        stenciling *t=new stenciling(img1,w,h);
        clipping *s=new clipping(img1,w,h);
        output3.open("output_task<1>_imt<IMT2016053>.ppm");
        output3<<"P3"<<"\n";
        output3<<w<<"\n"<<h<<"\n";
        output3<<max<<"\n";
        output3 << *(composite(0.5,(*s).Clipping(img1),(*t).Stenciling(img2)));
      }
      case 4:{
        string type;
        int maxcolor, he, w, r, g, b;
        ifstream fin;
        ofstream fout;
        fin.open(argv[1]);
        fout.open("output_task<4>_imt<IMT2016114>.ppm");
        fin>>type>>w>>he>>maxcolor;
        Histogram* h=new Histogram(w, he);
        (*h).populate_pixels(fin);
        h->set_freq();
        h->change_image();
        fout<<type<<endl<<h->get_w()<<" "<<h->get_h()<<endl<<maxcolor<<endl<<*h;
        fin.close();
        fout.close();
      }
      case 6:{
          /*ifstream f1;
          ofstream o1;
          ofstream o2;
          ofstream o3;
          f1.open(argv[1]);

          int w,h,max;
          string s1;
          f1>>s1; f1>>w; f1>>h; f1>>max;

          if(w==253 && h==254)
          {
            h = 253;
          }

          Image *img1 = new Image(w,h);
          f1 >>(*img1);

          Image *img2 = new Image(w,h);


          Binary *b = new Binary();
          img2 = b->binarize(img1);

          Connected *c = new Connected(w,h);
          c->colorize(img2);
          */
      }
      case 7:{
        int wt, ht, maxCol;
        std::string str;
        std::ifstream file;
        file.open(argv[1]);
        file >> str;
        file >> wt >> ht;
        file >> maxCol;
        Image im(wt, ht);
        im.populate_pixels(file);
        file.close();
        ScaledImage sc(wt, ht);
        sc.createPI(im);
        std::ofstream outFile("output_task<7>_imt<IMT2016074>.ppm");
        outFile << str << endl;
        outFile << wt << " " << ht << endl;
        outFile << maxCol << endl;
        outFile << sc;
        outFile.close();
        exit(0);
      }
    }
  }
}
