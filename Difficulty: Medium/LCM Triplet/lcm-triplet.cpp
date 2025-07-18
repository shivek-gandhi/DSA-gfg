class Solution {
  public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    
    long long lcm3(long long a, long long b, long long c) {
        return lcm(lcm(a, b), c);
    }
    int lcmTriplets(int n) {
        // code here
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;

        long long ans = 0;

        // Try top 5 numbers as starting points, safe for n >= 3
        for (int i = n; i >= max(1, n - 5); --i) {
            for (int j = i - 1; j >= max(1, n - 5); --j) {
                for (int k = j - 1; k >= max(1, n - 5); --k) {
                    long long val = lcm3(i, j, k);
                    ans = max(ans, val);
                }
            }
        }

        return ans;
        }
};