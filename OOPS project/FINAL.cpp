#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
using namespace std;
#define PASSWORD "vvv_nitj"

void title()
{
    cout << "\n\t\t\t\t ---------------------------------------------------------------------------";
    cout << "\n\t\t\t\t|    _____     _____     _____      ____     ______          ____           |";
    cout << "\n\t\t\t\t|   |         |     |   |     |    |    |      |       |    |        \\  /   |";
    cout << "\n\t\t\t\t|   |_____    |_____|   |     |    |____|      |       |    |___      \\/    |";
    cout << "\n\t\t\t\t|         |   |         |     |    |\\          |       |    |         Y     |";
    cout << "\n\t\t\t\t|    _____|   |         |_____|    | \\         |       |    |         |     |";
    cout << "\n\t\t\t\t|                                                                           |";
    cout << "\n\t\t\t\t ----------------------------------------------------------------------------";
}

void addons()
{
    cout << "\n                                        \t\t                \t\t                                   /";
    cout << "\n                                        \t\t            ___ \t\t        (((((((()))    ((())))))))/";
    cout << "\n                                        \t\t           / // \t\t      ((           )) ((         / ))";
    cout << "\n   __________                __________ \t\t          / //  \t\t     ((              ()   /\\    /    ))";
    cout << "\n  |          |              |          |\t\t        _/_//_  \t\t      ((                 /  \\  /    ))";
    cout << "\n  |          |______________|          |\t\t       /    //  \t\t        ((          /\\  /    \\/   ))";
    cout << "\n  |          _______________           |\t\t      /     //  \t\t          ((       /  \\/        ))";
    cout << "\n  |          |              |          |\t\t     /     //   \t\t             (( /\\/         ))";
    cout << "\n  |__________|              |__________|\t\t    /     //    \t\t               /((       ))";
    cout << "\n                                        \t\t   /_____//     \t\t              /    ((_))";
    cout << endl
         << endl
         << endl
         << endl;
}

void thanks()
{
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\t(A)    (A) \t\t   -------   |    |     /\\     |\\   |   |  /  \t   \\  /   ((()))    (        )   \t\t(A)    (A)";
    cout << "\n\t    V      \t\t      |      |____|    /  \\    | \\  |   | /   \t    \\/   (      )   (        )   \t\t    V     ";
    cout << "\n\t  \\   /   \t\t      |      |    |   /____\\   |  \\ |   |\\   \t     |   (     )    (      )    \t\t  \\   / ";
    cout << "\n\t    U      \t\t      |      |    |  /      \\  |   \\|   | \\  \t     |    ((()))       (())      \t\t    U    ";
}

void returndate(string &a)
{
    time_t timetoday;
    time(&timetoday);
    a = asctime(localtime(&timetoday));
}

class User;

class Sports
{
protected:
    string sport_name, coach, timeslots[2];
    int memberships[4];
};

