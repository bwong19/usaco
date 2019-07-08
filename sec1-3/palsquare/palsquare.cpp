/*
ID: bwong43
LANG: C++
TASK: palsquare
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

int main() {
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");

  int b;
  fin >> b;
  
  
  vector<string> palindromes;
  vector<string> squares;

  for (int n = 1; n <= 300; ++n) {
    if (is_palin(toString(convert(n*n, b)))) {
      palindromes.push_back(toString(convert(n,b)));
      squares.push_back(toString(convert(n*n,b)));
    }
  }

  for (int i = 0; i < palindromes.size(); ++i) {
    fout << palindromes[i] << " " << squares[i] << endl;
  }
  
}
