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

//not stable, just simple implementation
vector <int> countingSort1(vector <int> A) {
    int n = sz(A);
    vector <int> res(n);
    vector <int> cnts(*max_element(all(A))+1, 0);
    for (int i : A){
      cnts[i]++;
    }

    int pos = 0;
    for (int i = 0; i < n; ++i){
      while(cnts[pos] == 0) pos++;
      res[i] = pos;
      cnts[pos]--;
    }
    return res;
}

//stable sort
vector <int> countingSort2(vector <int> A) {
    int n = sz(A);
    vector <int> res(n);
    vector <int> cnts(*max_element(all(A))+1, 0);
    for (int i: A) {
        cnts[i]++;
    }
    for (int i = 1; i < sz(cnts); ++i) {
        cnts[i] += cnts[i-1];  //to set the base for each item 'i' 
    }
    for (int i = n-1; i >= 0; --i) {
        res[cnts[A[i]]-1] = A[i];
        cnts[A[i]]--;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A) cin >> i;

    vector <int> res = countingSort1(A);
    for (int i: res)
      cout << i << ' '; cout << endl;
    res = countingSort2(A);
    for (int i: res) cout << i << ' ';


  return 0;
}

/*
 * To apply radix sort, you should apply the counting sort each time from right most to left most.


*/