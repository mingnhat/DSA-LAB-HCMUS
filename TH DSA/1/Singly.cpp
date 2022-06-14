#include <iostream>
using namespace std;

struct NODE
{
    int key;
    NODE *p_next;
};
struct List
{
    NODE *p_head;
    NODE *p_tail;
};
NODE *createNode(int data)
{
    NODE *n = new NODE;
    n->key = data;
    n->p_next=nullptr;
    return n;
}
List *createList(NODE *p_node)
{
    List *l = new List;
    l->p_head = p_node;
    l->p_tail = l->p_head;
    return l;
}

//Stack push
bool addHead(List *&L, int data)
{
    NODE *n = createNode(data);
    if (L == nullptr)
        L = createList(n);
    else
    {
        n->p_next = L->p_head;
        L->p_head = n;
    }
    return true;
}

//Queue enque
bool addTail(List *&L, int data)
{
    if (L == nullptr)
    {
        createList(createNode(data));
    }
    else
    {
        L->p_tail->p_next = createNode(data);
        L->p_tail = L->p_tail->p_next;
    }
     return true;
}

//stack pop
//queue dequeue
void removeHead(List *&L)
{
    if (L == nullptr)
        return;
    if (L->p_head->p_next)
    {
        NODE *temp = L->p_head;
        L->p_head = L->p_head->p_next;
        delete temp;
    }
    else
        L->p_head = nullptr;
}
void removeTail(List*&L)    
{
	if (L->p_head == nullptr)
		return;
	NODE* p = L->p_head;
	while (p->p_next->p_next != nullptr)
	{
		p = p->p_next;
	}
	NODE* temp = L->p_tail;
	L->p_tail = p;
	L->p_tail->p_next = nullptr;
	delete temp;
}
void removeAll(List *&L)
{
    if(L->p_head==nullptr) return;
    while (L->p_head != nullptr)
    {
       removeHead(L);
    }
    L->p_tail = nullptr;
    L->p_head = nullptr;
}

void removeBefore(List*& l, int val)
{
	if (l->p_head == nullptr)
		return;
	if (l->p_head->p_next->key == val)
		removeHead(l);
    else
    {
        NODE* p = l->p_head;
        NODE* cur = l->p_head->p_next;
        while (cur->p_next != nullptr) 
        {
            if (cur->p_next->key == val) {
                NODE* temp = cur;
                p->p_next = cur->p_next;
                cur = cur->p_next;
                delete temp;
                break;
            }
            else {
                p = cur;
                cur = cur->p_next;
            }
        }
    }
}
void printList(List *L)
{

    NODE *cur = L->p_head;
    while (cur)
    {
        cout << cur->key << " ";
        cur = cur->p_next;
    }
    cout << endl;
}
void removeAfter(List *&l, int val)
{
    if (l->p_head == nullptr)
    return;
	NODE* p = l->p_head;
	NODE* cur = l->p_head->p_next;
	while (cur->p_next != nullptr) {
		if (p->key == val) {
			NODE* temp = cur;
			p->p_next = cur->p_next;
			cur = cur->p_next;
			p = cur;
			delete temp;
		}
		else {
			p = cur;
			cur = cur->p_next;
		}
	}
    if(p->key==val && p->p_next==l->p_tail)
    {
        removeTail(l);
    }
}
int countElements(List *L)
{
    NODE *cur = L->p_head;
    int i = 0;
    while (cur)
    {
        cur = cur->p_next;
        i++;
    }
    return i;
}
bool addPos(List *&L, int data, int pos)
{
    if (pos == 0)
    {
        addHead(L, data);
        return true;
    }
    else if(pos==countElements(L))
    {
        addTail(L,data);
        return true;
    }
    NODE *cur = L->p_head;
    for (int i = 0; i < pos - 1; i++)
    {
        cur = cur->p_next;
    }
    NODE *temp = new NODE;
    temp->key = data;
    temp->p_next = cur->p_next;
    cur->p_next = temp;
    return true;
}
void RemovePos(List *&L, int pos)
{
    if (pos == 1)
    {
        removeHead(L);
        return;
    }
    NODE *cur = L->p_head;
    for (int i = 0; i < pos - 1; i++)
    {
        cur = cur->p_next;
    }
    NODE *temp = cur->p_next;
    cur->p_next = cur->p_next->p_next;
    if(cur->p_next==nullptr) L->p_tail=cur;
    delete (temp);
}
bool addBefore(List *&L, int data, int val)
{
    NODE *cur = L->p_head;
    if (cur->key == val)
    {
        addHead(L, data);
        return true;
    }

    while (cur->p_next && cur->p_next->key != val)
    {
        cur = cur->p_next;
    }
    if (!cur->p_next)
        return false;
    NODE *temp = new NODE;
    temp->key = data;
    temp->p_next = cur->p_next;
    cur->p_next = temp;
    return true;
}
bool addAfter(List *&L, int data, int val)
{
    if (!L)
        return false;
    NODE *cur = L->p_head;
    while (cur && cur->key != val)
    {
        cur = cur->p_next;
    }
    if (!cur)
        return false;
    NODE *temp = new NODE;
    temp->key = data;
    temp->p_next = cur->p_next;
    cur->p_next = temp;
    if(temp->p_next==nullptr) L->p_tail=temp;
    return true;
}

