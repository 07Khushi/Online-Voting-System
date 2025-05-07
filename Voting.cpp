#include <iostream>
using namespace std;
void voting();
void voteresult();
void candidate();
int result[26],n;
string a[25];
int main(){
string username;
int password;
int choice;
start:
cout<<"\n\t**\n";
cout<<" ONLINE VOTING SYSTEM\n";
cout<<"\t**\n";
int login=0;
cout<<"\nChoose 1 to login as candidate\nChoose 2 to login as voter\nChoose 3 to see result\nChoose 4 to EXIT\n";
cin>>choice;
while((choice!=1)&&(choice!=2)&&(choice!=3)&&(choice!=4)){
cout<<"Invalid choice\nChoose again\n";
cin>>choice;
}
if(choice==4)
return 0;
else{
cout<<"**\n";
cout<<"WELCOME IN SRMIST ELECTIONS\n" ;
cout<<"**\n";
relogin:
cout<<"\nUSERNAME:";
cin>>username;
cout<<"PASSWORD:";
cin>>password;
if(username=="SRMIST" && password==2022){
    if(choice==1)
candidate();
else if(choice==2)
voting();
else if(choice==3)
voteresult();
}
else
{
cout<<"Invalid user id and password.\n";
login++;
if(login==4){
cout<<"Too many login attempts!\nInvalid to try more\n";
goto start;
}
else
goto relogin;
}
}
goto start;
return 0;
}
void candidate()
{
if(n==0)
cout<<"NO CANDIDATE AVAILABLE";
else
{
    cout<<"LIST OF CANDIDATES AVAILABLE";
for(int i=0;i<n;i++)
cout<<"\n"<<i<<" for "<<a[i];
}
if(n==25)
cout<<"\nCandidate list is full!!";
else
{
cout<<"\n\nEnter your name to register:\n";
cin>>a[n];
n++;
}
}
void voting()
{
    if(n==0)
cout<<"NO CANDIDATE AVAILABLE";
else
{
int i,c;
cout<<"CHOOSE NO. FOR CANDIDTE YOU WANT TO VOTE";
for(i=0;i<n;i++)
{
cout<<"\n"<<i<<" for "<<a[i];
result[i]=0;
}
cout<<"\n"<<n<<" for NOTA\n";
result[n]=0;
cout<<"\nEnter your choice : ";
cin>>c;
for(i=0;i<=n;i++)
{
if(i==c)
result[i]++;
}
}
}
void voteresult()
{
if(n==0)
cout<<"NO CANDIDATE AVAILABLE";
else
{
int won=0;
for(int i=1;i<=n;i++)
{
if(result[i]>result[won])
won=i;
}
if(won==n)
cout<<"NOTA IS WINNING THIS ELECTION\n";
else
cout<<a[won]<<" IS WINNING THIS ELECTION\n";
}
}