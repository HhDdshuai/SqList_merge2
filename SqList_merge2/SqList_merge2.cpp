#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef int elemType;
typedef struct LNode{
	elemType data;
	struct LNode *next;
}LNode;
LNode *createList(elemType arr[],int n){
	int i;
	LNode *L,*r,*s;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL){
		printf("ø’º‰∑÷≈‰ ß∞‹.\n");
		exit(0);
	}
	r = L;
	for(i = 0;i < n;i++){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = arr[i];
		r->next = s;
		r = s;
	}
	r->next =NULL;
	return L;
}
void printList(LNode *L){
	LNode *p = L->next;
	while(p != NULL){
		printf("%d->",p->data);
		p = p->next;
	}
	printf("\n");
}
void merge(LNode **L1,LNode **L2){
	LNode *p1,*p2,*pre,*q;
	p1 = (*L1)->next;
	p2 = (*L2)->next;
	free(*L1);
	while(p1 != NULL){
		q = p1->next;
		while((p2 != NULL) && (p2->data <= p1->data)){
			//printf("*%d*",p2->data);
			pre = p2;
			p2 = p2->next;
		}
		p1->next = p2;
		pre->next = p1;
		p1 = q;
		p2 = (*L2)->next;
	}
}
int main(){
	elemType a[] = {56,41,26,86,94,14,36,35};
	elemType b[] = {12,16,19,21,24,28,36,39,44,46,49};
	int len_a,len_b;
	LNode *L1,*L2;
	len_a = sizeof(a)/sizeof(a[0]);
	len_b = sizeof(b)/sizeof(b[0]);
	L1 = createList(a,len_a);
	printList(L1);
	L2 = createList(b,len_b);
	printList(L2);
	merge(&L1,&L2);
	printList(L2);
}