class Cricket : public Sports
{
public:
    static int available_slots;
    friend class User;
    Cricket()
    {
        coach = "Rahul Dravid";
        sport_name = "Cricket";
        timeslots[0] = "6:30 am to 7:30 am";
        timeslots[1] = "4:30 pm to 5:30 pm";
        memberships[0] = 2500;
        memberships[1] = 5500;
        memberships[2] = 9500;
        memberships[3] = 17500;
        available_slots++;
    }
    void display()
    {
        cout << "\n-----------CRICKET-------------" << endl;
        cout << "Memberships plans: " << endl;
        cout << "Monthly: " << memberships[0] << endl;
        cout << "Quaterly: " << memberships[1] << endl;
        cout << "Half Yearly: " << memberships[2] << endl;
        cout << "Yearly: " << memberships[3] << endl;
    }
    int choice_selection();
};
int Cricket::available_slots = -1;
class Football : public Sports
{
public:
    static int available_slots;
    friend class User;
    Football()
    {
        coach = "Sunil Chhetri";
        sport_name = "Football";
        timeslots[0] = "7:30 am to 8:30 am";
        timeslots[1] = "5:30 pm to 6:30 pm";
        memberships[0] = 3000;
        memberships[1] = 6500;
        memberships[2] = 10000;
        memberships[3] = 18000;
        available_slots++;
    }
    void display()
    {
        cout << "\n-----------FOOTBALL-------------" << endl;
        cout << "Memberships plans: " << endl;
        cout << "Monthly: " << memberships[0] << endl;
        cout << "Quaterly: " << memberships[1] << endl;
        cout << "Half Yearly: " << memberships[2] << endl;
        cout << "Yearly: " << memberships[3] << endl;
    }
    int choice_selection();
};
int Football::available_slots = -1;
class Basketball : public Sports
{
public:
    static int available_slots;
    friend class User;
    Basketball()
    {
        coach = "Satyam Singh";
        sport_name = "Basketball";
        timeslots[0] = "8:30 am to 9:30 am";
        timeslots[1] = "6:30 pm to 7:30 pm";
        memberships[0] = 2000;
        memberships[1] = 5000;
        memberships[2] = 9000;
        memberships[3] = 17000;
        available_slots++;
    }
    void display()
    {
        cout << "\n-----------BASKETBALL-------------" << endl;
        cout << "Memberships plans: " << endl;
        cout << "Monthly: " << memberships[0] << endl;
        cout << "Quaterly: " << memberships[1] << endl;
        cout << "Half Yearly: " << memberships[2] << endl;
        cout << "Yearly: " << memberships[3] << endl;
    }
    int choice_selection();
};
int Basketball::available_slots = -1;
class Tennis : public Sports
{
public:
    static int available_slots;
    friend class User;
    Tennis()
    {
        coach = "Rohan Bopanna";
        sport_name = "Lawn Tennis";
        timeslots[0] = "9:30 am to 10:30 am";
        timeslots[1] = "7:30 pm to 8:30 pm";
        memberships[0] = 3000;
        memberships[1] = 6500;
        memberships[2] = 10000;
        memberships[3] = 19000;
        available_slots++;
    }
    void display()
    {
        cout << "\n-----------TENNIS-------------" << endl;
        cout << "Memberships plans: " << endl;
        cout << "Monthly: " << memberships[0] << endl;
        cout << "Quaterly: " << memberships[1] << endl;
        cout << "Half Yearly: " << memberships[2] << endl;
        cout << "Yearly: " << memberships[3] << endl;
    }
    int choice_selection();
};
int Tennis::available_slots = -1;
Cricket c1;
Tennis t1;
Football f1;
Basketball b1;
class User
{
protected:
    static int index;
    static string name[];
    static string date_of_joining[];
    static int age[];
    static long long int phone[];
    static string sportspick[], timeslot[];
    static int package[];

public:
    friend class Cricket;
    friend class Football;
    friend class Basketball;
    friend class Tennis;
    friend int sportschoosen(User *u);
    friend void display();
    friend void curdisplay();
    void get_data_1()
    {
        if (index < 200)
        {
            index++;
            cout << "\nEnter your details\n\n";
            cout << "Enter Name: ";
            getline(cin, name[index]);
            cout << "Enter Age: ";
            cin >> age[index];
            cout << "Enter phone: ";
            cin >> phone[index];
            returndate(date_of_joining[index]);
            ofstream MyExcel;
            MyExcel.open("test.csv", ios::app);
            MyExcel << name[index] << " " << age[index] << " " << phone[index] << " ";
            MyExcel.close();
        }
        else
        {
            cout << "\n\tSeats Full!!!!" << endl;
        }
    }
    int get_data_2(int x)
    {
        int z;
        if (x == 1)
        {
            Cricket cc;
            ;
            z = cc.choice_selection();
        }
        else if (x == 2)
        {
            Football ff;
            z = ff.choice_selection();
        }
        else if (x == 3)
        {
            Basketball bb;
            z = bb.choice_selection();
        }
        else
        {
            Tennis tt;
            z = tt.choice_selection();
        }
        return z;
    }
};

int User::index = -1, User::age[200], User::package[200];
long long int User::phone[200];
string User::name[200], User::sportspick[200], User::timeslot[200], User::date_of_joining[200];

