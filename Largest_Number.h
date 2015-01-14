#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
bool compare(const string &s1,const string &s2) {
  //in compare function,if a==b,the return should be false;
  //The implementation of std::sort do not have a boundary detection, 
  //thus if you return true when two elements are equal, the iterator may probably go out.

  //this compare function is complex,there is a more easy function,think it
  int i1,i2,i1_begin,i2_begin;
  i1 = 0;
  i2 = 0;
  i1_begin = 0;
  i2_begin = 0;
  while (i1<s1.size() || i2<s2.size()) {
    if (i1 == s1.size()) {
      i2_begin = i2;
      i1 = i1_begin;
    }
    if (i2 == s2.size()) {
      i1_begin = i1;
      i2 = i2_begin;
    }
    if (s1[i1]>s2[i2]) {
      return 1;
    } else if (s1[i1]<s2[i2]) {
      return 0;
    } else {
      i1++;
      i2++;
    }
  }
  return 0;
}
class Solution {
  public:
    string largestNumber(vector<int> &num) {
      //stringstream ss;
      vector<string>vec;
      int i,temp;
      for (i = 0;i<num.size();i++) {
        temp = num[i];
        stringstream ss;
        ss<<temp;
        vec.push_back(ss.str());
        //vec.push_back(to_string(num[i]));
      }
      sort(vec.begin(),vec.end(),compare);
      //sort(vec.begin(),vec.end());
      string s;
      for (i = 0;i<vec.size();i++) {
        s += vec[i];
      }
      for (i = 0;i<s.size();i++) {
        if (s[i] != '0') {
          break;
        }
      }
      if (i == s.size())
        return "0";
      return s;

    }
};
