#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        std::function<void(string, int, int)> backtrack = [&backtrack, &result, &n](string s, int oc, int cc) {
            if (s.size() == 2 * n) {
                result.push_back(s);
                return;
            }

            if (oc < n) 
                backtrack(s + "(", oc + 1, cc);
            
            if (cc < oc) 
                backtrack(s + ")", oc, cc + 1);
        };
        backtrack("", 0, 0);
        return result;
    }
};

int main() {
    Solution task;
    int n;

    cin >> n;
    
    auto v = task.generateParenthesis(n);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return EXIT_SUCCESS;
}