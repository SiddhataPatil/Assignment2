/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) 
{
    vector<vector<int> > result;
    if (!A) return result;
    map <int,vector<int> > m;
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(A, 0)); 
    while(!q.empty()) 
    {
        pair<TreeNode*,int> front = q.front();
        q.pop();
        int currentHorizontalDistance = front.second;
        TreeNode* currentTreeNode = front.first;
        m[currentHorizontalDistance].push_back(currentTreeNode -> val);
        if (currentTreeNode -> left != NULL) 
        {
             q.push(make_pair(currentTreeNode -> left, currentHorizontalDistance - 1));
        }
        if (currentTreeNode -> right != NULL) 
        {
            q.push(make_pair(currentTreeNode -> right, currentHorizontalDistance + 1));
        }
    }
    for (map<int,vector<int> > :: iterator it = m.begin(); it != m.end(); it++) 
    {
        result.push_back(it -> second);
    }
    return result;
}