int Cricket::choice_selection()
{
    if (available_slots < 51)
    {
        int pick;
        int t = User::index;
        User::sportspick[t] = "Cricket";
        cout << "\n\tThese are the available Time-Slots :-";
        cout << "\n1. " << timeslots[0];
        cout << "\n2. " << timeslots[1] << endl;
        cout << "\nEnter your choice : ";
        cin >> pick;
        User::timeslot[t] = timeslots[pick - 1];
        cout << "\n\tThese are the Packages :-";
        cout << "\n1.Rs " << memberships[0] << "\\- Monthly";
        cout << "\n2.Rs " << memberships[1] << "\\- Quarterly";
        cout << "\n3.Rs " << memberships[2] << "\\- Half-Yearly";
        cout << "\n4.Rs " << memberships[3] << "\\- Yearly" << endl;
        cout << "\nEnter your choice : ";
        cin >> pick;
        User::package[t] = memberships[pick - 1];
        ofstream MyExcel;
        MyExcel.open("test.csv", ios::app);
        MyExcel << User::sportspick[t] << " " << User::package[t] << " " << User::timeslot[t] << endl;
        MyExcel.close();
        return 0;
    }
    else
    {
        cout << "Seats Full\nTry In Other Sports.";
        return -1;
    }
}
int Football::choice_selection()
{
    if (available_slots < 51)
    {
        int pick;
        int t = User::index;
        User::sportspick[t] = "Cricket";
        cout << "\n\tThese are the available Time-Slots :-";
        cout << "\n1. " << timeslots[0];
        cout << "\n2. " << timeslots[1] << endl;
        cout << "\nEnter your choice : ";
        cin >> pick;
        User::timeslot[t] = timeslots[pick - 1];
        cout << "\n\tThese are the Packages :-";
        cout << "\n1.Rs " << memberships[0] << "\\- Monthly";
        cout << "\n2.Rs " << memberships[1] << "\\- Quarterly";
        cout << "\n3.Rs " << memberships[2] << "\\- Half-Yearly";
        cout << "\n4.Rs " << memberships[3] << "\\- Yearly" << endl;
        cout << "\nEnter your choice : ";
        cin >> pick;
        User::package[t] = memberships[pick - 1];
        ofstream MyExcel;
        MyExcel.open("test.csv", ios::app);
        MyExcel << User::sportspick[t] << " " << User::package[t] << " " << User::timeslot[t] << endl;
        MyExcel.close();
        return 0;
    }
    else
    {
        cout << "Seats Full\nTry In Other Sports.";
        return -1;
    }
}

int Basketball::choice_selection()
{
    if (available_slots < 51)
    {
        int pick;
        int t = User::index;
        User::sportspick[t] = "Cricket";
        cout << "\n\tThese are the available Time-Slots :-";
        cout << "\n1. " << timeslots[0];
        cout << "\n2. " << timeslots[1] << endl;
        cout << "\nEnter your choice : ";
        cin >> pick;
        User::timeslot[t] = timeslots[pick - 1];
        cout << "\n\tThese are the Packages :-";
        cout << "\n1.Rs " << memberships[0] << "\\- Monthly";
        cout << "\n2.Rs " << memberships[1] << "\\- Quarterly";
        cout << "\n3.Rs " << memberships[2] << "\\- Half-Yearly";
        cout << "\n4.Rs " << memberships[3] << "\\- Yearly" << endl;
        cout << "\nEnter your choice : ";
        cin >> pick;
        User::package[t] = memberships[pick - 1];
        ofstream MyExcel;
        MyExcel.open("test.csv", ios::app);
        MyExcel << User::sportspick[t] << " " << User::package[t] << " " << User::timeslot[t] << endl;
        MyExcel.close();
        return 0;
    }
    else
    {
        cout << "Seats Full\nTry In Other Sports.";
        return -1;
    }
}

int Tennis::choice_selection()
{
    if (available_slots < 51)
    {
        int pick;
        int t = User::index;
        User::sportspick[t] = "Cricket";
        cout << "\n\tThese are the available Time-Slots :-";
        cout << "\n1. " << timeslots[0];
        cout << "\n2. " << timeslots[1] << endl;
        cout << "\nEnter your choice : ";
        cin >> pick;
        User::timeslot[t] = timeslots[pick - 1];
        cout << "\n\tThese are the Packages :-";
        cout << "\n1.Rs " << memberships[0] << "\\- Monthly";
        cout << "\n2.Rs " << memberships[1] << "\\- Quarterly";
        cout << "\n3.Rs " << memberships[2] << "\\- Half-Yearly";
        cout << "\n4.Rs " << memberships[3] << "\\- Yearly" << endl;
        cout << "\nEnter your choice : ";
        cin >> pick;
        User::package[t] = memberships[pick - 1];
        ofstream MyExcel;
        MyExcel.open("test.csv", ios::app);
        MyExcel << User::sportspick[t] << " " << User::package[t] << " " << User::timeslot[t] << endl;
        MyExcel.close();
        return 0;
    }
    else
    {
        cout << "Seats Full\nTry In Other Sports.";
        return -1;
    }
}
int sportschoosen(User *u)
{
    cout << "\n\n\nWhich Sport You Want To Choose :"
         << "\n1.Cricket\t\t2.Football\t\t3.Basketball\t\t4.Lawn Tennis\n";
    int choice;
    cin >> choice;
    int x = u->get_data_2(choice);
    return x;
}

