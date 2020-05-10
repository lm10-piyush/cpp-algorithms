#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ****************************************/

//don't use unorederd_map for trie

//********STANDARD TRIE**************
struct Trie{
  unordered_map <char, Trie*> ch;  
  char
  bool isEnd;

  Trie(){
    this->isEnd = false;
    //isEnd = false;
  }
  //~~~~~~~~~~~~~~INSERT~~~~~~~~~~~~~~~~~~~
  void insert(string s){
    Trie *curr = this;
    for (auto i: s){
      if(!curr->ch.count(i))
        curr->ch[i] = new Trie();
      curr = curr->ch[i];
    }
    curr->isEnd = true;
  }
  //~~~~~~~~~~~~~~~SEARCH~~~~~~~~~~~~~~~~~~~~~~
  bool search(string s){
    Trie *curr = this;
    for (auto i: s){
      if(!curr->ch.count(i))
        return false;
      curr = curr->ch[i];
    }
    return curr->isEnd;
  }

  //~~~~~~~~~~~~~~~~DELETE~~~~~~~~~~~~~~~~~~~~
 
};

//*************XOR TRIE*******************
//find the pair in array whose xor is maximum.
struct XOR_Trie{
  unordered_map<bool, XOR_Trie*> ch;
  bool isEnd;
  XOR_Trie(){
    this->isEnd = false;
  }

  void insert(int x){
    XOR_Trie *curr = this;
    for (int i = 30; i >= 0; --i){
      bool num = x & (1 << i);
      if(!curr->ch.count(num))
        curr->ch[num] = new XOR_Trie();
      curr = curr->ch[num];
    }
    curr->isEnd = true;
  }

  //xor will all the elements, to get the max_xor
  int XOR(int x){
    XOR_Trie *curr = this;
    int ans = 0;
    for (int i = 30; i >= 0; --i){
      bool num = x & (1 << i);
      if(curr->ch.count(!num)){
        curr = curr->ch[!num];
        ans |= (1 << i);
      }
      else{
        assert(curr->ch.count(num));
        curr = curr->ch[num];
      }      
    }
    return ans;
  }

  //returns the minimum number in trie
  int MIN(){
    XOR_Trie *curr = this;
    int res = 0;
    for (int i = 30; i >= 0; --i){
      if(curr->ch.count(0)){
        curr = curr->ch[0];
      }
      else{
        res |= (1 << i);
        curr = curr->ch[1];
      }
    }
    return res;
  }


};

//**************************************************
//implmentation using array
struct XOR_Trie{
  XOR_Trie* ch[2];
  bool isEnd;
  XOR_Trie(){
    ch[0] = ch[1] = nullptr;
    this->isEnd = false;
  }
 
  void insert(int x){
    XOR_Trie *curr = this;
    for (int i = 30; i >= 0; --i){
      bool num = x & (1 << i);
      if(curr->ch[num] == nullptr){
        curr->ch[num] = new XOR_Trie();
      }
      curr = curr->ch[num];
    }
    curr->isEnd = true;
  }
 
  int MIN(int x){
    XOR_Trie *curr = this;
    int res = 0;
    for (int i = 30; i >= 0; --i){
      bool num = x & (1 << i);
      if(curr->ch[num] != nullptr){
        curr = curr->ch[num];
      }
      else{
        res |= (1 << i);
        curr = curr->ch[!num];
      }
    }
    return res;
  }
 
 
};
//******************************************************************

//another Implementation of Trie, this is more SEXY
//this is good for strings with low bases, like binary string(base=2)
//but if you try it with base= 26, you will get memory limit exceeded
const int bits = 30, N = 5e5 * bits;
int trie[N][2], pos = 1;


void insert(int x){
    int p = 0;
    for (int i = bits-1; i >= 0; --i){
      if(!trie[p][x >> i & 1])
        trie[p][x >> i & 1] = pos++;
      p = trie[p][x >> i & 1];  
    }
}

int get(int x){
    int ans = 0, p = 0;
    for (int i = bits-1; i >= 0; --i){
      if(trie[p][x >> i & 1])
        p = trie[p][x >> i & 1];
      else{
        ans |= 1 << i;
        p = trie[p][!(x >> i & 1)];
      }
    }
    return ans;
}

//*********************************************************

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
          
    //~~~~~~~~~ Standard Trie~~~~~~~~~~~~
    Trie tree;
    string s, s1; cin >> s >> s1;
    tree.insert(s);
    cout << tree.search(s1);

    //~~~~~~~~~~Xor trie~~~~~~~~~~~~~~~~~~
    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A)
      cin >> i;
    XOR_Trie triee;
    triee.insert(A[0]);

    int ans = 0;
    for (int i = 1; i < n; ++i){
      ans = max(ans, triee.XOR(A[i]));
      triee.insert(A[i]);
    }
    cout << ans << endl;



  return 0;
}

//https://www.hackerearth.com/practice/notes/lalitkundu95/tutorial-on-trie-and-example-problems/

//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/cost-of-data-11/
//soln: https://pastebin.com/NRtWqUki
//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/

//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=2683&mosmsg=Submission+received+with+ID+2636226
//https://pastebin.com/mJqWZzf3