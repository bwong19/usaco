/*
ID: bwong43
LANG: C++
PROB: milk
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> insertionSort(vector<int> v) {
  vector<int> out(v.size());
  out = v;
  
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i; j < v.size(); ++j) {
      if (out[i] > out[j]) {
	int temp = out[i];
	out[i] = out[j];
	out[j] = temp;
      }
    }
  }
  return out;
}

void print_map(map<int, int> m) {
  for (map<int, int>::iterator it = m.begin();
       it != m.end();
       it++) {
    cout << it->first << ": " << it->second << endl;
  }
}

int main() {
  ifstream fin("milk.in");
  ofstream fout("milk.out");

  int n, m;
  fin >> n >> m;
  if (!n) {
    fout << 0 << endl;
    return 0;
  }
  map<int, int> prices;
  vector<int> list;

  int p, a;
  for (int i = 0; i < m; ++i) {
    fin >> p >> a;
    prices[p] += a;
    list.push_back(p);
  }
  
  if (list.size()) list = insertionSort(list);
  
  
  int malk = 0;
  int total = 0;

  int min_index = 0;
  int min_price = list[0];
  while (malk < n && min_index < m) {
    /*
    cout << "milk count: " << malk << endl;
    cout << "map: " << endl;
    print_map(prices);
    cout << endl;
    */
    if (prices[min_price]) {
      malk++;
      total += min_price;
      prices[min_price]--;
    }
    else {
      min_index++;
      min_price = list[min_index];
    }
  }

  fout << total << endl;
}
