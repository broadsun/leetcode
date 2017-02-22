/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //定制一个头，头只是一个标志，不存放东西
        ListNode* newHead = new ListNode(-1);  
        //定制一个尾巴，初始化时，尾巴就是头
        //尾巴用来移动
        ListNode* tail = newHead;  
        //进位初始化为0
        int carry = 0; 
        int val = 0;
        //遍历两个链表，直至全遍历完
        while(l1 != NULL || l2 != NULL)  
        {  
            //如果两个链表节点都有值
            if(l1 != NULL && l2 != NULL)  
            {  
                //相加求个位值和十位值
                int temp = l1->val + l2->val + carry;  
                //个位值
                val = temp%10;  
                //十位值，即进位
                carry = temp/10;  
            }
            //如果某一个链表短，已经遍历结束
            else  
            {  
                int temp = ( (l1 != NULL)?l1->val:l2->val ) + carry;  
                val = temp%10;  
                carry = temp/10;  
            } 
            //新建一个节点node，节点值是刚计算好的个位值
            ListNode* node = new ListNode(val);
            //尾巴的下一个节点指向node
            tail->next = node;
            //同时将node节点设置为尾巴
            tail = node;  
            //更新链表节点的指针，向后遍历
            l1 = (l1 != NULL)? l1->next:NULL;  
            l2 = (l2 != NULL)? l2->next:NULL;  
        }
        //如果遍历之后，还有一个进位，需要新建一个node
        if (carry)  
        {  
            ListNode* node = new ListNode(1);  
            tail->next = node;  
        }
        //返回头指向的节点，那里才是存着实际东西的地方 
        return newHead->next;  
    }
};