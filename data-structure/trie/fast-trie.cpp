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

//Fast trie means it is the fast implementation of Trie.

const int alpha = 26;

//cnt => count of prefix
//isEnd => count of exact strings

struct Trie {
  Trie *ch[alpha];
  int cnt, isEnd;

  Trie() {
    for (auto &i : ch) i = nullptr;
    cnt = 0; isEnd = 0;
  }

  void insert(string s) {
    Trie *curr = this;
    for (char i : s) {
      int p = i - 'a';
      if (curr->ch[p] == nullptr)
        curr->ch[p] = new Trie();
      curr = curr->ch[p];
      curr->cnt++;
    }
    curr->isEnd++;
  }

  int search(string s) {
    Trie *curr = this;
    for (char i : s) {
      int p = i - 'a';
      if (curr->ch[p] != nullptr && curr->ch[p]->cnt > 0)
        curr = curr->ch[p];
      else return 0;
    }
    return (curr->isEnd);
  }


  void remove(string s) {
    Trie *curr = this;
    if (!search(s)) return; //string not exits
    for (char i : s) {
      int p = i - 'a';
      curr = curr->ch[p];
      curr->cnt--;
    }
    curr->isEnd--;
  }

};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  Trie t;
  t.insert("abcde");
  t.insert("abcd");
  t.insert("abcdef");
  t.insert("abcde");

  cout << t.search("abcde") << endl;
  cout << t.search("abcdef") << endl;
  cout << t.search("abcd") << endl;

  t.remove("abcde");
  cout << t.search("abcde") << endl;

  t.remove("abcde");
  cout << t.search("abcde") << endl;



  return 0;
}


//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/description/
//https://pastebin.com/1cszDyUq

//https://leetcode.com/problems/add-and-search-word-data-structure-design/
//https://pastebin.com/jpLNVN9A