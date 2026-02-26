#include <iostream>
#include <string>

using namespace std;

// Maximum number of tasks
const int MAX_TASKS = 100;

// Simple arrays to store task data
string tasks[MAX_TASKS];
bool completed[MAX_TASKS];
int taskCount = 0;

// Function to add a new task
void addTask()
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "Task list is full!\n";
        return;
    }

    cout << "Enter task description: ";
    string description;
    getline(cin, description);

    tasks[taskCount] = description;
    completed[taskCount] = false;
    taskCount++;

    cout << "Task added successfully!\n";
}

// Function to list all tasks
void listTasks()
{
    if (taskCount == 0)
    {
        cout << "No tasks found.\n";
        return;
    }

    cout << "\n===== TODO LIST =====\n";
    for (int i = 0; i < taskCount; i++)
    {
        cout << "[" << (i + 1) << "] ";

        if (completed[i])
        {
            cout << "[X] ";
        }
        else
        {
            cout << "[ ] ";
        }

        cout << tasks[i] << "\n";
    }
    cout << "=====================\n\n";
}

// Function to mark task as complete
void completeTask()
{
    listTasks();

    if (taskCount == 0)
    {
        return;
    }

    cout << "Enter task number to complete: ";
    int num;
    cin >> num;
    cin.ignore(); // Clear the newline from input buffer

    if (num < 1 || num > taskCount)
    {
        cout << "Invalid task number!\n";
        return;
    }

    completed[num - 1] = true;
    cout << "Task marked as completed!\n";
}

// Function to delete a task
void deleteTask()
{
    listTasks();

    if (taskCount == 0)
    {
        return;
    }

    cout << "Enter task number to delete: ";
    int num;
    cin >> num;
    cin.ignore(); // Clear the newline from input buffer

    if (num < 1 || num > taskCount)
    {
        cout << "Invalid task number!\n";
        return;
    }

    // Shift all tasks after the deleted one
    for (int i = num - 1; i < taskCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
        completed[i] = completed[i + 1];
    }

    taskCount--;
    cout << "Task deleted successfully!\n";
}

// Function to show menu
void showMenu()
{
    cout << "\n===== TODO MANAGER =====\n";
    cout << "1. Add Task\n";
    cout << "2. List Tasks\n";
    cout << "3. Complete Task\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "========================\n";
    cout << "Choose an option: ";
}

int main()
{
    cout << "Welcome to Simple Todo Manager!\n";

    int choice;

    while (true)
    {
        showMenu();
        cin >> choice;
        cin.ignore(); // Clear the newline from input buffer

        if (choice == 1)
        {
            addTask();
        }
        else if (choice == 2)
        {
            listTasks();
        }
        else if (choice == 3)
        {
            completeTask();
        }
        else if (choice == 4)
        {
            deleteTask();
        }
        else if (choice == 5)
        {
            cout << "Goodbye!\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}