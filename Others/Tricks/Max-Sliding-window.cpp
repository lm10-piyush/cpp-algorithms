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

//same as monotonic queue
//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

   
    int n, k; cin >> n >> k;
    vector <int> A(n);
    for (int &i: A) cin >> i;
    vector <int> ans;  //stored indecies

    deque<int> dq; //store 'k' indecies such that A[i-1] > A[i] (decreasing order) 
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(dq.front());

    for (int i = k; i < n; ++i) {
        while (!dq.empty() && i - dq.front() >= k)
            dq.pop_front();

        while (!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();

        dq.push_back(i);
        ans.push_back(dq.front());
    }

    for (int i: ans) cout << A[i] << ' ';
        cout << endl;


    return 0;
}

