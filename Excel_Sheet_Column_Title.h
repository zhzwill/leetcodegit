class Solution {
  public:
    string convertToTitle(int n) {
      string s;
      if (n<1)
        return s;
      int i;
      i = 0;
      int temp;
      temp = n-1;
      char ch;
      while (true) {
        ch = char(temp%26+65);
        s = s.insert(0,1,ch);
        if (temp<26)
          break;
        temp = temp/26;
        temp--;
      }
      return s;
    }
};
