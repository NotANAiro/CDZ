#include <iostream>

#include <string>

#include <algorithm>

#include <fstream>

using namespace std;

struct Task {

    string title;

    int priority;

    string description;

    int day;
    int month;
    int year;


};

void printTask(const Task& task) {

    cout << "Task title: " << task.title << endl;

    cout << "Priority: " << task.priority << endl;
    
    cout << "Description: " << task.description << endl;

    cout << "Date: " << task.day << "." << task.month << "."<<task.year << endl;
    cout << endl;

}

void editTask(Task& task) {

    cout << "Enter new title: ";

    getline(cin >> ws, task.title);

    cout << "Enter new priority: ";

    cin >> task.priority;

    cout << "Enter new description: ";

    getline(cin >> ws, task.description);

    cout << "Enter new date: ";

    cin >> task.day;
    cin >> task.month;
    cin >> task.year;

   
}
void loadTasks(const Task taskList[], int size) {
    ofstream out;   // ofstream out("test.txt");
    out.open("D:\\test.txt");

    if (!out) {
        cout << "Open file error!";
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        out << "Task title: " << taskList[i].title << endl;
        out << "Task priority: " << taskList[i].priority << endl;
        out << "Task description: " << taskList[i].description << endl;
        out << "Date: " << taskList[i].day << "." << taskList[i].month << "." << taskList[i].year << endl;

        if (i < size - 1) {
            out << endl;
        }
    }

    out.close();
}

void printAllTasks(const Task taskList[], int size) {

    cout << "List of the tasks:" << endl;

    for (int i = 0; i < size; i++) {

        cout << "Task " << i + 1 << ":" << endl;

        printTask(taskList[i]);

    }
    

}

void searchByDescription(const Task taskList[], int size, const string& description) {

    cout << "Tasks with this description " << description << ":" << endl;

    bool found = false;

    for (int i = 0; i < size; i++) {

        if (taskList[i].description == description) {

            printTask(taskList[i]);

            found = true;

        }

    }

    if (!found) {

        cout << "Task not found." << endl;

    }

}

void searchByTitle(const Task taskList[], int size, const string& title) {

    cout << "Tasks with title \"" << title << "\":" << endl;

    bool found = false;

    for (int i = 0; i < size; i++) {

        if (taskList[i].title == title) {

            printTask(taskList[i]);

            found = true;

        }

    }

    if (!found) {

        cout << "Task not found." << endl;

    }

}

void searchByDay(const Task taskList[], int size, const int& day, const int& month, const int& year) {

    cout << "Tasks for day: \"" << "\":" << endl;

    bool found = false;

    for (int i = 0; i < size; i++) {

        if (taskList[i].day == day and taskList[i].month == month and taskList[i].year == year) {

            printTask(taskList[i]);

            found = true;

        }

    }

    if (!found) {

        cout << "Task not found." << endl;

    }

}

void searchByWeek(const Task taskList[], int size, const int& day, const int& month, const int& year) {

    cout << "Tasks for a week: \"" << "\":" << endl;

    bool found = false;

    for (int i = 0; i < size; i++) {

        if (taskList[i].day >= day and taskList[i].day <= day+7 and taskList[i].month == month and taskList[i].year == year) {

            printTask(taskList[i]);

            found = true;

        }

    }

    if (!found) {

        cout << "Task not found." << endl;

    }

}

void searchByMonth(const Task taskList[], int size, const int& month,const int& year) {

    cout << "Tasks for month: \"" << "\":" << endl;

    bool found = false;

    for (int i = 0; i < size; i++) {

        if (taskList[i].month == month and taskList[i].year == year) {

            printTask(taskList[i]);

            found = true;

        }

    }

    if (!found) {

        cout << "Task not found." << endl;

    }

}

bool compareByTitle(const Task& task1, const Task& task2) {

    return task1.title < task2.title;

}

bool compareByDescription(const Task& task1, const Task& task2) {

    return task1.description < task2.description;

}

bool compareByPriority(const Task& task1, const Task& task2) {

    return task1.priority < task2.priority;

}
void sortByDate(Task taskList[], int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (taskList[i].year > taskList[j].year ||
                taskList[i].year == taskList[j].year &&
                taskList[i].month > taskList[j].month ||
                taskList[i].year == taskList[j].year &&
                taskList[i].month == taskList[j].month &&
                taskList[i].day > taskList[j].day)
            {
                Task temp = taskList[j];
                taskList[j] = taskList[i];
                taskList[i] = temp;
            }
        }
    }
}

    void sortTasksByTitle(Task taskList[], int size) {

    sort(taskList, taskList + size, compareByTitle);

}

void sortTasksByDescription(Task taskList[], int size) {

    sort(taskList, taskList + size, compareByDescription);

}

void sortTasksByPriority(Task taskList[], int size) {

    sort(taskList, taskList + size, compareByPriority);

}



void addNewTask(Task taskList[], int& size) {


    Task newTask;

    cout << "Enter title: ";

    getline(cin >> ws, newTask.title);

    cout << "Enter priority: ";

    cin >> newTask.priority;

    cout << "Enter description: ";

    getline(cin >> ws, newTask.description);

    cout << "Enter date: ";

    cin >> newTask.day;
    cin >> newTask.month;
    cin >> newTask.year;


    taskList[size] = newTask;

    size++;

    cout << "Task successfully added." << endl;

}

int main() {

    Task taskList[10];

    int size = 0;


    Task book1 = { "B1", 3, "B", 12,03,2021};

    Task book2 = { "A2", 1, "You need to do task",15,03,2021};

    Task book3 = { "D2", 1, "A",12,01,2023 };

    Task book4 = { "C", 1, "You need to do task",14,03,2023 };

    taskList[size++] = book1;

    taskList[size++] = book2;

    taskList[size++] = book3;

    taskList[size++] = book4;

    

    addNewTask(taskList, size);

    editTask(taskList[0]);
    cout << "By day;" << endl;
    searchByDay(taskList, size, 12, 1, 2023);
    

    cout << "By week;" << endl;
    searchByWeek(taskList, size, 12, 3, 2021);
    

    cout << "By month;" << endl;
    searchByMonth(taskList, size, 3, 2023);
    

    searchByDescription(taskList, size, "You need to do task");

    searchByTitle(taskList, size, "Task1");
    cout << "Sorted by title"<<endl;
    sortTasksByTitle(taskList, size);
    loadTasks(taskList, size);
    
    printAllTasks(taskList, size);
    cout << "Sorted by Description" << endl;

    sortTasksByDescription(taskList, size);
    printAllTasks(taskList, size);
    cout << "Sorted by Priority" << endl;

    sortTasksByPriority(taskList, size);
    printAllTasks(taskList, size);
    cout << "Sorted by Date" << endl;

    sortByDate(taskList,size);
    printAllTasks(taskList, size);

    return 0;

}