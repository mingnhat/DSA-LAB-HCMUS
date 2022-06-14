#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
void InputArray(int* &a, int& n)
{
	cout << "Nhap n= ";
	cin >> n;
	a = new int[n];
	cout << "Nhap mang:\n";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
}

void SwapValue(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}
void SortArray(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j])
			{
				SwapValue(a[i], a[j]);
			}
			if (a[i] % 2 == 1 && a[j] % 2 == 1 && a[i] < a[j])
			{
				SwapValue(a[i], a[j]);
			}
		}
	}
}
//1
void Swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
//2
int *sum(int* a, int* b)
{
	int* c = new int;
	*c =*a+ *b;
	return c;
}
int* findMax(int* a, int n)
{
	int* max = new int;
	*max = -9999;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >* max)
		{
		*max = a[i];
		}
	}
	return max;
}
int* findLongestAscendingSubarray(int* a, int n, int& length)
{
	int* start = new int;
	int max = 1;
	for (int i = 0; i < n-1;)
	{
		max = 1;	
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[j + 1])
			{
				max += 1;
			}
			else break;
		}
		if (max > length)
		{
			length = max;
			max = 1;
			*start = i + 1;
		}
		i += max;
	}
	return start;
}
void swapArrays(int* a, int* b, int& na, int& nb) {
	int nc = 0;
	if (na < nb) nc = nb; else nc = na;
	int* c=new int[nc];
	c = a;
	a = b;
	b = c;	
	SwapValue(na, nb);
	printArray(a, na);
	cout << endl;
	printArray(b, nb);
}
int* concatenate2Arrays(int* a, int* b, int na, int nb)
{
	int* c;
	c = new int[na + nb];
	int j = 0;
	for (int i = 0; i < na+nb; i++)
	{
		if (i < na)
		{
			c[i] = a[i];
		}
		else
		{
			c[i] = b[j];
			j++;
		}
	}
	return c;
}
int* merge2Arrays(int* a, int* b, int na, int nb, int& nc)
{
	nc=0;
	nc = na + nb;
	int* c = new int[nc];
	int j = 0;
	for (int i = 0; i < nc; i++)
	{
		if (i < na)
		{
			c[i] = a[i];
		}
		else
		{
			c[i] = b[j++];
		}
	}
	for (int i = 0; i< nc-1;i++)
	{
		for (int t = i + 1; t < nc; t++)
		{
			if (c[i] > c[t])
			{
				SwapValue(c[i], c[t]);
			}
		}
	}
	return c;
}
void generateMatrix1(int** &A, int& length, int& width)
{
	srand(time(NULL));
	cout << "Input length: ";
	cin >> length;
	cout << "Input width: ";
	cin >> width;
	A = new int*[width];
	for (int i = 0; i < width; i++)
	{
		A[i] = new int[length];
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			A[i][j] = rand() % (100-3+1)+3;
		}
	}
}
void Inputmatrix(int**& A, int& length, int& width)
{
	cout << "Input length: ";
	cin >> length;
	cout << "Input width: ";
	cin >> width;
	A = new int* [width];
	for (int i = 0; i < width; i++)
	{
		A[i] = new int[length];
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cin >> A[i][j];
		}
	}
}
int** generateMatrix2(int* a, int* b, int na, int nb)
{
	int** c;
	c = new int* [na];
	for (int i = 0; i < na; i++)
	{
		c[i] = new int[nb];
	}
	for (int i = 0; i < na; i++)
	{
		for (int j = 0; j < nb; j++)
		{
			c[i][j] = a[i] * b[j];
		}
	}
	return c;
}
void OutputMatrix(int** A, int length, int width)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
void swapcolums(int** a, int length, int width)
{
	int w1, w2;
	cout << "Input number colum 1: ";
	cin >> w1;
	cout << "Input number colum 2: ";
	cin >> w2;
	for (int i = 0; i < width; i++)
	{
		SwapValue(a[i][w1], a[i][w2]);
	}
}
void swaprows(int** a, int length, int width)
{
	int r1, r2;
	cout << "Input number row 1: ";
	cin >> r1;
	cout << "Input number row 2: ";
	cin >> r2;
	for (int i = 0; i < length; i++)
	{
		SwapValue(a[r1][i], a[r2][i]);
	}
}
int** transposeMatrix(int** a, int length, int width) //Nhap output thi nhap width,length
{
	int** b;
	b = new int* [length];
	for (int i = 0; i < length; i++)
	{
		b[i] = new int[width];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j <width; j++)
		{
			b[i][j] = a[j][i];
		}
	}

	return b;
}
int** concatenate2MatricesV(int** a, int** b, int length, int width)  //Nhap output thi nhap length*2,width
{
	int** c;
	c = new int*[width * 2];
	for (int i = 0; i < width * 2; i++)
	{
		c[i] = new int[length];
	}
	int t = 0;
	for (int i = 0; i < width * 2; i++)
	{
		if (i < width)
		{
			for (int j = 0; j < length; j++)
			{
				c[i][j] = a[i][j];
			}
		}
		else
		{
			for (int d = 0; d < length; d++)
			{
				c[i][d] = b[t][d];
			}
			t += 1;
		}
	}
	return c;
}


