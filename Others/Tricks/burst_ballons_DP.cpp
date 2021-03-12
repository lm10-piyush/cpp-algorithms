#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector <int> blns(1, 1);
        for (int i: nums) blns.push_back(i);
        blns.push_back(1);
        auto profit = [&](int i, int l, int r) {
            return blns[i] * blns[l] * blns[r];
        };
        vector <vector <int>> dp(n+1, vector <int>(n+1, 0));
        for (int left = n; left >= 1; left--) {
            for (int right = left; right <= n; ++right) {
                if (left == right) dp[left][right] = profit(left, left-1, left+1);
                else {
                    //k = left
                    dp[left][right] = dp[left+1][right] + profit(left, left-1, right+1);
                    //k = right;
                    dp[left][right] = max(dp[left][right], dp[left][right-1] + profit(right, left-1, right + 1));
                    for (int k = left+1; k < right; ++k) {
                        dp[left][right] = max(dp[left][right], dp[left][k-1] + dp[k+1][right] + profit(k, left-1, right+1));
                    }
                }
            }
        }
        return dp[1][n];
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A) cin >> i;
    Solution sol;
    cout << sol.maxCoins(A);

    return 0;
}


/*
https://leetcode.com/problems/burst-balloons/

Meaning to DP with states
dp[left][right] => maximum profit can make by bursting ballons ONLY in range [left, right]
So, the ballons outside this range remains same.

dp[left][right] = max{dp[left][k-1] + dp[k+1][right] + profit(to burst kth ballon at last)}
k => to burst 'kth' ballon at last
left <= k <= right

NOTE: we did intentionally that: to burst kth ballon at last, it helps to keep left and right segment separate and independent. 
If we burst kth ballon at first then the both left and right segments combines which will be harder to maintain.

*/