#include <string>
using namespace std;
class Solution {
  public:
    int compareVersion(string version1, string version2) {
      int s1_begin,s1_end;
      int s2_begin,s2_end;
      s1_begin = 0;
      s2_begin = 0;
      while (s1_begin < version1.size() && s2_begin < version2.size()) {
        s1_end = s1_begin+1;
        s2_end = s2_begin+1;
        while(s1_end != version1.size()) {
          if (version1[s1_end] == '.') {
            break;
          }
          s1_end++;
        }
        while(s2_end != version2.size()) {
          if (version2[s2_end] == '.') {
            break;
          }
          s2_end++;
        }
        if (atoi(version1.substr(s1_begin,s1_end-s1_begin).c_str())>atoi(version2.substr(s2_begin,s2_end-s2_begin).c_str())) {
          return 1;
        } else if (atoi(version1.substr(s1_begin,s1_end-s1_begin).c_str())<atoi(version2.substr(s2_begin,s2_end-s2_begin).c_str())) {
          return -1;
        } else {
          s1_begin = s1_end+1;
          s2_begin = s2_end+1;
        }
      }
      while (s1_begin < version1.size()) {
        if (version1[s1_begin] >='1' && version1[s1_begin]<='9')
          return 1;
        s1_begin++;
      }
      while (s2_begin < version2.size()) {
        if (version2[s2_begin]>='1' && version2[s2_begin]<='9')
          return -1;
        s2_begin++;
      }
      return 0;
    }
};
