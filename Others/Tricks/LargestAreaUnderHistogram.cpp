#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


//https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); //appending the dummy bar with height 0, to make implementation easy
        int n  = heights.size();
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() and heights[s.top()] > heights[i]) {
                int H = heights[s.top()];
                s.pop(); //to find the left boundary of s.top()th bar
                int W = (s.empty() ? i : i - s.top()-1); //right boundary will be ith bar.
                ans = max(ans, H * W);
            }
            s.push(i);
        }
        return ans;
    }
};



int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A) cin >> i;

    Solution sol;
	cout << sol.largestRectangleArea(A);


    return 0;
}

/*
Idea: Suppose we are the ith bar, now we have find leftmost index (l) such all the bars between (l, i] has height atleast same
as current bar's height, similarly find the rightmost index(r) such that all the bars between [i, r) has height atleast same as
height of current bar.
now ans = max(ans, (r - l - 1) * current_bar_height)

But how to find the l, r?
To do that we use stack and stack will be monotonic, which means stack contains bars with only in increasing order heights.

It helps to calcuate the l, r, let's see how.

If the height of the current bar is greater than the height of the bar at stack's top, then just push that bar to stack.
Else:
	Now considering the ith bar as rightmost index, pop all the bars which has height greater than the current bar,
	it is pretty easy to see, because height[stack.top()] > height[i] so ith bar will be rightmost 'r' index for stack.top() bar, and 
	to find the leftmost bar(l) just do stack.pop() then it will give the 'l'.
	H = heights[stack.top()]
	stack.pop();
	so, ans = max(ans, H * (i - stack.top() - 1))

*/