void display()
{
    ifstream MyExcel;
    MyExcel.open("test.csv", ios::in);
    char mystring;
    while (MyExcel.good())
    {
        mystring = MyExcel.get();
        cout << mystring;
    }
    MyExcel.close();
}

void displaye()    //Employees
{
    ifstream MyExcel;
    MyExcel.open("employee.csv", ios::in);
    char mystring;
    while (MyExcel.good())
    {
        mystring = MyExcel.get();
        cout << mystring;
    }
    MyExcel.close();
}

void curdisplay()
{
    cout << User::name[User::index] << "  " << User::age[User::index] << "  " << User::phone[User::index] << "  " << User::sportspick[User::index] << "  " << User::package[User::index] << "  " << User::timeslot[User::index] << "  " << User::date_of_joining[User::index];
}
typedef struct emp_basic_det
{
    int id;
    long long int phone_num;            // Defining the structure to hold
    char e_name[30], doj[10], dept[30]; // the basic details of an employee
    char gender;
} basic;

class employ
{
protected:
    static int mang;
    static int coach;
    static int other;
    static int emp_count;  // defining variable for number of employees
    static basic *details; // defining the pointer to dynamincally hold the number of employees at

public:
    void get_employ()
    {
        emp_count++;                                                    // incrementing the count value as soon as the object is created
        details = (basic *)realloc(details, sizeof(basic) * emp_count); // reallocating the memory of the dynamic array to increase the memory

        ofstream MyExcel;
        MyExcel.open("employee.csv", ios::app);
        cout << "\n\tNew Employee  ==>" << endl;
        cout << "\nEnter your Employee-ID : ";
        cin >> (details + emp_count - 1)->id;
        MyExcel << (details + emp_count - 1)->id << " ";
        cout << "Enter your phone number (+91) : ";
        cin >> (details + emp_count - 1)->phone_num;
        MyExcel << (details + emp_count - 1)->phone_num << " ";
        cout << "Enter your gender : ";
        cin >> (details + emp_count - 1)->gender; // Taking the input of the details
        MyExcel << (details + emp_count - 1)->gender << " ";
        cout << "Enter your name : ";
        cin >> (details + emp_count - 1)->e_name;
        MyExcel << (details + emp_count - 1)->e_name << " ";
        cout << "Enter your date-of-joining : ";
        cin >> (details + emp_count - 1)->doj;
        MyExcel << (details + emp_count - 1)->doj << " ";
        cout << "Enter the name of your department : ";
        cin >> (details + emp_count - 1)->dept;
        MyExcel << (details + emp_count - 1)->dept << " ";
    }

    void show_emp(int index)
    {
        cout << "\nEmployee-ID : " << (details + index)->id;
        cout << "\nPhone number (+91) : " << (details + index)->phone_num;
        cout << "\nName : " << (details + index)->e_name;
        cout << "\nDate-of-joining : " << (details + index)->doj; // displaying the details of the employee at
        cout << "\nGender : " << (details + index)->gender;       // the entered index (given as an argument)
        cout << "\nDepartment : " << (details + index)->dept << endl;
    }

    void show_emp_count()
    {
        cout << "\nThe total number of employees till now are : " << emp_count << endl; // displaying the number of employees till excecution
    }
};

int m, c, o;
int employ::mang = m;
int employ::coach = c;
int employ::other = o;
int employ::emp_count = (employ::mang + employ::coach + employ::other); // intializing the number of employees to 0

class Manager : public employ
{
    string qual;

public:
    void input()
    {
        ofstream emp;
        emp.open("empcount.csv", ios::out);
        mang++;
        m = mang;
        emp << mang << " " << coach << " " << other;
        get_employ();
        cout << "Enter the Qualifications: ";
        cin >> qual;
        ofstream MyExcel;
        MyExcel.open("employee.csv", ios::app);
        MyExcel << qual << endl;
    }
};
class Coach : public employ
{
    int exp;

public:
    void input()
    {
        coach++;
        ofstream emp;
        emp.open("empcount.csv", ios::out);
        c = coach;
        emp << mang << " " << coach << " " << other;
        get_employ();
        cout << "Enter the Experience in yrs: ";
        cin >> exp;
        ofstream MyExcel;
        MyExcel.open("employee.csv", ios::app);
        MyExcel << exp << endl;
    }
};
class Other : public employ
{
public:
    void input()
    {
        other++;
        ofstream emp;
        emp.open("empcount.csv", ios::out);
        emp << mang << " " << coach << " " << other;
        o = other;
        get_employ();
    }
};

