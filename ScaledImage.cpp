#include "ScaledImage.h"

using namespace std;
ScaledImage::ScaledImage()  {}

ScaledImage::~ScaledImage() {}

ScaledImage::ScaledImage(int wt, int ht): Image(wt, ht){
}

void ScaledImage::createPI(Image im){
  int wt = im.get_w();
  int ht = im.get_h();
  Pixel **pix = im.get_p();

  pi = new Pixel *[ht];
  for(int i = 0; i < ht; i++){
    pi[i] = new Pixel[wt];
  }
  for(int i = 0; i < ht; i+=2){
    for(int j = 0; j < wt; j+=2){
        pi[i/2][j/2].set_colour(pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){
    for(int j = 0; j < wt; j+=2){
        pi[i/2][wt - j/2 - 1].set_colour(pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){
    for(int j = 0; j < wt; j+=2){
        pi[ht - i/2 - 1][wt - j/2 - 1].set_colour(pix[i][j].get_c());
    }
  }
  for(int i = 0; i < ht; i+=2){
    for(int j = 0; j < wt; j+=2){
        pi[ht - i/2 - 1][j/2].set_colour(pix[i][j].get_c());
    }
  }
  for(int i=0;i<ht;i++){
    for(int j=0;j<wt;j++){
      if(i<ht/4||j<wt/4||i>3*ht/4||j>3*wt/4){
        pi[i][j].set_colour(255,255,255);
      }
    }
  }
}

Pixel** ScaledImage::getPI(){
  return pi;
}

std :: ostream& operator<<(std :: ostream &os, ScaledImage &sim)
{
  for(int i = 0; i < sim.get_h(); i++)
  {
    for(int j = 0; j < sim.get_w(); j++)
    {
      os << sim.pi[i][j] << " ";
    }
    os <<'\n';
  }
  return os;
}
