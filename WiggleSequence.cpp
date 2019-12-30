#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// DP
// TC: O(n^2)
// SC: O(n)
// dp[2 * i + 1] -- stores result which nums[i] - nums[j] < 0
// dp[2 * i] -- vice versa

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        vector<int> dp(2 * N, 1);
        
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] - nums[j] > 0)
                {
                    dp[2 * i] = max(dp[2 * i], dp[2 * j + 1] + 1);
                }
                else if (nums[i] - nums[j] < 0)
                {
                    dp[2 * i + 1] = max(dp[2 * i + 1], dp[2 * j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution S;
    vector<int> test1 = { 1,17,5,10,13,15,10,5,16,8 };
    cout << S.wiggleMaxLength(test1) << endl;
}