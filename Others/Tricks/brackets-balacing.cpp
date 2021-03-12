#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

bool isPair(char x, char y) {
    if (x == '(' and y == ')') return true;
    if (x == '[' and y == ']') return true;
    if (x == '{' and y == '}') return true;
    return false;
}

void solve() {
    string s; cin >> s;
    stack <char> stk;
    for (char i: s) {
        if (i == '(' or i == '{' or i == '[') stk.push(i);
        else {
            if (!stk.empty() and isPair(stk.top(), i))
                stk.pop();
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    if (!stk.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
       solve();
    }


    return 0;
}

//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/balanced-brackets-3-4fc590c6/
//https://leetcode.com/problems/valid-parentheses/