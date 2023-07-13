# binary search 

def singleNonDuplicate(arr):
    # Write your code here
    l=0
    h = len(arr)-1

    while l<=h:
        mid = (l+h)//2

        if mid%2==0:
            if mid+1>=len(arr):
                return arr[mid]
            
            if arr[mid]==arr[mid+1]:
                l= mid+1
            else:
                h = mid-1
        else:
            if arr[mid]==arr[mid-1]:
                l = mid+1
            else:
                h = mid-1
    return arr[l] 