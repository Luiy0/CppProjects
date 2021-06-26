/* Luis A. Flores Carrubio
    11/12/2020 INM359 */

#include <iostream>
using namespace std;    // File: q2.cc

class my_array_class {
  int len = 2; // Array length (size_t ?)
  int *a = new int [2];

 public:
    // Constructor initializing array elements
  my_array_class() { a[0] = 1; a[1] = 2; }

    // Constructor initializinng both member variables
    // ln is user length, a is a pointer to the first element of the array
  my_array_class(int ln, const int * arr) : len(ln), a(new int [ln]){
      for (int n=0; n<ln; ++n) a[n] = arr[n];  }

      // Destructor
 ~my_array_class() { delete[] a; }

    // Getting element at n
    int get(int n) const { return a[n]; }

     // swap element at position n for integer v
 int set(int n, int v) {
     int tmp = a[n]; // storing value at position n
     a[n] = v; // changing value at position n for v
     return tmp;  }

};


// Do not change code below
void foo( const my_array_class & a2 ) {
   std::cout << a2.get(0) << std::endl;
}

// Do not change code below
int main() {

  int zero12[] = {13, 1, 2};
  my_array_class a1(3, zero12);
  foo(a1);
  return 0;

}
