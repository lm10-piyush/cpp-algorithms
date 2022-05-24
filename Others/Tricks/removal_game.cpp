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
/*
Problem link: https://cses.fi/problemset/task/1097

There is a list of n numbers and two players who move alternately. On each move, a player removes either the first
or last number from the list, and their score increases by that number. Both players try to maximize their scores.

Input:
4
4 5 1 3

output:
8

What is the maximum possible score for the first player when both players play optimally?
NOTE: problem says what is the maximal score the 1st player could take.. it doesn't mean that 1st player have the score greater
than 2nd player, 2nd player could have greater score than 1st one.
Ex: 1 100 1
1st player could get: 2
2nd player get: 100

Here, 2nd player wins the game, but here in this problem the aim is not to win the game, the aim is, to get the highest score by 1st player.

*/

//another way to write the code.
//NOTE: array<int, N> is memory efficient than vector<int> (N).
void solve() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n);
    for (auto &i : A)
        cin >> i;

    vector <vector <array <ll, 2>>> dp(n, vector <array <ll, 2>>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = A[i];
        dp[i][i][1] = 0;
    }

    for (int x = 2; x <= n; ++x) {
        for (int l = 0, r = x - 1; r < n; ++l, ++r) {
            dp[l][r][0] = max(A[l] + dp[l + 1][r][1], A[r] + dp[l][r - 1][1]); //best [l..r]
            dp[l][r][1] = min(dp[l + 1][r][0], dp[l][r - 1][0]); //2nd best when first player makes the move [l..r]
        }
    }

    cout << dp[0][n - 1][0];

}

//Top-down
void solve() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n);
    for (auto &i : A)
        cin >> i;

    vector <vector <array <ll, 2>>> dp(n, vector <array <ll, 2>>(n, { -1, -1}));
    function <ll(int, int, int)> go = [&](int l, int r, int flag) {
        if (l > r)
            return 0LL;
        if (dp[l][r][flag] != -1)
            return dp[l][r][flag];
        ll ans;
        if (flag) { //to get the second best
            ans = min(go(l + 1, r, 0), go(l, r - 1, 0));
        }
        else { //to get the best
            ll best1 = A[l] + go(l + 1, r, 1);
            ll best2 = A[r] + go(l, r - 1, 1);
            ans = max(best2, best1);
            //since it is top-down we don't have to call explicitly for the second best, it done implicitly in above best1, best2.
        }
        return dp[l][r][flag] = ans;
    };

    cout << go(0, n - 1, 0);
}


//better top-down
void solve() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n);
    for (auto &i : A)
        cin >> i;

    vector <vector <ll>> dp(n, vector <ll>(n, -1));

    function <ll(int, int)> go = [&](int L, int R) {
        if (L > R) return 0LL;
        if (L == R) return A[L];
        if (dp[L][R] != -1) return dp[L][R];

        ll curr = max(A[L] + min(go(L + 2, R), go(L + 1, R - 1)),
                      A[R] + min(go(L, R - 2), go(L + 1, R - 1)));

        dp[L][R] = curr;
        return curr;
    };

    cout << go(0, n - 1);
}

//another approach to maximizing the difference
void solve() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n);
    for (ll &i : A)
        cin >> i;

    //Mini-max problem, one player tries to maximize it other tries to minimize it.

    //score1 => score taken by 1st player.
    //score2 => score taken by 2nd player.
    //dp[i][j] => difference score1 - score2 can get the current player.
    //1st player tries to maximize it, 2nd player tries to minimize it.
    //When solving for dp[i][j], we assume current player as 1st player and dp[i+1][j] or dp[i][j-1] as next player or 2nd player with respect of dp[i][j]
    //Because current player is 1st player and dp[i+1][j] or dp[i][j-1] belongs to next player's move
    //so current player tries to maximize it, and next player tries to minimize the difference

    //dp[i][j] => maximum difference can be achived
    //dp[i][j] => belongs to 1st player, since both have same goals
    //-dp[i][j] => belongs to 2nd player

    //dp[i][j] => max difference can be achieved if current player is first player
    //-dp[i][j] => minimum diference can be achieved if current player is second player

    //if dp[i][j] => difference taken by current player, then -dp[i+1][j] or -dp[i][j-1] is taken by next player, why??
    //suppose we are finding the answer for [a, b], a > b, then let current player takes 'a', next player takes from [b], then..
    //dp[0][1] => a - b

    //suppose we are fiding answr for [a, b, c], a > b, dp[0][2], then let the current player takes 'c', then next player have to take from [a, b],
    //so, then what 2nd player tries to do to get minimum differerce: b - a, which is same as -dp[0][1] = (a - b) => b - a
    //so, dp[0][2] = c + (b - a) OR c - (a - b) OR c + (-dp[0][1]) OR c - dp[0][1]

    //Conclusion is: current player tries to make dp[i][j], next player will make -dp[i][j]
    //Assuming current player = 1st player, next player = 2nd player. Then ans will be at dp[0][n-1]
    //Current player tries to maximize dp[i][j], then it automatically means next player can get the best = -dp[i][j]

    //So the magical part is by storing the answer for the 1st player's turn and also storing the anwser for second player's turn which is -dp[i][j]

    //dp[i][j] => maximum difference of score1 - score2 can get by assuming current player = 1st player, that why we are maximizing it.
    vector <vector <ll>> dp(n, vector <ll> (n, -1e18));

    for (int l = 1; l <= n; ++l) {
        for (int i = 0, j = l - 1; j < n; ++j, ++i) {
            if (i == j)
                dp[i][j] = A[i];
            else dp[i][j] = max(A[i] + (-dp[i + 1][j]), A[j] + (-dp[i][j - 1])); //current_element_score + next_player_move()
        }
    }
    //dp[0][n-1] => best maximum difference 1st player can make.
    
    //To get the what total points 1st player will make..
    ll sum = 0;
    for (auto i : A)
        sum += i;

    ll ans = (sum + dp[0][n - 1]) / 2;
    cout << ans; //this is the value 1st player will get


}


