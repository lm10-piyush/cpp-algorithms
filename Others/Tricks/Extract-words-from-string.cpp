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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    //cin.get() //to avoid the whitespaces
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector <string> words;
    while (ss >> s) {
        words.push_back(s);
    }

    for (string i: words)
        cout << i << " ";

    //you can covert string number to int using stoi(std::string)

    return 0;
}
