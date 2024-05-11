#include "allocator.h"
#include "dnode.h"
#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
	int init;
	size_t size;
	int sizes[5] = {100, 200, 250, 200, 100};
	int i;
	size = 2000;
	init = allocator_init(size);
	allocator_print();
	if(init == -1){
		exit(-1);
	}
	// test first-fit policy
	for(i = 0; i < 5; i++){
		allocate(0, sizes[i]);
	}
	allocator_print();
	//remove a node
	struct dnode *curNode;
	curNode = getIterAllocatedList(2);
	printf("Removed Node size = %d, points to %lld", curNode->size, (long long) curNode->data);
	deallocate(curNode->data);
	allocator_print();
	// allocate space for mem size 300; will result in two free nodes, since we use first fit
	/*
	allocate(0, 250);
	allocator_print();
	*/
	//allocate space for mem size 250; will result in one free node, since we use best fit
	///*	
	allocate(1,250);
	allocator_print();	
	//*/	
	//attempt to allocate memory too large
	allocate(0,1300);

	//allocate more memory
	allocate(0, 300);
	allocate(0,320);
	allocate(0,340);
	allocator_print();

	//remove some data
	curNode = getIterAllocatedList(2);
	deallocate(curNode->data);
	curNode = getIterAllocatedList(1);
	deallocate(curNode->data);
	curNode = getIterAllocatedList(2);
	deallocate(curNode->data);
	allocator_print();
	//test first-fit - WORKS
	//allocate(0,20);
	//test best-fit - WORKS
	//allocate(1,20);
	//test worst-fit - WORKS
	allocate(2,20);
	allocator_print();
	// test if node is removed from allocated_list
	allocate(1,190);
	allocator_print();

	return 0;
}
