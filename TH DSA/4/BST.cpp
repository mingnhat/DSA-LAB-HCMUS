#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
struct NODE{
int key;
NODE* left;
NODE* right;
};

NODE* createNode(int data)
{
    NODE* root=new NODE;
    root->right=nullptr;
	root->left=nullptr;
	root->key=data;
    return root;
}
void Insert(NODE* &pRoot, int x)
{
if(pRoot==nullptr)
{
    pRoot=new NODE;
    pRoot->left=nullptr;
    pRoot->right=nullptr;
    pRoot->key=x;

}
else
{
    if(x<pRoot->key) Insert(pRoot->left,x);
    else if(x>pRoot->key) Insert(pRoot->right,x);
}
}
void NLR(NODE* pRoot)
{
    if(pRoot)
    {
    cout<<pRoot->key<<" ";
    NLR(pRoot->left);
    NLR(pRoot->right);
    }
}
void LNR(NODE* pRoot)
{
    if (pRoot)
    {
        LNR(pRoot->left);
        cout << pRoot->key<<" ";
        LNR(pRoot->right);
    }

}
void LRN(NODE* pRoot)
{
    if (pRoot)
    {
        LNR(pRoot->left);
        LNR(pRoot->right);
        cout << pRoot->key<<" ";
    }
}
int max1(int a,int b){
    if(a>b) return a;else return b;
}
int level(NODE* pRoot)
{
    if(!pRoot) return 0;
    return 1+ max1(level(pRoot->left),level(pRoot->right));
}
int countNode(NODE* pRoot)
{
    if(!pRoot)return 0;
    return 1+countNode(pRoot->left)+countNode(pRoot->right);
}
int sumNode(NODE* pRoot)
{
    if(pRoot==nullptr)
        return 0;
    return sumNode(pRoot->left)+sumNode(pRoot->right)+pRoot->key;

}
NODE* Search(NODE* pRoot, int x)
{
    if(pRoot)
    {
        if(pRoot->key==x) return pRoot;
        if(x<pRoot->key) return pRoot->left;
        if(x>pRoot->key) return pRoot->right;
    }
return pRoot;
}
void Remove(NODE* &pRoot, int x)
{
    if(pRoot)
    {
        if(x<pRoot->key) return Remove(pRoot->left,x);
        if(x>pRoot->key) return Remove(pRoot->right,x);
        if(!pRoot->left&&!pRoot->right) delete pRoot;
        else if(!pRoot->left)
        {
          NODE* ptmp=pRoot;
          pRoot=pRoot->right;
          delete ptmp;
        }
        else if(!pRoot->right)
        {
            NODE* ptmp=pRoot;
            pRoot=pRoot->left;
            delete ptmp;
        }
        else
        {
          NODE* ptmp=pRoot->right;
          while(ptmp->left)
          {
             ptmp=ptmp->left;
          }
          pRoot->key=ptmp->key;
          Remove(pRoot->right,ptmp->key);
        }
    }
}
void check_remove(NODE* pRoot, int x)
{
    if(Search(pRoot,x)!=nullptr) Remove(pRoot,x);
    else cout<<"can't find value need to remove";
}
NODE* secondlargest(NODE* pRoot)
{
    if(pRoot)
    {
        while(pRoot->right->right&&pRoot->right->left)
        {
            pRoot=pRoot->right;
        }
        if(!pRoot->right->right&&!pRoot->right->left) return pRoot;
        else if(pRoot->right->left)
        {
            NODE*ptmp=pRoot->right->left;
            while(ptmp->right)
            {
                ptmp=ptmp->right;
            }
            return ptmp;
        }
        else
        {
            NODE* ptmp=pRoot->right;
            return secondlargest(ptmp);
        }
    }
    else return pRoot;
}
void MaxNodeChan(NODE* pRoot,int &Max)
{
    if(pRoot->key %2 == 0 && pRoot->key > Max)
    {
        Max=pRoot->key;
    }
    if(pRoot->left!=nullptr)
        MaxNodeChan(pRoot->left,Max);
    if(pRoot->right!=nullptr)
        MaxNodeChan(pRoot->right,Max);
}
int GiaTriMaxNodeChan(NODE* pRoot)
{
    int MAX=-99999;
    MaxNodeChan(pRoot,MAX);
    return MAX;
}
void deleteNode(NODE* pRoot)
{
if(pRoot)
{
    deleteNode(pRoot->left);
    deleteNode(pRoot->right);
    delete pRoot;
}
pRoot=nullptr;
}
void create_Tree_with_array(int a[], int n)
{
    NODE* proot=nullptr;
    for(int i=0;i<n;i++){
        if(!proot)
        {
            proot=createNode(a[i]);
        }
        else
        {
            Insert(proot,a[i]);
        }
    }
    LNR(proot);
}
int heightNode(NODE* pRoot, int value)
{
    int a=1;
while(pRoot->key!=value){
    if(pRoot->key<value){
        pRoot=pRoot->right;
        a+=1;
    }
    if(pRoot->key>value){
        pRoot=pRoot->left;
        a+=1;
    }   
    }
    return a;
}
int Level(NODE* pRoot, NODE* p)
{
    int a=1;
while(pRoot->key!=p->key){
    if(pRoot->key<p->key){
        pRoot=pRoot->right;
        a+=1;
    }
    if(pRoot->key>p->key){
        pRoot=pRoot->left;
        a+=1;
    }   
    }
    return a;
}
int countLess(NODE* pRoot, int x)
{
	if(pRoot==nullptr)
		return 0;
	queue<NODE*> que;
	que.push(pRoot);
	NODE*p;
	int i=0;
	while (!que.empty())
	{
		p=que.front();
		if(p->left!=nullptr)
			que.push(p->left);
		if(p->right!=nullptr)
			que.push(p->right);
		if(p->key < x)
			i++;
		que.pop();

	}
	return i;
}
int countGreater(NODE* pRoot, int x)
{
	if(pRoot==nullptr)
		return 0;
	queue<NODE*> que;
	que.push(pRoot);
	NODE*p;
	int i=0;
	while (!que.empty())
	{
		p=que.front();
		if(p->left!=nullptr)
			que.push(p->left);
		if(p->right!=nullptr)
			que.push(p->right);
		if(p->key>x)
			i++;
		que.pop();

	}
	return i;
}
int minnode(NODE* proot) {
	if (proot == nullptr)return 100000;
	return min(min(proot->key, minnode(proot->left)), minnode(proot->right));
}
int maxnode(NODE* proot) {
	if (proot == nullptr)return -100000;
	return max(max(proot->key, maxnode(proot->left)), maxnode(proot->right));
}
bool isBST(NODE* pRoot) {
	if (pRoot == nullptr)return true;
	if (pRoot->key<minnode(pRoot->right ) && pRoot->key>maxnode(pRoot->left))
		return isBST(pRoot->left) && isBST(pRoot->right);
	return false;
}

