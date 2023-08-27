#include<iostream>
#include<fstream>
using namespace std;//Parking Project ::
void menu();//For Main Menu
void info();//For Enter Vehicle Information
void display();//Display All The Data That Are Enter In Database
void earn();//Check How Eaning
void park();//Check How Many Vehicle are Park In Parking
int entity();//Check How Many Vehicle are in File
void search();//It is Used To Search Data
void del();//It is Used To Delete Existing File
int n[400];
char fname[20];
char name[500];
int counter=0;//counter initialize
int main(){ //::Int Main::
    cout<<"     *********************************************************************\n";
	cout<<"     :    *     *  ****  *      ****  ****  *   * ****                   :\n";
	cout<<"     :    *  *  *  *     *      *     *  *  ** ** *                      :\n";
	cout<<"     :    *  *  *  ***   *      *     *  *  * * * ****                   :\n";
	cout<<"     :    *  *  *  *     *      *     *  *  *   * *                      :\n";
    cout<<"     :     ** **   ****  *****  ****  ****  *   * ****                   :\n";
    cout<<"     :                                                                   :\n";
	cout<<"     :             *****  ****                                           :\n";
	cout<<"     :               *    *  *                                           :\n";
    cout<<"     :               *    *  *                                           :\n";
	cout<<"     :               *    ****                                           :\n";
	cout<<"     :                                                                   :\n";
	cout<<"     :          *     *   *    *                                         :\n";
	cout<<"     :          * * * *     *  *                                         :\n";
	cout<<"     :          *  *  *       **                                         :\n";
	cout<<"     :          *     *        *                                         :\n";
	cout<<"     :          *     *        *                                         :\n";
	cout<<"     :                                                                   :\n";
    cout<<"     :  ****       *      * * *    *   *   *   *        *   * * * * *    :\n";
	cout<<"     :  *  *      * *     *   *    *  *    *   *  *     *   *            :\n";
    cout<<"     :  ****     * * *    * * *    * *     *   *    *   *   *    * * *   :\n";
    cout<<"     :  *       *     *   *   *    *  *    *   *      * *   *    *   *   :\n"; 
	cout<<"     :  *      *       *  *    *   *   *   *   *        *   * *  *   *   :\n";
	cout<<"     *********************************************************************\n"<<endl;
	menu(); 
	
}
void menu(){
	int c,n;//check Select Options
	do{
cout<<"\n:::Select One Options::"<<endl<<"Press 1  For Enter New Data"<<endl;
cout<<"Press 2 For Show Previous Data"<<endl<<"Press 3 For Check How Many Vehicle are Park In Parking"<<endl<<"Press 4 Check Earning "<<endl<<"Press 5 Search Data"<<endl;
	cout<<"Press 6 For Delete file "<<endl;//<<"Press 7 For Update Data";
	cin>>c;

	switch(c){//c=1
	case 1:{
		info();
		break;
}
case 2: {
	display();
	break;
}
case 3:{
	park();
	break;
}
case 4:{
	earn();
	break;
}
case 5:{
	search();
	break;
}
case 6:{
	del();
	break;
}

default:{
	cout<<"::You Press Wrong Option Please Try Again Thanku::\n\n";
	break;
} }

cout<<"\nTo Continue Press 1\n";
cin>>n;
if(n==1){
system("cls");}
else{
	cout<<"You Enter Wrong Number";
}
}while(n==1);
}
void info(){//1::
	char s; //check got to main menu or not
	fstream write;// Declare Class Object And Only Used FOr Write  Data Using File Handling
	cout<<"Enter file name: ";
    cin>>fname;
	write.open(fname,ios::out | ios::app);  //Open a File in Document Form  write.open("28-02-19.txt",ios::out | ios::app);
	  if(!write)
   {
       cout<<"Error in creating file!!!";
   }
   else
   {
   cout<<"File created successfully."<<endl;
   }
	for(int i=counter;i==counter;i++){ //for Is Used For Entering Data  counter=0; 0==0  i=0
	cout<<"Enter  Name:";
	cin>>name;
	cout<<"Enter Vehicle No:"; 
	cin>>n[counter];//n[0]=123,  
    write<<name<<"\t\t"<<""<<n[counter]<<endl;
    
	counter++;
	cout<<"Want TO Go Main Menu Press Y for Yes or Press N for No:";
	cin>>s;
	if((s=='y')||(s=='Y')){
	
	write.close();
	system("cls");
	menu();
}
}
}
void display(){//2::
   string a;
	char fname[20];
	cout<<"Enter date you want to See previous Data: ";
   cin>>fname;
	fstream read; 
	read.open(fname,ios::in); 
	 if(!read)
   {
       cout<<"File is not Available in Hardware";
   }
	else{
		cout<<"File is Open Successfully:"<<endl;
		 cout<<"\n---Name----"<<"\t"<<"Car NO--\n";
		 cout<<"================================================================"<<endl;
 while(!read.eof()){//It is used to show database data until The File End::
		
		getline(read,a);
		if(!(a=="")){
	    cout<<"   "<<a<<endl;}
	}
	cout<<"================================================================"<<endl;
	read.close();
}
}

void park(){//3:
       int p;
       p=entity();  //p=4
    if(p>0){
	cout<<"Total Vehicle Park In Parking Is:"<<p-1;}
}
void earn(){//Option 4:: It Check Total Earning Of Vehicle That the Data are Enter In Database 
int e;
     e=entity();
	  if(e>0){
	  cout<<"Total Earning="<<(e-1)*100<<endl;}//we charge 100 ruppess for every Vehicle
	  }

int entity(){ //This Function Is Used To Check The Total Number Of Vehicle Enter In Database
    char name[100];
   int c=0;
   string a;
   cout<<"Enter file name you want to see Details: ";
   cin>>name;
	fstream read; 
	read.open(name,ios::in); 
	if(!read){
		cout<<"::File Not Exits::";
	}
	else{
 while(!read.eof()){//It is used to show database data until The File End::
		getline(read,a);
	    c++;
	}
	read.close();
}
return c;
}
void search(){ //5.Option 5 For Search Data
	 char name[100];
	 string a;
   cout<<"Enter file name you want to Search Data: ";
   cin>>name;
	fstream read; 
	read.open(name,ios::in); 
	if(!read){
		cout<<"::File Not Exits::";
	}
		else{
		cout<<"File is Open Successfully:"<<endl;
    string find;
	cout<<"Please enter a name: ";
	cin>>find;
	bool isFound=0;
	while(!read.eof())
	{
		string temp = "";
		getline(read,temp);
		for(int i=0;i<find.size();i++) //i<3
		{
			if(temp[i]==find[i]){
			
				isFound = 1;}
			else
			{
				isFound =0;
				break;
			}
		}
		if(isFound)   //if(1)
		{
			//cout<<temp.size();
			for(int i=find.size()+1;i<temp.size();i++)  //i=4  i<9
			
				cout<<temp[i];
				 break;
		}

	}

	if(read.eof()&&(!isFound))
	{
		cout<<"Name not found!\n";
	}
   read.close();
	
}
}
void del(){  //6.It is Used To Delete Existing File
int checkstatus;
	char nam[100];
	cout<<"Enter name of file you want to delete : ";
	cin>>nam;
	checkstatus=remove(nam);//remove is used to delete file
 	if(checkstatus==0)
	{
		cout<<"::file "<<nam<<" Deleted successfully..!!\n";
	}
	else
	{
		cout<<"---Unable to delete file "<<nam<<"\n";
	}
}


