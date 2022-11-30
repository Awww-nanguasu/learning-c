#include"D:\git-workspace\learning-c\DataStruct\SeqList\SeqList.cpp"
void SheelSorting(SeqList* SL,int* dt,int t){
    int k=0;
    for (int i = 0; i < t; i++){
        for (int j = dt[i]; j<SL->size; j++){
            if (SL->a[j]<SL->a[j-dt[i]]){
                SeqListData tmp=SL->a[j];
                for (k=j-dt[i]; k>=0&&tmp<SL->a[k]; k=k-dt[i]){
                    SL->a[k+dt[i]]=SL->a[k];
                }
                SL->a[k+dt[i]]=tmp;
            }
        }
        SeqListDisplay(*SL);
    }
}