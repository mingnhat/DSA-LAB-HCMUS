#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


struct Examinee
{
	string id;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};

float tranfer(string s)
{
    if (s.empty())
        return 0;
    else {
        return stof(s);
    }
}

Examinee readExaminee(string line_info)
{
    Examinee e;
    stringstream ss(line_info);
    string name, note, province;
    string t[11];
    getline(ss, e.id, ',');
    getline(ss, name, ',');
    for(int i=0;i<11;i++)
        getline(ss, t[i], ',');
    e.math = tranfer(t[0]);
    e.literature = tranfer(t[1]);
    e.physic = tranfer(t[2]);
    e.chemistry = tranfer(t[3]);
    e.biology = tranfer(t[4]);
    e.history = tranfer(t[5]);
    e.geography = tranfer(t[6]);
    e.civic_education = tranfer(t[7]);
    e.natural_science = tranfer(t[8]);
    e.social_science = tranfer(t[9]);
    e.foreign_language = tranfer(t[10]);
    getline(ss, note, ',');
    if (note.empty())
        note = "Nope";
    getline(ss, province, ',');
    if (name.empty())
        name = "Unknow";
    return e;
}
vector<Examinee> readExamineeList(string file_name)
{
    vector<Examinee> e;
    ifstream file;
    file.open(file_name);
    Examinee temp;
    string line;
    getline(file, line);
    while (!file.eof())
    {
        getline(file,line);
        temp=readExaminee(line);
        e.push_back(temp);
    }
    file.close();
    return e;
}
void writeList(vector<Examinee> list, string fileName)
{
    float sum = 0;
    ofstream fout;
    fout.open(fileName);
    if (!fout.is_open())
        cout << "Can not create file !\n";
    else {
        for (int e = 0; e < list.size(); e++) {
            fout << list[e].id;
            fout << ' ';
            sum = list[e].math + list[e].literature + list[e].physic + list[e].chemistry + list[e].biology + list[e].history + list[e].geography + list[e].civic_education + list[e].foreign_language;
            fout << sum;
            fout << '\n';
            sum = 0;
        }
    }
    cout << "Done\n";
    fout.close();
}

void printVector(vector<Examinee> list)
{
    if (list.empty()) {
        cout << "EMPTY!!!\n";   
        return;
    }
    for (int e = 0; e <list.size(); e++) {
        cout << "ID \t\t\t: " << list[e].id << "\n";
    
        cout << "Math \t\t\t: " << list[e].math << "\n";
        cout << "Literature \t\t: " << list[e].literature << "\n";
        cout << "physic \t\t\t: " << list[e].physic << "\n";
        cout << "Chemistry \t\t: " << list[e].chemistry << "\n";
        cout << "Biology \t\t: " << list[e].biology << "\n";
        cout << "History \t\t: " << list[e].history << "\n";
        cout << "Geography \t\t: " << list[e].geography << "\n";
        cout << "Civic education \t: " << list[e].civic_education << "\n";
        cout << "Natural Science \t: " << list[e].natural_science << "\n";
        cout << "Social Science \t\t: " << list[e].social_science << "\n";
        cout << "Foreign Laguage \t: " << list[e].foreign_language << "\n";
  
        cout << "_________________________________\n\n";
    }
}
int main()
{
    ifstream f;
    string id;
    vector<Examinee> list = readExamineeList("data.txt");
    // printVector(list);
    writeList(list, "out.txt");

    return 0;
}