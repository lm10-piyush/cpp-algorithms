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
	int x=1000000000;
	int n=x;
	long long int data = 999999937;
	long long int max = data*data,max2 = (data-1)*(data-1);
	bool *A = new bool[x+1];
	sieve(A,x);
	for(long long int i=2;i<n;i++){
		if(A[i]==true){
		long long int mod=  max%i;
		max2 = (data-mod*mod)*(data-mod*mod);
		for(long long int j=2;j<n;j++){
			if(A[j]==true){
				if(max2%j==mod){
					cout<<"("<<i<<","<<j<<")"<<mod<<"  ";
				}
			}
		}
	}
}
cout<<"Hola";
}