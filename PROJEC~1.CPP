#include "iostream.h"
#include "conio.h"
#include "stdio.h"
#include <string.h>


#define MAX_NAME_LEN 20

int isExist(int);
void deleteEmp(int);
class Employee{
	private:
		int static count;
		int code;
		char name[MAX_NAME_LEN];
		int id;
		float bouns;
		float salary;
		float tax;
		float netSalary;
	public:
		Employee(){
		   id = NULL;

		}
		char *getName(){
			return name;
		}
		int read(){
			int n;
			gotoxy(28,11);
			cout<<"Enter employee ID (unique) : ";
			cin>>id;
			if(isExist(id)){
				return 0;
			}
			gotoxy(28,12);
            flushall();
			cout<<"Enter employee name : ";
		   // cin.getline(name,10);
           	gets(name);
			gotoxy(28,13);
			cout<<"Enter employee salary : ";
			cin>>salary;
			gotoxy(28,14);
			cout<<"Enter employee bouns : ";
			cin>>bouns;
			gotoxy(28,15);
			cout<<"Enter employee tax: ";
			cin>>tax;
			netSalary = salary + bouns - tax;
			code = ++count;
			return 1;

		}
		void write(){
			gotoxy(28,11);
			cout<<"Employee count : "<<this->code;
			gotoxy(28,12);
			cout<<"Employee ID (unique) : "<<this->id;
			gotoxy(28,13);
			cout<<"Employee name : "<<this->name;
			gotoxy(28,14);
			cout<<"Employee net salary : "<<this->netSalary;

		}
		int getId(){
			return id;
		}
		void static delEmp(){
			count--;

		}
		int static getNumOfEmp(){
			return count;
		}
		~Employee(){
			//code--;
		}


};


int Employee::count=0;
Employee *e;
int numOfEmp;
void menu();
int *searchEmp(char[]);
void arrow(int,int);
void printSquare();


int main(){
	clrscr();
	cout<<"\nEnter number of employees : ";
	cin>>numOfEmp;
	e = new Employee[numOfEmp];
	menu();




	//getch();
	return 0;
}

