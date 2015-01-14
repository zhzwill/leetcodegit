#include <string>
#include <map>
#include <sstream>
using namespace std;
//pay attention on -2147483648 and 2147483647 is the limit of int!!!(32)
class Solution {
  public:
    string fractionToDecimal(int numerator, int denominator) {
      if (-2147483648 == numerator && -1 == denominator) {
        return "2147483648";
      }
      map<int,int>map1;
      int num;
      string s;
      num = numerator/denominator;
      if (num == 0) {
        if (numerator>0 &&denominator<0 ||numerator<0 &&denominator>0) {
          s += "-";
        }
      }
      //string s;
      numerator = numerator % denominator;
      stringstream ss;
      ss<<num;
      s += ss.str();
      //s += to_string(num);
      if (numerator == 0) {
        return s;
      }
      s += '.';
      int begin,end;
      begin = s.size();
      end = s.size();
      int temp;
      while(true) {
        if (map1.find(numerator) != map1.end()) {
          break;
        }
        if (numerator>0) {
          numerator = -numerator;
        }
        if (denominator>0) {
          denominator = -denominator;
        }
        if (numerator %2 == 0 && denominator%2 == 0) {
          numerator = numerator/2;
          denominator = denominator/2;
        }
        map1.insert(pair<int,int>(numerator,s.size()));
        num = numerator*10/denominator;
        stringstream ss1;
        ss1<<num;
        s += ss1.str();
        //s += to_string(num);
        numerator = (numerator*10) % denominator;
        if (numerator == 0) {
          return s;
        }
      }
      s.insert(map1[numerator],"(");
      s += ")";
      return s;
    }
};
