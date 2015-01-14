#include <vector>
using namespace std;
class Solution {
  public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
      int *f = new int[dungeon[0].size()];
      int i,j;
      i = dungeon.size() - 1;
      j = dungeon[i].size()-1;
      f[dungeon[i].size()-1] = dungeon[i][j];
      for (j = dungeon[i].size()-2;j>-1;j--) {
        if (dungeon[i][j]<dungeon[i][j]+f[j+1]) {
          f[j] = dungeon[i][j];
        } else {
          f[j] = dungeon[i][j]+f[j+1];
        }
      }
      for (i = dungeon.size()-2;i>-1;i--) {
        for (j = dungeon[i].size()-1;j>-1;j--) {
          if (j == dungeon[i].size()-1) {
            if (dungeon[i][j]<dungeon[i][j]+f[j]) {
              f[j] = dungeon[i][j];
            } else {
              f[j] = dungeon[i][j]+f[j];
            }
          } else {
            if (f[j]>f[j+1]) {
              if (dungeon[i][j]<dungeon[i][j]+f[j]) {
                f[j] = dungeon[i][j];
              } else {
                f[j] = dungeon[i][j]+f[j];
              }
            } else {
              if (dungeon[i][j]<dungeon[i][j]+f[j+1]) {
                f[j] = dungeon[i][j];
              } else {
                f[j] = dungeon[i][j]+f[j+1];
              }
            }
          }
        }
      }
      if (f[0]>0)
        return 1;
      return -f[0]+1;
    }
};
