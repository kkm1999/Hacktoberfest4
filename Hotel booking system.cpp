
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#define size 51

void main(void);
void entry(void);
void modify(void);
void delet(void);
void view(void);

// Structure

struct hoteldata
{
char name[size][30], nic[size][20],rdate[size][12],cdate[size][12];
};

struct hoteldata guest;

struct hoteldata1
{
char name[size][30], nic[size][20],rdate[size][12],cdate[size][12];
};

struct hoteldata1 guest1;
// Initializations
int li,lp,sr[size];int dr[size];int rno;int i;int e;
char rc,ch,choice,echoice,rchoice,temp[80],vchoice,mf,ar;
// Main Fuction
void main(void)
{
clrscr();
sr[0]=1;dr[0]=1; // THE MAIN LOGIC !!

for(li=10;li<71;li++)
{
gotoxy(li,15);
delay(10);
printf("\/");
}
for(li=70;li>=10;li--)
{
gotoxy(li,22);
delay(10);
printf("\\");
}
for(lp=16;lp<=21;lp++)
{
gotoxy(10,lp);
delay(100);
printf("-");
}
for(lp=21;lp>=16;lp--)
{
gotoxy(70,lp);
delay(100);
printf("=");
}
gotoxy(16,17);
textcolor(BLINK + ORANGE);
cprintf("Welcome To The NALAIQUE's Hotel Reservation System");
gotoxy(12,20);

  
getch();
main();
}// Main Fuction End

//Main Menu Function
void main(void)
{
clrscr();
for(li=30;li<=50;li++)
{
gotoxy(li,14);
delay(10);
printf("*");
}
for(li=50;li>=30;li--)
{
gotoxy(li,30);
delay(10);
printf("*");
}
for(lp=15;lp<30;lp++)
{
gotoxy(30,lp);
delay(50);
printf("|");
}
for(lp=29;lp>=15;lp--)
{
gotoxy(50,lp);
delay(100);
printf("|");
}
gotoxy(15,10);
textcolor(WHITE);
cprintf("Press the corresponding Keys for the desired action");
gotoxy(33,16);
textcolor(BROWN);
cprintf("R: Reservation");
gotoxy(33,19);
textcolor(MAGENTA);
cprintf("V: Room Status");
gotoxy(33,22);
textcolor(LIGHTBLUE);
cprintf("M: Modification");
gotoxy(33,25);
textcolor(LIGHTRED);
cprintf("D: Deletion");
gotoxy(33,28);
textcolor(GREEN);
cprintf("Q: Quit");
textcolor(WHITE);
choice=getch();
switch(choice)
{// Choice Switch Begin
case 'R':
entry();
case 'V':
view();
case 'M':
modify();
case 'D':
delet();
case 'Q':
exit(0);
default:
{//Choice Default
gotoxy(33,40);
printf("\n\nIllegal Choice or make sure CAPS Lock is on");
getch();
mainm();
}//Choice Default End
} //Choice Switch End
} //Main Menu Function End
// Data Entry Function
void entry(void)
{//Data Entry Function Begin
clrscr();
printf("Do You Want To reserve A Room? (Y/N)\n");
echoice=getch();
switch(echoice) // Echoice Switch Begin
{
case 'Y':
{ // E-Choice Case Y Begin
printf("\n\nEnter S for Single Room or D for Double Room\n\n");
rchoice=getch();
switch(rchoice) // Rchoice Switch Begin
{
case 'S': // Rchoice
{// R-Choice Case S Begin
for(i=1;i<size;i++)
if(sr[i]==0)
{// Single Room IF begin
clrscr();
sr[i]=1;
printf("\n\nRoom No : %d Is available For Reservation",i);
printf("\n\nEnter Occupant's Name\n");
gets(guest.name[i]);
printf("\n\nEnter Occupant's NIC Number\n");
gets(guest.nic[i]);
printf("\n\nEnter Check In Date\n");
gets(guest.rdate[i]);
printf("\n\nEnter Check Out Date\n");
gets(guest.cdate[i]);
printf("\n\n\n\nDo You Want To Reserve Another Room? Y/N");
ar=getch();
switch (ar)
{// AR Switch Begin
case 'Y':
entry();
case 'N':
mainm();
default:
{//AR Default Begin
printf("\n\nIllegal Choice or make sure CAPS Lock is on");
getch();
mainm();
}//AR Default End

}// AR Switch End
}// Single Room IF End
}// Rchoice Case S End

case 'D':
{ //Rchoice Case D Begin
for(i=1;i<size;i++)
if(dr[i]==0)
{// Double Room IF begin
clrscr();
dr[i]=1;
printf("\n\nRoom No : %d Is available For Reservation",i);
printf("\n\nEnter Occupant's Name\n");
gets(guest1.name[i]);
printf("\n\nEnter Occupant's NIC Number\n");
gets(guest1.nic[i]);
printf("\n\nEnter Check In Date\n");
gets(guest1.rdate[i]);
printf("\n\nEnter Check Out Date\n");
gets(guest1.cdate[i]);
printf("\n\n\n\nDo You Want To Reserve Another Room? Y/N");
ar=getch();
switch (ar)
{// AR Switch Begin
case 'Y':
entry();
case 'N':
mainm();
default:
{//AR Default Begin
printf("\n\nIllegal Choice or make sure CAPS Lock is on");
getch();
mainm();
}//AR Default End
}// AR Switch End
}// Double Room IF End
}// Rchoice Case D End
default: // Rchoice Default
{//Rchoice Default Begin
printf("\n\nIllegal Choice or make sure CAPS Lock is on");
getch();
mainm();
}//Rchoice default end
}//Rchoice End
}//Echoice Case Y End
case 'N':
{// Echoice Case N Begin
mainm();
}//Echoice Case N End
default: //Echoice Default
printf("\n\nIllegal Choice or make sure CAPS Lock is on");
getch();
mainm();
} // Echoice Default End
} //Data Entry Function End


