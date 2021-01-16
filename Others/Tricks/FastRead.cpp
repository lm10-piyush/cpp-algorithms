#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

//for fast input
inline int Read() {  
    char ch = getchar();  
    while (!((ch >= '0' && ch < = '9') || ch == '-')) ch = getchar();  
    int x = 0, p = 1;  
    if (ch == '-') p = -1, ch = getchar();  
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();  
    return x * p;  
}


int main(){

    int x = Read(), k = Read(); 
    cout << x << ' ' << k;
    


    return 0;
}


/*
 There are problems which need really fast input which cannot be taken care by ios_base and scanf()
 Note: remove the ios_base:: line from your code and use the function Read(). This function is now can only read 'numbers' only.
*/