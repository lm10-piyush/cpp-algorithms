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

const int N = 1e7 + 4;
vector <int> factors(N+1);  //it will store smallest prime divisior of 'i'
bitset<N+10> primes;

void sieve(){
  primes.set();
  primes.reset(0);
  primes.reset(1);
  
  //if we have to check only primes then, it is better to do: i*i < N, in first loop,
  //no need to go to i < N
  for (ll i = 2; i < N; ++i){  
    if(primes[i]){
      factors[i] = i;
      for (ll j = i*i; j < N; j+=i){
        if(primes[j]){
          primes.reset(j);
          factors[j] = i;  //smallest prime factor of 'j'
        }
      }
    }
  }

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    sieve();
    //factoriazation in O(log(n))
    int n; cin >> n;
    while(n > 1){
      cout << factors[n] << ' ';
      n /= factors[n];
    }

  return 0;
}

/*
 Note:
 * If two numbers have same lowest divisors( > 1) then that means they are not coprime. But if those two have not same
   lowest divisor then it is not sure that both are coprime, they might or might not be coprime. Ex: (5, 10)
   Lowest divisor of 5 => 5, lowest divisor of 10 => 2, but still those are not coprime. 
*/

/*
 * https://codeforces.com/contest/546/problem/D
 * https://www.spoj.com/problems/FACTCG2/
 * https://www.codechef.com/problems/SMPLSUM
 * soln: https://www.codechef.com/viewsolution/33189927
 * https://codeforces.com/contest/222/problem/C
 * solution: https://codeforces.com/contest/222/submission/80800916
 * https://codeforces.com/contest/1366/problem/D
 * sol: https://codeforces.com/contest/1366/submission/87461823
 * https://atcoder.jp/contests/abc177/tasks/abc177_e
 * https://atcoder.jp/contests/abc177/submissions/16637688

 *https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-5th-september/challenges/easy-10-cc/problem
*/