class Solution {
  public:
    int maximumGap(vector<int> &num) {
      if (num.size()<2)
        return 0;
      sort(num.begin(),num.end());
      int max,i;
      max = num[1]-num[0];
      for (i = 1;i<num.size();i++) {
        if (num[i]-num[i-1]>max) {
          max = num[i]-num[i-1];
        }
      }
      return max;
    }
}

