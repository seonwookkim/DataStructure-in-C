#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

linkedlist_t
linkedlist_alloc () 
{
	return 0x0 ;
}

void
linkedlist_push (linkedlist_t * l, int e)
{
	linkedlist_t new_list = (linkedlist_t) malloc(sizeof(node_t)) ;

	new_list->element = e ;
	new_list->tail = *l ;
	// linkedlist_t는 pointer 인데 l도 pointer이다. pointer의 pointer! l의 값을 dereference 한다!
	// 즉 l이 가르키고 있는 값을 new_list->tail이 가르키게 된다!
	*l = new_list ; // l이 가르키는 값을 new_list 값으로 바꿔주세요!
}

int
linkedlist_retrieve (linkedlist_t l, int pos, int * e)
{
	int i = 0 ;
	while (l != 0x0) {
		if (i == pos) {
			*e = l->element ;
			return 0 ;
		}
		// i < pos
		i += 1 ;
		l = l->tail ; // 이번 ele에는 없었으니 tail값을 l로 설정해서 다시 확인한다!
	}

	return 1 ;
}

int 
linkedlist_length (linkedlist_t l)
{
	int i = 0 ;

	while (l != 0x0) {
		i += 1 ;
		l = l->tail ; 
	}
	return i ;
}

int 
linkedlist_pop (linkedlist_t * l, int * e)
{
	if (*l == 0x0)
		return 1 ;

	linkedlist_t tmp ; // tail로 l값 덮어씌우기
	*e = (*l)->element ; //head값 반환하기
	tmp = *l ; // l값을 tmp에 넣기 왜냐 free하기 위해!
	*l = (*l)->tail ; // tail 값을 l에 덮어씌우기
	free(tmp) ; // tmp 프리~ 첫 linked list의 element 값이 날아감
	return 0 ;
}

int
linkedlist_remove (linkedlist_t * l, int e)
{
	linkedlist_t * p ;

	p = l ;
	while (*p != 0x0) { // p값이 가르키는 주소의 값을 봤더니 null이다 (dereferenc)
		if ((*p)->element == e) {
			linkedlist_t tmp ;
			tmp = *p ;
			*p = (*p)->tail ; 
			free(tmp) ;
			return 0 ;
		}
		else {
			p = &((*p)->tail) ; // p값이 가르키고 있는 주소의 tail의 주소를 p에 저장한다
		}
	}
	return 1 ;
}
