#include <iostream>
#include <vector>
using namespace std;

bool M[5][5], taken[5][5];
vector<int> ans;

void backtrack() {
  if(ans.size() == 9) {
    for(int i=0; i<9; i++) cout << ans[i]+1;
    cout << endl;
    return ;
  }

  for(int i=0; i<5; i++) {
    if( M[ans.back()][i] && !taken[ans.back()][i] ) {
      taken[ans.back()][i] = true;
      taken[i][ans.back()] = true;
      ans.push_back(i);

      backtrack();

      ans.pop_back();
      taken[ans.back()][i] = false;
      taken[i][ans.back()] = false;
    }
  }
}

int main()
{
  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
      M[i][j] = taken[i][j] = false;

  M[0][1] = M[0][2] = M[0][4] = true;
  M[1][0] = M[1][2] = M[1][4] = true;
  M[2][0] = M[2][1] = M[2][3] = M[2][4] = true;
  M[3][2] = M[3][4] = true;
  M[4][0] = M[4][1] = M[4][2] = M[4][3] = true;

  ans.push_back(0);
  backtrack();

  return 0;
}
