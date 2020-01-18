//***************************************************************
// HEADER FILE USED IN PROJECT
//****************************************************************
#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<ctype.h>
//******************FUNCTION PROTOTYPE****************
void intromain();
int checkpass();
void intro();
void admin_menu();
void write_emp_infor();
char *getemployees();
void display_emp_sp(char n[15]);
void admin_menu1();
void emp_tabular();
void display_all_emp();
void emp_modify_menu();
void display_emp_sp1(char enm[15]);
 void display_emp_sp2(char enm[15]);
void display_emp_sp3(char enm[15]);
void display_emp_sp4(char enm[15]);
void display_emp_sp5(char enm[15]);
void delete_emp_record(char enm[15]);
void admin_salary();
int getsalid();
void write_emp_salary(char eid[5]);
void display_sal_allmonthyear(char mm[5],int yy);
void display_sal_slip(char eid[5],char month[5]);
void display_sal_slip(char eid[5],char month[5]);
 void showSalaryheadings(int c);
 void show_salary_modify_menu();
 void modify_sal_emp(char num[5],char mm[5],int yy);
 void modify_HRA_DA_emp(char num[5],char mm[5],int yy);
 void modify_BONUS_emp(char num[5],char mm[5],int yy);
 void modify_OTHER_emp(char num[5],char mm[5],int yy);
 void modify_pf_emp(char num[5],char mm[5],int yy);
 void admin_leave(char num[5]);
 void emp_LEAVE_menu();
 int getleavestatus(char eid[5]);
 void set_leave(char eid[5]);
 void displayall_leave();
 void gen_report(char num[5],int yy);
 //******************FUNCTION PROTOTYPE****************
//*************leave class
class leave
{
 char eid[5];
 char dateofleaveFrom[15];
 char dateofleaveTo[15];
 char desc[80];
 char status;
 public:
 char getstatus()
 { return status; }
 void setstatus()
 { status='n'; }
char *get_leave_eid()
{ return eid; }
char *get_leave_dTFrom()
{ return dateofleaveFrom; }
char *get_leave_desc()
{ return desc; }
char *get_leave_dTTO()
{ return dateofleaveTo; }
void input_leave(int c,char ed[5])
{
strcpy(eid,ed);
 gotoxy(5,c);
 cout<<"DATE OF LEAVE FROM(eg:05/02/1999) : ";cin>>dateofleaveFrom;
 c=c+1;
 gotoxy(5,c);
 cout<<"DATE OF LEAVE TO (eg:05/02/1999) : ";cin>>dateofleaveTo;
 c=c+1;
 gotoxy(5,c);
 cout<<"PURPOSE OF LEAVE: ";
 cin.ignore();
 cin.getline(desc,80);
 status='y';
}
void showsLEAVE_VER(int c)
 {
 gotoxy(5,c);
 cout<<eid<<setw(12)<<dateofleaveFrom<<setw(12)<<dateofleaveTo<<setw(12)<<desc;
 if(status=='y')
 { cout<<setw(15)<<"ON LEAVE";
 }else {cout<<setw(15)<<"BACK ON WORK"; } } };
//*************leave class
//*************class salary****************************
 class emp_salary
 {
 int sal_id;
 char semp_id[5];
 float basicsal,netsal;
 int HRA,DA,otherall;
 int bonus,PFamt;
 //*********date of salary given
 int dd,yy;
 char mm[5];
 public:
 int getyear()
 { return yy; }
 char *getmonth()
 { return mm; }
 int getsalid()
 { return sal_id; }
 float getbasicsal()
 { return basicsal; }
 int getHRA()
 { return HRA; }
 int getDA()
 { return DA; }
 int getother()
 { return otherall; }
 int getbonus()
 { return bonus; }
 char *getsempid()
 { return semp_id; }
 int getPF()
 { return PFamt; }
 void setbasiconly(float bcsal)
 { basicsal=bcsal;
 netsal=basicsal+((basicsal*HRA)/100)+((DA*basicsal)/100)+otherall+bonus-PFamt;
 }
 void setHRADA(int HR,int DA1)
 { HRA=HR;
 DA=DA1;
 netsal=basicsal+((basicsal*HRA)/100)+((DA*basicsal)/100)+otherall+bonus-PFamt;
 }
 void setotherall(int oth)
 { otherall=oth;
 netsal=basicsal+((basicsal*HRA)/100)+((DA*basicsal)/100)+otherall+bonus-PFamt;
 }
 void setbonus(int bns)
 { bonus=bns;
 netsal=basicsal+((basicsal*HRA)/100)+((DA*basicsal)/100)+otherall+bonus-PFamt;
 }
 void setPF(int PF)
 { PFamt=PF;
 netsal=basicsal+((basicsal*HRA)/100)+((DA*basicsal)/100)+otherall+bonus-PFamt;
 }
 void showsalreportMONTHLY()
 { gotoxy(5,13);
 cout<<"**********************EMPLOYEE'S SALARY INFORMATION*******************";
 gotoxy(5,14);
 cout<<"======================================================================";
 gotoxy(5,15);
 cout<<"BASIC SAL: "<<basicsal<<" HRA: "<<((basicsal*HRA)/100)<<" DA: "<<((DA*basicsal)/100);
 gotoxy(5,16);
 cout<<" OTHER ALLOW'S: "<<otherall<<" BONUS : "<<bonus<<" PF : "<<PFamt;
 gotoxy(5,17);
 cout<<" NET SALARY : "<<netsal<<setw(25)<<" SALARY DATE : "<<dd<<"-"<<mm<<"-"<<yy;
 }
 void showsalreportYEARLY(int c)
 { gotoxy(1,c);
 cout<<basicsal<<setw(9)<<((basicsal*HRA)/100)<<setw(6)<<((DA*basicsal)/100)<<" , ";
 cout<<otherall<<setw(10)<<bonus<<setw(7)<<PFamt<<setw(8)<<netsal<<setw(8)<<dd<<"-"<<mm<<"-"<<yy;
 }
 void input_salaryinfo(char empid[5],int id);
 };
