#include"ListusingLLadt7.h"
typedef struct student
{
	char usn[11];
	char name[25];
	int sem;
	int roll_no;
	char branch[6];
}stud;

void printlist(void *dp)
{
	stud *t;
	t=(stud*)dp;
	printf("\nStudent Name:%s\n",t->name);
	printf("Student USN:%s\n",t->usn);
	printf("Branch:%s\n",t->branch);
	printf("SEM=%d\n",t->sem);
	printf("Roll_No=%d\n",t->roll_no);
}
bool compare(void *p,void *q)
{
	stud *t,*d;
	t=(stud*)p;
	d=(stud*)q;
	if(!strcmp(t->usn,d->usn))
		return true;
	return false;
}

int main()
{
	int ch;
    stud *c;
    LIST *p;
    NODE *pred;
    char pkey[11];
    bool res;
	p=createlist();
	if(!p)
	{
		printf("List creation failed ");
		return 1;
	}
	printf("List Created Sucessfully");
	while(1)
	{
		printf("\n1 for insertion\n2 for deletion\n3 for retrieval\n4 for search\n5 for display\n6 for listfull\n7 for list empty\n8 for list count\n9 for destroy or exit\n");
		printf("Enter  choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			label1:
			 case 1:printf("1 for beginning\n2 for middle\n3 for end\n");
				   printf("Enter  choice:\n");
				   scanf("%d",&ch);
				   switch(ch)
				   {
					   case 1:pred=NULL;
							  break;
					   case 2:printf("Enter student USN after new node to be inserted\n");
							  scanf("%s",pkey);
							  pred=searchlist(p,pkey,compare);
							  if(!pred)
							  {
								  printf("Search is failed for key\n");
							  }
							  break;
						case 3:pred=p->head;
								while(pred->next)
								{
									pred=pred->next;
								}
								break;
						default:printf("Invalid choice\n");
								goto label1;
					}
						if(ch==2 && pred==NULL)
							break;
						c=(stud*)malloc(sizeof(stud));
						if(!c)
						{
							printf("List is full\n");
							break;
						}
						printf("Enter Student details\n");
						printf("Student Name:\n");
						scanf("%s",c->name);
						printf("Student USN:\n");
						scanf("%s",c->usn);
						printf("Branch:\n");
						scanf("%s",c->branch);
						printf("Semseter;\n");
						scanf("%d",&c->sem);
						printf("Student Roll_N0:\n");
						scanf("%d",&c->roll_no);
						res=insertion(p,pred,c);
						if(res)
							printf("Inserted successfully\n");
						else
							printf("Insertion failed\n");
						break;
			case 2:printf("1 for beginning\n2 for middle\n3 for end\n");
				   printf("Enter  choice:\n");
				   scanf("%d",&ch);
				   switch(ch)
				   {
					   label2:
					   case 1:pred=NULL;
							  break;
					   case 2:printf("enter student usn to delete:\n");
							  scanf("%s",pkey);
							  NODE *temp;
							  pred=NULL;
							  temp=p->head;
							  while(temp != NULL && strcmp(pkey, ((stud *)(temp->dp))->usn))
							  {
								pred=temp;
								temp=temp->next;
							  }  
							  break;
						case 3:pred=NULL;
							   NODE *t;
							   t=p->head;
							   while(t->next)
							   {
								   pred=t;
								   t=t->next;
							   }
							   break;
						default:printf("Invalid choice\n");
								goto label2;
					}
					if(ch==2 && pred==NULL)
					{
						printf("key is not found\n");
						break;
					}
					c=(stud*)deletion(p,pred);
					free(c);
					break;
			case 3:printf("enter key to retrieve the Student information\n");
				   scanf("%s",pkey);
				   c=(stud*)retrievelist(p,pkey,compare);
				   printlist(c);
				   break;
			case 4:printf("Enter Student USN to search\n");
				   scanf("%s",pkey);
				   pred=searchlist(p,pkey,compare);
				   if(pred)
				   {
					   printf("Student id found\n");
					   printlist(pred->dp);
				   }
				   else
						printf("Course is not found\n");
				   break;
			case 5:printf("contents of list are:\n");
				   if(!listempty(p))
						displaylist(p,printlist);
				   else
						printf("List is empty\n");
				   break;
			case 6:if(listfull(p))
						printf("List is full\n");
				   else
						printf("list is not full\n");
			       break;
			case 7:if(listempty(p))
						printf("List is empty\n");
				   else
						printf("list is not empty\n");
			       break;
			case 8:printf("number of elements are:%d\n",listcount(p));
				   break;
			case 9:if(destroylist(p))
						printf("destroyed successfully\n");
				   else
						printf("failed\n");
				   return 0;
			default:printf("Invalid choice\n");
		}
	}	  
}
