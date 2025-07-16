class Solution {
  public:
  
    vector <int> generatePrimes(int limit){
        vector<bool> isPrime(limit+1 ,true);
        vector<int> primes;
        
        isPrime[0] = isPrime[1] = false;
        
        for(int i=2;i<=limit;i++){
            if(isPrime[i]){
                primes.push_back(i);
                for(int j=i*i;j<=limit;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        return primes;
    };
    
    int countNumbers(int n) {
        // Code Here
        unordered_set<long long> unique;
        int count = 0;
        
        
        int limit = sqrt(n);
        vector<int> primes = generatePrimes(limit);
        
        for(int p:primes){
            long long num = 1;
            for (int i = 0; i < 8; i++) {
                num *= p;
                if (num > n) break;
            }
            if(num<=n){
                // count++;
                 unique.insert(num);
            }
        }
        
        int size = primes.size();
        for(int i=0;i< size;i++){
            for(int j=i+1;j<size;j++){
                long long a= 1LL* primes[i]*primes[i];
                if(a>n) break;
                long long b = 1LL* primes[j]*primes[j];
                if(b>n) break;
                // long long num = 1LL * primes[i]*primes[i]*primes[j]*primes[j];
                if (a*b <= n) {
                    unique.insert(a*b);
                } 
                else {
                    break;
                }
            }
        }
        return unique.size();
    }
};