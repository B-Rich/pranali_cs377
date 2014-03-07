#ifndef MYLIST_H
#define MYLIST_H
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
struct node_struct
{
	int inst_no;
//	int int_type;
	int uid;
	struct node_struct* next;
}; 
typedef struct node_struct node;
struct mylist_struct
{
	node* head;
};


typedef struct mylist_struct mylist;
void my_insert(int _inst_no,int _uid,mylist* l)
{
	node* a;
	a = (node*)malloc(sizeof(node));
	a->inst_no = _inst_no;
	a->uid = _uid;
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

node* my_top(mylist *l)
{
	return l->head;
}

void my_delete(mylist* l)
{
	if(l->head)
	{
		node* temp;
		temp = l->head;
		l->head = (l->head)->next;
		free(temp);
	}
}

/*int main()
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
}*/
#endif
