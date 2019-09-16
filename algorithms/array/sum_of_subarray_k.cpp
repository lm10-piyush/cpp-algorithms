using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fast
	long long int n,sum;
		cin>>n>>sum;
		long long int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];
		long long int s=0;
		int j=0,i=0;
		for(;i<n;i++){
			s=s+A[i];
			
			for(;j<=i && s>sum;j++)
				s=s-A[j];

			
			if(s==sum){
				cout<<(j+1)<<" "<<(i+1)<<"\n";
				break;
			}

		}
		if(s!=sum)
			cout<<"-1\n";
	
}