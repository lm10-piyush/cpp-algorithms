//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
// Here, we are mantaining multiple list at same time, two list of same length should not be exist
// so we pick that list which has lesser end value

#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

//*********** Using binary search ***************
int bi_search(vector<int> &v, int x){
    int lo = 0, hi = sz(v)-1;
    if(hi < 0) return 0;
    while(lo < hi){
      int mid = (lo + hi + 1) >> 1;
      if(v[mid] <= x)
        lo = mid;
      else hi = mid-1;
    }
    return (v[lo] >= x ? lo: lo+1);
}


int LIS_bi(int A[], int n){
    vector <int> v;
    for (int i = 0; i < n; ++i){
        int idx = bi_search(v, A[i]);
        if(idx >= sz(v)) v.push_back(A[i]);
        else v[idx] = A[i];
    }
    return sz(v);
}

//************* Using inubilt lower_bound**********
int LIS(int A[], int n){
    vector<int> v;
    v.push_back(A[0]);

    int len = 1;

    for (int i = 1; i < n; ++i){
        if(A[i] < v[0])
            v[0] = A[i];
        else if(A[i] > v[len - 1]){
            v.push_back(A[i]);
            len++;
        }

        else{
            auto pos = lower_bound(v.begin(),v.end(),A[i]) - v.begin();
            v[pos] = A[i];
        }
    }
    
    return len;
}

int main(){
    // int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int A[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    int n = sizeof(A)/sizeof(int);
    cout << LIS(A, n) << endl;
    cout << LIS_bi(A, n);
}

//https://codeforces.com/contest/977/problem/F
//https://codeforces.com/contest/566/problem/F (dp, LIS, Maths, Sieve)
//https://codeforces.com/contest/1350/problem/B (DP, LIS, MAths, sieve)
//https://codeforces.com/problemset/problem/264/B

/*
converting the LCS(longest common subsequence)problem to LIS when atleast one of the array has distinct elements only.
algorithm: 
given array A: [], B: [], B has distinct elements.
now create another array C[] of same size as A, it stores the index of the A[i] in B, i.e., mapped index of A[i] in B.
ex: A = [10, 2, 40, 50, 12], B = [3, 50, 12, 2, 10], now C = [4, 3, null, 1, 2], so C[i] represents the index of A[i] in 
B array.
Now, LCS of A and B would be LIS in A.
same problem asked in Codenation: https://www.youtube.com/watch?v=56B0HkJfx38


*/