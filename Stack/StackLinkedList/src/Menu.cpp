#include "../include/Menu.h"

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
    Stack stack;
    int flag = 0;
    int cp = 0;
    char menu[5][20] = {"Push", "Pop", "Peek", "Display", "Exit"};
    char ch;

    int value;

    do
    {
        system("cls");

        for (int i = 0; i < 5; i++)
        {
            if (i == cp)
                textattr(0x94);
            gotoxy(20, 5 + i);
            cout << menu[i];
            textattr(0x07);
        }

        ch = getch();
        switch (ch)
        {
        case -32:
            ch = getch();
            switch (ch)
            {
            case 72:
                cp--;
                if (cp < 0)
                    cp = 4;
                break;

            case 80:
                cp++;
                if (cp > 4)
                    cp = 0;
                break;
            }
            break;

        case 13:
            if (cp == 0)
            {
                system("cls");
                gotoxy(20, 5);
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                gotoxy(20, 7);
                cout << "Value " << value << " pushed successfully!";
                cout << "\nPress any key to continue...";
                getch();
            }
            else if (cp == 1)
            {
                system("cls");
                gotoxy(20, 5);
                if (stack.isEmpty())
                {
                    cout << "Stack is empty! Cannot pop.";
                }
                else
                {
                    int poppedValue = stack.pop();
                    cout << "Popped value: " << poppedValue;
                }
                cout << "\nPress any key to continue...";
                getch();
            }
            else if (cp == 2)
            {
                system("cls");
                gotoxy(20, 5);
                if (stack.isEmpty())
                {
                    cout << "Stack is empty!";
                }
                else
                {
                    cout << "Top element: " << stack.peek();
                }
                cout << "\nPress any key to continue...";
                getch();
            }
            else if (cp == 3)
            {
                system("cls");
                gotoxy(20, 5);
                cout << "=== Stack Contents ===" << endl;
                gotoxy(20, 6);
                cout << "Size: " << stack.getSize() << endl;
                gotoxy(20, 7);
                cout << "Elements (top to bottom): ";
                stack.display();
                cout << "\nPress any key to continue...";
                getch();
            }
            else if (cp == 4)
            {
                flag = 1;
            }
            break;

        case 27:
            flag = 1;
            break;
        }
    } while (flag == 0);

    system("cls");
    gotoxy(20, 10);
    cout << "Thank you for using the Stack Management System!" << endl;
}
