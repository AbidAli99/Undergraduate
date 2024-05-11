/*
*This code was done in C++
 *Merge Two Sorted Linked Lists
 *Assignment 1
 *ABID ALI_2019380141
 *abiduu354@gmail.com
 */
#include <iostream>
using namespace std;

typedef struct Node
{
public:

    int info;

    struct Node *link;
}Node,*PNode;

typedef struct LinkList
{
    PNode head;
    PNode tail;
    int size;
}LinkList, *PLinkList;


struct Node *create(struct Node *start);

struct Node *insert_list(struct Node *start, int data);

struct Node *insert(struct Node *start, int data);

void print_list(struct Node *start);




void merge_list(struct Node *p1, struct Node *p2)
{

    struct Node *start3;

    start3 = NULL;

    while (p1 != NULL && p2 != NULL)

    {

        if (p1->info < p2->info)

        {

            start3 = insert(start3, p1->info);

            p1 = p1->link;
        }

        else if (p2->info < p1->info)

        {

            start3 = insert(start3, p2->info);

            p2 = p2->link;
        }

        else if (p1->info == p2->info)

        {

            start3 = insert(start3, p1->info);

            p1 = p1->link;

            p2 = p2->link;
        }
    }

    while (p1 != NULL)

    {

        start3 = insert(start3, p1->info);

        p1 = p1->link;
    }

    while (p2 != NULL)

    {

        start3 = insert(start3, p2->info);

        p2 = p2->link;
    }



    print_list(start3);
}

struct Node*create(struct Node *start)
{

    int i, n, data;



    cin>>n;

    start = NULL;

    for (i = 1; i <= n; i++)

    {



        cin>>data;

        start = insert_list(start, data);
    }

    return start;
}

struct Node *
insert_list(struct Node *start, int data)
{

    struct Node *p, *tmp;

    tmp = (struct Node *)malloc(sizeof(struct Node));

    tmp->info = data;

    if (start == NULL || data < start->info)

    {

        tmp->link = start;

        start = tmp;

        return start;
    }

    else

    {

        p = start;

        while (p->link != NULL && p->link->info < data)

            p = p->link;

        tmp->link = p->link;

        p->link = tmp;
    }

    return start;
}

struct Node*insert(struct Node *start, int data)
{

    struct Node *p, *tmp;

    tmp = (struct Node *)malloc(sizeof(struct Node));

    tmp->info = data;

    if (start == NULL)

    {

        tmp->link = start;

        start = tmp;

        return start;
    }

    else

    {

        p = start;

        while (p->link != NULL)

            p = p->link;

        tmp->link = p->link;

        p->link = tmp;
    }

    return start;
}

void print_list(struct Node *start)
{

    struct Node *p;

    if (start == NULL)

    {

        cout<<"List is empty\n";

        return;
    }

    p = start;

    while (p != NULL)

    {

        printf("%d ", p->info);

        p = p->link;
    }

    cout<<"\n";
}
int main()
{

    struct Node *start1 = NULL, *start2 = NULL;

    start1 = create(start1);

    start2 = create(start2);


    merge_list(start1, start2);

    return 0;
}
