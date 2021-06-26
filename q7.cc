/* Luis A. Flores Carrubio
    14/12/2020 INM359 */

#include <iostream>
#include <iomanip>      // std::setw
#include <sstream>      // std::ostringstream
#include <string>
#include <map>
#include <utility>      // std::pair
#include <iterator>
#include <algorithm>

 /* add further includes here if you need to */

using namespace std;                  // File: q7.cc (for Q7–Q10)

/* Turn a token to a string - tokens cannot contain spaces or other characters that are not valid for a variable name. */

#define X(token) #token
string null = X(NULL);

string department_names[] = {
   X(Sales) , X(Engineering) , X(Clerical) , X(Marketing) };

 string employee_names[] = {
   X(Rafferty) , X(Jones) , X(Heisenberg) , X(Robinson) , X(Smith), X(Williams) };

/* Table department: columns = DepartmentID, DepartmentName */
map<int, string *> department = {
                                  {31, department_names+0}
                                 ,{33, department_names+1}
                                 ,{34, department_names+2}
                                 ,{35, department_names+3} };

/* Table employee: columns = LastName, DepartmentID */
map<string *, int> employee = {
                                {employee_names+0, 31}
                               ,{employee_names+1, 33}
                               ,{employee_names+2, 33}
                               ,{employee_names+3, 34}
                               ,{employee_names+4, 34}
                               ,{employee_names+5,  0} };

string get_null_or_X(int x) {
  ostringstream os;  os << setw(15);
  if (0 == x) os << null ;
  else        os << x ;

  return os.str();
}

string get_null_or_X(const string *x) {
  ostringstream os;  os << setw(15);
  if (nullptr == x) os << null ;
  else              os << *x ;

  return os.str();
}

string get_null_or_X(const char *x) {
  ostringstream os;
  os << setw(15) << x ;

  return os.str();
}

bool comp(const pair<int, string*> &key, const pair<int, string*> &value)
{
    //cout << *key.second << " " << *value.second << endl;
    return (*key.second < *value.second);
}

void print_dep() {
  cout << get_null_or_X(X(DepartmentID)) << get_null_or_X(X(DepartmentName))<< endl;

  /* YOUR CODE HERE */
//    map<int, string*>::iterator itr;
//
//    for(itr = department.begin(); itr != department.end(); ++itr)
//        cout << '\t' << itr->first << '\t' << *itr->second << '\n';

    vector<pair<int, string*>> v;
    for(auto it = department.cbegin(); it != department.cend(); ++it)
        v.push_back(*it);

    vector<pair<int, string*>>::iterator itr2;
    vector<pair<int, string*>>::iterator itr3;
    itr2 = v.begin(); itr3 = v.end();

    sort(itr2, itr3, comp);

    for(auto x : v)
        cout << '\t' <<x.first << '\t' << *x.second << endl;

    cout << '\n';
}

void print_emp() {
  cout << get_null_or_X(X(LastName)) << get_null_or_X(X(DepartmentID))<< endl;

  /* YOUR CODE HERE */
  int counter = 0;
  map<string*, int>::iterator itr;
    for(itr = employee.begin(); itr != employee.end(); ++itr){
        if (counter == 0 || counter == 2 || counter == 3 || counter == 5)
            cout << '\t' << *itr->first << '\t' << itr->second << '\n';
        else
            cout << '\t' << *itr->first << '\t' << '\t' << itr->second << '\n';
        counter++;
    }
    cout << '\n';

}

void print_inner_join() {

  cout << get_null_or_X(X(LastName)) << get_null_or_X(X(DepartmentID)) << get_null_or_X(X(DepartmentName))<< endl;

  /* YOUR CODE HERE */
    int count = 0;
    map<int, string*>::iterator itr;    //department
    map<string*, int>::iterator itr2; //employee

    // Using iterators for comparisons
    for(itr = department.begin(); itr != department.end(); ++itr){
            for(itr2 = employee.begin(); itr2 != employee.end(); ++itr2){
                if(itr->first == itr2->second){
                    if(count == 1 || count == 4)
                        cout << '\t' << *itr2->first << '\t' << '\t' << itr->first << '\t' << *itr->second << '\n';
                    else
                        cout << '\t' << *itr2->first << '\t' << itr->first << '\t' << *itr->second << '\n';
                count++;
                } // outer if
            }// inner for
    }// outer for

    cout << '\n';

}

int main() {
  print_dep();
  print_emp();
  print_inner_join();
  return 0;

}
