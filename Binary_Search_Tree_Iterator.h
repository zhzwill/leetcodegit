#include <vector>
#include <stack>
using namespace std;
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x): val(x),left(NULL),right(NULL){}
   };
class BSTIterator {
  vector<int>vec;
  stack<TreeNode*>sta;
  int i;
  public:
    BSTIterator(TreeNode *root) {
      i = 0;
      TreeNode *p = root;
      while (p != NULL || !sta.empty()) {
        if(p != NULL) {
          sta.push(p);
          p = p->left;
        } else {
          p = sta.top();
          sta.pop();
          vec.push_back(p->val);
          p = p->right;
        }
      }
    }

    bool hasNext() {
      if (i == vec.size()) {
        return false;
      }
      return true;
    }

    int next() {
      if (hasNext()) {
        return vec[i++];
      }
    }
};
