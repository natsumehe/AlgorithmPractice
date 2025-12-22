#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// 单链表节点定义
template <typename T = int>
class SingleListNode{
public:
    struct ListNode {
        T val;
        ListNode* next;
        ListNode(T x) : val(x), next(nullptr) {}
    };

    // 将列表转换为单链表（静态方便从外部直接调用）
    static ListNode* vectorToListNode(const std::vector<T>& vec) {
        ListNode* dum = new ListNode(T());
        ListNode* cur = dum;
        for (const T& val : vec) {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        ListNode* head = dum->next;
        delete dum;
        return head;
    }

    // 释放分配给链表的内存空间（静态）
    static void freeMemoryLinkedList(ListNode* head) {
        while (head) {
            ListNode* nxt = head->next;
            delete head;
            head = nxt;
        }
    }
};

// 创建双链表--双虚拟节点-头尾节点
template <typename T>
class DoubleListNode {
    struct ListNode
    {
        T val;
        ListNode* next;
        ListNode* prev;
        ListNode(T x) : val(x), next(nullptr), prev(nullptr) {}
    };
    
    // 虚拟头节点和尾节点
    ListNode* head;
    ListNode* tail;
    size_t size;

    //初始化节点
public:
    DoubleListNode() {
        head = new ListNode(T());
        tail = new ListNode(T());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // 析构函数释放节点
    ~DoubleListNode() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // 增
    // 在链表头添加
    void addHead(T val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        size++; 
    }
    // 在链表尾添加
    void addTail(T val) {
        ListNode* newNode = new ListNode(val);
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
        size++;
    }

    //链表中间
    void addIndex(size_t index, T val) {
        if (index > size or index < 0) {
            throw out_of_range("Index out of range");
        }
        else if(index == size) {
            addTail(val);
        }
        else {
            ListNode* newNode = new ListNode(val);
            ListNode* current = head;
            for(size_t i{}; i < index; ++i) {
                current = current->next;
            }

        }
        
    }
};
