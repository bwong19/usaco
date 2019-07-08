#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

typedef struct node {
  int data;
  vector<int> adj;
} Node;

typedef vector<Node> Graph;

int main() {
  ifstream fin("planting.in");
  ofstream fout("planting.out");

  int n;
  fin >> n;
  
  Graph g;

  for (int i = 0; i < n; ++i) {
    Node tmp;
    tmp.data = i;
    g.push_back(tmp);
  }

  for (int i = 0; i < n-1; ++i) {
    int n1, n2;
    fin >> n1 >> n2;
    n1--;
    n2--;

    g[n1].adj.push_back(n2);
    g[n2].adj.push_back(n1);
  }

  int max = -1;
  for (int i = 0; i < n; ++i) {
    if ((int) g[i].adj.size() > max) {
      max = g[i].adj.size();
    }
  }
  max++;

  fout << max << endl;
}
