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

class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> ugly(n, 0);
        ugly[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; ++i) {
            int next = min({ugly[a]*2, ugly[b]*3, ugly[c]*5});
            ugly[i] = next;
            if (ugly[a] * 2 == next) a++;
            if (ugly[b] * 3 == next) b++;
            if (ugly[c] * 5 == next) c++;
        }
        return ugly[n-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    Solution sol;
    int n; cin >> n;
    cout << sol.nthUglyNumber(n);

	return 0;
}

//https://leetcode.com/problems/ugly-number-ii/