//************************input information
void emp_salary::input_salaryinfo(char empid[5],int id)
{
 strcpy(semp_id,empid);
 sal_id=id;
 gotoxy(5,13);
 cout<<"**********************EMPLOYEE'S SALARY INFORMATION*******************";
 gotoxy(5,14);
 cout<<"======================================================================";
 gotoxy(5,15); cout<<"BASIC SAL: ";
 gotoxy(28,15); cin>>basicsal;
 gotoxy(35,15); cout<<" HRA: ";cin>>HRA;
 gotoxy(5,16); cout<<" DA: ";cin>>DA;
 gotoxy(25,16); cout<<" OTHER ALLOW'S: ";
 gotoxy(45,16); cin>>otherall;
 gotoxy(5,17); cout<<" BONUS : ";
 gotoxy(22,17); cin>>bonus;
 gotoxy(35,17); cout<<" PF : ";
 cin>>PFamt; gotoxy(5,18);
 cout<<" SALARY DATE :dd-mm-yy(05-DEC-1999): "; gotoxy(48,18);cin>>dd;
 gotoxy(53,18);cin>>mm; gotoxy(60,18);cin>>yy;
 netsal=basicsal+((basicsal*HRA)/100)+((DA*basicsal)/100)+otherall+bonus-PFamt;
}
//*****************class employee*************************
class employee
{
char emp_id[5];
char ename[35],fname[35];
char address[35],city[25],state[25];
int dd,mm,yy;
char phno[15];char desg[35];char depart[15];
char DOJ[15]; //05-dec-1999
public:
void setdes_dep_doj(char ds[35],char dpt[15],char dj[15])
{ strcpy(desg,ds);
strcpy(depart,dpt);
strcpy(DOJ,dj);
}
void set_phone(char ph[15])
{ strcpy(phno,ph);}
void set_address(char tadd[35],char tmpct[25],char tmpst[25])
{ strcpy(address,tadd); strcpy(city,tmpct); strcpy(state,tmpst);}
void set_father_name(char fnm[35])
{ strcpy(fname,fnm);}
void set_name(char enm1[35])
{ strcpy(ename,enm1);}
void showempreport()
{ gotoxy(5,6);
 cout<<"**********************EMPLOYEE'S INFORMATION**************************";
 gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(5,8); cout<<"EMP NO: ";
 gotoxy(18,8); cout<<emp_id;
 gotoxy(25,8); cout<<"NAME : ";
 gotoxy(35,8); cout<<ename<<" FATHERS NAME:"<<fname;
 gotoxy(5,9); cout<<"ADDRESS: ";
 cout<<address<<","<<city<<","<<state;
 gotoxy(5,10); cout<<"PHONE NO.: ";
 gotoxy(15,10); cout<<phno;
 gotoxy(35,10); cout<<"DESIGNATION:";
 gotoxy(48,10); cout<<desg;
 gotoxy(5,11); cout<<"DEPARTMENT: "<<depart<<" Date Of Joining:"<<DOJ;
 gotoxy(5,12); cout<<"=====================================================================";
}
char *getempid()
{return emp_id;}
char *getempnm()
{ return ename;}
char *getempadd()
{ return address;}
char *getphno()
{ return phno;}
char *getdesg()
{ return desg;}
void show_emp()
{ gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(10,8); cout<<"EMP NO:";
 gotoxy(25,8); cout<<emp_id;
 gotoxy(35,8); cout<<"NAME OF EMP:";
 gotoxy(54,8); cout<<ename;
 gotoxy(10,9); cout<<"ADDRESS:";
 gotoxy(25,9); cout<<address;
 gotoxy(10,10); cout<<"PHONE NO.:";
 gotoxy(25,10); cout<<phno;
 gotoxy(10,12); cout<<"DESIGNATION:";
 gotoxy(25,12); cout<<desg;
 gotoxy(5,14); cout<<"=====================================================================";
}
void showallemp(int c)
{
gotoxy(1,c);
cout<<emp_id<<setw(17)<<ename<<setw(8)<<address<<","<<city<<setw(15)<<phno<<setw(15)<<desg;
}
void showempdatamulti()
{
 gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(5,8); cout<<"EMP NO: ";
 gotoxy(17,8); cout<<emp_id;
 gotoxy(25,8); cout<<"NAME : ";
 gotoxy(30,8); cout<<ename<<" FATHERS NAME: "<<fname;
 gotoxy(5,9); cout<<"ADDRESS: ";
 gotoxy(25,9); cout<<address<<" ,"<<city<<" , "<<state;
 gotoxy(5,10); cout<<" PHONE NO.: ";
 gotoxy(30,10); cout<<phno;
 gotoxy(5,11); cout<<"DESIGNATION:";
 gotoxy(25,11); cout<<desg;
 cout<<" DEPARTMENT: "<<depart<<" DOJ :"<<DOJ;
 gotoxy(5,12); cout<<"=====================================================================";
}
void emp_input(char eid[15]);
};
//*******************input employee details ***************
void employee::emp_input(char eid[15])
{ char ch;
 int choice=0;
 gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(10,8); cout<<"Last Empno no:"<<eid<<" EMP NO: ";
 gotoxy(55,8); cin>>emp_id;
 gotoxy(8,9); cout<<"NAME OF EMP:";
 gotoxy(25,9); cin.ignore();
 cin.getline(ename,35); gotoxy(8,10);
 cout<<"DATE OF BIRTH:(dd/mm/yyyy)";
 gotoxy(35,10); cin>>dd; gotoxy(38,10);
 cin>>mm; gotoxy(45,10); cin.ignore();
 cin>>yy; gotoxy(5,11); cout<<"FATHERS NAME:";
 gotoxy(25,11); cin.ignore(); cin.getline(fname,35);
 gotoxy(5,12); cout<<"ADDRESS1:";
 gotoxy(15,12); cin.clear();
 cin.getline(address,35); gotoxy(45,12);
 cout<<"CITY:"; gotoxy(55,12);
 cin.clear(); cin.getline(city,25);
 gotoxy(8,13); cout<<"STATE:";
 gotoxy(18,13);cin.clear();
 cin.getline(state,25); gotoxy(8,14);
 cout<<"PHONE NO.:"; gotoxy(20,14);
 cin>>phno; gotoxy(5,15);
 cout<<"DESIGNATION(M for manager,A for asst-manager,S for superwiser,W for worker:";
 gotoxy(6,16); cin>>ch;
 switch(ch)
 {
 case 'M':strcpy(desg,"MANAGER");
 break;
 case 'A':strcpy(desg,"ASST-MANAGER");
 break;
 case 'S':strcpy(desg,"SUPERWISER");
 break;
 default:
strcpy(desg,"WORKER");
 }
 gotoxy(10,17);
 cout<<"DEPARTMENT:(1.SALES 2.FINANCE 3.PRODUCTION 4.ACCOUNTS 5. DISTRIBUTION";
 gotoxy(10,18);
 cin>>choice;
 switch(choice)
 {
case 1: strcpy(depart,"SALES"); break;
case 2: strcpy(depart,"FINANCE"); break;
case 3: strcpy(depart,"PRODUCTION"); break;
case 4: strcpy(depart,"ACCOUNTS"); break;
case 5: strcpy(depart,"DISTRIBUTION"); break;
 }
 gotoxy(10,19);
 cout<<"DATE OF JOINING:(EX:02-dec-2012) :";
 cin>>DOJ; gotoxy(5,20);
 cout<<"=====================================================================";
}
//*******************input employee details ***************
//*****************class employee*********************
//****************employee write function inot file emp.dat****************
void write_emp_infor()
{
 ofstream objoff;
 employee eobj;
 char r[15];
 strcpy(r,getemployees());
 objoff.open("employee.dat",ios::app);
 clrscr();
 intromain();
 if(strcmp(r,"NOVALUE")==0)
 { eobj.emp_input("first rec LIKE : E001");
 }else { eobj.emp_input(r); }
 objoff.write((char*)&eobj,sizeof(employee));
 objoff.close(); gotoxy(10,20);
 cout<<"***************CUSTOMER RECORD SAVED******************* ";
 cin.ignore(); getch();
}
//************get last record empno number*******************
char *getemployees()
{
ifstream objiff;
employee cust;
int count=0;
char *rt="NOVALUE";
int flag=-1;
objiff.open("employee.dat",ios::binary);
objiff.seekg(0,ios::beg);
if(!objiff)
{
cout<<"File could not be open !! Press any Key...";
flag=-1;
getch();
}
//**************temporary hiding these lines
while(objiff.read((char *) &cust, sizeof(employee)))
{ count++; flag=1; }
//***********jump to the last line
if(flag==1)
{
objiff.seekg(count-sizeof(cust),ios::beg);
objiff.read((char *) &cust, sizeof(employee));
strcpy(rt,cust.getempid());
}
return(rt);
}
//************get last record empno number*******************
//***************************************************************
// function to read specific record from file
//****************************************************************
void display_emp_sp(char n[15])
{
 ifstream objfp;
 employee cust;
 int flag=0;
 objfp.open("employee.dat",ios::binary);
 if(!objfp)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
 while(objfp.read((char*)&cust,sizeof(employee)))
{
 if(strcmpi(cust.getempid(),n)==0)
{
 clrscr();
 intromain();
 cust.showempreport();
 flag=1;
}
}
 objfp.close();
if(flag==0)
cout<<"\n\nrecord not exist";
getch();
}
//**********************employee record sepecific*******************************
//******************************************************************************
// DISPLAY ALL THE CUSTOMER TABULAR FORM
//******************************************************************************
void emp_tabular()
{
 int r=0,col=10;
employee cust;
ifstream inFile;
inFile.open("employee.dat",ios::binary);
if(!inFile)
{ cout<<"File could not be open !! Press any Key...";
getch();
return;
}display_all_emp();
while(inFile.read((char *) &cust, sizeof(employee)))
{
 if(r<=12)
 {
 r++;
 cust.showallemp(col);
 col++;
 }else
 {
 gotoxy(20,30);
 cout<<"--------------press any key------------------------";
 getch();
 clrscr();
 display_all_emp();
 col=10;
 r=0;
}
}
inFile.close();
getch();
}
//**************************tabular forms ends**********************************
//function to display all the records of salary
//**********************************************************************
void display_all_emp()
{
clrscr();
intromain();
gotoxy(1,5);
cout<<" **********************EMPLOYEES DETAILS***************************";
gotoxy(1,6);
cout<<"================================================================================";
gotoxy(1,7);
cout<<"CUST.NO"<<setw(10)<<"NAME"<<setw(15)<<"ADDRESS"<<setw(25)<<"PHONE
NO"<<setw(15)<<"DESIGNATION";
gotoxy(1,8);
cout<<"================================================================================";
}
//*********************DISPLAY ALL ENDS HERE***************************
//****************employee write function inot file emp.dat****************
//***************************************************************
// THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{
 char ch;
 intro();
 char num[5];
 int yy;
