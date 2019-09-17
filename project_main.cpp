#include "Image.h"
#include "Colour.h"
#include "Pixel.h"
#include "Pixel.h"
#include "ScaledImage.h"
using namespace std;
int main(int argc, char **argv)
{
  int wt, ht, maxCol;
  std::string str;
  std::ifstream file;
  file.open(argv[1]);
  file >> str;
  file >> wt >> ht;
  file >> maxCol;
  Image im(wt, ht);
  //cout<<"adfg";
  im.populate_pixels(file);
  file.close();
  ScaledImage sc(wt, ht);
  sc.createPI(im);
  //cout<<"adfg";
  std::ofstream outFile("dev.ppm");
  outFile << str << endl;
  outFile << wt << " " << ht << endl;
  outFile << maxCol << endl;
  outFile << sc;
  outFile.close();
  exit(0);
  return 0;
}
