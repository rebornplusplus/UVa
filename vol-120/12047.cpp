#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> dat;
struct edge { int u, v, w; };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m, src, des, p;
        cin >> n >> m >> src >> des >> p;

        vector<int> g[n+1], rg[n+1];
        vector<int> c[n+1], rc[n+1];

        vector<edge> e(m);
        for(int i=0; i<m; ++i) {
            cin >> e[i].u >> e[i].v >> e[i].w;
            g[e[i].u].push_back(e[i].v);
            c[e[i].u].push_back(e[i].w);
            rg[e[i].v].push_back(e[i].u);
            rc[e[i].v].push_back(e[i].w);
        }

        int ds[n+1];
        memset(ds, -1, sizeof ds);
        ds[src] = 0;
        priority_queue< dat > pq;
        pq.push(dat(0, src));

        while(!pq.empty()) {
            dat tp = pq.top(); pq.pop();
            int u = tp.second, d = -tp.first;

            if(ds[u] != -1 and ds[u] < d) continue;

            for(int i=0; i<(int) g[u].size(); ++i) {
                int v = g[u][i];
                if(ds[v] == -1 or ds[v] > d + c[u][i]) {
                    ds[v] = d + c[u][i];
                    pq.push(dat(-ds[v], v));
                }
            }
        }

        int dd[n+1];
        memset(dd, -1, sizeof dd);
        dd[des] = 0;
        pq.push(dat(0, des));

        while(!pq.empty()) {
            dat tp = pq.top(); pq.pop();
            int u = tp.second, d = -tp.first;

            if(dd[u] != -1 and dd[u] < d) continue;

            for(int i=0; i<(int) rg[u].size(); ++i) {
                int v = rg[u][i];
                if(dd[v] == -1 or dd[v] > d + rc[u][i]) {
                    dd[v] = d + rc[u][i];
                    pq.push(dat(-dd[v], v));
                }
            }
        }

        int res = -1;
        for(int i=0; i<(int) e.size(); ++i) {
            int u = e[i].u, v = e[i].v;
            if(ds[u] != -1 and dd[v] != -1) {
                int temp = ds[u] + e[i].w + dd[v];
                if(temp <= p) res = max(res, e[i].w);
            }
        }
        cout << res << "\n";
    }

    return 0;
}
