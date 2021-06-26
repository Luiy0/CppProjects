/* Luis A. Flores Carrubio
    11/12/2020 INM359 */

#include <iostream>
using namespace std;      // File: q3.cc

class my_array_over {
  int len = 1;
  int *a = new int [1];

 public:
  my_array_over() { a[0] = 0;  } // Constructor

  my_array_over(int ln, const int *o) : len(ln), a(new int [ln]) {
        for (int n=0; n<ln; ++n) a[n] = o[n]; } // Constructor

  ~my_array_over() { delete[] a; }

  /* Put your code here */

  // Overloading operator
 operator[] (int index) const{ return a[index]; }

};

void foo( const my_array_over & a2 ) {
   std::cout << a2[0] << std::endl;
}

int main() {

  int zero12[] = {13, 1, 2};
  my_array_over a1(3, zero12);
  foo(a1);
 return 0;

}
