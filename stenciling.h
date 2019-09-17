#include "math.h"
#include <algorithm>
#include "Image.h"
#include "Pixel.h"
#include "Colour.h"
#include "generate_holes.h"
#ifndef stenciling_H_
#define stenciling_H_
class stenciling :public Image
{
	private :
		int w,h;
public:
	stenciling(Image *i,int w,int h);
	Image* Stenciling(Image *i);
	};
#endif
