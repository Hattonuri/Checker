#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")

using namespace std;
using namespace __gnu_pbds;

// #define int long long
#define double long double
#define _ << ' ' <<
#define For(i,z) for(int32_t i=0;i<(z);i++)
#define sqr(a) ((a)*(a))

#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

template<typename T>
using orset = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K>
using ormap = tree <T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K> inline void umax(T &a, K b) { a = max(a, (T)b); }
template<typename T, typename K> inline void umin(T &a, K b) { a = min(a, (T)b); }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int32_t N = 3e5+10;
const int64_t INF = 1e16;
const pair<int64_t, int64_t> PINF = make_pair(INF, INF);
const double EPS = 1e-7;
const int MOD = 1e9;
const int II = 1e9 + 10;
const int64_t AMOD = 99194853094755497;
const double PI = 3.14159265359;

int n, k;
list <int> gr[N];
map<int,int,greater<int> >* buf[N];

void dfs(int v) {
    for (int i : gr[v])
        dfs(i);
    int btval = 0, bt = -1;
    for (int i : gr[v])
        if (btval < buf[i]->size()) {
            btval = buf[i]->size();
            bt = i;
        }
    if (bt == -1)
        buf[v] = new map<int,int,greater<int>>();
    else
        buf[v] = buf[bt];
    for (int i : gr[v])
        if (i != bt)
            for (pii j : *buf[i])
                (*buf[v])[j.f] += j.s;
    auto &zxc = *buf[v]->begin();
    zxc.s--;
    if (!zxc.s) buf[v]->erase(zxc.f);
    (*buf[v])[zxc.f+1]++;
}

int32_t main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    For (i, n-1) {
        int a; cin >> a; a--;
        gr[a].push_back(i+1);
    }
    dfs(0);
    int ans = 0;
    for (auto it = buf[0]->begin(); it != buf[0]->end() && k; it++)
        while (k && it->s) {
            ans += it->f;
            k--;
            it->s--;
        }
    cout << ans << '\n';
}
