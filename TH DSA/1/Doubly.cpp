#include<iostream>
using namespace std;
struct node
{
	int data;
	node* pnext;
    node* pprev;
};
struct list {
	node* phead;
	node* ptail;
};
node* createnode(list*& l)
{
            node* head=NULL;
            l-> phead= new node;				
			head = l->phead;
            head->pprev=NULL;
            return head;
}

void createlist( list*& l)
{
	node* head=NULL;
    int t;
	cout << "enter value of link list(0 is stop) ";
	cin >> t;
	while (t != 0)
	{
		if (l->phead == NULL)
		{
			head=createnode(l);
		}
		else
		{
			head->pnext = new node;
            head->pnext->pprev=head;
			head = head->pnext;
		}
        head->pnext = NULL;
		head->data = t;
		cout << "enter value of link list ";
		cin >> t;
	}
    l->ptail = head;
}
void display_list(list* l)
{
	node* head = NULL;
	head = l->phead;
	if (head == NULL) return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->pnext;
	}
}
void addhead(list*& l,int data){
if(!l->phead) return ;
node* p= new node;
p->data=data;
p->pnext= l->phead;
p->pprev=NULL;
l->phead->pprev=p;
l->phead=p;

}
void  addtail(list*& l,int data){
    if(!l->phead) return ;
    node* p=new node;
    p->data=data;
p->pnext=NULL;
p->pprev=l->ptail;
l->ptail->pnext=p;
l->ptail=p;
}
void removehead(list*& l){
    node* p=l->phead->pnext;
    delete l->phead;
    l->phead=p;
    l->phead->pprev=NULL;
}
void removetail(list*& l)
{
    node* p=l->ptail->pprev;
    delete l->ptail;
    l->ptail=p;
    l->ptail->pnext=NULL;
    
}
void removeallnode(list*& l){
    if(l->phead==NULL) return;
    node* p=l->phead;
    while(p)
    {
        node* ptmp=p->pnext;
        delete ptmp;
        p=ptmp;
    }
    l->phead=NULL;;
    l->ptail=NULL;
}
void removebefore_x(list*& l,int data)
{
    if(l->phead==NULL) return;
    node* p=l->phead;
    p=p->pnext;
    while(p)
    {
        if(p->data==data)
        {
            node* ptmp=p->pprev;
            p->pprev->pprev->pnext=p;
            p->pprev=p->pprev->pprev;
            delete ptmp;
            return;
        }
        else p=p->pnext;  
    }
    if(l->phead->pnext->data==data)
    {
      removehead(l);
    }
    cout<<"cant find value need to remove in list";
}
void removeafter_value(list*& l,int data)
{
    if(l->phead==NULL) return;
    node* p=l->phead;
    while(p&&p->pnext!=l->ptail)
    {
        if(p->data==data)
        {
            node* ptmp=p->pnext;
            p->pnext=p->pnext->pnext;
            p->pnext->pprev=p;
            delete ptmp;
            return;
        }
        else p=p->pnext;  
    }
    if(p->data==data)
{
       p->pnext=NULL;
       delete l->ptail;
       l->ptail=p;
       return;
}   
 cout<<"cant find value need to remove in list";
}
void addpos(list*& l,int data,int pos)
{
    if(l->phead==NULL) return ;
    if(pos==1)
    {
addhead(l,data); return ;
    }  
    node* p=l->phead;
    while(p)
    {
      if(pos==2)
      {
        node* px=new node;
        px->data=data;
        px->pnext=p->pnext;
        px->pprev=p;
        p->pnext->pprev=px;
        p->pnext=px;   
        return;
      }
          pos--;
          p=p->pnext;
    }
     cout<<"errol because position  is greater than the number of nodes in the list";
}
void removepos(list*& l, int pos)
{
     if(l->phead==NULL) return ;
    if(pos==1)
    {
     removehead(l); return ;
    }  
    node* p=l->phead; 
    while(p)
    {
      if(pos==1)
      {
            node* ptmp=p;
           p->pnext->pprev=p->pprev;
           p->pprev->pnext=p->pnext;    
            delete ptmp;
        return;
      }
      else 
      {
          pos--;
          p=p->pnext;
      }
    }
     cout<<"errol because position  is greater than the number of nodes in the list";
}
void insertbefore(list*& l,int data,int value)
{
if(l->phead==NULL) return;
if(l->phead->data==value)
{
    addhead(l,data);
    return;
}
node* p=l->phead;
while(p&&p->data!=value)
{
p=p->pnext;
}
if(!p) return;
node* px=new node;
px->data=data;
px->pnext=p;
px->pprev=p->pprev;
p->pprev->pnext=px;
p->pprev=px;
}
void insertafter(list*& l,int data,int value)
{
if(l->phead==NULL) return;
node* p=l->phead;
while(p&&p->data!=value)
{
p=p->pnext;
}
if(!p) return;
if(p==l->ptail) addtail(l,data);
else{
node* px=new node;
px->data=data;

        px->pnext=p->pnext;
        px->pprev=p;
        p->pnext->pprev=px;
        p->pnext=px;
}

}
int countnode(list*& l)
{
    if(l->phead==NULL) return 0;
    node* p=l->phead;
    int a=0;
    while(p)
    {
        a++;
        p=p->pnext;
    }
    return a;
}
void reverselist(list*& l)
{
    if(l->phead==NULL) return;
    node* px=l->ptail;
    while(px)
    {
        cout<<px->data<<" ";
        px=px->pprev;
    }

}
void removeduplicate(list*& l)
{
	if (l->phead == NULL)
		return;
	node* pCur = l->phead;
	while (pCur->pnext != NULL)
	{
		node* pPrev1 = pCur;
		node* pCur1 =pCur->pnext;
        if(pCur->data==l->ptail->data)
        {
            removetail(l);
        }
		while (pCur1 != NULL)
		{
			if (pCur1->data == pCur->data)
			{
                if(pCur1->pnext!=NULL)
                {
				node* pTmp = pCur1;
				pPrev1->pnext = pCur1->pnext;
				pCur1 = pCur1->pnext;
                pCur1->pprev=pPrev1;
				delete pTmp;
                }
                else removetail(l);
			}
			else
			{
				pPrev1 = pCur1; 
				pCur1 = pCur1->pnext;
			}
		}
		pCur = pCur->pnext;
	}
}

