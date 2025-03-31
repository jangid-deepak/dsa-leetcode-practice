#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

class Solution
{
public:
    vector<int> segmentedSieve(int L, int R)
    {
        int size = R - L + 1;
        vector<bool> isPrime(size, true);

        if (L == 1)
            isPrime[0] = false;

        vector<int> smallPrimes = simpleSieve(sqrt(R));

        for (int p : smallPrimes)
        {
            int start = max(p * p, L + (p - L % p) % p);

            for (int j = start; j <= R; j += p)
            {
                isPrime[j - L] = false;
            }
        }


        vector<int> primeValue;
        for(int i=0; i< size; i++) {
            if (isPrime[i]) {
                primeValue.push_back((L + i));
            }
        }

        int minDiff = INT_MAX;
        vector<int> closest(2, -1);
        for (int i = 0; i < primeValue.size() - 1; i++) {
            int diff = primeValue[i+1] - primeValue[i];
            if (minDiff > diff) {
                minDiff = diff;
                closest[0] = primeValue[i];
                closest[1] = primeValue[i+1];
            }
        }
        return closest;
    }

    vector<int> simpleSieve(int right)
    {
        vector<int> prime(right + 1, true);
        for (int p = 2; p * p <= right; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i < right; i += p)
                {
                    prime[i] = false;
                }
            }
        }
        vector<int> ans;
        for (int p = 2; p <= right; p++)
        {
            if (prime[p] == true)
                ans.push_back(p);
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // sol.print(10, 19);
    vector<int> ans = sol.segmentedSieve(1, 1000000);
    // vector<int> ans = sol.closestPrimes(210, 19);
    cout << "ans :" << ans[0] << " " << ans[1] << endl;
    return 0;
}