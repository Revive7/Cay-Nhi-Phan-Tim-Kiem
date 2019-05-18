#include<iostream>
using namespace std;
 //Vo Nguyen Xuan Quynh
 //1751060480
 //thptso1pm@gmail.com
struct node
{
	int data; 
	struct node *pLeft; 
	struct node *pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;
void Create(TREE &t)
{
	t = NULL;
}


void InsertNODE(TREE &t, int x)
{
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (x < t->data)
		{
			InsertNODE(t->pLeft, x);
		}
		else if (x > t->data)
		{
			InsertNODE(t->pRight, x);
		}
	}
}

void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}
void LNR(TREE t)
{
	if (t != NULL)
	{
	
		LNR(t->pLeft);	
		cout << t->data << "  ";
		LNR(t->pRight);
	}
}
void LRN(TREE t)
{
	if (t != NULL)
	{
		
		LRN(t->pLeft);
		LRN(t->pRight);
		cout << t->data << "  ";
	}
}

void SearchStandFor(TREE &X, TREE &Y)
{
	if (Y->pLeft != NULL)
	{
		SearchStandFor(X, Y->pLeft);
	}
	else 
	{
		X->data = Y->data; 
		X = Y; 
	}
}

void DelNODE(TREE &t, int data) 
{
	if (t == NULL)
	{
		return; 
	}
	else
	{
		if (data < t->data)
		{
			DelNODE(t->pLeft, data); 
		}
		else if (data > t->data)
		{
			DelNODE(t->pRight, data);  
		}
		else 
		{
			NODE *X = t; 
			if (t->pLeft == NULL)
			{				
				t = t->pRight; 
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else 
			{
				SearchStandFor(X, t->pRight);				
			}
			delete X; 
		}
	}
}
void Menu(TREE &t)
{
	int choose;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =================== MENU ==================";
		cout << "\n1. Nhap phan tu";
		cout << "\n2. Xoa phan tu bat ki";
		cout << "\n3. Duyet theo thu tu truoc";
		cout << "\n4. Duyet theo thu tu giua";
		cout << "\n5. Duyet theo thu tu sau";
		cout << "\n6. Xoa nut goc";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t ===================  END  ==================";

		cout << "\nNhap lua chon: ";
		cin >> choose;

		if (choose == 1)
		{
			int x;
			cout << "\nNhap gia tri: ";
			cin >> x;
			InsertNODE(t, x);
		}
		else if (choose == 2)
		{
			int x;
			cout << "\nNhap gia tri can xoa: ";
			cin >> x;
			DelNODE(t, x);
		}	
		else if (choose == 3)
		{
			cout << "\n\t CAY NHI PHAN TIM KIEM\n";
			NLR(t);
			system("pause");
		}
		else if (choose == 4)
		{
			cout << "\n\t CAY NHI PHAN TIM KIEM\n";
			LNR(t);
			system("pause");
		}
		else if (choose == 5)
		{
			cout << "\n\t CAY NHI PHAN TIM KIEM\n";
			LRN(t);
			system("pause");
		}
		else
		{
			break;
		}
	}
}


int main()
{
	TREE t;
	Create(t);
	Menu(t);

	system("pause");
	return 0;
}
