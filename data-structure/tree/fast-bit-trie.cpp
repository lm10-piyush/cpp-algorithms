#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/


struct Trie{
  Trie *bit[2];
  int cnt;   //tracks the count of the prefix 

  Trie(){
    for (auto &i: bit) i = nullptr;
    cnt = 0;
  }

  void insert(int x){
    Trie *curr = this;
    for (int i = 30; i >= 0; --i){
      bool b = (x >> i) & 1;
      if(curr->bit[b] == nullptr)
        curr->bit[b] = new Trie();
      curr = curr->bit[b];
      curr->cnt++;   //count every time the prefix
    }
  }

  int search(int x){
    Trie *curr = this;
    for (int i = 30; i >= 0; --i){
      bool b = (x >> i) & 1;
      if (curr->bit[b] != nullptr && curr->bit[b]->cnt > 0)
        curr = curr->bit[b];
      else return 0;
    }
    return curr->cnt; //if exists then return number of times
  }

  //assuming the x-integer must exists
  //first make search, if exists then remove
  void remove(int x){
    Trie *curr = this;
    for (int i = 30; i >= 0; --i){
      bool b = (x >> i) & 1;
      assert(curr->bit[b] != nullptr);
      curr = curr->bit[b];
      curr->cnt--;
    }
  }

  int minxor(int x){
    int ans = 0;
    Trie *curr = this;
    for (int i = 30; i >= 0; --i){
      bool b = (x >> i) & 1;
      if(curr->bit[b] != nullptr && curr->bit[b]->cnt > 0) {
        curr = curr->bit[b];
      } else{
        ans |= 1 << i;
        curr = curr->bit[!b];
      }
    }   
    return ans;
  }


};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    Trie t;

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

