/**********Sieve of Eratosthenes **********/

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
