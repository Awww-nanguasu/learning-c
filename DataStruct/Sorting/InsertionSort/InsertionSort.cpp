#include"D:\git-workspace\learning-c\DataStruct\SeqList\SeqList.cpp"
void InsertSorting(SeqList* SL){
    SeqListData tmp=0;int j;
    for (int i = 1; i < (SL->size); i++)
    {
        if (SL->a[i]<SL->a[i-1])
        {
            tmp=SL->a[i];SL->a[i]=SL->a[i-1];
            for (j = i-2; j>0&&tmp<SL->a[j]; j--)
            {
                SL->a[j+1]=SL->a[j];
            }
            SL->a[j+1]=tmp;
        }
    }
}