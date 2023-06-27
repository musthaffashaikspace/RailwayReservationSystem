#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<time.h>//header file used for clock function
#include<stdbool.h>//header file for all the boolean variables
#define MAX 80

struct details//this structure holds the details of the person travelling in the train
{
	char Name[MAX];
	char Gender[MAX];
	int Age;
	char Phone[MAX];
	struct details *link;
};
typedef struct details *NODE;//NODE declaration of the details structure

struct user//this is the structure declaration of the user using the reservation portal
{
	char name[MAX];
	char dob[10];
	char phno[10];
	char pass[MAX];
	struct user *link;
};
typedef struct user* USER_NODE;//NODE declaration of the user structure
 //MACRO declaration
#define MALLOC(p,s,t)\
	p=(t)malloc(s);\
	if(p==NULL)\
	{\
		printf("Insufficient Memory.\n");\
		exit;\
	}

char name[MAX];//variables used for the Readdata() function
char gen[MAX];
int age;
char ph[MAX];
int SL,Third,Second,First;
char source[MAX],dest[MAX],tname[MAX],tno[MAX],cla[MAX],dur[MAX],date[12];//To print the train details in the ticket
char berth[5];
int sno[MAX];
int amount,n;
float arr,depart;
char uname[MAX],dob[10],uph[10],upass[MAX],h;
//source functions 
void ban();
void hyd();
void mum();
void del();
void chen();
void kol();
//source destination functions
void ban_hyd(void);
void ban_mum(void);
void ban_del(void);
void ban_chen(void);
void ban_kol(void);
void hyd_ban(void);
void hyd_mum(void);
void hyd_del(void);
void hyd_chen(void);
void hyd_kol(void);
void mum_ban(void);
void mum_hyd(void);
void mum_del(void);
void mum_chen(void);
void mum_kol(void);
void del_ban(void);
void del_hyd(void);
void del_mum(void);
void del_chen(void);
void del_kol(void);
void chen_ban(void);
void chen_hyd(void);
void chen_mum(void);
void chen_del(void);
void chen_kol(void);
void kol_ban(void);
void kol_hyd(void);
void kol_mum(void);
void kol_del(void);
void kol_chen(void);
void ReadData();//Reads data into the structure
NODE InsFront(NODE,int);//appends the NODES by using the insert front method of linked list
void ticket(NODE,int);//Prints the tickets
NODE passdata(int,NODE);//Passes data to the function
int calc(int,int,int,int,int);//Calculates the amount of ticket
void seat(int);//allocates a person their seat by using the rand() function
void coach();//allocates the coach to the user by using the rand() function
void starting_display(void);//displays the initial display screen
void payment(void);//handles payment
USER_NODE user(USER_NODE);//starting function after entering the site
USER_NODE create(USER_NODE);//creates new user using the site or portal
bool login(USER_NODE);//logins the user as per the usn and password
//-------------------------------------------------------------------------------------------
void main()
{
	USER_NODE First=NULL;
	char q,g;
	starting_display();
	g:First=user(First);
	printf("\n\n\n");
	getchar();
	printf("\n\tThe available citites are\n");
	printf("Bengaluru\tHyderabad\tMumbai\t\tDelhi\t\tKolkata\t\tChennai\n");
	q:printf("Source:");
	gets(source);
	if(strcmp(strlwr(source),"bengaluru")==0)
		ban();
	else if(strcmp(strlwr(source),"hyderabad")==0)
		hyd();
	else if(strcmp(strlwr(source),"mumbai")==0)
		mum();
	else if(strcmp(strlwr(source),"delhi")==0)
		del();
	else if(strcmp(strlwr(source),"chennai")==0)
		chen();
	else if(strcmp(strlwr(source),"kolkata")==0)
		kol();
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
	goto g;
	return;
}
void starting_display(void)
{
	printf("\n\n\n\n\n\n\t\t\t\t\t");
	int i=0;
	while(i++<70)
		putchar('-');
	printf("\n\t\t\t\t\t|");
	i=0;while(i++<68)printf(" ");
	putchar('|');
	printf("\n\t\t\t\t\t|");
	printf("\tWELCOME TO IRCTC RAILWAY RESERVATION SYSTEM SIMULATION");
	clock_t start1=clock();
			while(clock()<start1+1000);//this is a clock() function which halts program for 1000ms
	i=0;
	while(i++<6)printf(" ");printf(" |");
	printf("\n\t\t\t\t\t|");
	i=0;while(i++<68)printf(" ");
	printf("|");
	printf("\n\t\t\t\t\t|\t\t----------MADE BY-----------");
	i=0;while(i++<25)printf(" ");printf("|");
	const char* array[]={
		"MUSTHAFFA","","","","","","",""
	};
	i=0;
	while(i<8)
	{
			clock_t start=clock();
			while(clock()<start+700);
				printf("\n\t\t\t\t\t|");
				printf("\t\t\t%s",array[i]);
				int a=0;while(a++<(45-strlen(array[i])))printf(" ");putchar('|');
			i++;
	}
	printf("\n\t\t\t\t\t");
	 i=0;
	while(i++<70)
		putchar('-');
	printf("\n\n\t\t\t\tPlease type the project password:\t");
	int k;
	while(scanf("%d",&k)==1)
	{
		if(k==976)
			break;
		printf("\n\t\t\t\tWrong password!! Type again:\t");
	}
	system("cls");//clears the display screen
	
}
USER_NODE user(USER_NODE First)
{
	char c;
	bool find;
	c:printf("\nChoose any one of the following:\t");
	printf("\n\n1.New user\t2.login\t\t3.exit\n");
	int n;scanf("%d",&n);
	switch(n)
	{
		case 1:First=create(First);find=true;break;
		case 2:find=login(First);break;
		case 3:exit(0);
		default:("Please choose the right option\n");goto c;
	}
	if(find==false)
		goto c;
	return First;
}

