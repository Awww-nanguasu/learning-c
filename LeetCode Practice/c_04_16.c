/*int removeDuplicates(int* nums, int numsSize){
    int i,j,sum=nums[0]-1,count;
    int sum1[numsSize];
    for ( j=1,i = 0,count=0; i < numsSize; i++)
    {
        sum+=(j*nums[i]);
        sum1[i]=sum;
        j*=-1;
        if(i==1&&nums[0]==nums[1])
        {
            continue;
        }
        if (i>=2 && sum1[i]==sum1[i-2])
        {
            continue;
        }
        nums[count]=nums[i];
        count++;
    }
    return count;
}*/