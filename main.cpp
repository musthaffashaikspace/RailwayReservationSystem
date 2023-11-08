#include<bits/stdc++.h>
#include "user.h"
#include "train.h"
using namespace std;
User * user=nullptr;
Train * train =nullptr;
Ticket* ticket=nullptr;
int numberofusers=0,numberoftickets=0;
User* signup(User *user,string u,bool & found)
{
    if(!user)
    {
        numberofusers++;
        cout<<"\nType Password\n";
        string pass;
        cin>>pass;
        user=new User(u,pass);
        return user;
    }
    if(u==user->getusername())
    {
        found=true;
        return nullptr;
    }
    else if(u>user->getusername())
    {
        user->right=signup(user->right,u,found);
        return user;
    }
    else{
        user->left=signup(user->left,u,found);
        return user;
    }
}
User* login(User *user,string username)
{
    if(!user)
    {
        return nullptr;
    }
    if(username==user->getusername())
    {
        string pass;
        cout<<"\nType Password\n";
        int i=0;
        while(cin>>pass)
        {
            if(user->getpassword()==pass)
            {
                return user;
            }
            else{
                if(i==4)
                    return nullptr;
                cout<<"\n!Wrong Password Try Again\a\n";
                cout<<"\nType Password\n";
                i++;
            }
        }
    }
    else if(username>user->getusername())
        return login(user->right,username);
    else
        return login(user->left,username);
}

map<int,vector<int>>make_train(void)
{
    map<int,vector<int>>ans;
    for(int i=1;i<4;i++)
    {
        vector<int>v(80,0);
        ans[i]=v;
    }
    return ans;
}
Ticket* addticket(int id,Ticket * currticket,Ticket * ticket)
{
    if(!ticket)
    {
        numberoftickets++;
        return currticket;
    }
    if(id>ticket->getticketid())
    {
        ticket->right= addticket(id,currticket,ticket->right);
        return ticket;
    }
    else 
    {
        ticket->left= addticket(id,currticket,ticket->left);
        return ticket;
    }
}
Ticket* book_ticket(User * user,Train * train)
{
    cout<<"\nWELCOME TO TICKET BOOKING\n";
    cout<<"Type the number of tickets you want to book:\t";
    int n;
    cin>>n;
    vector<string>names(n+1);
    cout<<"\nType names of passengers\n";
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<":\t";
        cin>>names[i];
        cout<<"\n";
    }
    cout<<"\nSelect the Class\n";
    cout<<"1.SL = "<<train->getcostfactor()*300<<"rs";
    cout<<"\n2.AC = "<<train->getcostfactor()*1000<<"rs";
    cout<<"\n3.GEN = "<<train->getcostfactor()*50<<"rs";
    int opt;
    cin>>opt;
    vector<string>seatclass={"SL","AC","GEN"};
    vector<int>seatnos=train->ticketbooker(opt,n);
    srand(time(0));
    if(seatnos.size()==0)
        return nullptr;
    int id=rand()%1000;
    Ticket * currticket=new Ticket(id,seatnos,seatclass[opt-1],names,train->gettrainno(),n);
    ticket=addticket(id,currticket,ticket);
    user->setticket(id);
    return currticket;
}
void print_ticket(Ticket * ct)
{
    if(!ct)
        return ;
    cout<<"\n-------------------------------------------------------------------------";
    cout<<"--------------------------------------\n";
    cout<<"Ticket ID:\t"<<ct->getticketid();
    cout<<"\nTrain NO:\t"<<ct->gettrainnum()<<endl;
    vector<string>names=ct->getnames();
    vector<int>seat=ct->getseatnos();
    string s=ct->getclass();
    for(int i=0;i<ct->getnum();i++)
    {
        cout<<names[i]<<"\t\t"<<seat[i]<<"\t"<<s<<endl;
    }
    cout<<"\n-------------------------------------------------------------------------";
    cout<<"--------------------------------------\n";
}
Ticket * findticket(Ticket * ticket,int id)
{
    if(!ticket)
        return nullptr;
    if(id==ticket->getticketid())
        return ticket;
    if(id>ticket->getticketid())
        return findticket(ticket->right,id);
    else  return findticket(ticket->left,id);
}
void traverseticket(Ticket * ticket,ofstream& ticketfile)
{
    if(ticket==nullptr)
        return ;
    
    ticketfile<<ticket->getticketid()<<" ";
    
    ticketfile<<ticket->getnum()<<" ";
    
    vector<int>temp=ticket->getseatnos();
    for(int i=0;i<ticket->getnum();i++)
    {
        ticketfile<<temp[i]<<" ";
        
    }
    ticketfile<<ticket->getclass()<<" ";
    
    vector<string>pe=ticket->getnames();
    for(int i=0;i<ticket->getnum();i++)
    {
        ticketfile<<pe[i]<<" ";
        
    }
    ticketfile<<ticket->gettrainnum()<<" ";
    
    traverseticket(ticket->left,ticketfile);
    traverseticket(ticket->right,ticketfile);
}
void traverseuser(User * user,ofstream& userfile)
{
    if(user==nullptr)
        return ;
    userfile<<user->getusername()<<" ";
    userfile<<user->getpassword()<<" ";
    userfile<<user->getnumtickets()<<" ";
    for(int i=0;i<user->getnumtickets();i++)
    {
        userfile<<user->getticketsbooked()[i]<<" ";
    }
    traverseuser(user->left,userfile);
    traverseuser(user->right,userfile);
}
void savetickets(void)
{
    ofstream ticketfile;
    
    ticketfile.open("ticket.txt");
    if(!ticketfile.is_open())
    {
        cout<<"error openeing the file\n";
        return ;
    }
    ticketfile<<numberofusers<<" ";
    traverseticket(ticket, ticketfile);
    
    ticketfile.close(); // Close the file stream
}

