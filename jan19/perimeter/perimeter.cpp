#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void printGrid(bool** grid, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

bool isSafe(bool** grid, int n, int r, int c) {
  return (r >= 0) && (r < n) && (c >= 0) && (c < n) && (grid[r][c]); 
}

void DFS(bool** grid, bool** visited, int n, int r, int c, int &count, int &perim) {
  visited[r][c] = 1;
  
  int s = 4;
  if (isSafe(grid, n, r+1, c)) {
    s--;
    if (!visited[r+1][c]) {
      count++;
      DFS(grid, visited, n, r+1, c, count, perim);
    }
  }

  if (isSafe(grid, n, r-1, c)) {
    s--;
    if (!visited[r-1][c]) {
      count++;
      DFS(grid, visited, n, r-1, c, count, perim);
    }
  }

  if (isSafe(grid, n, r, c+1)) {
    s--;
    if (!visited[r][c+1]) {
      count++;
      DFS(grid, visited, n, r, c+1, count, perim);
    }
  }

  if (isSafe(grid, n, r, c-1)) {
    s--;
    if (!visited[r][c-1]) {
      count++;
      DFS(grid, visited, n, r, c-1, count, perim);
    }
  }
  perim += s;
}

pair<int, int> bestBlob(bool** grid, int n) {
  bool** visited = new bool*[n];
  for (int i = 0; i < n; ++i) {
    visited[i] = new bool[n];
    for (int j = 0; j < n; ++j) {
      visited[i][j] = 0;
    }
  }

  pair<int, int> max = make_pair(-1, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      //cout << i << " " << j << endl;
      //printGrid(grid, n);
      //cout << endl;
      if (grid[i][j] && !visited[i][j]) {
	int count = 1;
	int perim = 0;
	
	DFS(grid, visited, n, i, j, count, perim);
	

	//cout << count << " " << perim << endl;
	//cout << perim << endl;
	if (max.second == -1) {
	  max.first = count;
	  max.second = perim;
	}

	if (count > max.first) {
	  max.first = count;
	  max.second = perim;
	}
	if (count == max.first) {
	  if (perim < max.second) {
	    max.second = perim;
	  }
	}
      }
    }
  }

  return max;

  for (int i = 0; i < n; ++i) {
    delete[] visited[i];
  }
  delete[] visited;
}



int main() {
  ifstream fin("perimeter.in");
  ofstream fout("perimeter.out");

  int n;
  fin >> n;

  bool** grid = new bool*[n];
  for (int i = 0; i < n; ++i) {
    grid[i] = new bool[n];
    for (int j = 0; j < n; ++j) {
      char tmp;
      fin >> tmp;
      if (tmp == '.') {
	grid[i][j] = 0;
      } else {
	grid[i][j] = 1;
      }
    }
  }

  
  pair<int, int> result = bestBlob(grid, n);

  fout << result.first << " " << result.second << endl;

  // printGrid(grid, n);


  for (int i = 0; i < n; ++i) {
    delete[] grid[i];
  }
  delete[] grid;
}
