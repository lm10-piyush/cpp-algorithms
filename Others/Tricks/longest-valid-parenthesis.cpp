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
    int longestValidParentheses(string s) {
        stack <int> st;
        st.push(-1); int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (!st.empty()) {
                    ans = max(ans, i - st.top());
                } else {
                    st.push (i);
                }

            }
        }

        return ans;
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;
    Solution sol;
    cout << sol.longestValidParentheses(s);


	return 0;
}

//https://codeforces.com/contest/5/problem/C
//https://codeforces.com/contest/5/submission/105786755