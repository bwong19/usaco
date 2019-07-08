/*
ID: bwong43
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

void i_sort(vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i; j < v.size(); ++j) {
      if (v[i] > v[j]) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
      }
    }
  }
}

bool in_set(int a, vector<int> set) {
  string s = to_string(a);
  for (int i = 0; i < s.length(); ++i) {
    bool found = 0;
    int n = s[i] - '0';
    for (int j = 0; j < set.size(); ++j) {
      if (n == set[j]) {
	found = 1;
      }
    }
    if (!found) return 0;
  }
  return 1;
}

bool valid(int a1, int a2, int a3, int b1, int b2, vector<int> set) {
  int n1 = a1*100 + a2*10 + a3;
  int n2 = b1*10 + b2;
  int p1 = b2*n1;
  int p2 = b1*n1;
  int t = n1*n2;
  
  if (((int)log10(p1)) != 2 || ((int)log10(p2)) != 2 || ((int)log10(t)) != 3) return 0;
  if (!in_set(p1, set)) return 0;
  if (!in_set(p2, set)) return 0;
  if (!in_set(t, set)) return 0;
  return 1;
}

int main() {
  ifstream fin("crypt1.in");
  ofstream fout("crypt1.out");

  int n;
  fin >> n;

  vector<int> d(n);
  for (int i = 0; i < n; ++i)
    fin >> d[i];
  i_sort(d);


  int count = 0;
  for (int a1 = 0; a1 < n; ++a1)
    for (int a2 = 0; a2 < n; ++a2)
      for (int a3 = 0; a3 < n; ++a3)
	for (int b1 = 0; b1 < n; ++b1)
	  for (int b2 = 0; b2 < n; ++b2)
	    if (valid(d[a1],d[a2],d[a3],d[b1],d[b2],d)) count++;

  fout << count << endl;
}
