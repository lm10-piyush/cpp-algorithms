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

//Pending: to implement the number of string having certain prefi
x
const int alpha = 26;
struct Trie{
    Trie *ch[26];
    int cnt;     //to keep track how many strings exists at the end of the string.
    Trie(){
      for (auto &i: ch) i = nullptr;
      cnt = 0;  //initally no string exists
    }

    //insert the string...
    void insert(string s){
      Trie *curr = this;
      for (char i: s){
        if(curr->ch[i-'a'] == nullptr)
          curr->ch[i-'a'] = new Trie();
        curr = curr->ch[i-'a'];
      }
      curr->cnt++;
    }
    //search the string...
    bool search(string s){
      Trie *curr = this;
      for (char i: s){
        if(curr->ch[i-'a'] == nullptr)
          return false;
        curr = curr->ch[i-'a'];
      }
      return (curr->cnt);
    }

    //have any child...
    bool haveChild(){
      Trie *curr = this;
      for (auto i: curr->ch)
        if(i != nullptr) return true;
      return false;
    }

    bool remove(Trie *curr, string &s, int idx){
      if(curr == nullptr) return false; //string not found
    
      //exact string found
      if(idx == sz(s) and curr->cnt){
        //if it has exactly more strings or it is not leaf 
        if(curr->cnt > 1 or curr->haveChild()){
          curr->cnt--;
          return false;
        }
         delete curr; curr = nullptr;
         return true;
      }
      else if(idx < sz(s)){
        int pos = s[idx]-'a';
        bool rm = remove(curr->ch[pos], s, idx+1);
        if(rm){
          curr->ch[pos] = nullptr;
          if(!curr->haveChild() and !curr->cnt){
            delete curr; curr = nullptr;
            return true;
          }
        }
        return false;
      }
      return false;
    }

    bool remove(string s){
      bool rm = remove(this->ch[s[0]-'a'], s, 1);
      if(rm){
        this->ch[s[0]-'a'] = nullptr;
      }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    Trie t;
    t.insert("abcde");
    t.insert("abcde");
    t.insert("abcdf");
    t.insert("abcd");
    t.insert("abc");
    t.insert("abce");
    t.remove("abcde");
    t.remove("abcde");
    
    cout << t.search("abcdf") << endl;
    cout << t.search("abcde") << endl;
    cout << t.search("abcd") << endl;


  return 0;
}
