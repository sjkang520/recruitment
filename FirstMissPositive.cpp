 #include <iostream>
using namespace std;
 int firstMissingPositive(int A[], int n) 
 {
        for(int i = 0;i < n;)
        {
            if(A[i]>0 && A[i]<=n && A[i] != A[A[i]-1]){ //在范围内，且不在正确的位置上要将A[i]调整到正确的位置
                int index = A[i];   //不能简单的交换，否则A[A[i]-1]就不是原来的位置了！
                A[i] = A[index-1];
                A[index-1] = index;
        }
        else   //但是被换到A[i]的新值需要重新检测，所以当不满足条件的时候才增加i的值
            ++i;
        }
        for(int i = 0;i < n;i++)
            if(A[i]!=i+1)
                return i+1;
        return n+1;
}
int main()
{
    int a[]={-5,1,4,3,2};
    int res=firstMissingPositive(a,5);
    cout<<res<<endl;
}