basic *employ::details = NULL; // intializing the dynamic details array to NULL

class Accounts : public User, public employ
{
    int revenue;
    int sal;

public:
    Accounts()
    {
        revenue = 0;
    }
    void salary();
    void get_revenue();
};

void Accounts::salary()
{
    sal = 0;
    cout << "Total number of emplyees: " << m + c + o << endl;
    sal = m * 40000 + c * 35000 + o * 20000;
    cout << "----------SALARIES-----------" << endl;
    cout << "Total Managers: " << m << endl;
    cout << "Total Coaches: " << c << endl;
    cout << "Total Others: " << o << endl;
    cout << endl
         << "-------Total salary given----------" << endl;
    cout << sal << endl;
}

void Accounts::get_revenue()
{
    for (int i = 0; i < index + 1; i++)
    {
        revenue += package[i];
    }
    cout << "Total revenue generated is: " << revenue - sal;
}

void search()
{
    ifstream MyExcel;
    MyExcel.open("employee.csv", ios::in);
    string s;
    cout << "\nEnter the ID to search: ";
    cin >> s;
    string mystring;
    while (mystring != s)
    {
        MyExcel >> mystring;
    }
    while (mystring != "\n")
    {
        mystring = MyExcel.get();
        cout << mystring;
    }
    MyExcel.close();
}