void menu(){
	int size = Employee::getNumOfEmp();
	int key=0;
	int postion=1;
	int maxPos=5;
	//et[0] = &e[0];
	while(key !=13){
		clrscr();
		printSquare();
		gotoxy(29,7);
		cout<<"--Employess System--";
		gotoxy(30,10);
		cout<<"you have added "<<size<<" employees";
		gotoxy(35,11);
		arrow(1,postion);
		cprintf("1.New Employee");
		gotoxy(35,12);
		arrow(2,postion);
		cprintf("2.Display Employees\n");
		gotoxy(35,13);
		arrow(3,postion);
		cprintf("3.Delete Employee\n");
		gotoxy(35,14);
		arrow(4,postion);
		cprintf("4.Search for Employee");
		gotoxy(35,15);
		arrow(5,postion);
		cprintf("5.End");
		key=getch();
		if(key==80 && postion!=maxPos)
			postion++;
		else if (key==72 && postion!=1)
			postion--;
		else if(key==49){
			postion=1;
			key=13;
			}
		else if(key==50){
			postion=2;
			key=13;
		}
		else if(key==51){
			postion=3;
			key=13;
		}
		else
			postion=postion;
	}
	clrscr();
	gotoxy(35,12);
	if(postion==1)
	{
		clrscr();
		if(size<numOfEmp){
			printSquare();
			if(e[size].read()){
				size++;
			}
			else{
				gotoxy(28,12);
				cprintf("This Employee Already Exist !!");
				getch();
				}
			menu();
		}
		else{
			gotoxy(20,12);
			cout<<"You have been added all available employess maximum : "<<numOfEmp;
			gotoxy(35,13);
			cout<<"press any key to end";
			getch();
			menu();
		}

	}
	else if(postion==2)
	{
		printSquare();
		if(size==0){
			gotoxy(28,13);
			cout<<"No Employee yet !";
			getch();
			menu();
		}
		printSquare();
		gotoxy(75,21);
		cout<<"-->";
		gotoxy(69,21);
		cout<<"<--";
		int empNum=0;
		gotoxy(73,21);
		cout<<empNum+1;
		e[empNum].write();
		int ch=0;
		ch = getch();
		while(1){
			ch = getch();
			if (ch==27 || ch==13){
				break;
			}
			else if (ch==77 && empNum<size-1){
				empNum+=1;
				clrscr();
				printSquare();
				gotoxy(75,21);
				cout<<"-->";
				gotoxy(69,21);
				cout<<"<--";
				gotoxy(73,21);
				e[empNum].write();
				gotoxy(73,21);
				cout<<empNum+1;

			}
			else if (ch==75 && empNum>0){
				empNum-=1;
				clrscr();
				printSquare();
				gotoxy(75,21);
				cout<<"-->";
				gotoxy(69,21);
				cout<<"<--";
				gotoxy(73,21);
				e[empNum].write();
				gotoxy(73,21);
				cout<<empNum+1;
			}
			else{
				empNum = 0;
				clrscr();
				printSquare();
				gotoxy(75,21);
				cout<<"-->";
				gotoxy(69,21);
				cout<<"<--";
				gotoxy(73,21);
				e[empNum].write();
				gotoxy(73,21);
				cout<<empNum+1;
			}
			getch();
		}
	   //getch();
	   menu();
	   }
	   else if(postion==3){
			clrscr();
			printSquare();
			int id;
			gotoxy(28,13);
			cout<<"Enter Employee ID to delete : ";
			cin>>id;
			deleteEmp(id);
			menu();

	   }
	   else if (postion==4){
			char na[MAX_NAME_LEN];
			clrscr();
			printSquare();
			gotoxy(22,13);
			cout<<"Enter Employee name to find : ";
			gets(na);
			int *p = searchEmp(na);
			int i=0;
			/*for(i=0;i<5;i++){
				cout<<p[i]<<endl;
				getch();
			} */
			for(i=0;p[i]!=-1;i++){
					clrscr();
					printSquare();
					//cout<<p[i];
					e[p[i]].write();
					getch();
					//i++;
			}
			if(i==0){
				gotoxy(28,14);
				cout<<"Not Found";
			}
			getch();
			menu();

	   }

}
void arrow(int realPos , int arrowPos){
	if(realPos == arrowPos){
		textcolor(2);
		cprintf("--> -");
	}
	else{
		textcolor(WHITE);
		cprintf("     ");

	}
}

void printSquare(){
	int i=-1;
	int j=-8;
	clrscr();
	textcolor(WHITE);
	clrscr();
	for(i=0;i<7;i++){
		gotoxy(26+j,10+i);
		cout<<"*";
		gotoxy(76+j,10+i);
		cout<<"*";
	}
	for(i=0;i<51;i++){
		gotoxy(18+i,9);
		cout<<"*";
		gotoxy(18+i,17);
		cout<<"*";

	}


}

int isExist(int id){
	for(int i=0;i<Employee::getNumOfEmp();i++){
		if(e[i].getId()==id)
			return 1;
	}
	return 0;

}
void deleteEmp(int id){
		int i;
		for(i=0;i<Employee::getNumOfEmp();i++){
			if(e[i].getId()==id){
				for(int j=i;j<Employee::getNumOfEmp()-1;j++)
					e[j] = e[j+1];
				Employee::delEmp();
				return;
			}
		}
		gotoxy(28,15);
		cout<<"Not Exist ";
		getch();
		return;

}
int *searchEmp(char ch[]){
	static int result[50];
	int j=0;
	for(int w=0;w<50;w++){
		result[w]=-1;
	}
	for(int k=0;k<Employee::getNumOfEmp();k++){
		if(strstr(e[k].getName(),ch)!=0){
			result[j]=k;
			j++;
		}


	}
	return result;


}

/*int *searchEmp(char ch[]){
	int bool=0,i=0,j=0;
	static int result[50];
	for(int w=0;w<50;w++){
		result[w]=-1;
	}
	for(int k=0;k<Employee::getNumOfEmp();k++){
		i=0;
		bool=0;
		while(ch[i]!='\0'){
			if(ch[i] != e[k].getName()[i]){
				bool=0;
				break;
			}
			else{
				bool=1;

			}
			i++;
		}
		if(bool){
			result[j]=k;
			j++;
			}


	}
	return result;


}*/










