#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct vertex {
	struct vertex* next;
	int v;
};

typedef struct vertex vertex_t;

typedef struct {
	vertex_t* head;
	int lenght;
	
}list_t;


// Creates a BRILLIANT (not really new, because we already have the pointer to it), empty list

void list_init(list_t* l) {
	l->next = NULL;
	l->length = 0;
};


// Inserts a new vertex with valence val_new into the list at the position between the elements at pos and pos+1.
// TODO: list_insert adds an element after pos, it would be nice if actually adds it before.
// TODO: if the list is empty, inserting an element should close the cycle.
void list_insert(list_t* l, int val_new, int pos) {

	//	l->head =def= (*l).head;
	pos = pos % l->length;
	vertex_t* ver_new = malloc(sizeof(vertex_t));
	//	vertex_t ver_new = *malloc(sizeof(vertex_t)); falsch, lokal
	ver_new->v = val_new;

	vertex_t* ver_iter = l->head;
	
	for (int i = 0; i < pos; i++) {
		ver_iter = ver_iter->next;
	}
	
	// (start;abbruchbedingung;befehl für jede iteration)

	ver_new->next = ver_iter->next;
	ver_iter->next = ver_new;

	l->length++;
	
};

// Deletes the element at position pos of the list l. 
//TODO: if pos==0, retarget the l->head pointer.
//TODO: if l->length == 0; define a behavior
//TODO(MAYBE): if l->length == 1; set l->head == NULL
void list_delete(list_t* l, int pos) {
	
	if(pos == 0) {
		pos = l->length;
	};

	vertex_t* ver_iter = l->head;
	
	

	for(int i = 0; i < pos-1; i++) {
		ver_iter = ver_iter->next;
	};
	

	vertex_t* ver_help = ver_iter->next;
	
	ver_iter->next = ver_iter->next->next;
	free(ver_help);

	l->length--;
};

void main(int argc, char** argv) {
	int a[2] = {1, 2};
	int* b = &a[0];
	int c = *b;

	
}



