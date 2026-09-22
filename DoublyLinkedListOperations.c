#include <stdio.h>
#include <stdlib.h>

struct node{
    int n;
    struct node *next,*prev;
};

void insert_beg(struct node **head){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the value ");
    scanf("%d",&newnode->n);
    newnode->next=*head;
    newnode->prev=NULL;
    *head=newnode;
    printf("done\n");
}

void insert_end(struct node **head){
    struct node *temp,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the value ");
    scanf("%d",&newnode->n);
    newnode->next=NULL;
    if(*head==NULL){
        (*head)=newnode;
        newnode->prev=NULL;
        printf("done\n");
        return;
    }
    else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        printf("done\n");
    }
}

void insert_any_position(struct node **head){
    struct node *temp,*temp2,*newnode;
    int pos;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the value ");
    scanf("%d",&newnode->n);
    printf("enter the position ");
    scanf("%d",&pos);
    int i=1;
    for(temp=*head;i<pos-1;temp=temp->next,temp2=temp,i++);
    newnode->next=temp;
    newnode->prev=temp2;
    temp2->next=newnode;
    temp->prev=newnode;
    printf("done\n");
}
void delete_beg(struct node **head){
    if(*head==NULL){
        printf("no nodes present\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        printf("done\n");
    }
    else{
        struct node *temp=*head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(temp);
        printf("done\n");
    }
}
void delete_end(struct node **head) {
    if(*head==NULL){
        printf("no nodes present\n");
        return;
    }
    struct node *temp=*head,*temp2;
    for(temp=*head;temp!=NULL;temp=temp->next);
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    printf("done\n");
}
void delete_any_position(struct node **head) {
    struct node *temp=*head;
    int pos,i=1;
    printf("enter the postion ");
    scanf("%d",&pos);
    while(i<pos-1){
        temp=temp->next;
    }
    if(temp==NULL) printf("invalid position\n");
    if(temp->next==NULL) temp->prev->next=NULL;
    if(temp==*head) *head=temp->next;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}
void delete_by_value(struct node **head){
    int val;
    printf("enter thhe value");
    scanf("%d",&val);
    if(*head==NULL){
        printf("empty\n");
        return;
    }
    struct node *curr=*head;
    while(curr!=NULL && curr->n!=val){
        curr=curr->next;
    }
    if(curr==NULL){
        printf("not found\n");
        return;
    }
    if(curr==*head){
        *head=curr->next;
    }
    else{
        curr->prev->next=curr->next;
    }
    if(curr->next!=NULL){
        curr->next->prev=curr->prev;
    }
    free(curr);
    printf("done\n");
}
void traverse(struct node **head){
    struct node *temp=*head;
    while(temp!=NULL){
        printf("%d <-> ",temp->n);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int x;
    struct node *head=NULL;
    printf("menu driven program for doubly linked list\n");
    printf("1. insert at beginning\n2. insert at last\n3. insert at any position\n");
    printf("4. delete at beginning\n5. delete at last\n6. delete at any position\n7. delete by value\n");
    printf("8.traverse\n9.exit\n");
    while(1){
        printf("enter your choice ");
        scanf("%d",&x);
        if(x==9) break;
        switch(x){
            case 1:
            insert_beg(&head);
            break;
            case 2:
            insert_end(&head);
            break;
            case 3:
            insert_any_position(&head);
            break;
            case 4:
            delete_beg(&head);
            break;
            case 5:
            delete_end(&head);
            break;
            case 6:
            delete_any_position(&head);
            break;
            case 7:
            delete_by_value(&head);
            break;
            case 8:
            traverse(&head);
            break;
            default:
            printf("invalid choice ");
            break;
        }
    }
    return 0;
}