USER_NODE create(USER_NODE first)
{
	USER_NODE curr=first;
	if(first==NULL)
	{
		first=(USER_NODE)malloc(sizeof(struct user));
		printf("this is the first user\n");
		printf("\nType the username:\t");
		scanf("%s",first->name);
		printf("\nType the phone number:\t");
		scanf("%s",first->phno);
		printf("\nType the the date of birth:\t");
		scanf("%s",first->dob);
		printf("\nPlease set a password:\t");
		scanf("%s",first->pass);
		first->link=NULL;
		printf("\n\n\t\tWElCOME\t%s",first->name);
		return first;
	}
	while((curr->link)!=NULL){
		curr=curr->link;}//this searches till the last of the linked list
		USER_NODE temp=NULL;
		MALLOC(temp,sizeof(struct user),USER_NODE);
		printf("\nType the username:\t");
		scanf("%s",temp->name);
		printf("\nType the phone number:\t");
		scanf("%s",temp->phno);
		printf("\nType the the date of birth:\t");
		scanf("%s",temp->dob);
		printf("\nPlease set a password:\t");
		scanf("%s",temp->pass);
		temp->link=NULL;
		curr->link=temp;
		printf("\n\n\t\tWelcome!!\t%s \n",temp->name);
		getchar();
	return first;
}
bool login(USER_NODE first)//this function can return true or false based on the fact that user was found or not
{
	if(first==NULL)
	{
		printf("\n\tThere is no existing user present\n");
		return false;//NO user was find;
	}
	printf("\nType the username:\t");
	char username[30];scanf("%s",username);
	USER_NODE curr=first;
	while(curr!=NULL&&strcmp(curr->name,username))
		curr=curr->link;
	if(curr==NULL)
	{
		printf("\n There is no person with this name in our list\n");
		return false;
	}
	printf("\nType your password");
	char password[MAX];scanf("%s",password);
	while(strcmp(password,curr->pass))
	{
		printf("\n\tTry again\n");
		scanf("%s",password);
	}
	return true;
}
//----------------------------------------------------------------------
void ban()
{
	char q;
	q:printf("Destination:");
	gets(dest);
	if(strcmp(strlwr(dest),"hyderabad")==0)
	{
		printf("Date:");
		gets(date);
		ban_hyd();
	}
	else if(strcmp(strlwr(dest),"mumbai")==0)
	{
		printf("Date:");
		gets(date);
		ban_mum();
	}
	else if(strcmp(strlwr(dest),"delhi")==0)
	{
		printf("Date:");
		gets(date);
		ban_del();
	}
	else if(strcmp(strlwr(dest),"chennai")==0)
	{
		printf("Date:");
		gets(date);
		ban_chen();
	}
	else if(strcmp(strlwr(dest),"kolkata")==0)
	{
		printf("Date:");
		gets(date);
		ban_kol();
	}
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
}
void hyd()
{
	char q;
	q:printf("Destination:");
	gets(dest);
	if(strcmp(strlwr(dest),"bengaluru")==0)
	{
		printf("Date:");
		gets(date);
		hyd_ban();
	}
	else if(strcmp(strlwr(dest),"mumbai")==0)
	{
		printf("Date:");
		gets(date);
		hyd_mum();
	}
	else if(strcmp(strlwr(dest),"delhi")==0)
	{
		printf("Date:");
		gets(date);
		hyd_del();
	}
	else if(strcmp(strlwr(dest),"chennai")==0)
	{
		printf("Date:");
		gets(date);
		hyd_chen();
	}
	else if(strcmp(strlwr(dest),"kolkata")==0)
	{
		printf("Date:");
		gets(date);
		hyd_kol();
	}
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
}
void mum()
{
	char q;
	q:printf("Destination:");
	gets(dest);
	if(strcmp(strlwr(dest),"bengaluru")==0)
	{
		printf("Date:");
		gets(date);
		mum_ban();
	}
	else if(strcmp(strlwr(dest),"hyderabad")==0)
	{
		printf("Date:");
		gets(date);
		mum_hyd();
	}
	else if(strcmp(strlwr(dest),"delhi")==0)
	{
		printf("Date:");
		gets(date);
		mum_del();
	}
	else if(strcmp(strlwr(dest),"chennai")==0)
	{
		printf("Date:");
		gets(date);
		mum_chen();
	}
	else if(strcmp(strlwr(dest),"kolkata")==0)
	{
		printf("Date:");
		gets(date);
		mum_kol();
	}
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
}
void del()
{
	char q;
	q:printf("Destination:");
	gets(dest);
	if(strcmp(strlwr(dest),"bengaluru")==0)
	{
		printf("Date:");
		gets(date);
		del_ban();
	}
	else if(strcmp(strlwr(dest),"hyderabad")==0)
	{
		printf("Date:");
		gets(date);
		del_hyd();
	}
	else if(strcmp(strlwr(dest),"mumbai")==0)
	{
		printf("Date:");
		gets(date);
		del_mum();
	}
	else if(strcmp(strlwr(dest),"chennai")==0)
	{
		printf("Date:");
		gets(date);
		del_chen();
	}
	else if(strcmp(strlwr(dest),"kolkata")==0)
	{
		printf("Date:");
		gets(date);
		del_kol();
	}
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
}
void chen()
{
	char q;
	q:printf("Destination:");
	gets(dest);
	if(strcmp(strlwr(dest),"bengaluru")==0)
	{
		printf("Date:");
		gets(date);
		chen_ban();
	}
	else if(strcmp(strlwr(dest),"hyderabad")==0)
	{
		printf("Date:");
		gets(date);
		chen_hyd();
	}
	else if(strcmp(strlwr(dest),"mumbai")==0)
	{
		printf("Date:");
		gets(date);
		chen_mum();
	}
	else if(strcmp(strlwr(dest),"delhi")==0)
	{
		printf("Date:");
		gets(date);
		chen_del();
	}
	else if(strcmp(strlwr(dest),"kolkata")==0)
	{
		printf("Date:");
		gets(date);
		chen_kol();
	}
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
}
void kol()
{
	char q;
	q:printf("Destination:");
	gets(dest);
	if(strcmp(strlwr(dest),"bengaluru")==0)
	{
		printf("Date:");
		gets(date);
		kol_ban();
	}
	else if(strcmp(strlwr(dest),"hyderabad")==0)
	{
		printf("Date:");
		gets(date);
		kol_hyd();
	}
	else if(strcmp(strlwr(dest),"mumbai")==0)
	{
		printf("Date:");
		gets(date);
		kol_mum();
	}
	else if(strcmp(strlwr(dest),"delhi")==0)
	{
		printf("Date:");
		gets(date);
		kol_del();
	}
	else if(strcmp(strlwr(dest),"chennai")==0)
	{
		printf("Date:");
		gets(date);
		kol_chen();
	}
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
}
//Bangalore to Hyderabad
void ban_hyd(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("17604\t\tYelahanka(YNK)\t Kacheguda(KCG)\t\t YNK KCG EXP\t 16.20\t\t 5.00\t\t12hr40min\n");
	printf("12786\t\tBengaluru(SBC)\t Kacheguda(KCG)\t\t Kacheguda EXP\t 18.20\t\t 5.40\t\t11hr20min\n");
	printf("22691\t\tBengaluru(SBC))\t Secundrabad Jn(SC)\t RAJDHANI EXP\t 20.00\t\t 7.05\t\t11hr5min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 17604:printf("\nFare Chart:\n");
					printf("SL:365/-\t3A:990/-\t2A:1410/-\t1A:2360\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Yelahanka Jn(YNK)");
					strcpy(dest,"Kacheguda(KCG)");
					strcpy(tname,"YNK KCG EXP");
					strcpy(tno,"17604");
					strcpy(dur,"12hr40min");
					depart=16.20;
					arr=5.00;
					fi=passdata(n,fi);
					SL=365;
					Third=990;
					Second=1410;
					First=2360;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12786:printf("\nFare Chart:\n");
					printf("SL:385/-\t3A:1005/-\t2A:1415/-\t1A:2360\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"Kacheguda(KCG)");
					strcpy(tname,"KACHEGUDA EXP");
					strcpy(tno,"12786");
					strcpy(dur,"11hr20min");
					depart=18.20;
					arr=5.40;
					fi=passdata(n,fi);
					SL=385;
					Third=1005;
					Second=1415;
					First=2360;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 22691:printf("\nFare Chart:\n");
					printf("3A:1790/-\t2A:2100/-\t1A:3190\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"Secundrabad Jn(SC)");
					strcpy(tname,"RAJDHANI EXP");
					strcpy(tno,"22691");
					strcpy(dur,"11hr5min");
					depart=20.00;
					arr=7.05;
					fi=passdata(n,fi);
					SL=0;//No SL Class Coach
					Third=1790;
					Second=2100;
					First=3190;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Bangalore to Mumbai
void ban_mum(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("11302\t\tBengaluru(SBC)\t\t Mumbai(CSMT)\t\t UDYAN EXP\t 20.40\t\t 20.15\t\t 23hr35min\n");
	printf("16534\t\tBengaluru(SBC)\t\t Vasai Road(BSR)\t JODHPUR EXP\t 17.05\t\t 22.40\t\t 1day5hr35min\n");
	printf("16587\t\tYeshwantpur Jn(YPR)\t Vasai Road(BSR)\t BIKANER EXP\t 11.30\t\t 13.20\t\t 1day1hr50min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);
	switch(z)
	{
		case 11302:printf("\nFare Chart:\n");
					printf("SL:530/-\t3A:1425/-\t2A:1850/-\t1A:3465\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(tname,"UDYAN EXP");
					strcpy(tno,"11302");
					strcpy(dur,"23hr35min");
					depart=20.40;
					arr=20.15;
					fi=passdata(n,fi);
					SL=530;
					Third=1425;
					Second=1850;
					First=3465;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 16534:printf("\nFare Chart:\n");
					printf("SL:530/-\t3A:1425/-\t2A:1850/-\t1A:3465\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"Vasai Road(BSR)");
					strcpy(tname,"JODHPUR EXP");
					strcpy(tno,"16534");
					strcpy(dur,"1day5hr35min");
					depart=17.05;
					arr=22.40;
					fi=passdata(n,fi);
					SL=570;
					Third=1530;
					Second=2210;
					First=3740;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 16587:printf("\nFare Chart:\n");
					printf("SL:530/-\t3A:1425/-\t2A:1850/-\t1A:3465\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Yeshwantpur Jn(YPR)");
					strcpy(dest,"Vasai Road(BSR)");
					strcpy(tname,"BIKANER EXP");
					strcpy(tno,"16587");
					strcpy(dur,"1day1hr50min");
					depart=11.30;
					arr=13.20;
					fi=passdata(n,fi);
					SL=560;
					Third=1495;
					Second=2155;
					First=0;//No First Class Coach
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
}
//Bangalore to Delhi
void ban_del(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12627\t\tBengaluru(SBC)\t\t New Delhi(NDLS)\t KARNATAKA EXP\t 19.20\t\t 9.00\t\t 1day13hr40min\n");
	printf("22691\t\tBengaluru(SBC)\t\t Delhi(NZM)\t\t RAJDHANI EXP\t 20.00\t\t 5.30\t\t 1day9hr30min\n");
	printf("12629\t\tYeshwantpur Jn(YPR)\t Delhi(NZM)\t\t SAMPARK KRANTI\t 13.55\t\t 11.40\t\t 1day21hr45min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);
	switch(z)
	{
		case 12627:printf("\nFare Chart:\n");
					printf("SL:860/-\t3A:2225/-\t2A:3230/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"New Delhi(NDLS)");
					strcpy(tname,"KARNATAKA EXP");
					strcpy(tno,"12627");
					strcpy(dur,"1day13hr40min");
					depart=19.20;
					arr=9.00;
					fi=passdata(n,fi);
					SL=860;
					Third=2225;
					Second=3230;
					First=0;//No First Class Coach
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 22691:printf("\nFare Chart:\n");
					printf("3A:3280/-\t2A:4420/-\t1A:7300\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"Hazrat Nizammudin Delhi(NZM)");
					strcpy(tname,"RAJDHANI EXP");
					strcpy(tno,"22691");
					strcpy(dur,"1day9hr30min");
					depart=20.00;
					arr=5.30;
					fi=passdata(n,fi);
					SL=0;//No SL Class Coach
					Third=3280;
					Second=4420;
					First=7300;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12629:printf("\nFare Chart:\n");
					printf("SL:905/-\t3A:2335/-\t2A:3400/-\t1A:5815\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Yeshwantpur Jn(YPR)");
					strcpy(dest,"Hazrat Nizammudin Delhi(NZM)");
					strcpy(tname,"SAMPARK KRANTI");
					strcpy(tno,"12649");
					strcpy(dur,"1day21hr45min");
					depart=13.55;
					arr=11.40;
					fi=passdata(n,fi);
					SL=905;
					Third=2335;
					Second=3400;
					First=5815;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
}
//Bangalore to Chennai
void ban_chen(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12509\t\tKrishnarajapuram(KJM)\t Perambur(PER)\t\t GUWAHATI EXP\t 23.53\t\t 5.25\t\t 5hr32min\n");
	printf("12658\t\tBengaluru(SBC)\t\t Chennai(MAS))\t\t CHENNAI MAIL\t 22.40\t\t 4.15\t\t 5hr35min\n");
	printf("12295\t\tKrishnarajapuram(KJM)\t Perambur(PER)\t\t SANGHAMITRA EXP 9.35\t\t 14.35\t\t 5hr\n");
	printf("\nEnter train number:");
	scanf("%d",&z);
	switch(z)
	{
		case 12509:printf("\nFare Chart:\n");
					printf("SL:255/-\t3A:660/-\t2A:910/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krishnarajapuram(KJM)");
					strcpy(dest,"Perambur(PER)");
					strcpy(tname,"GUWAHATI EXP");
					strcpy(tno,"12509");
					strcpy(dur,"5hr32min");
					depart=23.53;
					arr=5.25;
					fi=passdata(n,fi);
					SL=255;
					Third=660;
					Second=910;
					First=0;//No First Class Coach
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12658:printf("\nFare Chart:\n");
					printf("SL:245/-\t3A:680/-\t2A:945/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"Puratchi Thalaivar Dr. M.G. Ramachandran Central(MAS)");
					strcpy(tname,"CHENNAI MAIL");
					strcpy(tno,"12658");
					strcpy(dur,"5hr35min");
					depart=22.40;
					arr=4.15;
					fi=passdata(n,fi);
					SL=245;
					Third=680;
					Second=945;
					First=0;//No First Class Coach
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12295:printf("\nFare Chart:\n");
					printf("SL:255/-\t3A:660/-\t2A:830/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krishnarajapuram(KJM)");
					strcpy(dest,"Perambur(PER)");
					strcpy(tname,"SANGHAMITRA EXP");
					strcpy(tno,"12295");
					strcpy(dur,"5hr");
					depart=9.35;
					arr=14.35;
					fi=passdata(n,fi);
					SL=905;
					Third=2335;
					Second=3400;
					First=5815;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
}
//Bangalore to Kolkata 
void ban_kol(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t\t Destination\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12246\t\tYeshwantpur Jn(YPR)\t Howrah Jn(HWH)\t DURONTO EXPRESS 11.00\t\t 16.50\t\t 1day5hr50min\n");
	printf("12864\t\tYeshwantpur Jn(YPR)\t Howrah Jn(HWH)) YPR HOWRAH EXP\t 10.15\t\t 7.55\t\t 1day9hr40min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);
	switch(z)
	{
		case 12246:printf("\nFare Chart:\n");
					printf("SL:1650/-\t3A:3890/-\t2A:5345/-\t1A:6685/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Yeshwantpur Jn(YPR)");
					strcpy(dest,"Howrah Jn(HWH)");
					strcpy(tname,"DURONTO EXPRESS");
					strcpy(tno,"12246");
					strcpy(dur,"1day5hr50min");
					depart=11.00;
					arr=16.50;
					fi=passdata(n,fi);
					SL=1650;
					Third=3890;
					Second=5345;
					First=6685;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12864:printf("\nFare Chart:\n");
					printf("SL:780/-\t3A:2035/-\t2A:2935/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Yeshwantpur Jn(YPR)");
					strcpy(dest,"Howrah Jn(HWH)");
					strcpy(tname,"YPR HOWRAH EXP");
					strcpy(tno,"12864");
					strcpy(dur,"1day9hr40min");
					depart=10.15;
					arr=19.55;
					fi=passdata(n,fi);
					SL=780;
					Third=2035;
					Second=2935;
					First=0;//No first Class Coach
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
}
//Hyderabad to Bangalore
void hyd_ban(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12591\t\tSecundrabad Jn(SC) Yeshwantpur Jn(YPR)\t GKP YPR EXPRESS 13.45\t\t 2.45\t\t13hr\n");
	printf("12650\t\tKacheguda(KCG)\t Yeshwantpur Jn(YPR)\t YPR SAMPARK KRT 8.40\t\t 5.30\t\t20hr50min\n");
	printf("12785\t\tKacheguda(KCG))\t Bengaluru(SBC)\t\t KCG MYS SF EXP\t 19.05\t\t 6.25\t\t11hr20min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12591:printf("\nFare Chart:\n");
					printf("SL:415/-\t3A:990/-\t2A:1390/-\t1A:2325\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Secundrabad Jn(SC)");
					strcpy(dest,"Yeshwantpur Jn(YPR)");
					strcpy(tname,"GKP YPR EXPRESS");
					strcpy(tno,"12591");
					strcpy(dur,"13hr");
					depart=13.45;
					arr=2.45;
					fi=passdata(n,fi);
					SL=415;
					Third=990;
					Second=1390;
					First=2325;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12650:printf("\nFare Chart:\n");
					printf("SL:540/-\t3A:1420/-\t2A:2020/-\t1A:3410\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Kacheguda(KCG)");
					strcpy(dest,"Yeshwantpur Jn(YPR)");
					strcpy(tname,"YPR SAMPARK KRT");
					strcpy(tno,"12650");
					strcpy(dur,"20hr50min");
					depart=8.40;
					arr=5.30;
					fi=passdata(n,fi);
					SL=540;
					Third=1420;
					Second=2020;
					First=3410;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12785:printf("\nFare Chart:\n");
					printf("SL:385/-\t3A:1005/-\t2A:1415/-\t1A:2360\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Kacheguda(KCG)");
					strcpy(dest,"Krantivira Sangolli Rayanna(SBC)");
					strcpy(tname,"KCG MYS SF EXP");
					strcpy(tno,"12785");
					strcpy(dur,"11hr20min");
					depart=19.05;
					arr=6.25;
					fi=passdata(n,fi);
					SL=385;
					Third=1005;
					Second=1415;
					First=2360;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
	
}
//Hyderabad to Mumbai
void hyd_mum(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("18519\t\tSecundrabad Jn(SC) Mumbai(LTT)\t\t VSKP LTT SPL\t 12.55\t\t 4.15\t\t15hr20min\n");
	printf("12702\t\tHyderabad(HYB)\t Mumbai(CSMT)\t\t HUSSAIN SAGAR\t 14.50\t\t 4.55\t\t14hr5min\n");
	printf("17032\t\tHyderabad(HYB))\t Mumbai(CSMT)\t\t MUMBAI EXP\t 20.55\t\t 13.05\t\t16hr10min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 18519:printf("\nFare Chart:\n");
					printf("SL:410/-\t3A:1110/-\t2A:1585/-\t1A:2660\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Secundrabad Jn(SBC)");
					strcpy(dest,"Lokmanya Tilak Terminus(LTT)");
					strcpy(tname,"VSKP LTT SPL");
					strcpy(tno,"18519");
					strcpy(dur,"15hr20min");
					depart=12.55;
					arr=4.15;
					fi=passdata(n,fi);
					SL=410;
					Third=1110;
					Second=1585;
					First=2660;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12702:printf("\nFare Chart:\n");
					printf("SL:405/-\t3A:1165/-\t2A:1645/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hyderabad(HYB)");
					strcpy(dest,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(tname,"HUSSAIN SAGAR");
					strcpy(tno,"12702");
					strcpy(dur,"14hr5min");
					depart=14.50;
					arr=4.55;
					fi=passdata(n,fi);
					SL=405;
					Third=1165;
					Second=1645;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 17032:printf("\nFare Chart:\n");
					printf("SL:415/-\t3A:1120/-\t2A:1445/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hyderabad(HYB)");
					strcpy(dest,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(tname,"MUMBAI EXP");
					strcpy(tno,"17032");
					strcpy(dur,"16hr10min");
					depart=20.55;
					arr=13.05;
					fi=passdata(n,fi);
					SL=415;
					Third=1120;
					Second=1445;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
}
//Hyderabad to Delhi
void hyd_del(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12285\t\tSecundrabad Jn(SC) Delhi(NZM)\t\t NZM DURONTO EXP 12.55\t\t 10.50\t\t21hr55min\n");
	printf("12723\t\tHyderabad(HYB)\t New Delhi(NDLS)\t TELANGANA EXP\t 6.00\t\t 7.50\t\t1day1hr50min\n");
	printf("12721\t\tHyderabad(HYB))\t Delhi(NZM)\t\t DAKSHIN EXP\t 23.00\t\t 3.40\t\t1day4hr40min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12285:printf("\nFare Chart:\n");
					printf("SL:1435/-\t3A:3440/-\t2A:4405/-\t1A:5865\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Secundrabad Jn(SC)");
					strcpy(dest,"Hazrat Nizammudin Delhi(NZM)");
					strcpy(tname,"NZM DURONTO EXP");
					strcpy(tno,"12285");
					strcpy(dur,"21hr55min");
					depart=12.55;
					arr=10.50;
					fi=passdata(n,fi);
					SL=1435;
					Third=3440;
					Second=4405;
					First=5865;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12723:printf("\nFare Chart:\n");
					printf("SL:700/-\t3A:1665/-\t2A:2395/-\t1A:4505\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hyderabad(HYB)");
					strcpy(dest,"New Delhi(NDLS)");
					strcpy(tname,"TELANGANA EXP");
					strcpy(tno,"12723");
					strcpy(dur,"1day1hr50min");
					depart=6.00;
					arr=7.50;
					fi=passdata(n,fi);
					SL=700;
					Third=1665;
					Second=2395;
					First=4505;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12721:printf("\nFare Chart:\n");
					printf("SL:700/-\t3A:1840/-\t2A:2645/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hyderabad(HYB)");
					strcpy(dest,"Hazrat Nizamuddin Delhi(NZM)");
					strcpy(tname,"DAKSHIN EXP");
					strcpy(tno,"12721");
					strcpy(dur,"1day4hr40min");
					depart=23.00;
					arr=3.40;
					fi=passdata(n,fi);
					SL=700;
					Third=1840;
					Second=2645;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
	
}
//Hyderabad to Chennai
void hyd_chen(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("17652\t\tKacheguda(KCG)\t Tambaram(TBM)\t\t KCG CGL EXPRESS 17.00\t\t 7.30\t\t14hr30min\n");
	printf("12604\t\tHyderabad(HYB)\t Chennai(MAS)\t\t CHENNAI SF EXP\t 16.45\t\t 5.40\t\t12hr55min\n");
	printf("12760\t\tHyderabad(HYB))\t Tambaram(TBM)\t\t CHARMINAR EXP\t 18.00\t\t 7.55\t\t13hr55min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 17652:printf("\nFare Chart:\n");
					printf("SL:415/-\t3A:1125/-\t2A:1610/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Kacheguda(KCG)");
					strcpy(dest,"Tambaram(TBM)");
					strcpy(tname,"KCG CGL EXPRESS");
					strcpy(tno,"17652");
					strcpy(dur,"14hr30min");
					depart=17.00;
					arr=7.30;
					fi=passdata(n,fi);
					SL=415;
					Third=1125;
					Second=1610;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12604:printf("\nFare Chart:\n");
					printf("SL:420/-\t3A:1100/-\t2A:1550/-\t1A:2595\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hyderabad(HYB)");
					strcpy(dest,"Puratchi Thalaivar Dr. M.G. Ramachandran Central(MAS)");
					strcpy(tname,"CHENNAI SF EXP");
					strcpy(tno,"12604");
					strcpy(dur,"12hr55min");
					depart=16.45;
					arr=5.40;
					fi=passdata(n,fi);
					SL=420;
					Third=1100;
					Second=1550;
					First=2595;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12760:printf("\nFare Chart:\n");
					printf("SL:455/-\t3A:1085/-\t2A:1525/-\t1A:2825\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hyderabad(HYB)");
					strcpy(dest,"Tambaram(TBM)");
					strcpy(tname,"CHARMINAR EXP");
					strcpy(tno,"12760");
					strcpy(dur,"13hr55min");
					depart=18.00;
					arr=7.55;
					fi=passdata(n,fi);
					SL=455;
					Third=1085;
					Second=1525;
					First=2825;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
}
//Hyderabad to Kolkata
void hyd_kol(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12704\t\tSecundrabad Jn(SC) Howrah Jn(HWH)\t FALAKNUMA EXP\t 15.55\t\t 17.40\t\t1day1hr45min\n");
	printf("18046\t\tHyderabad(HYB)\t Shalimar(SHM)\t\t EAST COAST EXP\t 8.00\t\t 14.40\t\t1day6hr40min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12704:printf("\nFare Chart:\n");
					printf("SL:600/-\t3A:1570/-\t2A:2490/-\t1A:4230\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Secundrabad Jn(SC)");
					strcpy(dest,"Howrah Jn(HWH)");
					strcpy(tname,"FALAKNUMA EXP");
					strcpy(tno,"12704");
					strcpy(dur,"1day1hr45min");
					depart=15.55;
					arr=17.40;
					fi=passdata(n,fi);
					SL=600;
					Third=1570;
					Second=2490;
					First=4230;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 18046:printf("\nFare Chart:\n");
					printf("SL:645/-\t3A:1720/-\t2A:2495/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hyderabad(HYB)");
					strcpy(dest,"Shalimar(SHM)");
					strcpy(tname,"EAST COAST EXP");
					strcpy(tno,"18046");
					strcpy(dur,"1day6hr40min");
					depart=8.00;
					arr=14.40;
					fi=passdata(n,fi);
					SL=645;
					Third=1720;
					Second=2495;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Delhi to Bangalore
void del_ban(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12650\t\tDelhi(NZM)\t Yeshwantpur Jn(YPR)\t YPR SAMPARK KRT 20.20\t\t 12.30\t\t1day16hr10min\n");
	printf("12628\t\tNew Delhi(NDLS)\t Bengaluru(SBC)\t\t KARNATAK EXP\t 8.20\t\t 5.30\t\t20hr50min\n");
	printf("22692\t\tDelhi(NZM))\t Bengaluru(SBC)\t\t SBC RAJDHANI\t 19.50\t\t 5.20\t\t1day9hr30min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12650:printf("\nFare Chart:\n");
					printf("SL:920/-\t3A:2380/-\t2A:3465/-\t1A:5935\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hazrat Nizamuddin Delhi (NZM)");
					strcpy(dest,"Yeshwanthpur Jn (YPR)");
					strcpy(tname,"YPR SAMPARK KRT");
					strcpy(tno,"12650");
					strcpy(dur,"1day21hr10min");
					depart=8.20;
					arr=5.30;
					fi=passdata(n,fi);
					SL=920;
					Third=2380;
					Second=3465;
					First=5935;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12628:printf("\nFare Chart:\n");
					printf("SL:865/-\t3A:2240/-\t2A:3250/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"New Delhi(NDLS)");
					strcpy(dest,"Krantivira Sangolli Rayanna(SBC)");
					strcpy(tname,"KARNATAKA EXP");
					strcpy(tno,"12628");
					strcpy(dur,"1day16hr10min");
					depart=20.20;
					arr=12.30;
					fi=passdata(n,fi);
					SL=865;
					Third=2240;
					Second=3250;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 22692:printf("\nFare Chart:\n");
					printf("3A:4245/-\t2A:4420/-\t1A:7300\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hazarat Nizamuddin(NZM)");
					strcpy(dest,"Krantivira Sangolli Rayanna(SBC)");
					strcpy(tname,"SBC RAJDHANI");
					strcpy(tno,"22692");
					strcpy(dur,"1day9hr30min");
					depart=19.50;
					arr=5.20;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=4245;
					Second=4420;
					First=7300;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Delhi to Hyderabad
void del_hyd(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12286\t\tDelhi(NZM)\t Secundrabad Jn(SC)\t SC DURONTO EXP\t 15.55\t\t 14.10\t\t22hr15min\n");
	printf("22692\t\tDelhi(NZM)\t Secundrabad Jn(SC)\t SBC RAJDHANI\t 19.50\t\t 17.10\t\t21hr20min\n");
	printf("12214\t\tDelhi(DEE))\t Secundrabad Jn(SC)\t DEE YPR DURONTO 22.10\t\t 20.55\t\t22hr45min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12286:printf("\nFare Chart:\n");
					printf("SL:1435/-\t3A:3240/-\t2A:3835/-\t1A:5865\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hazrat Nizamuddin Delhi (NZM)");
					strcpy(dest,"Secundrabad Jn (SC)");
					strcpy(tname,"SC DURONTO EXP");
					strcpy(tno,"12286");
					strcpy(dur,"22hr15min");
					depart=15.55;
					arr=14.10;
					fi=passdata(n,fi);
					SL=1435;
					Third=3240;
					Second=3835;
					First=5865;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 22692:printf("\nFare Chart:\n");
					printf("3A:3440/-\t2A:3545/-\t1A:5865\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hazrat Nizammudin Delhi(NZM)");
					strcpy(dest,"Secundrabad Jn(SC)");
					strcpy(tname,"SBC RAJDHANI");
					strcpy(tno,"22692");
					strcpy(dur,"21hr20min");
					depart=19.50;
					arr=17.10;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=3440;
					Second=3545;
					First=5865;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12214:printf("\nFare Chart:\n");
					printf("3A:3280/-\t2A:4750/-\t1A:5915\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Delhi Sarai Rohilla(DEE)");
					strcpy(dest,"Secundrabad Jn(SC)");
					strcpy(tname,"DEE YPR DURONTO");
					strcpy(tno,"12214");
					strcpy(dur,"22hr45min");
					depart=22.10;
					arr=20.55;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=3280;
					Second=4750;
					First=5915;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Delhi to Mumbai
void del_mum(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("19020\t\tDelhi(NZM)\t Bandra Jn(BDTS)\t HW BDTS EXP\t 18.55\t\t 22.15\t\t1day3hr20min\n");
	printf("12926\t\tNew Delhi(NDLS)\t Bandra Jn(BDTS)\t PASCHIM EXPRESS 16.35\t\t 15.25\t\t22hr50min\n");
	printf("12904\t\tDelhi(NZM))\t Mumbai Central(MMCT)\t GOLDEN TEMPLE M 4.00\t\t 23.45\t\t19hr45min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 19020:printf("\nFare Chart:\n");
					printf("SL:575/-\t3A:1565/-\t2A:2260/-\t1A:3835\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hazrat Nizamuddin Delhi (NZM)");
					strcpy(dest,"Bandra Jn (BDTS)");
					strcpy(tname,"HW BDTS EXP");
					strcpy(tno,"19020");
					strcpy(dur,"1day3hr20min");
					depart=18.55;
					arr=22.15;
					fi=passdata(n,fi);
					SL=575;
					Third=1565;
					Second=2260;
					First=3835;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12926:printf("\nFare Chart:\n");
					printf("SL:615/-\t3A:1610/-\t2A:2305/-\t1A:3910/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"New Delhi(NDLS)");
					strcpy(dest,"Bandra Jn(BDTS)");
					strcpy(tname,"PASCHIM EXPRESS");
					strcpy(tno,"12926");
					strcpy(dur,"22hr50min");
					depart=16.35;
					arr=15.25;
					fi=passdata(n,fi);
					SL=615;
					Third=1610;
					Second=2305;
					First=3910;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12904:printf("\nFare Chart:\n");
					printf("SL:620/-\t3A:1630/-\t2A:2335/-\t1A:3955\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hazarat Nizamuddin(NZM)");
					strcpy(dest,"Mumbai Central(MMCT)");
					strcpy(tname,"GOLDEN TEMPLE M");
					strcpy(tno,"12904");
					strcpy(dur,"19hr45min");
					depart=4.00;
					arr=13.45;
					fi=passdata(n,fi);
					SL=620;
					Third=1630;
					Second=2335;
					First=3955;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Delhi to Chennai
void del_chen(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12642\t\tDelhi(NZM)\t Tambaram(TBM)\t\t NZM CAPE SF EXP 5.20\t\t 16.43\t\t1day11hr23min\n");
	printf("12616\t\tNew Delhi(NDLS)\t Chennai(MAS)\t\t GRAND TRUNK EXP 16.10\t\t 4.30\t\t1day12hr20min\n");
	printf("12688\t\tDelhi(NZM))\t Perambur(PER)\t\t CDG MDU SF EXP\t 14.15\t\t 3.25\t\t1day13hr10min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12642:printf("\nFare Chart:\n");
					printf("SL:825/-\t3A:2150/-\t2A:3115/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hazrat Nizamuddin Delhi (NZM)");
					strcpy(dest,"Tambaram(TBM)");
					strcpy(tname,"NZM CAPE SF EXP");
					strcpy(tno,"12642");
					strcpy(dur,"1day11hr23min");
					depart=5.20;
					arr=16.43;
					fi=passdata(n,fi);
					SL=825;
					Third=2150;
					Second=3115;
					First=0;//Coach not avilable
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12616:printf("\nFare Chart:\n");
					printf("SL:820/-\t3A:2140/-\t2A:3100/-\t1A:5285/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"New Delhi(NDLS)");
					strcpy(dest,"Puratchi Thalaivar Dr. M.G. Ramachanran Central(MAS)");
					strcpy(tname,"GRAND TRUNK EXP");
					strcpy(tno,"12616");
					strcpy(dur,"1day12hr20min");
					depart=16.10;
					arr=4.30;
					fi=passdata(n,fi);
					SL=820;
					Third=2140;
					Second=3100;
					First=5285;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12688:printf("\nFare Chart:\n");
					printf("SL:820/-\t3A:2130/-\t2A:3080/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Hazarat Nizamuddin(NZM)");
					strcpy(dest,"Perambur(PER)");
					strcpy(tname,"CDG MDU SF EXP");
					strcpy(tno,"12688");
					strcpy(dur,"1day13hr10min");
					depart=14.15;
					arr=3.25;
					fi=passdata(n,fi);
					SL=820;
					Third=2130;
					Second=3080;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Delhi to Kolkata
void del_kol(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12312\t\tSabzi Mandi(SZM) Howrah Jn\t\t NETAJI EXPRESS\t 5.38\t\t 8.05\t\t1day2hr27min\n");
	printf("12314\t\tNew Delhi(NDLS)\t Sealdah(SDAH)\t\t SEALDAH RAJDHANI 16.30\t\t 10.10\t\t17hr40min\n");
	printf("12260\t\tNew Delhi(NDLS)\t Sealdah(SDAH)\t\t SDAH DURONTO\t 19.45\t\t 13.15\t\t17hr30min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12312:printf("\nFare Chart:\n");
					printf("SL:635/-\t3A:1665/-\t2A:2385/-\t1A:4045/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Sabzi Mandi(SZM)");
					strcpy(dest,"Howrah Jn(HWH)");
					strcpy(tname,"NETAJI EXPRESS");
					strcpy(tno,"12312");
					strcpy(dur,"1day2hr27min");
					depart=5.38;
					arr=8.05;
					fi=passdata(n,fi);
					SL=635;
					Third=1665;
					Second=2385;
					First=4045;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12314:printf("\nFare Chart:\n");
					printf("3A:3040/-\t2A:4170/-\t1A:4760/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"New Delhi(NDLS)");
					strcpy(dest,"Sealdah(SDAH)");
					strcpy(tname,"SEALDAH RAJDHANI");
					strcpy(tno,"12314");
					strcpy(dur,"17hr40min");
					depart=16.30;
					arr=10.10;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=3040;
					Second=4170;
					First=4760;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12260:printf("\nFare Chart:\n");
					printf("3A:2950/-\t2A:3295/-\t1A:5070/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"New Delhi(NDLS)");
					strcpy(dest,"Sealdah(SDAH)");
					strcpy(tname,"SDAH DURONTO");
					strcpy(tno,"12260");
					strcpy(dur,"17hr30min");
					depart=19.45;
					arr=13.15;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=2950;
					Second=3295;
					First=5070;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Mumbai to Bangalore
void mum_ban(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("16588\t\tVasai Road(BSR)\t Yeshwantpur Jn(YPR)\t BKN YPR EXP\t 14.00\t\t 15.45\t\t1day1hr45min\n");
	printf("11013\t\tMumbai(LTT)\t Bengaluru(SBC)\t\t COIMBTORE EXP\t 22.35\t\t 21.05\t\t22hr30min\n");
	printf("11005\t\tDadar(DR)\t Krishnarajauram(KJM)\t PUDUCHERRY EXP\t 21.30\t\t 22.05\t\t1day55min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 16588:printf("\nFare Chart:\n");
					printf("SL:560/-\t3A:1495/-\t2A:2155/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Vasai Road(BSR)");
					strcpy(dest,"Yeshwantpur Jn(YPR)");
					strcpy(tname,"BKM YPR EXP");
					strcpy(tno,"16588");
					strcpy(dur,"1day1hr45min");
					depart=14.00;
					arr=15.45;
					fi=passdata(n,fi);
					SL=560;
					Third=1495;
					Second=2155;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 11013:printf("\nFare Chart:\n");
					printf("SL:520/-\t3A:1385/-\t2A:1995/-\t1A:3375/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Lokmanya Tilak Terminus(LTT)");
					strcpy(dest,"Krantivira Sangolli Rayanna(SBC)");
					strcpy(tname,"COIMBTORE EXP");
					strcpy(tno,"11013");
					strcpy(dur,"22hr30min");
					depart=22.35;
					arr=21.05;
					fi=passdata(n,fi);
					SL=520;
					Third=1385;
					Second=1995;
					First=3375;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 11005:printf("\nFare Chart:\n");
					printf("SL:550/-\t3A:1475/-\t2A:2130/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Dadar(DR)");
					strcpy(dest,"Krishnarajapuram(KJM)");
					strcpy(tname,"PUDUCHERRY EXP");
					strcpy(tno,"11005");
					strcpy(dur,"1day55min");
					depart=21.30;
					arr=22.25;
					fi=passdata(n,fi);
					SL=550;
					Third=1475;
					Second=2130;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Mumbai to Hyderabad
void mum_hyd(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("22717\t\tVasai Road(BSR)\t Secundrabad Jn(SC)\t RJT SC SUP EXP\t 16.50\t\t 7.40\t\t14hr50min\n");
	printf("18520\t\tMumbai(LTT)\t Secundrabad Jn(SC)\t LTT VSKP EXP\t 6.55\t\t 20.30\t\t13hr35min\n");
	printf("17057\t\tMumbai(CSMT)\t Secundrabad Jn(SC)\t DEVAGIRI EXP\t 21.30\t\t 14.45\t\t17hr15min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 22717:printf("\nFare Chart:\n");
					printf("SL:445/-\t3A:1165/-\t2A:1645/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Vasai Road(BSR)");
					strcpy(dest,"Secundrabad Jn(SC)");
					strcpy(tname,"RJT SC SUP EXP");
					strcpy(tno,"22717");
					strcpy(dur,"14hr50min");
					depart=16.50;
					arr=7.40;
					fi=passdata(n,fi);
					SL=445;
					Third=1165;
					Second=1645;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 18520:printf("\nFare Chart:\n");
					printf("SL:410/-\t3A:1110/-\t2A:1585/-\t1A:2660/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Lokmanya Tilak Terminus(LTT)");
					strcpy(dest,"Secundrabad Jn(SC)");
					strcpy(tname,"LTT VSKP EXP");
					strcpy(tno,"18520");
					strcpy(dur,"13hr35min");
					depart=6.55;
					arr=20.30;
					fi=passdata(n,fi);
					SL=410;
					Third=1110;
					Second=1585;
					First=2660;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 17057:printf("\nFare Chart:\n");
					printf("SL:445/-\t3A:1205/-\t2A:1725/-\t1A:2905/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(dest,"Secundrabad Jn(SC)");
					strcpy(tname,"DEVAGIRI EXP");
					strcpy(tno,"17057");
					strcpy(dur,"1day55min");
					depart=21.30;
					arr=14.45;
					fi=passdata(n,fi);
					SL=445;
					Third=1205;
					Second=1725;
					First=2905;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Mumbai to Delhi
void mum_del(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("11057\t\tMumbai(CSMT)\t New Delhi(NDLS)\t CSMT ASR EXP\t 23.30\t\t 3.45\t\t1day4hr15min\n");
	printf("12171\t\tMumbai(LTT)\t Delhi(NZM)\t\t LTT HW AC EXP\t 7.55\t\t 6.35\t\t22hr40min\n");
	printf("22221\t\tMumbai(CSMT)\t Delhi(NZM)\t\t NZM RAJDHANI EX 16.00\t\t 9.55\t\t17hr55min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 11057:printf("\nFare Chart:\n");
					printf("SL:640/-\t3A:1705/-\t2A:2230/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(dest,"New Delhi(NDLS)v");
					strcpy(tname,"CSMT ASR EXP");
					strcpy(tno,"11057");
					strcpy(dur,"1day4hr15min");
					depart=23.30;
					arr=3.45;
					fi=passdata(n,fi);
					SL=640;
					Third=1705;
					Second=2230;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12171:printf("\nFare Chart:\n");
					printf("3A:1735/-\t2A:2490/-\t1A:3820/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Lokmanya Tilak Terminus(LTT)");
					strcpy(dest,"Hazrat Nizamuddin Delhi (NZM)");
					strcpy(tname,"LTT HW AC EXP");
					strcpy(tno,"12171");
					strcpy(dur,"22hr40min");
					depart=7.55;
					arr=6.35;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=1735;
					Second=2490;
					First=3820;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 22221:printf("\nFare Chart:\n");
					printf("3A:2945/-\t2A:3210/-\t1A:5360/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(dest,"Hazrat Nizamuddin Delhi (NZM)");
					strcpy(tname,"NZM RAJDHANI EXP");
					strcpy(tno,"22221");
					strcpy(dur,"17hr55min");
					depart=16.00;
					arr=9.55;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=2945;
					Second=3210;
					First=5360;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Mumbai to Chennai
void mum_chen(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("22157\t\tMumbai(CSMT)\t Chennai Egmore(MS)\t CSMT MS SF MAIL 22.55\t\t 22.15\t\t23hr20min\n");
	printf("22179\t\tMumbai(LTT)\t Chennai(MAS)\t\t LTT CHENNAI EXP 13.20\t\t 11.00\t\t23hr20min\n");
	printf("22159\t\tThane(TNA)\t Chennai(MAS)\t\t CSMT CHENNAI EXP 13.20\t\t 10.50\t\t21hr30min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 22157:printf("\nFare Chart:\n");
					printf("SL:595/-\t3A:1560/-\t2A:2225/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(dest,"Chennai Egmore(MS)");
					strcpy(tname,"CSMT MS SF MAIL");
					strcpy(tno,"22157");
					strcpy(dur,"23hr20min");
					depart=22.55;
					arr=22.15;
					fi=passdata(n,fi);
					SL=595;
					Third=1560;
					Second=2225;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 22179:printf("\nFare Chart:\n");
					printf("SL:590/-\t3A:1540/-\t2A:2200/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Lokmanya Tilak Terminus(LTT)");
					strcpy(dest,"Puratchi Thalaivar Dr. M.G. Ramachanran Central(MAS)");
					strcpy(tname,"LTT CHENNAI EXP");
					strcpy(tno,"22179");
					strcpy(dur,"21hr40min");
					depart=13.20;
					arr=11.00;
					fi=passdata(n,fi);
					SL=590;
					Third=1540;
					Second=2200;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 22159:printf("\nFare Chart:\n");
					printf("SL:590/-\t3A:1540/-\t2A:2200/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Thane(TNA)");
					strcpy(dest,"Puratchi Thalaivar Dr. M.G. Ramachanran Central(MAS)");
					strcpy(tname,"CSMT CHENNAI EX");
					strcpy(tno,"22159");
					strcpy(dur,"21hr30min");
					depart=13.20;
					arr=10.50;
					fi=passdata(n,fi);
					SL=590;
					Third=1540;
					Second=2200;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Mumbai to Kolkata
void mum_kol(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12859\t\tMumbai(CSMT)\t Howrah Jn(HWH)\t\t GITANJALI EXP\t 6.00\t\t 12.30\t\t1day6hr30min\n");
	printf("12809\t\tMumbai(CSMT)\t Howrah Jn(HWH)\t\t HOWRAH MAIL\t 21.10\t\t 6.00\t\t1day8hr50min\n");
	printf("20821\t\tPanvel Jn(PNVL)\t Santragachi Jn(RSC)\t PUNE SRC SUP EXP 13.05\t\t 18.35\t\t1day5hr30min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12859:printf("\nFare Chart:\n");
					printf("SL:780/-\t3A:2035/-\t2A:2935/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(dest,"Howrah Jn(HWH)");
					strcpy(tname,"GITANJALI EXP");
					strcpy(tno,"12859");
					strcpy(dur,"1day6hr30min");
					depart=6.00;
					arr=12.30;
					fi=passdata(n,fi);
					SL=780;
					Third=2035;
					Second=2935;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12809:printf("\nFare Chart:\n");
					printf("SL:780/-\t3A:2035/-\t2A:2935/-\t1A:5005/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(dest,"Howrah Jn(HWH)");
					strcpy(tname,"HOWRAH MAIL");
					strcpy(tno,"12809");
					strcpy(dur,"1day8hr50min");
					depart=21.10;
					arr=6.00;
					fi=passdata(n,fi);
					SL=780;
					Third=2035;
					Second=2935;
					First=5005;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 20821:printf("\nFare Chart:\n");
					printf("SL:770/-\t3A:2015/-\t2A:2910/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Panvel Jn(PNVL)");
					strcpy(dest,"Santragachi(SRC)");
					strcpy(tname,"PUNE SRC SUP EXP");
					strcpy(tno,"20821");
					strcpy(dur,"1day5hr30min");
					depart=13.05;
					arr=18.35;
					fi=passdata(n,fi);
					SL=770;
					Third=2015;
					Second=2910;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Kolkata to Bangalore
void kol_ban(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12863\t\tHowrah Jn(HWH)\t Yeshwantpur Jn(YPR)\t HWH YPR EXPRESS 23.00\t\t 7.15\t\t1day8hr15min\n");
	printf("22863\t\tHowrah Jn(HWH)\t Yeshwantpur Jn(YPR)\t YPR SUF AC EXP\t 10.50\t\t 16.20\t\t1day5hr30min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);
	switch(z)
	{
		case 12863:printf("\nFare Chart:\n");
					printf("SL:780/-\t3A:2035/-\t2A:2935/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Howrah Jn(HWH)");
					strcpy(dest,"Yeshwantpur Jn(YPR)");
					strcpy(tname,"HWH YPR EXPRESS");
					strcpy(tno,"12863");
					strcpy(dur,"1day8hr15min");
					depart=23.00;
					arr=7.15;
					fi=passdata(n,fi);
					SL=780;
					Third=2035;
					Second=2935;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 22863:printf("\nFare Chart:\n");
					printf("3A:2035/-\t2A:2935/-\t1A:5005/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Howrah Jn(HWH)");
					strcpy(dest,"Yeshwantpur Jn(YPR)");
					strcpy(tname,"YPR SUF AC EXP");
					strcpy(tno,"22863");
					strcpy(dur,"1day5hr30min");
					depart=10.50;
					arr=16.20;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=2035;
					Second=2935;
					First=5005;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
}
//Kolkata to Hyderabad
void kol_hyd(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12703\t\tHowrah Jn(HWH)\t Secundrabad Jn(SC)\t HWH SC SUF EXP\t 8.35\t\t 10.10\t\t1day1hr35min\n");
	printf("18045\t\tShalimar(SHM)\t Hyderabad(HYB)\t\t SHM HYB EXP\t 11.25\t\t 17.45\t\t1day6hr20min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 18045:printf("\nFare Chart:\n");
					printf("SL:645/-\t3A:1720/-\t2A:2495/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Shalimar(SHM)");
					strcpy(dest,"Hyderabad(HYB)");
					strcpy(tname,"SHM HYB EXP");
					strcpy(tno,"18045");
					strcpy(dur,"1day6hr20min");
					depart=11.25;
					arr=17.45;
					fi=passdata(n,fi);
					SL=645;
					Third=1720;
					Second=2495;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12703:printf("\nFare Chart:\n");
					printf("SL:665/-\t3A:1735/-\t2A:2490/-\t1A:4230/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Howrah Jn(HWH)");
					strcpy(dest,"Secundrabad Jn(SC)");
					strcpy(tname,"HWH SC SUF EXP");
					strcpy(tno,"12703");
					strcpy(dur,"1day1hr35min");
					depart=8.35;
					arr=10.10;
					fi=passdata(n,fi);
					SL=665;
					Third=1735;
					Second=2490;
					First=4230;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
			default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Kolkata to Mumbai
void kol_mum(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("12102\t\tShalimar(SHM)\t Mumbai(LTT)\t\t SHM LTT SUF EXP 21.05\t\t 3.55\t\t1day6hr50min\n");
	printf("12321\t\tHowrah Jn(HWH)\t Mumbai(CSMT)\t\t MUMBAI MAIL\t 23.35\t\t 13.20\t\t1day13hr55min\n");
	printf("12810\t\tHowrah Jn(HWH)\t Mumbai(CSMT)\t\t HWH CSMT SF EXP 19.50\t\t 4.25\t\t1day8hr35min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12102:printf("\nFare Chart:\n");
					printf("SL:770/-\t3A:2015/-\t2A:2910/-\t1A:4960\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Shalimar(SHM)");
					strcpy(dest,"Lokmanya Tilak Terminus(LTT)");
					strcpy(tname,"SHM LTT SUF EXP");
					strcpy(tno,"12102");
					strcpy(dur,"1day6hr50min");
					depart=21.05;
					arr=3.55;
					fi=passdata(n,fi);
					SL=770;
					Third=2015;
					Second=2910;
					First=4960;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12321:printf("\nFare Chart:\n");
					printf("SL:820/-\t3A:2130/-\t2A:3080/-\t1A:5260/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Howrah Jn(HWH)");
					strcpy(dest,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(tname,"MUMBAI MAIL");
					strcpy(tno,"12321");
					strcpy(dur,"1day13hr55min");
					depart=23.35;
					arr=13.30;
					fi=passdata(n,fi);
					SL=820;
					Third=2130;
					Second=3080;
					First=5260;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12810:printf("\nFare Chart:\n");
					printf("SL:780/-\t3A:2035/-\t2A:2935/-\t1A:5005\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Howrah Jn(HWH)");
					strcpy(dest,"Chhatrapati Shivaji Maharaj Terminus(CSMT)");
					strcpy(tname,"HWH CSMT SF EXP");
					strcpy(tno,"12810");
					strcpy(dur,"1day8hr35min");
					depart=19.50;
					arr=4.25;
					fi=passdata(n,fi);
					SL=780;
					Third=2035;
					Second=2935;
					First=5005;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Kolkata to Delhi
void kol_del(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("22857\t\tSantragachi(SRC) Delhi(ANVT)\t\t SRC ANVT SF EXP 10.00\t\t 8.40\t\t22hr40min\n");
	printf("12311\t\tHowrah Jn(HWH)\t Sabzi Mandi(SZM)\t NETAJI EXPRESS\t 21.55\t\t 21.24\t\t23hr29min\n");
	printf("12273\t\tHowrah Jn(HWH)\t New Delhi(NDLS)\t NDLS DURONTO EX 8.35\t\t 6.35\t\t22hr\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12311:printf("\nFare Chart:\n");
					printf("SL:635/-\t3A:1665/-\t2A:2385/-\t1A:4045\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Howrah Jn(HWH)");
					strcpy(dest,"Sabzi Mandi(SZM)");
					strcpy(tname,"NETAJI EXPRESS");
					strcpy(tno,"12311");
					strcpy(dur,"23hr29min");
					depart=21.55;
					arr=21.24;
					fi=passdata(n,fi);
					SL=635;
					Third=1665;
					Second=2385;
					First=4045;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12273:printf("\nFare Chart:\n");
					printf("SL:1360/-\t3A:2545/-\t2A:3375/-\t1A:5570/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Howrah Jn(HWH)");
					strcpy(dest,"New Delhi(NDLS)");
					strcpy(tname,"NDLS DURONTO EX");
					strcpy(tno,"12273");
					strcpy(dur,"22hr");
					depart=8.35;
					arr=6.35;
					fi=passdata(n,fi);
					SL=1360;
					Third=2545;
					Second=3375;
					First=5570;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 22857:printf("\nFare Chart:\n");
					printf("SL:670/-\t3A:1755/-\t2A:2520/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Santragachi Jn(SRC)");
					strcpy(dest,"Anand Vihar Terminal(ANVT)");
					strcpy(tname,"RSC ANVT EXP");
					strcpy(tno,"22857");
					strcpy(dur,"22hr40min");
					depart=10.00;
					arr=8.40;
					fi=passdata(n,fi);
					SL=670;
					Third=1755;
					Second=2520;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Kolkata to Chennai
void kol_chen(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t\t Departure\t Arrival\tDuration\n");
	printf("12841\t\tShalimar(SHM)\t Chennai(MAS)\t\t SHM MAS SUF EXP\t 15.20\t\t 16.50\t\t1day1hr30min\n");
	printf("22642\t\tSantragachi Jn(SRC)Perambur(PER)\t SHM TVC SUF EXP\t 00.07\t\t 2.35\t\t1day2hr28min\n");
	printf("12665\t\tHowrah Jn(HWH)\t Tambaram(TBM)\t\t HWH CAPE SF EXP\t 16.15\t\t 21.38\t\t1day5hr23min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12841:printf("\nFare Chart:\n");
					printf("SL:695/-\t3A:1825/-\t2A:2625/-\t1A:4460\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Shalimar(SHM)");
					strcpy(dest,"Puratchi Thalaivar Dr. M.G. Ramachanran Central(MAS)");
					strcpy(tname,"SHM MAS SUF EXP");
					strcpy(tno,"12841");
					strcpy(dur,"1day1hr30min");
					depart=15.20;
					arr=16.50;
					fi=passdata(n,fi);
					SL=695;
					Third=1825;
					Second=2625;
					First=4460;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 22642:printf("\nFare Chart:\n");
					printf("SL:695/-\t3A:1825/-\t2A:2625/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Santaragachi Jn(SRC)");
					strcpy(dest,"Perambur(PER)");
					strcpy(tname,"SHM TVC SUF EXP");
					strcpy(tno,"22642");
					strcpy(dur,"1day2hr28min");
					depart=00.07;
					arr=2.35;
					fi=passdata(n,fi);
					SL=695;
					Third=1825;
					Second=2625;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12665:printf("\nFare Chart:\n");
					printf("SL:700/-\t3A:1840/-\t2A:2645/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Howrah Jn(HWH)");
					strcpy(dest,"Tambaram(TBM)");
					strcpy(tname,"HWH CAPE SF EXP");
					strcpy(tno,"12665");
					strcpy(dur,"1day5hr23min");
					depart=16.15;
					arr=21.38;
					fi=passdata(n,fi);
					SL=700;
					Third=1840;
					Second=2645;
					First=0;//Coach not available 
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Chennai to Hyderabad
void chen_hyd(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t\t Departure\t Arrival\tDuration\n");
	printf("12759\t\tTambaram(TBM)\t Hyderabad(HYB)\t\t CHARMINAR EXPRESS\t 17.10\t\t 7.50\t\t14hr40min\n");
	printf("17651\t\tTambaram(TMB)\t Kacheguda(KCG)\t\t CGL KCG EXPRESS\t 16.05\t\t 7.55\t\t15hr50min\n");
	printf("12603\t\tChennai(MAS)\t Hyderabad(HYB)\t\t MAS HYB EXPRESS\t 16.45\t\t 5.45\t\t13hr\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12759:printf("\nFare Chart:\n");
					printf("SL:455/-\t3A:1190/-\t2A:1685/-\t1A:2825\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Tambaram(TBM)");
					strcpy(dest,"Hyderabad(HYB)");
					strcpy(tname,"CHARMINAR EXPRESS");
					strcpy(tno,"12759");
					strcpy(dur,"14hr40min");
					depart=17.10;
					arr=7.50;
					fi=passdata(n,fi);
					SL=455;
					Third=1190;
					Second=1685;
					First=2825;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 17651:printf("\nFare Chart:\n");
					printf("SL:415/-\t3A:1125/-\t2A:1610/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Tambaram(TMB)");
					strcpy(dest,"Kacheguda(KCG)");
					strcpy(tname,"CGL KCG EXPRESS");
					strcpy(tno,"17651");
					strcpy(dur,"15hr50min");
					depart=16.05;
					arr=7.55;
					fi=passdata(n,fi);
					SL=415;
					Third=1125;
					Second=1610;
					First=0;//Coach not avvailable
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12603:printf("\nFare Chart:\n");
					printf("SL:420/-\t3A:1100/-\t2A:1550/-\t1A:2595\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Purutchi Thalaivar Dr.M.G.Ramachandran central(MAS)");
					strcpy(dest,"Hyderabad(HYB)");
					strcpy(tname,"MAS HYB EXPRESS");
					strcpy(tno,"12603");
					strcpy(dur,"13hr");
					depart=16.45;
					arr=5.45;
					fi=passdata(n,fi);
					SL=420;
					Third=1100;
					Second=1550;
					First=2595;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Chennai to Kolkata
void chen_kol(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t\t Departure\t Arrival\tDuration\n");
	printf("12842\t\tChennai(MAS)\t Shalimar(SHM)\t\t COROMANDEL EXPRESS\t 7.00\t\t 10.40\t\t1day3hr40min\n");
	printf("12840\t\tChennai(MAS)\t Howrah Jn(HWH)\t\t MAS HWH MAIL\t\t 7.15\t\t 23.00\t\t1day3hr45min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12842:printf("\nFare Chart:\n");
					printf("SL:695/-\t3A:1825/-\t2A:2625/-\t1A:4460\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Puratchi Thalaivar Dr.M.G.Ramachandran Central(MAS)");
					strcpy(dest,"Shalimar(SHM)");
					strcpy(tname,"COROMANDEL EXPRESS");
					strcpy(tno,"12842");
					strcpy(dur,"1day3hr40min");
					depart=7.00;
					arr=10.40;
					fi=passdata(n,fi);
					SL=695;
					Third=1825;
					Second=2625;
					First=4460;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12840:printf("\nFare Chart:\n");
					printf("SL:635/-\t3A:1650/-\t2A:2625/-\t1A:4460\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Puratchi Thalaivar Dr.M.G.Ramachandran Central(MAS)");
					strcpy(dest,"Howrah Jn(HWH)");
					strcpy(tname,"MAS HWH MAIL");
					strcpy(tno,"12840");
					strcpy(dur,"1day3hr45min");
					depart=7.15;
					arr=23.00;
					fi=passdata(n,fi);
					SL=635;
					Third=1650;
					Second=2625;
					First=4460;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Chennai to Bangalore
void chen_ban(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("16021\t\tChennai(MAS)\t Bengaluru(SBC)\t\t MAS MYS SPL\t 21.15\t\t 3.45\t\t6hr30min\n");
	printf("12657\t\tChennai(MAS)\t Bengaluru(SBC)\t\t MAS SBC MAIL\t 22.50\t\t 4.30\t\t5hr40min\n");
	printf("12504\t\tPerambur(PER)\t Bangalore Cant(BNC)\t HUMSAFAR EXP\t 14.00\t\t 20.15\t\t6hr15min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 16021:printf("\nFare Chart:\n");
					printf("SL:235/-\t3A:575/-\t2A:900/-\t1A:1355\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Puratchi Thalaivar Dr.M.G.Ramachandran Central(MAS)");
					strcpy(dest,"Krantivira Sangolli Rayanna(SBC)");
					strcpy(tname,"MAS MYS SPL");
					strcpy(tno,"16021");
					strcpy(dur,"6hr30min");
					depart=21.15;
					arr=3.45;
					fi=passdata(n,fi);
					SL=235;
					Third=575;
					Second=900;
					First=1355;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12657:printf("\nFare Chart:\n");
					printf("SL:265/-\t3A:680/-\t2A:945/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Puratchi Thalaivar Dr.M.G.Ramachandran Central(MAS)");
					strcpy(dest,"Krantivira Sangolli Rayanna(SBC)");
					strcpy(tname,"MAS BSC MAIL");
					strcpy(tno,"12657");
					strcpy(dur,"5hr40min");
					depart=22.50;
					arr=4.30;
					fi=passdata(n,fi);
					SL=265;
					Third=680;
					Second=945;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12504:printf("\nFare Chart:\n");
					printf("3A:690/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Perambur(PER)");
					strcpy(dest,"Bangalore Cant(BNC)");
					strcpy(tname,"HUMSAFAR EXP");
					strcpy(tno,"12504");
					strcpy(dur,"6hr15min");
					depart=14.00;
					arr=20.15;
					fi=passdata(n,fi);
					SL=0;//Coach not available
					Third=690;
					Second=0;//Coach not available
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Chennai to Delhi
void chen_del(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t\t Departure\t Arrival\tDuration\n");
	printf("12621\t\tChennai(MAS)\t New Delhi(NDLS)\t TAMILNADU EXP\t\t 22.00\t\t 7.40\t\t1day9hr40min\n");
	printf("12687\t\tPerambur(PER)\t Delhi(NZM)\t\t MDU CDG EXPRESS\t 9.15\t\t 21.35\t\t1day12hr20min\n");
	printf("12269\t\tChennai(MAS)\t Delhi(NZM)\t\t MAS NZM DURONTO\t 6.35\t\t 10.40\t\t1day4hr5min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 12621:printf("\nFare Chart:\n");
					printf("SL:820/-\t3A:2140/-\t2A:3100/-\t1A:5285\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Puratchi Thalaivar Dr.M.G.Ramachandran Central(MAS)");
					strcpy(dest,"New Delhi(NDLS)");
					strcpy(tname,"TAMILNADU EXP");
					strcpy(tno,"12621");
					strcpy(dur,"1day9hr40min");
					depart=22.00;
					arr=7.40;
					fi=passdata(n,fi);
					SL=820;
					Third=2140;
					Second=3100;
					First=5285;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 12687:printf("\nFare Chart:\n");
					printf("SL:820/-\t3A:2140/-\t2A:3100/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Perambur(PER)");
					strcpy(dest,"Hazrat Nizamuddin Delhi (NZM)");
					strcpy(tname,"MDU CDG EXPRESS");
					strcpy(tno,"12687");
					strcpy(dur,"1day12hr20min");
					depart=9.15;
					arr=21.35;
					fi=passdata(n,fi);
					SL=820;
					Third=2140;
					Second=3100;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 12269:printf("\nFare Chart:\n");
					printf("SL:1525/-\t3A:3585/-\t2A:4530/-\t1A:6940\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Puratchi Thalaivar Dr. M.G. Ramachanran Central(MAS)");
					strcpy(dest,"Hazrat Nizamuddin Delhi (NZM)");
					strcpy(tname,"MAS NZM DURONTO");
					strcpy(tno,"12269");
					strcpy(dur,"1day4hr5min");
					depart=6.35;
					arr=10.40;
					fi=passdata(n,fi);
					SL=1525;
					Third=3585;
					Second=4530;
					First=6940;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
//Chennai to Mumbai
void chen_mum(void)
{
	int z,y;
	char q;
	NODE fi=NULL;
	q:printf("\nTrain Number\tSource\t\t\t Destination\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("11018\t\tChennai Egmore(MS)\t Mumbai(LTT)\t KIK LTT EXPRESS 22.10\t\t 20.30\t\t22hr20min\n");
	printf("22158\t\tChennai Egmore(MS)\t Dadar(DR)\t MS CSMT EXP\t 6.20\t\t 5.17\t\t22hr57min\n");
	printf("22160\t\tChennai(MAS)\t\t Dadar(DR)\t MAS CSMT EXP\t 13.25\t\t 11.52\t\t22hr27min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 11018:printf("\nFare Chart:\n");
					printf("SL:560/-\t3A:1495/-\t2A:2155/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Chennai Egmore(MS)");
					strcpy(dest,"Lokmanya Tilak Terminus(LTT)");
					strcpy(tname,"KIK LTT EXPRESS");
					strcpy(tno,"11018");
					strcpy(dur,"22hr20min");
					depart=22.10;
					arr=20.30;
					fi=passdata(n,fi);
					SL=560;
					Third=1495;
					Second=2155;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
				   break;
		case 22158:printf("\nFare Chart:\n");
					printf("SL:595/-\t3A:1560/-\t2A:2225/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Chennai Egmore(MS)");
					strcpy(dest,"Dadar(DR)");
					strcpy(tname,"MS CSMT EXP");
					strcpy(tno,"22158");
					strcpy(dur,"22hr57min");
					depart=6.20;
					arr=5.17;
					fi=passdata(n,fi);
					SL=595;
					Third=1560;
					Second=2225;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		case 22160:printf("\nFare Chart:\n");
					printf("SL:590/-\t3A:1540/-\t2A:2200/-\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Puratchi Thalaivar Dr. M.G. Ramachanran Central(MAS)");
					strcpy(dest,"Dadar(DR)");
					strcpy(tname,"MAS CSMT EXP");
					strcpy(tno,"22160");
					strcpy(dur,"22hr27min");
					depart=13.25;
					arr=11.52;
					fi=passdata(n,fi);
					SL=590;
					Third=1540;
					Second=2200;
					First=0;//Coach not available
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}	
}
NODE passdata(int m,NODE t)
{
	int i;
	for(i=1;i<=m;i++)
		{
	   		printf("\nEnter Passenger %d details:\n",i);
	   		ReadData();
	   		t=InsFront(t,m);
	   }
	   return t;
}
//Reading Passenger Details
void ReadData()
{
	printf("Enter Name:\n");
	getchar();
	gets(name);
	printf("Enter Gender:\n");
	scanf("%s",gen);
	printf("Enter Age:\n");
	scanf("%d",&age);
	printf("Enter Phone Number:\n");
	scanf("%s",ph);
}
NODE InsFront(NODE first,int y)
{
	NODE q=NULL;
	MALLOC(q,sizeof(struct details),NODE);
	strcpy(q->Name,name);
	strcpy(q->Gender,gen);
	q->Age=age;
	strcpy(q->Phone,ph);
	q->link=first;
	return q;
}
//Train Fare Calculation
int calc(int x1,int x2,int x3,int x4,int y)
{
	int d,h;
	printf("Select Class:\n");
	printf("1.SL\t2.3A\t3.2A\t4.1A\n");
	scanf("%d",&d);
	switch(d)
	{
		case 1:strcpy(cla,"SL");
				h=x1*y;
				payment();
				return h;
				
		case 2:strcpy(cla,"3A");
				h=x2*y;
				payment();
				return h;
				
		case 3:strcpy(cla,"2A");
				h=x3*y;
				payment();
				return h;
				
		case 4:strcpy(cla,"1A");
				h=x4*y;
				payment();
				return h;
			
		default:printf("Select valid Class.\n");
		break;
	}
}
//Seat Allotment
void seat(int p)
{
	time_t t;
	int i,x[MAX];
	srand((unsigned) time(&t));
	if(p<6)
	{
		for(i=0;i<p;i++)
			sno[i]=(rand()%25)+32;
	}	
	else
	{
		for(i=0;i<p;i++)
		sno[i]=(rand()%72)+1;
	}	
	for(i=0;i<p;i++)
		x[i]=sno[i]%8;
		printf("\nBerth:\t");
	for(i=0;i<n;i++)
	{
		if(x[i]==1||x[i]==4)
			printf("LB\t");//Lower Berth
		else if(x[i]==2||x[i]==5)
			printf("MB\t");//Middle Berth
		else if(x[i]==3||x[i]==6)
			printf("UB\t");//Upper Berth
		else if(x[i]==7)
			printf("SLB\t");//Side lower Berth
		else
			printf("SUB\t");//Side Upper Berth
	}
	printf("\n");
	printf("Seat No.:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",sno[i]);
	}
	printf("\n");
	return;
}
//Ticket Payment
void payment(void)
{
	time_t t;
	srand((unsigned) time(&t));
	while(1){
	printf("\n\n\t\tPlease type the otp received on your mobile number:(wait 5 seconds)\t");
	int k=(rand()%8999)+1000;//rand() function with ranges to generate random otp
	clock_t start=clock();
			while(clock()<start+5000);//will receive otp in five seconds
	printf("\t\t\t\t\t\t|OTP--%d|\n",k);
	int y;
	printf("Enter OTP:");
	scanf("%d",&y);
	if(y==k){
		printf("\nYour payment is being processed\n");
		start=clock();
			while(clock()<start+2000);
		printf("\nYour payment was successful.\n");
		start=clock();
			while(clock()<start+2000);
		break;
	}
	printf("\nType again");
	continue;
	}
	return;
}
//Coach Allotment
void coach()
{
	int x;
	time_t t;
	srand((unsigned) time(&t));
	x=1+(rand()%12);
	printf("\nCoach:S%d\n",x);
}
//Final Ticket PrintOut
void ticket(NODE q,int p)
{
	int i;
	printf("\n**************************************************TICKET**************************************************\n");
	printf("\nSource\t\tDestination\t\tTrain Name\tTrain No.\tClass\n");
	printf("%s\t%s\t%s\t%s\t\t%s\n",source,dest,tname,tno,cla);
	printf("\nDate:%s\n",date);
	printf("\nDeparture\tArrival\t\tDuration\n");
	printf("%.2f\t\t%.2f\t\t%s\n",depart,arr,dur);
	printf("\nFare:%d\n",amount);
	clock_t start=clock();
			while(clock()<start+500);//it takes a little time to print the further ticket
	coach();
	seat(p);
	printf("\n");
	printf("\nPassenger Details:\n");
	start=clock();
			while(clock()<start+300);
	while(q)
	{
		printf("\nName:%s\nGender:%s\nAge:%d\nPhone Number:%s\n",q->Name,q->Gender,q->Age,q->Phone);
		q=q->link;
	}
	printf("\n\n*********************************************HAPPY JOURNEY*********************************************\n\n");
	printf("1.Cancel Ticket\t2.continue\n");
	int n;
}
