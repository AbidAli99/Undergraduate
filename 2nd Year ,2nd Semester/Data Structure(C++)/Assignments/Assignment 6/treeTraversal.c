/*
 * Binary Tree Traversal.
 *ABID ALI
 * abiduu354@gmail.com
 */
#include <stdio.h>
#include <stdlib.h>
#include "treeTraversal.h"

/** Helper function that allocates a new node with the
  * given data and NULL left and right pointers.
  * We have implemented this function for your convenience.
  * Don't forget to free all memory allocated here before your program terminates. */
node_t *new_node(char data)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

/** Recursive function to construct a binary tree from preorder traversal pre and inorder traversal in,
    where the lengths of pre and in are both len. */
node_t *build_tree(char pre[], char in[], int len)
{
    //TODO: Insert your code here
    if (len == 0) {
        return NULL;
    }

    node_t *temp = (node_t *)malloc(sizeof(node_t));//need to allocate memory space for the new node of the tree
    temp->data = pre[0];
    int k;

    for (k = 0; k < len; k++) {
        if (in[k] == pre[0]) {
            break;
        }
    }

    temp->left = build_tree(pre+1, in, k);
    temp->right = build_tree(pre+k+1, in+k+1, len-k-1);

    return temp;

}

/** Prints the post-order traversal of the given root of a binary tree. */
void print_postorder(node_t *node)
{
    //TODO: Insert your code here

    if (node != NULL) {
        print_postorder(node->left);
        print_postorder(node->right);
        printf("%c", node->data);
    }
}
