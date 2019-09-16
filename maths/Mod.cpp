#include<bits/stdc++.h>
using namespace std;
/*
to find inverse modulo: x=(A/B)%m => x=(A%m * (B^(m-2))%m)%m.....(by fermi litle )


*/

/***** Modular exponentation *******/

long long int modularExponentiation(long long int x,long long int n,long long int M)
{
   long long int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}




int main(){
    long long int s=1000000004;
	long long int r=modularExponentiation(2,s,1000000007);
	cout<<r;
}