// Data View Fucntion
void view(void)
{// Data View Function Begin
clrscr();
printf("Press S for Sequential Display of the room status \
\n\nPress R for Manual Check Of Room Status\n\n");
vchoice=getch();
switch(vchoice)
{//Vchoice Switch Begin
case 'S':
{//Vchoice Case S Begin
clrscr();
printf("R.No.\tName\t\tNIC Number\tCheck In\tCheck Out\n");
for(i=1;i<size;i++)
{//i Loop Begin
if(sr[i]==1)
{//SR[i]==1 Conditional Printing Begin
printf("\n%d\t%s\t%s\t%s\t%s\n",i,guest.name[i],guest.nic[i], \
guest.rdate[i],guest.cdate[i]);

}//SR[i]==1 Conditional Printing End
}//i Loop End
printf("\n\n\nPress Any Key For Double Room Status\n\n");
getch();
clrscr();
printf("R.No.\tName\t\tNIC Number\tCheck In\tCheck Out\n");
for(i=1;i<size;i++)
{//i Loop Begin
if(dr[i]==1)
{//dr[i]==1 Conditional Printing Begin
printf("\n%d\t%s\t%s\t%s\t%s\n",i,guest1.name[i],guest1.nic[i] \
,guest1.rdate[i],guest1.cdate[i]);

}//dr[i]==1 Conditional Printing End
}//i Loop End
printf("\n\n\nPress Any Key To Return To The Main Menu\n\n");
getch();
mainm();
}//Vchoice Case S End
case 'R':
{// Vchoice case R Start
clrscr();
printf("Enter The Room Number That Needs To Be Checked For \
Occupancy\n\n");
gets(temp);
rno=atoi(temp);
// Room Number Limit Check
if(rno<1 || rno >51)
{//IF Condition Begin
printf("\n\nIllegal Room Number");
getch();
mainm();
} //IF Condition End
else
{ // Limit Else Falsified Begin
if(sr[rno]==1)
{//sr==1 if Begin
printf("\n\nSingle Room No %d Is Reserved",rno);
printf("\n\nOccupant's Name : %s \n\nOccupant's NIC Number : %s \
\n\nCheck In Date : %s\n\nCheck Out Date : %s \n\n", \
guest.name[rno],guest.nic[rno],guest.rdate[rno],guest.cdate[rno]);

}//sr==1 if End
else
{// sr else begin
printf("\n\nSingle Room No %d is Vacant",rno);
getch();
}//sr else end
if(dr[rno]==1)
{//dr==1 if Begin
printf("\n\nDouble Room No %d Is Reserved",rno);
printf("\nOccupant's Name : %s \n\nOccupant's NIC Number : \
%s \n\nCheck In Date : %s\n\nCheck Out Date : %s \n\n", \
guest1.name[rno],guest1.nic[rno],guest1.rdate[rno], \
guest1.cdate[rno]);
printf("\n\nPress Any Key To Return To The Main Menu");
getch();
mainm();
}//dr==1 if End
else
{// dr else begin
printf("\n\nDouble Room No %d is Vacant",rno);
getch();
mainm();
}//dr else end
}//Vchoice Case R End
}// Falsified Limit End
default:
{
//Vchoice Default Begin
printf("\n\nIllegal Choice or make sure CAPS Lock is on");
getch();
mainm();
} // Vchoice Default End
} // Vchoice Switch End
} // Data View Function End



