/* Luis A. Flores Carrubio
    13/12/2020 INM359 */

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;        // File: q6.cc

template <typename X>
class zamplex {
  list<X> vi;

 public:
  zamplex(list <X> some_vi);
  const list <X> & get_data() const;

}; // class

/* a) Put your code here to get it to compile */
//template <typename X>
//zamplex( list <X> some_vi){
//    for(list<X>::iterator x = begin(some_vi); x != end(some_vi); ++x)
//        vi.push_back(some_vi.pop_back());
    // must have  a trailing return type?
//}


int main() {

//  list<float> lf = {11, 12, 13};
//  zamplex<float> z1(lf);
//  const list<float> & lfr = z1.get_data();

/* b) Put your code here to print the elements of lfr. */
//    for (size_t x = 0; x < lfr.size(); ++x)
//        lfr.pop_back();

  return 0;
}
