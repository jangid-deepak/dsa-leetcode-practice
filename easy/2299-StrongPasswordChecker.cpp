#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool strongPasswordCheckerII(string password) {
            if (password.size() < 8 ) {
               return false; 
            }
            bool isLowerV = false;
            bool isUpperV = false;
            bool isDigitV = false;
            bool isSpecialV = false;
    
            string special = "!@#$%^&*()-+";
            if (islower(password[0])) {
                isLowerV = true;
            }
            if (isupper(password[0])) {
                isUpperV = true;
            }
            if (isdigit(password[0])) {
                isDigitV = true;
            }
    
            for(char s: special) {
                if (s == password[0]) {
                    isSpecialV = true;
                    break;
                }
            }
    
            for(int i=1; i<password.size(); i++)  {
                if (password[i] == password[i-1]) {
                    return false;
                }
                if (!isSpecialV) {
                    for(char s: special) {
                        if (s == password[i]) {
                            isSpecialV = true;
                            break;
                        }
                    }
                }
    
                if (!isLowerV && islower(password[i])) {
                    isLowerV = true;
                }
                
                if (!isUpperV && isupper(password[i])) {
                    isUpperV = true;
                }
                
                if (!isSpecialV && isdigit(password[i])) {
                    isSpecialV = true;
                }
            }
            return isLowerV && isUpperV && isSpecialV;
        }
    };

int main() {
    Solution sol;
    bool ans =  sol.strongPasswordCheckerII("ziyS5FrPQhoQ5oEWRpHW2MjI7sGfcMJdcsjQnIyRbdCilvFaQN07jQtAkOklbjFrU5KcHzw4EvJ41Yz2Ykyd");

    cout << "ans: " << ans << endl;
    return 0;
}