#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define int long long

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());


int getbtw(int a, int b) {
    return (rnd() % (b-a+1) + a);
}

int32_t main() {
    freopen("input.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n = getbtw(1, 300000);
    int k = getbtw(1, n);
    cout << n << ' ' << k << '\n';
    for (int i = 0; i < n-1; i ++)
        cout << getbtw(1,i+1) << ' ';
}
