/*int searchInsert(int* nums, int numsSize, int target){
    int Left_Mark,Right_Mark,Mid_Mark=0;
    Right_Mark=numsSize-1;
    int q=0;
    if(target>nums[numsSize-1]){
        return numsSize;
    }
    if(target<=nums[0]){
        return 0;
    }
    while(Left_Mark<=Right_Mark){
        Mid_Mark=(Left_Mark+Right_Mark)/2;
        if(nums[Mid_Mark]>target){
            Right_Mark=Mid_Mark-1;
            q=1;
            continue;
        }
        if(nums[Mid_Mark]<target){
            Left_Mark=Mid_Mark+1;
            q=0;
            continue;
        }
        if(nums[Mid_Mark]==target){
            return Mid_Mark;
        }
    }
    return Left_Mark;
}*/