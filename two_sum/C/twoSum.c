/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct HashNode{
    char flag;
    int index;
    int data;
}HashNode_t;

void insert(HashNode_t *dict, int index, int data, int tableSize){
    int key = data%tableSize;
    if(key < 0){
        key = -1*key;
    }

    while(dict[key].flag != 0){
        ++key;
        if(key >= tableSize){
            key = 0;
        }
    }
    dict[key].flag = 1;
    dict[key].index = index;
    dict[key].data = data;
}

HashNode_t find(HashNode_t *dict, int data, int tableSize){

    int key = data%tableSize;
    if(key < 0){
        key = -1*key;
    }

    HashNode_t returnData = dict[key];
    int count = 0;

    while(returnData.data != data && returnData.flag != 0){
        ++key;
        if(key >= tableSize){
            key = 0;
        }
        returnData = dict[key];

        ++count;
        if(count > tableSize){
            returnData.flag = 0;
            return returnData;
        }
    }
    return returnData;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *returnArray = (int *)malloc(sizeof(int)*2);
    int tableSize = numsSize*2;
    HashNode_t *dict = malloc(sizeof(HashNode_t)*tableSize);
    HashNode_t result;
    
    for(int i = 0; i< tableSize; ++i){
        dict[i].flag = 0;
    }

    for(int i = 0; i< numsSize; ++i){
        result = find(dict, target - nums[i], tableSize);
        if(result.flag == 0){
            insert(dict, i, nums[i], tableSize);
        }
        else{
            returnArray[0] = i;
            returnArray[1] = result.index;
            free(dict);
            return returnArray;
        }
    }
    
    *returnSize = 0;
    free(returnArray);
    free(dict);
    return NULL;
}
