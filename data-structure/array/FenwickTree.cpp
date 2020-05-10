#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ****************************************/

//***********Prefix sum***************
struct BIT{
  int n;
  vector <int> bit;
  BIT(int n){
    this->n = n;
    bit.assign(n+1, 0);
  }
  //~~~~~~~~~~~~~update~~~~~~~~~~~~~
  void upd(int i, int val){
    for (++i; i <= n; i+= i&-i)
      bit[i] += val;
  }
  //~~~~~~~~~~~~~~query~~~~~~~~~~~~~~
  int qry(int i){
    int res = 0;
    for (++i; i > 0; i -= i&-i)
      res += bit[i];
    
    return res;
  }
};

//************* Prefix Min************
struct BITmin{
  int n;
  vector <int> bit;
  BITmin(int n){
    this->n = n;
    bit.assign(n+1, 1e9);
  }
  //~~~~~~~~~~~~~~~~~update~~~~~~~~~~~~~~~~
  void upd(int i, int val){
    for (++i; i <= n; i+= i&-i)
      bit[i] = min(bit[i], val);
  }
  //~~~~~~~~~~~~~~~~~query~~~~~~~~~~~~~~
  int qry(int i){
    int res = 1e9;
    for (++i; i > 0; i -= i&-i)
      res = min(res, bit[i]);
    
    return res;
  }
};




int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  //-------------sum--------------------
  int A[]={0,1,2,3,4,5,6,7,8,9};
  int n = sizeof(A)/sizeof(A[0]);
  BIT bit(n);
  for (int i = 0; i < n; ++i)
    bit.upd(i, A[i]);
  for (int i = 0; i < n; ++i)
    cout << bit.qry(i) << " \n"[i==n-1];

  //------------min-----------------
  int B[]={8,6,10,3,5,9,6,1,0,-1};
  n = sizeof(B)/sizeof(B[0]);
  BITmin bitmin(n);
  for (int i = 0; i < n; ++i)
    bitmin.upd(i, B[i]);
  for (int i = 0; i < n; ++i)
    cout << bitmin.qry(i) << " \n"[i==n-1];


  return 0;
}

