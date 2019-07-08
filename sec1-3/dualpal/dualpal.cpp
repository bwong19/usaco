/*
ID: bwong43
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool is_palin(string s) {
  for (int i = 0; i < s.length()/2; ++i)
    if (s[i] != s[s.length()-1-i])
      return 0;
  return 1;
}

// converts base 10 number to base B
vector<int> convert(int num, int base) {
  vector<int> out;
  if (num < base) {
    out.push_back(num);
    return out;
  }
  int div = base;
  while (div*base <= num ) {
    div *= base;
  }
 
  while (div > 0) {
    out.push_back(num/div);
    num %= div;
    div /= base;
  }
  return out;
}

string toString(vector<int> num) {
  string out = "";

  for (int i = 0; i < num.size(); ++i) {
    int n = num[i];

    if (0 <= n && n <= 9) out += to_string(n);

    else out += (n + 'A' - 10);
  }
  
  return out;
}

string magic(int num, int base) {
  return toString(convert(num, base));
}

bool dualpal(int num) {
  int count = 0;
  for (int b = 2; b <= 10; ++b) {
    if (is_palin(magic(num, b))) count++;
    if (count == 2) return 1;
  }
  if (count == 2) return 1;
  return 0;
}

int main() {
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");
  
  int n, s;
  fin >> n >> s;
  s++;
  int count = 0;
  vector<int> hehe;
  
  while (count < n) {
    if (dualpal(s)) {
      hehe.push_back(s);
      count++;
    }
    s++;
  }
  
  for (int i = 0; i < hehe.size(); ++i) {
    fout << hehe[i] << endl;
  }
}
