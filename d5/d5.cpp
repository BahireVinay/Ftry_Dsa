#include <bits/stdc++.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        int Mid=(cnt)/2;
        while(Mid>0){
            head=head->next;
            Mid--;
        }
        return head;
    }
    ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    stack<int> st;
    ListNode* temp = head;

    // Push all data into stack
    while (temp) {
        st.push(temp->val);
        temp = temp->next;
    }

    // Assign values back in reverse order
    temp = head;
    while (temp) {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}
bool hasCycle(ListNode *head) {
/*
    Constraints:
    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.
*/
    if (head == NULL || head->next == NULL) return false;

    ListNode* temp = head;
    int cnt = 0;

    // Traverse with a hard limit
    while (temp != NULL && cnt < 10000) {
        cnt++;
        temp = temp->next;
    }

    // If we stopped because temp became NULL → no cycle
    if (temp == NULL) return false;

    // If we hit the limit → assume cycle
    return true;
}
};
ListNode* convertARRtoLL(int arr[],int n){
    ListNode* head=new ListNode(arr[0]);
    ListNode* temp=head;
    for(int i=1;i<n;i++){
        ListNode* newNode=new ListNode(arr[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}


int main(){
    Solution s;
    int arr[]={1,2,3,4,5};
    ListNode* head=convertARRtoLL(arr,5);
    ListNode* ans=s.middleNode(head);
    //iscycle=s.hasCycle(head);
    //ListNode* ans=s.reverseList(head);
    while(ans){
        cout<<ans->val<<endl;
        ans=ans->next;
    }
    return 0;
}