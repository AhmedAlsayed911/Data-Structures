#include "../headers/Menu.h"

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void runMenu()
{
    LinkedList list;
    int flag = 0;
    int cp = 0, subCp = 0;
    int inSub = 0;
    char menu[6][20] = {"New", "Display", "Count", "Search", "Delete", "Exit"};
    char newSubMenu[3][20] = {"Append", "Insert First", "Insert Middle"};
    char searchSubMenu[2][20] = {"By ID", "By Name"};
    char deleteSubMenu[3][20] = {"By ID", "By Name", "Delete All"};
    char ch;

    int id, age;
    char name[50];

    do
    {
        system("cls");

        for (int i = 0; i < 6; i++)
        {
            if (inSub == 0 && i == cp)
                textattr(0x94);
            gotoxy(20, 5 + i);
            cout << menu[i];
            textattr(0x07);
        }

        if (inSub == 1 && cp == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i == subCp)
                    textattr(0x94);
                gotoxy(40, 5 + i);
                cout << newSubMenu[i];
                textattr(0x07);
            }
        }

        if (inSub == 1 && cp == 3)
        {
            for (int i = 0; i < 2; i++)
            {
                if (i == subCp)
                    textattr(0x94);
                gotoxy(40, 5 + i);
                cout << searchSubMenu[i];
                textattr(0x07);
            }
        }

        if (inSub == 1 && cp == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i == subCp)
                    textattr(0x94);
                gotoxy(40, 5 + i);
                cout << deleteSubMenu[i];
                textattr(0x07);
            }
        }

        ch = getch();
        switch (ch)
        {
        case -32:
            ch = getch();
            switch (ch)
            {
            case 72:
                if (inSub == 0)
                {
                    cp--;
                    if (cp < 0)
                        cp = 5;
                }
                else
                {
                    subCp--;
                    if (subCp < 0)
                    {
                        if (cp == 0) subCp = 2;
                        else if (cp == 3) subCp = 1;
                        else if (cp == 4) subCp = 2;
                    }
                }
                break;

            case 80:
                if (inSub == 0)
                {
                    cp++;
                    if (cp > 5)
                        cp = 0;
                }
                else
                {
                    subCp++;
                    if (cp == 0 && subCp > 2) subCp = 0;
                    else if (cp == 3 && subCp > 1) subCp = 0;
                    else if (cp == 4 && subCp > 2) subCp = 0;
                }
                break;

            case 75:
                if (inSub == 1)
                {
                    inSub = 0;
                }
                break;
            }
            break;

        case 13:
            if (inSub == 0)
            {
                if (cp == 0)
                {
                    inSub = 1;
                    subCp = 0;
                }
                else if (cp == 1)
                {
                    system("cls");
                    gotoxy(20, 5);
                    cout << "=== Employee List ===" << endl;
                    list.Display();
                    cout << "\nPress any key to continue...";
                    getch();
                }
                else if (cp == 2)
                {
                    system("cls");
                    gotoxy(20, 10);
                    cout << "Total Employees: " << list.Count() << endl;
                    cout << "\nPress any key to continue...";
                    getch();
                }
                else if (cp == 3)
                {
                    inSub = 1;
                    subCp = 0;
                }
                else if (cp == 4)
                {
                    inSub = 1;
                    subCp = 0;
                }
                else if (cp == 5)
                {
                    flag = 1;
                }
            }
            else
            {
                if (cp == 0)
                {
                    system("cls");
                    gotoxy(20, 5);
                    cout << "Enter Employee ID: ";
                    cin >> id;
                    gotoxy(20, 6);
                    cout << "Enter Employee Name: ";
                    cin.ignore();
                    cin.getline(name, 50);
                    gotoxy(20, 7);
                    cout << "Enter Employee Age: ";
                    cin >> age;

                    if (subCp == 0)
                    {
                        list.Append(id, name, age);
                        gotoxy(20, 9);
                        cout << "Employee added successfully!";
                    }
                    else if (subCp == 1)
                    {
                        list.InsertFirst(id, name, age);
                        gotoxy(20, 9);
                        cout << "Employee inserted at the beginning!";
                    }
                    else if (subCp == 2)
                    {
                        list.InsertMiddle(id, name, age);
                        gotoxy(20, 9);
                        cout << "Employee inserted in the middle!";
                    }
                    cout << "\nPress any key to go back...";
                    getch();
                    inSub = 0;
                }
                else if (cp == 3)
                {
                    system("cls");
                    gotoxy(20, 5);
                    if (subCp == 0)
                    {
                        cout << "Enter Employee ID to search: ";
                        cin >> id;
                        gotoxy(20, 7);
                        list.searchById(id);
                    }
                    else if (subCp == 1)
                    {
                        cout << "Enter Employee Name to search: ";
                        cin.ignore();
                        cin.getline(name, 50);
                        gotoxy(20, 7);
                        list.SearchByName(name);
                    }
                    cout << "\nPress any key to go back...";
                    getch();
                    inSub = 0;
                }
                else if (cp == 4)
                {
                    system("cls");
                    gotoxy(20, 5);
                    if (subCp == 0)
                    {
                        cout << "Enter Employee ID to delete: ";
                        cin >> id;
                        list.DeleteById(id);
                        gotoxy(20, 7);
                        cout << "Employee deleted (if found)!";
                    }
                    else if (subCp == 1)
                    {
                        cout << "Enter Employee Name to delete: ";
                        cin.ignore();
                        cin.getline(name, 50);
                        list.DeleteByName(name);
                        gotoxy(20, 7);
                        cout << "Employee deleted (if found)!";
                    }
                    else if (subCp == 2)
                    {
                        char confirm;
                        cout << "Are you sure you want to delete all employees? (y/n): ";
                        cin >> confirm;
                        if (confirm == 'y' || confirm == 'Y')
                        {
                            list.DeleteAll();
                            gotoxy(20, 7);
                            cout << "All employees deleted!";
                        }
                    }
                    cout << "\nPress any key to go back...";
                    getch();
                    inSub = 0;
                }
            }
            break;

        case 27:
            if (inSub == 1)
                inSub = 0;
            else
                flag = 1;
            break;
        }
    } while (flag == 0);

    system("cls");
    gotoxy(20, 10);
    cout << "Thank you for using the Employee Management System!" << endl;
}
