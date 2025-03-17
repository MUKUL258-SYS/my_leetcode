/*class Solution {
public:

void sieve(int n, vector<bool> &isPrime) {
    isPrime.assign(n + 1, true); // Mark all numbers as prime initially
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (long long i = 2; i * i <= n; i++) {
        if (isPrime[i]) { // If i is a prime
            for (long long j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

}

    int nonSpecialCount(int l, int r) {
        vector<int>vp;
        int v=1e4;
        vector<int>arr;
        vector<bool>isprime(v+10);
        sieve(v,isprime);
        for(int i=0;i<=v;i++){
            if(isprime[i])arr.push_back(i);
        }
        
        for(auto i:arr){
            cout<<i<<" ";
            vp.push_back(i*i);
        }
       vector<int>specialNumbers=vp;
        int specialCount = upper_bound(specialNumbers.begin(), specialNumbers.end(), r)
                     - lower_bound(specialNumbers.begin(), specialNumbers.end(), l);
       // int dec=idx2-idx1+1;
        return r-l+1-specialCount;

    }
};
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Sieve of Eratosthenes to generate prime numbers up to sqrt(r)
    vector<int> generatePrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return primes;
    }

    // Function to count numbers in range [l, r] that are NOT special
    int nonSpecialCount(int l, int r) {
        int sqrtR = sqrt(r);
        vector<int> primes = generatePrimes(sqrtR);
        vector<int> specialNumbers;
        
        // Store all prime squares
        for (int p : primes) {
            int square = p * p;
            if (square > r) break;
            specialNumbers.push_back(square);
        }
        
        // Count special numbers in [l, r] using binary search
        int specialCount = upper_bound(specialNumbers.begin(), specialNumbers.end(), r)
                         - lower_bound(specialNumbers.begin(), specialNumbers.end(), l);
        
        return (r - l + 1) - specialCount; // Total count - special count
    }
};