if(checkpass()==0)
{
 do
 {
 //****************TEMPORARY***********************
clrscr();
intromain();
gotoxy(20,6);
cout<<"=================MAIN MENU====================";
gotoxy(28,7);
cout<<"01. PAYROLL REPORT GENERATOR";
gotoxy(28,8);
cout<<"02. ADMINISTRATOR";
gotoxy(28,9);
cout<<"03. EXIT";
gotoxy(20,10);
cout<<"==============================================";
gotoxy(25,12);
cout<<"Please Select Your Option (1-3) ";
gotoxy(30,14);
ch=getche();
 switch(ch)
 {
 case '1': clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:: ";
cin>>num;
gotoxy(10,9);
cout<<"*****ENTER YEAR (eg:2012) TO BE SEARCHED:";
cin>>yy;
gen_report(num,yy);
getch();
break;
 case '2': admin_menu();
 break;
 case '3':
 exit(0);
 default :cout<<"\a";
}
 }while(ch!='3');
}else{exit(0);}}
//***************************************************************
// THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void intromain()
{ clrscr();
gotoxy(1,2);
cout<<"*************************PAYROLL****MANAGEMENT******SYSTEM********************";
gotoxy(1,3);
cout<<"******************************************************************************";
}
//***************main intro
//******************************login name and password****************
int checkpass()
{
 char nm[20];
 char pass[10];
 clrscr();
 intromain();
 gotoxy(20,20);
 cout<<"PLEASE ENTER THE USER NAME:";
 gotoxy(20,21);
 cin>>nm;
 clrscr();
 gotoxy(20,20);
 cout<<"PLEASE ENTER THE PASSWORD:";
 gotoxy(20,21);
 cin>>pass;
 if(strcmpi(nm,"admin")==0 && strcmpi(pass,"vicky")==0)
 { return 0; }else { return 1; }
}
//********************************************************************
//***************************************************************
// INTRODUCTION FUNCTION
//****************************************************************
void intro()
{ clrscr();
gotoxy(4,2);
cout<<"****************************PAYROLL MANAGEMENT**************************";
gotoxy(12,4);
cout<<"===========================================================";
gotoxy(5,5);
cout<<"****************************S=Y=S=T=E=M********************************";
gotoxy(50,10);
cout<<"PROJECT:";
gotoxy(50,12);
cout<<"MADE BY : --------------------";
gotoxy(10,14);
cout<<"---------------CLASS : XII A--------------------";
getch();
}
//***************************************************************
// ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
 clrscr();
 char ch2;
 //************************************************************
 clrscr();
