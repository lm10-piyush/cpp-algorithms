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
//another way
/*
Call this function: 
vector <string> v = split(s, ' '); or some other delimeter split(s, ',');
*/

vector <string> split(string s, char delim) {
  vector <string> v;
  stringstream ss(s);
  while (ss.good()) {
    string stk;
    getline(ss, stk, delim);
    if (stk.empty()) continue;
    v.push_back(stk);
  }
  return v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    //cin.get() //to avoid the whitespaces
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector <string> words;
    string lol;
    while (ss >> lol) {
        words.push_back(lol);
    }

    for (string i: words)
        cout << i << " ";
    cout << endl;

    /********* More general way*****************/
    words = split(s, ' ');
    for (auto i: words) {
        cout << i << endl;
    }

    //now, you can covert string number to int using stoi(std::string)

    return 0;
}
