#include<bits/stdc++.h>
using namespace std;
int main(){

	int n;
	
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];
		long long int sum1=0,sum2=INT_MIN;
		
		for(int i=0;i<n;i++){
			sum1=sum1+A[i];
			
			if(sum1>sum2)
				sum2=sum1;
		if(sum1<0)
				sum1=0;
		}

		cout<<sum2<<"\n";
	
	return 0;
}