/*
ID: brandon43
LANG: C++
TASK: transform
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> grid;

bool equal(grid g0, grid g1) {
  int n = g0.size();
  for (int i = 0; i < n; ++i)
    if (g0[i].compare(g1[i])) return 0;
  return 1;
}

string reverse(string s) {
  string out = s;
  for (int i = 0; i < s.length(); ++i) {
    out[i] = s[s.length()-i-1];
  }
  return out;
}

grid rot_90(grid g) {
  int n = g.size();
  for (int i = 0; i < n/2; ++i) {
    for (int j = i; j < n-i-1; ++j) {
      char temp = g[i][j];
      g[i][j] = g[n-1-j][i];
      g[n-1-j][i] = g[n-1-i][n-1-j];
      g[n-1-i][n-1-j] = g[j][n-1-i];
      g[j][n-1-i] = temp;
    }
  }

  return g;
}

grid rot_180(grid g) {
  return rot_90(rot_90(g));
}

grid rot_270(grid g) {
  return rot_90(rot_90(rot_90(g)));
}

grid refl(grid g) {
  grid out;
  for (int i = 0; i < g.size(); ++i) {
    out.push_back(reverse(g[i]));
  }
  return out;
}

void print(grid g) {
  for (int i = 0; i < g.size(); ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      cout << g[i][j];
    }
    cout << endl;
  }
}

int main() {
  ifstream fin("transform.in");
  ofstream fout("transform.out");

  int n;
  fin >> n;
  
  grid before;
  for (int i = 0; i < n; ++i) {
    string s;
    fin >> s;
    before.push_back(s);
  }
  grid after;
  for (int i = 0; i < n; ++i) {
    string s;
    fin >> s;
    after.push_back(s);
  }
  
  if (equal(after, rot_90(before))) {
    fout << 1 << endl;
    return 0;
  }
  else if (equal(after, rot_180(before))) {
    fout << 2 << endl;
    return 0;
  }
  else if (equal(after, rot_270(before))) {
    fout << 3 << endl;
    return 0;
  }
  else if (equal(after, refl(before))) {
    fout << 4 << endl;
    return 0;
  }
  else if (equal(after, rot_90(refl(before)))) {
    fout << 5 << endl;
    return 0;
  }
  else if (equal(after, rot_180(refl(before)))) {
    fout << 5 << endl;
    return 0;
  }
  else if (equal(after, rot_270(refl(before)))) {
    fout << 5 << endl;
    return 0;
  }
  else if (equal(before, after)) {
    fout << 6 << endl;
    return 0;
  }
  else {
    fout << 7 << endl;
    return 0;
  }
  fout << 8 << endl;
  return 0;
}
