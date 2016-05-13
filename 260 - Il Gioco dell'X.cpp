#include <iostream>
#include <cstdio>
using namespace std;

#define M 205
char board[M][M];
bool color[M][M], flag;
int fx[] = { -1, -1, 0, 0, 1, 1 };
int fy[] = { -1, 0, -1, 1, 0, 1 };
int N;

inline bool valid(int i, int j) { return (i>=0 && i<N && j>=0 && j<N); }

void dfs_visit(int x, int y) {
  if(color[x][y] || flag) return;
  if(x == N-1) {
    flag = true;
    return;
  }

  color[x][y] = 1;
  for(int i=0; i<6; i++) {
    int tx = x + fx[i];
    int ty = y + fy[i];
    if(valid(tx, ty) && board[tx][ty]=='b')
      dfs_visit(tx, ty);
  }
  color[x][y] = 2;
}

// check only if black won... if not, definitely white won as there can be no tie
void dfs() {
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) color[i][j] = 0;
  flag = false;

  for(int i=0; i<N && !flag; i++)
    if(!color[0][i] && board[0][i] == 'b') dfs_visit(0, i);
}

int main()
{
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cnt=0;
  while(cin >> N && N) {
    for(int i=0; i<N; i++) cin >> board[i];
    cout << ++cnt;

    dfs();
    if(flag) cout << " B\n";
    else cout << " W\n";
  }

  return 0;
}
