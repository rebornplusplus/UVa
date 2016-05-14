#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map <char, char> m;
bool palicheck(const char *ptr);
bool mirrorcheck(const char *ptr);

int main()
{
  m.insert(make_pair('A', 'A'));
  m.insert(make_pair('B', ' '));
  m.insert(make_pair('C', ' '));
  m.insert(make_pair('D', ' '));
  m.insert(make_pair('E', '3'));
  m.insert(make_pair('F', ' '));
  m.insert(make_pair('G', ' '));
  m.insert(make_pair('H', 'H'));
  m.insert(make_pair('I', 'I'));
  m.insert(make_pair('J', 'L'));
  m.insert(make_pair('K', ' '));
  m.insert(make_pair('L', 'J'));
  m.insert(make_pair('M', 'M'));
  m.insert(make_pair('N', ' '));
  m.insert(make_pair('O', 'O'));
  m.insert(make_pair('P', ' '));
  m.insert(make_pair('Q', ' '));
  m.insert(make_pair('R', ' '));
  m.insert(make_pair('S', '2'));
  m.insert(make_pair('T', 'T'));
  m.insert(make_pair('U', 'U'));
  m.insert(make_pair('V', 'V'));
  m.insert(make_pair('W', 'W'));
  m.insert(make_pair('X', 'X'));
  m.insert(make_pair('Y', 'Y'));
  m.insert(make_pair('Z', '5'));
  m.insert(make_pair('0', ' '));
  m.insert(make_pair('1', '1'));
  m.insert(make_pair('2', 'S'));
  m.insert(make_pair('3', 'E'));
  m.insert(make_pair('4', ' '));
  m.insert(make_pair('5', 'Z'));
  m.insert(make_pair('6', ' '));
  m.insert(make_pair('7', ' '));
  m.insert(make_pair('8', '8'));
  m.insert(make_pair('9', ' '));

  char str[21];
  bool pali, mirror;

  while(cin >> str) {
    pali = mirror = false;
    if(palicheck(str)) pali = true;
    if(mirrorcheck(str)) mirror = true;

    if(!pali && !mirror) cout << str << " -- is not a palindrome.";
    else if(pali && !mirror) cout << str << " -- is a regular palindrome.";
    else if(!pali && mirror) cout << str << " -- is a mirrored string.";
    else cout << str << " -- is a mirrored palindrome.";

    cout << "\n\n";
  }

  return 0;
}

bool palicheck(const char *ptr) {
  bool flag = true;
  int l = strlen(ptr);
  for(int i=0; i<l/2; i++) {
    if(ptr[i] != ptr[l-i-1]) {
      flag = false;
      break;
    }
  }

  return flag;
}

bool mirrorcheck(const char *ptr) {
  bool flag = true;
  int l = strlen(ptr);

  for(int i=0; i<l/2; i++) {
    if(m[ ptr[i] ] != ptr[l-i-1]) {
      flag = false;
      break;
    }
  }
  if(flag && l%2) {
    if(ptr[l/2] != m[ ptr[l/2] ]) flag = false;
  }

  return flag;
}
