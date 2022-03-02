
    #include <bits/stdc++.h>
    using namespace std;

    class Node
    {
    public:
        int data;
        Node *next; // declares p to have the type pointer to Node class

        Node(int value) : data(value), next(nullptr) {}
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    void display(Node *head)
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    int countnodes(Node *head)
    {
        Node *tmp = head;
        int count = 0;
        while (tmp != nullptr)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    void insertNode(int idx, int val)
    {
        if (idx > countnodes(head)-1)
            return;

        Node *newnode = new Node(val);
        if (idx == 0){
            newnode->next = head;
            head = newnode;
        }
        else if (idx == countnodes(head)){
            tail->next = newnode;
            tail = newnode;
        }
        else{
            Node *prevnode = head;
            for (int i = 0; i < idx - 1; i++)
            {
                prevnode = prevnode->next;
            }
            newnode->next = prevnode->next;
            prevnode->next = newnode;
        }
    }

    int deleteNode(int idx)
    {
        if (idx > countnodes(head)-1) return -1;
        if (idx == 0){
            Node *tmp = head;
            head = head->next;
            return tmp->data;
            delete tmp;
        }else if (idx == countnodes(head)-1){
            Node *p = head;
            Node *q = nullptr;
            for (int i = 0; i <= idx - 1; i++){
                q = p;
                p = p->next;
            }
            q->next = nullptr;
            tail = q;
            return p->data;
            delete p;
        }else{
            Node *p = head;
            Node *q = nullptr;
            for (int i = 0; i <= idx - 1; i++){
                q = p;
                p = p->next;
            }
            q->next = p->next;
            return p->data;
            delete p;
        }
    }

    int main()
    {

        //    Node* first = new Node(4);
        //    Node* second = new Node(8);
        //    Node* third = new Node(9);

        //    head = first;
        //    first->next = second;
        //    second->next = third;
        //    tail = third;

        int n;
        cin >> n;
        int value;
        while (n--)
        {
            cin >> value;
            Node *newnode = new Node(value);
            if (head == nullptr)
            {
                head = tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
        }

        display(head);
        cout << countnodes(head) << endl;
        insertNode(0, 55); //insertion at begining
        display(head);
        cout << countnodes(head) << endl;
        insertNode(countnodes(head), 77); //insertion at last pos
        display(head);
        cout << countnodes(head) << endl;
        insertNode(6, 44); //insertion at 6th pos
        display(head);
        cout << countnodes(head) << endl;

        display(head);
        cout << countnodes(head) << endl;
        cout<<"Node "<<deleteNode(0)<<" successfully deleted\n";
        display(head);
        cout << countnodes(head) << endl;
        cout<<"Node "<<deleteNode(countnodes(head)-1)<<" successfully deleted\n";
        display(head);
        cout << countnodes(head) << endl;
        cout<<"Node "<<deleteNode(10)<<" successfully deleted\n";
        display(head);
        cout << countnodes(head) << endl;
        cout<<"Node "<<deleteNode(3)<<" successfully deleted\n";
        display(head);
        cout << countnodes(head) << endl;

        return 0;
    }