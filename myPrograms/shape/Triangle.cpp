#include "Triangle.h"

int Triangle::numTriag = 0;

Triangle::~Triangle() {
  numTriag--;
  std::cout << "Triangle Destructor\n";
}

Triangle::Triangle(double b, double d)
  :Shape(), base(b), height(d)
{
  numTriag++;
}

double
Triangle::GetArea(void) {
  return 1/2*base*height;
}

void 
Triangle::PrintArea(std::ostream &s) {
  s << "Triangle: " << 1/2 * base * height << " numRect: " << numTriag << "\n";
}

