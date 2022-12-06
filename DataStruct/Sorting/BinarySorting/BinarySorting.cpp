#include"D:\git-workspace\learning-c\DataStruct\SeqList\SeqList.cpp"
//二分查找插入排序
void BinarySort(SeqList SL){
    SeqListData tmp=0;int j=0;
    for (int i = 1; i < SL.size; i++){
        int low=0,high=i-1;
        if (SL.a[i]<SL.a[i-1]){
            tmp=SL.a[i];
            while (low<=high){
                int mid=(low+high)/2;
                if (SL.a[mid]<tmp){
                    low=mid+1;
                }
                else high=mid-1;                     
            }
            for (j = i-1; j>=high+1; j--)
            {
                SL.a[j+1]=SL.a[j];
            }
            SL.a[j+1]=tmp;
        }
    }
}