`greedy`
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, n=0;
        map<char, int> m;
        while (j<s.length()) {
            char c = s[j];
            if (m.count(c)) {
                while (m[c]>0) {
                    m[s[i++]] -= 1;
                }
            }
            m[c] = 1;
            n = max(n, j-i+1);
            j++;
        }
        return n;
    }
};
```

https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1356443198/

```c++
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
class Solution {
public:
    bool probeNextSequeue(ListNode* head, int k) {
        int cnt = 0;
        while (cnt < k && head!=nullptr) {
            cnt += 1;
            head = head->next;
        }
        return cnt>=k;
    }

    pair<ListNode*, ListNode*> reverseSequeue(ListNode* head, int k) {
        ListNode *s=nullptr, *e=head, *nxt=nullptr;

        for(;k>0;k--){
            nxt = head->next;
            head->next = s;
            s = head;
            head=nxt;
        }
        e->next = nxt;
        return make_pair(s, e);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode H(0, head);
        ListNode* last = &H;

        while (probeNextSequeue(head, k)) {
            pair<ListNode*, ListNode*> p = reverseSequeue(head, k);
            last->next = p.first;
            last = p.second;
            head = p.second->next;
        }
        return H.next;
    }
};
```