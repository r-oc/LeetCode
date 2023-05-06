// author: r-oc ryan o'callaghan
// date: 2023-05-05
// status: Accepted

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << endl << #y << "=" << y << endl << endl

#define sz(x) (int) (x).size()

string longestCommonPrefix(vector<string>& strs) {

  int num_of_strings = sz(strs);
  string longest_prefix = strs[0], temp;

  for(int i = 1; i < num_of_strings; i++) {

    temp.clear();

    if(longest_prefix == strs[i])
      temp = longest_prefix;

    else {

      for(int j = 0; j < strs[i].length() && j < longest_prefix.length(); j++) {
        if(strs[i][j] == longest_prefix[j])
          temp.push_back(longest_prefix[j]);
        else break;
      }

      longest_prefix = temp;

    }

  }

  return longest_prefix;
}

void solve() {
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // vector<string> stringArr = {"flower", "flow", "flight"};
  vector<string> stringArr = {"cir","car"};
  string answer = "c";

  if(longestCommonPrefix(stringArr) == answer) {
    cout << "Test passed!" << endl;
  } else cout << "Test Failed!" << endl;
}
