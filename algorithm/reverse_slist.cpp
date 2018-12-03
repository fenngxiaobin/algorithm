#include <iostream>
#include <stack>
#include <exception>
using std::clog;
using std::endl;
struct ListNode{
    int n_value;
    ListNode* p_next;
};

/**
 * reverse output the elements of the slist
 * method: stack
 * @param head
 */
void reverse_slist(ListNode* head){
    std::stack<int> st;
    if(head== nullptr||head->p_next== nullptr){
        return;
    }
    ListNode *ptr=head;
    while(ptr!= nullptr){
        st.push(ptr->n_value);
        ptr=ptr->p_next;
    }
    while(!st.empty()){
        clog<<st.top()<<endl;
        st.pop();
    }
}

/**
 * reverse output the elements of the slist
 * method: recurse
 * @param head
 */
void reverse_slist_recurse(ListNode* head){
    if(head!= nullptr) {
        if (head->p_next != nullptr) {
            reverse_slist_recurse(head->p_next);
        }
        clog << head->n_value << endl;
    }
}

int main() {
    ListNode *head= nullptr;
    ListNode *l1=new ListNode();
    l1->n_value = 1;
    ListNode *l2=new ListNode();
    l2->n_value = 2;
    ListNode *l3=new ListNode();
    l3->n_value = 3;
    l1->p_next=l2;
    l2->p_next=l3;
    l3->p_next= nullptr;
    head=l1;
    reverse_slist(head);
    reverse_slist_recurse(head);
    delete l1;
    delete l2;
    delete l3;
    return 0;
}