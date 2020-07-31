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

//gray codes
vector<int> grayCode(int n) {
    vector <string> A;
    A.push_back("0");
    A.push_back("1");
    
    for (int i = 2; i < (1 << n); i = i << 1) {
        for (int j = i-1; j >= 0; --j) {
            A.push_back(A[j]);
        }
        for (int j = 0, k = i; j < i; ++j, ++k) {
            A[j] = "0" + A[j];
            A[k] = "1" + A[k];
        }
    }
    
    vector <int> ans(A.size());
    for (int i = 0; i < A.size(); ++i) {
        ans[i] = bitset<32>(A[i]).to_ulong();
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> A = grayCode(3);
    for (int i: A) cout << i << ' ';

    return 0;
}
