#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(x) (int)x.size() 
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ****************************************/

/*
  it gives: if exactly found: return index.
  otherwise: that index (lo), such that A[lo] < x; 

  NOTE: Mainly we apply binary search the ans for finding Max or Min or Exact ans by assumptions and then verify it then move 
        accordingly.
*/
int bi_search(vector<int> &v, int x){
    int lo = 0, hi = sz(v)-1;
    while(lo < hi){
      int mid = (lo + hi + 1) >> 1;  //ceil: it is really helpful when lo & hi are adjacent.
      if(v[mid] <= x)
        lo = mid;
      else hi = mid-1;  //also important
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> v = {3, 5, 7, 19, 20, 25, 30, 39, 50, 55};

    int x; cin >> x;
    cout << bi_search(v, x);

      


  return 0;
}


//https://www.spoj.com/problems/AGGRCOW/
//https://pastebin.com/X1an8ztv

//https://codeforces.com/contest/913/problem/D
//https://codeforces.com/contest/913/submission/82218543

//https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/monster-gouketsu/description/?filter=all&sort=recent-comments
//https://pastebin.com/Yvqu8dfp


//https://codeforces.com/contest/1359/problem/C
//https://codeforces.com/contest/1359/submission/81821635

//https://codeforces.com/contest/1077/problem/D
// https://codeforces.com/contest/1077/submission/80058854

//https://leetcode.com/problems/longest-palindromic-substring/  (Longest Pallindrom using Binary search)
//https://pastebin.com/5iSP1HWv

// https://codeforces.com/contest/1370/problem/D
//https://codeforces.com/contest/1370/submission/84926060

// https://www.codechef.com/AFZQ2019/problems/SCAP   (Given sample is wrong, ans is 2)
//https://www.codechef.com/viewsolution/34908502

//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/people-carrying-6dd467ed/description/
//https://pastebin.com/WcF3v3M8 

// https://codeforces.com/problemset/problem/1181/D
//https://codeforces.com/contest/1181/submission/86457494

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//try binary search in this way: while (hi - lo > 1){}, in this way you will the range [lo, lo+1]
