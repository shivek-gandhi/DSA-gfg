class Solution {
  public:
    
    int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
    }
    
    int vowelCount(string& s) {
        // code here
    unordered_map<char, int> vowelCount;
    string vowels = "aeiou";
    
    for (char c : s) {
        if (vowels.find(c) != string::npos) {
            vowelCount[c]++;
        }
    }

    if (vowelCount.empty()) return 0;

    int product = 1;
    for (auto& it : vowelCount) {
    product *= it.second;
    }
    
    int numUniqueVowels = vowelCount.size();
    int permutations = factorial(numUniqueVowels);

    return product * permutations;
    }
};