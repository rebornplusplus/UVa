#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

vector<int> par, freq;

void MakeSet(int x){
  for(int i=0; i<=x; i++) {
    par.push_back(i);
    freq.push_back(0);
  }
}

int findRep(int x){
  if(x!=par[x]) par[x]=findRep(par[x]);
  return par[x];
}

void MakeUnion(int &a, int &b){
  int u=findRep(a);
  int v=findRep(b);

  if(u==v) return;

  if(freq[u] > freq[v])
    par[v]=u;
  else{
    par[u]=v;
    if(freq[u]==freq[v]) freq[v]++;
  }
}

int main(){
  int t, MAX, a, b, suc, unsuc;
  char ch;
  string s;

  scanf("%d", &t);
  while(t--) {
    scanf("\n%d\n", &MAX);
    MakeSet(MAX);

    suc = unsuc = 0;

    while(1){
      if(!getline(cin,s) || s.empty()) break;
      sscanf(s.c_str(),"%c %d %d", &ch, &a, &b);

      if(ch=='c') MakeUnion(a, b);
      else {
        if(findRep(a) == findRep(b)) suc++;
        else unsuc++;
      }
    }

    printf("%d,%d\n", suc, unsuc);
    if(t) printf("\n");

    par.clear();
    freq.clear();
  }

  return 0;
}
