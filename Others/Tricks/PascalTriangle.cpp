#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector <vector<int>> dp(2, vector<int> (n+1));
        for (int row = 0; row <= n; ++row) {
            int prev = !(row & 1);  //for previous row
            for (int j = 0; j <= row; ++j) {
                if (j == 0 || j == row) {
                    dp[row & 1][j] = 1;
                }
                else dp[row & 1][j] = dp[prev][j-1] + dp[prev][j];
            }
        }
        
        return dp[n & 1];
    }
};
 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    Solution sol;
    vector <int> ans = sol.getRow(n); //nth row
    for (int i: ans) cout << i << " ";

    return 0;
}

//https://leetcode.com/problems/pascals-triangle-ii/
/*
 * we need just previous row to calculate current row, so need to store whole data, just
   create a matrix of 2 x N, it is fine, and fill the data alternatively in the row.
   Current row will be row & 1, and previous row would be !(row & 1)


https://practice.geeksforgeeks.org/contest-problem/tie-the-poles-in-pairs/0/  (problem on catalan number)
Catalan(n) = (1/(n+1)) * 2nCn 

https://leetcode.com/problems/champagne-tower/
https://pastebin.com/Kg7wZN4u

*/
