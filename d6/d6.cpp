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

ListNode* reverseList(ListNode* head){
        stack<int>st;
        if(head==nullptr || head->next==nullptr)return head;

        ListNode*temp = head;
        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

    ListNode* slow = head;
    ListNode* fast = head;

    // Find middle
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* secondHalf = reverseList(slow->next);

    // Compare first half and second half
    ListNode* p1 = head;
    ListNode* p2 = secondHalf;
    while (p2 != nullptr) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}
ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;  // save starting point of even list

    while (even && even->next) {
        odd->next = even->next;   // link odd to next odd
        odd = odd->next;

        even->next = odd->next;   // link even to next even
        even = even->next;
    }

    odd->next = evenHead;  // attach even list after odd list
    return head;
    }
ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return nullptr;

        int len=0;
        ListNode*curr=head;

        while(curr){
            len++;
            curr=curr->next;
        }
        curr=head;
        //chking for head
        if(n==len){
            ListNode*delnode=head;
            head=head->next;
            curr=head;
            delete delnode;
            return head;
        }
        int cnt=len-n;

        while(cnt>1){
            curr=curr->next;
            cnt--;
        }

        ListNode*delnode=curr->next;
        curr->next=delnode->next;
        delete delnode;

        return head;
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
    //bool ans=s.isPalindrome(head);
    //ListNode* ans=s.oddEvenList(head);
    //ListNode* ans=s.removeNthFromEnd(head,2);
    
    while(ans){
        cout<<ans->val<<endl;
        ans=ans->next;
        //cout<<ans<<endl;
    }
    return 0;
}