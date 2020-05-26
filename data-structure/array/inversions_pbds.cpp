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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>,  rb_tree_tag, tree_order_statistics_node_update>

void solve(){
    int n; cin >> n;
    vector <int> A(n);
    for (int &i : A) cin >> i;
    
    ordered_set tree;
    ll ans =  0;
    //A[i] > A[j], i < j
    //iterating over 'j',
    //for each 'j' we find the inversions for that 'j', using pbds
    for (int i: A){
      int cnt = tree.order_of_key(i+1);
      ans += sz(tree) - cnt;
      tree.insert(i);
    }

    cout << ans << endl; 

    /*
    --another way
    reverse(all(A));
    ordered_set tree;
    ll ans =  0;
    for (int i: A){
      ans += tree.order_of_key(i+1);
      tree.insert(i);
    }
    cout << ans;
    */


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
      solve();

  return 0;
}
