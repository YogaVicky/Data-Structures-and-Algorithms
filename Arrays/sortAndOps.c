#include<stdio.h>
#include<stdlib.h>
void sort(int a[100] , int size){
    int i=0,j=0,n;
    int buff;
    n=size;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                buff=a[j];
                a[j]=a[j+1];
                a[j+1]=buff;
            }
        }
    }
}
int ops(int a[100] , int n){
    int i , j = 0 , k;
    sort(a , n);
    for(i=0;i<n;i++){
        if(i%2 == 0){
            a[j] = a[i+1] - a[i];
            j++;
        }
    }
    for(k=0;k<j;k++)
        printf("%d " , a[k]);
    printf("\n");
    return j;
}
int main()
{
    int n , a[100] , i , b[100] , j = 0 , k , r;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    r = n;
    while(r!=1){
        r = ops(a , r);
    }
    return 0;
}

