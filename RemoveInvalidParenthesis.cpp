#include <vector>
#include <stack>
#include <string>
#include <iostream>

using std::vector;
using std::stack;
using std::string;
using std::cout;
using std::endl;
using std::pair;

// DFS. Seems this one is hard to get it work.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        string curr = "";
        stack<int> st;
        int targetLength = findCorrectLength(s);
        dfs(s, curr, targetLength, 0, st, result);
        return result;
    }
private:
	int findCorrectLength(string s)
	{
		stack<int> st;
		int result = s.size();
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') {
				st.push(i);
			} else if (s[i] == ')') {
				if (!st.empty()) {
					st.pop();
				} else {
					--result;
				}
			}
		}

		return result - st.size();
	}

	void dfs(
		const string& s, 
		string curr, 
		const int targetLength,
		int idx, 
		stack<int> st, 
		vector<string>& res)
	{
		for (int i = idx; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] != ')')
			{
				curr.push_back(s[i]);

				if (s[i] == '(')
					st.push(curr.size() - 1);
			}
			else if (!st.empty())
			{
				int top_idx = st.top();
				st.pop();
				curr.push_back(s[i]);
				dfs(s, curr, i + 1, st, res);
				curr.pop_back();
				st.push(top_idx);
			}
		}

		// Invariant idx == s.size();
		// Redundant left parenthesis, remove them.
		while (!st.empty())
		{
			curr.erase(curr.begin() + st.top());
			st.pop();
		}

		if (!curr.empty() && curr.size() == targetLength)
		{
			res.push_back(curr);
		}
	}
};

void unitTest(string s)
{
	Solution solution;
   	auto res = solution.removeInvalidParentheses(s);
   	for (const auto& r : res)
   	{
   		cout << r << endl;
   	}

   	cout << endl;
}

int main ()
{
	string test1("(()()(())");
	unitTest(test1);

	return 0;
}