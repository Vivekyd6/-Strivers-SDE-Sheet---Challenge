double median(vector<int>& nums1, vector<int>& nums2) {
	// Write your code here
	// bruteforce approach - .
	// vector<int> merged;
    // int i = 0, j = 0;

    // while (i < nums1.size() && j < nums2.size()) {
    //     if (nums1[i] < nums2[j]) {
    //         merged.push_back(nums1[i]);
    //         i++;
    //     } else {
    //         merged.push_back(nums2[j]);
    //         j++;
    //     }
    // }

    // while (i < nums1.size()) {
    //     merged.push_back(nums1[i]);
    //     i++;
    // }

    // while (j < nums2.size()) {
    //     merged.push_back(nums2[j]);
    //     j++;
    // }

    // int n = merged.size();
    // int mid = n / 2;

    // if (n % 2 == 1) {
    //     // For odd-sized arrays, return the middle element
    //     return merged[mid];
    // } else {
    //     // For even-sized arrays, return the average of the two middle elements
    //     return (merged[mid - 1] + merged[mid]) / 2.0;
    // }
	if(nums2.size()<nums1.size())
          return median(nums2,nums1);
    
      int n1=nums1.size();
      int n2=nums2.size();
      int low=0;
      int high=n1;
      
      while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=(n1+n2+1)/2-cut1;
        
        int left1=cut1==0 ? INT_MIN :nums1[cut1-1];
        int left2=cut2==0?INT_MIN:nums2[cut2-1];
        
        int right1=cut1==n1?INT_MAX:nums1[cut1];
        int right2=cut2==n2?INT_MAX:nums2[cut2];
        
        if(left1<=right2 && left2<=right1)
        {
          if((n1+n2)%2==0)
            return (max(left1,left2)+min(right1,right2))/2.0;
          else
            return max(left1,left2);
        }
        else if(left1>right2)
          high=cut1-1;
        else
          low=cut1+1;
        
      }
      return 0.0;
}