void admin()
{
    int in = 0;
    while (in != 6)
    {
        cout << "\n1. New Employ Entry \t\t\t2. Check for revenue \t\t\t3. Check for salaries given " << endl;
        cout << "4. Display the users/Employees \t\t5. Search employee details \t\t6. Exit" << endl;
        cout << "\nEnter the desired option : ";
        cin >> in;
        if (in == 1)
        {
            int choice;
            cout << "\n\t1. Manager 2. Coach 3. Others" << endl;
            cout << "Enter the type of employee you want to add: ";
            cin >> choice;
            if (choice == 1)
            {
                Manager m;
                m.input();
            }
            else if (choice == 2)
            {
                Coach c;
                c.input();
            }
            else if (choice == 3)
            {
                Other o;
                o.input();
            }
        }
        else if (in == 2)
        {
            Accounts a;
            a.get_revenue();
        }
        else if (in == 3)
        {
            Accounts a;
            a.salary();
        }
        else if (in == 4)
        {
            int choice;
            cout << "\n1. Display Users 2. Display Employees" << endl;
            cin >> choice;
            if (choice == 1)
            {
                display();
            }
            else if (choice == 2)
            {
                displaye();
            }
        }
        else if (in == 5)
        {
            search();
        }
    }
}
void DietChart(int x, int y)
{
    if (x == 0)
    {
        if (y == 0)
        {
            cout << "Breakfast 	2 egg brown bread sandwich + green chutney + 1 cup milk + 3 cashews + 4 almonds + 2 walnuts\n";
            cout << "Mid-Meal 	1 cup banana shake\n";
            cout << "Lunch 	 	1 cup arhar dal + 1 cup potato curry + 3 chapatti + 1/2 cup rice + 1/2 cup low fat curd + salad\n";
            cout << "Evening 	1 cup strawberry smoothie + 1 cup vegetable poha\n";
            cout << "Dinner 	 	1 cup beans potato vegetable + 3 chapatti + salad\n";
        }
        if (y == 1)
        {
            cout << "Breakfast 	3 paneer stuffed besan cheela + green chutney + 1 cup curd + 3 cashews + 4 almonds + 2 walnuts\n";
            cout << "Mid-Meal 	1 apple smoothie with maple syrup\n";
            cout << "Lunch 	 	1 cup masoor dal + 1 cup calocasia + 3 chapatti + 1/2 cup rice + 1 cup low curd + salad\n";
            cout << "Evening 	1 cup tomato soup with bread crumbs + 1 cup aloo chaat\n";
            cout << "Dinner  	1 cup carrot peas vegetable +3 chapatti + salad\n";
        }
        if (y == 2)
        {
            cout << "Breakfast 	1.5 cup vegetable bread upma + 1 cup milk + 3 cashews + 4 almonds + 2 walnuts\n";
            cout << "Mid-Meal 	1 cup ripe banana with 2 tsp ghee\n";
            cout << "Lunch    	1 cup rajma curry + 1 cup spinach potato + 3 chapatti + 1/2 cup rice + salad\n";
            cout << "Evening 	1 cup vegetable juice + 1 cup upma\n";
            cout << "Dinner   	1.5 cup parwal vegetable + 3 chapatti + salad\n";
        }
    }
    if (x == 1)
    {
        if (y == 0)
        {
            cout << "Breakfast 	3 egg whites + 1 toasted brown bread + 1/2 cup low fat milk (no sugar)\n";
            cout << "Mid-Meal 	1 cup papaya\n";
            cout << "Lunch 	 	1 cup arhar dal + 1 chapatti + 1/2 cup low fat curd + salad\n";
            cout << "Evening 	1 cup vegetable soup\n";
            cout << "Dinner 	 	1 cup pumpkin + 1 chapatti + salad\n";
        }
        if (y == 1)
        {
            cout << "Breakfast 	1 onion stuffed chapatti + 1/2 cup low fat curd\n";
            cout << "Mid-Meal 	1 cup coconut water\n";
            cout << "Lunch 	 	1 cup moong dal/ chicken curry + 1 chapatti + salad\n";
            cout << "Evening 	1 cup pomegranate\n";
            cout << "Dinner  	1 cup beans + 1 chapatti + salad\n";
        }
        if (y == 2)
        {
            cout << "Breakfast 	2 besan cheela + 1/2 cup low fat curd\n";
            cout << "Mid-Meal 	1 apple\n";
            cout << "Lunch    	1 cup masoor dal + 1 chapatti + 1/2 up low fat curd + salad\n";
            cout << "Evening 	1 cup tomato soup\n";
            cout << "Dinner   	1 cup carrot peas vegetable +1 chapatti + salad\n";
        }
    }
    if (x == 2)
    {
        if (y == 0)
        {
            cout << "Breakfast 	1 cup vegetable brown bread upma + 1/2 cup low fat milk (no sugar\n";
            cout << "Mid-Meal 	1 cup musk melon\n";
            cout << "Lunch 	 	1 cup rajma curry + 1 chapatti + salad\n";
            cout << "Evening 	1 cup vegetable soup\n";
            cout << "Dinner 	 	1 cup parwal vegetable + 1 chapatti + salad\n";
        }
        if (y == 1)
        {
            cout << "Breakfast 	1 cucmber hungcurd sandwich + 1/2 tsp green chutney + 1 orange\n";
            cout << "Mid-Meal 	1 cup buttermilk\n";
            cout << "Lunch 	 	1 cup white chana/ fish curry + 1 chapatti + salad\n";
            cout << "Evening 	1 cup low fat milk (no sugar)\n";
            cout << "Dinner  	1 cup cauliflower vegetable + 1 chapatti + salad\n";
        }
        if (y == 2)
        {
            cout << "Breakfast 	1 cup vegetable poha + 1 cup low fat curd\n";
            cout << "Mid-Meal 	1 cup watermelon\n";
            cout << "Lunch    	1 cup chana dal + 1 chapatti + salad\n";
            cout << "Evening 	1 cup sprouts salad\n";
            cout << "Dinner   	1 cup tinda vegetable + 1 chapatti + salad\n";
        }
    }
    if (x == 3)
    {
        if (y == 0)
        {
            cout << "Breakfast 	1 cup sabudana khichadi+peanuts\n";
            cout << "Mid-Meal 	1 cup lime juice\n";
            cout << "Lunch 	 	2 Besan Cheela + Yogurt\n";
            cout << "Evening 	1 cup Green Tea\n";
            cout << "Dinner 	 	Fruit Smoothie + salad\n";
        }
        if (y == 1)
        {
            cout << "Breakfast 	1 cup dry fruits + 1/2 cup papaya shake \n";
            cout << "Mid-Meal 	1 cup coconut water\n";
            cout << "Lunch 	 	2 whole grain roti + 1 cup paneer sabzi\n";
            cout << "Evening 	1 cup fruit bowl\n";
            cout << "Dinner  	1 Tortorella wrap + salad\n";
        }
        if (y == 2)
        {
            cout << "Breakfast 	1 Apple + 1 small cup oats (cooked in water)\n";
            cout << "Mid-Meal 	1 cup warm water with apple cider vinegar\n";
            cout << "Lunch    	1/2 cup boiled (black lentils + kidney beans)\n";
            cout << "Evening 	2 Brown Break Slices withput topping\n";
            cout << "Dinner   	2 cup vegetable soup\n";
        }
    }
    if (x == 4)
    {
        if (y == 0)
        {
            cout << "Breakfast 	Aloo Paratha (2) + Raita (1 cup)\n";
            cout << "Mid-Meal 	Fruit Salad (1 cup) + Tender Coconut Water (1 glass)\n";
            cout << "Lunch 	 	1 cup moong dal + 1 cup bhindi + 2 chapatti + salad\n";
            cout << "Evening 	Tea/ Coffee (1 cup) + Boiled Chana Chat (1 cup)\n";
            cout << "Dinner 	 	Chapati (2) + Jeera Aloo (1 cup)\n";
        }
        if (y == 1)
        {
            cout << "Breakfast 	Chapati (2) + Daal (1 cup)\n";
            cout << "Mid-Meal 	Fruit Salad (1 cup) + Tender Coconut Water (1 glass)\n";
            cout << "Lunch 	 	1 cup rajma + 1 cup gobhi aloo + 1 cup cucumber raita + 1 cup rice + 1 chapatti + onion salad\n";
            cout << "Evening 	Tea/ Coffee (1 cup) + Aloo Chat (1 cup)\n";
            cout << "Dinner  	Chapati (2) + Mix Veg.\n";
        }
        if (y == 2)
        {
            cout << "Breakfast 	Veg. Poha (1 cup) + Raita (1/2 cup)\n";
            cout << "Mid-Meal 		Fruit Salad (1 cup) + Tender Coconut Water (1 glass)\n";
            cout << "Lunch    	1 cup white chana + palak paneer + 1 cup rice + 1 chapatti + salad\n";
            cout << "Evening 	Tea/ Coffee (1 cup) + Mur-mure Chat (1 cup)\n";
            cout << "Dinner   	Chapati (2) + Mustard Greens (1 cup)\n";
        }
    }
    cout << "\n\nNOTE :\n\n";
    cout << "1.Don't Skip Meals.\n2.Try To Eat Meal On Time.\n3.Drink Plenty Of Water When You Are Hungry(13-16 glass)\n";
    cout << "4.Don't Use Sausage's,Mayonies,Cheese.\n4.Don't Forget About The Calories You Drink.\n\n\n";
}
float BMI(float weight, float height)
{
    float res = (weight) / (height * height);
    int x = res * 100 + 0.5;
    res = x / 100.0;
    return res;
}
float Fat_Percentage(int age, float bmi)
{
    float res = (1.20) * (bmi) + (0.23 * age) - 5.4;
    int x = res * 100 + 0.5;
    res = x / 100.0;
    return res;
}
float Ideal_Weight(float height, char c)
{
    int res;
    if (c == 'M' || c == 'M' + 32)
    {
        res = ((height / (2.54)) - 60) * 2.3 + 50;
    }
    else
    {
        res = ((height / (2.54)) - 60) * 2.3 + 45.5;
    }
    int x = res * 100 + 0.5;
    res = x / 100.0;
    return res;
}
void Healithfy()
{
    srand(time(NULL));
    int random = rand() % 3;
    cout << "Hello,Please Enter The Below Necessary Details : \n\n";
    char c;
    float height, weight, age, waist, hip, neck, chest;
    cout << "Sex (M/F) : ";
    cin >> c;
    cout << "Age : ";
    cin >> age;
    cout << "Height (in meters) : ";
    cin >> height;
    cout << "Weight (in kg) : ";
    cin >> weight;
    cout << "Waist (in inches) : ";
    cin >> waist;
    cout << "Hip (in inches) : ";
    cin >> hip;
    cout << "Neck (in inches) : ";
    cin >> neck;
    cout << "Chest (in inches) : ";
    cin >> chest;
    float z = BMI(weight, height);
    float x = Fat_Percentage(age, z);
    int dietplan;
    cout << "\nYour BMI is " << z << endl;
    if (z < 18.5)
    {
        cout << "You Are Underweight.\n";
        dietplan = 0;
    }
    else if (18.5 <= z && z < 25)
    {
        cout << "You Have Normal Weight.\n";
        dietplan = 4;
    }
    else if (25 <= z && z < 30)
    {
        cout << "You Are OverWeight.\n";
        dietplan = 1;
    }
    else if (30 <= z && z < 35)
    {
        cout << "You Have Class I Obesity .\n";
        dietplan = 2;
    }
    else if (35 <= z && z < 40)
    {
        cout << "You Have Class II Obesity .\n";
        dietplan = 2;
    }
    else
    {
        cout << "You Have Class III Obesity .\n";
        dietplan = 3;
    }
    cout << "Your Fat Percentage Is " << x << "%\n\n\n";
    cout << "Ideal Scenario According To Your Age and Height Should Be :\n";
    float y = Ideal_Weight(height * 100, c);
    float bmi_ideal = BMI(y, height);
    float ideal_fat = Fat_Percentage(age, bmi_ideal);
    cout << "Weight = " << y << "kgs\n";
    cout << "BMI = " << bmi_ideal << endl;
    cout << "Fat Percentage = " << ideal_fat << "%" << endl;
    cout << "\n\nTo Help You These Goals Follow The Below Die Chart : \n\n";
    DietChart(dietplan, random);
}
int main()
{
    ifstream emp;
    emp.open("empcount.csv", ios::in);
    emp >> m >> c >> o;

    int choice = 0;
    bool wrong_pass = false;

    while (choice != 3)
    {

        if (wrong_pass)
        {
            for (int i = 15; i >= 0; i--)
            {
                system("cls");
                title();
                addons();
                cout << "\n\t\t\t\t\t\t-------------WELCOME TO THE SPORTIFY---------------" << endl;
                cout << "\t\t\t\t\t\t\tYour Journey to fitness begins here" << endl
                     << endl;
                cout << "\n\tTRY OUT AFTER : " << i << " secs!" << endl;
                Sleep(1000);
            }

            wrong_pass = false;
        }
        system("cls");
        title();
        addons();
        cout << "\n\t\t\t\t\t\t-------------WELCOME TO THE SPORTIFY---------------" << endl;
        cout << "\t\t\t\t\t\t\tYour Journey to fitness begins here" << endl
             << endl;
        cout << "\nEnter your position (1 for user/2 for admin/3 Exit): ";

        cin >> choice;
        if (choice == 2)
        {
            int attempts = 3;
            string pass;
            char ch;
            for (int i = attempts; i > 0; i--)
            {
                cout << "\n\t" << i << " attempts remaining!" << endl;
                cout << "\nEnter the password : ";
                ch = _getch();
                while (ch != 13)
                {
                    if (ch != 8)
                    {
                        pass.push_back(ch);
                        cout << '*';
                    }
                    ch = _getch();
                }
                cout << endl;
                if (pass == PASSWORD)
                    break;

                else
                    pass = "";
            }

            if (pass == PASSWORD)
            {
                wrong_pass = false;
                cout << endl;
                admin();
            }

            else
            {
                cout << "\n\n\tERROR : TOO MANY WRONG ATTEMPTS !!!" << endl;
                wrong_pass = true;
                Sleep(1000);
            }
        }
        else if (choice == 1)
        {
            int in;
            User u;
            while (in != 4)
            {
                cout << "\n1. New Entry \t\t2. Check for Plans \t\t3. Healthify \t\t4. Exit" << endl;
                cout << "\nEnter the desired option: ";
                cin >> in;
                if (in == 1)
                {

                    cin.ignore(256, '\n');
                    u.get_data_1();
                    int z = sportschoosen(&u);
                    while (z == -1)
                    {
                        z = sportschoosen(&u);
                    }
                    cout << "Entered Details: " << endl
                         << endl;
                    cout << "Name\t\tAge\tPhone No.\tSports  Fees\tTime Slot\tDate of joining" << endl
                         << endl;
                    curdisplay();
                }
                else if (in == 2)
                {
                    c1.display();
                    f1.display();
                    b1.display();
                    t1.display();
                }
                else if (in == 3)
                {
                    Healithfy();
                }
            }
        }
        else if (choice != 3)
        {
            cout << "\n\t\tERROR : CHOOSE A VALID OPTION !!!! " << endl;
            Sleep(2000);
        }
    }

    thanks();
    cout << "\n\n\n\t\tThank You for choosing SPORTIFY!!" << endl;
    cout << "\t\tHave a nice day !!!\n"
         << endl;
    return 0;
}