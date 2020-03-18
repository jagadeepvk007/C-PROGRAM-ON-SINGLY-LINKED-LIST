#include<stdio.h>
#include<conio.h>
struct list
 {
  char usn[15];
  char name[50];
  char branch[4];
  int sem;
  char phno[15];
  struct list *link;
  };
  typedef struct list node;


  node* insertfront(node *first)
   {
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("enter usn,name,branch,sem,phno\n");
    scanf("%s%s%s%d%s",&temp->usn,&temp->name,&temp->branch,&temp->sem,&temp->phno);
    temp->link=NULL;

    if(first==NULL)
     {
      first=temp;
      return(first);
     }
    else
     {
      temp->link=first;
      first=temp;
      return(first);
     }
    }

   node* insertend(node *first)
    {
     node *temp,*ptr;
     temp=(node*)malloc(sizeof(node));
     printf("enter the usn, name, branch, sem, phno\n");
     scanf("%s%s%s%d%s",&temp->usn,&temp->name,&temp->branch,&temp->sem,&temp->phno);
     temp->link=NULL;

     if(first==NULL)
      {
       first=temp;
       return first;
      }
     else
      {
       ptr=first;
       while(ptr->link!=NULL)
       ptr=ptr->link;
       ptr->link=temp;
       return(first);
      }
    }

    node* deletefront(node *first)
     {
      node *ptr;
      if(first==NULL)
       {
	printf("list is empty, cannot delete\n");
	return(first);
       }
      else
       {
	ptr=first;
	printf("the node deleted is %s\n",ptr->name);
	first=ptr->link;
	free(ptr);
       }
      return(first);
     }

    node* deleteend(node *first)
     {
      node *ptr,*last;
      if(first==NULL)
       {
	printf("list is empty, cannot delete\n");
	return first;
       }
      if(first->link==NULL)
       {
	printf("the node deleted is %s\n",first->name);
	first=first->link;
	free(first);
	return first;
       }
      else
       {
	ptr=first;
	while(ptr->link!=NULL)
	 {
	  last=ptr;
	  ptr=ptr->link;
	 }
	printf("the node deleted is %s\n",ptr->name);
	free(ptr);
	last->link=NULL;
       }
       return first;
   }


   node* stackoperation(node *first)
    {
     int ch;
     printf("1.push \n 2.pop \n 3.exit stack \n");
     printf("enter the choice\n");
     scanf("%d",&ch);
      switch(ch)
       {
	case 1:first=insertfront(first);
		break;
	case 2:first=deletefront(first);
		break;
	case 3:return;
       }
       return first;
     }
    node* queueoperation(node *first)
      {
       int ch;
       printf("1. insert\n  2.delete\n  3.exit queue\n");
       printf("enter the choice\n");
       scanf("%d",&ch);
	switch(ch)
	 {
	  case 1:first=insertend(first);
		break;
	  case 2:first=deletefront(first);
		break;
	  case 3:return;
	 }
	 return first;
      }

     void display(node *first)
      {
      node *ptr;
      int count=0;
       if(first==NULL)
	{
	 printf("no student data to display\n");
	}
       else
	{
	 ptr=first;

	 while(ptr!=NULL)
	  {
	   count++;
	    printf("%s%s%s%d%s\n",ptr->name,ptr->usn,ptr->branch,ptr->sem,ptr->phno);
	    ptr=ptr->link;
	  }
	}
     }

    void main()
       {
	int ch,i,n;
	node *first=NULL;
	clrscr();

	printf("1. create\n 2.insert front\n  3.insert end\n  4.delete front \n 5.delete end\n");
	printf("6. display \n 7. sll as stack\n  8. sll as queue \n 9. exit \n");

	while(1)
	 {
	  printf("enter your choice\n");
	  scanf("%d",&ch);
	   switch(ch)
	    {
	     case 1:printf("\n enter the no. of students \n");
		    scanf("%d",&n);
		    for(i=1;i<=n;i++)
		     first=insertfront(first);
		    break;
	     case 2:first=insertfront(first);
		    break;
	     case 3:first=insertend(first);
		    break;
	     case 4:first=deletefront(first);
		    break;
	     case 5:first=deleteend(first);
		    getch();
		    break;
	     case 6:display(first);
		    break;
	     case 7:first=stackoperation(first);
		    getch();
		    break;
	     case 8:first=queueoperation(first);
		    getch();
		    break;
	     case 9:exit();

	    }
	  }
	}