intromain();
gotoxy(20,6);
cout<<"=================ADMIN MENU====================";
gotoxy(22,7);
cout<<"1.EMPLOYEE DETAILS";gotoxy(22,8);
cout<<"2.GRADE / SALARY DETAILS"; gotoxy(22,9);
cout<<"3.LEAVE DETAILS"; gotoxy(22,10);
cout<<"4.BACK TO MAIN MENU"; gotoxy(22,11);
cout<<"Please Enter Your Choice (1-8) "; gotoxy(22,12);
 //**********************************************************
 ch2=getche();
 switch(ch2)
 {
 case '1': clrscr();admin_menu1(); break;
 case '2':clrscr();admin_salary(); break;
 case '3': clrscr(); intromain();emp_LEAVE_menu(); break;
 default: cout<<"\a";//admin_menu();
}
}
//***************************************************************
void admin_menu1()
{
 clrscr();
 char ch2;
char num[15];
 //************************************************************
 clrscr();
intromain();
gotoxy(20,6);
cout<<"============EMPLOYEES MENU====================";
gotoxy(22,7);
cout<<"1.CREATE EMPLOYEE DETAILS";
gotoxy(22,8);
cout<<"2.DISPLAY ALL EMPLOYEE'S DETAILS";
gotoxy(22,9);
cout<<"3.SEARCH RECORD(QUERY) ";
gotoxy(22,10);
cout<<"4.MODIFY EMPLOYEE RECORDS";
gotoxy(22,11);
cout<<"5.DELETE EMPLOYEE RECORDS";
gotoxy(22,12);
cout<<"6.BACK TO MAIN MENU";
gotoxy(18,13);
cout<<"Please Enter Your Choice (1-6) ";
gotoxy(55,13);
 //**********************************************************
 ch2=getche();
 switch(ch2)
 {
 case '1': clrscr();
write_emp_infor();
break;
 case '2': emp_tabular();
 break;
 case '3':
 //********************
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
display_emp_sp(num);
 break;
case '4':
clrscr();
emp_modify_menu();
 break;
case '5':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED AND TO DELETE:";
gotoxy(55,9);
cin>>num;
delete_emp_record(num);
break;
case '6': break;
default:cout<<"\a";admin_menu1();
}
}
//*****************Employee Modify menu
void emp_modify_menu()
{
 clrscr();
 char ch2;
char num[15];
 //************************************************************
 clrscr();
intromain();
gotoxy(20,6);
cout<<"============EMPLOYEES MODIFY MENU====================";
gotoxy(22,7);
cout<<"1.SEARCH AND MODIFY NAME";
gotoxy(22,8);
cout<<"2.SEARCH AND MODIFY FATHERS NAME";
gotoxy(22,9);
cout<<"3.SEARCH AND MODIFY ADDRESS";
gotoxy(22,10);
cout<<"4.SEARCH AND MODIFY PHONE NUMBER";
gotoxy(22,11);
cout<<"5.SEARCH AND MODIFY DEPARTMENT,DESIGNATION AND DATE OF JOINING";
gotoxy(22,12);
cout<<"6.BACK TO MAIN MENU";
gotoxy(18,13);
cout<<"Please Enter Your Choice (1-6) ";
gotoxy(55,13);
 //**********************************************************
 ch2=getche();
 switch(ch2)
 {
 case '1':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
display_emp_sp1(num);
break;
 case '2': clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
display_emp_sp2(num);
 break;
 case '3':
 //********************
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
display_emp_sp3(num);
 break;
case '4':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED AND MODIFY:";
gotoxy(55,9);
cin>>num;
display_emp_sp4(num);
 break;
case '5':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
display_emp_sp5(num);
break;
case '6': break;
default:cout<<"\a";admin_menu1();
}
}
//*****************Emp modify Name of employee
void display_emp_sp1(char enm[15])
{
 employee cust;
char tmpnm[35];
ifstream inFile;
int fpos1=-1;
inFile.open("employee.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ clrscr();
 intromain();
 cust.showempdatamulti();
 flag=1;
}
}
inFile.close();
if(flag==0)
 { cout<<"\n\nrecord not exist";}
else
{
//*******modifying the records starts here
fstream File;
File.open("employee.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
while(File.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ fpos1=(int)File.tellg();
 break;
}
 }
File.seekp(fpos1-sizeof(employee),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
gotoxy(5,14);
cout<<"\nEnter the Name :";
cin.ignore();
cin.getline(tmpnm,35);
cust.set_name(tmpnm);
File.write((char *) &cust, sizeof(employee));
File.close();
}
}
//**************************modify the fathers name
 //*****************Emp modify Name of employee
void display_emp_sp2(char enm[15])
{
 employee cust;
char tmpnm[35];
ifstream inFile;
int fpos1=-1;
inFile.open("employee.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ clrscr();
 intromain();
 cust.showempdatamulti();
 flag=1;
}
}
inFile.close();
if(flag==0)
 { cout<<"\n\nrecord not exist";}
else
{
//*******modifying the records starts here
fstream File;
File.open("employee.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
while(File.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ fpos1=(int)File.tellg();
 break;
}
 }
File.seekp(fpos1-sizeof(employee),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
gotoxy(5,14);
cout<<"\nEnter the Fathers Name :";
cin.ignore();
cin.getline(tmpnm,35);
cust.set_father_name(tmpnm);
File.write((char *) &cust, sizeof(employee));
File.close();
}
}
//**************************modify the fathers name
//*****************Emp modify address
void display_emp_sp3(char enm[15])
{
 employee cust;
char tmpadd[35],tmpcity[15],tmpstate[25];
ifstream inFile;
int fpos1=-1;
inFile.open("employee.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ clrscr();
 intromain();
 cust.showempdatamulti();
 flag=1;
}
}
inFile.close();
if(flag==0)
 { cout<<"\n\nrecord not exist";}
else
{
//*******modifying the records starts here
fstream File;
File.open("employee.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
while(File.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ fpos1=(int)File.tellg();
 break;
}
 }
File.seekp(fpos1-sizeof(employee),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
gotoxy(5,14);
cout<<"\nEnter the ADDRESS :";
cin.ignore();
cin.getline(tmpadd,35);
gotoxy(5,15);
cout<<"\nEnter the CITY :";
cin.clear();
//cin.ignore();
cin.getline(tmpcity,15);
gotoxy(5,16);
cout<<"\nEnter the STATE :";
cin.clear();
//cin.ignore();
cin.getline(tmpstate,25);
cust.set_address(tmpadd,tmpcity,tmpstate);
File.write((char *) &cust, sizeof(employee));
File.close();
}
}
//**************************modify the address
 //*****************Emp modify phone number
void display_emp_sp4(char enm[15])
{
 employee cust;
char tmpph[15];
ifstream inFile;
int fpos1=-1;
inFile.open("employee.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ clrscr();
 intromain();
 cust.showempdatamulti();
 flag=1;
}
}
inFile.close();
if(flag==0)
 { cout<<"\n\nrecord not exist";}
