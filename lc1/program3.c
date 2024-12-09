#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
	struct node*prev;
};
struct node*head=NULL;
void insertBegining(int value);
void insertEnd(int value);
void insertPosition(int value,int pos);
void deleteBegining();
void deleteEnd();
void deletePosition(int pos);
void display();

int main(){
        int choice,subChoice,value,pos;
        do{
                printf("\nChoose an operation\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
                scanf("%d",&choice);

                switch(choice){
                        case 1:
                                printf("\nChoose insertion method \n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n");
                                scanf("%d",&subChoice);
                                switch(subChoice){
                                        case 1:
                                                printf("\nEnter the value to be inserted at the begining :");
                                                scanf("%d",&value);
                                                insertBegining(value);
                                                break;
                                        case 2:
                                                printf("\nEnter the value to be inserted at the end :");
                                                scanf("%d",&value);
                                                insertEnd(value);
                                                break;
                                        case 3:
                                                printf("\nEnter the position and value to be inserted :");
                                                scanf("%d%d",&pos,&value);
                                                insertPosition(value,pos);
                                                break;

                                        default :
                                                printf("\nInvalid insertion choice !\n");
                                }
                                break;
                    case 2:
                                printf("\nChoose deletion method \n1.Delete from the begining\n2.Delete from the end\n3.Delete from Position\n");
                                scanf("%d",&subChoice);
                                switch(subChoice){
                                        case 1:
                                                deleteBegining();
                                                break;
                                        case 2:
                                                deleteEnd();
                                                break;
                                        case 3:
                                                printf("\nEnter the position for deletion.\n");
                                                scanf("%d",&pos);
                                                deletePosition(pos);
                                                break;
                                        default:
                                                printf("\nInvalid deletion method !\n");
                                        break;
                                }
                                break;
                        case 3:
                                display();
                                break;
                        case 4:
                                printf("\nExiting....\n");
                                break;
                        default :
                                printf("\nInvalid choice! Please insert again\n");
                                break;
                }
        }
        while(choice!=4);
        return 0;
}

void insertBegining(int value){

	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(newnode==NULL)
	{
	printf("memory allocation failed");
	return;
	}
	if(head==NULL)
	{
	newnode=head;
	}

	else
{
	newnode->prev=NULL;
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}
}

void insertEnd(int value){
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
	printf("memory allocation failed");
	return;
	}
	newnode->data=value;
	newnode->next=NULL;
	newnode->prev=NULL;
	struct node*temp=head;
if(head==NULL)
{
	newnode=head;

}
	while(temp->next!=NULL)
{
	temp=temp->next;
}
	newnode->next=NULL;
	newnode->prev=temp;
	temp->next=newnode;
}

void insertPosition(int pos,int value){
	  struct node*newnode=(struct node*)malloc(sizeof(struct node));
	if(pos<1){
	printf("invalid position");
	return;
	}
	if(pos==1){
	insertBegining(value);
	return;
	}
	if(newnode==NULL){
	printf("Memory allocation failed \n");
	return;
	}
	struct node*temp=head;
	newnode->data=value;
}

void deleteBegining(){
		if(head==NULL){
                printf("List is empty ! Nothing to delete .\n");
                return;
		}
		struct node*temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
}

void deleteEnd(){
 if(head==NULL){
                printf("List is empty ! Nothing to delete .\n");
                return;
        }
        if(head->next==NULL){
                free(head);
                head=NULL;
                printf("Node deleted from the end .\n");
                display();
                return;
		}
		struct node*temp=head;
		while(temp->next!=NULL)
		{
		temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
}
void deletePosition(int pos){
 if(head==NULL){
                printf("List is empty ! Nothing to delete .\n");
                return;
        }
        if(pos<1){
                printf("Invalid position !\n");
                return;
        }
        if(pos==1){
                deleteBegining();
                return;
        }

	struct node*temp=head;
	  for (int i = 1; i < pos && temp != NULL; i++) {
                temp = temp->next;
        }

        if (temp == NULL) {
                printf("Invalid position.\n");
        } else {
                if (temp->next != NULL) {
                 temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
                temp->prev->next = temp->next;
        }
        printf("Deleted %d from position %d.\n", temp->data, pos);
        free(temp);
        }
}





void display(){
        if(head==NULL){
                printf("List is empty!\n");
                return;
        }
        struct node*temp=head;
        printf("\nLinked List elements :");
        while (temp->next!=NULL){
                printf("%d->",temp->data);
                temp=temp->next;
        }
        printf("%d\n",temp->data);
}

