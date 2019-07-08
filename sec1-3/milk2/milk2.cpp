/*
ID: brandon43
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

int streak(vector<bool> v, int min, bool b) {
  int max = 0;
  int count = 0;
  
  if (v[min] == b) count = 1;

  for (int i = min+1; i < v.size(); ++i) {
    if (v[i] == b) {
      count++;
    }
    else {
      count = 0;
    }
    if (count > max) max = count;
  }

  return max;
}

int main() {
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");

  int n;
  fin >> n;

  if (n == 1) {
    int a, b;
    fin >> a >> b;
    fout << b-a << " 0" << endl;
    return 0;
  }
  
  vector<pair<int, int> > v;
  for (int i = 0; i < n; ++i) {
    int a, b;
    fin >> a >> b;
    pair<int, int> p(a, b);
    v.push_back(p);
  }

  int max = 0;
  for (int i = 0; i < n; ++i)
    if (v[i].second > max) max = v[i].second;
  
  int min = max;
  for (int i = 0; i < n; ++i)
    if (v[i].first < min) min = v[i].first;

  vector<bool> vec(max);

  for (int j = 0; j < n; ++j) {
    for (int k = v[j].first; k < v[j].second; ++k) {
      vec[k] = true;
    }
  }

  fout << streak(vec, min, 1) << " " << streak(vec, min, 0) << endl;
  return 0;
}
