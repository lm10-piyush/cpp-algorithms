#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
#define x second
#define y first
using namespace std;

//Sweep line


//Sort according to Y-coordinate
auto cmp = [](pair<double, double> a, pair<double, double> b) { return (a.x < b.x);};


double closestPoints(vector<pair<double, double>> &A) { //A => points (x, y)
    int n = A.size();
    sort(A.begin(), A.end(), cmp); //sort according to Y-coordinate

    double best = 1e9;
    set <pair<double, double>> box; //store points according to X-coordiante
    box.insert(A[0]);

    int left = 0;
    for (int i = 1; i < n; ++i) {
        while (left < i and A[i].x - A[left].x > best)
            box.erase(A[left++]);

        auto start = box.lower_bound({A[i].y - best, A[i].x - best});
        //this loop will run atmost 5-times
        for (auto it = start; it != box.end() and A[i].y + best >= it->y; ++it) {
            best = min(best, hypot(A[i].x - it->x, A[i].y - it->y));
        }

        box.insert(A[i]);
    }
    return best;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // freopen("D:/TestFiles/input.txt","r",stdin);

    /*********************** CODE IS HERE *****************************************/
    int n; cin >> n;
    vector<pair<double, double>> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i].x >> A[i].y;

    cout << closestPoints(A);


    return 0;
}


/*
In sweepline, we move a line from left to right, and do some operation whenever you hit an event. An event might be a point(mostly), line, etc anything, it might be
anything at which something intresting happens and whenever you hit an event you do some processing/operation.
So, common trick is, sort the points on the basis of x-direction, now apply the sweepline.

Tutorials:
https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/tutorial/

Similar tutorial, but only difference is it sorts on X-coordinate, then stores the points in std::set on the basis of Y
https://www.topcoder.com/thrive/articles/Line%20Sweep%20Algorithms

* https://medium.com/silvathiago/sweep-line-algorithm-8c878b006883
* https://usaco.guide/plat/sweep-line?lang=cpp#line-segments
* https://cp-algorithms.com/geometry/intersecting_segments.html#algorithm


https://www.geeksforgeeks.org/given-a-set-of-line-segments-find-if-any-two-segments-intersect/

*/