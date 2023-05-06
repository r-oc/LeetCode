// author: r-oc ryan o'callaghan
// date: 2023-05-05
// status: Accepted
// desc: Two-pass method

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

ListNode* removeNthFromEnd(ListNode* head, int n) {
  int list_len = 0;
  ListNode* saved_head = head;
  ListNode* next_node;

  /* Calculate the length of the list */
  while(head != NULL) {
    list_len++;
    head = head->next;
  }

  /* Edge Cases:
   *    1. list_length is 1, return empty (NULL).
   *    2. n == 1 (i.e. the last node in the list)
   *    2. n == list_length (i.e. the first node in the list)
   */

  // 1.
  if(list_len == 1)
    return NULL;

  head = saved_head;
  
  // 2.
  if(n == 1) {
    while(head->next->next != NULL) {
      head = head->next;
    }
    head->next = NULL;

    head = saved_head;
    return head;
  }

  // 3. 
  else if(n == list_len) {
    head = head->next;
    return head;
  }

  /* List is at least 2 nodes long, and the node to remove is in between two other nodes. */
  next_node = head->next;
  for(int i = 0; i < list_len-n-1; i++) {
    head = next_node;
    next_node = next_node->next;
  }
  head->next = next_node->next;

  head = saved_head;
  return head;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

}
