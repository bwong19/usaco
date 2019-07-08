/*
ID: bwong43
LANG: C++
PROG: barn1
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> get_gaps(vector<int> v) {
  vector<int> gaps;
  for (int i = 0; i < v.size()-1; ++i) {
    gaps.push_back(v[i+1]-v[i]-1);
  }
  
  for (int i = 0; i < gaps.size(); ++i) {
    for (int j = i; j < gaps.size(); ++j) {
      if (gaps[i] < gaps[j]) {
	int temp = gaps[i];
	gaps[i] = gaps[j];
	gaps[j] = temp;
      }
    }
  }
  return gaps;
}

void isort(vector<int>& v) {
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

int main() {
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");
  
  int m, s, c;
  fin >> m >> s >> c;
  
  vector<int> occupied;
  for (int i = 0; i < c; ++i) {
    int temp;
    fin >> temp;
    occupied.push_back(temp);
  }
  isort(occupied);
  
  /*
  for (int i = 0; i < occupied.size(); ++i) cout << occupied[i] << " ";
  cout << endl;
  */

  int covered = occupied[c-1] - occupied[0] + 1;
  // cout << "covered = " << covered << endl;
 
  vector<int> gaps = get_gaps(occupied);
  if (m > c) m = c;
  for (int i = 0; i < m-1; ++i) {
    covered -= gaps[i];
  }
  
  /*
  for (int i = 0; i < gaps.size(); ++i) cout << gaps[i] << " ";
  cout << endl;
  */  

  fout << covered << endl;
}
