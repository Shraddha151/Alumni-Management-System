#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class employee
{
	private:
		char name[20];
		char usn[10];
		int age;
		int year;
		char des[10];
		char comp[20];
	public:
	
		void menu();
		void insert();
		void edit();
		void del();
		void list();
		void enquiry();
};
void employee::menu()
{
	system("COLOR 1F");
	employee e;
	while(1)
	{
	system("cls");
	
	cout<<"\n		1 	 To add an Alumni details";
	cout<<"\n		2	 To see list of Alumni details";
	cout<<"\n		3	 To edit an Alumni details";
	cout<<"\n		4	 To remove an Alumni details from list";
	cout<<"\n		5	 To search details of an Alumni";
	cout<<"\n		0	 To exit	";
	cout<<"\n\n\n\n		Choose your option 	:	";
	int ab;
	cin>>ab;

		switch(ab)
		{
			case 1:
				e.insert();
				break;
			case 2:
				e.list();
				break;
			case 3:
				e.edit();
				break;
			case 4:
				e.del();
				break;
			case 5:
				e.enquiry();
				break;
			case 0:
				return ;
			default:
				cout<<"Invalid Option";
				break;
		}
	}
}
void employee::insert()
{
	system("cls");
	FILE *fa;
	char ch;
	employee e;
	system("cls");
	system("COLOR 2F");
	
	cout<<"\n	Enter name of Alumni			:	";
	cin>>e.name;
	
	cout<<"\n	Enter USN of Alumni			:	";
	cin>>e.usn;
	
	cout<<"\n	Enter age of Alumni			:	";
	cin>>e.age;
	
	cout<<"\n	Enter Graduated year of Alumni		:	";
	cin>>e.year;
	
	cout<<"\n Enter the company name Alumni working on : ";
	cin>>e.comp;

	cout<<"\n	Enter designation of Alumni		:	";
	cin>>e.des;

	
	

	
	cout<<"\n	Do you wish to save the above details(y/n)	:	";
	cin>>ch;
	if(ch=='y')
	{
		fa=fopen("details.txt","a");
		fprintf(fa,"%s %s %d %d %s %s \n",e.name,e.usn,e.age,e.year,e.comp,e.des);
		fclose(fa);
	}
	else
		insert();
		cout<<"Details Saved";
}
void employee::list()
{
	system("cls");
	system("COLOR 3F");
	FILE *fb;
	fb=fopen("details.txt","r");
	employee e;
	cout<<"\n\n  name	\t\t	usn	\t\t	designation	\t\t	age	  \t\t  	Grad.Year	\t\t\t  	Company Working on   \t\t\t   Designation   \t\t \n";
	while(fscanf(fb,"%s %s  %d  %d  %s %s \n",e.name,e.usn,&e.age,&e.year,e.comp,e.des)!=EOF)
	{	
		cout<<"\n"<<e.name<<"\t\t"<<e.usn<<"\t\t"<<e.age<<"\t\t"<<e.year<<"\t\t\t"<<e.comp<<"\t\t\t"<<e.des;
	}
	fclose(fb);
			getch();
}

void employee::edit()
{
	system("COLOR 4F");
	system("cls");
	FILE *fc,*fd;

	employee e;
	char cusn[5];
	cout<<"Enter USN 	:	";
	cin>>cusn;
	char id[5],desg[10];
	cout<<"Enter new usn 	:	";
	cin>>id;
	cout<<"Enter new designation 	:	";
	cin>>desg;
	fc=fopen("details.txt","r");
	fd=fopen("temp.txt","w");
	while(fscanf(fc,"%s %s %d %d %s %s \n",e.name,e.usn,&e.age,&e.year,e.comp,e.des)!=EOF)
	{
		if(strcmp(cusn,e.usn)==0)
		{
			fprintf(fd,"%s %s %d %d %s %s \n",e.name,id,e.age,e.year,e.comp,e.des);
		}
		else
		{
			fprintf(fd,"%s %s %d %d %s %s \n",e.name,e.usn,e.age,e.year,e.comp,e.des);
		}
	}
	char s[]="details.txt";
	char t[]="temp.txt";
	
	fclose(fc);
	fclose(fd);	
	
	int a = remove(s);
	int b = rename(t,s);
			getch();
}
void employee::enquiry()
{
	
	system("cls");
	system("COLOR 6F");
	FILE *fe;

	employee e;
	char cusn[5];
	cout<<"Enter usn ";
	cin>>cusn;
	fe=fopen("details.txt","r");
	while(fscanf(fe,"%s %s %d %d %s %s \n",e.name,e.usn,&e.age,&e.year,e.comp,e.des)!=EOF)
	{
		if(strcmp(cusn,e.usn)==0)
		{
			cout<<"\n NAME \t\t		USN   \t\t	AGE	 \t\t	Graduated On	\t\t	Company Working ON	\t\t	DESIGNATION";
			cout<<"\n"<<e.name<<"\t\t"<<e.usn<<"\t\t"<<e.age<<"\t\t"<<e.year<<"\t\t"<<e.comp<<"\t\t\t"<<e.des;
		}
	}
	fclose(fe);
			getch();
}
void employee::del()
{
	system("cls");
	FILE *ff,*fg;

	employee e;
	char cusn[10];
	cout<<"Enter usn ";
	cin>>cusn;
	ff=fopen("details.txt","r");
	fg=fopen("temp.txt","w");
	while(fscanf(ff,"%s %s %d %d %s %s \n",e.name,e.usn,&e.age,&e.year,e.comp,e.des)!=EOF)
	{
		if(strcmp(cusn,e.usn)!=0)
		{
			fprintf(fg,"%s %s %d %d %s %s \n",e.name,e.usn,e.age,e.year,e.comp,e.des);
		}
	}
	char s[]="details.txt";
	char t[]="temp.txt";
	
	fclose(ff);
	fclose(fg);	
	
	int a = remove(s);
	int b = rename(t,s);
			getch();
}


int main()
{
	int a;
	employee e;
	e.menu();
			
	return 0;
}
