#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(x) (int)x.size()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ****************************************/

/*
  it gives: if exactly found: return index.
  otherwise: that index (lo), such that A[lo] < x;

  NOTE: Mainly we apply binary search the ans for "finding Max or Min or Exact ans" by assumptions and then verify it then moving
        accordingly.
        Ex: Given a graph with 'n' nodes and 'm' weighted edges, traverse the graph such that maximum weight in the path should be minimum.
        Then idea is just make Binary search by assuming some upper bound and traverse the graph (dfs).
*/

//Calcualtes upperbound
int bi_search(vector<int> &v, int x) {
  int lo = 0, hi = sz(v) - 1;
  //helps to find the upper found.
  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;  //ceil: it is really helpful when lo & hi are adjacent.
    if (v[mid] <= x)
      lo = mid;
    else hi = mid - 1; //also important, NOTE: to apply on floating points, hi = mid - (1e-8)
  }
  return lo;
}

//calculates lowerbound
int bi_search_lowerBound(vector <int> &v, int x) {
  int lo = 0, hi = sz(v) - 1;
  //helps to find lower bound
  while (lo < hi) {
    int mid  = (lo + hi) >> 1;
    if (v[mid] <= x)
      hi = mid;
    else lo = mid + 1;
  }
  return lo;
}

//finding the square root of any number
double sqrtD(int n) {
  double lo = 0, hi = n;
  const double eps = 1e-7;
  while (hi - lo >= eps) {
    double mid = (lo + hi + eps) / 2.0;
    if (mid * mid <= (double) n) lo = mid;
    else hi = mid - eps;
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  vector <int> v = {3, 5, 7, 19, 20, 25, 30, 39, 50, 55};

  int x; cin >> x;
  cout << bi_search(v, x);



  return 0;
}

/*
  Tip: when you are not able to solve the equation in O(1) then, it probably a good idea to use the binary search to find the ans.

  * number of elements in range(l, r) in array => upper_bound(r) - lower_bound(l);
  * some times we need to check: a * b <= n, and a*b might get overwed so we do: a <= n / b
       then we have to this operation safely: that means:
       1) if a <= n / b => a <= floor(n / b)
       2) if a >= n / b => a >= ceil(n / b)
       https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A   (problem based on this trick, https://pastebin.com/wMm6Zrku)
       https://atcoder.jp/contests/abc192/tasks/abc192_d                soln: https://atcoder.jp/contests/abc192/submissions/20358093
*/


//https://www.spoj.com/problems/AGGRCOW/
//https://pastebin.com/X1an8ztv

// https://cses.fi/problemset/task/1620
//https://pastebin.com/53j3E4H7

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

/*
https://www.geeksforgeeks.org/k-th-smallest-absolute-difference-two-elements-array/         (important binary search)

https://codeforces.com/contest/1408/problem/C  (Discrete Acceleration, Binary search on POINTS)
https://codeforces.com/contest/1408/submission/94390152

https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B   (on floating points)
https://pastebin.com/reaBM9G2

https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E (on floating points)
https://pastebin.com/KB8BjiM3

https://codeforces.com/contest/937/problem/C
(maths, binary search, Trick Important, Floating points, https://codeforces.com/contest/937/submission/109316320)

https://leetcode.com/problems/path-with-minimum-effort/ (binary search on graph, max on path)
https://pastebin.com/DPBFr5YQ

https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H  (maths, common way to solve maths problems)
https://pastebin.com/mzPenZMn

https://www.codechef.com/ICL2016/problems/ICL16A  (binary search on graph)
https://www.codechef.com/viewsolution/41940310

https://codeforces.com/contest/1117/problem/C (Tip, displacement is order Independent)
solN: https://codeforces.com/contest/1117/submission/88736716

https://codeforces.com/contest/812/problem/C
https://codeforces.com/contest/812/submission/91554317

https://codeforces.com/contest/622/problem/C
https://codeforces.com/contest/622/submission/107269192

https://codeforces.com/contest/1169/problem/C           (nice problem)
https://codeforces.com/contest/1169/submission/108859224

https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D    (Overflow can cause problem)
https://pastebin.com/9B8qtWqQ

https://codeforces.com/contest/1250/problem/J            (Greedy binary search, Standard use)
https://codeforces.com/contest/1250/submission/111583703

https://codeforces.com/contest/1393/problem/C
https://codeforces.com/contest/1393/submission/89554852

https://codeforces.com/contest/91/problem/B
https://codeforces.com/contest/91/submission/90313176
http://algoshots.herokuapp.com/problems/queue-91B/  (greedy solution also)

https://codeforces.com/contest/231/problem/C       (relative difference)
https://codeforces.com/contest/231/submission/90343783

https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-25th-july/challenges/irritating-queries
https://pastebin.com/5J165eFz

* https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/A
 * https://pastebin.com/gMgch3U1       (substring search, suffix array) (recommended method)

 https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/B  (occurence count, suffix array)
 https://pastebin.com/u7ETqb75

https://pastebin.com/tWQNM2Nj   (binary search on the matrix)

https://cses.fi/problemset/task/1085
https://pastebin.com/m8svmF50

https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c  (BIT, MEX query with binary search)
https://atcoder.jp/contests/hhkb2020/submissions/17299633

https://leetcode.com/problems/search-in-rotated-sorted-array/
https://pastebin.com/pUiy846u

https://codeforces.com/contest/1486/problem/D
(Binary search, greedy common trick of 1, -1, https://codeforces.com/contest/1486/submission/113162907)

https://codeforces.com/contest/1454/problem/F  (sparse table + binary search)
https://codeforces.com/contest/1454/submission/101060423

https://atcoder.jp/contests/abc183/tasks/abc183_b     (maths, binary search on floating points)
https://atcoder.jp/contests/abc183/submissions/19180907

https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b#problem
https://pastebin.com/kvfxMjJB

https://cses.fi/problemset/task/1140
(DP, like LIS, interval, sorting, binary search, Observe how we have picked the state, https://pastebin.com/XL5i6kkT)

https://codeforces.com/contest/1288/problem/D         (Bitmask + binary search)
https://codeforces.com/contest/1288/submission/106519133
*/
