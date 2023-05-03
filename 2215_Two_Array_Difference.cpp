// author: r-oc ryan o'callaghan
// date: 2023-05-03
// status: Accepted | 31ms runtime (beats 97%), 26.2mb (beats 99%)

#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;

#define sz(x) (int) (x).size()

#define yes cout << "yes\n"
#define no cout << "no\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << endl << #y << "=" << y << endl << endl

using ll = long long;

#define MAX_NUM 2001

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
  vector<vector<int>> ans(2);
  bool values1[MAX_NUM];
  bool values2[MAX_NUM];
  bool added1[MAX_NUM];
  bool added2[MAX_NUM];

  memset(values1, 0, sizeof(values1));
  memset(values2, 0, sizeof(values2));
  memset(added1, 0, sizeof(added1));
  memset(added2, 0, sizeof(added2));

  for(int i = 0; i < sz(nums1); i++)
    values1[nums1[i] + 1000] = 1;
  
  for(int i = 0; i < sz(nums2); i++)
    values2[nums2[i] + 1000] = 1;

  for(int i = 0; i < sz(nums1); i++)
    if(values2[nums1[i] + 1000] == 0 && added1[nums1[i] + 1000] == 0) {
      ans[0].push_back(nums1[i]);
      added1[nums1[i] + 1000] = 1;
    }

  for(int i = 0; i < sz(nums2); i++)
    if(values1[nums2[i] + 1000] == 0 && added2[nums2[i] + 1000] == 0) {
      ans[1].push_back(nums2[i]);
      added2[nums2[i] + 1000] = 1;
    }

  return ans;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // vector<int> nums1 = {1, 2, 3};
  // vector<int> nums2 = {2, 4, 6};
  vector<int> nums1 = {1, 2, 3, 3};
  vector<int> nums2 = {1, 1, 2, 2};
  vector<vector<int>> output = {{3}, {}};
  
  if(findDifference(nums1, nums2) == output) {
    cout << "Passed Test 1" << endl;
  } else cout << "Failed Test 1" << endl;
}
