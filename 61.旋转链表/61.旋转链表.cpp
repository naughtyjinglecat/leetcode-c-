#include <iostream>
#include <cstring>
#include <vector>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode *p = head, *front = head, *rear = head;
        while(p != NULL){
            p = p->next;
            length++;
        }
        if(length == 0){
            return head;
        }
        k = k % length;
        for(int i = 0; i < k; i++){
            rear = rear->next;
        }
        while(rear->next != NULL){
            rear = rear->next;
            front = front->next;
        }
        rear->next = head;
        head = front->next;
        front->next = NULL;
        return head;
    }
};