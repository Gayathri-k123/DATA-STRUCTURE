#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node* next;
};
struct node* head=NULL;

void insertBegining(int value);
void insertEnd(int value);
void insertPosition(int value,int pos);
void deleteBegining();
void deleteEnd();
void deletePosition(int pos);
void display();


void insertBegining(int value){
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
        }
        newNode->data=value;
        newNode->next=head;
        head=newNode;
        printf("%d inserted at the biginning.\n ",value);
        display();
}
void insertEnd(int value){
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
        }
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL)
        {
                 head=newNode;
      }
        else{
                struct node*temp=head;
                while(temp->next!=NULL){
                temp=temp->next;
        }
        temp->next=newNode;
        printf("%d inserted at the biginning .\n",value);
        display();
        }
}
void insertPosition(int value ,int pos){
        if(pos<1){
                printf("Invalid position !\n");
                return;
        }
        if(pos==1){
                insertBegining(value);
                return;
        }
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        if (newNode==NULL){
                printf("Memory allocation failed\n");
                return;
        }
        newNode->data=value;
        struct node* temp=head;
        for(int i=1;i<pos-1&&temp!=NULL;i++){
                temp=temp->next;
        }
        if(temp==NULL){
                printf("Position %d is out of bounds.Node note inserted\n",pos);
                free(newNode);
                return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        printf("%d inserted at position %d .\n",value,pos);
        display();
}
void deleteBegining(){
        if(head==NULL){
                printf("List is empty ! Nothing to delete .\n");
                return;
        }

        struct node* temp=head;
        head=head->next;
        free(temp);
        printf("Node deleted from the begining.\n");
        display();

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
        struct node*prev=NULL;
        while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
        }
        free(temp);
        prev->next=NULL;
        printf("Node deleted from the end.\n");
        display();
}
void  deletePosition(int pos){
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
        struct node* temp=head;
        struct node* prev=NULL;
        for(int i=1;i<pos&&temp!=NULL;i++)
        {
                prev=temp;
                temp=temp->next;
        }
        if(temp==NULL){
                printf("Position %d is out of bounds.Node not deleted.\n",pos);
                return;
                prev->next=temp->next;
                free(temp);
                printf("Node deleted from position %d.\n",pos);
                display();
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


