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

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (char i: s) {
            if (i == '(' or i == '{' or i == '[') {
                st.push(i);
                
            } 
            else if (!st.empty()) {
                if (i == ')' && '(' != st.top())
                    return false;
                else if (i == '}' && '{' != st.top())
                    return false;
                else if (i == ']' && '[' != st.top())
                    return false;
                st.pop();
            } 
            else
                return false;
        }
        
        return st.empty();
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;
    Solution sol;
    cout << sol.isValid(s);

	return 0;
}
