#include "Histogram.h"
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
Histogram::Histogram(int a, int b):Image(a, b){
  int i;
  count=0;
  for(i=0;i<6;i++)
    c[i]=0;
  for(i=0;i<256;i++){
    freq[i]=0;
  }

}
void Histogram::set_freq(){
  int i, j, k;
  //cout<<(*this).get_h()<<" "<<(*this).get_w()<<endl;
  for(i=0;i<(*this).get_h();i++){
    for(j=0;j<(*this).get_w();j++){
      k=((*this).get_p()[i][j]).get_c().get_red() + ((*this).get_p()[i][j]).get_c().get_green() + ((*this).get_p()[i][j]).get_c().get_blue();
      //cout<<((*this).get_p()[i][j]).get_c().get_red()<<" "<<((*this).get_p()[i][j]).get_c().get_green()<<" "<<((*this).get_p()[i][j]).get_c().get_blue()<<endl;
      k=k/3;
      //cout<<k<<" ";
      freq[k]++;
    }
  }
  for(i=1;i<255 && count<6;i++){
    //cout<<freq[i]<<" ";
    if(freq[i]<freq[i-1] && freq[i]<freq[i+1]){
      c[count]=i;
      count++;
    }
  }
}
void Histogram::change_image(){
  if(count==0){
    int i, j;
    //cout<<"varada\n";
    for(i=0;i<(*this).get_h();i++){
      for(j=0;j<(*this).get_w()/2;j++){
        Colour c=(*this).get_p()[i][j].get_c();
        Colour c1=(*this).get_p()[i][(*this).get_w()-1-j].get_c();
        (*this).get_p()[i][j].set_colour((0.6)*c.get_red()+0.4*c1.get_red(),
                                         (0.6)*c.get_green()+0.4*c1.get_green(),
                                         (0.6)*c.get_blue()+0.4*c1.get_blue());
        (*this).get_p()[i][(*this).get_w()-1-j].set_colour((0.6)*c1.get_red()+0.4*c.get_red(),
                                         (0.6)*c1.get_green()+0.4*c.get_green(),
                                         (0.6)*c1.get_blue()+0.4*c.get_blue());
      }
    }
    return;
  }
  int i, j, k, temp;
  for(i=0;i<(*this).get_h();i++){
    for(j=0;j<(*this).get_w();j++){
      temp=((*this).get_p()[i][j]).get_c().get_red() + ((*this).get_p()[i][j]).get_c().get_green() + ((*this).get_p()[i][j]).get_c().get_blue();
      temp=temp/3;
      for(k=0;k<count;k++){
        if(c[k]>temp){
          break;
        }
      }
      Pixel*p1 = new Pixel();
      if(k==0){
        (*p1).set_colour(255, 0, 0);
      }
      else if(k==1){
        (*p1).set_colour(0, 255, 0);
      }
      else if(k==2){
        (*p1).set_colour(0, 0, 255);
      }
      else if(k==3){
        (*p1).set_colour(255, 255, 0);
      }
      else if(k==4){
        (*p1).set_colour(255, 0, 255);
      }
      else if(k==5){
        (*p1).set_colour(0, 255, 255);
      }
      else{
        (*p1).set_colour(0, 0, 0);
      }
      (*this).get_p()[i][j].set_colour((0.6)*((*this).get_p()[i][j]).get_c().get_red()+0.4*(*p1).get_c().get_red(),
                                       (0.6)*((*this).get_p()[i][j]).get_c().get_green()+0.4*(*p1).get_c().get_green(),
                                       (0.6)*((*this).get_p()[i][j]).get_c().get_blue()+0.4*(*p1).get_c().get_blue());
    }
  }
}/*
int main(int argc, char* argv[]){
  string type;
  int maxcolor, he, w, r, g, b;
  ifstream fin;
  ofstream fout;
  fin.open("fruit.ppm");
  fout.open("something.ppm");
  fin>>type>>w>>he>>maxcolor;
  Histogram* h=new Histogram(w, he);
  (*h).populate_pixels(fin);
  h->set_freq();
  h->change_image();
  fout<<type<<endl<<h->get_w()<<" "<<h->get_h()<<endl<<maxcolor<<endl<<*h;
  fin.close();
  fout.close();
}*/
