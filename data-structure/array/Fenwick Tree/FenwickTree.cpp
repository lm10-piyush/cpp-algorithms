#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ****************************************/

//***********Prefix sum***************
struct BIT {
  int n;
  vector <int> bit;
  BIT(int _n) {
    n = _n;
    bit.assign(n + 2, 0);
  }
  //~~~~~~~~~~~~~update~~~~~~~~~~~~~
  //if given i is zero based, then ++i because here only positive indices are used.
  //You can do ++i even if it is not zero based but then you have to increase the 'n' also.
  void upd(int i, int val) {
    for (++i; i <= n; i += i & -i)
      bit[i] += val;
  }
  //~~~~~~~~~~~~~~query~~~~~~~~~~~~~~
  //if given i is zero based, then ++i
  int qry(int i) {
    int res = 0;
    for (++i; i > 0; i -= i & -i)
      res += bit[i];

    return res;
  }
};

//************* Prefix Min************
struct BITmin {
  int n;
  vector <int> bit;
  BITmin(int n) {
    this->n = n;
    bit.assign(n + 2, 1e9);
  }
  //~~~~~~~~~~~~~~~~~update~~~~~~~~~~~~~~~~
  void upd(int i, int val) {
    for (++i; i <= n; i += i & -i)
      bit[i] = min(bit[i], val);
  }
  //~~~~~~~~~~~~~~~~~query~~~~~~~~~~~~~~
  int qry(int i) {
    int res = 1e9;
    for (++i; i > 0; i -= i & -i)
      res = min(res, bit[i]);

    return res;
  }
};




int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  //-------------sum--------------------
  int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(A) / sizeof(A[0]);
  BIT bit(n);
  for (int i = 0; i < n; ++i)
    bit.upd(i, A[i]);
  for (int i = 0; i < n; ++i)
    cout << bit.qry(i) << " \n"[i == n - 1];

  //------------min-----------------
  int B[] = {8, 6, 10, 3, 5, 9, 6, 1, 0, -1};
  n = sizeof(B) / sizeof(B[0]);
  BITmin bitmin(n);
  for (int i = 0; i < n; ++i)
    bitmin.upd(i, B[i]);
  for (int i = 0; i < n; ++i)
    cout << bitmin.qry(i) << " \n"[i == n - 1];


  return 0;
}

/*
fenwick tree only deals with indices of +ve numbers, that why if our indexing is 0-based then we do +1 or ++, to do it
1-based in fenwick tree.
NOTE: It is quite common technique to sort the queries (offline) such as with Right end points, according to values etc.

we can also do range update, concept is same as difference array: upd(l, x), upd(r+1, -x)

https://www.codechef.com/COCA2020/problems/TWOARM
https://www.codechef.com/viewsolution/34707170

https://www.spoj.com/problems/INVCNT/ (number of inversions)
same repo: others/tricks/inversions

https://www.spoj.com/problems/DQUERY/  (DQUERY USING BIT)
https://pastebin.com/5QkP5KkC


https://www.spoj.com/problems/KQUERY/
https://pastebin.com/jNap9hvZ


https://codeforces.com/problemset/problem/61/E  (Enemy is weak)
https://codeforces.com/contest/61/submission/80213191

https://cses.fi/problemset/task/1646

https://codeforces.com/contest/597/problem/C
(dp, combinatorics, fenwick tree, data structure, https://codeforces.com/contest/597/submission/107186179)

https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-16-january/challenges/triplets-mania
https://pastebin.com/epBbY5pK

https://atcoder.jp/contests/abc186/tasks/abc186_f  (BIT, on Matrix, chess, paths)
https://atcoder.jp/contests/abc186/submissions/18982424

https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-10-october/challenges/changing-binary-search-tree/problem

https://codeforces.com/contest/1208/problem/D (restore permutations, BIT, binary serach)
https://codeforces.com/contest/1208/submission/83283233

https://cses.fi/problemset/task/1749 (Binary search with fenwick tree for find the number of elements Dynamically)
https://pastebin.com/MzmUMHR6 (this is same as implementing the std::multiset or gnu_pbds, but in this ques, sorting is not allowed)

https://codeforces.com/problemset/problem/1354/D  (same ques, but here sorted order is compulsory)
https://codeforces.com/contest/1354/submission/83517596

http://lightoj.com/volume_showproblem.php?problem=1085

https://www.codechef.com/MARCH20B/problems/LAZER  (sweep line with fenwick)
soln: https://www.codechef.com/MARCH20B/problems/LAZER

https://leetcode.com/problems/create-sorted-array-through-instructions/  (same as inversions)

https://www.spoj.com/problems/RANGESUM/
SOL: https://pastebin.com/vqBY30V6

Euler tour + array to tree conversion
https://www.codechef.com/JULY20B/problems/DRGNDEN or https://www.codechef.com/problems/DRGNDEN/
https://www.codechef.com/viewsolution/37019647

https://codeforces.com/contest/1311/problem/F  (moving points)
https://codeforces.com/contest/1311/submission/71993217

https://cses.fi/problemset/task/1137  (Euler tour, trees, subtree query)
https://pastebin.com/XCc6Hq8X
https://pastebin.com/JTQ2UQwB        (Clean code, finish time is always excluded from subtree)

https://codeforces.com/gym/102694/problem/E      (Euler tour, trees, subtree qry, Big numbers, Logrithms)
https://pastebin.com/FQatRMZt

https://codeforces.com/gym/102694/problem/F    (Euler tour, trees, subtree qry)
https://pastebin.com/8HsnPVf4

 * https://cses.fi/problemset/task/1138  (euler tour, path sum query, we have to store two values +x, -x)
 * https://pastebin.com/Kdb74mwu   (using fenwick tree)

https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c  (MEX query with binary search)
https://atcoder.jp/contests/hhkb2020/submissions/17299633

https://atcoder.jp/contests/abc187/tasks/abc187_e  (Euler tour, tree, subtree value sum)
https://atcoder.jp/contests/abc187/submissions/19168934  (clean code)

 https://codeforces.com/contest/1262/problem/D2         (Can be done with c++ pbds)
 https://codeforces.com/contest/1262/submission/109781843   (pbds solution)

https://codeforces.com/contest/1405/problem/E
(pbds or BIT + binary search, Merge sort tree not necessary to use but I've used it here, https://codeforces.com/contest/1405/submission/113355063)
https://codeforces.com/blog/entry/61364     (Binary lifting Tutorial of trick with BIT might help)
*/