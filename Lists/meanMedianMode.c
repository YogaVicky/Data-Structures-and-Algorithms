#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head = NULL;
void push(int pos , int data){
	struct node *thead = head;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if(pos == 0){
		temp->next = head;
		head = temp;
	}
	else{
		pos = pos - 1;
		while(pos--){
			thead = thead->next;
		}
		temp->next = thead->next;
		thead->next = temp;
	}
}
void mode(int a[],int n){
   int maxValue = 0, maxCount = 0, i, j;
   for(i = 0; i < n; ++i){
      	int count = 0;
    	for(j = 0; j < n; ++j){
        if (a[j] == a[i])
        ++count;
    	}  
	    if(count > maxCount){
	       	maxCount = count;
	        maxValue = a[i];
	    }
    }
   	printf("The mode is %d\n" , maxValue);
}
void displayall(){	
	int a[100] , n , i = 0 , j;
	float sum = 0;
	struct node *thead = head;
	while(thead!=NULL){
		a[i] = thead->data;
		i++;
		thead = thead->next;
	}
	for(j=0;j<i;j++)
		sum += a[j];
	printf("%d\n", i);
	printf("The mean is %f\n" , sum/i);
	printf("The median is %d\n", a[i/2]);
	mode(a , i);

}
int main(){
	int num , n = 1 , pos;
	while(n){
		printf("Enter the element to be inserted\n");
		scanf("%d" , &num);
		printf("Enter the position\n");
		scanf("%d" , &pos);
		push(pos , num);
		printf("Press 1 to continue insertion , 0 to stop\n");
		scanf("%d" , &n);
	}
	displayall();
}