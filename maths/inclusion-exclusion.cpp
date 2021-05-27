#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
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
    ans += (n / num) * sign;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t; cin >> t;

  while (t--) {
    ll n, m, a, d; cin >> n >> m >> a >> d;
    vector <ll> divisors;
    for (int i = 0; i <= 4; ++i) divisors.push_back(a + i * d);

    ll ans1 = compute(m, divisors);
    ll ans2 = compute(n - 1, divisors);
    //find all the divisors in [1..n-1] and [1...m], then required will be: Ans([1...m]) - Ans(1..n-1).
    //all these are Invalid numbers so we have subtract them.
    ll ans =  m - n + 1 - (ans1 - ans2);

    cout << ans << endl;
  }

  return 0;
}

/*
 * I think inclusion exclusion not for the multisets, it is only for sets (atmost one occurrence of each element)
 * https://codeforces.com/blog/entry/64625
 * https://cp-algorithms.com/combinatorics/inclusion-exclusion.html     (with proofs and problems)

 * Inclusion exclusion principle helps to find the count(number of elements) in set(single or Union of sets) without getting
   miscounting(less or overcounting).

   Formula:
   |A_1 U A_2 U A_3 U...A_n| = (|A_1| + |A_2| + ...A_n) - (|A_1 Ⴖ A_2| + |A_1 Ⴖ A_2| + .. + |A_2 Ⴖ A_3| + |A_2 Ⴖ A_4| +....+ |A_3 Ⴖ A_4|... every pair)
                               - (|A_1 Ⴖ A_2 Ⴖ A_3| + |A_1 Ⴖ A_2 Ⴖ A_4| + ... every triplet) + ... (-1)^n|A_1 Ⴖ A_2 ... A_n|.

    |X| => cardinatlity(number of elements) of the set X.

    As you can see the pattern: first only single set, and then every pair with intersection, then every triplet.. so on with alternate sign.

    As you can see, we are iterating over each subset of A, and sign depends on how many number we are taking at one time (odd : +, even -),
    so we need to do brute force for that (bitmasking).

  * Note: while calculating prime factors, count prime factors only once, that means prime factorization must have only distinct elements.
  * We can also use the Mobius function, with the inclusion-exlusion also, it works in similar way. Actually mobius function gives values {0, 1, -1} depending
  upon the input, and we actually do same thing.

  * Suppose you want to find the count of numbers which are non-coprime with given number 'X' (gcd(X, A[i]) == 1), then calculate the prime factorization of the 'X'
   X = {p1, p2...pk} write each occurrence only once. (because we are representing them as a set).
   let, d: set of numbers constructed using differnet combination of {p1, p2...}, or we can say 'd' is set of divisors of X such that each divisor is square free number.
   d : {d1, d2...}
   Now, lets define a function F(D) which represents a set of numbers (from the given ones) such that D is the divisor of all those numbers:
   F(D) = {a1, a2...}, |F(D)| => cardinality of that set.
   Ex: A = [2, 4, 6, 12, 18, 20], given numbers
   F(4) => {4, 12, 20}
   Now, we can the the numbers which are non-coprime with 'X' using inclusion exclusion.
   F(d1) => {a1, a2....}
   F(d2) => {b1.....} .. so on.
   As you can see F(d_i) => shows those number whose divisor is d_i and those numbers are non-coprime to 'X', so we can say that
   |F(d_i)| => the count of those number, but might get overcounted, lets fix it using inclusion exclusion.
   ans => summation (|F(d_i)| * (-1)^(count of prime divisor in d_i))

   Actually in similicity we can write it as in Mobius function terms also:
   ans => summation (u(d_i) * |F(d_i)|)
    we can write even this: ans => summation (u(i) * |F(i)|), i => {1, ..... to any given constrain}
    Actually mobius function puts the value accordingly and gives the correct answer.
    u(x) => 0 , when x is not a square free number, so as you can see in just above equation most of the number will get zero.
    u(x) => -1, when x has odd number of prime divisor and x is square free number
    u(x) => 1, when x has even divisor and x is square free number

    So, as you can see, how we replaced (-1)^count(d_i) with mobius function and rest of the part is same.

    ====================================================================================================


 http://acm.hdu.edu.cn/showproblem.php?pid=4135
 https://pastebin.com/BBpBcAfp

 https://codeforces.com/contest/547/problem/C           (with queries)
 https://codeforces.com/contest/547/submission/105842907
 https://codeforces.com/contest/547/submission/16880958       (solved using mobius function + inclusion exclusion)


 https://www.hackerrank.com/challenges/gcd-product/problem

*/