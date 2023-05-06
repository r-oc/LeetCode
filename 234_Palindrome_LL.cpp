// author: r-oc ryan o'callaghan
// date: 2023-05-06
// status: accepted. O(n) time complexity, O(n) space complexity.

#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define sz(x) (int) (x).size()

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << endl << #y << "=" << y << endl << endl

bool isPalindrome(ListNode* head) {
  vector<int> nodes;

  while(head != NULL) {
    nodes.push_back(head->val);
    head = head->next;
  }

  return equal(nodes.begin(), nodes.end(), nodes.rbegin(), nodes.rend());
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
