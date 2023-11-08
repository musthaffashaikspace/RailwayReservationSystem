#include<bits/stdc++.h>
class Train
{
    private:
        int trainno;
        std::map<int,std::vector<int>>coaches;
        float costfactor;
        std::vector<int>&getcoach(int i){return coaches[i];}
    public:
        Train(int t,std::map<int,std::vector<int>>c,float cf)
        {
            trainno=t;
            coaches=c;
            costfactor=cf;
        }
        int gettrainno(void){return trainno;}
        int getcostfactor(void){return costfactor;}
        std::vector<int>ticketbooker(int cl,int no);
};
int findleft(std::vector<int>&coach,int c)
{
    if(c<0)
        return 0;
    if(coach[c]==0)
        return 0;
    else return 1+findleft(coach,c-1);
}
int findright(std::vector<int>&coach,int c)
{
    if(c>=80)
        return 0;
    if(coach[c]==0)
        return 0;
    else return 1+findright(coach,c+1);
}
int giveseat(std::vector<int>&coach,int c)
{
    int left=findleft(coach ,c);
    int right=findright(coach ,c);
    if(left>=40)
    {
        if(right>=40)
            return -1;
    }
    if(right>=40)
    {
        if(left>=40)
            return -1;
    }
    if(left<right)
    {
        return c-left;
    }
    else return c+right;
}
std::vector<int>Train::ticketbooker(int cl,int no)
{
    std::vector<int>&coach=getcoach(cl);
    std::vector<int>ans;
    for(int i=0;i<no;i++)
    {
        int t=giveseat(coach,39);
        if(t<0||t>=80)
        {
            std::vector<int>temp;
            return temp;
        }
        coach[t]=1;
        ans.push_back(t+1);
    }
    return ans;
}
