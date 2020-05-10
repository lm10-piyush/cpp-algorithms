#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define endl "\n"
#define tab " "
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pll pair<ll,ll>
#define pi 3.141592653589793238460
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define RF(i,a,b) for(int i=(int)a;i>=(int)b;i--)
using namespace std;

void make_set(int A[],int n, int size[])
{
    for(int i=0;i<n;i++)
    {
        A[i]=i;
        size[i]=1; // size == number of nodes
    }

}


int find_set(int A[],int a)
{
    if(A[a]==a) return a;
    //go for the parent
    return A[a] = find_set(A,A[a]);
}




void union_set(int A[], int a,int b, int size[])
{
    int x = find_set(A, a);
    int y = find_set(A, b);

    if(x==y) return;
    if(size[x] < size[y])
        swap(x, y);

    A[y] = x;
    size[x] += size[y];


}

int main()
{
    int n,m,e1,e2;
    cin>>n>>m;

    int A[n+1],size[n+1];
    make_set(A,n+1,size);

    F(i,1,m)
    {
        cin>>e1>>e2;
        union_set(A,e1,e2,size);

    }


}