else
{
//*******modifying the records starts here
fstream File;
File.open("employee.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
while(File.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ fpos1=(int)File.tellg();
 break;
}
 }
File.seekp(fpos1-sizeof(employee),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
gotoxy(5,14);
cout<<"Enter the NEW MOBILE NUMBER :";
gotoxy(10,15);
cin>>tmpph;
cust.set_phone(tmpph);
File.write((char *) &cust, sizeof(employee));
File.close();
}
}
//**************************modify the phone number
 //*****************Emp modify Department designation
void display_emp_sp5(char enm[15])
{
 employee cust;
char ds[35],dpt[15],dj[15];
ifstream inFile;
int fpos1=-1;
inFile.open("employee.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ clrscr();
 intromain();
 cust.showempdatamulti();
 flag=1;
}
}
inFile.close();
if(flag==0)
 { cout<<"\n\nrecord not exist";}
else
{
//*******modifying the records starts here
fstream File;
File.open("employee.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
while(File.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ fpos1=(int)File.tellg();
 break;
}
 }
File.seekp(fpos1-sizeof(employee),ios::beg);
 char ch;
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
gotoxy(5,14);
 cout<<"DESIGNATION(M for manager,A for asst-manager,S for superwiser,W for worker:";
 gotoxy(6,15);
 cin>>ch;
 switch(ch)
 {
 case 'M':strcpy(ds,"MANAGER");
 break;
 case 'A':strcpy(ds,"ASST-MANAGER");
 break;
 case 'S':strcpy(ds,"SUPERWISER");
 break;
 default:
strcpy(ds,"WORKER");
 }
//***************for department****************
 int choice;
 gotoxy(5,16);
 cout<<"DEPARTMENT:(1.SALES 2.FINANCE 3.PRODUCTION 4.ACCOUNTS 5. DISTRIBUTION";
 gotoxy(10,17);
 cin>>choice;
 switch(choice)
 {
case 1: strcpy(dpt,"SALES");
break;
case 2: strcpy(dpt,"FINANCE");
break;
case 3: strcpy(dpt,"PRODUCTION");
break;
case 4: strcpy(dpt,"ACCOUNTS");
break;
case 5: strcpy(dpt,"DISTRIBUTION");
break;
 }
 //******************desgnation
gotoxy(5,19);
cout<<"Enter Date Of Joining:";
gotoxy(5,20);
cin>>dj;
cust.setdes_dep_doj(ds,dpt,dj);
File.write((char *) &cust, sizeof(employee));
File.close();
}
}
//**************************modify the Designation , Department
//*****************************deletion of employee record**************
void delete_emp_record(char enm[15])
{
 employee cust;
 // char ds[35],dpt[15]dj[15];
ifstream inFile;
//int fpos1=-1;
inFile.open("employee.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &cust, sizeof(employee)))
{
if(strcmpi(cust.getempid(),enm)==0)
{ clrscr();
 intromain();
 cust.showempdatamulti();
 flag=1;
}
}
inFile.close();
char ch;
if(flag==0)
cout<<"\n\nrecord not exist";
else
{
//*******deletion of the records starts from here
gotoxy(1,15);
cout<<"*****************************************************************************";
gotoxy(5,16);
cout<<"======DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)========";
gotoxy(2,17);
cin>>ch;
 if (toupper(ch)=='Y')
 {
 ofstream outFile;
 outFile.open("Temp2.dat",ios::binary);
 ifstream objiff("employee.dat",ios::binary);
 objiff.seekg(0,ios::beg);
 while(objiff.read((char *) &cust, sizeof(employee)))
{
 if(strcmpi(cust.getempid(),enm)!=0)
 {
 outFile.write((char *) &cust, sizeof(employee)); }
}
outFile.close();
objiff.close();
remove("employee.dat");
rename("Temp2.dat","employee.dat");
//againopenandclosecust();
gotoxy(30,20);
cout<<"----------------------------Record Deleted----------------------------------";
}
}
getch();
}
//**********************************************************************
//********************salary menu
void admin_salary()
{
clrscr();
 char ch2;
 int yy;
char num[15],month1[5];
 //************************************************************
 clrscr();
intromain();
gotoxy(20,6);
cout<<"============SALARY AND BONUS MENU====================";
gotoxy(22,7);
cout<<"1.MONTHLY SALARY INFORMATION OF EMPLOYEE";
gotoxy(22,8);
cout<<"2.DISPLAY SALARY SLIP OF EMPLOYEE";
gotoxy(22,9);
cout<<"3.DISPLAY SALARY OF ALL EMPLOYEES MONTHWISE EACH YEAR";
gotoxy(22,10);
//cout<<"4.DISPLAY SALARY OF EMPLOYEES YEARWISE";
//gotoxy(22,11);
cout<<"4.MODIFY THE SALARY INFORMATIONS";
gotoxy(22,11);
cout<<"5.DELETE THE SALARY INFORMATIONS";
gotoxy(22,12);
cout<<"6.BACK TO MAIN MENU";
gotoxy(18,13);
cout<<"Please Enter Your Choice (1-6) ";
gotoxy(55,14);
 //**********************************************************
 ch2=getche();
 switch(ch2)
 {
 case '1':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
write_emp_salary(num);
break;
 case '2': clrscr();
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID AND MONTH TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
cin>>month1;
display_sal_slip(num,month1);
 break;
 case '3':
 //********************
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE MONTH AND YEAR TO BE SEARCHED:";
gotoxy(55,9);
cin>>month1;
cin>>yy;
//display_sal_allmonthyear(char mm[5],int yy)
display_sal_allmonthyear(month1,yy);
 break;
case '4':
show_salary_modify_menu();
 break;
case '5':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
display_emp_sp5(num);
break;
case '6': break;
default:cout<<"\a";admin_menu1();
}
}
//*********************salary menu***************************
//************************entry of salary in a file
//****************employee write function inot file emp.dat****************
void write_emp_salary(char eid[5])
{
 ofstream objoff;
 ifstream objiff;
 employee eobj;
 emp_salary salobj;
 int flag=-1;
 objiff.open("employee.dat",ios::binary);
 clrscr();
 intromain();
 int r;
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),eid)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 //strcpy(str1,eobj.getdesg());
 flag=1;
 break;
}
}
 objiff.close();
