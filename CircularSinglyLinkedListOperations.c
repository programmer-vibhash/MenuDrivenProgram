#include <stdio.h>
#include <stdlib.h>

struct node{
    int n;
    struct node *next;
};

void AddAtFront(struct node** head){
    struct node *new, *temp;
    new=(struct node *)malloc(sizeof(struct node));
    printf("enter the value ");
    scanf("%d",&new->n);
    if(*head==NULL){
        new->next=new;
        *head=new;
        return;
    }
    temp=*head;
    while (temp->next!=*head){
        temp=temp->next;
    }
    new->next=*head;
    temp->next=new;
    *head=new;
}

void AddAtEnd(struct node** head){
    struct node *new, *temp;
    new=(struct node *)malloc(sizeof(struct node));
    printf("enter the value ");
    scanf("%d",&new->n);
    if(*head==NULL){
        new->next=new;
        *head=new;
        return;
    }
    temp=*head;
    while (temp->next!=*head){
        temp=temp->next;
    }
    temp->next=new;
    new->next=*head;
}

void AddAtAnyPos(struct node** head){
    struct node *new, *temp, *temp2=NULL, *t;
    int pos,i=0;
    new=(struct node *)malloc(sizeof(struct node));
    printf("enter the value ");
    scanf("%d",&new->n);
    printf("enter the position ");
    scanf("%d",&pos);
    if(*head==NULL){
        new->next=new;
        *head=new;
        return;
    }
    if(pos==1){
        temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        new->next=*head;
        temp->next=new;
        *head=new;
    }
    temp=*head;
    while (i<pos){
        temp2=temp;
        temp=temp->next;
        i++;
    }
    temp2->next=new;
    new->next=temp;
}

void DelAtFront(struct node **head){
    if(*head==NULL){
        printf("no elements\n");
        return;
    }
    if((*head)->next==*head){
        free(*head);
        *head=NULL;
        return;
    }
    struct node *temp=*head,*t;
    while(temp->next!=*head){
        temp=temp->next;
    }
    t=(*head)->next;
    temp->next=t;
    free(*head);
    *head=t;
}

void DelAtEnd(struct node **head){
    if(*head==NULL){
        printf("no elements\n");
        return;
    }
    if((*head)->next==*head){
        free(*head);
        *head=NULL;
        return;
    }
    struct node *temp=*head,*t;
    while(temp->next!=*head){
        t=temp;
        temp=temp->next;
    }
    t->next=*head;
    free(temp);
}

void DelAtAnyPos(struct node **head){
    if(*head==NULL){
        printf("no elements\n");
        return;
    }
    int pos,i=0;
    printf("enter the position ");
    scanf("%d",&pos);
    if((*head)->next==*head){
        free(*head);
        *head=NULL;
        return;
    }
    struct node *temp,*t;
    if(pos==1){
        temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        t=(*head)->next;
        temp->next=t;
        free(*head);
        *head=t;
        return; 
    }
    temp=*head;
    while(i<pos){
        t=temp;
        temp=temp->next;
        i++;
    }
    t->next=temp->next;
    free(temp);
}

void DelByVal(struct node **head){
    if(*head==NULL){
        printf("no elements\n");
        return;
    }
    int val,i=0;
    printf("enter the value ");
    scanf("%d",&val);
    struct node *temp=*head,*curr=NULL,*prev=NULL;
    while(temp->next!=*head && temp->n!=val){
        prev=temp;
        curr=temp;
        temp=temp->next;
    }
    if(temp->n==val){
        curr=temp;
    }
    if(curr==NULL){
        printf("element not found\n");
        return;
    }
    if(curr->next==curr){
        free(*head);
        *head=NULL;
        return;
    }
    if(curr==*head){
        temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=(*head)->next;
        *head=(*head)->next;
        free(curr);
        return;
    }
    if(curr->next==*head){
        temp=*head;
        while(temp->next!=curr){
            temp=temp->next;
        }
        temp->next=*head;
        free(curr);
        return;
    }
    prev->next=curr->next;
    free(curr);
}

void Traverse(struct node **head){
    if(*head==NULL){
        printf("no elements\n");
        return;
    }
    struct node *temp=*head;
    while(temp->next!=*head){
        printf("%d -> ",temp->n);
        temp=temp->next;
    }
    printf("%d ",temp->n);
}
int main(){
    int x;
    struct node *head=NULL;
    printf("menu driven program for circular singly linked list\n");
    printf("1. insert at beginning\n2. insert at last\n3. insert at any position\n");
    printf("4. delete at beginning\n5. delete at last\n6. delete at any position\n7. delete by value\n");
    printf("8.traverse\n9.exit\n");
    while(1){
        printf("enter your choice ");
        scanf("%d",&x);
        if(x==9) break;
        switch(x){
            case 1:
            AddAtFront(&head);
            break;
            case 2:
            AddAtEnd(&head);
            break;
            case 3:
            AddAtAnyPos(&head);
            break;
            case 4:
            DelAtFront(&head);
            break;
            case 5:
            DelAtEnd(&head);
            break;
            case 6:
            DelAtAnyPos(&head);
            break;
            case 7:
            DelAtAnyPos(&head);
            break;
            case 8:
            Traverse(&head);
            break;
            default:
            printf("invalid choice ");
            break;
        }
    }
    return 0;
}