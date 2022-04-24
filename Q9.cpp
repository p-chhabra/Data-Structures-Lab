#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;
    public:
    PriorityQueue(){
        
    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()) return 0;
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);
        int cI = pq.size() - 1;

        while(cI > 0){
            int pI = (cI - 1)/2;
            if(pq[cI] > pq[pI]){
                swap(pq[cI], pq[pI]);
                cI = pI;
            }else{
                break;
            }
        }
    }

    int removeMax(){
        if(isEmpty()){
            return 0;
        }
        swap(pq[0], pq[pq.size() - 1]);
        int ans = pq[pq.size() - 1];
        pq.pop_back();

        int pI = 0;
        while(1){
            int lcI = 2*pI + 1;
            int rcI = 2*pI + 2;
            int maxIndex = pI;

            if(lcI < pq.size() && pq[lcI] > pq[maxIndex]){
                maxIndex = lcI;
            }
            if(rcI < pq.size() && pq[rcI] > pq[maxIndex]){
                maxIndex = rcI;
            }
            if(maxIndex == pI){
                break;
            }
            swap(pq[pI], pq[maxIndex]);
            pI = maxIndex;

        } 
        return ans;
    }
};

int main()
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(45);
    p.insert(58);
    p.insert(25);
    p.insert(65);
    p.insert(21);
    cout<<p.getSize()<<endl;
    cout<<p.removeMax()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMax()<<" ";
    }
}