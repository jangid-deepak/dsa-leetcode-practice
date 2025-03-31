#include <iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        // bool canThreePartsEqualSum(vector<int>& arr) {
        //     int totalSum=0;
        //     for(int i : arr)totalSum+=i;
        
        //     if(totalSum%3 != 0)return 0; //if partition not possible
        
        //     int partitions=0;
        //     int i=0;  
        //     int sum=0;
        
        //     while(i<arr.size() && partitions < 2){
        //         sum+=arr[i]; 
        //         if(sum == (totalSum/3)) {     
        //             partitions++; 
        //             sum=0;
        //         }
        
        //     i++; 
        //     } 
            
        //     if(partitions < 2 || i == arr.size()) return 0;
        
            
        //     return 1;  
        // }
       bool canThreePartsEqualSum(vector<int>& arr) {
            int sum = 0;
            int count = 0;
            for(int i=0; i<arr.size(); i++) {
                sum += arr[i];
            }

            cout << sum << endl;
            if (sum%3 == 0) {
                int currentSum = 0;
                for(int i=0; i<arr.size(); i++) {
                    currentSum += arr[i];
                    if (currentSum == sum/3) {
                        count++;
                        currentSum = 0;
                    }
                }
            } else {
                return false;
            }
            cout << "count :" << count << endl;
            return count == 3? true: false;
       } 
};

int main() {
    Solution sol;
    vector<int> arr = {1,-1,1,-1};
    cout << sol.canThreePartsEqualSum(arr) << endl;
    return 0;
}