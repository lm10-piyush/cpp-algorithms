#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

//complexity O(n^3)

double a[110][110], b[110];

void multiply_row(int n, double val, int i){
    for(int j = 0; j < n; ++j){
        a[i][j]*=val;
    }
    b[i]*=val;
}
void add_rows(int n, int i, int j){
    double val = a[i][j] / a[j][j];
    val *= -1;
    for(int col = 0; col < n; ++col){
        a[i][col] += (val*a[j][col]);
    }
    b[i] += (val * b[j]);
}
 
void simple_add(int n, int i, int j){
    int k = (i+1) % n;
    while(i != k){
        if(a[k][j] != 0) break;
        k++;
    }
    for(int l = 0; l < n; ++l){
        a[i][l] += a[k][l];
    }
    b[i] += b[k];
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < n; ++j)printf("%f ",a[i][j]);
    //     printf("|--| %f\n",b[i]);
    // }
}

//solution
void display(int n){
    for(int i = 0; i < n; ++i){
        cout << b[i] << " ";
    }
}

//input the equation
void input(int n){
    int i,j;
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j) cin >> a[i][j];
        cin >> b[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    input(n);
    for(int i = 0; i < n; ++i){
        if(a[i][i] == 0){
            simple_add(n, i, i);
        }
        multiply_row(n, 1.0 / a[i][i], i);
        for(int j = 1; j < n; ++j){
            add_rows(n, (i+j) % n, i);   
        }
    }

    display(n);

    return 0;
}


/*
a1.x + a2.y + a3.z = b1
a2.x + a2.y + a2.z = b2
a3.x + a3.y + a3.z = b3

input:
n = number of variables OR number of equations
n lines:
(a1, a2, a3, b1)
(ai, ai, ai, bi)
...
...
(an, an, an, bn)

https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-24-october/challenges/linear-equations/problem

*/