#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void showdata(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("\nELEMENT : %d", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertionhead(struct Node* head , int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next = head;
    return ptr;

};

struct Node * insertionbetween(struct Node *head , int data , int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node* p= head;
    int i= 0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
};
struct Node * deletionhead(struct Node* head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr=head->next;
   free(head);


    return ptr;

};
struct Node * deletionindex(struct Node* head,int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    int i=0;
    while(i!=index-1)
    {
        ptr=ptr->next;
        i++;
    }
    struct Node* q = ptr->next;
    ptr->next=q->next;

    free(q);



    return head;

};
struct Node * deletiongiven(struct Node* head,struct Node* previous)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    int i=0;
    while(ptr->next!=previous)
    {
        ptr=ptr->next;

    }
    ptr->next=previous->next;
    free(previous);
    return head;

};
struct Node * deletionend(struct Node* head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    struct Node* p = head->next;
    int i=0;
    while(p->next != NULL)
    {
        ptr=ptr->next;
        p=p->next;
        i++;
    }
    ptr->next=NULL;
    free(p);
    return head;

};




int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
     struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->next=second;

    second->data=12;
    second->next=third;

    third->data=14;
    third->next=fourth;

    fourth->data=16;
    fourth->next=NULL;

    showdata(head);

  //INSERTION OF NODE:-

    // head = insertionhead(head , 50);
    //head = insertionbetween(head,40,1);
    //head = insertionend(head,40);
   // head = insertionnode(head,second,40);

   //DELETION OF NODE:-

    //head = deletionhead(head);
   // head = deletionindex(head,2);
   // head = deletiongiven(head,second);
   // head = deletionend(head);
    showdata(head);

    return 0;
}
