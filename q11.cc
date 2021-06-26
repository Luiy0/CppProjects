/* Luis A. Flores Carrubio
    13/12/2020 INM359 */
#include <iostream>

using namespace std;      // File: q11.cc

class my_array_mem {
    int len = 1;
    int *a = new int [1];

 public:
    my_array_mem() { a[0] = 0; }
    my_array_mem(int l, const int *o) : len(l), a(new int [l]){ for (int n=0; n<l; ++n) a[n] = o[n];   }
    ~my_array_mem() { delete[] a; }
    int get(int n) {return a[n];}
    int set(int n, int v) { int tmp = a[n]; a[n] = v; return tmp; }

 /* Put your code here. Don’t change the code in gray. */

 // Overloading equal operator
 my_array_mem& operator = (my_array_mem& b){
    if (&b != this){
        delete [] a; len = b.len;
        a = new int[len];

        for (int x=0; x<len; ++x)
            a[x] = b.get(x);
    }
    return *this;
 } //  Equal operator overloader

 //Copy Constructor
 my_array_mem(my_array_mem& b): len(b.len), a(new int[b.len])    {
    for(size_t x = 0; x<static_cast<size_t>(len); ++x)
        a[x] = b.get(x);
 } // Copy Constructor

}; // class


void foo() {
    int zero12[] = {13, 14, 15};
    my_array_mem a1(3, zero12);
    my_array_mem a2 = a1;
    my_array_mem a3;
    a3 = a2;
    std::cout << a3.set(0, a2.get(1) ) << std::endl;
}

int main() {
    std::cout << 1 << std::endl;
    foo();
    std::cout << 3 << std::endl;
    return 0;
}
