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
  BIT(int _n){
    n = _n
    bit.assign(n+2, 0);
  }
  //~~~~~~~~~~~~~update~~~~~~~~~~~~~
  //if given i is zero based, then ++i
  void upd(int i, int val){
    for (++i; i <= n; i+= i&-i)
      bit[i] += val;
  }
  //~~~~~~~~~~~~~~query~~~~~~~~~~~~~~
  //if given i is zero based, then ++i
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
    bit.assign(n+2, 1e9);
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

/*
https://www.codechef.com/COCA2020/problems/TWOARM
https://www.codechef.com/viewsolution/34707170

https://www.spoj.com/problems/INVCNT/ (number of inversions)
same repo: others/tricks/inversions

https://www.spoj.com/problems/DQUERY/  (DQUERY USING BIT)
https://pastebin.com/5QkP5KkC

https://codeforces.com/problemset/problem/61/E  (Enemy is weak)
https://codeforces.com/contest/61/submission/80213191

https://www.spoj.com/problems/KQUERY/
https://pastebin.com/jNap9hvZ

https://cses.fi/problemset/task/1646

https://codeforces.com/contest/1208/problem/D (restore permutations, BIT, binary serach)
https://codeforces.com/contest/1208/submission/83283233 

https://cses.fi/problemset/task/1749 (Binary search with fenwick tree for find the number of elements Dynamically)
https://pastebin.com/MzmUMHR6 (this is same as implementing the std::multiset or gnu_pbds, but in this ques, sorting is not allowed)
https://codeforces.com/problemset/problem/1354/D  (same ques, but here sorted order is compulsory)
https://codeforces.com/contest/1354/submission/83517596

http://lightoj.com/volume_showproblem.php?problem=1085

https://www.codechef.com/MARCH20B/problems/LAZER  (sweep line with fenwick)
soln: https://www.codechef.com/MARCH20B/problems/LAZER

https://www.spoj.com/problems/RANGESUM/
SOL: https://pastebin.com/vqBY30V6

*/