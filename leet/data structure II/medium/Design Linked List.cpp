class node{
    public:
     int val;
     node* next;
 };

class MyLinkedList {
public:
    node* head;
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        if(head==NULL)
            return -1;

        node* temp = head;

        for(int i=0; i<index; i++)
        {
            if(temp->next==NULL)
                return -1;
            
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        node* temp = new node();
        temp->val = val;
        temp->next = head;
        head = temp;
    }
    
    void addAtTail(int val) {
        if(head==NULL)
        {
            node* n = new node();
            n->val = val;
            head= n;
            return;
        }
        node* temp = head;
        node* n = new node();
        n->val = val;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    
    void addAtIndex(int index, int val) {
        node* temp = head;
        node* n = new node();
        n->val = val;

        if(index==0)
        {
            addAtHead(val);
            return;
        }
        
        for(int i=0; i<index-1; i++)
        {
            temp=temp->next;
            if(temp==NULL)
                return;
        }
        if(temp==NULL)
            return;
        n->next = temp->next;
        temp->next = n;
    }
    
    void deleteAtIndex(int index) {
        node* temp = head;
        if(head==NULL)
        {
            return;
        }
        if(index==0)
        {
            head = head->next;
            return;
        }
        for(int i=0; i<index-1; i++)
        {
            temp=temp->next;
            if(temp==NULL || temp->next==NULL)
                return;
        }
        if(temp==NULL || temp->next==NULL)
            return;
        temp->next=temp->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