if(flag==-1)
{ cout<<"\n\nrecord not exist";
getch();
}else
{
 r=getsalid();
 objoff.open("salary.dat",ios::binary|ios::app);
 if(r>=1000) //1000
 {
 r=1; // r=100
 }
 salobj.input_salaryinfo(eid,r);
 objoff.write((char*)&salobj,sizeof(emp_salary));
 gotoxy(10,20);
 cout<<"***************CUSTOMER RECORD SAVED******************* ";
}
 objoff.close();
 cin.ignore();
 getch();
}
//***************get salary number
int getsalid()
{
ifstream objiff;
int count=0;
emp_salary salobj;
objiff.open("salary.dat",ios::binary);
objiff.seekg(0,ios::beg);
if(!objiff)
{
cout<<"File could not be open !! Press any Key...";
getch();
}
//**************temporary hiding these lines
while(objiff.read((char*)&salobj,sizeof(emp_salary)))
{
 count++;
}
//***********jump to the last line
objiff.seekg(count-sizeof(emp_salary),ios::beg);
objiff.read((char *) &salobj, sizeof(emp_salary));
count=salobj.getsalid();
count++;
objiff.close();
return count;
}
//******************get salary number
//***************************entry of salary into file
//******************************************************************************
// DISPLAY ALL THE salary TABULAR FORM
//******************************************************************************
void display_sal_slip(char eid[5],char month[5])
{
 ifstream objiff2;
 ifstream objiff;
 employee eobj;
 emp_salary salobj;
 int flag=-1;
 objiff.open("employee.dat",ios::binary);
 clrscr();
 intromain();
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),eid)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 flag=1;
 break;
}
}
 objiff.close();
if(flag==-1)
{ cout<<"\n\nrecord not exist";
getch();
}else
{
objiff2.open("salary.dat",ios::binary);
while(objiff2.read((char *) &salobj, sizeof(emp_salary)))
{
 if(strcmp(salobj.getsempid(),eid)==0 && strcmpi(salobj.getmonth(),month)==0)
{
 salobj.showsalreportMONTHLY();
 break;
}
}
}
objiff2.close();
 getch();
}
//**************************salary tabular forms ends**********************************
void display_sal_allmonthyear(char mm[5],int yy)
{
int c1=7;
 emp_salary salobj;
ifstream objiff2;
objiff2.open("salary.dat",ios::binary);
 clrscr();
intromain();
showSalaryheadings(c1);
c1++;
while(objiff2.read((char *) &salobj, sizeof(emp_salary)))
{
 if((salobj.getyear()==yy) && strcmpi(salobj.getmonth(),mm)==0)
{
 if(c1<=25)
 {
 salobj.showsalreportYEARLY(c1);
 c1++;
 }else
 {
 clrscr();
 intromain();
 c1=7;
 showSalaryheadings(c1);
 c1++;
 salobj.showsalreportYEARLY(c1);
 c1++;
 } } }
objiff2.close();
 getch();
}
void showSalaryheadings(int c)
 {
gotoxy(1,c);
cout<<"EMPID :"<<"BASICSAL"<<setw(6)<<"HRA"<<setw(5)<<"DA"<<" , OTHER ALLOW"<<setw(7) <<"BONUS"
<<setw(5)<<"PFamt"<<setw(9)<<"NETSAL"<<setw(8)<<"DOJ";
}
//************************modify salary information
void show_salary_modify_menu()
{
clrscr();
 char ch2;
char num[15];
char month1[5];
int yy;
 //************************************************************
 clrscr();
intromain();
gotoxy(20,6);
cout<<"============EMPLOYEES SALARY MODIFY MENU====================";
gotoxy(22,7);
cout<<"1.SEARCH AND MODIFY BASIC SALARY";
gotoxy(22,8);
cout<<"2.SEARCH AND MODIFY HRA AND DA";
gotoxy(22,9);
cout<<"3.SEARCH AND MODIFY BONUS";
gotoxy(22,10);
cout<<"4.SEARCH AND MODIFY OTHER ALLOWANCES";
gotoxy(22,11);
cout<<"5.SEARCH AND MODIFY PROVIDENT FUND AMOUNT";
gotoxy(22,12);
cout<<"6.BACK TO MAIN MENU";
gotoxy(18,13);
cout<<"Please Enter Your Choice (1-6) ";
gotoxy(55,13);
 //**********************************************************
 ch2=getche();
 switch(ch2)
 {
 case '1':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:: ";
cin>>num;
gotoxy(10,9);
cout<<"*****ENTER MONTH (eg:JAN,FEB..) TO BE SEARCHED:";
cin>>month1;
gotoxy(10,10);
cout<<"*****ENTER YEAR (eg:2012) TO BE SEARCHED:";
cin>>yy;
modify_sal_emp(num,month1,yy);
break;
case '2':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:: ";
cin>>num;
gotoxy(10,9);
cout<<"*****ENTER MONTH (eg:JAN,FEB..) TO BE SEARCHED:";
cin>>month1;
gotoxy(10,10);
cout<<"*****ENTER YEAR (eg:2012) TO BE SEARCHED:";
cin>>yy;
modify_HRA_DA_emp(num,month1,yy);
 break;
 case '3':
 //********************
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:: ";
cin>>num;
gotoxy(10,9);
cout<<"*****ENTER MONTH (eg:JAN,FEB..) TO BE SEARCHED:";
cin>>month1;
gotoxy(10,10);
cout<<"*****ENTER YEAR (eg:2012) TO BE SEARCHED:";
cin>>yy;
modify_BONUS_emp(num,month1,yy);
 break;
case '4':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:: ";
cin>>num;
gotoxy(10,9);
cout<<"*****ENTER MONTH (eg:JAN,FEB..) TO BE SEARCHED:";
cin>>month1;
gotoxy(10,10);
cout<<"*****ENTER YEAR (eg:2012) TO BE SEARCHED:";
cin>>yy;
modify_OTHER_emp(num,month1,yy);
 break;
case '5':
clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:: ";
cin>>num;
gotoxy(10,9);
cout<<"*****ENTER MONTH (eg:JAN,FEB..) TO BE SEARCHED:";
cin>>month1;
gotoxy(10,10);
cout<<"*****ENTER YEAR (eg:2012) TO BE SEARCHED:";
cin>>yy;
modify_pf_emp(num,month1,yy);
break;
case '6': break;
default:cout<<"\a";admin_menu1();
}
}
void modify_sal_emp(char num[5],char mm[5],int yy)
{
fstream objiff2;
 ifstream objiff;
 employee eobj;
 emp_salary salobj;
 int flag=-1;
 float tmpbasicsal;
 objiff.open("employee.dat",ios::binary);
 clrscr();
 intromain();
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),num)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 flag=1;
 break;
}
}
 objiff.close();
