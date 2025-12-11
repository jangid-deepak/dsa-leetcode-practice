#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> countBits(int n) {
  vector<int> ans;
  for (int i = 0; i <= n; i++) {
    int x = i >> 1;
    cout << "i >> 1 : " << x << " ";
    int temp = i;
    int count = 0;
    while (temp > 0) {
      if (temp % 2 == 1)
        count++;
      temp /= 2;
    }
    ans.push_back(count);
    cout << "i " << i << ":\t " << count << endl;
  }
  return ans;
};

int main() {

  vector<int> ans = countBits(100);

  for (int num : ans) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
