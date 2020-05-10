/******************* segment tree***********/
/*
*Segment tree is a binary tree, each node stores the information of a particular segment of the original array
	 of an array ranges, and we bulid this segment tree in another array, like we use heap to represent a tree.
*Complexity to bulid and search is O(n) and O(log n) respectively.
*Here I take starting index as 1 for segment tree.
ques: cicular Rmq on codeforces
solution: LM10_Piyush

*/
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
using namespace std;
const int maxn  = 2e5;


struct segTree{
	ll tree[4*maxn + 4];
	ll lazy[4*maxn + 4];

	void build(int A[], int lo, int hi, int node=1){
		if(lo == hi){
			tree[node] = A[lo];
			return;
		}

		int mid = (lo + hi) / 2;
		build(A, lo, mid, 2*node);
		build(A, mid+1, hi, 2*node+1);
		tree[node] = min(tree[2*node], tree[2*node + 1]);
	}


	ll query(int lo, int hi, int l, int r, int node=1){
		//propogate the value
		if(lazy[node]){
			tree[node] += lazy[node];
			if(lo != hi){
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		//no overlapp
		if(hi < l or lo > r) 
			return 1e18;

		//total overlapp
		if(l <= lo and hi <= r){
			return tree[node];
		}

		int mid = (lo + hi)/2;
		return min(query(lo, mid, l, r, 2*node), query(mid+1, hi, l, r, 2*node+1));
	}

	void update(int lo, int hi, int l, int r, ll delta, int node=1){
		//propogate the value
		if(lazy[node]){
			tree[node] += lazy[node];  //update the value
			if(lo != hi){
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0; //reset lazy
		}
		
		// no overlapp
		if(hi < l or lo > r)
			return;

		//total overlapp
		if(l <= lo and hi <= r){
			tree[node] += delta;
			//to the child
			if(lo != hi){
				lazy[2*node] += delta;
				lazy[2*node + 1] += delta;
			}
			return;
		}

		int mid = (lo + hi)/2;
		update(lo, mid, l, r, delta, 2*node);
		update(mid+1, hi, l, r, delta, 2*node+1);
		tree[node] = min(tree[2*node], tree[2*node+1]);
	}

} s;



int main(){
	int n;
	// cin>>n;
	int A[]={1,2,3,4,5,6,7,8,9,10};
	n=sizeof(A)/sizeof(int);

	
	s.build(A, 0, n-1);
	
	s.query(0, n-1, 1, 4);
	s.update(0, n-1, 1, 4, 30);
	s.query(0, n-1, 1, 4);
	 

	cout<<endl;

	
}