//using pairs
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n);
    for (ll &i : A) cin >> i;

    vector <vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {0, 0}));

    for (int len = 1; len <= n; len++) {
        for (int i = 0, j = len - 1; j < n; ++i, ++j) {
            if (i == j) dp[i][j] = {A[i], 0};
            else {
                ll best1 = A[i] + dp[i + 1][j].second;
                ll best2 = A[j] + dp[i][j - 1].second;
                if (best1 >= best2) {
                    ll player2 = dp[i + 1][j].first;
                    dp[i][j] = {best1, player2};
                } else {
                    ll player2 = dp[i][j - 1].first;
                    dp[i][j] = {best2, player2};
                }
            }
        }
    }

    cout << dp[0][n - 1].first;

    return 0;
}

/*
player1 starts first,
current player tries to get the best, next player choses the best from the rest part (2nd best score).
I don't need to keep track of which player is currently playing. Just assume 1st player is current player and choses the best and
next player is 2nd player choses best from remaining part.

f(i, j).best => the best amount, player with the current turn will get from this range [i..j] will be f(i, j).turn1

best for turn1 f(i, j).better = {
                                    A[i],           if i == j
                                    max(A[i] + f(i+1, j).turn2, A[j] + f(i, j-1).turn2)
                                    f(i, j).turn2 will get 2nd best from the above section ie, f(i+1, j).turn1 or f(i, j-1).turn1

                                }

https://cses.fi/problemset/task/1097
http://lightoj.com/volume_showproblem.php?problem=1031 (https://pastebin.com/xUEjseJ6)

===============================================================

/*
 2nd best in [l..r] means: best from the remaining part when current player used chance.
 * min-max game, there is one common thing where we one player tri
 * f(l, r, 0) => best from A[l..r] for the current player
 * f(l, r, 1) => 2nd best score can get from A[l..r] which means first current player takes his move then next player takes the best from remaining.
 * Current player always choses to get the best score, the next player choses the best from the rest part.
 * f(l, r, 0) => max(A[l] + f(l+1, r, 1), A[r] + f(l, r-1, 1))
   f(l, r, 1) => min(f(l+1, r, 0), f(l, r-1, 0))


========================== In these problems we have to find the winner =============================
NOTE: To win the game it doesn't depends directly that which player has how much score, because we can't say that just maximize the score of
1st player, it doesn't mean that 1st player will win. So, how to do it??
Main point is: difference of score_1st_player - score_2nd_player
if difference > 0 then 1st player wins
else if difference < 0 then 2nd player wins
else Draw.

Yeah, indirectly we are just increasing or decreasing the score of 1st or 2nd, but main point is the difference.
You can try below problems.

https://leetcode.com/problems/stone-game/       (greedy solution exits, but try dp here to learn game theory, winning game)
https://pastebin.com/zYZ7U0xK

https://leetcode.com/problems/stone-game-ii/          (same as removal game, how much 1st player can get)

https://leetcode.com/problems/stone-game-iii/        (winning game)
https://pastebin.com/gFtUA4gQ

https://leetcode.com/problems/stone-game-vii/       (winning game)
https://pastebin.com/c324Vani

https://leetcode.com/problems/stone-game-viii/        (winning game, strategy)
https://pastebin.com/qCibP0bF

https://atcoder.jp/contests/abc201/tasks/abc201_d
sol1: https://atcoder.jp/contests/abc201/submissions/23117569
soln2: https://atcoder.jp/contests/abc201/submissions/23114814 (same idea as above but clean)


https://codeforces.com/contest/1527/problem/B2         (nice dp, game theory problem)
https://codeforces.com/contest/1527/submission/118138141

*/
