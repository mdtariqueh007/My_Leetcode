
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXor(n + 1, 0);

        // Compute prefix XOR
        for (int i = 0; i < n; ++i) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }

        int count = 0;

        // Iterate over all possible i and k
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                // If prefixXor[i] == prefixXor[k + 1], count the number of valid j's
                if (prefixXor[i] == prefixXor[k + 1]) {
                    count += (k - i);
                }
            }
        }

        return count;
    }
};
