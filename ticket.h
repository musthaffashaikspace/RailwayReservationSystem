#include<bits/stdc++.h>
class Ticket
{
    private:
        int ticket_id;
        int nopeople;
        std::vector<int>seat_no;
        std::string seat_class;
        std::vector<std::string>people;
        int trainno;
    public:
        Ticket* left;
        Ticket * right;
        Ticket(int id,std::vector<int>v,std::string cl,std::vector<std::string>p,int trno,int np):ticket_id(id),
        seat_no(v),seat_class(cl),people(p),trainno(trno),nopeople(np){left=nullptr;right=nullptr;}
        int getticketid(void){return ticket_id;}
        std::vector<int>getseatnos(void){return seat_no;};
        std::string getclass(void){return seat_class;}
        std::vector<std::string>getnames(void){return people;}
        int getnum(void){return nopeople;}
        int gettrainnum(void){return trainno;}
};