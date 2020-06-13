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

vector <int> A;
vector <int> cnt(1000, 0);
int n;

int mex() {
    for (int i : A) cnt[i] = 1;
    for (int i = 1; i < 1000; ++i)
        cnt[i] += cnt[i-1];

    int lo = 0, hi = sz(A);
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (cnt[mid] >= mid+1) {
            lo = mid + 1;
        } else hi = mid;
    }
    return hi;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    A.resize(n);
    for (int &i: A) cin >> i;

    cout << mex();

    return 0;
}

/*
concept: If number of distinct elements at 'i' is equal to i+1, ie., cnt[i]==i+1, that means MEX doesn't lie
        between [0, i], so go for higher range, otherwise go the same range. In this way, we can make binary search to 
        find the MEX. Same approch is helpful when we are using Segment tree, fenwick tree for finding the number MEX on queries
        updation & deletion etc. Data structures will help us to update the number of distict elements then use 
        Binary search for MEX.

        qury, So just maintain the number of unique elements in the range [l, r] or number of elements less than 'i'.

*/