#include<iostream>
#include<cmath>
#include<string>
using namespace std;
//S=1+2+3+..+n
//#Ex1
int Sum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return Sum(n - 1)+n;
}

//Ex2 n! = 1 ∗ 2 ∗ 3 ∗ ... ∗ n.
long long factorial(int n)
{
    if(n==1) return 1;
    return factorial(n-1)*n;
}

//Ex3 Calculate x^n
long long xn(int x,int n)
{
	if(n==0) return 1;
	return xn(x,n-1)*x;
}

//Ex4
int digitnumber(int n)
{
	if (n == 0)
		return 0;
	return digitnumber(n / 10) + 1;
}

//Ex5
bool CheckEvenDigit(int n)
{
	if (n == 0)
	{
		return true;
	}
	if (n % 2 == 1)
	{
		return false;
	}
	return CheckEvenDigit(n / 10);
}

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
//Ex6
int countDis(int a, int b, int i)
{
	if (i == 1) return 1;
	if (a % i == 0 && b % i == 0)
	{
		return countDis(a, b, i - 1)+1;
	}
	return countDis(a, b, i - 1);
}

//Ex7
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

//Ex8
int DoiChuSo(int H, int Dem)
{
	if (Dem > 0)
	{
		return DoiChuSo(H * 10, Dem - 1);
	}
	return H;
}

int ChuSoDaoNguoc(int n)
{
	if (n == 0)
	{
		return 0;
	}
	int Dem = digitnumber(n);
	int H = n % 10;
	int T = DoiChuSo(H, Dem - 1);
	return ChuSoDaoNguoc(n / 10) + T;
}

int Fibonacci(int n)
{
	if(n==0) return 0;
	else if(n==1) return 1;
	else
	return Fibonacci(n-1)+Fibonacci(n-2);
}

void permutations(string str, int i, int n)
{
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }
 
    for (int j = i; j < n; j++)
    {
 
        swap(str[i], str[j]);        
 
        permutations(str, i + 1, n);
 
        swap(str[i], str[j]);
    }
}
void permutatiton(string s, int j)
{
	if (j == s.size()-1) cout << s <<endl;
	else
	{
		for (int i = j; i < s.size(); i++)
		{
			swap(s[j], s[i]);
			permutatiton(s, j+1);
			swap(s[j], s[i]);
		}
	}
}
int main()
{
	// int n,x;
	// cout<<"Nhap x: ";
	// cin>>x;
	// cout<<"Nhap n: ";
	// cin>>n;
	// cout<<endl<<"Ket qua tong chuoi n Ex1 la:"<<Sum(n);
	// // cout<<endl<<"Ket qua cua chuoi giai thua n la:"<<factorial(n);
	// cout<<endl<<"Ket qua cua mu n cua x la:"<<xn(x,n);
	// cout<<endl<<"Ket qua cua do dai chuoi so n la:"<<digitnumber(n)<<endl;
	// if(CheckEvenDigit(n)) cout<<"Tat ca so trong chuoi n deu la chan";
	// else cout<<"Trong chuoi n co so khong thoa chan";
	// int a, b,i;
	// cout<<endl<<"Nhap a va b";
	// cin>>a>>b;
	// i=max(a,b);
	// cout <<endl<<"So uoc chung cua a va b la: "<<countDis(a, b, i);
	// cout<<endl<<"Boi chung nho nhat cua a va b la: "<<gcd(a,b);
	// cout<<endl<<"Uoc chung lon nhat cua a va b la: "<<lcm(a,b);
	// cout<<endl<<"Chu so dao nguoc cua n la: "<<ChuSoDaoNguoc(n);
	// cout<<endl<<"Fibonacci cua n la: "<<Fibonacci(n);
	string s;
	cout<<endl<<"Nhap chuoi ki tu: ";
	cin >> s;
	permutatiton(s,0);
	return 0;
}

 