#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data)
{
// create a new node that is to be added    
DoublyLinkedListNode *new_node = new DoublyLinkedListNode(data);
// create pointer for the current node for traversal
DoublyLinkedListNode *current_node = head;
DoublyLinkedListNode *prev_node = head;

// Condition when the list is empty
if (head==NULL)
{
    head = new_node;
    return head;
}

// if data is to be inserted before the current head
if (data < head->data)
{
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return head;
}

// Traverse the list to find the insertion position
/*
IMPORTANT NOTE:
When current_node is null, we cannot calculate current_node->data!!!
Thus, "current_node!=nullptr" check needs to come first.
Else, need to change program structure.
*/
while((current_node!=nullptr) && (current_node->data < data))
{
    prev_node = current_node;
    cout<<current_node->next;
    current_node = current_node->next;
}

// if last node, current node is null
if (current_node==NULL)
{
    prev_node->next = new_node;
    new_node->prev = prev_node;
    new_node->next=nullptr;
    cout<<"here";
    return head;
}

// Insert the new node here
new_node->next = current_node;
new_node->prev = prev_node;

current_node->prev = new_node;
prev_node->next = new_node;

return head;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
