#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

#define pii pair<int, int>
#define uu first
#define vv second

int fx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int fy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
bool vis[9][9];
int dis[9][9];

void bfs(int, int, int, int);

int main()
{
  int sx, sy, dx, dy;
  string s1, s2;

  while(cin >> s1 >> s2) {
    sx = (int) s1[0] - 96;
    sy = (int) s1[1] - 48;
    dx = (int) s2[0] - 96;
    dy = (int) s2[1] - 48;

    bfs(sx, sy, dx, dy);
    cout << "To get from " << s1 << " to " << s2 << " takes " << dis[dx][dy] << " knight moves.\n";
  }

  return 0;
}

void bfs(int sx, int sy, int dx, int dy) {
  memset(vis, 0, sizeof(vis));

  queue<pii> Q;
  Q.push(pii(sx, sy));
  vis[sx][sy] = 1;
  dis[sx][sy] = 0;

  while(!Q.empty()) {
    pii tmp = Q.front();
    Q.pop();

    for(int i=0; i<8; i++) {
      int tx = tmp.uu + fx[i];
      int ty = tmp.vv + fy[i];

      if(tx>=1 && tx<=8 && ty>=1 && ty<=8 && !vis[tx][ty]) {
        vis[tx][ty] = 1;
        dis[tx][ty] = dis[tmp.uu][tmp.vv] + 1;
        Q.push(pii(tx, ty));
      }

      if(tx==dx && ty==dy) return;
    }
  }

  return;
}
