/******************* segment tree***********/
/*
*Segment tree is a binary tree of an array ranges, and we bulid this segment tree in another array.
*Complexity to bulid and search is O(n) and O(log n) respectively.
*Here I take starting index as 1 for segment tree.
*/

#include<bits/stdc++.h>
using namespace std;

void buildSumTree(int A[],int tree[],int start,int end,int treeNode){
	if(start==end){
		tree[treeNode]=A[start];
		return;
	}
	int mid=(start+end)/2;
	buildSumTree(A,tree,start,mid,2*treeNode);
	buildSumTree(A,tree,mid+1,end,2*treeNode+1);
	tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
	return;

}

int sumQuery(int A[],int tree[],int start,int end,int treeNode,int l,int r){
	if(l<=start && end<=r)
		return tree[treeNode];
	else if((start<l && end<l) || (start>r && end>r))
		return 0;
	int mid = (start+end)/2;
	int sum=0;
	sum = sum+ sumQuery(A,tree,start,mid,2*treeNode,l,r);
	sum=sum+ sumQuery(A,tree,mid+1,end,2*treeNode+1,l,r);
	return sum;
}

//change the value at ith index by ele
void sumUpdate(int A[],int tree[],int start,int end,int treeNode,int i,int ele){
	if(start==end && end==i){
		tree[treeNode]=ele;
		return;
	}

	if(start<=i && i<=end){
		int mid=(start+end)/2;
		sumUpdate(A,tree,start,mid,2*treeNode,i,ele);
		sumUpdate(A,tree,mid+1,end,2*treeNode+1,i,ele);
		tree[treeNode]=tree[2*treeNode] + tree[2*treeNode+1];
		return;
	}
}


void buildMinTree(int A[],int tree[],int start,int end,int treeNode){
	if(start==end){
		tree[treeNode]=A[start];
		return;
	}
	int mid = (start+end)/2;
	buildMinTree(A,tree,start,mid,2*treeNode);
	buildMinTree(A,tree,mid+1,end,2*treeNode+1);
	if(tree[2*treeNode]<tree[2*treeNode+1])
		tree[treeNode]=tree[2*treeNode];
	else
		tree[treeNode]=tree[2*treeNode+1];
	return;
}

int minQuery(int A[],int tree[],int start,int end,int treeNode,int l,int r){
	if(l<=start && end<=r){
		return tree[treeNode];
	}
	else if((start<l && end<l) || (start>r && end>r))
		return INT_MAX;
	int mid = (start+end)/2;
	int min1 = minQuery(A,tree,start,mid,2*treeNode,l,r);
	int min2 = minQuery(A,tree,mid+1,end,2*treeNode+1,l,r);
	if(min1<min2)
		return min1;
	else
		return min2;
}

//change the value at ith index by ele
void minUpdate(int A[],int tree[],int start,int end,int treeNode,int i,int ele){
	if(start==end && end==i){
		tree[treeNode] = ele;
		return;
	}
	else if(start<=i && i<=end){
		int mid = (start+end)/2;
		minUpdate(A,tree,start,mid,2*treeNode,i,ele);
		minUpdate(A,tree,mid+1,end,2*treeNode+1,i,ele);
		int min1 = tree[2*treeNode];
		int min2 =tree[2*treeNode+1];
		if(min1<min2)
			tree[treeNode]=min1;
		else
			tree[treeNode]= min2;
		return; 
	}
}



void buildMaxTree(int A[],int tree[],int start,int end,int treeNode){
	if(start==end){
		tree[treeNode]=A[start];
		return;
	}
	int mid = (start+end)/2;
	buildMaxTree(A,tree,start,mid,2*treeNode);
	buildMaxTree(A,tree,mid+1,end,2*treeNode+1);
	int max1 = tree[2*treeNode];
	int max2=tree[2*treeNode+1];
	if(max1>max2)
		tree[treeNode]=max1;
	else
		tree[treeNode]=max2;

	return;
}

//partial, complete, no overlap
int maxQuery(int A[],int tree[],int start,int end,int treeNode,int l,int r){
	if(l<=start && end<=r){
		return tree[treeNode];
	}
	//more optimize could be: if(end<l || start>r)
	else if((start<l && end<l) || (start>r && end >r) )
		return INT_MIN;
	int mid = (start+end)/2;
	int max1=maxQuery(A,tree,start,mid,2*treeNode,l,r);
	int max2 =maxQuery(A,tree,mid+1,end,2*treeNode+1,l,r);
	if(max1>max2)
		return max1;
	else
		return max2;
}

void maxUpdate(int A[],int tree[],int start,int end,int treeNode,int i,int ele){
	if(start==end && end ==i){
		tree[treeNode]=ele;
		return;
	}
	else if(start<=i && i<=end){
		int mid =(start+end)/2;
		maxUpdate(A,tree,start,mid,2*treeNode,i,ele);
		maxUpdate(A,tree,mid+1,end,2*treeNode+1,i,ele);
		int max1= tree[2*treeNode];
		int max2 = tree[2*treeNode+1];
		if(max1>max2)
			tree[treeNode]=max1;
		else
			tree[treeNode]=max2;
		return;
	}
}



int main(){
	int n;
	// cin>>n;
	int A[]={1,2,3,4,5,6,7,8,9,10};
	n=sizeof(A)/sizeof(int);
	int n1=1;

	//to find number n1 which is nearest + greater than n, n1 is in power of 2 
	while(n1<n)
		n1=n1<<1;
	n1=2*n1;

	int tree[n1];
	for(int i=0;i<n1;i++)
		tree[i]=-1;
	
	buildMaxTree(A,tree,0,n-1,1);
	maxUpdate(A,tree,0,n-1,1,5,0);
	maxUpdate(A,tree,0,n-1,1,4,0);
	maxUpdate(A,tree,0,n-1,1,3,0);

	for(int i=1;i<n1;i++)
		if(tree[i]!=-1)
			cout<<tree[i]<<" ";
	
	
	cout<<endl<<maxQuery(A,tree,0,n-1,1,0,5);

	 

	cout<<endl;

	
}