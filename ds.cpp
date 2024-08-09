#include <iostream>
#include <string>
using namespace std;

class BSTNode {
public:
    int priority;
    string taskName;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int priority, string taskName) {
        this->priority = priority;
        this->taskName = taskName;
        left = nullptr;
        right = nullptr;
    }
};

class PriorityQueue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    string taskNames[MAX_SIZE];
    bool done[MAX_SIZE];
    BSTNode* root;
    int size;

    void insertBST(BSTNode*& node, int priority, string taskName) {
        if (!node) {
            node = new BSTNode(priority, taskName);
            return;
        }
        if (taskName < node->taskName)
            insertBST(node->left, priority, taskName);
        else
            insertBST(node->right, priority, taskName);
    }

    BSTNode* searchBST(BSTNode* node, string taskName) {
        if (!node || node->taskName == taskName)
            return node;
        if (taskName < node->taskName)
            return searchBST(node->left, taskName);
        return searchBST(node->right, taskName);
    }

public:
    PriorityQueue() {
        size = 0;
        root = nullptr;
        fill_n(done, MAX_SIZE, false);
    }

    bool isEmpty() { return (size == 0); }
    bool isFull() { return (size == MAX_SIZE); }

    void push(int value, const string& taskName) {
        if (isFull()) {
            cout << "Priority queue is full. Cannot enqueue." << endl;
            return;
        }
        int i = size - 1;
        while (i >= 0 && arr[i] > value) {
            arr[i + 1] = arr[i];
            taskNames[i + 1] = taskNames[i];
            done[i + 1] = done[i];
            i--;
        }
        arr[i + 1] = value;
        taskNames[i + 1] = taskName;
        done[i + 1] = false;
        size++;

        insertBST(root, value, taskName);
        cout << "Task added with priority: " << value << endl;
    }

    bool markTaskAsDone(string taskName) {
        for (int i = 0; i < size; i++) {
            if (taskNames[i] == taskName && !done[i]) {
                done[i] = true;
                cout << "Task marked as done: " << taskName << endl;
                return true;
            }
        }
        cout << "Task not found or already marked as done." << endl;
        return false;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Priority queue is empty." << endl;
            return;
        }
        cout << "Tasks ordered by priority: " << endl;
        for (int i = 0; i < size; i++) {
            cout << "Priority: " << arr[i] << ", Task: " << taskNames[i] << (done[i] ? " (Done)" : " (Not Done)") << endl;
        }
        cout << endl;
    }

    void search(string taskName) {
        BSTNode* result = searchBST(root, taskName);
        if (result)
            cout << "Task found: " << result->taskName << " with priority " << result->priority << endl;
        else
            cout << "Task not found." << endl;
    }};

int main() {
    PriorityQueue pq;
    int choice;
    string taskName;

    do {
        cout << "\nTask Management System\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Done\n";
        cout << "3. Display Tasks by Priority\n";
        cout << "4. Search for a Task by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int priority;
                string name, description;
                cout << "Enter task name: ";
                cin.ignore();  // To handle leftover newline character if any
                getline(cin, name);
                cout << "Enter task priority: ";
                cin >> priority;
                cout << "Enter task description: ";
                cin.ignore();  // Clear the input buffer to correctly use getline next
                getline(cin, description);
                pq.push(priority, name);
                break;
            }
          case 2: {
              cout << "Enter task name to mark as done: ";
              cin.ignore();  // Ensure input buffer is clear
              getline(cin, taskName);  // Get the full task name as input
              pq.markTaskAsDone(taskName);  // Attempt to mark the task as done
              break;
          }

            case 3: {
                pq.displayQueue();
                break;
            }
            case 4: {
                cout << "Enter task name to search: ";
                cin.ignore();  // To handle leftover newline character if any
                getline(cin, taskName);
                pq.search(taskName);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
