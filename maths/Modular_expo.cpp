#include<bits/stdc++.h>
using namespace std;
/*
to find inverse modulo: x=(A/B)%m => (A%m * (B^-1)%m)%m => x=(A%m * (B^(m-2))%m)%m.....(by fermi litle )
To find (B^-1 mod n) = we mean to find (B * x = 1 mod n), then find x = ?
*/

/*
how to do x power(^) n or x^n?
Represent 'n' in binary with their correspoinding powers of x, Ex: n = 10 => 1010
1010 ==> x^8 x^4 x^2 x^1 (powers of x corresponding to each bit).
then, start from right, when ever, there is 1's in binary of n, multiply corresponding power of x into the result 

Initialize, res = 1, now start from Right:
1) 0 comes, do not multiply into the res.
2) 1 comes, multiply x^2 into res, res = x^2.
3) 0 comes, donot mulitply.
4) 1 comes, multiply x^4 into the res, res = x^10;
*/

/***** Modular exponentation *******/

long long modMul(long long x,long long n,long long M){
   long long int result=1;
    while(n>0){
        if(n % 2 ==1) // when ever 1's comes to n, multiply with res
            result=(result * x)%M;
        x=(x*x)%M;  // keep multiplying x in powers of 2. (1, 2, 4, 8, 16...)
        n=n/2;
    }
    return result;
}




int main(){
    long long int s=1000000004;
	long long int r=modMul(2,1,1000000007);
	cout<<r;
}
