// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int left=m-1;
//         int right=0;
//         while(left>=0 && right<m)
//         {
//             if(nums1[left]>nums2[right])
//             {
//                 swap(nums1[left],nums2[right]);
//                 left--;
//                 right++;
//             }
//             else
//             {
//                 break;
//             }

//         }

//         sort(nums1 ,nums1 + m);
//         sort(nums2,nums2 + n);
//     }

// };

// for (int j = 0, i = m; j<n; j++){
//     nums1[i] = nums2[j];
//     i++;
// }
// sort(nums1.begin(),nums1.end());

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

// class Node{
//     public :
//     int data;
//     int i;
//     int j;
//     Node(int data,int row,int col)
//     {
//         this->data=data;
//         i=row;
//         j=col;
//     }
// }

// class compare{
//     public:
//     bool operator()(Node* a,Node* b){
//         return a->data>b->data;
//     }
// }

//  class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
//     }
// };















