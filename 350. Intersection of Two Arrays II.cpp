#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> nums1;
vector<int> nums2;
vector<int> res;
	    
void intersect(vector<int> nums1, vector<int> nums2) {

    /*
    Tips:
    What if the given array is already sorted? 
    To Do:
    Sort two arrays
    */
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int i,j;
    /*
    Two pointers ¡®i¡¯ & 'j' point to two arrays
    */
    for(i=0,j=0;i<nums1.size() && j<nums2.size();) {
        if(nums1[i]==nums2[j]) {
            res.push_back(nums1[i]);
            /*
            Each element in the result should appear as many times 
            as it shows in both arrays
            */
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}


int main(void){

	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(2);
	nums1.push_back(1);
	nums2.push_back(2);
	nums2.push_back(2);

	
	intersect(nums1,nums2);
	
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	
	
}



/*
Submission Detail:

Runtime: 8 ms, faster than 100.00% of C++ online submissions for Intersection of Two Arrays II.
Memory Usage: 9 MB, less than 83.44% of C++ online submissions for Intersection of Two Arrays II.

*/


/*
Study Notes:

Two Pointers: 'i' & 'j'.

*/ 
