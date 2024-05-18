#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
      {
    string description;
    bool completed;
      };

class TodoList  
{
private:
    vector<Task> tasks;

public:
    void addTasktodo(const string& description) 
       {
        tasks.push_back({description, false});
        cout<<"Task Added Successfully.\n";
       }

    void viewTasktodo()
       {
        cout<<"|||||||||| To-Do List ||||||||||\n";
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout<<i + 1<< "."<<tasks[i].description<<" - "<<(tasks[i].completed ? "Completed" : "Pending")<<endl;
        }
        cout<<"************\n";
      }

    void markTaskAsCompleted(size_t index)
    {
        if (index>=1 && index<=tasks.size())
        {
            tasks[index - 1].completed = true;
            cout<<"Task Marked As Completed.\n";
        } 
        else
        {
            cout<<"Invalid Task Index.\n";
        }
    }

    void removeTheTask(size_t index) 
    {
        if (index>=1 && index<=tasks.size()) 
        {
            tasks.erase(tasks.begin() + index - 1);
            cout<<"Task Removed Successfully.\n";
        } 
        else 
        {
            cout<<"Invalid Task Index.\n";
        }
    }
};

int main() 
{
    TodoList todoList;

    while (true)
    {
        cout<<"**************\n";
        cout<<"Choose An Option:\n";
        cout<<"1. Add Task\n";
        cout<<"2. View Tasks\n";
        cout<<"3. Mark Task As Completed\n";
        cout<<"4. Remove Task\n";
        cout<<"5. Exit\n";
        
        int ch;
        cout<<"*************\n";
        cout<<"Enter Your Option:";
        cin >> ch;

        switch (ch) 
        {
            case 1:
            {
                cout<<"Enter Task Description: ";
                string description;
                cin.ignore(); 
                getline(cin, description);
                todoList.addTasktodo(description);
                break;
            }
            case 2:
                todoList.viewTasktodo();
                break;
            case 3: 
            {
                cout<<"Enter The Index Of The Task To Mark As Completed: ";
                size_t index;
                cin>>index;
                todoList.markTaskAsCompleted(index);
                break;
            }
            case 4:
            {
                cout<<"Enter The Index Of The Task To Remove: ";
                size_t index;
                cin>>index;
                todoList.removeTheTask(index);
                break;
            }
            case 5:
                cout<<"Exiting Program\n";
                return 0;
            default:
                cout<<"Invalid Choice.Please Try Again.\n";
        }
    }

    return 0;
}