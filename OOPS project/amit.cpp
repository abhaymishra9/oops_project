#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
class voter;
class ec
{
    long long int n;

public:
    friend int show_totalvoters();
    friend void signup(voter);
};
int show_totalvoters()
{
    ec *e1;
    ifstream fin;
    fin.open("totalvoters.dat", ios::in);
    fin.read((char *)e1, sizeof(e1));
    if (!fin)
    {
        return 0;
    }
    else
    {
        return e1->n;
    }
    fin.close();
}

class voter
{
    long long int vt_ID;
    string name;
    string pswrd;

public:
    voter()
    {
        vt_ID = 0;
    }
    friend void login(voter);
    friend void signup(voter);
    friend int check_login(voter);
};
int check_login(voter v1)
{
    voter *v2;
    ifstream fin;
    fin.open("allvoterslist.dat", ios::in | ios::binary);
    fin.read((char *)v2, sizeof(v2));
    if (!fin)
    {
        cout << "!!!Invalid username and password!!!" << endl;
        return 0;
    }
    while (!fin.eof())
    {
        if ((v1.vt_ID == v2->vt_ID) || (v1.pswrd == v2->pswrd))
        {
            return 1;
            break;
        }
    }
    fin.close();
    return 0;
}
void login(voter v1)
{
    system("cls");
    cout << "Enter Voter ID : ";
    if (v1.vt_ID != 0)
    {
        cout << v1.vt_ID << endl;
    }
    else
    {
        cin >> v1.vt_ID;
    }
    fflush(stdin);
    cout << "Enter password : ";
    if (v1.pswrd.length() > 0)
    {
        for (int i = 0; i < v1.pswrd.length() - 1; i++)
        {
            cout << '*';
        }
    }
    while (1)
    {
        v1.pswrd += getch();
        if (v1.pswrd.back() == 13)
        {
            break;
        }
        else if (v1.pswrd.back() == 8)
        {
            v1.pswrd.pop_back();
            v1.pswrd.pop_back();
            login(v1);
            break;
        }
        else
        {
            cout << '*';
        }
    }
    check_login(v1);
    return;
}
void signup(voter v1)
{
    cout << "Enter your name : ";
    getline(cin >> ws, v1.name);
    cout << "Set password : ";
    cin >> v1.pswrd;
    v1.vt_ID = show_totalvoters();
    ofstream v_out;
    v_out.open("allvoterslist.dat", ios::app);
    v_out.write((char *)&v1, sizeof(v1));
    v_out.close();
    ec e1;
    e1.n = v1.vt_ID + 1;
    ofstream v_out2;
    v_out.open("totalvoters.dat", ios::out);
    v_out.write((char *)&e1, sizeof(e1));
    v_out2.close();
}
int main()
{
    voter v1;
    // login(v1);
    signup(v1);
    return 0;
}