#include<iostream>
using namespace std;
int h[100] = {0};
int hash(int data){
	return data%100;
}
int probe(int data){
	int index = hash(data);
	while(h[(index+i)%100]!=0)
		i++;
	return (index+i)%!100;
}
void insert(int data){
	int index = hash(data);
	if(h[index]!=0)
		index = probe(data);
	h[index] = data;
}
void deletehash(int data){
	
}
int main(){
	int ch = 1 , a , i;
    while(ch){
        printf("Enter your choice\n");
        printf("1.Insert\n2.Delete\n3.Search\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the number\n");
            scanf("%d",&a);
            inserthash(a);
            for(i=0;i<10;i++)
               printlist(h[i]); 
            break;
        case 2:
            printf("Enter the number\n");
            scanf("%d",&a);
            deletehash(a);
            for(i=0;i<10;i++)
               printlist(h[i]);
            break;
        case 3:
            printf("Enter the number\n");
            scanf("%d",&a);
            searchhash(a);
            break;
        }
    }
    return 0;
	return 0;
}