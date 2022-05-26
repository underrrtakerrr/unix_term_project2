
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

static bool isInit = false;

void init(){
	isInit = true;
	_head = malloc(sizeof(Node));
	_tail = malloc(sizeof(Node));
	_cur_node = _head;

	_head->next = _tail;
	_tail->prev = _head;
}

bool empty(){
	return_head == NULL;
}

size_t size(){
	size_t count = 0;
	Node *now = _head;

	while(now != NULL){
		now = now->next;
		count++;
	}
	return count;
}

void print(){
	Node *now = _head;
	printf("LinkedList [ ");
	while(now != NULL){
		printf("%s ", now->data);
		now = now->next;
	}
	printf("]\n");
}

void print_file(FILE* stream){
	Node *now = _head;
	fprintf(stream, "[ ");
	while(now!=NULL){
		fprintf(stream,"%s ", now->data);
		now = now->next;
	}
	fprintf(stream,"]\n");
}

void clear(){
	Node* now = Null;
	if(empty())
		return;
	
	now = _tail;
	while(now != _head){
		now = now->prev;
		free(now->next->data);
		free(now->next);
	}
	free(now->data);
	free(now);

	_tail = NULL;
	_head = NULL;
	_cur_node = NULL;
}

Node* append_left(size_t n, char new_data[]){
	if(size() == 0)
		return push(new_data);

	if(cur_node == _head)
		return push(new_data);

	struct Node* new_node = alloc_node(new_data);

	new_node->prev = cur_node->prev;
	cur_node->prev = new_node;
	new_node->next = cur_node;

	if(new_node->prev != NULL)
		new_node->prev->next = new_node;

	return new_node;
}

Node* insert_after(Node* cur_node, Node* new_node){
	if(size()==0)
		return push(new_data);

	struct Node* new_node = alloc_node(new_data);

	new_node->next = cur_node->next;
	cur_node->next = new_node;
	new_node->prev = cur_node;

	if(new_node->next != NULL)
		new_node->next->prev = new_node;
	else
		_tail = new_node;

	return new_node;
}

Node* append(size_t n, char new_data[]){
	if(isInit)
		init();
	Node* new = malloc(sizeof(Node));
	new->data = new_data;
	insert_after(_tail->prev,new)
}

Node* _insert_after(Node* cur_node, size_t n, char new_data[]){

}


Node* pop_left(){

}

Node* pop(){

}

Node* delete_node(Node* cur_node){
	if(size() == 0)
		return NULL;
	
	if(cur_node == _head){
		Node *now = cur_node->next;
		now->prev=NULL;
		free(cur_node);
		_head = now;
		return NULL;
	}

	Node *prev = cur_node->prev;
	prev->next = cur_node->next;
	
	if(prev->next != NULL;)
		prev->next->prev = prev;
	else
		_tail = prev;

	free_node(cur_node);
	return NULL;

}

Node* delete_by_data(char* data){
	Node *now = _head;

	while(now != NULL){
		if(strcmp(now->data, data) == 0)
			return delete_node(now);

		now = now->next;
	}
	return NULL;
}

Node* next(){
	Node* s = _cur_node->next;
	if(_cur_node == _tail)
		s = _tail->prev;
	return s;
}

Node* prev(){
	Node* s = _cur_node->prev;
	if(_cur_node == _head)
		s = _head->prev;
	return s;
}

Node* first_node(){
	if(size() > 0)
		return _head->next;
	else
		return _tail;
}

Node* last_node(){
	if(size() > 0)
		return _tail->prev;
	else
		return _tail;
}

Node* get_node(size_t index){
	int count = 0;
	if(size() - 1 < index)
		return NULL;

	Node *now = _head;
	while(count != index){
		now = now->next;
		count++
	}
	return now;
}

Node* push(char new_data[]){
	struct Node* new_node = alloc_node(new_data);
	new_node->next = _head;
	new_node->prev = NULL;

	if(_head != NULL)
		_head->prev = new_node;
	else
		_cur_node = _tail = new_node;

	_head = new_node;
	return new_node;
}


