#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/


//Remember, problem should be monotonic to apply this approach.

// find the pairs in the array whose sum is equal to the given sum

//https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, target; cin >> n >> target;
    vector <int> A(n);
    for (int &i : A)
        cin >> i;
    sort(all(A));
    for (int i = 0, j = n - 1; i < j; ) {
        if (A[i] + A[j] == target) {
            cout << A[i] << ' ' << A[j];
            break;
        }
        else if (A[i] + A[j] < target)
            i++;
        else j--;
    }

    /*
    One more approach to solve the above problem by hashing, it takes only O(n) time and O(n) space.

    */

    return 0;
}


/*
1) One of the famous question could be, you have a binary string, also given a number 'm' which tells you that atmost 'm'bits
    you could flip. Find the longest length of the continuous sequence of 1's.
    This can be done by Two pointers.

2) The we thinking about using 2-loops, then we can optimize it using 2-pointers when we know the solution is MONOTONIC, so we don't
need to start again, so right pointer will be as it is or increases its value.

Resource: https://usaco.guide/silver/2P?lang=cpp

https://leetcode.com/problems/subarray-product-less-than-k/
https://pastebin.com/wWR4ESDW

https://www.interviewbit.com/problems/container-with-most-water/
https://pastebin.com/FjxmhBa2

https://leetcode.com/problems/minimum-size-subarray-sum/
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

https://leetcode.com/problems/minimize-deviation-in-array/
Greedy, Important, Can be solved using Smart brute force(here two pointer), https://pastebin.com/bi2Tn5W4,
Can be solved using Heap, Solution of Heap is intresting how they reduced the two operation into just one)

https://codeforces.com/contest/1380/problem/D
(greedy, two pointer, observation, costs, https://codeforces.com/contest/1380/submission/106140134)

https://leetcode.com/problems/arithmetic-slices/
https://pastebin.com/CKRbJiVB
*/