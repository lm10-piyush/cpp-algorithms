//https://leetcode.com/problems/subarray-sum-equals-k/
//count the total number of subarray-whose sum is k;

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
