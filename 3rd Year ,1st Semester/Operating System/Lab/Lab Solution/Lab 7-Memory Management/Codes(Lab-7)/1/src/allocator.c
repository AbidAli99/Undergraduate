#include "dlist.h"
#include "dnode.h"
#include "allocator.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct dlist *free_list;
struct dlist *allocated_list;



int allocator_init(size_t size){
	free_list = dlist_create();
	allocated_list = dlist_create();
	void *data;
	data = malloc(size);
	if(data == NULL){
		printf("ERROR WITH MALLOC()\n");
		return -1;
	}
	dlist_add_front(free_list, data, size); //added size
	return 0;
}


void *allocate(int policy, size_t size){
	void *ret;
	if(policy == 0){
		ret = firstFit(size);	
	}
	else if(policy == 1){
		ret = bestFit(size);
	}
	else if(policy == 2){
		ret = worstFit(size);
	}
	return ret;


}

void *firstFit(size_t size){

	dlist_iter_begin(free_list); // set iter to start of free_list
	struct dnode *curNode; // declare curNode as a dnode
	do{
		curNode = free_list->iter; // current node is iterator
		if(curNode == NULL){ // case free_list is empty
			break;
		}
		if(curNode->size > size){ // if size of node is large enough
			//printf("ADDRESS: %lld\n", (long long) curNode->data);
			dlist_add_back(allocated_list, curNode->data, size);
			curNode->size -= size;
			curNode->data += size;		
			void *retVal;
			retVal = curNode->data;
			if (curNode->size <= 0){
				dlist_find_remove(free_list, retVal);
			}
			return retVal;
		}

	}while(dlist_iter_next(free_list) != NULL);
	printf("No node is large enough to store memory!\n");
	return NULL;
	

}

void *bestFit(size_t size){
	dlist_iter_begin(free_list); // set iter to start of free_list
	struct dnode *curNode; // declare curNode as a dnode
	struct dnode *smallestNode;

	curNode = free_list->iter;

	if (curNode == NULL){
		return NULL;
	}

	smallestNode = curNode; // set default smallest node to first node
	
	do{
		curNode = free_list->iter;
		//printf("curNode size: %d\n", curNode->size);
		//printf("size: %lld\n", (long long) size);
		//printf("smallNode size: %d\n\n", smallestNode->size);
		if(curNode->size >= size && curNode->size < smallestNode->size){
			//printf("SET NEW SMALL\n\n");
			smallestNode = curNode; // set smallestNode
		}

	}while(dlist_iter_next(free_list) != NULL);
	
	if(smallestNode->size < size){ // if no node is large enough
		printf("No node is large enough to store memory!\n");
		return NULL;
	}

	dlist_add_back(allocated_list, smallestNode->data, size);
	smallestNode->size -= size;
	smallestNode->data += size;
	void *retVal;
	retVal = smallestNode->data;
	//printf("SMALL SIZE: %d\n", smallestNode->size);
	if (smallestNode->size <= 0){ // remove node from free_list if size is 0
		dlist_find_remove(free_list, retVal);
	}
	return retVal;
	

}

void *worstFit(size_t size){
	dlist_iter_begin(free_list); // set iter to start of free_list
	struct dnode *curNode; // declare curNode as a dnode
	struct dnode *largestNode;


	curNode = free_list->iter;

	if (curNode == NULL){
		return NULL;
	}

	largestNode = curNode; // set degault largest node to first node
	
	do{
		curNode = free_list->iter;
		if(curNode->size >= size && curNode->size > largestNode->size){
			largestNode = curNode; // set largestNode
		}

	}while(dlist_iter_next(free_list) != NULL);
	
	if(largestNode->size < size){ // if no node is large enough
		printf("No node is large enough to store memory!\n");
		return NULL;
	}

	dlist_add_back(allocated_list, largestNode->data, size);
	largestNode->size -= size;
	largestNode->data += size;
	void *retVal;
	retVal = largestNode->data;
	if (largestNode->size <= 0){
		dlist_find_remove(free_list, retVal);
	}
	return retVal;


}

int deallocate(void *ptr){

	//need to see if node exists
	void *curNode;
	bool exists = false;
	curNode = dlist_iter_begin(allocated_list);
	while(curNode != NULL){
		if(curNode == ptr){
			exists = true;
			break;
		}
		curNode = dlist_iter_next(allocated_list);
	}

	if(exists == false){
		return -1;
	}

	int size = allocated_list->iter->size;
	dlist_find_remove(allocated_list, ptr);
	dlist_add_back(free_list, curNode, size);
	return 0;
}

void allocator_print(){
	dlist_iter_begin(free_list); // set iter to start of free_list
	struct dnode *curNode; // declare curNode as a dnode
	//print free list
	curNode = free_list->iter;
	if(curNode == NULL){
		printf("Free List is empty!\n");
	}
	else{
		printf("\nFree List:\n");
		do{
			curNode = free_list->iter;
			printf("Node size = %d, points to %lld\n", curNode->size, (long long) curNode->data);

		}while(dlist_iter_next(free_list) != NULL);
	}
	//print allocated_list
	dlist_iter_begin(allocated_list);
	curNode = allocated_list->iter;
	if(curNode == NULL){
		printf("Allocated List is empty!\n");
	}
	else{
		printf("\nAllocated List:\n");
		do{
			curNode = allocated_list->iter;
			printf("Node size = %d, points to %lld\n", curNode->size, (long long) curNode->data);

		}while(dlist_iter_next(allocated_list) != NULL);
	}
	return;
}

void *getIterAllocatedList(int a){ // a is a positive number, returns ath allocated node
	int count = 0;
	dlist_iter_begin(allocated_list); // set iter to start of free_list
	struct dnode *curNode; // declare curNode as a dnode
	curNode = allocated_list->iter;
	if(curNode == NULL){
		printf("Allocated List is Empty!\n");
		return NULL;
	}
	while(count != a && curNode != NULL){
		dlist_iter_next(allocated_list);
		curNode = allocated_list->iter;
		count+= 1;
	}
	//printf("node size = %d, points to %lld\n", curNode->size, (long long) curNode->data);
	return curNode;

}