bool isFullBST(NODE* pRoot)
{
    if(pRoot==nullptr) return true;
    if(pRoot->left==nullptr && pRoot->right==nullptr)
        return true;
    if(pRoot->left!=nullptr && pRoot->right!=nullptr && isBST(pRoot))
        return isFullBST(pRoot->left) && isFullBST(pRoot->right);
}
int countLeaf(NODE* proot)
{
    if(proot==nullptr) return 0;
    if(proot->left==nullptr&& proot->right==nullptr) return 1 ;
    return countLeaf(proot->left)+countLeaf(proot->right);
}
void pre_order_travelsal(NODE* proot) {
	if (proot == nullptr)return;
	cout << proot->key << " ";
	pre_order_travelsal(proot->left);
	pre_order_travelsal(proot->right);
}
int getheight(NODE* proot) {
	if (proot == nullptr)return 0;
	return 1 + max(getheight(proot->left), getheight(proot->right));
}

void print_current_level(NODE* proot, int level) {
	if (proot == nullptr)return;
	else if (level == 1)cout << proot->key << " ";
	else if (level > 1) {
		print_current_level(proot->left, level - 1);
		print_current_level(proot->right, level - 1);
	}
}

void print_level_traversal(NODE* proot) {
	if (proot == nullptr)return;
	int h = getheight(proot);
	for (int i = 1; i <= h; i++) {
		print_current_level(proot, i);
	}
}
int main()
{
    int x;
     cout<<"pls input integer(0.stop) ";
     cin>>x;
     NODE* p=createNode(x);
      cout<<"pls input integer(0.stop) ";
      cin>>x;
     while(x!=0){
        Insert(p,x);
        cout<<"pls input integer(0.stop) ";
         cin>>x;
     }

// cout<<"NLR\n";
// NLR(p);
// cout<<"\nLNR\n";
// LNR(p);
// cout<<"\nLRN\n";
// LRN(p);
// cout<<"\nlevel: ";
// cout<<level(p);
// cout<<"\namount Node: ";
// cout<<countNode(p);
// cout<<"\ntotal: ";
// cout<<sumNode(p);
// cout<<"\ninput value need to find:";
// cin>>x;
// NODE* px=Search(p,x);
// if(px) cout<<"\nyes";
// else cout<<"\nno\n";
// LNR(p);
// cout<<"\nsecond largest is:\n";
// NODE* pxy=secondlargest(p);
// cout<<pxy->key;
// cout<<"\npls input amount elements: ";
// cin>>x;
//  int a[50];
// for(int i=0;i<x;i++){
//     cout<<"a["<<i<<"]= ";
//     cin>>a[i];
// }
// create_Tree_with_array(a,x);
// cout<<"\npls input int need to get height: ";
// cin>>x;
// cout<<heightNode(p,x);
//cout<<"\namount of leaf node: ";
//cout<<countLeaf(p);
// cout<<"\ncount less ";
// cout<<"\ninput value ";
// cin>>x;
// cout<<countLess(p,x);
// cout<<"\ncount greater ";
// cout<<"\ninput value ";
// cin>>x;
// cout<<countGreater(p,x);
// cout<<"\nis bst ";
// cout<<isBST(p);
// cout<<"\nis Full BST ";
// cout<<isFullBST(p);
//cout<<GiaTriMaxNodeChan(p);
//print_level_traversal(p)  //in theo level
deleteNode(p);
}
