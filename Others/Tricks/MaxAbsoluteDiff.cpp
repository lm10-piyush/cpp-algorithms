#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define LM10_Piyush
#ifdef LM10_Piyush
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define watch(...)
#endif

//https://www.interviewbit.com/problems/maximum-absolute-difference/
//https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i : A)
        cin >> i;

    int mx1 = INT_MIN, mn1 = INT_MAX; // for max and min of (A[i] + i)
    int mx2 = INT_MIN, mn2 = INT_MAX; // for max and min of (A[i] - i)
    for (int i = 0; i < n; ++i) {
        int x = A[i] + i;
        int y = A[i] - i;
        mx1 = max(mx1, x);
        mn1 = min(mn1, x);
        mx2 = max(mx2, y);
        mn2 = min(mn2, y);
    }

    int ans = max(mx1 - mn1, mx2 - mn2);
    cout << ans;

    return 0;
}


/*

A[i] - A[j] + i - j => (A[i] + i) - (A[j] + j)
A[i] - A[j] - i + j => (A[i] - i) - (A[j] - j)
-A[i] + A[j] + i - j => -(A[i] - i) + (A[j] - j)
-A[i] + A[j] - i + j => -(A[i] + i) + (A[j] + j)

case 1, 4 are same and Case 2, 3 are same with just i, j swapped.

=> max { max(A[i] + 1) - min(A[i] + i), max(A[i] - i) min(A[i] - i)}
=> You might be thinking that we should open the modulo accordingly, but we are opening it kind of randomly (correct and wrong both),
   so is it wrong??
=> Ans is NO, because we have to maximize the answer. So, if we are opening the mod in wrong way it would lead to less maximum number
    which can be the real answer and we are also opening the bracktes in correct way which leads to larger number, so correct way will
    shadow the incorrect way. Thats why we can say when we have to find the Minimum ans this strategy won't work, because modulus doesn't give
    negative result by our way is giving it.

*/