//Modify Function
void modify(void)
{// Modify Function Begin
clrscr();
printf("\t\t\t\tData Modification\n\n\n\n\n\n");
printf("Enter The Room Number To Be Modified\n");
gets(temp);
rno=atoi(temp);
// Room Number Limit Check
if(rno<1 || rno >51)
{//IF Condition Begin
printf("\n\nIllegal Room Number");
getch();
mainm();
} //IF Condition End
else
{ // Limit Else Falsified Begin
printf("Enter S For Single Room / D For Double Room\n");
rc=getch();
switch(rc)
{//rc Switch Begin
case 'S':
{//rc Case S Begin
if(sr[rno]==1)
{//sr==1 if Begin
clrscr();
printf("\n\nSingle Room No %d Is Reserved",rno);
printf("\n\nOccupant's Name : %s \n\nOccupant's NIC Number : \
%s \n\nCheck In Date : %s\n\nCheck Out Date : %s \n\n", \
guest.name[rno],guest.nic[rno],guest.rdate[rno],guest.cdate[rno]);

printf("\n\nPress N : Change Of Name\nI : Change In NIC\nR : \
Check In Date\nO : Check Out Date\n\n");
mf=getch();
switch(mf)
{//mf switch Begin
case 'N':
{//mf Case N Begin
printf("\n\nEnter New Name\n");
gets(guest.name[rno]);
getch();
mainm();
}//mf Case N End
case 'I':
{//mf Case I Begin
printf("\n\nEnter New NIC Number\n");
gets(guest.nic[rno]);
getch();
mainm();
}//mf Case I End
case 'R':
{//mf Case R Begin
printf("\n\nEnter New Check In Date\n");
gets(guest.rdate[rno]);
getch();
mainm();
}//mf Case R End
case 'O':
{//mf Case O Begin
printf("\n\nEnter New Check Out Date\n");
gets(guest.cdate[rno]);
getch();
mainm();
}//mf Case O End
default:
{//mf Default Begin
printf("\n\nInvalid Entry");
getch();
mainm();
}//mf Default End
}//sr==1 if End
} //rc Case S End
else
{// sr else begin
printf("\n\nSingle Room No %d is Vacant",rno);
getch();
mainm();
}//sr else end
}//rc Case S End
case 'D':
{// rc Case D Begin
if(dr[rno]==1)
{//dr==1 if Begin
clrscr();
printf("\n\nDouble Room No %d Is Reserved",rno);
printf("\n\nOccupant's Name : %s \n\nOccupant's NIC Number : \
%s \n\nCheck In Date : %s\n\nCheck Out Date : %s \n\n",\
guest1.name[rno],guest1.nic[rno],guest1.rdate[rno],\
guest1.cdate[rno]);

printf("\n\nPress N : Change Of Name\nI : Change \
In NIC\nR : Check In Date\nO : Check Out Date\n\n");
mf=getch();
switch(mf)
{//mf switch Begin
case 'N':
{//mf Case N Begin
printf("\n\nEnter New Name\n");
gets(guest1.name[rno]);
getch();
mainm();
}//mf Case N End
case 'I':
{//mf Case I Begin
printf("\n\nEnter New NIC Number\n");
gets(guest1.nic[rno]);
getch();
mainm();
}//mf Case I End
case 'R':
{//mf Case R Begin
printf("\n\nEnter New Check In Date\n");
gets(guest1.rdate[rno]);
getch();
mainm();
}//mf Case R End
case 'O':
{//mf Case O Begin
printf("\n\nEnter New Check Out Date\n");
gets(guest1.cdate[rno]);
getch();
mainm();
}//mf Case O End
default:
{//mf Default Begin
printf("\n\nIllegal Choice or make sure CAPS Lock is on");
getch();
mainm();
}//mf Default End
}//dr==1 if End
}//rc Case D End
else
{// dr else begin
printf("\n\nSingle Room No %d is Vacant",rno);
getch();
mainm();
}//dr else end
} // Case D End
default:
{// rc Default Begin
printf("\n\n\nIllegal Entry Or Make Sure CAPS Lock is On");
getch();
mainm();
} // rc Default End
} //Switch rc End
} // Limit Else Falsified End
} //Modify Function End


//Delete Function
void delet(void)
{//Delete Function
clrscr();
printf("Enter The Room Number To Vacate\n");
gets(temp);
rno=atoi(temp);

// Room Number Limit Check
if(rno<1 || rno >51)
{//IF Condition Begin
printf("\n\nIllegal Room Number");
getch();
mainm();
} //IF Condition End
else
{// Room Number Limit Falsified Else
printf("\n\nSingle Or Double Room? (S/D)");
rc=getch();
switch(rc)
{//rc Switch Begin
case 'S':
{//rc Case S Begin
sr[rno]=0;
printf("\n\nRoom Vacated");
printf("\n\nPress Any Key To Exit To The Main Menu");
getch();
mainm();
}// rc Case S End
case 'D':
{//rc Case D Begin
dr[rno]=0;
printf("\n\nRoom Vacated");
printf("\n\nPress Any Key To Exit To The Main Menu");
getch();
mainm();
}//rc Case D End
default:
{//rc Default Begin
printf("\n\nIllegal Choice Or Make Sure CAPS Lock is ON");
getch();
mainm();
}// rc Default End
}// rc Switch End
}// Room Number Falsified Else End
}// Delete Function End

// END OF PROGRAM
