#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" "<<x<<endl
using namespace std;

int ans=0;

void combo(int A[],int n,int idx,int sum)
{
  // watch(sum);
  ans= max(ans,sum);
  if(idx==n) return;

  for(int i=idx+1;i<n;i++)
  {    
      combo(A,n,i,sum+A[i]);
  }

}


bool visited[10];

void permute(string &s,int n,int idx,string s1)
{   
    visited[idx]=true;

    s1 = s1+ s[idx];
    if(s1.size()==n) cout<<s1<<endl;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            permute(s,n,i,s1);
    }
    visited[idx]=false;
}


void combination(string &s,int n,int idx,string s1)
{
    s1=s[idx]+s1;
    cout<<s1<<endl;

    for(int i=idx+1;i<n;i++)
    {
        combination(s,n,i,s1);
    }
}



int main(){

  int A[]={1,2,3,4};
  int n=sizeof(A)/sizeof(int);

  /***** All possible combination  *******/
  for(int i=0;i<n;i++)
  {    
    combo(A,n,i,A[i]);
  }

  cout<<ans<<endl;

  cout<<"........combination.......\n";

  string s = "abc";
  for(int i=0;i<s.size();i++)
    combination(s,s.size(),i,"");



  /**** All possible permutation ******/
  cout<<".........permutation.......\n";
  
  memset(visited,0,sizeof(visited));
  for(int i=0;i<s.size();i++)
  {
    permute(s,s.size(),i,"");

  }

 
  return 0;
}