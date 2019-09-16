#include<bits/stdc++.h>
using namespace std;


void build_GCD_Tree(int A[], int tree[], int start, int end, int treeNode)
{
  if(start==end)
  {
    tree[treeNode]=A[start];
    return;
  }
  int mid = (start+end)/2;
  build_GCD_Tree(A, tree, start, mid, 2*treeNode);
  build_GCD_Tree(A, tree, mid+1, end, 2*treeNode+1);
  tree[treeNode] = __gcd(tree[2*treeNode],tree[2*treeNode+1]);
  return;

}




int query(int BIT[], int idx)
{
	int sum=0;
	idx += 1;

	while(idx>0)
	{
		sum += BIT[idx];
		idx -= idx & (-idx);
	}
	return sum;
}


void update(int BIT[],int idx, int ele, int n)
{
	idx+=1;

	while(idx<=n)
	{
		BIT[idx] += ele;
		idx += idx &(-idx);
	}
}


int *builtBIT(int A[],int n)
{
	int * BIT = new int[n+1];
	for(int i=0;i<=n;i++)
		BIT[i]=0;

	for(int i=0;i<n;i++)
		update(BIT, i, A[i], n);

	return BIT;
}



int main()
{
	int A[]={1,2,3,4,5,6,7,8,9};
	int n= sizeof(A)/sizeof(int);
	int *BIT = builtBIT(A,n);
	cout<<query(BIT,0)<<endl;
	cout<<query(BIT,5)<<endl;
	cout<<query(BIT,8)<<endl;

}