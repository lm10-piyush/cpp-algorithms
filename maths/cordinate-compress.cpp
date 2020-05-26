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

void another_way_to_compress(){
    int n; cin >> n;
    vector <int> A(n), extra(n);
    for (int i = 0; i < n; ++i){
      cin >> A[i];
      extra[i] = A[i];
    }

    sort(all(extra));  //2 2 2 4 4 4 4 7 7 7 7 
    unordered_map<int,int> mp;
    for (int i = 0; i < n; ++i){
      mp[extra[i]] = i;
    }
    for (int i = 0; i < n; ++i){
      A[i] = mp[A[i]];
    }

    for (int i: A)
      cout << i << ' ';
    //in case if we want to find the correspoding real element we do: extra[A[i]]=> original element
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector <int> A(n);
    vector <int> compress;

    for (int &i: A){
    	cin >> i;
    	compress.push_back(i);
    }

    sort(all(compress));
    //unique returns the iterator after the last iterator when duplicacy removed.
    compress.resize(unique(all(compress)) - compress.begin());
    for (int i = 0; i < n; ++i){
    	A[i] = lower_bound(all(compress), A[i]) - compress.begin();
    }
    //now it will contain the compressed path
    for (int i = 0; i < n; ++i)
    	cout << A[i] << ' ';


	return 0;
}

/*
this is very famous when we want to track the elemnts as index, one of the way is using std::map,
but using this trick we going to do same thing in an array.
https://codeforces.com/contest/459/problem/D
BIT with path compression.
*/
