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

    int n, k, target; cin >> n >> k >> target;
    vector<int> A(n);
    for (int &i: A) cin >> i;

    int sum = 0, target = 0;
    for (int i = 0, j = 0; i < n; ++i) {
    	sum += A[i];
    	if (i - j + 1 > k)
    		sum -= A[j++];

        /*
        while (curr > mx && i <= j) {
            if (s[i] != ch) curr--;
            j++;
        }
        */


    	if((i-j+1 == k) && sum == target)
    		ans++;
    }

    cout << ans;


	return 0;
}

/*
1) One of the famous question could be, you have a binary string, also given a number 'm' which tells you that atmost 'm'bits 
    you could flip. Find the longest length of the continuous sequence of 1's.
    This can be done by Two pointers. 

https://leetcode.com/problems/subarray-product-less-than-k/
https://pastebin.com/wWR4ESDW

https://www.interviewbit.com/problems/container-with-most-water/
https://pastebin.com/FjxmhBa2
*/