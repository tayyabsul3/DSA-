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
        printf("ELEMENT : %d", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=12;
    second->next=third;

    third->data=14;
    third->next=NULL;

    showdata(head);
    return 0;
}
