
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

void sieve(bool A[],int n){
    for(int i=0;i<=n;i++)
        A[i]=true;  
    
    A[0]=A[1]=false;

    for(int i=2;i*i<=n;i++){
        if(A[i]==true){
            for(int j=i*i;j<=n;j+=i)
                A[j]=false;
        }
    }
}





int main()
{
    fast;
    int n=100001;
    bool* A = new bool[n+1];

    sieve(A,n);

    vector<int> primes; //primes(vector) contains the primes between 2 to 100000

    for(int i=2;i<=n;i++)
        if(A[i]==true)
            primes.push_back(i);

    int t;
    cin>>t;
    while(t--)
    {
    long long l,r; //left and right
    cin>>l>>r;

    bool* segPrimes = new bool[r-l+1]; // to store relative prime position in (l,r)
    for(int i=0;i<=(r-l);i++)
        segPrimes[i]=true;
    // segPrimes[0]=segPrimes[1]=false;

    if(l==1) segPrimes[0]=false;

    for(int i=0;(long long )primes.at(i)*(long long)primes.at(i)<=r;i++){
        int currPrime = primes.at(i);
        int base = (l/currPrime)*(currPrime); // to get the base value, from where to start
        
        if(base < l)
            base += currPrime;

        for(int j=base;j<=r;j+=currPrime){
            segPrimes[j-l] = false;
        }

        if(base==currPrime)
            segPrimes[base - l] = true; 
    }

    for(int i=0;i<=(r-l);i++)
        if(segPrimes[i]==true)
        cout<<(i+l)<<endl;
    cout<<endl;
}
}