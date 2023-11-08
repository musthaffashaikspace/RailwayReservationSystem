#include<iostream>
#include "ticket.h"
class User
{
    private:
        std::string username;
        std::string password;
        int numtickets;
        std::vector<int>ticketsbooked;
    public:
        User * left;
        User * right;
        User (std::string uname,std::string pass,int num,std::vector<int>v)
        {
            username=uname;
            password=pass;
            numtickets=num;
            ticketsbooked=v;
        }
        User(std::string s,std::string p){username=s;password=p,numtickets=0;left=nullptr;right=nullptr;}
        std::string getusername(void){return username;}
        std::string getpassword(void){return password;}
        void setticket(int tic)
        {
            ticketsbooked.push_back(tic);
            numtickets=ticketsbooked.size();
        }
        std::vector<int>getticketsbooked(void){return ticketsbooked;}
        int getnumtickets(void){return numtickets;}
};