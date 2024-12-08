#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** ans = NULL;
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            long long newTarget = (long long)target - nums[i] - nums[j];
            int low = j + 1, high = numsSize - 1;
            while (low < high) {
                long long sum = (long long)nums[low] + nums[high];
                if (sum < newTarget) {
                    low++;
                } else if (sum > newTarget) {
                    high--;
                } else {
                    (*returnSize)++;
                    ans = (int**)realloc(ans, (*returnSize) * sizeof(int*));
                    ans[*returnSize - 1] = (int*)malloc(4 * sizeof(int));
                    ans[*returnSize - 1][0] = nums[i];
                    ans[*returnSize - 1][1] = nums[j];
                    ans[*returnSize - 1][2] = nums[low];
                    ans[*returnSize - 1][3] = nums[high];
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                }
            }
        }
    }
    
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 4;
    }
    
    return ans;
}

int main() {
    int nums1[] = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    int returnSize1 = 0;
    int* returnColumnSizes1 = NULL;
    int** result1 = fourSum(nums1, 6, target1, &returnSize1, &returnColumnSizes1);
    
    printf("Output for Example 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("[%d, %d, %d, %d]\n", result1[i][0], result1[i][1], result1[i][2], result1[i][3]);
        free(result1[i]);
    }
    free(result1);
    free(returnColumnSizes1);
    
    int nums2[] = {2, 2, 2, 2, 2};
    int target2 = 8;
    int returnSize2 = 0;
    int* returnColumnSizes2 = NULL;
    int** result2 = fourSum(nums2, 5, target2, &returnSize2, &returnColumnSizes2);
    
    printf("Output for Example 2:\n");
    for (int i = 0; i < returnSize2; i++) {
        printf("[%d, %d, %d, %d]\n", result2[i][0], result2[i][1], result2[i][2], result2[i][3]);
        free(result2[i]);
    }
    free(result2);
    free(returnColumnSizes2);
    
    return 0;
}