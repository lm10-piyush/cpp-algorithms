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

const int lg = 21;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i : A) cin >> i;
    vector <int> F(n, 0);
    vector <vector<int>> dp(n, vector <int>(lg, 0)); //dp[]

    for (int mask = 0; mask < n; ++mask) { // for every mask
        for (int i = 0; i < lg; ++i) { //try every bit of mask, it will overlapp
            if (mask & (1 << i)) {
                if (i == 0)
                    dp[mask][i] = A[mask] + A[mask ^ (1 << i)];
                else
                    dp[mask][i] = dp[mask][i - 1] + dp[mask ^ (1 << i)][i - 1];
            }
            else {
                if (i == 0)
                    dp[mask][i] = A[mask];
                else
                    dp[mask][i] = dp[mask][i - 1];
            }
        }
        F[mask] = dp[mask][lg - 1];
    }

    for (int i : F)
        cout << i << ' ';
    cout << endl;

    return 0;
}

/*
resources: https://codeforces.com/blog/entry/45223
           https://www.geeksforgeeks.org/sum-subsets-dynamic-programming/

F(mask) => A[x1] + A[x2]..., such that x1 & mask = x1
which means, sum of elements over all the subset of Mask.

* Key point for Sos dp is operation on subset of bits, if there is some condition like this then we can use it.

The main idea is we create all the subsets of every mask and while doing this we also track the position of the current
working bit repesented by S(mask, i), then will overlapp


Some points from above resources:
1) Reason of DP: a) Any index 'i' of A, it will contribute to the number of masks => 2^k (k = number of zeros in 'i').
                    Suppose, i = 10010110, possible number of masks which will be superset of 'i'=> x00x0xx0, x => 0/1.
                    So this causes the overlapping subproblem.
                b) Due to the recurrence, if you try the above algo for different masks with same 'i'(S(mask, i))
                   then you will get the overlapping subproblem.
                c) We build the recurrence using the Diagram.

2) Similarity between the above code and explained algo in resources, n = 2^N, N = number of bits required to represent
  the number, in code "lg = N", 10^6 < 2^20.

3) S(mask, i) = {x |(mask ^ x) < 2^(i+1)}, it is mathematical way to just say that we are considering only [0, i]bits part.



***************************************************
Problem:
1) https://www.hackerrank.com/contests/all-india-contest-by-coding-club-india/challenges/oreo/problem (now this problem link is expired, but the problem was just given in the CF blog)
soln : https://pastebin.com/emtb1TK8 SAME AS ABOVE

*/



