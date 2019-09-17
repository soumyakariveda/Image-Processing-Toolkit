#include"Binary.h"
#include "Colour.h"
#include "Pixel.h"
#include "Image.h"
#include <bits/stdc++.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;

Binary::Binary ()
{

}

int Binary :: brightness(int r,int g ,int b)
{
   int br = (r + g + b)/3;
   return br;
}

int Binary :: get_median(vector<int> v)
{
  int median_t ;
  int size1 = v.size();
  if(size1%2 != 0)
  {
    median_t = v[size1 / 2];;
  }
  else
  {
    median_t = (v[size1 / 2 - 1] + v[size1 / 2]) / 2;
  }

  return median_t;

}

Image* Binary :: binarize(Image *img)
{
  //cout<<"Binarize";
  ofstream out,o2,o3;
  ifstream i1,i2,i3;
  out.open("data.txt");
  Pixel pl;
  Colour cl;
  int w1 = img->get_w();
  int h1 = img->get_h();
  //cout<<w1<<h1;
  int arr[256] = {0};
  vector<int> thresholds;
  int n1,n2,n3;

  for(int i=0;i<h1;i++)
  {
    for(int j=0;j<w1;j++)
    {
      pl = img->get_p()[i][j];
      cl = pl.get_c();
      int br = brightness(cl.get_red(),cl.get_green(),cl.get_blue());
      out<<br<<" ";
    }
    out<<endl;
  }
  out.close();

  i1.open("data.txt");

  for(int i=0;i<h1;i++)
  {
    for(int j=0;j<w1;j++)
    {
      i1>>n1;
      arr[n1]=1+arr[n1];
    }
  }
  i1.close();

  for(int i =1;i<255;i++)
  {
    if(arr[i-1]>=arr[i] && arr[i]<=arr[i+1])
    {
      thresholds.push_back(i);
    }
  }

 int median = get_median(thresholds);

 i2.open("data.txt");
 o2.open("graph.txt");
 for(int i=0;i<h1;i++)
 {
   for(int j=0;j<w1;j++)
   {
     i2>>n2;
     if(n2<=median)
     {
       o2<<0<<" ";
     }
     else
     {
      o2<<1<<" ";
     }
   }
   o2<<endl;
 }
 i2.close();
 o2.close();

 Image *img3 = new Image(w1,h1);
 i3.open("graph.txt");

 for(int i=0;i<h1;i++)
 {
   for(int j=0;j<w1;j++)
   {
     i3>>n3;
     if(n3 == 1)
     {
       ((*img3).get_p()[i][j]).set_colour(255, 255, 255);
     }
     else
     {
       ((*img3).get_p()[i][j]).set_colour(0, 0, 0);
     }
 }
 }
 i3.close();

 ofstream out1("output_binary.ppm");
 out1<<"P3"<<endl;
 out1<<w1<<" "<<h1<<endl;
 out1<<255<<endl;

 for(int i=0;i<h1;i++)
 {
   for(int j=0;j<w1;j++)
   {
     out1<<img3->get_p()[i][j]<<endl;
   }
 }
 out1.close();
 return img3;

}
