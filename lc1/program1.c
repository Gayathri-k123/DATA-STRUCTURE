//STACK IMPLEMENTATION
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	int data;
	struct node*next;
};
struct node*top=NULL;
void push(int item){
	struct node*newnode=malloc(sizeof(struct node*));
	newnode ->data=item;
	newnode ->next=temp;
	temp=newnode;
}
void pop(){
	if(top==NULL){
	printf("STACK UNDERFLOW\n");
	return;
	}
	else{
	int val;
	struct node*temp=top;
	val=temp->data;
	top=temp->next;
	free(temp);
	printf("%d popped",val);
	}
}
void display(){
	if (top==NULL){
		printf("STACK UNDERFLOW\n");
		return;
	}
	else{
		struct node*temp=top;
		while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
		}
	}
}
void search(int key){
	struct node*temp=top;
	int count=0;
	while(temp!=NULL){
		if(temp->data==key){
			printf("\nElement found\n");
			count=count+1;
			break;
		}
		else{
			temp=temp->next;
		}
	}
	if(count==0){
		printf("\nElement not found\n");
	}
}
void main(){
	int ch;
	while(true){
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.SEARCH\n5.Exit \nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				int item;
				printf("\nEnter the element to be pushed:");
				scanf("%d",&item);
				push(item);
				break;
			case 2:

				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				int key;
				printf("\nEnter the element to be searched:");
				scanf("%d",&key);
				search(key);
				break;
			case 5:
				printf("Exiting....");
				exit(0);
			default:
				printf("Invalid Choice\n");
			}
	}
}