List *reverseList(List *L)
{
    NODE *cur = L->p_head;
    NODE *prev = nullptr;
    NODE *next = nullptr;
    L->p_tail=L->p_head;
    while (cur)
    {
        next = cur->p_next;
        cur->p_next = prev;
        prev = cur;
        cur = next;
    }
    L->p_head = prev;
    return L;
}
void removeDuplicate(List*& l)
{
	if (l->p_head == nullptr)
		return;
	NODE* pCur = l->p_head;
	while (pCur != nullptr)
	{
		NODE* pPrev1 = pCur;
		NODE* pCur1 =pCur->p_next;
        if(l->p_tail->key==pCur->key)
        {
        while(l->p_tail->key==pCur->key)
        {
            if(pCur == l->p_tail)
            break;
             removeTail(l);
        }
        }
        else
        {
		while (pCur1 != nullptr)
		{
			if (pCur1->key == pCur->key)
			{
				NODE* pTmp = pCur1;
				pPrev1->p_next = pCur1->p_next;
				pCur1 = pCur1->p_next;
				delete pTmp;
			}
			else
			{
				pPrev1 = pCur1; 
				pCur1 = pCur1->p_next;
			}
		}
        }
		pCur = pCur->p_next;
	}
}

bool removeElement(List *&L, int key)
{
    while (L->p_head->key == key)
    {
        removeHead(L);

    }
    NODE* cur=L->p_head;
    while (cur->p_next)
    {

       if (cur->p_next->key == key)
        {
            NODE *temp = cur->p_next;
            cur->p_next = cur->p_next->p_next;
            delete (temp);
        }
        else
            cur = cur->p_next;
    }
    L->p_tail=cur;
    return true;
}

int main()
{
    List *myList = nullptr;
    NODE *myNode;
    myNode = createNode(233);
    myList = createList(myNode);
    int x=0,y=0;
    cout<<"pls input int(0=stop) ";
    cin>>x;
    while(x!=0){
    addHead(myList, x);
    cout<<"pls input int(0=stop) ";
    cin>>x;
    }
    printList(myList);
     cout<<"\nadd head:\n";    //cau 3
    cout<<"input data: ";
    cin>>x;
    addHead(myList,x);
    printList(myList);
    cout<<"\nadd tail:\n";    //cau 4
    cout<<"input data: ";
    cin>>x;
    addTail(myList,x);
    printList(myList);
    cout<<"\nremove head ";        //cau 5
    removeHead(myList);
    printList(myList);
    cout<<"\nremove tail ";    //cau 6
    printList(myList);
   cout<<"\npls input to remove before ";    //cau 7
   cin>>x;  
    removeBefore(myList, x);
    printList(myList);
    cout<<"\npls input to remove after ";cin>>x;    //cau 8
    removeAfter(myList, x);
    printList(myList);
    cout<<"\npls input position and value to insert after ";cin>>x>>y;     //cau 9
    addPos(myList, y, x);
     printList(myList);
    cout<<"\npls input position to remove value ";    //cau 10
    cin>>x;
    RemovePos(myList,x);
    printList(myList);
    cout<<"\npls input value and value insert to insert before " ;cin>>x>>y;    //cau 11
    addBefore(myList, y, x);
     printList(myList);
     cout<<"\npls input value and value insert to insert after " ;cin>>x>>y;    //cau 12
    addAfter(myList, y, x);
     printList(myList);
     cout<<"\namount of element: ";    //cau 13
    cout << countElements(myList);
    cout<<"\nremove duplicate elements: ";    //cau 14
    removeDuplicate(myList);
     printList(myList);
    cout<<"pls input int to remove elements: ";    //cau 15
    cin>>x;
    removeElement(myList,x);
     printList(myList);
    cout<<endl;
    cout<<"\nreverse List";    //cau 17
    reverseList(myList);
    printList(myList);
    removeAll(myList);    //cau 18
}
