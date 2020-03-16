#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define F first
#define S second
#define forn(i,n) for(int32_t i=0;i<(n);++i)

using namespace std;
using namespace __gnu_pbds;
const int N = 3e5+5;
const int INF = 1e8+7;
const int MOD = 1e9+7;
const double EPS = 1e-8;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> SET;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<> rnd01(0,1);

int n,k;
vector<int> g[N];

struct node
{
    multiset<int> *s;
};

node T[N];

void dfs(int v, int p=-1)
{
    for(int u : g[v]) if(u!=p) dfs(u,v);
    if(g[v].size()==1 && v!=0){
        T[v].s=new multiset<int>();
        T[v].s->insert(1LL);
        return;
    }
    T[v].s=new multiset<int>();
    for(int u : g[v]){
        if(u!=p){
            if(T[u].s->size()>T[v].s->size()){
                T[v].s=T[u].s;
            }
        }
    }
    for(int u : g[v]){
        if(u!=p && T[v].s!=T[u].s){
            for(auto it=T[u].s->begin();it!=T[u].s->end();it++){
                T[v].s->insert(*it);
            }
        }
    }
    auto it = --T[v].s->end();
    int nw = *it+1;
    T[v].s->erase(it);
    T[v].s->insert(nw);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    cin>>n>>k;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    forn(i,n-1){
        int x; cin>>x;
        g[x-1].push_back(i+1);
        g[i+1].push_back(x-1);
    }
    dfs(0);
    int ans=0;
    vector<int> mb;
    for(auto it=T[0].s->begin();it!=T[0].s->end();it++){
        mb.push_back(*it);
    }
    sort(mb.rbegin(),mb.rend());
    k=min(k,(int)mb.size());
    for(int i=0;i<k;i++){
        ans+=mb[i];
    }
    cout<<ans<<endl;
}
