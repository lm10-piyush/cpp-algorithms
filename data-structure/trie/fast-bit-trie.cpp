#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

template <typename T>
struct Trie {
  Trie *bit[2];
  T cnt;   //tracks the count of the prefix
  const int LOG = 29;

  Trie() {
    for (auto &i : bit) i = nullptr;
    cnt = 0;
  }

  void insert(int x) {
    Trie *curr = this;
    for (int i = LOG; i >= 0; --i) {
      bool b = (x >> i) & 1;
      if (curr->bit[b] == nullptr)
        curr->bit[b] = new Trie();
      curr = curr->bit[b];
      curr->cnt++;   //count every time the prefix
    }
  }

  T search(int x) {
    Trie *curr = this;
    for (int i = LOG; i >= 0; --i) {
      bool b = (x >> i) & 1;
      if (curr->bit[b] != nullptr && curr->bit[b]->cnt > 0)
        curr = curr->bit[b];
      else return 0;
    }
    return curr->cnt; //if exists then return number of times
  }

  void remove(int x) {
    Trie *curr = this;
    if (!search(x)) return; //number doesn't exits
    for (int i = LOG; i >= 0; --i) {
      bool b = (x >> i) & 1;
      assert(curr->bit[b] != nullptr);
      curr = curr->bit[b];
      curr->cnt--;
    }
  }
  //pair of elements whose xor is minimum
  T minxor(T x) {
    T ans = 0;
    Trie *curr = this;
    for (int i = LOG; i >= 0; --i) {
      bool b = (x >> i) & 1;
      if (curr->bit[b] != nullptr && curr->bit[b]->cnt > 0) {
        curr = curr->bit[b];
      } else {
        ans |= 1LL << i;
        curr = curr->bit[!b];
      }
    }
    return ans;
  }

  T maxxor(ll x) {
    Trie *curr = this;
    T ans = 0;
    for (int i = LOG; i >= 0; --i) {
      bool b = x >> i & 1;
      if (curr->bit[!b] != nullptr && curr->bit[!b]->cnt > 0) {
        ans |= 1LL << i;
        curr = curr->bit[!b];
      }
      else curr = curr->bit[b];
    }
    return ans;
  }

  //MEX using Trie
  //NOTE: elements must be distinct, or frequecny of each element will be 1 in trie
  // otherwise it does not work properly, So mess this Trie with others
  T mex() {
    Trie *curr = this;
    T ans = 0;
    for (int i = LOG; i >= 0; --i) {
      if (curr->bit[0] == nullptr) return ans;
      if (curr->bit[0]->cnt < (1LL << i)) {
        curr = curr->bit[0];
      } else {
        ans |= 1LL << i;
        if (curr->bit[1] == nullptr) return ans;
        curr = curr->bit[1];
      }
    }
    return ans;
  }

};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  Trie <int> t;

  t.insert(5);
  t.insert(5);
  t.insert(1);
  t.insert(2);
  t.insert(3);
  t.insert(6);
  t.insert(5);
  t.insert(7);
  // t.remove(4);

  cout << endl << t.search(4) << endl;
  cout << t.search(5) << endl;
  cout << t.search(3) << endl;
  t.remove(5);
  t.remove(5);
  t.remove(5);
  cout << t.search(5) << endl;

  return 0;
}

//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/description/
// https://pastebin.com/CEh0miYW


//tip: xor of [l...r] => xor of [1...r] ^ xor of [1...l-1]
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=2683&mosmsg=Submission+received+with+ID+2636226
//https://pastebin.com/mJqWZzf3   (find subarray with max-xor)

//https://www.spoj.com/problems/SUBXOR/
//sol: https://pastebin.com/nBcXKkqy

//https://codeforces.com/contest/706/problem/D (Max xor)
// https://codeforces.com/contest/706/submission/81589035

//https://codeforces.com/contest/665/problem/E
//sol1: https://codeforces.com/contest/665/submission/81592094
//sol2 : https://codeforces.com/contest/665/submission/81592891

//https://www.codechef.com/AFZ2019/problems/CAFE
//soln: https://www.codechef.com/viewsolution/33384947

//https://codeforces.com/contest/282/problem/E
//https://codeforces.com/contest/282/submission/81691155

//https://codeforces.com/contest/842/problem/D  (Xor, MEX, Trie)
//https://codeforces.com/contest/842/submission/83123978

// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//https://pastebin.com/XB1j89Fw



/*
Trick for MEX, is number of distince values in [0, i] => i+1, then that means, MEX does not lie in that range
so go for larger. So we can use Binary search.
Similarly in Trie, if size of subtree of  node is of complete tree, so, MEX doesn't lie in that part.
In this way try, both [0, 1] check size of subtree.
*/