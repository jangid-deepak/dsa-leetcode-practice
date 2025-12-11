#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int main() {
    vector<int> array = {1, 2, 1};
    int ans;
    for(int i=0; i<array.size(); i++) {
        unordered_map<int, int> hash;
        for(int j=i; j<array.size(); j++) {
            hash[array[j]] ++;
            
            for(int k=i; k<=j; k++) {
                cout << array[k] << " ";
            }
            cout << endl;
            ans += (hash.size() * hash.size());
        }
        cout << endl;
    }
    
    cout << "ams " << ans << endl;
}
