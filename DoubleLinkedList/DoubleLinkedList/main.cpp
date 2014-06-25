//
//  main.cpp
//  DoubleLinkedList
//
//  Created by garam on 2014. 6. 23..
//  Copyright (c) 2014년 garam. All rights reserved.
//

#include <iostream>
using namespace std;
//노드 링크드 리스트에 노드가 되는 곳
template <class T>
class Node{
private:
    //Node가 가지고 있는 데이터
    T data;
    //이전을 가르키는 노드를 가르키는 포인터
    Node<T> * prevNode;
    //다음을 가르키는 노드를 가르키는 포인터
    Node<T> * nextNode;
public:
    //데이터가 들어오지 않았을 때는 '0'?
    Node<T>(){data=0;};
    //데이터가 들어왔을 경우
    Node<T>(T input){data=input;};
    
    //getter
    T getData(){return data;};
    Node<T> * getPrevNode(){return prevNode;};
    Node<T> * getNextNode(){return nextNode;};
    
    //setter
    void setData(T _data){ data= _data;};
    void setNextNode(Node<T> * node){nextNode = node;};
    void setPrevNode(Node<T> * node){prevNode = node;};
};

//더블 링크드 리스트
template <class T>
class DoubleLinkedList{
private:
    Node<T> *head;// 가장 앞에 있는 Node, data값은 비어있음
    Node<T> *rear; // 가장 뒤어있는 Node, data값은 비어있음
public:
    DoubleLinkedList<T>(){
        head = new Node<T>();
        rear = new Node<T>();
        //초기화시 헤더는 리어를,리어는 해더를 가르켜야함.
        head->setNextNode(rear);
        rear->setPrevNode(head);
    }
    
    /*메모리 해제 해줘야하는것 아닌가?*/
//    ~DoubleLinkedList(){
//        delete head;
//        delete rear;
//    }
    
    /*비어있음을 확인*/
    bool isEmpty(){
        //해더는 리어를, 리어는 헤더를 가르키면 더블 링크드 리스트는 비어있는것.
        return head->getNextNode()==rear&&rear->getPrevNode()==head;
    }
    /*노드 찾기*/
    Node<T> *searchNode(T); //Find Target Node
    /*노드 넣기*/
    void insertNode(Node<T> *);//포인터 값을 넘기
    /*노드 지우기*/
    Node<T> *deleteNode(T);
};

template<typename T>
/*인자로 넘어온 객체가 있는지 확지 확인하고 있다면 관련 Node를 리턴해줌
 만약에 없다면 NULL리턴*/
Node<T> *DoubleLinkedList<T>::searchNode(T input){
    //해더의 오른쪽 왼쪼 모두  null일 경우 아무것도 없는 것
    if(isEmpty()){
        cout<<"Double Linked List is Empty"<<endl;
        return NULL;
    }
    else{
        //임시 포인터를 만들고 거기에 해더를 넣는다.
        Node<T> * cusorNode = head;
        while (cusorNode->getNextNode()!=rear) {
            cusorNode = cusorNode->getNextNode();
            if (cusorNode->getData()  == input) {
                return cusorNode;
            }
        }
        }
    return NULL;
};

template<typename T>
/*링크드 리스트를 마지막에 넣을 것임*/
void DoubleLinkedList<T>::insertNode(Node<T> *in){ //Insert on Tail Node.
    Node<T> * tmpNode;
    //rear의 앞에있는 놈을 tmpNode에 저장시킴
    tmpNode =  rear->getPrevNode();
    //tmpNode의 nextNode 포인터로 in(Node)를 가르킴
    tmpNode->setNextNode(in);
    //rear를 prevNode 포인터로 in(Node)를 가르킴
    rear->setPrevNode(in);
    in->setPrevNode(tmpNode);
    in->setNextNode(rear);
};

template<typename T>
Node<T> *DoubleLinkedList<T>::deleteNode(T inputData){
};

int main(int argc, const char * argv[])
{

    // insert code here...
    DoubleLinkedList<int> *ddl = new DoubleLinkedList<int>();
    Node<int> * node1 = new Node<int>(1);
    Node<int> * node2 = new Node<int>(2) ;
    Node<int> * node3= new Node<int>(3);
    
    ddl->insertNode(node1);
    ddl->insertNode(node2);
    ddl->insertNode(node3);
    
    Node<int> * searched1 = ddl->searchNode(1);
    Node<int> * searched2 = ddl->searchNode(2);
    Node<int> * searched3 = ddl->searchNode(3);
    cout<<searched1->getData() << endl;
    cout<<searched2->getData() << endl;
    cout<<searched3->getData() << endl;
    ddl->~DoubleLinkedList();

    delete node1;
    delete node2;
    delete node3;
    delete ddl;
    
    return 0;
}

