#include<stdio.h>
#include<stdlib.h>
struct node *insert(struct node*head,int d,int pos);
void display(struct node*head);
struct node *delete(struct node*head,int pos);
struct node
{
    int data;
    struct node *next;
};
void main()
{
        struct node*head;
        int d,pos,ch,choice;
        head=NULL;
        do
        {
                printf("select operation:1-insert,2-delete,3-display,4-exit");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:printf("enter value and position to insert:");
                                scanf("%d%d",&d,&pos);
                                head=insert(head,d,pos);
                                break;
                        case 2:printf("enter position of which node to be deleted");
                                scanf("%d",&pos);
                                head=delete(head,pos);
                                break;
                        case 3:display(head);
                                break;
                        case 4:exit(0);        
                        default:printf("Invalid choice");
                }
                printf("want to continue:1-yes,0-no");
                scanf("%d",&ch);
        }while(ch);
}
struct node *insert(struct node*head,int d,int pos)
{
        struct node *new,*prev;
        new=(struct node*)malloc(sizeof(struct node));
        new->data=d;
        if(pos==1)
        {
                new->next=head;
                head=new;
        }
        else
        {
                int k=1;
                prev=head;
                while(k<pos-1 && prev->next!=NULL)
                {
                        prev=prev->next;
                        k++;
                }
                new->next=prev->next;
                prev->next=new;
        }
        return head;
}
void display(struct node*head)
{
        int c=0;
        struct node*cur;
        cur=head;
        while(cur!=NULL)
        {
                printf("%d\t",cur->data);
                c++;
                cur=cur->next;
        }
        printf("no.of nodes:%d",c);
}
struct node *delete(struct node*head,int pos)
{}