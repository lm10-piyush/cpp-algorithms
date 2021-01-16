#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

const int N = 1e7 + 2;
vector <int> factor(N); //factor[i] => smallest prime factor i
vector <int> primes;

void linear_seive() {
    for (int i = 2; i < N; ++i) {
        if (factor[i] == 0) {
            factor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < sz(primes) and primes[j] <= factor[i] and primes[j] * i < N; ++j) {
            factor[i * primes[j]] = primes[j];
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    linear_seive();
    for (int i = 1; i <= 30; ++i) {
        watch(i, factor[i]);
    }


    return 0;
}

/*
x => a.b
a = lp[x]
x => a.b, lp[b]
lp[x]

In Sieve of Eratothenese, we pick the prime number(i) and iterate on the multiples of that number (j, j += i), this works in O(nloglong) time
because we move over the same number multiple times like: on 30, when i = 2, 3, 5 we move over 30, this is time consuming.
This is because we can write 30 as: 2*15 or 3 * 10 or 5*6
Similarly there are many numbers over which are moving multiple times.
So, solution would be if could move on each number only once than complexity would be O(n).
But how?
Suppose a number X, if we represent X as:  smallest_prime_factor * remaining_part
Ex: 30: 2 * 15
  : 45 : 3 * 15
Then, this representation would be always unique.
This is the main idea of linear seive

===================================================================

So, we represent number X as: X = lp[X] * b,  where lp[X] => lower prime factor of x.
Ex: 30 : 2*15
One more thing to notice: lp[b] >= lp[X] 
why?
because, if lp[b] < lp[X], and lp[b] is divisor of X, then lp[X] = lp[b].

So, above representaton of X is unique always
===============================================================

Implmentation, we iterate of 'b', for each 'b' we calculate the value of X and find the lp[X], 
how?
we know that in X the lp[X] <= lp[b], then we iterate over different primes such that p <= lp[b] and produce the different different
x such that, x = p * b, where p <= lp[b]
that x is unique, and we trace it exactly once.

*/