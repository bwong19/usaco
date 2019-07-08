/*
ID: bwong43
LANG: C++
TASK: namenum
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string conv(char n) {
  switch(n) {
  case '2': return "ABC";
  case '3': return "DEF";
  case '4': return "GHI";
  case '5': return "JKL";
  case '6': return "MNO";
  case '7': return "PRS";
  case '8': return "TUV";
  case '9': return "WXY";
  default: cout << "error: n = " << n << endl;
  }
  return "";
}

vector<string> narrow(vector<string> words, string con, int pos) {
  vector<string> out;
  for (int i = 0; i < words.size(); ++i) {
    if (words[i][pos] == con[0]) out.push_back(words[i]);
    else if (words[i][pos] == con[1]) out.push_back(words[i]);
    else if (words[i][pos] == con[2]) out.push_back(words[i]);
  }
  return out;
}

vector<string> grind_time(vector<string> kms, string nvm) {
  vector<string> out;

  for (int i = 0; i < kms.size(); ++i)
    for(int j = 0; j < 3; ++j) 
      out.push_back(kms[i]+nvm[j]);

  return out;
}

int main() {
  ifstream fin("namenum.in");
  ifstream din("dict.txt");
  ofstream fout("namenum.out");

  string s;
  fin >> s;

  vector<string> dict;
  string temp;
  while (din >> temp) if (s.length() == temp.length()) dict.push_back(temp);
  
  

  vector<string> nums;
  for (int i = 0; i < s.length(); ++i) nums.push_back(conv(s[i]));
  
  vector<string> words;
  for (int i = 0; i < 3; ++i) {
    string temp = "";
    temp += nums[0][i];
    words.push_back(temp);
  }
  /*
  for (int i = 1; i < nums.size(); ++i) {
    words = grind_time(words, nums[i]);
  }
  */
  for (int i = 0; i < nums.size(); ++i) {
    dict = narrow(dict, nums[i], i);
  }
  
  
  /*
  for (int i = 0; i < dict.size(); ++i) {
    for (int j = 0; j < words.size(); ++j) {
      if (!dict[i].compare(words[j])) result.push_back(dict[i]);
    }
  }
  */

  
  if (!dict.size()) {
    fout << "NONE" << endl;
    return 0;
  }
  for (int i = 0; i < dict.size(); ++i) {
    fout << dict[i] << endl;
  }
}
