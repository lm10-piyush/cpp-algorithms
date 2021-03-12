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
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector <vector <int>> dp(n, vector <int> (n, 0));
        //BASE: for 1, 2 lengths pallindroms
        for (int i = 1; i <= 2; ++i) {
            for (int j = 0; j + i <= n; ++j) {
                if (s[j] == s[j+i-1])
                    dp[j][j+i-1] = i;
                else if (i == 2) dp[j][j+i-1] = max({dp[j][j+i-2], dp[j+1][j+i-1]});
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int j = 0; j+len <= n; ++j) {
                int k = j + len - 1;
                if (s[j] == s[k]) dp[j][k] = dp[j+1][k-1] + 2;
                else dp[j][k] = max(dp[j+1][k], dp[j][k-1]);
            }
        }
        return dp[0][n-1];
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;
    Solution sol;
    cout << sol.longestPalindromeSubseq(s);

    return 0;
}


/*
https://leetcode.com/problems/longest-palindromic-subsequence/

another practice problem: https://leetcode.com/problems/longest-palindromic-substring/

Building the ans from smaller lengths to larger lengths
f(l, r) => maximum length palindromic subsequence
f(l, r) = {
    if (s[l] == s[r]) dp[i][j] = dp[i+1][j-1] + 2;
    else dp[i][j] = max(dp[i+1][j], dp[i][j-1]); //becuase it is subsequence
}



for base case: do it mannually for length 1, 2 because we could have 2 types of pallindrome: 1) odd palindrome (aba), 2) even palindrome(abba)

NOTE: Greate part of this problem is: how to make reccurence or we can how to break the problem into subproblems. If you are thinking in this way that: 
moving left to right and every time do one of the two parts : 1) pick current element 2) leave it. Then check the palindrome, then this implementation 
would be messy, and you have also maintain the some array or mask to store the element you took. Then there would be 2^k cases. So, we have fix something. 
IF we think in this way, that always break the problem such that it is always palindrome, so we don't need to check for palindrome because it always be.
Thats why we have done in this way. First check for small lengths from those small lengths build the anwer for bigger lengths. 

*/