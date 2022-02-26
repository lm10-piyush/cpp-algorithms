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

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = tortoise;
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (hare != tortoise);
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i : A) cin >> i;
    Solution sol;
    cout << sol.findDuplicate(A);

    return 0;
}

//https://leetcode.com/problems/find-the-duplicate-number/
//https://leetcode.com/problems/linked-list-cycle-ii/  (similar code with pointers validations)
//https://leetcode.com/problems/linked-list-cycle/
//https://www.interviewbit.com/problems/find-duplicate-in-array/