bool multiple2Matrices(int **a, int **b, int lengtha, int widtha, int lengthb, int widthb)
{
    if (widtha != lengthb)
        return false;
    int **A = new int *[lengtha];
    for (int i = 0; i < lengtha; i++)
    {
        A[i] = new int[widthb];
    }
    int i, j, k;
    for (i = 0; i < lengtha; i++)
    {

        for (j = 0; j < widthb; j++)
        {
            A[i][j] = 0;
            for (k = 0; k < widtha; k++)
                A[i][j] += a[i][k] * b[k][j];
        }
    }
    OutputMatrix(A, widthb, lengtha);
    return true;
}
int** concatenateVertical(int** a, int** b, int len, int wid)
{

	int** c;
	c = new int* [wid * 2];
	for (int i = 0; i < wid * 2; i++)
	{
		c[i] = new int[len];
	}
	int t = 0;
	int maxa = 0, maxb = 0;
	for (int i = 0; i < wid; i++)
	{
		for (int j = 0; j < len; j++)
		{
			maxa += a[i][j];
			maxb += b[i][j];
		}
		for (int i = 0; i < wid * 2; i++)
		{
			if (i < wid)
			{
				for (int j = 0; j < len; j++)
				{
					if (maxa > maxb)
					{
						c[i][j] = a[i][j];
					}
					else
					{
						c[i][j] = b[i][j];
					}
				}
			}
			else
			{
				for (int d = 0; d < len; d++)
				{
					if (maxa > maxb)
					{
						c[i][d] = b[t][d];
					}
					else
					{
						c[i][d] = a[t][d];
					}
				}
				t += 1;
			}
		}
	}
	return c;
}
double calculateTotalMatrix(int** a, int length, int width, int curI, int curJ) { // Ex 16 sub-function
	double sum = 0;
	for (int i = curI, countI = 0; countI < width; ++i, ++countI)
		for (int j = curJ, countJ = 0; countJ < length; ++j, ++countJ)
			sum += a[i][j];
	return sum;
}
int** findSubmatrix(int** a, int length, int width, int& length_, int& width_) { // Ex 16 main-function
	int bestSum = 0, bestRow = 0, bestCol = 0;
	double tempSum = 0;

	for (int i = 0; i + width_ - 1 < width; ++i) {
		for (int j = 0; j + length_ - 1 < length; ++j) {
			tempSum = calculateTotalMatrix(a, length_, width_, i, j);
			if (bestSum <= tempSum) {
				bestSum = tempSum;
				bestRow = i;
				bestCol = j;
			}
		}
	}

	int** newMatrix = new int* [width_];
	for (int i = 0; i < width_; ++i)
		newMatrix[i] = new int[length_];
	for (int i = bestRow, k = 0; k < width_; ++i, ++k)
		for (int j = bestCol, l = 0; l < length_; ++j, ++l)
			newMatrix[k][l] = a[i][j];
	return newMatrix;
}
int** concatenate2MatricesH(int** a, int** b, int length, int width)  //Nhap output thi nhap length,width*2
{
	int** c;
	c = new int* [width];
	for (int i = 0; i < width; i++)
	{
		c[i] = new int[length * 2];
	}
	int t = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length * 2; j++)
		{
			if (j < length)
			{
				c[i][j] = a[i][j];
			}
			else c[i][j] = b[i][t++];
		}
		t = 0;
	}
	return c;
}
int LinearSearch(int* a, int n, int key)
{
	int i = 0;
	while (i < n)
	{
		if (a[i] == key)
		{
			return i;
		}
		i++;
	}
	return -1;
}
int SentinelLinearSearch(int* a, int n, int key)
{
	int i = 0;
	a[n] = key;
	while (a[i] != key)
	{
		i++;
	}
	if (i >= n)
	{
		return -1;
	}
	else return i;
}	
int BinarySearch(int* a, int n,int key)
{
	int left, right,mid;
	left = 0; right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == key)
		{
			return mid;
		}
		else if (a[mid] > key)
		{
			right = mid - 1;
		}
		else if (a[mid] < key)
		{
			left = mid + 1;
		}
	}
	return -1;
}
int RecursiveBinarySearch(int* a, int left, int right, int key)
{
	if (left > right)
	{
		return -1;
	}
	int mid = (left + right) / 2;
	if (a[mid] == key)
	{
		return mid;
	}
	if (a[mid] > key)
	{
		return RecursiveBinarySearch(a, left,mid-1, key);
	}
	else if (a[mid] < key)
	{
		return RecursiveBinarySearch(a, mid + 1, right, key);
	}
}
int main()
{
	//Mang dong

	/* 
	int *a=new int,*b=new int;
	*a=5; *b=6;
	swap(a,b); //Cau 1
	cout<<"a va b sau khi hoan vi la:"<<*a<<" "<<*b<<endl;
	cout<<"Tong cua a va b la:"<<*sum(a,b); //cau 2
	*/

	/*
	int *a,n,length=0;
	InputArray(a,n); //Cau 3
	printArray(a,n); //Cau 4
	cout<<endl<<"Gia tri max cua mang la:"<<*findMax(a,n); //Cau 5
	cout<<endl<<"Vi tri bat dau cua chuoi dai nhat tang dan la:"<<*findLongestAscendingSubarray(a,n,length)-1<<endl; //Cau 6
	cout<<"Do dai cua chuoi dai nhat la:"<<length<<endl;
	*/

	/*
	int *a,na,*b,nb,nd;
	InputArray(a,na);
	InputArray(b,nb);
	// swapArrays(a,b,na,nb); //Cau 7
	// cout<<endl;
	int *c=concatenate2Arrays(a,b,na,nb); //Cau 8
	cout<<"2 mang sau khi concatenate la:"; printArray(c,na+nb); 
	int *d=merge2Arrays(a,b,na,nb,nd); //Cau 9
	cout<<endl;
	cout<<"2 mang sau khi merge theo ascending la:"; printArray(d,nd);
	
	*/
	//Ma tran
	// int **a,length,width;
	// generateMatrix1(a,length,width); //Cau 10

	// int *a,na,*b,nb,**c;
	// InputArray(a,na);
	// InputArray(b,nb);
	// c=generateMatrix2(a,b,na,nb); //Cau 11
	// OutputMatrix(c,nb,na);
	
	//Cau 12
	// int **a,length,width;
	// generateMatrix1(a,length,width);
	// OutputMatrix(a,length,width);
	// swaprows(a,length,width);
	// cout<<"Ma tran sau khi hoan vi dong la"<<endl; OutputMatrix(a,length,width);
	// swapcolums(a,length,width);
	// cout<<"Ma tran sau khi hoan vi cot la"<<endl; OutputMatrix(a,length,width);

	//Cau 13
	// int **a,length,width;
	// generateMatrix1(a,length,width);
	// OutputMatrix(a,length,width);
	// cout<<"Ma tran sau khi hoan vi la"<<endl;
	// a=transposeMatrix(a,length,width);
	// OutputMatrix(a,width,length);

	//Cau 14
	// int **a,**b,length,width;
	// generateMatrix1(a,length,width);
	// generateMatrix1(b,length,width);
	// OutputMatrix(a,length,width);
	// OutputMatrix(b,length,width);
	// cout<<"Ma tran sau khi noi dong la"<<endl;
	// int**c=concatenate2MatricesH(a,b,length,width);
	// OutputMatrix(c,length*2,width);
	// cout<<"Ma tran sau khi noi cot la"<<endl;
	// int**d=concatenate2MatricesV(a,b,length,width);
	// OutputMatrix(d,length,width*2);

	//Cau 15
	// int **a,**b,lengtha,lengthb,widtha,widthb;
	// generateMatrix1(a,lengtha,widtha);
	// generateMatrix1(b,lengthb,widthb);
	// cout<<endl;
	// multiple2Matrices(a,b,widtha,lengtha,widthb,lengthb);

	//Cau 16
	// int **a,length,width,length_=3,width_=2;
	// generateMatrix1(a,length,width);
	// int**c=findSubmatrix(a,length,width,length_,width_);
	// OutputMatrix(c,length_,width_);
	return 0;
}
