#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

//It is not a monotonic queue.
//here calculating the maximum in a window/queue using two stacks.
//https://cp-algorithms.com/data_structures/stack_queue_modification.html

template <typename T>
struct Queue {
    stack <pair<T, T>> s1, s2;

    void push(T x) {
        T mn = (s1.empty() ? x : min(x, s1.top().second));
        s1.push({x, mn});
    }

    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                T x = s1.top().first;
                T mn = (s2.empty() ? x : min(x, s2.top().second));
                s2.push({x, mn});
                s1.pop();
            }
        }
        s2.pop(); //remove the element.
    }

    T top() {
        if (s1.empty() or s2.empty())
            return (s1.empty() ? s2.top().second : s1.top().second);
        return min(s1.top().second, s2.top().second);
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector <int> A(n);
    for (int &i : A) cin >> i;

    Queue <int> q;
    for (int i = 0; i < k; ++i)
        q.push(A[i]);
    cout << q.top() << ' ';
    for (int i = k; i < n; ++i) {
        q.pop();
        q.push(A[i]);
        cout << q.top() << ' ';
    }


    return 0;
}


/*
 * Monotonic queue: It is a custom queue data structure which stores the elements like a queue but with a extra functionality that:
   finding the minimum element between stored ones.
 * This is similar like Max-Sliding Window, but this version is better because we maitain each element, it givs more feel about Queue.
 * Benefits:
 * Storing and tracking all the elements.
 * Operations are done in O(1).
 * It helps to reduce the complexity without having log(n) factor like in std::set.
 * Simple and easy.

  https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
  (std::set will give the TLE)

  https://codeforces.com/contest/1077/problem/F2
  https://codeforces.com/contest/1077/submission/118180721


*/