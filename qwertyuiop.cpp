// дерево мое ебаное мое.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <conio.h>
#include <clocale>

struct node
{
	int d;
	node*left;
	node*right;
};

node*p;
node*first()
{
	node*pv=new node;
	cout << endl << "Введите целое число" << endl;
	cin >> pv->d;
	pv->left=0;
	pv->right=0;
	return pv;
}

node*search(node*root, int d)
{
	node*pv=root, *prev;
	bool f = false;
	while(pv && !f){
		prev=pv;
		if(d==pv->d) f = true;
		else if(d<pv->d)pv=pv->left;
		else pv=pv->right;
	}
	if(f) return pv;
	node*pnew=new node;
	pnew->d=d;
	pnew->left=0;
	pnew->right=0;
	if(d<prev->d)
		prev->left=pnew;
	else
		prev->right=pnew;
	return pnew;
}

void print(node*p, int l)
{
	if(p)
	{
		print(p->left,l+1);
		for(int i=0;i<l;i++) cout << "  ";
			cout << p->d << endl;
		print(p->right,l+1);
	}
}

void SymmetricOrder_BinaryTree(node*p){
  if (p != NULL) {
    SymmetricOrder_BinaryTree(p->left);
    printf ("%3ld",p->d);
    SymmetricOrder_BinaryTree(p->right);
  }
}

void PostOrder_BinaryTree(node*p){
  if (p != NULL) {
    PostOrder_BinaryTree(p->left);
    PostOrder_BinaryTree(p->right);
    printf ("%3ld",p->d);
  }
}

bool  Empty_BinaryTree(node*p ){
  return ( p == NULL ? true : false );
}

void print_(node*p, int l, int el)
{
	if(p)
	{
		print_(p->left,l+1, el);
		for(int i=0;i<l;i++) cout << "  ";
		if(p->d!=el)
			cout << p->d << endl;
		else
			l+1;
		print_(p->right,l+1, el);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	node*root=first();
	int d,l;
	for(int i=1;i<7;i++)
	{
		cout << "Введите целое число" << endl;
		cin >> d;
		search(root,d);
	}
	print(root,0);
	cout<<"Симметрич обход:"<<endl;
	SymmetricOrder_BinaryTree(root);
	cout<<endl<<"Обрат обход"<<endl;
	PostOrder_BinaryTree(root);
	cout<<endl<<"Пустота"<<endl;
	Empty_BinaryTree(p);
	int el;
	cout <<endl<< "Введите элемент для удаления" << endl;
	cin >> el;
	print_(root,0,el);
	{
	cout<<" Добавление элемента:";
	cin >>d;
	search(root,d);
	}
	print(root,0);
	_getch();
}

