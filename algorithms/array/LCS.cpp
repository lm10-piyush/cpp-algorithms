#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s, t; cin >> s >> t;
    int n = sz(s);
    int m = sz(t);

    //dp[i][j] => represents max length subsequence I can get using elements
    //of s =>[1...i] and t=>[1...j]
    //initally dp[0][0] = 0, becuz, both string are empty
    vector <vector<int>> dp(n+1, vector <int>(m+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    // cout << dp[n][m]; //length

    string ans;
    for (int i = n, j = m; i > 0 and j > 0;) {
        if (dp[i][j] == dp[i-1][j]) i = i - 1;
        else if (dp[i][j] == dp[i][j-1]) j = j-1;
        else {
            ans += s[i-1];
            i = i - 1;
            j = j - 1;
        }
    }
    reverse(all(ans));
    cout << ans;

    return 0;
}

// solution using other recurrece relation which is more intutive little hard to build bottom up, because hard to imagine
//how to construct. 
//: https://atcoder.jp/contests/dp/submissions/14428752

/*recurrence relation:
    
    f(i, j) = max { f(i+1, j), 1 <= i <= n
                    f(i, j+1), 1 <= j <= m
                    1 + f(i+1, j+1), i <= n and j <= m
                    0,    i < 1 or j < 1
                    }
    this is same as brute force soln, hence, brute force soln gives the recurrence 
    relation.
    If we use the above recurrence for bottom up then base case will be at
    f[n+1][m+1] = 0, and we get the final ans at f[1][1] by moving [n...1][m...1];


    So, we change the recurrence little bit, for moving [1...n] & [1...m], base at 
    f[0][0] and ans at [n][m], recurrece is similer only change is the movement
    from one to another state.
    f(i, j) = max { f(i-1, j), 1 <= i <= n
                    f(i, j-1), 1 <= j <= m
                    1 + f(i-1, j-1), i <= n and j <= m
                    }


https://atcoder.jp/contests/dp/tasks/dp_f
*/