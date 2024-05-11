/*
 *This code was done in C++
 *Merge Two Sorted Linked Lists
 *Assignment 2
 *ABID ALI_2019380141
 *abiduu354@gmail.com
 */
#include<conio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
//Declaring poly data type
typedef struct node
{
    int coef;/* coefficient */
    int expo;/* exponent */
    struct node *link;
}node;
//We are creating instances such as insert,traverse, use , add and multiply

void insert_value(struct node **,int,int);

void traverse(struct node *);

void poly_add(struct node **,struct node **,struct node **);

void poly_multi(struct node **,struct node **,struct node **);

int main()
{

    struct node *start_p=NULL,*start_q=NULL,*start_r=NULL;

    int i,n,c,e;

    cin>>n;

    for(i=0; i<n; i++)
    {

        cin>>c;
        cin>>e;
        insert_value(&start_p,c,e);

    }

    cin>>n;

    for(i=0; i<n; i++)
    {

        cin>>c;

        cin>>e;

        insert_value(&start_q,c,e);

    }


    poly_add(&start_p,&start_q,&start_r);

    //Sum of two polynomial values were calculated in this function

    traverse(start_r);

    start_r=NULL;

    poly_multi(&start_p,&start_q,&start_r);

    //Product of the two polynomial values were calculated in this function


    traverse(start_r);

}
void traverse(struct node *start)
{
    struct node *current;

    current = start;

    if (current == NULL)
    {

        cout << current << "Empty polynomial number";
    }
    else
    {

        while (current != NULL)
        {
            if (current->coef == 0)
            {
                current = current->link;
                continue;
            }
            cout << current->coef << " "<< current->expo << " ";

            current = current->link;

            if (current != NULL)
                cout << " ";
            else
                cout << "\n";
        }
    }
}

void poly_add(struct node **start_p, struct node **start_q, struct node **start_r)

{
    int c, e;

    struct node *pptr, *qptr;

    *start_r = NULL;

    pptr = *start_p;

    qptr = *start_q;

    while (pptr != NULL && qptr != NULL)
    {

        if (pptr->expo == qptr->expo)
        {

            c = pptr->coef + qptr->coef;

            e = pptr->expo;

            insert_value(start_r, c, e);

            pptr = pptr->link;

            qptr = qptr->link;
        }
        else
        {
            if (pptr->expo > qptr->expo)
            {
                c = pptr->coef;

                e = pptr->expo;

                insert_value(start_r, c, e);

                pptr = pptr->link;
            }
            else
            {
                c = qptr->coef;

                e = qptr->expo;

                insert_value(start_r, c, e);

                qptr = qptr->link;
            }
        }
    }

    while (pptr != NULL)
    {

        c = pptr->coef;

        e = pptr->expo;

        insert_value(start_r, c, e);

        pptr = pptr->link;
    }

    while (qptr != NULL)
    {

        c = qptr->coef;

        e = qptr->expo;

        insert_value(start_r, c, e);

        qptr  = qptr->link;
    }
}

void poly_multi(struct node **start_p, struct node **start_q, struct node **start_r)
{

    int c, e;

    struct node *pptr, *qptr;

    *start_r = NULL;

    pptr = *start_p;

    qptr = *start_q;

    if (*start_p == NULL && *start_q == NULL)
    {
        cout << start_p << start_q << "Multiplication of polynomial is not possible!";//Warning is given for invalid value.
    }
    else
    {
        while (pptr != NULL)
        {

            qptr = *start_q;

            while (qptr != NULL)
            {

                c = pptr->coef * qptr->coef;

                e = pptr->expo + qptr->expo;

                insert_value(start_r, c, e);

                qptr = qptr->link;
            }

            pptr = pptr->link;
        }
    }
}
void insert_value(struct node **start,int c,int e)
{
    struct node *current,*current1,*prev;

    if (*start==NULL)
    {

        current=(struct node*)malloc(sizeof(struct node));

        if (current==NULL)
            cout << current << "Node is cann't be created, value cann't be inserted";
        else
        {
            current->coef=c;

            current->expo=e;

            current->link=NULL;

            *start=current;

        }
    }
    else
    {
        current1=*start;

        //Inserting value in the ascending order
        while (current1!=NULL && current1->expo<e)
        {

            prev=current1;
            current1=current1->link;

        }

        if(current1==NULL)
        {

            current=(struct node *)malloc(sizeof(struct node));

            if(current==NULL)
            {
                cout << current << "Node is not found";
            }
            else
            {
                current->coef=c;

                current->expo=e;

                current->link=NULL;

                prev->link=current;

            }
        }
        else
        {
            if(current1->expo==e)
                current1->coef=current1->coef+c;
            else
            {
                if(current1==*start)
                {
                    current=(struct node *)malloc(sizeof (struct node));

                    if(current==NULL)
                    {

                        cout << current << "Node is not created";

                    }
                    else
                    {
                        current->coef=c;

                        current->expo=e;

                        current->link=*start;

                        *start=current;

                    }
                }
                else
                {
                    current=(struct node *)malloc(sizeof(struct node));

                    if (current==NULL)
                    {

                        cout << current << "Node is not created";
                    }
                    else
                    {
                        current->coef=c;

                        current->expo=e;

                        current->link=current1;

                        prev->link=current;
                    }
                }
            }

        }
    }
}
