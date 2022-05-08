#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {

    ListNode<T> *addedNode = new ListNode(value);

    addedNode->next = head->next;
    head->next = addedNode;
    num_of_element++;

}

template<class T>
void LinkedList<T>::push_back(const T &value) {

    ListNode<T> *tracker = head;

    while(tracker->next != nullptr){
        tracker = tracker->next;
    }

    num_of_element++;
    tracker->next = new ListNode(value);


}

template<class T>
void LinkedList<T>::pop_back() {

    if(head->next != nullptr){
        ListNode<T> *tracker = head;

        while(tracker->next->next != nullptr){
            tracker = tracker->next;
        }

        delete tracker->next;
        tracker->next = nullptr;
        num_of_element--;
    }
}

template<class T>
void LinkedList<T>::pop_front() {

    if(head->next != nullptr){
        ListNode<T> *tracker = head->next;
        head->next = tracker->next;
        delete tracker;
        num_of_element--;
    }

}

template<class T>
void LinkedList<T>::remove(T &val) {

    if(head->next != nullptr){
        ListNode<T> *tracker1 = head->next;
        ListNode<T> *tracker2 = head;

        while(tracker1 != nullptr){
            if(tracker1->val == val){
                tracker2->next = tracker1->next;
                delete tracker1;
                tracker1 = tracker2->next;
                num_of_element--;

            }
            else {
                tracker2 = tracker2->next;
                tracker1 = tracker1->next;
            }
        }
    }

}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {

    //tracker node
    ListNode<T> *tracker = head;
    auto &other = (LinkedList<T> &) ot;

    //for loop with the size of the over list
    for(int i = 0; i < other.size(); i++){
        //get the value of index i of the other list
        // iterate through the tracker until the spot is found or until next is void
        while(tracker->next != nullptr && tracker->next->val < other[i]){
            tracker = tracker->next;
        }
        //create a new node and connect it using the tracker
        ListNode<T> *insert = new ListNode(other[i]);
        insert->next = tracker->next;
        tracker->next = insert;
        num_of_element++;
    }

}

template<class T>
void LinkedList<T>::reverse_iterative() {

    if(head->next != nullptr){

        ListNode<T> *tracker = head->next;

        int beginningSize = num_of_element;

        while (tracker->next != nullptr){
            tracker = tracker->next;
            push_front(tracker->val);
        }

        for(int i = 0; i < beginningSize - 1; i++){

            pop_back();
        }

    }





}