int fpos1=-1;
if(flag==-1)
{ cout<<"\n\nrecord not exist";
getch();
}else
{
objiff2.open("salary.dat",ios::binary|ios::in|ios::out);
while(objiff2.read((char *) &salobj, sizeof(emp_salary)))
{
 if(strcmp(salobj.getsempid(),num)==0 && strcmpi(salobj.getmonth(),mm)==0 && (salobj.getyear()==yy))
{
 salobj.showsalreportMONTHLY();
 fpos1=(int)objiff2.tellg();
 break;
}
}
objiff2.seekp(fpos1-sizeof(emp_salary),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"===ENTER NEW VALUES FOR BASIC SALARY FOR THE RECORDS GIVEN ABOVE=======";
gotoxy(5,14);
cin>>tmpbasicsal;
 salobj.setbasiconly(tmpbasicsal);
objiff2.write((char *) &salobj, sizeof(emp_salary));
}
objiff2.close();
getch();
}
void modify_HRA_DA_emp(char num[5],char mm[5],int yy)
{
fstream objiff2;
 ifstream objiff;
 employee eobj;
 emp_salary salobj;
 int flag=-1;
 int tmpHRA,tmpDA;
 objiff.open("employee.dat",ios::binary);
 clrscr();
 intromain();
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),num)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 flag=1;
 break;
}
}
 objiff.close();
int fpos1=-1;
if(flag==-1)
{ cout<<"\n\nrecord not exist";
getch();
}else
{
objiff2.open("salary.dat",ios::binary|ios::in|ios::out);
while(objiff2.read((char *) &salobj, sizeof(emp_salary)))
{
 if(strcmp(salobj.getsempid(),num)==0 && strcmpi(salobj.getmonth(),mm)==0 && (salobj.getyear()==yy))
{
 salobj.showsalreportMONTHLY();
 fpos1=(int)objiff2.tellg();
 break;
}
}
objiff2.seekp(fpos1-sizeof(emp_salary),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"===ENTER NEW VALUES FOR HRA and DA FOR THE RECORDS GIVEN ABOVE===";
gotoxy(5,14);
cin>>tmpHRA>>tmpDA;
salobj.setHRADA(tmpHRA,tmpDA);
objiff2.write((char *) &salobj, sizeof(emp_salary));
}
objiff2.close();
getch();
}
void modify_BONUS_emp(char num[5],char mm[5],int yy)
{
fstream objiff2;
 ifstream objiff;
 employee eobj;
 emp_salary salobj;
 int flag=-1;
 int tmpbn;
 objiff.open("employee.dat",ios::binary);
 clrscr();
 intromain();
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),num)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 flag=1;
 break;
}
}
 objiff.close();
int fpos1=-1;
if(flag==-1)
{ cout<<"\n\nrecord not exist";
getch();
}else
{
objiff2.open("salary.dat",ios::binary|ios::in|ios::out);
while(objiff2.read((char *) &salobj, sizeof(emp_salary)))
{
 if(strcmp(salobj.getsempid(),num)==0 && strcmpi(salobj.getmonth(),mm)==0 && (salobj.getyear()==yy))
{
 salobj.showsalreportMONTHLY();
 fpos1=(int)objiff2.tellg();
 break;
}
}
objiff2.seekp(fpos1-sizeof(emp_salary),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"===ENTER NEW VALUES FOR BONUS FOR THE RECORDS GIVEN ABOVE==========";
gotoxy(5,14);
cin>>tmpbn;
salobj.setbonus(tmpbn);
objiff2.write((char *) &salobj, sizeof(emp_salary));
}
objiff2.close();
getch();
}
void modify_OTHER_emp(char num[5],char mm[5],int yy)
{
fstream objiff2;
 ifstream objiff;
 employee eobj;
 emp_salary salobj;
 int flag=-1;
 int tmpOT=0;
 objiff.open("employee.dat",ios::binary);
 clrscr();
 intromain();
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),num)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 flag=1;
 break;
}
}
 objiff.close();
int fpos1=-1;
if(flag==-1)
{ cout<<"\n\nrecord not exist";
getch();
}else
{
objiff2.open("salary.dat",ios::binary|ios::in|ios::out);
while(objiff2.read((char *) &salobj, sizeof(emp_salary)))
{
 if(strcmp(salobj.getsempid(),num)==0 && strcmpi(salobj.getmonth(),mm)==0 && (salobj.getyear()==yy))
{
 salobj.showsalreportMONTHLY();
 fpos1=(int)objiff2.tellg();
 break;
}
}
objiff2.seekp(fpos1-sizeof(emp_salary),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"==ENTER NEW VALUES FOR OTHER ALLOWANCES FOR THE RECORDS GIVEN ABOVE======";
gotoxy(5,14);
cin>>tmpOT;
salobj.setotherall(tmpOT);
objiff2.write((char *) &salobj, sizeof(emp_salary));
}
objiff2.close();
getch();
}
void modify_pf_emp(char num[5],char mm[5],int yy)
{
fstream objiff2;
 ifstream objiff;
 employee eobj;
 emp_salary salobj;
 int flag=-1;
 int tmpPF=0;
 objiff.open("employee.dat",ios::binary);
 clrscr();
 intromain();
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),num)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 flag=1;
 break;
}
}
 objiff.close();
int fpos1=-1;
if(flag==-1)
{ cout<<"\n\nrecord not exist";
getch();
}else
{
objiff2.open("salary.dat",ios::binary|ios::in|ios::out);
while(objiff2.read((char *) &salobj, sizeof(emp_salary)))
{
 if(strcmp(salobj.getsempid(),num)==0 && strcmpi(salobj.getmonth(),mm)==0 && (salobj.getyear()==yy))
{
 salobj.showsalreportMONTHLY();
 fpos1=(int)objiff2.tellg();
 break;
}
}
objiff2.seekp(fpos1-sizeof(emp_salary),ios::beg);
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"==ENTER NEW VALUES FOR PROVIDENT FUND FOR THE RECORDS GIVEN ABOVE========";
gotoxy(5,14);
cin>>tmpPF;
salobj.setPF(tmpPF);
objiff2.write((char *) &salobj, sizeof(emp_salary));
}
objiff2.close();
getch();
}
//************************modify salary information
//***************leave
void admin_leave(char num[5])
{
ofstream objiff2;//("leave.dat",ios::binary|ios::app);
 ifstream objiff;
 employee eobj;
leave leaveobj;
 int flag=-1;
 objiff.open("employee.dat",ios::binary);
 clrscr();
 intromain();
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),num)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 flag=1;
 break;
}
}
 objiff.close();
