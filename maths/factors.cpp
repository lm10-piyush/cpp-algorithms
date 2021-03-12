#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define endl "\n"
#define tab " "
#define pb push_back
#define ff first
#define ss second
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pll pair<ll,ll>
#define pi 3.141592653589793238460
 
using namespace std;
 
int n,k,p;
ll ans=0;

//prime factorization
vector<long long> factors(long long n){
    vector<long long> v;
    
    for(int i = 2; i*i <= n; i++){
        while(n % i ==0){
            v.push_back(i);
            n /= i;
        }
    }
    if(n > 1) v.push_back(n);

    return v;
}


int main()
{
    vector<long long> v = factors(24);
    for(long long i: v) cout << i << " ";
    return 0;
}

/*
 * Factors of 'n' exists in pairs, and the middle number is root(n).
 that means: n = 12, 
 then factors: (2, 6), (1, 12), (3, 4) in pairs


*/
//https://www.spoj.com/problems/FACT0/      (factoring using seive)
//https://pastebin.com/gwEK1ZfT

//https://codeforces.com/contest/1025/problem/B
//https://codeforces.com/contest/1025/submission/90256368

//https://codeforces.com/contest/1285/problem/C
//https://codeforces.com/contest/1285/submission/69926022


//https://www.spoj.com/problems/COMDIV/
//https://pastebin.com/LEw7WvwW

//https://www.spoj.com/problems/DIVSUM/
//https://pastebin.com/7AQ4yEhX