#include <iostream>
#include <string>
#include <iomanip> // added to maipulate viewAll
using namespace std;

const int MAX = 50;

// to store student data
string names[MAX];
float grades[MAX];
int count = 0;

void addStudent()
{
    if (count >= MAX)
    {
        cout << "List is full.\n";
        return;
    }

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, names[count]);

    cout << "Enter grade (0-100): ";
    cin >> grades[count];

    count++;
    cout << "Student added!\n";
}

// void viewAll()
// {
//     if (count == 0)
//     {
//         cout << "No students yet.\n";
//         return;
//     }

//     cout << "\nID  Name          Grade\n";
//     cout << "------------------------\n";
//     for (int i = 0; i < count; i++)
//     {
//         cout << i + 1 << "   " << names[i] << "     " << grades[i] << "\n";
//     }
// }

void viewAll()
{
    if (count == 0)
    {
        cout << "No students yet.\n";
        return;
    }

    cout << "\n"
         << setw(5) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Grade" << "\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        cout << setw(5) << i + 1
             << setw(20) << names[i]
             << setw(10) << grades[i] << "\n";
    }
}

void getAverage()
{
    if (count == 0)
    {
        cout << "No students yet.\n";
        return;
    }

    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += grades[i];
    }

    cout << "Class average: " << sum / count << "\n";
}

void deleteStudent()
{
    cout << "Enter ID to delete: ";
    int id;
    cin >> id;

    if (id < 1 || id > count)
    {
        cout << "Invalid ID.\n";
        return;
    }

    // Shift everything left to fill the gap
    for (int i = id - 1; i < count - 1; i++)
    {
        names[i] = names[i + 1];
        grades[i] = grades[i + 1];
    }
    count--;
    cout << "Student deleted.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- Student Grade Manager ---\n";
        cout << "1. Add Student\n";
        cout << "2. View All\n";
        cout << "3. Class Average\n";
        cout << "4. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            viewAll();
        else if (choice == 3)
            getAverage();
        else if (choice == 4)
            deleteStudent();
        else if (choice == 0)
            cout << "Bye!\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 0);

    return 0;
}