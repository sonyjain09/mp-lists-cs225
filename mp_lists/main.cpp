#include "List.h"

int main() {
    std::cout<<"Testing reverse"<<std::endl;
    List<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);
    list.insertBack(4);
    list.insertBack(5);
    list.insertBack(6);
    list.insertBack(7);
    std::cout<<"Before"<<std::endl;
    list.print();
    std::cout<<"\n"<<std::endl;
    std::cout<<"After"<<std::endl;
    list.reverse();
    list.print();
    std::cout<<"\n"<<std::endl;
    std::cout<<"Testing reverseNTH"<<std::endl;
    std::cout<<"nothing leftover"<<std::endl;
    List<int> list2;
    list2.insertBack(1);
    list2.insertBack(2);
    list2.insertBack(3);
    list2.insertBack(4);
    list2.insertBack(5);
    list2.insertBack(6);
    list2.insertBack(7);
    list2.insertBack(8);
    list2.insertBack(9);
    std::cout<<"Before"<<std::endl;
    list2.print();
    std::cout<<"\n"<<std::endl;
    std::cout<<"After"<<std::endl;
    list2.reverseNth(3);
    list2.print();
    std::cout<<"\n"<<std::endl;
    List<int> list3;
    std::cout<<"n greater than length"<<std::endl;
    list3.insertBack(1);
    list3.insertBack(2);
    list3.insertBack(3);
    list3.insertBack(4);
    list3.insertBack(5);
    list3.insertBack(6);
    list3.insertBack(7);
    std::cout<<"Before"<<std::endl;
    list3.print();
    std::cout<<"\n"<<std::endl;
    std::cout<<"After"<<std::endl;
    list3.reverseNth(14);
    list3.print();
    std::cout<<"\n"<<std::endl;
    List<int> list4;
    std::cout<<"part left over"<<std::endl;
    list4.insertBack(1);
    list4.insertBack(2);
    list4.insertBack(3);
    list4.insertBack(4);
    list4.insertBack(5);
    list4.insertBack(6);
    list4.insertBack(7);
    std::cout<<"Before"<<std::endl;
    list4.print();
    std::cout<<"\n"<<std::endl;
    std::cout<<"After"<<std::endl;
    list4.reverseNth(4);
    list4.print();
    std::cout<<"\n"<<std::endl;
    std::cout<<"Testing sort"<<std::endl;
    List<int> list5;
    list5.insertBack(1);
    list5.insertBack(2);
    list5.insertBack(4);
    list5.insertBack(3);
    list5.insertBack(7);
    list5.insertBack(6);
    list5.insertBack(8);
    std::cout<<"Before"<<std::endl;
    list5.print();
    std::cout<<"\n"<<std::endl;
    std::cout<<"After"<<std::endl;
    list5.sort();
    list5.print();
    // std::cout<<"Testing mergesort"<<std::endl;
    // List<int> list6;
    // list6.insertBack(5);
    // list6.insertBack(7);
    // list6.insertBack(8);
    // list6.insertBack(4);
    // list6.insertBack(5);
    // list6.insertBack(3);
    // list6.insertBack(7);
    // std::cout<<"Before"<<std::endl;
    // list6.print();
    // std::cout<<"\n"<<std::endl;
    // std::cout<<"After"<<std::endl;
    // list6.mergesort(list3);
    // list6.print();
}
