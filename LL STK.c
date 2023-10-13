#include<stdio.h>
#define pf printf
#define sf scanf

struct node
{
    int data;
    struct node *prev;
};

struct node *top;

void push ();
void pop ();
void display ();

void main ()
{
 int ch;
 top=NULL;
 do{
    pf("1:push\n2:pop\n3:dis\n4:exit\nchoice:");
    sf("%d",&ch);
    switch(ch)
    {
        case 1:push();break;
        case 2:pop();break;
        case 3:display();break;
        case 4:pf("\nProgram End\n");break;
        default:pf("\nWrong choice\n");break;
    }
 }while(ch!=4);
}

void push ()
{
    struct node *nn;
    nn=(struct node *)malloc(sizeof(struct node));
    pf("enter data\n");
    sf("%d",&nn->data);
    nn->prev=top;
    top=nn;
    pf("%d is pushed",top->data);
}

void display()
{
    struct node *p;
    if(top==NULL)
    {
      pf("STK IS EMPTY");
      return;
    }
    p=top;
    while(p!=NULL)
    {
        pf("\n%d\n",p->data);
        p=p->prev;
    }

}

void pop ()
{
    struct node *p;
    if(top==NULL)
    {
        pf("STK IS EMPTY");
        return;
    }
    p=top;
    top=top->prev;
    pf("%d is poped",p->data);
    free(p);
}
















