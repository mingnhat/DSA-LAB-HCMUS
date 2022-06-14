#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<math.h>
using namespace std;
struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadCompanyList(string file_name)
{
	vector<Company> res;
	ifstream fin(file_name);
	string a;
	getline(fin, a);
	while (!fin.eof())
	{
		getline(fin, a);
		stringstream line(a);
		Company temp;
		getline(line, temp.name, '|');
		getline(line, temp.profit_tax, '|');
		getline(line, temp.address, '|');
		res.push_back(temp);
	}
	return res;
}

long long HashCalcu(int p,int i,int m)
{
	long long result=1;
	for(int j=0;j<i;j++)
	{
		result*=p;
		result = result % m; //chia dư để không bị tràn số
	}
	return result;
}

long long HashString(string company_name)
{
	int len=company_name.size() > 20 ? 20 : company_name.size(); //VD chuoi co 60 ky tu thi len=20
	int beg=company_name.size() > 20 ? company_name.size()-20 : 0; //Vd chuoi co 60 ky tu thi beg=40
	long long m = pow(10,9)+9; 
	long long hashvalue=0;
	for(int i= beg;i< (beg+len) ;i++) //voi chuoi 60 ky tu thi i=40;i<60
	{
		hashvalue += int(company_name[i]) * HashCalcu(31,i-beg,m); //s[i]*p^i
		hashvalue = hashvalue % m; 
	}
	return hashvalue;
}

Company *CreateHashTable(vector<Company> list_company)
{
	Company *res=new Company[2000];
	for(int i=0; i<2000; i++)
	{
		res[i]={"","",""}; //Khoi tao res
	}
	for(int i=0;i<list_company.size(); i++)
	{
		int hval=HashString(list_company[i].name);
		if(res[hval%2000].name=="") //Neu bucket đó trống thì sẽ gán luôn
		{
			res[hval%2000]=list_company[i];
		}
		else //Nếu phần tử đó không trống thì linear để không collision
		{
			int temp=HashString(list_company[i].name)%2000 +1; //Cong 1 phan tu truoc khi xet while
			while(res[temp].name!="") //Cho den khi nao tim duoc phan tu trong
			{
				temp=(temp+1)%2000;
			}
			res[temp]=list_company[i]; //Sau khi kết thúc vòng lặp nghĩa là đã tìm được temp còn trống thì gán
		}
	}
	return res; 
}
void Insert(Company *hash_table, Company company)
{
	int index = HashString(company.name) % 2000; 
	while (hash_table[index].name != "") 
		index = (index + 1) % 2000;
	hash_table[index] = company; //Cung nhu ham tren , sau khi tim dc bucket trống thì sẽ lấp vào
}
Company *Search(Company *hash_table, string company_name)
{
	int index = HashString(company_name) % 2000;
	while(hash_table[index].name!=company_name)
	{
		if(hash_table[index].name == "") //điều đó có nghĩa là phần tử đó không tồn tại
			return nullptr; 
		index= (index+1)%2000;
	}
	return &hash_table[index];
}
int main()
{
	vector<Company> Com = ReadCompanyList("MST.txt");
	Company *hashTable = CreateHashTable(Com);
	for(int i=0;i<2000;i++)
	{
		cout<<i<<" "<<hashTable[i].name<<endl;
	}
	// Company New={"Nhat","123456","Khong biet"};
	// Insert(hashTable,New);
	// cout<<Search(hashTable,"Nhat")->profit_tax;
	delete[] hashTable;
	return 0;
}
