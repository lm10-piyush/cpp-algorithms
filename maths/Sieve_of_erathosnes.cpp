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
//https://codeforces.com/contest/546/problem/D
//https://www.spoj.com/problems/FACTCG2/
//https://www.codechef.com/problems/SMPLSUM
//soln: https://www.codechef.com/viewsolution/33189927
//https://codeforces.com/contest/222/problem/C
//solution: https://codeforces.com/contest/222/submission/80800916

const int N = 1e7;
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
          factors[j] = i;
        }
      }
    }
  }

  //factoriazation in O(log(n))
  int n; cin >> n;
  while(n > 1){
    cout << factors[n] << ' ';
    n /= factors[n];
  }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    sieve();

  return 0;
}


