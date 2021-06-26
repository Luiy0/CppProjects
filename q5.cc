/* Luis A. Flores Carrubio
    12/12/2020 INM359 */

#include <iostream>
#include <vector>
using namespace std;        // File: q5.cc

class zample {
  vector<int> vi;

 public:
  zample(vector<int> some_vi) : vi(some_vi) {} // constructor
  const vector<int> & get_data() const { return vi; } // accesing vector

};

/* Put your code here */
ostream& operator << (ostream& out,  const zample& z ){
    out << "<";
    out << z.get_data().size();
    out << ": ";

    for(size_t x =0; x < static_cast<size_t> (z.get_data().size()); ++x){
            out << z.get_data().at(x);

            if (x != static_cast<size_t> (z.get_data().size()) - 1){
                out << " "; }
    }

    out << ">";
    return out;
}

istream& operator >> (istream& inputStream, zample& z){

    char colon, l_sign, r_sign;
    int value;  size_t len;

    std::vector<int> temp;

    if (inputStream >> l_sign) {
        if ((inputStream >> len >> colon) && (l_sign == '<' && colon == ':' && len > 0)){
            for (size_t x=0; x<len; ++x){
                if (inputStream >> value)
                    temp.push_back(value);
                else
                    inputStream.setstate(ios::badbit);
            }

            if (inputStream >> r_sign && r_sign == '>')
                z = zample(temp);
        }
    }
    else
        inputStream.setstate(ios::badbit);

    return inputStream;
}


// NO changes allowed here
int main() {

  vector<int> vi = {11, 12, 13, 14, 15};
  zample z1(vi);
  cout << z1 << endl; /* should print: <5: 11 12 13 14 15> I.e., <size: elements> */
  cin >> z1 >> z1; /* should be able to read “<5: 11 12 13 14 15><6: 21 22 23 24 25 26>a” (two samples on the same line, stuck together, with a character ‘a’ immediately following the 2nd one. */
  cout << z1 << endl; /* should print: <6: 21 22 23 24 25 26> */
  char c;
  cin >> c; cout << c << endl; /* should print ‘a’ – the char after the 2nd zample above. */
  return 0;

}
