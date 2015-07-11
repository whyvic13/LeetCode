Idea:

Tips to speed up:
1. Boundary : p < sqrt(n). We only need to consider factors up to √n because, if n is divisible by some number p, then n = p × q and since p ≤ q, we could derive that p ≤ √n.
2. Avoid time-expensive operator: use j += i instead of j % i == 0, use i * i < n instead of i < sqrt(n).
3. Sieve of Eratosthenes

Time Complexity:

O(n*log(log(n)))

Space Complexity:

O(n)

class Solution {
public:
    int countPrimes(int n) {
        bool *isPrime = new isPrime[n];
        for(int i=2;i<n;i++){
            isPrime[i] = true;
        }
        for(int i=2;i*i<n;i++){
            if(!isPrime[i]) continue;
            for(int j=i*i;j<n;j+=i){
                isPrime[j] = false;
            }
        }
        int count = 0;
        for(int i=2;i<n;i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
    
};
