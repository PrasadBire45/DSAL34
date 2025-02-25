#include <iostream>
#include <cstring>
using namespace std;

typedef struct node 
{
    char k[20];  
    char m[20]; 
    struct node* left;
    struct node* right;
} node;

class dict 
{
public:
    node* root;
    dict() 
    {
        root = NULL;  
    }
    void create();
    void insert(node* &root, node* temp);
    void display(node* root);
    int search(node* root, char k[20]);
    int update(node* root, char k[20]);
    node* del(node* root, char k[20]);
    node* min(node* q);
};

void dict::create() 
{
    node* temp;
    char ch;
    do 
    {
        temp = new node;
        cout << "\nEnter keyword: ";
        cin >> temp->k;
        cout << "Enter meaning: ";
        cin >> temp->m;

        temp->left = NULL;
        temp->right = NULL;

        if (root == NULL) 
        {
            root = temp;
        } 
        else 
        {
            insert(root, temp);
        }

        cout << "Do you want to add more (y/Y): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void dict::insert(node*& root, node* temp) 
{
    if (strcmp(temp->k, root->k) < 0) 
    {
        if (root->left == NULL) 
        {
            root->left = temp;
        } 
        else 
        {
            insert(root->left, temp);
        }
    } 
    else 
    {
        if (root->right == NULL) 
        {
            root->right = temp;
        } 
        else 
        {
            insert(root->right, temp);
        }
    }
}

void dict::display(node* root) 
{
    if (root != NULL) 
    {
        display(root->left);
        cout << "\nKeyword-> " << root->k;
        cout << "\n   Meaning-> " << root->m;
        display(root->right);
        cout << endl;
    }
}

int dict::search(node* root, char k[20]) 
{
    int count = 0;
    while (root != NULL) 
    {
        count++;
        if (strcmp(k, root->k) == 0)
        {
            cout << "Number of comparisons is : " << count << endl;
            cout << "Meaning: " << root->m << endl;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    cout << "Keyword not found." << endl;
    return -1;
}

int dict::update(node* root, char k[20])
{
    while (root != NULL)
    {
        if (strcmp(k, root->k) == 0)
        {
            cout << "Enter new meaning for keyword " << root->k << ": ";
            cin >> root->m;
            cout << "Meaning updated!" << endl;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    cout << "Keyword not found." << endl;
    return -1;
}

node* dict::del(node* root, char k[20])
{
    if (root == NULL)
    {
        cout << "Element not found." << endl;
        return root;
    }

    node* temp;

    if (strcmp(k, root->k) < 0)
    {
        root->left = del(root->left, k);
        return root;
    }
    if (strcmp(k, root->k) > 0)
    {
        root->right = del(root->right, k);
        return root;
    }

    if (root->right == NULL && root->left == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }
    if (root->right == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    if (root->left == NULL)
    {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }

    temp = min(root->right);
    strcpy(root->k, temp->k);
    root->right = del(root->right, temp->k);
    return root;
}

node* dict::min(node* q)
{
    while (q->left != NULL)
    {
        q = q->left;
    }
    return q;
}

int main() 
{
    dict obj;
    int choice;

    do 
    {
        cout << "\n1. Create Dictionary";
        cout << "\n2. Display Dictionary";
        cout << "\n3. SEARCH";
        cout << "\n4. UPDATE";
        cout << "\n5. DELETE";
        cout << "\n6. EXIT";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display(obj.root);
            break;
        case 3:
            cout << "Enter keyword you want to search: ";
            char k[20];
            cin >> k;
            obj.search(obj.root, k);
            break;
        case 4:
            cout << "Enter keyword you want to update: ";
            cin >> k;
            obj.update(obj.root, k);
            break;
        case 5:
            cout << "Enter keyword you want to delete: ";
            cin >> k;
            obj.root = obj.del(obj.root, k);
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

