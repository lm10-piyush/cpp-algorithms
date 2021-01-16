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

    int n, x; cin >> n >> x;
    vector <int> price(n+1), pages(n+1);
    for (int i = 1; i <= n; ++i) //cost/weight
        cin >> price[i];
    for (int i = 1; i <= n; ++i) 
        cin >> pages[i];  //value..

    //dp[i][j] => using elements [1..i], maximum value I can get if current weight is 'j'
    //to do the above job correctly, here is the recurrence relation, which is based on "use it" or "not"
    //dp[i][j] = max(dp[i-1][j], pages[i] + dp[i-1][j-price[i]]); //max(dont use current one, use the current one)
    vector <vector <int>> dp(n+1, vector <int> (x+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            dp[i][j] = dp[i-1][j]; // not ith book
            int left = j - price[i];
            if (left >= 0)
                dp[i][j] = max(dp[i][j], pages[i] + dp[i-1][left]); //include the ith book
        }
    }

    cout << dp[n][x];


    return 0;
}

//https://cses.fi/problemset/task/1158


//Note: above algorithm assumes one item only once, not multiple occurence
// to allow multiple occurrence you just do, =>pages[i] + dp[i][left]
//problem: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0/

//https://www.spoj.com/problems/KNAPSACK/
//https://pastebin.com/FSTqifYA       (memory efficient, only by 2-vectors)

//https://atcoder.jp/contests/dp/tasks/dp_d
//sol: https://atcoder.jp/contests/dp/submissions/14115284

//https://atcoder.jp/contests/dp/tasks/dp_e  (knapsack with W <= 1e9)
//https://atcoder.jp/contests/dp/submissions/14384195

/*
Coin change 1: More like combinatorics rather than Knapsack. (https://cses.fi/problemset/result/500193/) soln: (https://pastebin.com/5LjA9Ngy)
Coin change 2: The concept behind this is same as knapsack (https://cses.fi/problemset/task/1636) soln: (https://pastebin.com/VqCEchsh)
Same as knapsack problem + combinatorics : https://www.codechef.com/PBK22020/problems/ITGUY24 soln: https://www.codechef.com/viewsolution/40679126, bottom up memory efficient: https://www.codechef.com/viewsolution/40679190

*/