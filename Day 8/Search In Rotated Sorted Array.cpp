int search(int* arr, int n, int key) {
    // Write your code here.
    // approach 1 - use linear traversal 0(n) time 


    // optimal approach - use Binary search - 0(logn) time 

    int low = 0;
    int high = n-1;


    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==key) return mid;
        // left array is sorted 
        else if(arr[low]<=arr[mid]){
            // key should be in left part only 
           if(key>=arr[low] && arr[mid]>=key)  high = mid-1;
           else low = mid+1;
        }
        else {
            if(arr[mid]<=key && arr[high]>=key) low = mid+1;
            else high = mid-1;
        }
    }

    return -1;
}