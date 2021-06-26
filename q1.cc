/* Luis A. Flores Carrubio
    11/12/2020 INM359 */

#include <iostream>
using namespace std;    // File: q1.cc

class some_class {
  int state;

 public:
  some_class(int s = 3) : state(s) {}  // constructor
  int get_state();
  void set_state(int s);

};


/* Your code here */
void some_class::set_state(int s){ state = s; } // set state to the given value

int some_class::get_state(){ return state; } // return the state

int main() {

  some_class c1;
  c1.set_state(5);
  cout << c1.get_state() << endl; // should print 5
  return 0;

}
