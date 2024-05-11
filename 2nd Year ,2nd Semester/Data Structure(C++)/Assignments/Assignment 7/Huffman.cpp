/*
 Student Name:ABID ALI
 Student ID  :2019380141
 Email ID    :abiduu354@gmail.com
 In that assignment we have to write a program for encoding and decoding messages by Huffman .
 Assignment 07
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXNODE 100
#define MAXINT 1000000
using namespace std;

typedef struct HTNode{
	int weight;
	int parent;
	int lch;
	int rch;
}HTNode,*PHTNode;

typedef struct HTree{
	HTNode ht[MAXNODE];
	int root;
}HTree,*PHTree;

void Code(PHTree pht,char *taget,int n,int *w,char *chs);
PHTree HTCode(int n,int *w);
void Selection(PHTree pht,int pos,int *x1,int *x2);




int main()
{

	int n;
	int w[101];
	char chs[101];
	char taget[101];

	  cout<<"Input  ."<<endl;
	cin>>n;

	for (int i = 0; i < n; ++i)cin>>chs[i];

	for(int i=0; i<n; ++i)cin>>w[i];

	getchar();
	gets(taget);
	PHTree pht=HTCode(n,w);

	cout<<endl;
	cout<<"Output ."<<endl;
	Code(pht,taget,n,w,chs);
	cout<<taget<<endl;

	getchar();
	getchar();
	return 0;
}

PHTree HTCode(int n,int *w)
{

	PHTree pht;
	int i,x1=0,x2=0;
	pht = (PHTree)malloc(sizeof(HTree));

	for(i=1;i<=2*n-1;i++){
		pht->ht[i].lch = 0;
		pht->ht[i].rch = 0;
		pht->ht[i].parent = 0;
		if(i<=n)pht->ht[i].weight = w[i-1];
		else pht->ht[i].weight = 0;
	}
	for(i=1;i<n;i++){
		Selection(pht,n+i,&x1,&x2);
		pht->ht[x1].parent = n+i;
		pht->ht[x2].parent = n+i;
		pht->ht[n+i].weight = pht->ht[x1].weight + pht->ht[x2].weight;
		pht->ht[n+i].lch = x1;
		pht->ht[n+i].rch = x2;
		pht->root = n+i;
	}
	return pht;
}

void Selection(PHTree pht,int pos,int *x1,int *x2)
{

	int m1=MAXINT,m2=MAXINT;
	for(int j=1;j<pos;j++){
		if(pht->ht[j].weight<m1 && pht->ht[j].parent ==0){
			m2=m1;
			*x2=*x1;
			m1 = pht->ht[j].weight;
			*x1=j;
		}
		else if(pht->ht[j].weight<m2 && pht->ht[j].parent == 0){
			m2=pht->ht[j].weight;
			*x2=j;
		}
	}
}

void Code(PHTree pht,char *taget,int n,int *w,char *chs)
{

	int le=strlen(taget);
	for (int i = 0; i <le ; ++i)
	{
		int j,cntemp=0;
		char temp[100];
		for ( j = 0; j < n; ++j)
		{
			if(chs[j]==taget[i])break;
		}
		int c=j+1,f;
		for(f = pht->ht[j+1].parent; f!=0 ;c=f,f=pht->ht[f].parent){
			if(pht->ht[f].lch == c)temp[cntemp++]='0';
			else temp[cntemp++]='1';
		}
		while(--cntemp)
            cout<<temp[cntemp];
		cout<<temp[cntemp];
	}
	cout<<endl;

}