bool removeelement(list *&L, int key)
{
    while (L->phead->data == key)
    {
        removehead(L);
    }
    while(L->ptail->data == key)
    {
        removetail(L);
    }
    node* cur=L->phead;
    while (cur->pnext) 
    {
       if (cur->pnext->data == key) 
        {
            node *temp = cur->pnext; 
            cur->pnext = cur->pnext->pnext; 
            temp->pnext->pprev=cur;
            delete (temp);
        }
        else
            cur = cur->pnext;
    }
    return true;
}
int main()
{
    list* l=new list;
    l->phead=NULL;l->ptail=NULL;
    int data=0,value=0;
    createlist(l);
    cout<<"list:\n";
    display_list(l);
    // cout<<"\nadd head:\n";    //cau 3
    // cout<<"input data: ";
    // cin>>data;
    // addhead(l,data);
    // display_list(l);
    // cout<<"\nadd tail:\n";    //cau4
    // cout<<"input data: ";
    // cin>>data;
    // addtail(l,data);
    // display_list(l);
    // cout<<"\nremove head:\n";   //cau 5
    // removehead(l);
    // display_list(l);
    // cout<<"\nremove tail:\n";   //cau 6
    // removetail(l);
    // display_list(l);
    // cout<<"\nremove before:\n";   //cau 8
    // cout<<"input value ";
    // cin>>value;
    // removebefore_x(l,value);
    // display_list(l);
    // cout<<"\nremove after value \n";    //cau 9
    // cout<<"input value ";
    // cin>>value;
    // removeafter_value(l,value);
    // display_list(l);
    // cout<<"\nadd position\n ";    //cau 10
    // cout<<"input position ";
    // cin>>value;
    // cout<<"input data ";cin>>data;
    // addpos(l,data,value);
    // display_list(l);
    // cout<<"\nremove position\n ";    //cau 11
    // cout<<"input position ";
    // cin>>value;
    // removepos(l,value);
    // display_list(l);
    // cout<<"\nadd before value \n";    //cau 12
    // cout<<"input value to insert before ";
    // cin>>value;
    // cout<<"input data ";cin>>data;
    // insertbefore(l,data,value);
    // display_list(l);
    // cout<<"\ninsert after value \n";    //cau 13
    // cin>>value;
    // cout<<"input data ";
    // cin>>data;
    // insertafter(l,data,value);
    // display_list(l);
    // cout<<"\namount node: ";    //cau 14
    // cout<<countnode(l);
    // cout<<"\nreverse list\n";    //cau 15
    // reverselist(l);
    // cout<<"\nremove duplicate\n";    //cau 16
    // removeduplicate(l);
    // display_list(l);
    // cout<<"\nremove elements from list\n";    //cau 17
    // cout<<"input element ";
    // cin>>data;
    // removeelement(l,data);
    // display_list(l);
    // removeallnode(l);    //cau 18
}
