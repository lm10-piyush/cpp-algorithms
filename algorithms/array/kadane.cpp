#include<bits/stdc++.h>
using namespace std;

//divide-n-conquer to calculate the max sum subarray.
//maxSubarraySum(A, 0, n-1);
//idea is to take max of (left part, right part, the segment which includes the middle part)
// this technique helps in segment trees
int maxSubarraySum(int A[], int l , int r) {
	if (l == r)
		return A[l];
	int mid = (l + r) / 2;
	int ans = max(maxSubarraySum(l, mid), maxSubarraySum(mid + 1, r));

	int res = -1e9, curr = 0;
	for (int i = mid + 1; i <= r; ++i) { //right sum from mid
		curr += A[i];
		res = max(res, curr);
	}
	curr = res;
	for (int i = mid; i >= l; --i) { //left sum from mid
		curr += A[i];
		res = max(res, curr);
	}
	return max(res, ans);
}


int main() {

	int n;
	cin >> n;

	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];


	int ans = INT_MIN, curr = 0;

	for (int i = 0; i < n; ++i) {
		curr += A[i];

		ans = max(ans, curr);
		//keep continue the sum untill it is negative
		if (curr < 0)
			curr = 0;
	}

	cout << ans << endl;

	//just above method in array way
	vector <long long> dp(n + 1, 0);
	//dp[i] => max segment sum such that ith element is the last element of the segment and it is included.
	for (int i = 1; i <= n; ++i) {
		//we have two options, either extend the previous segment OR start new segment
		dp[i] = max(dp[i - 1] + A[i - 1], A[i - 1]);
	}

	cout << dp[n] << endl;

	return 0;
}