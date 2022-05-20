/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
    head_ = NULL;
    tail_ = NULL;
    length_ = 0;
}

template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  return List<T>::ListIterator(head_);
}

template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  return List<T>::ListIterator(NULL);
}

template <typename T>
void List<T>::_destroy() {
  if(head_ != NULL){
    ListNode* curr = head_;
    while(curr != NULL){
      ListNode* iter = curr->next;
      delete curr;
      curr = iter;
    }
  }
  head_ = NULL;
  tail_ = NULL;
}

template <typename T>
void List<T>::insertFront(T const & ndata) {
  ListNode * newNode = new ListNode(ndata);
  if(length_ == 0){
    head_ = newNode;
    tail_ = newNode;
  }
  else{
    newNode -> next = head_;
    head_ -> prev = newNode;
    head_ = newNode;
  }
  length_ ++;
}

template <typename T>
void List<T>::insertBack(const T & ndata) {
  ListNode * newNode = new ListNode(ndata);
  if(length_ == 0){
    head_ = newNode;
    tail_ = newNode;
  }
  else{
    tail_ -> next = newNode;
    newNode -> prev = tail_;
    tail_ = newNode;
  }
  length_ ++;
}

template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  //edge cases (return start in all of these cases)
  //check if splitPoint is 0
  if(splitPoint == 0) return start;
  //check if start is NULL
  if(start == NULL) return NULL;
  //check if splitPoint is greater than length
  if(splitPoint >= length_) return NULL;
  //actual function
  //make a temp node pointer equal to start
  ListNode* temp = start;
  //loop till splitPoint keep setting temp equal to next. by end should get to node we want to disconnect at
  for(int i = 0; i < splitPoint; i++){
    //if temp is null return null (meaning the splitpoint is past the end of the list)
    if(temp == NULL) return NULL;
    //increment temp
    temp = temp->next;
  }
  //disconnect lists. get rid of all connection between both nodes
  if(temp != NULL) tail_ = temp->prev;
  if(tail_ != NULL) tail_->next = NULL;
  temp->prev = NULL;
  //return starting node for disconnected list
  return temp;
}

template <typename T>
void List<T>::tripleRotate() {
  //divide the length of the list by 3 to figure out how many groups are going to be rotated
  int groups = length_/3;
  //length mod 3 equals 0 set a boolean variable whole to true
  bool whole = false;
  if(length_ % 3 == 0) whole = true;
  //set new temp node to head
  ListNode* temp = head_;
  //loop from 0 to number of groups 
  for(int i = 0; i < groups; i++){
    ListNode* curr1 = temp;
    ListNode* curr2 = temp->next;
    ListNode* curr3 = temp->next->next;
    ListNode* after3 = curr3->next;
    ListNode* before1 = curr1->prev;
    //curr1 stuff
    curr1->prev = curr3;
    curr3->next = curr1;
    curr1->next = after3;
    if(after3 != NULL) after3->prev = curr1;
    //curr2 stuff
    curr2->prev = before1;
    if(before1 != NULL) before1->next = curr2;
    //check if i is 0. if it is make curr2 head
    if(i == 0) head_ = curr2;
    //check if whole is true and i = group - 1. if it is make curr1 tail
    if(whole == true and i == groups-1) tail_ = curr1;
    //set temp to node after curr1
    temp = curr1->next;
  }
}

template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  //edge cases
  //check if startpoint and endpoint are valid
  if(startPoint == NULL or endPoint == NULL) return;
  //check if startpoint and endpoint are the same
  if(startPoint == endPoint) return;
  //make copy nodes of startpoints prev and endpoints next (they will change but need to be saved)
  ListNode* startPointPrev = startPoint->prev;
  ListNode* endPointNext = endPoint->next;
  //set an iter node to startpoint
  ListNode* iter = startPoint;
  //loop till endpoint
  while(iter != endPoint){
    //set a temp variable to the iters next
    ListNode* temp = iter->next;
    //switch iter next and iter prev
    iter->next = iter->prev;
    iter->prev = temp;
    //make iter = temp
    iter = temp;
  }
  //change stuff for endpoint bc was not changed in loop
  endPoint->next = endPoint->prev;
  endPoint->prev = startPointPrev;
  //set startpoints next to endpoints next
  startPoint->next = endPointNext;
  //switch the prev and next of the nodes next to startpoint and endpoint if they're valid
  if(startPointPrev != NULL) startPointPrev->next = endPoint;
  if(endPointNext != NULL) endPointNext->prev = startPoint;
  //switch startpoint and endpoint with a temp variable
  ListNode* temp = startPoint;
  startPoint = endPoint;
  endPoint = temp;
  //switch head and tail if needed
  if(startPointPrev == NULL) head_ = startPoint;
  if(endPointNext == NULL) tail_ = endPoint;
}

template <typename T>
void List<T>::reverseNth(int n) {
  //divide the length of the list by n to figure out how many groups are going to be reversed
  int groups = length_/n;
  bool whole = false;
  //length mod n equals 0 set a boolean variable whole to true (tells us if there is no part left over)
  if(length_%n == 0) whole=true;
  //start at head
  ListNode* iter = head_;
  //loop to number of groups
  for(int i = 0; i < groups; i++){
    ListNode* startPoint = iter;
    //loop n-1 times to get to endpoint
    ListNode* temp = iter;
    for(int j = 0; j < n-1; j++) temp = temp->next;
    ListNode* endPoint = temp;
    //put startpoint and endpoint in
    reverse(startPoint, endPoint);
    //change iter to one after next group
    iter = endPoint->next;
  }
  //reverse left over
  if(whole != true) reverse(iter, tail_);
}

template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  //edge cases
  //if they are the same
  if(first == second) return first;
  //if either is null
  if(first == NULL) return second;
  if(second == NULL) return first;
  //first and second will be iter variables for their respective lists 
  //set output node to what will be new list head. see which list has a smaller head
  //increment first or second based on which ones head is used
  ListNode* out;
  if(first->data < second->data){
    out = first;
    first=first->next;
  }
  else{
    out = second;
    second=second->next;
  }
  //set an iter node to out
  ListNode* iter = out;
  //loop till the end of one list
  while(first != NULL and second != NULL){
    //set iters next to second or first depending on which one is smaller
    //set that ones prev to iter
    //increment whicher one was used
    if(first->data < second->data){
      iter->next = first;
      first->prev = iter;
      first = first->next;
    }
    else{
      iter->next = second;
      second->prev = iter;
      second = second->next;
    }
    //increment iter
    iter=iter->next;
  }
  //if we reached the end of one list and not the other set iters next to the list that we did not reach end of
  //set that lists prev to iter
  if(first != NULL){
    iter->next = first;
    first->prev = iter;
  }
  else if (second != NULL){
    iter->next = second;
    second->prev = iter;
  }
  //return out node made at beginning
  return out;
}


template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  //base case
  if (chainLength == 1) return start;
  //split into problem of half size
  int half = chainLength/2;
  //make a new list with second half of list using split
  ListNode* secondHalf = split(start, half);
  //mergesort first half of list and second half of list
  ListNode* p1 = mergesort(start, half);
  ListNode* p2 = mergesort(secondHalf, chainLength-half);
  //return the merge of two parts 
  return merge(p1,p2);
}
