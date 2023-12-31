#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
//LINKED LIST PRINT FUNCTION
void traversal(struct Node * ptr)
{

    while(ptr!=NULL)
    {
        printf("\nELEMENT : %d", ptr->data);
        ptr=ptr->next;
    }
}

//LINKED LIST USING STACK PUSH FUNCTION
struct Node* push(struct Node * top,int x)
{
    if(isFull())
    {
        printf("STACK OVERFLOW");
    }
    else{
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data=x;
    n->next=top;
    top = n;
    return top;
        }
}
//LINKED LIST USING STACK pop FUNCTION
int pop(struct Node ** top)
{
    if(isEmpty(*top))
    {
        printf("STACK UNDERFLOW");
    }
    else{
    int x=(*top)->data;
   struct Node * n =* top;
    *top=(*top)->next;
    free(n);
    return x;
}}
//CHECKING FOR EMPTY STACK
int isEmpty(struct Node * top)
{
    if (top == NULL)
        {
        return 1;
        }
        return 0;
}
//CHECKING FOR full STACK
int isFull()
{
    struct Node * p = (struct Node*)malloc(sizeof(struct Node));
    if (p==NULL)
       {
        return 1;
       }
        return 0;
}


//PEEK OPERATION
int peek(int pos,struct Node* top)
{
struct Node *ptr = top;
 for(int i=0;(i<pos-1 && ptr!=NULL);i++)
 {
     ptr=ptr->next;
 }
 if(ptr!=NULL)
 {
     return ptr->data;
 }
 else
 {
     return -1;
 }
}
//STCAK TOP AND BOTTOMHOME WORK
int main()
{
  struct Node * top =NULL;
   top = push(top,1);
    top = push(top,2);
     top = push(top,3);
      top = push(top,4);
  //  traversal(top);
  //  printf("%d ELEMENT POPPED\n" , pop(&top) );
  //  traversal(top);
     printf("%d peeked\n" , peek(9,top));

}
