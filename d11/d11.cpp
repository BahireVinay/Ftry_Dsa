#include <bits/stdc++.h>
using namespace std;
//the following function is random not recursion week 

//the following function is for finding maximum frequency of an element in an array after k increments

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Sort the array first
        
        long long sum = 0;  // To store the sum of current window
        int left = 0;       // Left pointer for window
        int maxFreq = 0;    // Result: maximum frequency found
        
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];  // Add current number to the window
            
            // Check if we can make all numbers in window equal to nums[right]
            // If not, move the left pointer to shrink the window
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }
            
            // Update the maximum frequency
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }

//the following function is for checking if an array is sorted and rotated or not
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // count how many times nums[i] > nums[i+1]

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            if (count > 1) return false; // more than one drop = not sorted-rotated
        }

        return true;
    }
//the following function is for removing duplicates from a sorted array in place and returning the new length
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int j = 0; // position of last unique element

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i]; // place next unique element
        }
    }

    return j + 1; // number of unique elements
}

int main() {
    vector<int> nums = {1,2,4};
    int k = 5;
    cout << maxFrequency(nums, k) << endl; 
    //
    return 0;

}