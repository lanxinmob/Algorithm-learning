#include<stdio.h>
#define N 10000
void swap(int *a,int *b){
     int temp = *a;
     *a = *b;
     *b = temp;
}
void heapify(int a[],int n,int i){
     int max = i;
     int left = 2*i+1;
     int right = 2*i+2;
     if(a[left]<a[max]&&left<n)max = left;
     if(a[right]<a[max]&&right<n)max = right;
     if(max!=i){
      swap(&a[i],&a[max]);
      heapify(a,n,max);//继续向下，交换后是否大于新左右子叶
     }
}
void heapsort(int a[],int n){
     for(int i = n/2-1; i >=0; i--){//从最后一个非子叶结点开始建堆 
        heapify( a, n, i );
     }
     for(int i = n-1; i >=0; i--){//n-1次把堆顶元素移至尾部
        swap(&a[0],&a[i]);
        heapify( a, i, 1 );
     } 
}
int main(){
  int n,a[N];
  heapsort(a,n);
  for(int i=0;i<n;i++)
      printf("%d",a[i]);
  return 0;
}