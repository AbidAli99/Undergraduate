#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "dnode.h"
/*
  initializes two dlists: free_list and allocated_list. allocated_list is
  initialized as empty. free_list is initialized with one dnode. For this dnode,
  the size is equal to the size passed, and the data pointer points to the start
  of allocated memory, which is allocated using malloc(size).
*/

int allocator_init(size_t size);

/*
  This is a simple redirecting function, where depending on the int policy
  passed, one of the three policies will be called.
*/
void *allocate(int policy, size_t size);

/*
  Iterates through the nodes in free_list, starting from the front of the list.
  A temporary node, curNode is declared, which is set equal to the iterator of
  free_list. A do-while loop is used to test if curNode is has enough memory
  to allocate. Each iteration of the loop sets the iterator to the next node.
  When a suitable node is found, a new node is added to the back of dlist, and
  curNode's size is decreased and it's data pointer is increased by size. If
  curNode's size is = 0 after this decrease in size, it is removed from
  free_list. If the list is empty or no node has enough memory to allocate, 
  NULL is returned. 
*/
void *firstFit(size_t size);

/*
  Iterates through the nodes in free_list, starting from the front of the list.
  A temporary node, curNode is declared, which is set equal to the iterator of
  free_list. Another temporary node, smallestNode is declared, which is by 
  default set equal to the first node in free_list. A do-while loop is used to
  iterate through every node of free_list. If the current node has enough
  memory and is smaller than smallestNode, then smallestNode is set to the
  currentNode. After every node is checked, the loop terminates. smallestNode is
  added to the back of the allocated_list. If smallestNode's size = 0, then it
  is removed from free_list. Otherwise, the size and data pointer of
  smallestNode are adjusted accordingly. If free_list is empty or no node has
  enough memory to allocate, NULL is returned.
*/
void *bestFit(size_t size);

/*
  Iterates through the nodes in free_list, starting from the front of the list.
  A temporary node, curNode is declared, which is set equal to the iterator of
  free_list. Another temporary node, largestNode is declared, which is by 
  default set equal to the first node in free_list. A do-while loop is used to
  iterate through every node of free_list. If the current node has enough memory  and is larger than largestNode, then largestNode is set to the current node. 
  After every node is checked, the loop terminates. largestNode is added to the
  back of allocated_list. If largestNode's size = 0, then it is removed from
  free_list. Otherwise, the size and data pointer of smallestNode are
  adjusted accordingly. If free_list is empty or no node has enough memory to
  allocate, NULL is returned.
*/
void *worstFit(size_t size);

/*
  Iterates through the nodes in allocated_list, starting from the front of the
  list. A temporary node, curNode is declared, which is set equal to the
  iterator of allocated_list. A boolean variable 'exists' is set to false as 
  well. A while loop iterates through allocated_list. The loop will run as long
  as curNode is not NULL. If curNode's data address equals the address pointer
  passed, called ptr, then exits is set to true and the loop terminates. After
  the loop terminates, if exits is false, the function exits and returns -1.
  Otherwise, the node pointed to is removed from allocated_list and added to the
  back of free_list.
*/
int deallocate(void *ptr);

/*
  Simply put, this function prints both free_list and allocated_list. A
  temporary node, curNode is declared, and is set equal to the iterator of 
  free_list. The iterator is set to the first node in the list. If curNode is
  NULL to start, then free_list is empty. Otherwise, a do-while loop is used
  to iterate through every node in free_list and print out the node's size
  and memory address that data points to. After free_list is printed, curNode
  is set equal to the iterator of allocated_list, and the same process to print
  free_list applies to allocated_list.

*/
void allocator_print();

/*
  Returns a node in allocated_list. Simply put, a helper function for deallocate.
  A temporary node, curNode is declared, and is set equal to the iterator of
  allocated_list. The iterator is set to the first node in allocated_list. If
  curNode is NULL right after it is set to the iterator, allocated_list is empty
  and NULL is returned. A counter for a while loop, count, is initialized to 1.
  A while loop iterates through allocated_list until the iterator is equal to the
  'ath' node of allocated_list. After the loop exits, the function returns the
  node that the iterator points to. All in all, this function returns the 'ath'
  node of allocated_list.
*/
void *getIterAllocatedList(int a);

/*
  Returns a double representing the average size of the nodes in free_list. A temporary
  node is initialized to the iterator of free_list, which is set to the first node of
  the list. A while loop is used to iterate through every node, where after each
  iteration of the loop, curNode is set equal to the next node. During each iteration
  the size of curNode is added to double totalSize, and the int totalNodes is
  implemented by 1. After the loop terminates, there is a check to see if the list
  is empty. If so, a message is printed and 0.0 is returned. Otherwise, the return
  value is totalSize/totalNodes.
*/

double average_frag();



#endif /* _ALLOCATOR_H_ */

