#include <iostream>
#include <string>
#include <algorithm>
#include <vector> 
using namespace std; 




int lengthOfLongestSubstring(string s) {
    vector<char> lookup; 
    int max = 0; 

    for(char &c: s) { 
        auto it = find(lookup.begin(), lookup.end(), c); 
        if(it != lookup.end()) { 
            if(max < lookup.size()) {
                max = lookup.size(); 
            }
            it++; 
            lookup.erase(lookup.begin(), it); 
        } 
        lookup.push_back(c);
    }
    if (max < lookup.size()) {
        max = lookup.size();
    }
    return max; 
}

int main()  { 
    cout << "Longest substring: " << lengthOfLongestSubstring("dvdf");
}