if(flag==-1)
{
gotoxy(10,25);
cout<<"****************record not exist***********************";
getch();
}else
{ //**********************check status of leave********************
int pos=getleavestatus(num);
//**********************check status of leave********************
 if(pos==0)
 {
 gotoxy(1,14);
 cout<<"*****************************************************************************";
 gotoxy(1,15);
 cout<<"you are on leave or please check your status of leave";
 getch();
 }else
 {
gotoxy(1,14);
cout<<"*****************************************************************************";
objiff2.open("leave.dat",ios::binary|ios::app);
leaveobj.input_leave(15,num);
objiff2.write((char *) &leaveobj, sizeof(leave));
objiff2.close();
}} }
//***********************MENU 1 CUSTOMERS ENDS HERE*************************
int getleavestatus(char eid[5])
{
int flag=1;
ifstream objiff2;
leave leaveobj;
objiff2.open("leave.dat",ios::binary);
objiff2.seekg(0,ios::beg);
if(!objiff2)
{
cout<<"File could not be open !! Press any Key...";
//return flag;
getch();
}
 while(objiff2.read((char*)&leaveobj,sizeof(leave)))
{
 if(leaveobj.getstatus()=='y' && strcmpi(leaveobj.get_leave_eid(),eid)==0)
 {
flag=0;
 }else
 {
 flag=1;
 }
}
 objiff2.close();
 return flag;
}
void emp_LEAVE_menu()
{
 clrscr();
 char ch2;
 char eid[5];
 //************************************************************
 clrscr();
intromain();
gotoxy(20,6);
cout<<"============LEAVE MENU====================";
gotoxy(22,7);
cout<<"1.LEAVE TO THE EMPLOYEE";
gotoxy(22,8);
cout<<"2.STATUS OF THE LEAVE(BACK TO WORK)";
gotoxy(22,9);
cout<<"3.EMPLOYEE LEAVE DETAILS";
gotoxy(22,10);
cout<<"Please Enter Your Choice (1-4) ";
gotoxy(22,11);
 //**********************************************************
 ch2=getche();
 switch(ch2)
 {
 case '1':
 clrscr();
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:: ";
cin>>eid;
 admin_leave(eid);
break;
 case '2':
clrscr();
intromain();
 gotoxy(10,8);
cout<<"*****ENTER THE EMP ID TO BE SEARCHED:: ";
cin>>eid;
set_leave(eid);
 break;
case '3':
clrscr();
intromain();
 displayall_leave();
 break;
 default:cout<<"\a";admin_menu1();
}
}
void set_leave(char eid[5])
{ //int flag=0;
char tmpdate[15];
fstream objiff2;
leave leaveobj;
int fpos1=-1;
objiff2.open("leave.dat",ios::binary|ios::in|ios::out);
objiff2.seekg(0,ios::beg);
if(!objiff2)
{
cout<<"File could not be open !! Press any Key...";
getch();
}
 gotoxy(10,10);
cout<<"*****ENTER THE DATE OF JOINING AFTER LEAVE:: ";
cin>>tmpdate;
 while(objiff2.read((char*)&leaveobj,sizeof(leave)))
{
 if( leaveobj.getstatus()=='y' && strcmpi(leaveobj.get_leave_eid(),eid)==0 &&
strcmpi(leaveobj.get_leave_dTTO(),tmpdate)==0)
 {
 fpos1=(int)objiff2.tellg();
 break;
 }
}
if(fpos1>0)
{
 leaveobj.setstatus();
 objiff2.seekp(fpos1-sizeof(leave),ios::beg);
 objiff2.write((char *) &leaveobj, sizeof(leave));
}
objiff2.close();
}
void displayall_leave()
{
ifstream objiff2;
leave leaveobj;
objiff2.open("leave.dat",ios::binary);
objiff2.seekg(0,ios::beg);
if(!objiff2)
{
cout<<"File could not be open !! Press any Key...";
getch();
}
clrscr();
intromain();
gotoxy(5,8);
cout<<"EMPID"<<setw(12)<<"DATEOFLEAVE"<<setw(12)<<"DATEOFLEAVE"<<setw(12)<<"DESCRIPTION"<<setw(10)<
<"STATUS";
gotoxy(1,9);
cout<<"***************************************************************************";
 int x=10;
 while(objiff2.read((char*)&leaveobj,sizeof(leave)))
{
 leaveobj.showsLEAVE_VER(x);
 x++;
}
 objiff2.close();
getch();
}
//*****************Emp modify Name of employee
//*******************report of employee******************
void gen_report(char num[5],int yy)
{
ifstream objiff3;
leave leaveobj;
objiff3.open("leave.dat",ios::binary);
ifstream objiff2;
 ifstream objiff;
 employee eobj;
 emp_salary salobj;
 int flag=-1;
 objiff.open("employee.dat",ios::binary);
objiff2.open("salary.dat",ios::binary);
 clrscr();
 intromain();
while(objiff.read((char*)&eobj,sizeof(employee)))
{
 if(strcmp(eobj.getempid(),num)==0)
{
 clrscr();
 intromain();
 eobj.showempdatamulti();
 flag=1;
 break;
}
}
 objiff.close();
//int fpos1=-1;
if(flag==-1)
{ cout<<"\n\nrecord not exist";
getch();
}else
{
int c=13;
gotoxy(1,c);
c++;
cout<<"BASIC SAL"<<setw(5)<<"HRA"<<setw(4)<<"DA"<<" ,
"<<"OTHERALLOW"<<setw(7)<<"BONUS"<<setw(5)<<"PF";
 cout<<setw(12)<<"NETSALARY"<<setw(8)<<"DOJ";
gotoxy(1,c);
cout<<"========================================================================";
c++;
while(objiff2.read((char *) &salobj, sizeof(emp_salary)))
{
 if(strcmp(salobj.getsempid(),num)==0 && (salobj.getyear()==yy))
{
 salobj.showsalreportYEARLY(c);
c++;
}
}
gotoxy(1,c);
cout<<"========================================================================";
c++;
gotoxy(1,c);
cout<<"******************EMPLOYEE LEAVE INFORMATION ***************************";
c++;
gotoxy(1,c);
cout<<"EMPID"<<setw(15)<<"DATEOFLEAVE"<<setw(15)<<"DATEOFLEAVE"<<setw(15)<<"DESCRIPTION"<<setw(14)<
<"STATUS";
c++;
gotoxy(1,c);
cout<<"***************************************************************************";
c++;
while(objiff3.read((char*)&leaveobj,sizeof(leave)))
{
if(strcmpi(leaveobj.get_leave_eid(),num)==0)
{
leaveobj.showsLEAVE_VER(c);
c++;
}}}
objiff2.close();
 objiff3.close();
getch();
}
//*******************report of employee******************