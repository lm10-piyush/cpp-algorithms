#include<bits/stdc++.h>
#include<chrono>
#define ll long long
#define mod 1000000007
#define endl '\n'
#define tab ' '
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pi 3.141592653589793238460
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define RF(i,a,b) for(int i=(int)a;i>=(int)b;i--)
// a.exe < "C:/Users/Piyush Naithani/Desktop/Codechef/Testfiles/icpc2.txt"
using namespace std;

class SqrtDecompSum{
public:
	int n, b_size, *A, *blocks;

	SqrtDecompSum(int A[], int n){
		this->A = A;
		this->n = n;
		b_size = ceil(sqrt(n));
		blocks = new int [b_size]{0};
		build();
	}

	void build(){
		for (int i = 0; i < n; ++i){
			blocks[i/b_size] += A[i];
		}
	}

	//for a given index (idx), the block number is blk = idx/size_each_block
	//the starting index of that block in array A[] is = blk * (size_each_block)
	// last index of that block in array A[] is (blk + 1)*(size_each_block) - 1
	// so the range of block is => [blk * (size_each_block), (blk + 1)*(size_each_block) - 1]
	int query(int l, int r){
		// l and r positions bcuz of standard ques, so first convert into indecies..
		l--;
		r--;

		int b_l = l / b_size;
		int b_r = r / b_size;

		int sum = 0;
		if (b_l == b_r){
			for (int i = l; i <= r; ++i)
				sum += A[i];
		}
		
		else {
			for(int i = l, last = (b_l+1)*b_size; i < last ; ++i)
				sum += A[i];

			for (int i = (b_l + 1); i < b_r; ++i)
				sum += blocks[i];

			for (int i = b_r*b_size; i <= r; ++i)
				sum += A[i];			
		}

		return sum;

	}

	void update(int pos, int new_value){
		pos--;
		int blk = pos / b_size;
		blocks[blk] += new_value - A[pos];
		A[pos] = new_value;
	}

};



void solve(){

	int n;
	// cin >> n;

	int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	n = sizeof(A) / sizeof(int);

	SqrtDecompSum s1(A, n);

	for(int i = 0; i < s1.b_size; ++i)
		cout << s1.blocks[i] << ' ';
	cout << endl;

	cout << s1.query(1, 5) << endl;
	cout << s1.query(1, 7) << endl;
	cout << s1.query(3, 5) << endl;
	cout << s1.query(2, 2) << endl;
	cout << s1.query(5, 5) << endl;
	cout << s1.query(1, 1) << endl;
	cout << s1.query(13, 13) << endl;
	cout << s1.query(12, 13) << endl;
	cout << s1.query(1, 12) << endl;
	cout << s1.query(1, 13) << endl;
	
	
}


int main(){
	fast;
	#ifndef ONLINE_JUDGE
  	// freopen("C:\Users\Piyush Naithani\Desktop\Codechef\Testfiles\icpc2.txt","r",stdin);
	
	// freopen("file name","w",stdout);
	#endif

	solve();

	return 0;
}
