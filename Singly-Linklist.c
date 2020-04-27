#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0



typedef int bool;

struct node
{
	int data;
	struct node* next;
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

	newn->next=*first;
	*first=newn;

	return true;
}

bool InsertAtPos(PPNODE first,int data,int ipos)
{	
	int icnt=Count(*first);

	if((ipos<0)||(ipos>icnt+1))
	{
		return false;
	}
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
	  	PNODE newn=(PNODE)malloc(sizeof(NODE));
	  	PNODE temp=*first;

	  	newn->next=NULL;
	  	newn->data=data;
	  	
	  	for(int i=1;i<=ipos-2;i++)
	  	{
	  	temp=temp->next;	
	  	}
	  	newn->next=temp->next;
	  	temp->next=newn;
	  }
	return true;
}

bool InsertLast(PPNODE first,int data)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=data;
	newn->next=NULL;

	PNODE temp=*first;

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
	}

	return true;
}



bool DeleteFirst(PPNODE first)
{	
	PNODE temp=*first;

		if(temp!=NULL)
		{
			*first=(*first)->next;
			free(temp);
		}
	return true;
}

bool DeleteAtPos(PPNODE first,int ipos)
{
	PNODE temp=*first;
	PNODE temp2=NULL;

	int icnt=Count(*first);
	printf("%d\n",icnt);

	if((ipos<1)||(ipos>icnt))
	{
		return false;
	}
	if(ipos==1)
	{
		DeleteFirst(first);
		
	}
	else if(ipos==icnt)
	{
		DeleteLast(first);
		
	}
	else
	{
		for(int i=1;i<=ipos-2;i++)
		{
			temp=temp->next;
		}

		temp2=temp->next;

		temp->next=temp2->next;
		free(temp2);
	
		
	}
	return true;
}

bool DeleteLast(PPNODE first)
{
		
	PNODE temp=*first;
	if(*first==NULL)
	{
		return true;
	}
	else if(temp->next==NULL)
	{
		free(temp);
		*first=NULL;
		return true;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}

		free(temp->next);
		temp->next=NULL;
		return true;

	}
}


void Display(PNODE first)
{
	while(first!=NULL)
	{
		printf("Data is :%d\n",first->data);
		first=first->next;
	}
}


int Count(PNODE first)
{
	int icnt=0;
	while(first!=NULL)
	{
		icnt++;
		first=first->next;
	}
	return icnt;
}

int main()
{
	PNODE head=NULL;
	//bool bret=InsertFirst(&head,11);
	//Display(head);
	int icnt=0;
	int ch=0;
	int ino=0;
	int pos=0;
	int ipos2=0;

	while(1)
	{	
		printf("*********************************\n");
		printf("1:InsertFirst Node :\n");
		printf("2:InsertAtPosition Node :\n");
		printf("3:InsertLast Node :\n");
		printf("4:Display the Nodes :\n");
		printf("5:Count the Nodes :\n");
		printf("6:DeleteFirst Node :\n");
		printf("7:DeleteAtPos Node :\n");
		printf("8:DeleteLast Node :\n");
		printf("9:Exit :\n");
		printf("**********************************\n");

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
				printf("Enter position :");
				scanf("%d",&pos);
				printf("Enter the Integer data :");
				scanf("%d",&ino);
				InsertAtPos(&head,ino,pos);
				break;

				
			case 3:
				printf("Enter the Integer data :");
				scanf("%d",&ino);
				InsertLast(&head,ino);
				break;
		

			case 4:
				printf("\nDisplay data is :\n");
				Display(head);	
				break;


			case 5:
				icnt=Count(head);
				printf("Number of Node is :%d\n",icnt);	
				break;


			case 6:
				DeleteFirst(&head);
				break;

			case 7:
				printf("\nEnter the position :");
				scanf("%d",&ipos2);
				DeleteAtPos(&head,ipos2);
				break;

			case 8:
				DeleteLast(&head);
				break;
	

			case 9:
				return 1;
				break;
				

			default:
				printf("Invalid choice \n");
				break;
					
		}
	}
	return 0;
}