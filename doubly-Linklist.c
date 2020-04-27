#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0



typedef int bool;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

typedef struct node NODE;
typedef NODE* PNODE;
typedef PNODE* PPNODE;


bool InsertFirst(PPNODE first,int data)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=data;
	newn->next=NULL;
	newn->prev=NULL;

	newn->next=*first;
	*first=newn;
	newn->prev=*first;
	
	return true;
}

bool InsertLast(PPNODE first,int data)
{
	PNODE newn=NULL;
	PNODE temp=*first;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=data;
	newn->next=NULL;
	newn->prev=NULL;

	if(*first==NULL)
	{
		*first=newn;
	}
	else 
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		temp->next=newn;
		newn->prev=temp->next;
	}
	return true;
}

bool InsertAtPos(PPNODE first,int data,int ipos)
{
	PNODE newn=NULL;
	PNODE temp=*first;
	int icnt=0;
	icnt=Count(*first);

	if((ipos<0)||(ipos>icnt+1))
	{
		return false;
	}

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=data;
	newn->next=NULL;
	newn->prev=NULL;

	if(ipos==1)
	{
		InsertFirst(first,data);
	}
	else if(ipos==icnt+1)
		 {
			InsertLast(first,data);
		 }
		 else
		 {
		 	for(int i=1;i<=ipos-2;i++)
		 	{
		 		temp=temp->next;
		 	}
		 	newn->next=temp->next;
		 	temp->next->prev=newn;
		 	temp->next=newn;
		 	newn->prev=temp;

		 	

		 }
	return true;
}

bool DeleteFirst(PPNODE first)
{
	PNODE temp=*first;

	if(*first==NULL)
	{
		return false;
	}
	else if(temp->next==NULL)
	{
		free(temp);
		*first=NULL;
	}
	else
	{
		*first=temp->next;
		free(temp);
		(*first)->prev=*first;
	}                      
	
	return true;
}

bool DeleteLast(PPNODE first)
{
	PNODE temp=*first;

	if(*first==NULL)
	{
		return false;
	}
	else if(temp->next==NULL)
	{
		free(temp);
		*first=NULL;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}

		temp->next=NULL;
		free(temp->next);
	}                      
	
	return true;
}

bool DeleteAtPos(PPNODE first,int ipos)
{
	PNODE newn=NULL;
	PNODE temp=*first;
	

	int icnt=Count(*first);

	if((ipos<=0)||(ipos>icnt))
	{
		return false;
	}
	if(ipos==1)
	{
		return DeleteFirst(first);
	}
	else if(ipos==icnt)
		 {
			return DeleteLast(first);
		 }
		 else
		 {
		 	for(int i=1;i<=ipos-2;i++)
		 	{
		 		temp=temp->next;
		 	}
		 	
		 	temp->next=temp->next->next;
		 	temp->next->prev=NULL;
		 	free(temp->next->prev);
		 	temp->next->prev=temp;

		 }
	return true;
}

void Display(PNODE first)
{
	while(first!=NULL)
	{
		printf("[%d]->",first->data);
		first=first->next;
	}
}


int Count(PNODE first)
{ 
	int i=0;
	while(first!=NULL)
	{
		i++;
		first=first->next;
	}
	return i;
}

int main()
{
	PNODE head=NULL;
	int ino=0;
	int ch=0;
	int icnt=0;
	int ipos=0;

	while(1)
	{	
		printf("\n\n*********************************\n");
		printf("1:-> InsertFirst Node :\n");
		printf("2:-> DeleteFirst Node :\n");
		printf("3:-> Display     Node :\n");
		printf("4:-> Count       Node :\n");
		printf("5:-> InsertLast  Node :\n");
		printf("6:-> DeleteLast  Node :\n");
		printf("7:-> InsertAtPos Node :\n");
		printf("8:-> DeleteAtPos Node :\n");
		printf("\n*******************************\n");

		printf("\nEnter the choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter the Integer data :");
				scanf("%d",&ino);
				InsertFirst(&head,ino);
				break;
			
			case 2:
				DeleteFirst(&head);
				break;
							

			case 3:
				printf("\nDisplay data is :\n");
				Display(head);	
				break;


			case 4:
				icnt=Count(head);
				printf("\nCount is :%d\n",icnt);
				break;


			case 5:
				printf("Enter the Integer data :");
				scanf("%d",&ino);
				InsertLast(&head,ino);
				break;


			case 6:
				DeleteLast(&head);
				break;


			case 7:

				printf("Enter the Position :");
				scanf("%d",&ipos);

				printf("Enter the Integer data :");
				scanf("%d",&ino);
				InsertAtPos(&head,ino,ipos);
				break;



			case 8:

				printf("Enter the Position :");
				scanf("%d",&ipos);

				DeleteAtPos(&head,ipos);
				break;	
			


			default:
				printf("Invalid choice \n");
				break;
					
		}
	}
	return 0;
}

