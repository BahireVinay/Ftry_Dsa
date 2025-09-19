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
ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> mp;
        ListNode* node = head;
        while(node!=nullptr){
            if(mp[node]>0){
                return node;
            }
            mp[node] = 1;
            node=node->next;
        }
        return nullptr;
    }

int findLengthOfLoop(ListNode *head) {
        if(head == nullptr && head->next == nullptr)return 0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                //cycle detected
                int len=1;
                ListNode* temp=slow;
                while(temp->next!=slow){
                    len++;
                    temp=temp->next;
                }
                return len;
            }
        }
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
    ListNode* ans=s.detectCycle(head);
    //int ans=s.findLengthOfLoop(head);

    while(ans){
        cout<<ans->val<<endl;
        ans=ans->next;
        //cout<<ans<<endl;
    }
    return 0;
}