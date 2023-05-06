// author: r-oc ryan o'callaghan
// date: 2023-05-06
// status: accepted. O(n) time complexity, O(1) space complexity.

#include <bits/stdc++.h>
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
  ListNode* slow = head;
  ListNode* fast = head;

  // Set slow = middle of list or,
  //            the beginning of the reverse of the first half of the list.
  while(fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  fast = head;

  // Reverse slow
  ListNode* prev = NULL;
  while(slow != NULL) {
    ListNode* next = slow->next;
    slow->next = prev;
    prev = slow;
    slow = next;
  }
  slow = prev;

  // Check differences
  while(slow != NULL) {
    if(slow->val != fast->val)
      return false;
    slow = slow->next;
    fast = fast->next;
  }

  return true;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
