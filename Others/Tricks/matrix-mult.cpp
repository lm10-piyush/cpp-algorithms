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

vector<vector<int>> mult(vector<vector<int>> A, vector<vector<int>> B) {
    int a = sz(A), b = sz(A[0]), c = sz(B[0]);

    vector<vector<int>> ans(a, vector<int> (c, 0));
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < c; ++j) {
            int res = 0;
            for (int k = 0; k < b; ++k) {
                res += A[i][k] * B[k][j];
            }
            ans[i][j] = res;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    //first matrix
    int a, b;
    cin >> a >> b;
    vector <vector<int>> A(a, vector <int>(b));
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            cin >> A[i][j];
    
    //2nd matrix
    int c, d; cin >> c >> d;
    vector <vector<int>> B(c, vector <int>(d));
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < d; ++j)
            cin >> B[i][j];

    //ans matrix
    vector <vector<int>> ans = mult(A, B);
    for (int i = 0; i < sz(ans); ++i)
        for (int j = 0; j < sz(ans[0]); ++j)
            cout << ans[i][j] << " \n"[j == sz(ans[0])-1];


    return 0;
}
