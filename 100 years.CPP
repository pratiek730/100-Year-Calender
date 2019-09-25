#include<conio.h>
#include<iostream.h>
#include<fstream.h>


//Printing *******************************************************************************************************************
void prt(int st,int td)
{
int i;
cout<<"Mon\tTue\tWed\tThu\tFri\tSat\tSun\n\n";
for(i=1;i<st;i++)
cout<<"\t";
i=1;
while(i<=td)
{
if(st<=7)
{
cout<<i<<"\t";
st++;
i++;
}
else
{
cout<<"\n";
st=1;
}

}

}

//Class Y *******************************************************************************************************************


class Year
{
int y;
char t;

public:
void input(int x)
{
y=x;
cout<<"Enter for "<<y;
cin>>t;
}

int rety()
{
return y;
}

int rett()
{
return t;
}

void all()
{
cout<<y<<"\t"<<t;
}
};
void showyr()
{
fstream file;
file.open("data.xyz",ios::binary|ios::in);
Year object;
for(int i=2001;i<=2100;i++)
{
file.read((char*)&object,sizeof(object));
object.all();
cout<<"\n";
}
getch();
}





//Class M *******************************************************************************************************************
class mon
{
char cd;
int m,n;

public:

void input(char x,int mn)
{
cd=x;
m=mn;
cout<<"Enter code for "<<cd<<" month : "<<m<<" ";
cin>>n;
}

int retm()
{
return m;
}

int retn()
{
return n;
}

char retcd()
{
return cd;
}

void all()
{
cout<<n<<"   ";
}
};







void showmn()
{
fstream file;
file.open("data2.xyz",ios::binary|ios::in);
mon object;
for(int j=1;j<=14;j++)
{
for(int i=1;i<=12;i++)
{
file.read((char*)&object,sizeof(object));
object.all();
}
cout<<"\n";
}
getch();
}




//Data Extraction*****************************************************

char year_ext(int x)
{
fstream file;
file.open("data.xyz",ios::binary|ios::in);
Year object;
while(file.read((char*)&object,sizeof(object)))
{
if(object.rety()==x)
return object.rett();
}
}


int mon_ext(char x,int y)
{
fstream file;
file.open("data2.xyz",ios::binary|ios::in);
mon object;
while(file.read((char*)&object,sizeof(object)))
{
if(object.retcd()==x&&object.retm()==y)
return object.retn();
}
}


//Number of days*******************************************************
int nod(int y,int m)
{
if(m%2!=2)
return 31;
else if(m!=2)
return 30;
else
{
if(y%4==0||y%100==0&&y%400==0)
return 29;
else
return 28;
}
}


//MAIN-----------------------------
void main()
{

char t;
do
{
clrscr();
cout<<"Choose a Command to Initiate Process : \n\n\n1. View a Specific Month\n\n2. View Year Chart\n\n3. View Month Chart";
t=getch();

clrscr();
if(t=='1')
{
char p;
clrscr();
int year,month;
cout<<"Enter Year (2001-2100) ";
cin>>year;
cout<<"Enter Month (1-12) ";
cin>>month;
clrscr();
prt(mon_ext(year_ext(year),month),nod(year,month));
getch();
clrscr();
}

else if(t=='2')
showyr();

else if(t=='3')
showmn();

else
{
cout<<"error re-enter value";
getch();
}
clrscr();
cout<<"press x to exit";
t=getch();
}while(t!='x');
}









