#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
using namespace std;

/*********************** CODE IS HERE *****************************************/


vector <int> kmpPreProcess(string &pattern) {

    vector <int> piTable((int)pattern.size(), 0);  //(piTable[i] = x) => longest string which is a suff at i (i-x+1...i) and prefix (1...x)
    for (int i = 1, j = 0; i < (int)pattern.size(); ++i) {
        while (j > 0 and pattern[j] != pattern[i])
            j = piTable[j - 1]; //key step, you know why it works?
        assert(0 <= j and j <= (int)pattern.size());

        if (pattern[j] == pattern[i]) j++;
        piTable[i] = j;
    }
    return piTable;
}

vector<int> kmpMatch(string text, string pattern) {
    vector<int> idx;
    vector <int> piTable =  kmpPreProcess(pattern);

    for (int i = 0, j = 0; i < (int)text.size(); ++i) {
        while (j > 0 and pattern[j] != text[i])
            j = piTable[j - 1];
        assert(0 <= j and j <= (int)text.size());
        if (pattern[j] == text[i]) {
            if (j + 1 == (int)pattern.size()) {
                idx.push_back(i - j);
                j = piTable[j];
            }
            else j++;
        }

    }

    return idx;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    int t; cin >> t;
    while (t--) {
        string pattern = "AABA";
        string text = "AABAACAADAABAABA";

        // string pattern, text; cin >> pattern >> text;

        //for (int i = 0; i < pattern.size(); ++i)
        //  cout << piTable[i] << " ";
        //cout << endl;

        vector<int> idx = kmpMatch(text, pattern);
        for (int i : idx)
            cout << i << ' ';
    }
    return 0;
}

/*
 * Tip: learn why and how KMP works, dive into its basics will help you.
 * Let me explain you why it works.
  : suppose below is given string with some characters (here x = some unknow charcter)
  : x x x x x x x x x x x x x x
              j         i
  : j = 5, i = 10
  : now suppose, s[i] != s[j], then where should we go and why?
  : we should go at that index 'k' (k < j) such that s[0...k] == s[i-k ....i], and k should be maximum possible (max k leads to best result).
  : Ok, now we know where and why should we go, but how efficiently?
  : key: Notice, s[0...j-1] == s[....i-1] (already matched). ie., s[0, 4] == s[5, 9]
  : or we can say, k = piTable[j-1], s[0...k] == s[5...9], now start matching after 'k'

 * We can do some tricks in strings like: s = s + '?' + reverse(s). Then apply KMP here. We can use it to find the longest paldindromic prefix.

*/

//problem: https://codeforces.com/contest/625/problem/B
//sol: https://codeforces.com/contest/625/submission/82346364

//https://codeforces.com/contest/126/problem/B
//https://codeforces.com/contest/126/submission/82435794

//https://acmp.ru/index.asp?main=task&id_task=202

//https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/first-one-6fc38abd-229bcc5f/description/
//https://pastebin.com/rvd9CMgm

//https://leetcode.com/problems/longest-happy-prefix/
//https://pastebin.com/BgZijfYu

//https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
//https://www.geeksforgeeks.org/print-the-longest-palindromic-prefix-of-a-given-string/
//https://pastebin.com/vnUXNEfa