void saveusers(void)
{
    ofstream userfile;
    
    userfile.open("user.txt");
    if(!userfile.is_open())
    {
        cout<<"error openeing the file\n";
        return ;
    }
    userfile<<numberofusers<<" ";
    traverseuser(user, userfile);
    userfile.close(); // Close the file stream
}
User * adduserstart(User * user, User * curruser)
{
    if (!user)
        return curruser;

    if (curruser->getusername() == user->getusername())
    {
        cout << "Error: Found two users with the same username in the file." << endl;
        exit(0);
    }
    else if (curruser->getusername() < user->getusername())
    {
        user->left = adduserstart(user->left, curruser); 
    }
    else
    {
        user->right = adduserstart(user->right, curruser); 
    }
    return user;  // This line was missing in your original code.
}
void readuserstart(void)
{
    ifstream userfile;
    userfile.open("user.txt");

    if (!userfile.is_open())
    {
        cout << "Error opening the file" << endl;
        return;
    }

    int num;
    userfile >> num;
    numberofusers=num;
    for (int i = 0; i < num; i++)
    {
        string name;
        string password;
        int n;
        userfile >> name;
        userfile >> password;
        userfile >> n;
        vector<int> ticketsbooked(n);
        for (int j = 0; j < n; j++)
        {
            userfile >> ticketsbooked[j];
        }

        
        User *curruser = new User(name, password, n, ticketsbooked);
        
        user = adduserstart(user, curruser);
    }

    userfile.close();
}

void readticketstart(void)
{
    ifstream ticketfile;
    ticketfile.open("ticket.txt");
    if(!ticketfile.is_open())
    {
        cout<<"error openeing the file\n";
        return ;
    }
    int n;
    ticketfile>>n;
    numberoftickets=n;
    for(int i=0;i<n;i++)
    {
        int ticketno;
        int numpeople;
        string seatclass;
        int trainno;
        ticketfile>>ticketno;
        ticketfile>>numpeople;
        vector<int>seatnos(numpeople);
        vector<string>people(numpeople);
        for(int i=0;i<numpeople;i++)
        {
            ticketfile>>seatnos[i];
        }
        ticketfile>>seatclass;
        for(int i=0;i<numpeople;i++)
        {
            ticketfile>>people[i];
        }
        ticketfile>>trainno;
        Ticket* newticket=new Ticket(ticketno,seatnos,seatclass,people,numpeople,trainno);
        ticket=addticket(ticketno,newticket,ticket);
    }
    ticketfile.close();
}
int main(void)
{
    readuserstart();
    readticketstart();
    User * loginuser=nullptr;
    cout<<"1.Signup\t2.Login\t\t3.exit(q to exit)\n";
    Train *currtrain=new Train(1,make_train(),7);
    while(true)
    {
        int opt;
        while(cin>>opt)
        {
            if(opt==1)
            {
                string username;
                cout<<"\nType Username\n";
                cin>>username;
                bool found=false;
                User * newuser=signup(user,username,found);
                if(found)
                {
                    cout<<"\n\nUsername Already Taken\n\n";
                }
                else
                {
                    user=newuser;
                    cout<<"\nUser successfully Registered\n\n";
                }
            }
            else if (opt==2)
            {
                if(!user)
                {
                    cout<<"\n!No users present\n";
                    cout<<"1.Signup\t2.Login\t3.exit(q to exit)\n";
                    continue;
                }
                string username;
                cout<<"\nType Username\n";
                cin>>username;
                loginuser=login(user,username);
                if(!loginuser)
                {
                    cout<<"\n\nWrong Username or password\n\n";
                    cout<<"1.Signup\t2.Login\t3.exit(q to exit)\n";
                    continue;
                }
                cout<<"1.Continue Booking\t2.Print Tikcket\n";
                int optnew;
                cin>>optnew;
                if(optnew==1)  break;
                else
                {
                    vector<int>ticketids=loginuser->getticketsbooked();
                    for(int i=0;i<ticketids.size();i++)
                    {
                        cout<<"\n\n\n**********TICKET NO "<<i+1<<" *****************\n";
                        print_ticket(findticket(ticket,ticketids[i]));
                    }
                }
            }
            else 
            {
                break;
            }
            cout<<"1.Signup\t2.Login\t3.exit(q to exit)\n";
        }
        if(opt==3)
            break;
        cout<<"\n\n\nSource:\t\t\tDestination\t\tTrainNo\n";
        cout<<"\nBangalore\t\tHyderabad\t 1\n";
        if(!currtrain)
        {
            cout<<"Train was not made\n";
            return 0;
        }
        cout<<"Type the train numer to book\n";
        while(cin>>opt)
        {
            if(opt!=1)
                continue;
            else break;
        }
        Ticket *success=book_ticket(loginuser,currtrain);
        if(success)
        {
            print_ticket(success);
        }
        else{
            cout<<"\nError Booking the Ticket\n";
        }
        cout<<"1.Signup\t2.Login\t3.exit(q to exit)\n";
    }
    
    try
    {
        //saving the users
        saveusers();
        //saving the tickets
        savetickets();
    }
    catch(exception e)
    {
        cerr<<e.what()<<endl;;
    }
}