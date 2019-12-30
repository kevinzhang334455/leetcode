// Leetcode 337, House Robber III
// https://leetcode.com/problems/house-robber-iii/

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// We can use BFS
class Solution
{
public:
	int Rob(TreeNode* root)
	{
		if (!root)
			return 0;

		int result = 0;
		queue<queueData> q;
		queueData rootData(root, root->val, 0);
		q.emplace(root, root->val, 0);

		while(!q.empty())
		{
			auto curr = q.front();
			q.pop();

			result = std::max(
				result, 
				std::max(curr.maxTakeNode, curr.maxNotTakeNode));

			if (curr.treeNode->left != nullptr)
			{
				q.emplace(curr.treeNode->left, 
					curr.maxNotTakeNode + curr.treeNode->left->val,
				    curr.maxTakeNode);
			}

			if (curr.treeNode->right != nullptr)
			{
				q.emplace(curr.treeNode->right,
					curr.maxNotTakeNode + curr.treeNode->right->val,
					curr.maxTakeNode);
			}
		}

		return result;
	}

private:
	struct queueData
	{
		TreeNode* treeNode;

		int maxTakeNode;
		int maxNotTakeNode;

		queueData(TreeNode* node, int take, int notTake): 
		treeNode(node),
		maxTakeNode(take),
		maxNotTakeNode(notTake)
		{		
		}
	};
};

int main()
{
	TreeNode *n0 = new TreeNode(3);
	TreeNode *n1 = new TreeNode(7);
	TreeNode *n2 = new TreeNode(5);
	TreeNode *n3 = new TreeNode(8);
	TreeNode *n4 = new TreeNode(12);
	TreeNode *n5 = new TreeNode(11);
	TreeNode *n6 = new TreeNode(2);
	TreeNode *n7 = new TreeNode(2);

	n0->left = n1;
	n0->right = n2;
	n1->right = n3;
	n2->right = n4;
	n4->left = n5;
	n4->right = n6;
	n6->right = n7;

	Solution solution;

	std::cout << solution.Rob(n0) << std::endl;

	return 0;
}