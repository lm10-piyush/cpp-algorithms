#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <long long, int> used;
        long long sum = 0;
        int ans = 0;
        used[sum]++;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(used.count(sum - k)){
                ans += used[sum-k];
                
            }
            used[sum]++;
        }
        return ans;
    }
};

int main(){
    int n, k; cin >> n >> k;
    vector <int> v(n);
    Solution s;
    cout << s.subarraySum(v, k);  
}

//https://leetcode.com/problems/subarray-sum-equals-k/
//count the total number of subarray-whose sum is k;

//https://www.codechef.com/COCA2020/problems/COCA2001
//https://www.codechef.com/viewsolution/34733651

//https://leetcode.com/problems/path-sum-iii/
// https://pastebin.com/8Y5cJEz4

//https://codeforces.com/contest/1398/problem/C
//https://codeforces.com/contest/1398/submission/89965926

//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003381cb#problem 
//(Perfect subarray, Don't use Map it will give TLE, use vector, https://pastebin.com/nvWVgJ3T)

//https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/   ((a + b) % k = 0) => b = (k - a) % k (NOTE: caution about negative)
//https://pastebin.com/dzaUHSUP

//https://cses.fi/problemset/task/1662   (pref[r] - pref[l]) % n = 0
//https://pastebin.com/C4LxG7H5