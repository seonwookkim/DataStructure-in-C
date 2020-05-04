typedef struct node node_t ;
typedef struct node * linkedlist_t ;

struct node {
	int element ;
	linkedlist_t tail ; // struct node * tail 결국 구조체형 포인터이다! tail은 또 다른 리스트이기에 그렇다.
} ;

linkedlist_t  
linkedlist_alloc()  ;

void
linkedlist_push (linkedlist_t * l, int e) ;

int
linkedlist_retrieve (linkedlist_t l, int pos, int * e) ;

int 
linkedlist_length (linkedlist_t l) ;

int 
linkedlist_pop (linkedlist_t * l, int * e) ;

int
linkedlist_remove (linkedlist_t * l, int e) ;
