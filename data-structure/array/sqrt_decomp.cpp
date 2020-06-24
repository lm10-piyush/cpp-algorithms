#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

struct SqrtDecomp {
    vector <int> A, blocks;
    int blk, n;
    SqrtDecomp(vector<int> _A) {
        A = _A;
        n = sz(A);
        blk = ceil(sqrt(n));
        blocks.assign(blk, 0);
        build();
    }
    void build() {
        for (int i = 0; i < n; ++i) {
            blocks[i / blk] += A[i];
        }
    }
    int qry(int l, int r) {
        int bl = l / blk;
        int br = r / blk;
        int ans = 0;
        if (bl == br) {
            for (int i = l; i <= r; ++i) 
                ans += A[i];
            return ans;
        }
        int last = (bl + 1) * blk;
        for (int i = l; i < last; ++i)
            ans += A[i];
        for (int i = bl+1; i < br; ++i)
            ans += blocks[i];
        for (int i = blk*br; i <= r; ++i)
            ans += A[i];
        return ans;
    }
    void upd(int pos, int val) {
        int b = pos / blk;
        blocks[b] += val - A[pos];
        A[pos] = val;
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A) cin >> i;

    SqrtDecomp st(A);

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            l--; r--;
            cout << st.qry(l, r) << endl;
        }
        else {
            int pos, val; cin >> pos >> val;
            pos--;
            st.upd(pos, val);
        }
    
    }

    return 0;
}


/*
 *for a given index (idx), the block number is blk = idx/size_each_block
 *the starting index of that block of index 'blk' in array A[] is = blk * (size_each_block)
 *last index of that block in array A[] is (blk + 1)*(size_each_block) - 1
 *so the range of block is => [blk * (size_each_block), (blk + 1)*(size_each_block) - 1]

 *We can combine the sqrt decomp with Mo, to make fast operations.

https://www.spoj.com/problems/RMQSQ/
https://pastebin.com/8cbLqFe3


*/