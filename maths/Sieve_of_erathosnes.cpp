#include<bits/stdc++.h>
using namespace std;
//using namespace std::chrono;


/**********Sieve of Eratosthenes **********/
//largest 10^9 prime ->999999937,999999929,(999999937,999999936)
//bool A[n+1];  initialize like this, because loop is untill n(inclusive);
//use as sieve(A,n)
void sieve(bool A[],int n){
	//n=[1,n]
	//initalize all true
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
 
int main(){
	int n=100000;
	bool *A = new bool[n+1];
	sieve(A,n);
	
}
