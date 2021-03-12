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
    string longestPalindrome(string s) {
        int n = s.size();
        vector <vector <int>> dp(n, vector <int>(n, 0));
        //BASE CASE: setting as for 1, 2 lenght palindromes
        
        int ans = 1, idx = 0;
        for (int len = 1; len <= 2; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) 
                    dp[i][j] = len;
                if (ans < dp[i][j]) {
                    ans = dp[i][j];
                    idx = i;
                }
            }
        }
        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] and dp[i+1][j-1]) dp[i][j] = dp[i+1][j-1] + 2;
                if (ans < dp[i][j]) {
                    ans = dp[i][j];
                    idx = i;
                }
            }
        }
        return s.substr(idx, ans);
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    string s; cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s);

    return 0;
}



/*
 * When a problem requires alot of case work then go for generalized solution.
 * For generalization: smart brute-force, converting into different problem, efficient simulation etc.
 * Stay calm, give your best.
 * Whenever you start practising the only goal should be to improve yourself by:
    learning new ideas, building focus, giving 100% etc.
*/


/*
https://leetcode.com/problems/longest-palindromic-substring/

Building the ans from smaller lengths to larger lengths
f(l, r) => maximum length palindromic subsequence
f(l, r) = {
    if (s[l] == s[r]) dp[i][j] = dp[i+1][j-1] + 2;
}



for base case: do it mannually for length 1, 2 because we could have 2 types of pallindrome: 1) odd palindrome (aba), 2) even palindrome(abba)

NOTE: Greate part of this problem is: how to make reccurence or we can how to break the problem into subproblems. If you are thinking in this way that: 
moving left to right and every time do one of the two parts : 1) pick current element 2) leave it. Then check the palindrome, then this implementation 
would be messy, and you have also maintain the some array or mask to store the element you took. Then there would be 2^k cases. So, we have fix something. 
IF we think in this way, that always break the problem such that it is always palindrome, so we don't need to check for palindrome because it always be.
Thats why we have done in this way. First check for small lengths from those small lengths build the anwer for bigger lengths. 

https://codeforces.com/contest/607/problem/B            (
DP, kind of MCM, palindrome substring, https://codeforces.com/contest/607/submission/105788794)
*/