
#include<stdio.h>
#define pf printf
#define sf scanf

struct {
    int data;
    struct node *next;
};node


struct node *front,*end;

void enqueue ();
void dequeue ();
void display ();

void main ()
{
 int ch;
 front=end=NULL;
 do{
    pf("1:enq\n2:deq\n3:dis\n4:exit\nchoice:");
    sf("%d",&ch);
    switch(ch)
    {
        case 1:enqueue();break;
        case 2:dequeue();break;
        case 3:display();break;
        case 4:pf("\nProgram End\n");break;
        default:pf("\nWrong choice\n");break;
    }
 }while(ch!=4);
}

void enqueue ()
{
    struct node *nn;
    nn=(struct node *) malloc(sizeof (struct node));
    pf("\n\nenter data\n\n");
    sf("%d",&nn->data);
    nn->next=NULL;

    if(end==NULL)
    {
        front=nn;
        end=nn;
    }
    else
    {
     end->next=nn;
     end=nn;
    }
    pf("\n\n%d is enqued\n\n",nn->data);
}

void dequeue()
{ struct node *p;
int x;
    if(end==NULL)
   {
       pf("\n\nque is empty\n\n");
       return;
   }

   p=front;
   x=front->data;
   if(front==end)
   {
       front=end=NULL;
   }
   else
   {
   front=front->next;
   }

   free(p);
   pf("\n\n%d is dequed\n\n",x);
}

void display()
{
    struct node *p;
    if(front==NULL)
    {
        pf("Que is empty");
        return;
    }
    p=front;
    while(p!=NULL)
    {
        pf("\n%d\n",p->data);
        p=p->next;
    }
}
