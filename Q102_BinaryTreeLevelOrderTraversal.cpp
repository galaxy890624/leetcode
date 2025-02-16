#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // stack lifo
        // queue fifo
        queue<TreeNode*> q;
        // 2d array
        vector<vector<int>> ans;
        // Enqueue(加入佇列) the root node if root node exist
        if(root)
        {
            q.push(root);
        }
        
        while(!q.empty())
        {
            // Record the number of nodes at the current level
            int level_size = q.size(); 
            
            vector<int> level;
            
            while(level_size-- > 0)
            {
                // Dequeue the front node of the queue
                TreeNode* cur = q.front(); q.pop(); 
                // Record the value of the current node
                level.push_back(cur  ->  val); 
                
                if(cur  ->  left)
                {
                    // Enqueue the left child (if it exists)
                    q.push(cur  ->  left); 
                }
                if(cur  ->  right)
                {
                    // Enqueue the right child (if it exists)
                    q.push(cur  ->  right); 
                }
            }
            // Add the level's values to the result vector
            ans.push_back(level);
        }
        
        return ans;
    }
};

// Function to print 2D vector
void printLevelOrder(const vector<vector<int>>& levelOrder)
{
    cout << "[";
    for (size_t i = 0; i < levelOrder.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < levelOrder[i].size(); j++)
        {
            cout << levelOrder[i][j];
            if (j != levelOrder[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != levelOrder.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

int main()
{
    Solution Sol;
    // Test case
    // Create a sample binary tree:
    //        3
    //       / \
    //      9  20
    //        /  \
    //       15   7
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    vector<vector<int>> levelOrderResult = Sol.levelOrder(root);
    printLevelOrder(levelOrderResult);

    return 0;
}