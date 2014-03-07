#include<time.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node_struct
{
	int inst_no;
	int int_type;
	int uid;
	struct node_struct* next;
} node; 
typedef struct
{
	node* head;
} mylist;
void insert(node* a,mylist* l)
{
	node* cur;
	node* cur_next;
	cur = l->head;
	if(!l->head )
	{
		a->next = l->head;
		l->head = a;
		
		return;
	}
	if( a->inst_no < l->head->inst_no)
	{
		a->next = l->head;
		l->head = a;
		
		return;
	}
	cur_next = cur->next;
	while(cur_next!=NULL && cur_next->inst_no <a->inst_no)
	{
		cur = cur_next;
		cur_next = cur->next;
	}
	a->next = cur_next;
	cur->next = a;
	
	return;	
}

node* top(mylist *l)
{
	return l->head;
}

void delete(mylist* l)
{
	if(l->head)
	{
		node* temp;
		temp = l->head;
		l->head = (l->head)->next;
		free(temp);
	}
}

int main()
{
	srand(time(NULL));
	mylist l;
	l.head= NULL;
	int i;
	for( i=0;i<10;i++)
	{
		node* a;
		a = (node*)malloc(sizeof(node));
		a->next = NULL;
		a->inst_no = rand();
		printf("inserting %d\n",a->inst_no);
		insert(a,&l);
	}
	while(top(&l))
	{
		printf("deleting %d\n",	top(&l)->inst_no);
		delete(&l);
	}
	return 0;
}
