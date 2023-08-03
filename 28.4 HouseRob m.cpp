// https://leetcode.com/problems/house-robber-ii/description/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int dp[N][2];
vector<int> nums;

int rob(int n)
{
    int p = nums.size() - 1;

    if (n <= 0)
        return 0;
    if (n == 1)
        return nums[1];

    if (dp[n][1] != -1)
        return dp[n][1];

    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;

    if (p % 2 == 0)
    {
        for(int i=1 ;i<=n;i++)
        {
            if(i%2 == 0)
            ans1 += nums[i];

            else
            ans2 += nums[i];
        }
        cout<<ans1<<" "<<ans2<<endl;
        int ans = max(ans1, ans2);
        return ans;
    }

    if (p % 2 == 1)
    {
        if(n > 1)
            ans3 += nums[n] + rob(n - 2);
        else if(n < p)
            ans4 += nums[n] + rob(n-2);
        
        cout<<ans3<<" "<<ans4;

        ans2=max(ans3,ans4);
        dp[n][1] = ans2;
    }
    return ans2;
}

int main()
{
    string input;
    cout << "Enter the elements of the array (press Enter to stop):" << endl;

    getline(cin, input);

    istringstream iss(input);
    int num;
    nums.push_back(0);
    while (iss >> num)
    {
        nums.push_back(num);
    }

    for (int i = 1; i <= nums.size(); i++)
        dp[i][1] = -1;

    // cout<<nums[1];

    cout << rob(nums.size() - 1) << endl;

    return 0;
}