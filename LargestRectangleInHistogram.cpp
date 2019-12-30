// Leetcode 84, Largest Rectangle In Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	int largestRectangleArea(vector<int>& heights)
	{
		if (heights.empty())
			return 0;

		heights.push_back(0);
		int result = 0;
		stack<int> st;

		for (int i = 0; i < heights.size(); i++)
		{
			int r = i - 1, l = 0, h = 0;

			while (!st.empty() && heights[i] < heights[st.top()])
			{	
				int topVal = st.top();
				st.pop();
				h = heights[topVal];

				// *** In here we need to consider the maximum width (a.k.a. minimum l)
				// for the current height. So l should be minimum as much as possible
				// in a ***greedy*** manner.
				l = !st.empty() ? st.top() + 1 : 0; 
				result = std::max(result, calcArea(l, r, h));
			}

			st.push(i);
			// So for every given i, which equivalently means for every heights[i], it is going
            // to be evalauted in the while loop above. So we won't miss any possible answers.
		}

		return result;
	}
private:
	int calcArea(int l, int r, int h)
	{
		return (r - l + 1) * h;
	}
};

int main ()
{
	Solution solution;
	vector<int> test1 = {2,1,3,4,2,3};
	auto result = solution.largestRectangleArea(test1);
	cout << result << endl;

	vector<int> test2 = {2,1,5,6,2,3};
	result = solution.largestRectangleArea(test2);
	cout << result << endl;
}
