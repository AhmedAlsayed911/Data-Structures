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
    Queue queue;
    int flag = 0;
    int cp = 0;
    char menu[5][20] = {"Enqueue", "Dequeue", "Display", "Is Empty", "Exit"};
    char ch;

    int data;

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
            case 72: // Up arrow
                cp--;
                if (cp < 0)
                    cp = 4;
                break;

            case 80: // Down arrow
                cp++;
                if (cp > 4)
                    cp = 0;
                break;
            }
            break;

        case 13: // Enter
            if (cp == 0) // Enqueue
            {
                system("cls");
                gotoxy(20, 5);
                cout << "Enter data to enqueue: ";
                cin >> data;
                queue.enqueue(data);
                gotoxy(20, 7);
                cout << "Data enqueued successfully!";
                cout << "\nPress any key to continue...";
                getch();
            }
            else if (cp == 1) // Dequeue
            {
                system("cls");
                gotoxy(20, 5);
                int value = queue.dequeue();
                if (value == -1)
                {
                    cout << "Queue is Empty! Cannot dequeue.";
                }
                else
                {
                    cout << "Dequeued value: " << value;
                }
                cout << "\nPress any key to continue...";
                getch();
            }
            else if (cp == 2) // Display
            {
                system("cls");
                gotoxy(20, 5);
                cout << "=== Queue Contents ===" << endl;
                gotoxy(20, 6);
                queue.display();
                cout << "\nPress any key to continue...";
                getch();
            }
            else if (cp == 3) // Is Empty
            {
                system("cls");
                gotoxy(20, 5);
                if (queue.isEmpty())
                {
                    cout << "Queue is Empty!";
                }
                else
                {
                    cout << "Queue is NOT Empty!";
                }
                cout << "\nPress any key to continue...";
                getch();
            }
            else if (cp == 4) // Exit
            {
                flag = 1;
            }
            break;

        case 27: // Escape
            flag = 1;
            break;
        }
    } while (flag == 0);

    system("cls");
    gotoxy(20, 10);
    cout << "Thank you for using the Queue Management System!" << endl;
}
