#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct Queue {
    	int items[MAX];
    	int front, rear;
	};
static int size;
struct Queue *q;
	void init() {
    	printf("\nEnter the size of the queue:");
    	scanf("%d",&size);
    	if(size>MAX||size<=0){
        	printf("\nEntered size is invalid\n");
        	exit(1);
    	}
    	q=(struct Queue*)malloc(sizeof(struct Queue));
    	q->front=-1;
    	q->rear=-1;
	}
	int isfull() {
    	return((q->rear + 1)%size==q->front);
	}
	int isempty() {
    	return (q->front==-1);
	}
	void enqueue(int value) {
    	if(isfull()) {
        	printf("Queue is full\n");
        	return;
    	}
    	if(isempty()){
        	q->front = 0;
    	}
    	q->rear=(q->rear+1)%size;
    	q->items[q->rear]=value;
    	printf("%d Inserted\n",value);
	}
void dequeue() {
    	if(isempty()) {
        	printf("Queue is empty\n");
        	return;
    	}
    	printf("%d Deleted\n",q->items[q->front]);
    	if(q->front==q->rear) {
        	q->front=q->rear = -1;
    	}else{
        	q->front=(q->front+1)%size;
    	}
}
void search(int value) {
    	if (isempty()){
        	printf("Queue is empty\n");
        	return;
		}
       	printf("Enter the value to search: ");
       	scanf("%d",&value);
	int i=q->front;
    	do{
        	if(q->items[i]==value) {
            	printf("Element %d found at position %d.\n", value,(i-q->front+size)%size + 1);
            	return;
        }
        	i=(i + 1)%size;
    	}while(i!=(q->rear+ 1)%size);
    	printf("Element %d not found in the queue.\n",value);
	}
void display() {
    	if(isempty()){
        	printf("Queue is empty\n");
        	return;
    	}
    	printf("Elements are:\n");
    	int i=q->front;
    	do{
        	printf("%d\t", q->items[i]);
        	i=(i+ 1)%size;
    	}while(i!=(q->rear+ 1)%size);
    	printf("\n");
	}
int main(){
    	init();
    	int ch,value;
    	while(1){
        	printf("\n1. Enqueue\n2. Dequeue\n3. Search\n4. Display\n5. Exit\n");
        	printf("Enter your choice: ");
        	scanf("%d",&ch);
        	switch(ch){
            	case 1:
                	printf("Enter the value to enqueue: ");
                	scanf("%d",&value);
                	enqueue(value);
                	break;
            	case 2:
                	dequeue();
                	break;
            	case 3:
                	search(value);
                	break;
            	case 4:
                	display();
                	break;
            	case 5:
                	free(q);
                	printf("Exiting...\n");
                	exit(0);
           	default:
                	printf("Invalid choice\n");
        	}
    	}
}
