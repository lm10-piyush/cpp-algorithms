#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

ll lcm(ll a, ll b) {    
    return (a * b) / __gcd(a, b);
}

/*
Motivation problem: https://www.codechef.com/NQST2020/problems/XMASGIFT

To break it down the solution part, here compute() function takes the number N, and an array of Integers and function returns the 
count of integers which are divisible by the elements of the array in [1..N].
More formally, it returns the number of integers in [1..N] which are multiple of array elements.
To do this I have used the inclusion-Exclusion principle.

This is the main concept, I used to solve the above (motivation)problem.

*/

ll compute(ll n, vector<ll> divisors) {
    ll ans = 0;
    //applying the brute force.
    for (int i = 1; i < (1 << 5); ++i) {
        //choosing sign.
        int sign = (__builtin_popcount(i) & 1 ? 1 : -1);
        ll num = 1;
        int useful = 1;
        for (int j = 0; j < 5; ++j) {
            if (i >> j & 1) num = lcm(num, divisors[j]);
            if (num > n) {
                useful = 0;
                break;
            }
        }
        if (!useful) continue;
        ans += (n / num)*sign;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        ll n, m, a, d; cin >> n >> m >> a >> d;
        vector <ll> divisors;
        for (int i = 0; i <= 4; ++i) divisors.push_back(a + i*d);

        ll ans1 = compute(m, divisors);
        ll ans2 = compute(n-1, divisors);
        //find all the divisors in [1..n-1] and [1...m], then required will be: Ans([1...m]) - Ans(1..n-1).
        //all these are Invalid numbers so we have subtract them. 
        ll ans =  m - n + 1 - (ans1 - ans2);

        cout << ans << endl;
    }

    return 0;
}

/*
 * https://codeforces.com/blog/entry/64625 
 
 * Inclusion exclusion principle helps to find the count(number of elements) in set(single or Union of sets) without getting 
   miscounting(less or overcounting).

   Formula:
   |A_1 U A_2 U A_3 U...A_n| = (|A_1| + |A_2| + ...A_n) - (|A_1 Ⴖ A_2| + |A_1 Ⴖ A_2| + .. + |A_2 Ⴖ A_3| + |A_2 Ⴖ A_4| +....+ |A_3 Ⴖ A_4|... every pair)
                               - (|A_1 Ⴖ A_2 Ⴖ A_3| + |A_1 Ⴖ A_2 Ⴖ A_4| + ... every triplet) + ... (-1)^n|A_1 Ⴖ A_2 ... A_n|.
    
    |X| => cardinatlity(number of elements) of the set X. 

    As you can see the pattern: first only single set, and then every pair with intersection, then every triplet.. so on with alternate sign.

    As you can see, we are iterating over each subset of A, and sign depends on how many number we are taking at one time (odd : +, even -),
    so we need to do brute force for that (bitmasking).
 
*/