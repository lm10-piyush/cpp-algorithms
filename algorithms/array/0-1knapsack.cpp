#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

//In knapsack we have 3states of each item: not-considered, picked (considered), not-picked (considered)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector <int> price(n + 1), pages(n + 1);
    for (int i = 1; i <= n; ++i) //cost/weight
        cin >> price[i];
    for (int i = 1; i <= n; ++i)
        cin >> pages[i];  //value..

    //dp[i][j] => using elements [1..i](subset of elements), maximum value I can get if current weight is 'j'
    //to do the above job correctly, here is the recurrence relation, which is based on "use it" or "not"
    //dp[i][j] = max(dp[i-1][j], pages[i] + dp[i-1][j-price[i]]); //max(dont use current one, use the current one)
    vector <vector <int>> dp(n + 1, vector <int> (x + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j]; // not ith book
            int left = j - price[i];
            if (left >= 0)
                dp[i][j] = max(dp[i][j], pages[i] + dp[i - 1][left]); //include the ith book
        }
    }

    cout << dp[n][x];


    return 0;
}

/*
 Because of items are order independent and it doesnot matter that how many elements we have picked. Only thing depends is
 how much profit we get TILL NOW for a particular weight. To specify TILL NOW we have used: 'i'

 Here it does not depends where am I (that means which position I'm currently at). The only thing matters is: how much
 profit can I get till now for a certain weight 'j'. So here we have use 'i' to represent the number of elments we have used
 only to differentiate that how many elements we have used.

 So, if we only 2 1-D arrays then the solution also works, because it only depends that how much profit we get till now. Then consider
 next item and pick the best answer. If we move in particular order ex: left to right, then we can be assure we are not double counting anything.

==========================================
When I'm currently at some item say ith item: then it does not matter that how many we have picked, which item is picked. The only
thing that matters is: how much the profit is and how much weight is left. Then step by step BUILD The answer.

=====================Bottom up=========================
Now lets understand this: dp[i][j] => We have considered, from [1...i], we have picked some elements and the remaining weight is : 'j'
and we are currently some element let say: ith element. Then there are two possibilites: currently we have picked this ith element
for dp[i][j] to get best answer or not.
1) IF we have picked current item (ith) for dp[i][j], that means in dp[i][j], 'i' is included in (i, j) state.
So, how much part remain from dp[i][j] if we remove it (ith element): which will be: i-1 and j - weight[i]: dp[i-1][j-weight[i]]
2) If we have not picked the current element then: dp[i][j] => dp[i-1][j] => weight does not change because we have not picked the current element.

==========================================================
Problems like coin change-2 when order does matter and you don't want to count extra things, then you should iterate the elmenets as outer loop because it helps to create a correct recurrcece.
but problems like coint change-1 then you should you them inner loop (it helps to counts all possible).
*/

//https://cses.fi/problemset/task/1158


//Note: above algorithm assumes one item only once, not multiple occurence
// to allow multiple occurrence you just do, =>pages[i] + dp[i][left]
//problem: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0/

//https://www.spoj.com/problems/KNAPSACK/
//https://pastebin.com/FSTqifYA       (memory efficient, only by 2-vectors, order of elements doesnot matter)

//https://atcoder.jp/contests/dp/tasks/dp_d
//sol: https://atcoder.jp/contests/dp/submissions/14115284

//https://atcoder.jp/contests/dp/tasks/dp_e  (knapsack with W <= 1e9)
//https://atcoder.jp/contests/dp/submissions/14384195

//https://codeforces.com/contest/1459/problem/D     (like knapsack, Nice problem, memory limit is strict)
//https://codeforces.com/contest/1459/submission/104722331, using 2-vectors(less efficient): https://codeforces.com/contest/1459/submission/104722194

/*
Coin change 1: More like combinatorics rather than Knapsack. (https://cses.fi/problemset/result/500193/) soln: (https://pastebin.com/5LjA9Ngy)
Coin change 2: The concept behind this is same as knapsack (https://cses.fi/problemset/task/1636) soln: (https://pastebin.com/VqCEchsh)
Same as knapsack problem + combinatorics : https://www.codechef.com/PBK22020/problems/ITGUY24 soln: https://www.codechef.com/viewsolution/40679126, bottom up memory efficient: https://www.codechef.com/viewsolution/40679190
https://leetcode.com/problems/count-sorted-vowel-strings/        (not a knapsack but useful, https://pastebin.com/bn9cYjh1)

https://codeforces.com/contest/864/problem/E
https://codeforces.com/contest/864/submission/105663711
https://codeforces.com/contest/1526/problem/C1                              (Important, ans as state, when the state is very high, trick https://codeforces.com/contest/1526/submission/117814100)
https://atcoder.jp/contests/dp/tasks/dp_e                                      (Important, similar problem, taking ans as state and check is it possible to achive or not, https://atcoder.jp/contests/dp/submissions/14384195)

--Greedy--coin change problem (important, when all the items are multiple of each other then it is optimal to pick the largest one first,
because if we can pick largest one then answer is optimal, if we can't pick largest one then try for smaller ones but if we pick the smaller
then larger it might not be optimal)

A problem which looks like a Knapsack one, could become completly greedy when we can there is some relation between elements like in greedy minimum coin change problem.
ex: https://codeforces.com/contest/1526/problem/B  (here all the elements greater than equal to 1111 can be formed by 11 or 111 combo.)
*/