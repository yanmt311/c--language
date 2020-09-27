#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<vld.h>
#include<list>
#include<stack>
using namespace std;

void main()
{
	struct ListNode* middleNode(struct ListNode* head)
	{
		int x = 0;
		struct ListNode *p = head;
		while (p != NULL)
		{
			p = p->next;
			x++;
		}
		if (x % 2 == 0)
		{
			x = x / 2 + x % 2;
		}
		else
		{
			x = x / 2;
		}
		p = head;
		while (x-- > 0)
		{
			p = p->next;
		}
		return p;
	}
}

/*
typedef char ElemType;
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *link;
}LinkStackNode;

typedef LinkStackNode* LinkStack;
void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
ElemType LinkStackTop(LinkStack *pst);
int LinkStackSize(LinkStack *pst);
bool LinkStackEmpty(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);
/////////////////////////////////////////////////////

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
}

void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = *pst;
	*pst = node;
}
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	if(*pst != NULL)
	{
		LinkStackNode *p = *pst;
		*pst = p->link;
		free(p);
	}
}
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL && *pst != NULL);
	return (*pst)->data;
}

int LinkStackSize(LinkStack *pst)
{
	assert(pst != NULL);
	int size = 0;
	LinkStackNode *p = *pst;
	while(p != NULL)
	{
		size++;
		p = p->link;
	}
	return size;
}

bool LinkStackEmpty(LinkStack *pst)
{
    assert(pst != NULL);
    return *pst == NULL;
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = *pst;
	while(p != NULL)
	{
		*pst = p->link;
		free(p);
		p = *pst;
	}
}

//////////////////////////////////////////////////////////

typedef struct {
    LinkStack st;
    LinkStack min_st;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *pst = (MinStack*)malloc(sizeof(MinStack));
    LinkStackInit(&(pst->st));
    LinkStackInit(&(pst->min_st));
    return pst;
}

void minStackPush(MinStack* obj, int x) {
    LinkStackPush(&(obj->st), x);
    if(LinkStackEmpty(&(obj->min_st)) || x<=LinkStackTop(&(obj->min_st)))
        LinkStackPush(&(obj->min_st), x);
}

void minStackPop(MinStack* obj) {
    ElemType topval = LinkStackTop(&(obj->st));
    LinkStackPop(&(obj->st));
    if(topval == LinkStackTop(&(obj->min_st)))
        LinkStackPop(&(obj->min_st));
}

int minStackTop(MinStack* obj) {
    return LinkStackTop(&(obj->st));
}

int minStackGetMin(MinStack* obj) {
    return LinkStackTop(&(obj->min_st));
}

void minStackFree(MinStack* obj) {
    LinkStackDestroy(&(obj->st));
    LinkStackDestroy(&(obj->min_st));
    free(obj);
}

void main()
{

}

/*
void main()
{
	list<int> mylist;
	for(int i=1; i<=5; ++i)
		mylist.push_back(i);


}

/*
typedef char ElemType;
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *link;
}LinkStackNode;

typedef LinkStackNode* LinkStack;
void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
ElemType LinkStackTop(LinkStack *pst);
int LinkStackSize(LinkStack *pst);
bool LinkStackEmpty(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);
/////////////////////////////////////////////////////

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
}

void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = *pst;
	*pst = node;
}
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	if(*pst != NULL)
	{
		LinkStackNode *p = *pst;
		*pst = p->link;
		free(p);
	}
}
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL && *pst != NULL);
	return (*pst)->data;
}

int LinkStackSize(LinkStack *pst)
{
	assert(pst != NULL);
	int size = 0;
	LinkStackNode *p = *pst;
	while(p != NULL)
	{
		size++;
		p = p->link;
	}
	return size;
}

bool LinkStackEmpty(LinkStack *pst)
{
    assert(pst != NULL);
    return *pst == NULL;
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = *pst;
	while(p != NULL)
	{
		*pst = p->link;
		free(p);
		p = *pst;
	}
}
//////////////////////////////////////////////////////////////

bool isValid(char * s)
{
    if(s == NULL)
        return false;
    if(*s == '\0')
        return true;

    LinkStack st;
    LinkStackInit(&st);

    while(*s != '\0')
    {
        if(*s=='{' || *s=='[' || *s=='(')
            LinkStackPush(&st, *s);
        else
        {
			if(LinkStackEmpty(&st))
				return false;
            char top = LinkStackTop(&st);
            if((*s=='}'&&top!='{') || (*s==']'&&top!='[') || (*s==')'&&top!='('))
                return false;
            LinkStackPop(&st);
        }
        s++;
    }
    bool flag = LinkStackEmpty(&st);
    LinkStackDestroy(&st);
    return flag;
}

void main()
{
	char *str = "[()]";
	bool flag = isValid(str);
	if(flag)
		printf("OK.\n");
	else
		printf("Error.\n");
}







/*
void SeqListEraseAll(int *ar, int *n, int key)
{

}

void main()
{
	int ar[] = {1,3,5,5,5,5,7,9,5,5,8,0,2};
	int n = sizeof(ar) / sizeof(ar[0]);
	int size = n;
	SeqListEraseAll(ar, &size, 5);
	for(int i=0; i<size; ++i)
		printf("%d ",ar[i]);
	printf("\n");
}


/*
typedef struct ListNode
{
	int data;       //数据域
	ListNode *next; //指针域
}ListNode;

typedef ListNode* List;
void ListInit(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	(*phead)->next = NULL;
}
//尾插法
void ListCreate_Tail(List *phead)
{
	ListNode *p = *phead;
	for(int i=1; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

//头插法
void ListCreate_Head(List *phead)
{
	for(int i=1; i<=10; ++i)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = (*phead)->next;
		(*phead)->next = s;
	}
}

void ListShow(List head)
{
	ListNode *p = head->next;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void main()
{
	List mylist;        //ListNode *mylist
	ListInit(&mylist);
	ListCreate_Head(&mylist);
	ListShow(mylist);
}

/*
//1->2->3->4......->10
//单链表
typedef struct ListNode
{
	int data;       //数据域
	ListNode *next; //指针域
}ListNode;

typedef ListNode* List;
void ListInit(List *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}
//尾插法
void ListCreate_Tail(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	ListNode *p = *phead;
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

//头插法
void ListCreate_Head(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = *phead;
		*phead = s;
	}
}

void ListCreate(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	ListNode *p = *phead;
	for(int i=2; i<=10; ++i)
	{
		p = p->next = (ListNode*)malloc(sizeof(ListNode));
		p->data = i;
		p->next = NULL;
	}
}

void ListShow(List head)
{
	ListNode *p = head;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void main()
{
	List mylist;        //ListNode *mylist
	ListInit(&mylist);
	ListCreate(&mylist);
	ListShow(mylist);
}

/*
//0  
void main()
{
	int a = 10;
	int b = 1;

	int res = a || ++b;  //短路求值

	printf("res = %d\n", res); //
	printf("b = %d\n", b);     //
}

/*
void main()
{
	int *p = (int*)malloc(sizeof(int));
	*p = 100;

	int *pa = (int*)malloc(sizeof(int)*10);
	//free(p);
}
*/