#ifndef _TRIANGLE
#define _TRIANGLE

#include "Shape.h"

class Triangle: public Shape {
 public:
  Triangle(double w, double h);
  ~Triangle();
  double GetArea(void);
  void PrintArea(std::ostream &s);  

 protected:

 private:
  double base, height;
  static int numTriag;
};

#endif // _TRIANGLE

  
