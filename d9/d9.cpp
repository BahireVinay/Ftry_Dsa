#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
//the following function is for checking palindrome
char converttolower(char ch) {
        if(ch>='a'&& ch<='z') {
            return ch;
        }
        else {
            char temp = ch +'a'-'A';
            return temp;
        }
    }                                           
    bool isPalindrome(string s) {
        return recur(s,0,s.size()-1);
    }

    bool recur(string &s , int i,int n) {

        if(i>=n) {
            return true;
        }
        if(!isalnum(s[i])) {
            return recur(s,i+1,n);
        }
        if(!isalnum(s[n])) {
            return recur(s,i,n-1);
        }

        if(converttolower(s[i]) != converttolower(s[n]) ) {
            return false;
        }
        return recur(s,i+1,n-1);
      
    }
//the following function is for finding fibonacci number
    int fib(int n) {
        if(n==0||n==1)return n;
        return {fib(n-1)+fib(n-2)};
    }
    /*best tc approach 
     int fib(int n){

        if(n == 1 || n == 0)
            return n;

        int prev1 = 0;
        int prev2 = 1;
        int curr;

        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
            
        return curr;
    }
    */
};
int main(){
    Solution s;
    string str =" ";
    cout<<s.isPalindrome(str);
        //cout<<s.fib(5);
    return 0;
}