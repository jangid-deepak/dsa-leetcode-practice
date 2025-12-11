#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string pushDominoes(string d) {

    int N = d.size();

    // left to right
    // check leftForce
    vector<int> lf(N);

    bool actingForce = false;
    int forceValue = N;
    for (int i = 0; i < N; i++) {
      if (d[i] == 'R') {
        forceValue = N;
        lf[i] = forceValue;
        actingForce = true;
      } else if (d[i] == 'L') {
        actingForce = false;
        lf[i] = 0;
      } else {
        if (actingForce) {
          lf[i] = --forceValue;
        } else {
          lf[i] = 0;
        }
      }
    }
    cout << "left to right" << endl;
    // consoling rf;
    for (int num : lf) {
      cout << num << " ";
    }
    cout << endl;

    // right to left
    // rightForce
    actingForce = false;
    vector<int> rf(N);
    for (int i = N - 1; i >= 0; i--) {
      if (d[i] == 'L') {
        forceValue = N;
        rf[i] = forceValue;
        actingForce = true;
      } else if (d[i] == 'R') {
        actingForce = false;
        rf[i] = 0;
      } else {
        if (actingForce) {
          rf[i] = --forceValue;
        } else {
          rf[i] = 0;
        }
      }
    }

    cout << "right to left" << endl;
    for (int num : rf) {
      cout << num << " ";
    }
    cout << endl;

    string ans = "";

    for (int i = 0; i < N; i++) {
      if (lf[i] > rf[i]) {
        // left
        ans += 'R';
      } else if (lf[i] < rf[i]) {
        // right
        ans += 'L';
      } else {
        // equal
        ans += '.';
      }
    }
    return ans;
  }
};

int main() {

  Solution sol;
  string d = ".......LR...LR.R......L";
  string ans = sol.pushDominoes(d);
  cout << ans << endl;
  return 0;
}
