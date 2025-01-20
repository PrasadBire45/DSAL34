#include<iostream>
using namespace std;

#define SIZE 20


struct node 
{
    char label[SIZE];         
    struct node* child[SIZE];
};


class Tree {
public:
    int i, j, k;
    int chapters, sections, subsections;
    node* root;

    Tree() 
    {
        root = NULL; 
    }

    
    void create() 
    {
        root = new node();  

        cout << "Enter name of the book: ";
        cin >> root->label;

        cout << "Enter number of chapters: ";
        cin >> chapters;

        
        for (i = 0; i < chapters; i++) 
        {
            root->child[i] = new node(); 

            cout << "\nEnter name of chapter " << i + 1 << ": ";
            cin >> root->child[i]->label;

            cout << "Enter number of sections in chapter " << i + 1 << ": ";
            cin >> sections;

            
            for (j = 0; j < sections; j++) 
            {
                root->child[i]->child[j] = new node();

                cout << "Enter name of section " << j + 1 << " in chapter " << i + 1 << ": ";
                cin >> root->child[i]->child[j]->label;

                cout << "Enter number of subsections in section " << j + 1 << ": ";
                cin >> subsections;

               
                for (k = 0; k < subsections; k++) 
                {
                    root->child[i]->child[j]->child[k] = new node(); 

                    cout << "Enter name of subsection " << k + 1 << " in section " << j + 1 << ": ";
                    cin >> root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }

    
    void display(node* r1) 
    {
        if (r1 == NULL) return;

        
        cout << "BOOK: " << r1->label << endl;

        
        for (i = 0; i < chapters; i++) 
        {
            cout << "Chapter " << i + 1 << ": " << r1->child[i]->label << endl;

            
            for (j = 0; j < sections; j++) 
            {
                cout << "  Section " << j + 1 << ": " << r1->child[i]->child[j]->label << endl;

                
                for (k = 0; k < subsections; k++) 
                {
                    cout << "    Subsection " << k + 1 << ": " << r1->child[i]->child[j]->child[k]->label << endl;
                }
            }
        }
    }

    
    void menu() {
        int choice;
        while (true) {
            cout << "\nMenu:" << endl;
            cout << "1. Create Tree" << endl;
            cout << "2. Display Tree" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    create();  
                    break;
                case 2:
                    if (root == NULL) {
                        cout << "Tree is not created yet!" << endl;
                    } else {
                        display(root);  
                    }
                    break;
                case 3:
                    cout << "Exiting the program." << endl;
                    return;  
                default:
                    cout << "Invalid choice, please try again." << endl;
            }
        }
    }
};

int main() {
    Tree bookTree;

    
    bookTree.menu();

    return 0;
}

