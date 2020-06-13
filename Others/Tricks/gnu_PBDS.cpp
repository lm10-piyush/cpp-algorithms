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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int>, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ordered_set oset;

    int n; cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        oset.insert(x);
    }

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        x--;
        auto it = oset.find_by_order(x);  //returns the iterator of the element at xth index
        cout << *it << ' ';
    }

    int k; cin >> k;
    cout << order_of_key(k); //returns numbers of elements less than k; 



    return 0;
}
