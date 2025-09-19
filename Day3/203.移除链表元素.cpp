class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //删除头节点
        while(head!=NULL&&head->val==val){//注意这里不是if
            ListNode* tmp = head;
            head = head ->next;
            delete tmp;
        }

        //删除非头节点
        ListNode* cur = head;
        while(cur!=NULL && cur->next!=NULL){
            if(cur->next->val==val){
                ListNode* tmp=cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};

class Solution{
public:
    ListNode* removeElements(ListNode* head,int val){
        ListNode* dummyHead = new ListNode(0);//设置一个虚拟头结点
        dummyHead->next = head;//将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;//注意这个地方dummyHead的val事实在head的前面。
        while(cur->next!=NULL){
            if(cur->next->val==val){
                ListNode* tmp = cur->next;
                cur->next=cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
