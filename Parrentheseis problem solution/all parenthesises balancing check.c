#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack * ptr)
{
    if (ptr->top < 0)
        {
        return 1;
        }
    else
      {
        return 0;
      }
}
int isFull(struct stack * ptr)
{
    if (ptr->top == ptr->size-1)
       {
        return 1;
       }
    else
       {
        return 0;
       }
}
char push(char element,struct stack * ptr )
{
    if(isFull(ptr))
    {
        printf("STACK OVERFLOW");
        return 0;
    }
    else
    {
       ptr->top++;
       ptr->arr[ptr->top] = element;
    }
    return 1;
}
char pop(struct stack * ptr)
{
   if(isEmpty(ptr))
   {
       printf("STACK underFLOW");
       return 0;
   }
   else
   {
       char val = ptr->arr[ptr->top];
       ptr->top--;
      return val;

   }
}
//MATHCH FUNCTION THAT IS IN PARETHESE BALANCING FUNCTION
int MATCH(char a,char b)
{
    if(a==')' && b == '(')
    {
        return 1;
    }
    if(a=='}' && b == '{')
    {
        return 1;
    }
    if(a=='}' && b == '[')
    {
        return 1;
    }
}
//PAREMTHESE MATCHING CHECKING BALANCED FOR ALLA TYPE OF PARENTHESESE
int parenthesis(char * exp)
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=20;
    sp->top=-1;
    sp->arr = (char *)malloc(sp->size* sizeof(char));
    char element;
    for(int i=0 ; exp[i]!='\0';i++)
    {
       if(exp[i]=='('  ||  exp[i]=='['  || exp[i]=='{' )
       {
           push(exp[i],sp);
       }
       else if(exp[i]==')' ||  exp[i]==']'  || exp[i]=='}')
       {
        element = pop(sp);
         if( !MATCH(exp[i],element))
            {
            printf("Parenthesese is  not balanaced");
            return 0;
            }
        }
    }
    if( isEmpty(sp))
    {
        printf("Parenthesese is  balanaced");
    return 1;
    }
    else
    {

        printf("Parenthesese is not balanaced");
    return 0 ;
    }
}
int main()
{
    parenthesis("3+4(3*3){}");
    return 0;
}
