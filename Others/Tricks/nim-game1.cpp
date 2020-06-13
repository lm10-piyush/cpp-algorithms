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

/*
Game theory generally depends on two things.
1) who starts (mostly dominates).
2) pattern of the game (key point, where one must lose or win if he is at that point).
3) To win, you have to keep in trap the other player.

**********************************

To win the game, one player tries to trap the another player such that himself will win or dominates in the game.
Once a player a player in the trap, then another one keeps him at that trap.
That's why initially (before start of the game), we can check who is on the trap, keep him in the trap.
To start first *can be* (not always) the key to dominates mostly.

Like in nim, game 1st player tries to trap him once another player is trapped.
eg-> in below ques, if n = 8, then now 1st player in the trap already(before start of game)

So, once a player in the trap, then second player tries to keep him in that trap.
That's why mostly games could be judge by earlier (before start of the game) that who will win.

So, that was greedy Game theory problems where we can see initially who is in trap already, then other
one keeps him in the trap and win the game.

But in Dynamic Game theory problems, we don't know earlier who wins or lose, we have to calculate the 
data dyamically.

*/


class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    Solution s;
    cout << s.canWinNim(n);

	return 0;
}


//https://leetcode.com/problems/nim-game/  (given n, as size of single heap(only), find the winner)
