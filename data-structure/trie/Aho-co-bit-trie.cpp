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

//Aho-Corasick Algorithm
//another Implementation of Trie, this is more SEXY
//this is good for strings with low bases, like binary string(base=2)
//but if you try it with base= 26, you will get memory limit exceeded
const int bits = 30, N = 2e5 * bits;
int trie[N][2], pos = 1;

void insert(int x){
  int p = 0;
  for (int i = bits; i >= 0; --i){
    if(!trie[p][x >> i & 1])
      trie[p][x >> i & 1] = pos++;
    p = trie[p][x >> i & 1];
  }
}

//xor maximum
int xor_max(int x){
  int p = 0;
  int ans = 0;
  for (int i = bits; i >= 0; --i){
    bool bit = x >> i & 1;
    if(trie[p][!bit]){
      ans |= 1 << i;
      p = trie[p][!bit];
    }
    else p = trie[p][bit];
  }
  return ans;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A)
      cin >> i;
    
    //for finding the pairs in the array whose xor is maximum
    int ans = 0;
    for (int i: A){
      insert(i);
      ans = max(ans, xor_max(i));
    }

    cout << ans << endl;


  return 0;
}


//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=2683&mosmsg=Submission+received+with+ID+2636226
//https://pastebin.com/mJqWZzf3