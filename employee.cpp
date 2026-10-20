#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node* left;
    Node* right;
};

Node* createNode(int id)
{
    Node* newNode = new Node;
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int id)
{
    if (root == NULL)
        return createNode(id);

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}

void display(Node* root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << root->id << " ";
        display(root->right);
    }
}

void search(Node* root, int id)
{
    if (root == NULL)
    {
        cout << "Employee ID not found\n";
        return;
    }

    if (root->id == id)
        cout << "Employee ID found\n";
    else if (id < root->id)
        search(root->left, id);
    else
        search(root->right, id);
}

int main()
{
    Node* root = NULL;
    int choice, id;

    do
    {
        cout << "\n1. Insert Employee ID";
        cout << "\n2. Display Employee IDs";
        cout << "\n3. Search Employee ID";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                root = insert(root, id);
                cout << "Employee ID inserted\n";
                break;

            case 2:
                cout << "Employee IDs: ";
                display(root);
                cout << endl;
                break;

            case 3:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                search(root, id);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}