/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) 
{
       TreeLinkNode* a = NULL;
        TreeLinkNode* previous = NULL; 
        TreeLinkNode* c = A;
        while (c != NULL) 
        {
            while (c != NULL) 
            {
                if (c->left != NULL) 
                {
                    if (previous != NULL) 
                    {
                        previous->next = c->left;
                    } 
                    else 
                    {
                        a = c->left;
                    }
                    previous = c->left;
                }
                if (c->right != NULL) 
                {
                    if (previous != NULL) 
                    {
                        previous->next = c->right;
                    } 
                    else 
                    {
                        a = c->right;
                    }
                    previous = c->right;
                }
                c = c->next;
            }
            c = a;
            a = NULL;
            previous = NULL;
        }
    }

