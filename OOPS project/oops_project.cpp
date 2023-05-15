#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

void mainMenu();
void election_commission();
void voter_list();
void show_result();
// void votesCount();

int main()
{
    mainMenu();
    return 0;
}
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
    void show_details()
    {
        cout << vt_ID << "    " << name << "    " << endl;
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
    v1.vt_ID = show_totalvoters()+1;
    ofstream v_out;
    v_out.open("allvoterslist.dat", ios::app);
    v_out.write((char *)&v1, sizeof(v1));
    v_out.close();
    ec e1;
    e1.n = v1.vt_ID;
    ofstream v_out2;
    v_out.open("totalvoters.dat", ios::out);
    v_out.write((char *)&e1, sizeof(e1));
    v_out2.close();
}
void mainMenu()
{
    system("cls");
    int ch1;
    cout << "\n\n\n\n\n";
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t        =                  WELCOME                  =";
    cout << "\n\t\t\t\t        =                    TO                     =";
    cout << "\n\t\t\t\t        =                  VOTING                   =";
    cout << "\n\t\t\t\t        =                  SYSTEM                   =";
    cout << "\n\t\t\t\t        =              OF NIT JALANDHAR             =";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";

    cout << "\t\t\t\t1.ELECTION COMMISION LOGIN .\n\t\t\t\t2.CANDIDATE LOGIN.\n\t\t\t\t3.EXIT.\n";
    cout << "\t\t\t\tEnter your choice : 1 , 2 or 3 : ";
    cin >> ch1;
    if (ch1 == 1)
    {
        election_commission();
    }
    else if (ch1 == 2)
    {
        voter v1;
        signup(v1);
    }
    else if (ch1 == 3)
        exit(0);
    else
    {
        mainMenu();
    }
}

void election_commission()
{
    system("cls");
    int ch2;
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\t\t\t\t\t              1.SHOW VOTERS LIST\n";
    cout << "\t\t\t\t\t              2.SCHEDULING ELECTIONS\n";
    cout << "\t\t\t\t\t              3.SHOW RESULTS\n";
    cout << "\t\t\t\t\t              4.MAIN MENU\n";
    cout << "\t\t\t\tEnter your choice : 1 , 2 , 3 or 4  : \n";
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cin >> ch2;
    if (ch2 == 1)
    {
        voter_list();
    }
    else if (ch2 == 2)
    {
    }
    else if (ch2 == 3)
    {
        show_result();
    }

    else if (ch2 == 4)
    {
        mainMenu();
    }
    else
    {
        cout << "INVALID CHOICE !!!";
    }
}

void voter_list()
{
    system("cls");
    ifstream FileName;
    cout << "\n  ******************LIST OF VOTERS*************** :\n";
    FileName.open("allvoterslist.dat", ios::in);
    voter v1;
    FileName.read((char *)&v1, sizeof(v1));
    if (!FileName)
    {
        cout << "File doesn’t exist.";
        FileName.close();
        return;
    }
    while (!FileName.eof())
    {
        v1.show_details();
        FileName.read((char *)&v1, sizeof(v1));
    }
    FileName.close();
}

void show_result()
{
    system("cls");
    // votesCount();
}