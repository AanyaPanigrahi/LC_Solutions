class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair <double,pair<int,int>>> pq;
        int num=classes.size();
        for(int i=0;i<num; i++){
            int x=classes[i][0];
            int y=classes[i][1];
            double more=(double)(x+1)/(y+1) -(double)x/y;
            pq.push({more,{x,y}});
        }   
        while (extraStudents-- ){
            auto itemcnt=pq.top();
            pq.pop();
            
            int pass= itemcnt.second.first;
            int total=itemcnt.second.second;
            
            pass++; total++;
            
            double summ=(double)(pass+1)/(total+1)-(double)pass/total;
            pq.push({summ,{pass,total}});
            
        }
        double averg= 0;
        while(!pq.empty()){ auto itemcnt = pq.top();
            pq.pop();
            int pass = itemcnt.second.first;
            int total = itemcnt.second.second;
            averg+=(double)pass/(double(total));
        }
        return averg/num;
    }
};