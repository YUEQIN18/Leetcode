#include <stddef.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
  int maxCount; // 最大频率
  int count;    // 统计频率
  TreeNode *pre;
  vector<int> result;
  void searchBST(TreeNode *cur)
  {
    if (cur == NULL)
      return;

    searchBST(cur->left); // 左
                          // 中
    if (pre == NULL)
    { // 第一个节点
      count = 1;
    }
    else if (pre->val == cur->val)
    { // 与前一个节点数值相同
      count++;
    }
    else
    { // 与前一个节点数值不同
      count = 1;
    }
    pre = cur; // 更新上一个节点

    if (count == maxCount)
    { // 如果和最大值相同，放进result中
      result.push_back(cur->val);
    }

    if (count > maxCount)
    {                   // 如果计数大于最大值频率
      maxCount = count; // 更新最大频率
      result.clear();   // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
      result.push_back(cur->val);
    }

    searchBST(cur->right); // 右
    return;
  }

public:
  vector<int> findMode(TreeNode *root)
  {
    count = 0;
    maxCount = 0;
    TreeNode *pre = NULL; // 记录前一个节点
    result.clear();

    searchBST(root);
    return result;
  }
};

/*
中序遍历的迭代法
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int maxCount = 0; // 最大频率
        int count = 0; // 统计频率
        vector<int> result;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top();
                st.pop();                       // 中
                if (pre == NULL) { // 第一个节点
                    count = 1;
                } else if (pre->val == cur->val) { // 与前一个节点数值相同
                    count++;
                } else { // 与前一个节点数值不同
                    count = 1;
                }
                if (count == maxCount) { // 如果和最大值相同，放进result中
                    result.push_back(cur->val);
                }

                if (count > maxCount) { // 如果计数大于最大值频率
                    maxCount = count;   // 更新最大频率
                    result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
                    result.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};
*/