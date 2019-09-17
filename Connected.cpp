#include"Binary.h"
#include"Connected.h"
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

int g[1024][1024] = {0};
int warr[1024][1024] = {0};

int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {1,1,1,0,-1,-1,-1,0};

Connected::Connected (int w,int h)
{
  //cout<<"Constructor";
}

void Connected::dfs(int x,int y,int c,int w1,int h1)
{
  warr[x][y] = c;
  for(int i=0; i<8;i++){
    //  cout<<"reached here"<<endl;
      int nx = x+dx[i], ny = y+dy[i];
      //cout<<"also reached here"<<endl;
      if(nx>0 && nx<=w1 && ny>0 && ny<=h1)
      if(g[nx][ny] && !warr[nx][ny])
      {
        dfs(nx,ny,c,w1,h1);
      }

    }
}

void Connected :: colorize(Image *img)
{
  ofstream out,o3;
  ifstream i1,i3;
  int w1 = img->get_w();
  int h1 = img->get_h();
  int set = 1;

  i1.open("graph.txt");
  out.open("labeled.txt");
  int n4;

  for(int i=1; i<=h1; i++)
  {
   for(int j=1; j<=w1; j++)
   {
     i1>>n4;
     g[i][j] = n4;
    }
  }

  for(int i=1; i<=h1;i++)
  {
        //    cout<<"loop1";
      for(int j=1; j<=w1; j++)
      {
      //  cout<<"loop2";

          if(g[i][j] && !warr[i][j])
          {
            //  cout<<i<<" "<<j<<endl;
              dfs(i,j,set++,w1,h1);
          }
        }
      }


  for(int i=1; i<=h1;i++){
    for(int j=1; j<=w1;j++)
    {

        out<<warr[i][j]<<" ";
    }
      out<<endl;
    }
  i1.close();
  out.close();

  int n3;
  Image *img4 = new Image(w1,h1);
  i3.open("labeled.txt");
  ofstream o2("output_task<7>_imt<IMT2016096>.ppm");
  o2<<"P3"<<endl;
  o2<<w1<<" "<<h1<<endl;
  o2<<255<<endl;

  for(int i=0;i<h1;i++)
  {
    for(int j=0;j<w1;j++)
    {
      i3>>n3;
      //cout<<i3;
      if(n3 == 0)
      {
        ((*img4).get_p()[i][j]).set_colour(255, 255, 255);
      }
      else if(n3%6 == 0 && n3!=0)
      {
        ((*img4).get_p()[i][j]).set_colour(255, 0, 0);
      }
      else if(n3%6 == 1)
      {
        ((*img4).get_p()[i][j]).set_colour(102, 204, 0);
      }
      else if(n3%6 == 2)
      {
        ((*img4).get_p()[i][j]).set_colour(0, 204, 204);
      }
      else if(n3%6 == 3)
      {
        ((*img4).get_p()[i][j]).set_colour(0,255,255);
      }
      else if(n3%6 == 4)
      {
        ((*img4).get_p()[i][j]).set_colour(255, 0, 255);
      }
      else if(n3%6 == 5)
      {
        ((*img4).get_p()[i][j]).set_colour(255, 255, 0);
      }

    }
  }
  i3.close();
  for(int i=0;i<h1;i++)
  {
    for(int j=0;j<w1;j++)
    {
      o2<<img4->get_p()[i][j]<<endl;
    }
  }

  o2.close();
  cout<<"Done"<<endl;
  return;
}
