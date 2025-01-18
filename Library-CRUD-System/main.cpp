#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node{
    string titleBook;
    string writer;
    string publisher;
    string year;
    Node* next;
};

void addNode(Node* &head,string &titleBook,string &writer,string &publisher,string &year){
    Node* newNode = new Node();
    newNode->titleBook = titleBook;
    newNode->year = year;
    newNode->writer = writer;
    newNode->publisher = publisher;
    if(head == NULL){
        head = newNode;
    }else{
        Node* cur = head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

void updateNode(Node* &head,string &titleBook){
    int choose;
    cout<<"What you want to change:"<<endl;
    cout<<"1. Title\n";
    cout<<"2. Writer\n";
    cout<<"3. Publisher\n";
    cout<<"4. Year\n";
    cout<<"choose (1-4): ";cin>>choose;
    Node* cur = head;
    while(cur != NULL){
        if(cur->titleBook == titleBook){
            if(choose == 1){
                string newTitle;
                cin.ignore();
                cout<<"New title: ";getline(cin,newTitle);
                cur->titleBook = newTitle;
            }else if(choose == 2){
                string newWriter;
                cin.ignore();
                cout<<"New writer: ";getline(cin,newWriter);
                cur->writer = newWriter;
            }else if(choose == 3){
                string newPublisher;
                cin.ignore();
                cout<<"New publisher: ";getline(cin,newPublisher);
                cur->publisher = newPublisher;
            }else if(choose == 4){
                string newYear;
                cout<<"New year: ";cin>>newYear;
                cur->year = newYear;
            }
            break;
        }else{
            cur = cur->next;
        }
    }
}

void removeNode(Node* &head,string &titleBook){
    Node* cur = head;
    Node* del = head;
    Node* before = head;
    int count = 1;
    int countNode = 1;
    while(cur != NULL){
        if(cur->titleBook == titleBook){
            break;
        }else{
            cur = cur->next;
            countNode++;
        }
    }
    cur = head;
    while(count <= countNode){
        if(count == countNode){
            del = cur;
        }else if(count <= countNode-1){
            before = cur;
        }
        cur = cur->next;
        count++;
    }
    before->next = cur;
    if(del == head){
        head = NULL;
    }
    delete del;
}
void printNode(Node* &head){
    Node* cur = head;
    cout<<"==========================================================="<<endl;
    cout<<"|      Title     |     Writer     |   Publisher  |  Year  |"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    while(cur != NULL){
        cout<<left<<"|"<<setw(16)<<cur->titleBook<<'|'<<setw(16)<<cur->writer<<'|'<<setw(14)<<cur->publisher<<'|'<<setw(2)<<" "<<cur->year<<"  "<<'|'<<endl;
        cur = cur->next;
    }
    cout<<"==========================================================="<<endl;
}

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void menu(){
    cout<<"======================"<<endl;
    cout<<"     CRUD LIBRARY\n";
    cout<<"======================"<<endl;
    cout<<"1. Add Book\n";
    cout<<"2. Show Book\n";
    cout<<"3. Update Book\n";
    cout<<"4. Delete Book\n";
    cout<<"5. Exit\n";
    cout<<"======================"<<endl;
    cout<<"choose (1-5): ";
}
int main(){
    Node* head = NULL;
    int choose;
    string title;
    string writer;
    string publisher;
    string year;
    do{
        clearScreen();
        menu();
        cin>>choose;
        enum{CREATE = 1,READ,UPDATE,DELETE,EXIT};
        switch(choose){
            case CREATE:
                clearScreen();
                cout<<"===================="<<endl;
                cout<<"      ADD BOOK\n";
                cout<<"===================="<<endl;
                cin.ignore();
                cout<<"Title    : ";getline(cin,title);
                cout<<"Writer   : ";getline(cin,writer);
                cout<<"Publisher: ";getline(cin,publisher);
                cout<<"Year     : ";cin>>year;
                addNode(head,title,writer,publisher,year);
                break;
            case READ:
                if(head == NULL){
                    clearScreen();
                    cout<<"Linked List is Empty"<<endl;
                    system("pause");
                }else{
                    clearScreen();
                    printNode(head);
                    system("pause");
                }
                break;
            case UPDATE:
                if(head == NULL){
                    clearScreen();
                    cout<<"Linked List is Empty"<<endl;
                    system("pause");
                }else{
                    clearScreen();
                    cout<<"================="<<endl;
                    cout<<"   UPDATE BOOK\n";
                    cout<<"================="<<endl;
                    printNode(head);
                    cin.ignore();
                    cout<<"Book name => ";getline(cin,title);
                    updateNode(head,title);
                    system("pause");
                }
                break;
            case DELETE:
                if(head == NULL){
                    cout<<"Linked list is empty"<<endl;
                    system("pause");
                }else{
                    clearScreen();
                    cout<<"================="<<endl;
                    cout<<"   DELETE BOOK\n";
                    cout<<"================="<<endl;
                    printNode(head);
                    cout<<"Input Title Book to delete: ";getline(cin,title);
                    removeNode(head,title);
                }
                break;
            case EXIT:
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid Input"<<endl;
                break;
        }
    }while(choose != 5);
    return 0;
}