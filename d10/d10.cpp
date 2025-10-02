#include <bits/stdc++.h>
using namespace std;

//the following function is for sorting a stack using recursion

void insertSorted(stack<int> &st, int val) {
    if (st.empty() || st.top() <= val) { // Correct position found
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    insertSorted(st, val);   // Recursive call
    st.push(temp);           // Restore element
}
// Sort the stack using recursion
void sortStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    sortStack(st);           // Sort smaller stack
    insertSorted(st, topElement); // Insert back correctly
}

//the following function is for reversing a stack using recursion
void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(temp);  // restore the element
}

// Recursive reverse function
void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    reverseStack(st);         // reverse smaller stack
    insertAtBottom(st, topElement); // put current element at bottom
}

int main() {
    stack<int> st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);

    sortStack(st);

    cout << "Sorted stack is:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}