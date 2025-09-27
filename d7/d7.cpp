#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
};
ListNode* convertARRtoLL(int arr[],int n){
    if(n==0)return nullptr;
    ListNode* head=new ListNode();
    head->val=arr[0];
    ListNode* temp=head;
    for(int i=1;i<n;i++){
        ListNode* newnode=new ListNode();
        newnode->val=arr[i];
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = slow->next;  // Remove middle node
        delete slow;  // Free memory

        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head; // base case

        // Step 1: Convert LL to array
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Sort the array
        sort(arr.begin(), arr.end());

        // Step 3: Copy sorted values back to linked list
        temp = head;
        for(int val : arr){
            temp->val = val;
            temp = temp->next;
        }

        return head;
    }

};

int main(){
    Solution s;
    int arr[]={1,2,3,4,5};
    ListNode* head=convertARRtoLL(arr,5);
    ListNode* ans=s.deleteMiddle(head);
    ListNode* temp=ans; 
    
    while(ans){
        cout<<ans->val<<endl;
        ans=ans->next;
        //cout<<ans<<endl;
    }
    return 0;
}