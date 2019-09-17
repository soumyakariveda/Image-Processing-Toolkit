#include "math.h"
#include <algorithm>
#include "Image.h"
#include "Pixel.h"
#include "Colour.h"
#include "generate_holes.h"
#ifndef clipping_H_
#define clipping_H_
class clipping :public Image
{
    private :
    int w,h;
public:
    clipping(Image *i,int w,int h);
    Image* Clipping(Image *i);
 };
#endif
