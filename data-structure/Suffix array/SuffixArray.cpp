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


void countSort(vector <int> &A, vector <int> &c) {
    int n = sz(A);
    vector <int> cnts(n);
    for (auto i: c) cnts[i]++;
    for (int i = 1; i < n; ++i) cnts[i] += cnts[i-1];
    vector <int> B(n);    
    for (int i = n-1; i >= 0; --i) {
        int idx = c[A[i]];
        B[cnts[idx]-1] = A[i];
        cnts[idx]--;
    }
    A = B;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;

    s += '$';
    int n = sz(s);
    vector <int> suff(n), c(n);  //suffix array, equivalence class
    {
        //k = 0, base for length 1
        vector <pair<char, int>> aux(n);
        for(int i = 0; i < n; ++i) aux[i] = {s[i], i};
        sort(all(aux));
        for (int i = 0; i < n; ++i) suff[i] = aux[i].second;
        //for suffix suff[i], the corresponding equiv class will be c[suff[i]]
        c[suff[0]] = 0; //build the equvi class
        for (int i = 1; i < n; ++i) {
            if (aux[i].first == aux[i-1].first) {
                c[suff[i]] = c[suff[i-1]];
            } else c[suff[i]] = c[suff[i-1]] + 1;
        }
    }
    //sort the strings of length 2^(k+1) using data string of length 2^k
    for (int k = 0; (1 << k) < n; ++k) {
        for (int i = 0; i < n; ++i) {
            suff[i] = (suff[i] - (1 << k) + n) % n;
        }
        countSort(suff, c);
        //build the equiv class for current 'k' using previous class
        vector <int> c_new(n);
        c_new[suff[0]] = 0;
        for (int i = 1; i < n; ++i) {
            pair <int, int> prev = {c[suff[i-1]], c[(suff[i-1] + (1 << k)) % n]};
            pair <int, int> curr = {c[suff[i]], c[(suff[i] + (1 << k)) % n]};
            if (prev == curr) c_new[suff[i]] = c_new[suff[i-1]];
            else c_new[suff[i]] = c_new[suff[i-1]] + 1;
        }
        c = c_new;
    } 

    for (int i: suff) cout << i << ' ' << s.substr(i) << endl; cout << endl;

    //LCP array
    vector <int> lcp(n);
    for (int i = 0, k = 0; i < n-1; ++i) {
        int pi = c[i];
        int j = suff[pi-1];
        while (s[i+k] == s[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1, 0);
    }

    for (int i = 1; i < n; ++i) {
        cout << lcp[i] << ' ';
    }
    return 0;
}

/*
 * Create a new suffix array, sort the array to the correspoinding characters.
 * Create the class array 'c', this will help to sort the strings in next step.

 * Do the following steps ceil(log2(n)) times:
 * Create new suffix array(aux), convert it into its corresponding string to pairs using previous iteration 'c' array.
 * for suffix suff[i], the corresponding equiv class will be c[suff[i]]
 * Sort the pairs, assign the array(aux) to ans(suff) array.
 * Regenerate class array 'c'.
 * Observation: Once completly built, then equivalence class array 'c' will contain distinct elements and for any suffix s[i]
   c[i] == suff[i] and this information will help to inversion (inverse mapping) to calculate the LCP array
 * sample test case: 
  ababba : 6 5 0 2 4 1 3

 * https://codeforces.com/edu/course/2/lesson/2/1
 * lcp = longest common prefix in suffix(i..n) and suffix[j..n] in a given string s
 
 * first find the lcp array and to find lcp(i, j)
 * finding lcp(i, j) => min(lcp(i), lcp(i+1)..., lcp(j))
 * you can you segment tree or sparse table for finding the minimum lcp in the segment.


 https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-25th-july/challenges/irritating-queries
 https://pastebin.com/cMbjJ6xu
 
 * https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/A
 * https://pastebin.com/gMgch3U1       (binary search, substring search) (recommended method)
 
 https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/B  (binary search, occurence count)
 https://pastebin.com/u7ETqb75

*/
