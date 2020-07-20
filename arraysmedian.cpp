#include <iostream> 
#include <vector> 
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    float n1med = 0, n2med = 0, val = -1; 
    int n1size = nums1.size() - 1, n2size = nums2.size() - 1; 

    if(n1size + 1 % 2 != 0 && n2size + 1 % 2 != 0) { 
        n1med = nums1[n1size/2];  
        n2med = nums2[n2size/2]; 

        val = n1med + n2med / 2;
        
        return val; 

    } else if(nums1.size() % 2 != 0 && nums2.size() % 2 == 0) { 
        return (nums1[nums1.size()/2] + (nums2[nums2.size()/2] + nums2[nums2.size()/2+1])) / 2; 
    } else if(nums2.size() % 2 != 0 && nums1.size() % 2 == 0) { 
        return (nums2[nums2.size()/2] + (nums1[nums1.size()/2] + nums1[nums1.size()/2+1])) / 2; 
    } 
    return val; 
}



int main()  { 
    vector<int> l1{1,2,3}; 
    vector<int> l2{3,4,5};  
    cout << findMedianSortedArrays(l1, l2);
    return 0; 
}