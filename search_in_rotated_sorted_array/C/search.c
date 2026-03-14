#include <stdio.h>

#define NOT_FOUND -1

// int num_transfer(int n, int k, int numsSize){
//     int m = k+1;
//     return (n + ( (n<=k)? m: m+numsSize )) % numsSize;
// }

int search(int* nums, int numsSize, int target) {

    int k = -1;
    int begin = 0;
    int end = numsSize - 1;

    int mid;
    // find k;
    while( begin < end ){

        mid = (begin + end) / 2;
        if(nums[mid] == target){
            return mid;
        }

        if(mid > begin && nums[mid - 1] >= nums[mid]){
            k = mid-1;
            break;
        }
        if(mid < end && nums[mid] >= nums[mid+1]){
            k = mid;
            break;
        }

        begin = (nums[begin] < nums[mid])? mid+1: begin;
        end = (nums[mid] < nums[end])? mid-1: end;
    }

    // binary search;
    if(!numsSize){
        return NOT_FOUND;
    }
    begin = 0;
    end = numsSize - 1;
    
    while(begin <= end){
        mid = (begin + end) / 2;
        int mid_value = nums[ (mid+k+1) % numsSize ];
        if(mid_value < target){
            begin = mid + 1;
        }
        else if(mid_value > target){
            end = mid - 1;
        }
        else{
            return (mid+k+1) % numsSize;
        }
    }

    return NOT_FOUND;
}

int main(int argc, char **argv){
    
    int arr[] = {5, 1, 3};
    unsigned long long arr_len = sizeof(arr)/sizeof(int);
    int n = 0;
    scanf("%d", &n);
    printf("%lld, %d\n", arr_len, search(arr, arr_len, n));
    return 0;
}