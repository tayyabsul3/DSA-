#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node * next;
};
void cicularlltraversal(struct Node* head)
{
    struct Node* ptr=head;
    do
    {
        printf("Elememt : %d" ,ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
int main()
{
    struct Node* head = (struct Node * )malloc(sizeof(struct Node));
     struct Node* second = (struct Node * )malloc(sizeof(struct Node));
      struct Node* third = (struct Node * )malloc(sizeof(struct Node));
       struct Node* fourth = (struct Node * )malloc(sizeof(struct Node));

       head->data = 1;
       head->next = second;

       second->data=2;
       second->next=third;

       third->data=3;
       third->next=fourth;

       fourth->data=4;
       fourth->next = head;

       cicularlltraversal(head);
    return 0;
}
