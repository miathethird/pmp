#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>

class node
{
    public:
    node* next;
    int val = 0;
    int count = 0;
    node(): next(nullptr){}
    node(int _val, int _count) : val(_val), count(_count){}
};

std::vector<int> solve(std::string s, std::vector<int> startIdx, std::vector<int> endIdx)
{
    std::vector<int> res;

    int curr_count = 0;
    bool startPipeFound = false;

    node* head = nullptr;
    node* og_head = nullptr;

    for (int i =0; i<s.length(); i++)
    {
        if(s[i] == '|' && !startPipeFound)
        {
            startPipeFound = true;
            curr_count = 0;

            if(!head)
            {
                head = new node();
                
                head->next = nullptr;
                head->val = i;
                head->count = 0;
                og_head = head;
            }
        }
        else if (startPipeFound && s[i]=='|')
        {
            head->next = new node(i, curr_count);
            head=head->next;
            curr_count=0;
        }
        else
        {
            curr_count++;
        }
    }
    
    for(int i = 0; i< startIdx.size(); i++)
    {
        int counter = 0;
        node* curr = og_head;
        bool skip_first_node = false;
        while(curr && curr->val <=endIdx[i]-1)
        {
            if(s[startIdx[i]-1] == '|')
            {
                if(curr->val >= startIdx[i]-1 && curr->val <=endIdx[i]-1) counter+= curr->count;
            }
            else
            {
                if(curr->val >= startIdx[i]-1 && skip_first_node)
                {
                    counter+= curr->count;
                }
                else if (curr->val >= startIdx[i]-1 && !skip_first_node)
                {
                    skip_first_node = true;
                }
            }
            curr = curr->next;
        }

        res.push_back(counter);
    }

    return res;
}

int main()
{
    std::string s = "*|***|*|**********|"; //"|**|***|**";
    std::vector<int> startIdx = {1,1,1};
    std::vector<int> endIdx  = {5,6,9};
    std::vector<int> result = solve(s, startIdx, endIdx);
    for(auto i : result) std::cout << i << " " ;
    return 0;
}