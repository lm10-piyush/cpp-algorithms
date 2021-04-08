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

//https://www.codechef.com/problems/SMPLSUM
//soln: https://www.codechef.com/viewsolution/33189927

const int N = 1e7 + 2;
vector <int> tots(N);

void seive_tots() {
  iota(all(tots), 0);
  for (int i = 2; i < N; ++i) {
    if (tots[i] == i) {       //prime number
      for (int j = i; j < N; j += i)
        tots[j] -= tots[j] / i;
    }
  }
}



int euler_tot(int n) {
  int phi = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0)
        n /= i;
      phi -= phi / i;
    }
  }
  if (n > 1)
    phi -= phi / n;
  return phi;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  seive_tots();
  for (int i = 1; i < 30; ++i) {
    if (euler_tot(i) != tots[i])
      cout << i << ' ';
  }
  cout << "done";
  return 0;
}


/*
properties:
0) Most important: It is a multiplicative function, because of that we can calculate phi(n) independently for each prime number
  and then combine them.
  Why it is a multiplicative function? because the basic way to calculte phi(n) is using inclusion-exclusion principal, and we can use
  the Mobius function in inclusion and exclusion then we can write phi(n) as:
  ph(n) => summation(d) {mobius(d).(n / d)}, where d => divisor on 'n'
  We know that, mobius(d) and (n/d) => both are multiplicative function, and the above summation is Drichlet convolution.
  Thats why phi(n) is multiplicative.

1) phi(p^k) = p^k - p^(k-1), p = prime
2) summation {phi(d)} = n, d => divisor of n
3) count of numbers <= n, such that gcd with n gives d, gcd(n, k) = d.
   then it will be, phi(n / d)
4) phi(a.b) = phi(a). ph(b). d/phi(d), d = gcd(a, b);

5) euler totients of 3,4 and 6 are primes, rest of the numbers have composite totients
*/

/*
https://www.codechef.com/NQST2020/problems/HEIST101

https://codeforces.com/contest/1295/problem/D                 (Important, Nice problem)
https://codeforces.com/contest/1295/submission/111568254


*/