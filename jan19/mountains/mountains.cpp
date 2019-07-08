#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void printPeaks(vector<pair<int, int> > peaks) {
  for (int i = 0; i < (int) peaks.size(); ++i) {
    cout << peaks[i].first << " " << peaks[i].second << endl;
  }
}

bool checkPeak(vector<pair<int, int> > peaks, int p1, int p2) {
  int x1 = peaks[p1].first;
  int y1 = peaks[p1].second;
  int x2 = peaks[p2].first;
  int y2 = peaks[p2].second;
  return !((x2 >= x1 && (x1+y1) >= (x2+y2)) || (x2 < x1 && (y1-x1) >= (y2-x2)));
}

int main() {
  ifstream fin("mountains.in");
  ofstream fout("mountains.out");

  int n;
  fin >> n;

  vector<pair<int, int> > peaks;

  for (int i = 0; i < n; ++i) {
    int a, b;
    fin >> a >> b;
    pair<int, int> p = make_pair(a, b);
    peaks.push_back(p);
  }

  
  vector<bool> valid(n, 1);
  for (int i = 0; i < n-1; ++i) {
    for (int j = i+1; j < n; ++j) {
      //if (i == j) continue;
      if (!checkPeak(peaks, i, j)) {
	valid[j] = 0;
      }
      if (!checkPeak(peaks, j, i)) {
	valid[i] = 0;
      }
    }
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (valid[i]) {
      count++;
    }
  }

  fout << count << endl;
}
