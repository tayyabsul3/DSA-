/*#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node * previous;
    int data;
    struct Node * next;

};
void doubllyLLtraversal(struct Node* head)
{
    struct Node* ptr=head;
while(ptr!=NULL)
{
    printf("\nElements in standard : %d " , ptr->data);
    ptr=ptr->next;
}
ptr=ptr->previous;
while(ptr!=NULL)
{
    printf("\nElements in reverse : %d " , ptr->data);
    ptr=ptr->previous;
}

}
int main()
{
    struct Node* head = (struct Node * )malloc(sizeof(struct Node));
     struct Node* second = (struct Node * )malloc(sizeof(struct Node));
      struct Node* third = (struct Node * )malloc(sizeof(struct Node));
       struct Node* fourth = (struct Node * )malloc(sizeof(struct Node));

       head->data = 1;
       head->previous=NULL;
       head->next = second;

       second->data=2;
       second->previous=head;
       second->next=third;

       third->data=3;
       third->previous=second;
       third->next=fourth;

       fourth->data=4;
       fourth->previous=third;
       fourth->next = NULL;

       doubllyLLtraversal(head);
    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* previous;
    int data;
    struct Node* next;
};

void doubllyLLtraversalforward(struct Node* head)
{
    struct Node* ptr = head;

    // Traverse forward to find the last node
    while (ptr != NULL)
    {
        printf("\nElements : %d ", ptr->data);
        ptr = ptr->next;
    }
}
void doubllyLLtraversalreverse(struct Node* head)
{
    struct Node* ptr = head;
    // Traverse backward and print in reverse order
     while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("\nElements in reverse: %d ", ptr->data);
        ptr = ptr->previous;
    }
}
int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->previous = NULL;
    head->next = second;

    second->data = 2;
    second->previous = head;
    second->next = third;

    third->data = 3;
    third->previous = second;
    third->next = fourth;

    fourth->data = 4;
    fourth->previous = third;
    fourth->next = NULL;

    doubllyLLtraversalforward(head);
    doubllyLLtraversalreverse(head);
    return 0;
}

