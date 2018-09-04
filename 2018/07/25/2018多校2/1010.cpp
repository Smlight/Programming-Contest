#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt;
int arr[100010];
void Merge(int* arr,int* tmp,int left,int right,int rightEnd){
    int leftEnd = right - 1;
    int start = left;
    while (left <= leftEnd && right <= rightEnd){
        if (arr[left] > arr[right]){
            tmp[start++] = arr[right++];
            cnt += (leftEnd - left+1);
        }
        else{
            tmp[start++] = arr[left++];
        }
    }
    while (left <= leftEnd){
        tmp[start++] = arr[left++];
    }
    while (right <= rightEnd){
        tmp[start++] = arr[right++];
    }
}
void MergeSort(int* arr,int* tmp,int n,int length)
{
    int i;
    for (i = 0; i <= n - 2 * length; i += 2 * length){
        Merge(arr,tmp,i,i+length,i+2*length-1);
    }
    if (i + length < n){
        Merge(arr,tmp,i,i+length,n-1);
    }
    else{
        for (int j = i; j < n; j++){
            tmp[j] = arr[j];
        }
    }
}
void Merge_Sort(int* arr,int n){
    int lenght = 1;
    int* tmp = (int *)malloc(sizeof(int)*n);
    while (lenght < n){
        MergeSort(arr,tmp,n,lenght);
        lenght *= 2;
        MergeSort(tmp,arr,n,lenght);
        lenght *= 2;
    }
    free(tmp);
}
int main()
{
    int n;
    ll x,y;
    while(scanf("%d%lld%lld",&n,&x,&y)!=EOF){
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        cnt=0;
        Merge_Sort(arr,n);
        printf("%lld\n",min(cnt*x,cnt*y));
    }
    return 0;
}