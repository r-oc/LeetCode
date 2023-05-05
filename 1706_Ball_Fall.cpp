// author: r-oc ryan o'callaghan
// date: 2023-05-04
// status: Accepted

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << endl << #y << "=" << y << endl << endl

#define sz(x) (int) (x).size()

vector<int> findBall(vector<vector<int>>& grid) {
  int m = sz(grid);
  int n = sz(grid[0]);
  vector<int> ans;

  int x, y;

  for(int i = 0; i < n; i++) {
    x = 0; y = i;

    for(int j = 0; j < m; j++) {

      if(grid[x][y] == 1) {
        if(y+1 >= n) {
          ans.push_back(-1);
          break;
        }
        else if(grid[x][y] != grid[x][y+1]) {
          ans.push_back(-1);
          break;
        }
        x++; y++;
      }
      else if(grid[x][y] == -1) {
        if(y-1 < 0) {
          ans.push_back(-1);
          break;
        }
        else if(grid[x][y] != grid[x][y-1]) {
          ans.push_back(-1);
          break;
        }
        x++; y--;
      }
    }

    if(x == m) {
      ans.push_back(y);
    }

  }

  return ans;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
  vector<int> answer = {1,-1,-1,-1,-1};

  if(findBall(grid) == answer) {
    cout << "Test passed!" << endl;
  } else cout << "Test faild!" << endl;

}
