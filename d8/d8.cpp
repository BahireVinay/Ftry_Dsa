#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {

       
        int i = 0, n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-')sign=-1;
            i++;
        }

        // 3. Convert digits
        long long num = 0; // use long long to detect overflow
        while (i < n && isdigit(s[i])) {
            int rmdr = s[i] - '0';

            // 4. Check overflow before multiplying
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && rmdr > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + rmdr;
            i++;
        }

        return (int)(sign * num);
    }
 double myPow(double x, int n) {
        long long N = n;      // handle INT_MIN safely
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }

private:
    double fastPow(double x, long long n) {
        if(n == 0) return 1;        // base case
        double half = fastPow(x, n / 2);  // divide step
        if(n % 2 == 0)
            return half * half;     // even power
        else
            return half * half * x; // odd power
    }
};
const long long MOD = 1000000007;

    long long binpow(long long a, long long b, long long mod) {
        long long res = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long part1 = binpow(5, even_count, MOD);
        long long part2 = binpow(4, odd_count, MOD);

        return (part1 * part2) % MOD;
    }

int main(){
    Solution s;
    string str="-42";
    cout<<s.myAtoi(str);
    return 0;
}