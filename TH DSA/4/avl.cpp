#include<iostream>

using namespace std;
struct NODE
{
	int data;
	NODE* pleft;
	NODE* pright;
};
NODE* create_node(int n) {
	NODE* p = new NODE;
	p->data = n;
	p->pleft = nullptr;
	p->pright = nullptr;
	return p;
}

int height(NODE* proot) {
	if (proot == nullptr)return 0;
	else {
		return 1 + max(height(proot->pleft), height(proot->pright));
	}
}


void right_rotate(NODE*& proot) {
	NODE* p = proot->pleft;
	proot->pleft = p->pright;
	p->pright = proot;
	proot = p;
}

void left_rotate(NODE*& proot) {
	NODE* p = proot->pright;
	proot->pright = p->pleft;
	p->pleft = proot;
	proot = p;
}


void insert(NODE*& proot, int n) {
	if (proot == nullptr) {
		proot = create_node(n);
		return;
	}
	else if (n < proot->data) insert(proot->pleft, n);
	else if (n > proot->data)insert(proot->pright, n);
	else if (n == proot->data)return;
	int balance = height(proot->pleft) - height(proot->pright);
	// mat can bang trai
	if (balance > 1) {
		//left left case
		if (height(proot->pleft->pleft) > height(proot->pleft->pright)) {
			right_rotate(proot);
		}
		//left right case
		else if (height(proot->pleft->pleft) < height(proot->pleft->pright)) {
			left_rotate(proot->pleft);
			right_rotate(proot);
		}
	}
	//mat can bang phai
	else if (balance < -1) {
		//right right case
		if (height(proot->pright->pright) > height(proot->pright->pleft)) {
			left_rotate(proot);
		}
		//right left case
		else if (height(proot->pright->pright) < height(proot->pright->pleft)) {
			right_rotate(proot->pright);
			left_rotate(proot);
		}
	}

}

NODE* search(NODE* proot, int x)
{
	if (!proot) return proot;
	if (proot->data == x) return proot;
	if (proot->data > x)return search(proot->pleft, x);
	return search(proot->pright, x);
}

void Remove(NODE* &pRoot, int x){
	if(pRoot == nullptr)
		return;
	if(pRoot->data > x)
		Remove(pRoot->pleft, x);
	if(pRoot->data < x)
		Remove(pRoot->pright, x);
	if(pRoot->data == x){
		//TH1 Node la  
		if(pRoot->pleft == nullptr && pRoot->pright == nullptr){
			delete pRoot; // xoa roi nhung van mang gia tri rac nen gan no bang NULL
			pRoot = nullptr;
			//return;
		}
		//TH2 cay con phai
		else if(pRoot->pleft == nullptr && pRoot->pright != nullptr){
			NODE* p = pRoot;
			pRoot = pRoot->pright;
			delete p;
			//return;
		}
		//TH2 Cay con phai
		else if(pRoot->pleft != nullptr && pRoot->pright == nullptr){
			NODE* p = pRoot;
			pRoot = pRoot->pleft;
			delete p;
			//return;
		}
		//TH3 Node co 2 con
		else if(pRoot->pleft != nullptr && pRoot->pright != nullptr){
			NODE* p = pRoot->pleft;
			while(p->pright != nullptr){
				p = p->pright;
			}
			pRoot->data = p->data;
			Remove(pRoot->pleft, pRoot->data);
		}
	}
    //Đi can bang
	if (pRoot == nullptr)
		return;
	int balance = height(pRoot->pleft) - height(pRoot->pright);
	// Mất can bang trai
	if (balance >= 2)
	{
		// Mất can bang trai trai
		if (height(pRoot->pleft->pleft) > height(pRoot->pright)) 
			right_rotate(pRoot);
		// Mất can bang trai phai
		else if (height(pRoot->pleft->pleft) < height(pRoot->pleft->pright)) 
		{
			left_rotate(pRoot->pleft);
			right_rotate(pRoot);
		}
		}
	// Mất can bang phai
	if (balance <= -2)
	{
		if (height(pRoot->pright->pright) > height(pRoot->pleft))
		{ // Mất can bang phai phai
			left_rotate(pRoot);
		}
		else if (height(pRoot->pright->pright) < height(pRoot->pright->pleft))
		{ // Mất can bang phai trai
			right_rotate(pRoot->pright);
			left_rotate(pRoot);
		}
	}
}
//19. * Determine if a given Binary Tree is Binary Search Tree:
int minnode(NODE* proot) {
	if (proot == nullptr)return 100000;
	return min(min(proot->data, minnode(proot->pleft)), minnode(proot->pright));
}
int maxnode(NODE* proot) {
	if (proot == nullptr)return -100000;
	return max(max(proot->data, maxnode(proot->pleft)), maxnode(proot->pright));
}

bool isBST(NODE* proot) {
	if (proot == nullptr)return true;
	if (proot->data<minnode(proot->pright) && proot->data>maxnode(proot->pleft))
		return isBST(proot->pleft) && isBST(proot->pright);
	return false;
}

bool isAVL(NODE* proot) {
	int balance = height(proot->pleft) - height(proot->pright);
	if (balance > 1 || balance < -1)return false;
	if (proot->pleft != nullptr)isAVL(proot->pleft);
	if (proot->pright != nullptr)isAVL(proot->pright);
	if (balance == 1 || balance == 0 || balance == -1)
		return true;
}



void pre_order_travelsal(NODE* proot) {
	if (proot == nullptr)return;
	cout << proot->data << " ";
	pre_order_travelsal(proot->pleft);
	pre_order_travelsal(proot->pright);
}
int getheight(NODE* proot) {
	if (proot == nullptr)return 0;
	return 1 + max(getheight(proot->pleft), getheight(proot->pright));
}

void print_current_level(NODE* proot, int level) {
	if (proot == nullptr)return;
	else if (level == 1)cout << proot->data << " ";
	else if (level > 1) {
		print_current_level(proot->pleft, level - 1);
		print_current_level(proot->pright, level - 1);
	}
}

void print_level_traversal(NODE* proot) {
	if (proot == nullptr)return;
	int h = getheight(proot);
	for (int i = 1; i <= h; i++) {
		print_current_level(proot, i);
	}
}

int main() {
	
	NODE* proot = nullptr;
	int n;
	cout << "input n(exit n=0)";
	cin >> n;
	while (n != 0) {
		insert(proot, n);
		cout << "input n(exit n=0)";
		cin >> n;
	}
	print_level_traversal(proot);
	/*if (isBST(proot) == true) {
		if (isAVL(proot) == true)cout << "true";
		else cout << "false";
	}
	else if(isBST(proot)==false) cout << "false";*/
	cout << "input value to remove: ";
	cin >> n;
	Remove(proot, n);
	pre_order_travelsal(proot);
	return 0;
}
