#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void mainMenu();
void election_commission();
void voter_list();
void show_result();
int show_totalvoters()
{
    string str;
    int n;
    ifstream fin;
    fin.open("totalvoters.txt", ios::in);
    if (!fin)
    {
        return 0;
    }
    getline(fin, str);
    n = stoi(str);
    fin.close();
    ofstream fout;
    fout.open("totalvoters.txt", ios::out);
    str = to_string(n + 1);
    fout << str;
    fout.close();
    return n;
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
        name = "no_name";
    }
    void signup()
    {
        cout << "Enter your name : ";
        getline(cin >> ws, name);
        // cin.ignore();
        cout << "Set password : ";
        cin >> pswrd;
        vt_ID = show_totalvoters() + 1;
        ofstream v_out;
        v_out.open("allvoterslist.dat", ios::app);
       v_out.write((char *)this, sizeof(*this));
       //v_out<<"\n"<<name<<"\n"<<pswrd<<"\n";
        v_out.close();
    }
    void login()
    {
        system("cls");
        cout << "Enter Voter ID : ";
        if (vt_ID != 0)
        {
            cout << vt_ID << endl;
        }
        else
        {
            cin >> vt_ID;
        }
        fflush(stdin);
        cout << "Enter password : ";
        if (pswrd.length() > 0)
        {
            for (int i = 0; i < pswrd.length() - 1; i++)
            {
                cout << '*';
            }
        }
        while (1)
        {
            pswrd += getch();
            if (pswrd.back() == 13)
            {
                break;
            }
            else if (pswrd.back() == 8)
            {
                pswrd.pop_back();
                pswrd.pop_back();
                login();
                break;
            }
            else
            {
                cout << '*';
            }
        }
        check_login();
        return;
    }
    int check_login()
    {
        voter *v2;
        ifstream fin;
        fin.open("allvoterslist.dat", ios::in | ios::binary);
        fin.read((char *)v2, sizeof(*v2));
        if (!fin)
        {
            cout << "!!!Invalid username and password!!!" << endl;
            return 0;
        }
        while (!fin.eof())
        {
            if ((this->vt_ID == v2->vt_ID) || (this->pswrd == v2->pswrd))
            {
                return 1;
                break;
            }
        }
        fin.close();
        return 0;
    }
    void show_details()
    {
        cout << vt_ID << "   " << name << endl;
    };
    friend void voter_list();
};
void voter_list()
{
    system("cls");
    cout << "\n  ******************LIST OF VOTERS*************** :\n";
    voter v1;
    ifstream fin;
    fin.open("allvoterslist.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "File doesn't exist.";
        fin.close();
        return;
    }
    fin.read((char *)&v1, sizeof(voter));
    while (!fin.eof())
    {
        v1.show_details();
        fin.read((char *)&v1, sizeof(voter));
    }
    fin.close();
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
// void mainMenu()
// {
//     system("cls");
//     int ch1, ch3;
//     cout << "\n\n\n\n\n";
//     cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
//     cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
//     cout << "\n\t\t\t\t        =                  WELCOME                  =";
//     cout << "\n\t\t\t\t        =                    TO                     =";
//     cout << "\n\t\t\t\t        =                  VOTING                   =";
//     cout << "\n\t\t\t\t        =                  SYSTEM                   =";
//     cout << "\n\t\t\t\t        =              OF NIT JALANDHAR             =";
//     cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
//     cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";

//     cout << "\t\t\t\t1.ELECTION COMMISION LOGIN .\n\t\t\t\t2.CANDIDATE SIGNUP.\n\t\t\t\t3.EXIT.\n";
//     cout << "\t\t\t\tEnter your choice : 1 , 2 or 3 : ";
//     cin >> ch1;
//     if (ch1 == 1)
//     {
//         election_commission();
//     }
//     do
//     {
//         if (ch1 == 2)
//         {
//             voter v1;
//             v1.signup();
//             switch (ch3)
//             {
//             case 1:
//                 v1.signup();
//                 break;
//             }
//         }
//         while (ch1 != 0)
//             ;

//         // hold the screen
//         getchar();

//         if (ch1 == 3)
//             exit(0);
//     }
    void show_result()
    {
        system("cls");
        // votesCount();
    }
    void mainMenu(){
        system("cls");
        int ch1, ch3;
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

        cout << "\t\t\t\t1.ELECTION COMMISION LOGIN .\n\t\t\t\t2.CANDIDATE SIGNUP.\n\t\t\t\t3.EXIT.\n";
        cout << "\t\t\t\tEnter your choice : 1 , 2 or 3 : ";
        cin >> ch1;
        if (ch1 == 1)
        {
            election_commission();
        }
        
           else if (ch1 == 2)
            {
                voter v1;
                v1.signup();
                mainMenu();
            }

            else
            {
                exit(0);
            }
         
    }
    int main()
    {
        mainMenu();
    //     void mainMenu(){
    //     system("cls");
    //     int ch1, ch3;
    //     cout << "\n\n\n\n\n";
    //     cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    //     cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    //     cout << "\n\t\t\t\t        =                  WELCOME                  =";
    //     cout << "\n\t\t\t\t        =                    TO                     =";
    //     cout << "\n\t\t\t\t        =                  VOTING                   =";
    //     cout << "\n\t\t\t\t        =                  SYSTEM                   =";
    //     cout << "\n\t\t\t\t        =              OF NIT JALANDHAR             =";
    //     cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    //     cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";

    //     cout << "\t\t\t\t1.ELECTION COMMISION LOGIN .\n\t\t\t\t2.CANDIDATE SIGNUP.\n\t\t\t\t3.EXIT.\n";
    //     cout << "\t\t\t\tEnter your choice : 1 , 2 or 3 : ";
    //     cin >> ch1;
    //     if (ch1 == 1)
    //     {
    //         election_commission();
    //     }
    //     do
    //     {
    //         if (ch1 == 2)
    //         {
    //             voter v1;
    //             v1.signup();
    //             switch (ch3)
    //             {
    //             case 1:
    //                 v1.signup();
    //                 break;
    //             }
    //         }

    //      } while (ch1 != 0);
    //         getchar();
    //         if (ch1==3)
    //         {
    //             exit(0);
    //         }
            
        
    // }
    }
