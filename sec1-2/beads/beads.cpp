/*
ID: brandon43
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream fin("beads.in");
  ofstream fout("beads.out");

  int n;
  fin >> n;
  string s;
  fin >> s;
  
  if (s.length() != n) n = s.length();


  int cur = 0, max = 0;
  char color;
  bool switched;
  bool switches = 0;
  color = 'w';
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'w' && color != 'w') color = s[i];
    if (color != s[i]) switches = true;
  }

  if (!switches) {
    fout << n << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    cur = 0;
    color = 'w';
    switched = false;

    for (int j = 0; j < n; ++j) {
      const char cur_c = s[(i+j)%n];
      
      if (cur_c != 'w') {
	if (color == 'w') color = cur_c;
	else if (color != cur_c) {
	  if (switched) break;
	  else {
	    color = cur_c;
	    switched = true;
	  }
	}
      }
      cur++;
    }
    if (cur > max) max = cur;
  }

  fout << max << endl; 

  return 0;
}
