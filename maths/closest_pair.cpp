#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
#define x second
#define y first
using namespace std;

auto cmp = [](pair<double, double> a, pair<double, double> b){ return (a.x < a.y);};

//Sweep line

double closestPoints(vector<pair<double, double>> &A){
    int n = A.size();
    sort(A.begin(), A.end(), cmp);

    double best = 1e9;
    set <pair<double,double>> box;
    box.insert(A[0]);

    int left = 0;
    for (int i = 1; i < n; ++i){
        while(left < i and A[i].x - A[left].x > best)
            box.erase(A[left++]);

        auto start = box.lower_bound({A[i].y - best, A[i].x - best});
        for (auto it = start; it!=box.end() and A[i].y+best >= it->y; ++it){
            best = min(best, hypot(A[i].x - it->x, A[i].y - it->y));
        }

        box.insert(A[i]);
    }
    return best;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // freopen("D:/TestFiles/input.txt","r",stdin);
    
    /*********************** CODE IS HERE *****************************************/
    int n; cin >> n;
    vector<pair<double,double>> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i].x >> A[i].y;

    cout << closestPoints(A);
    

    return 0;
}


/*
6
0 0
3 4
7 6
3 8
7 9
5 10

6
0 0
3 4
7 6
3 8
7 9
6 10


6
0 0
3 4
7 6
3 8
7 9
6 12


*/