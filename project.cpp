#include <iostream>
#include <fstream>
#include<stdlib.h>
using namespace std;
struct lesson{
	string name;
	string number;
	int unit;
	int numberOfStudent;
	lesson *next;	
};

struct student {
	string studentName;
	string studentLastName;
	string studentNumber;
	int numberOfLessons;
	unsigned long int salary;
	lesson *lessons;
	student *next; 
};
void readFile(student *&,lesson*&);
void showLessons(lesson*);
void showStudent(student*);
student * findStudent(student*&);
void addLessonAtEnd(lesson*&,lesson*);
void addLessonForStudent(student*&,lesson*);
lesson *findLesson(lesson*&);
int deleteLesson(student *& );
void writeToFile(student*,lesson*);
void start(student*&,lesson*&);
int main(){
	student *studentHead=NULL;
	lesson *lessonsHead=NULL;
	readFile(studentHead,lessonsHead);
	start(studentHead,lessonsHead);
	return 0;
}


void start(student*&studentHead,lesson*&lessonsHead){
	
		int x;
	student *targetStudent=findStudent(studentHead);
	if(targetStudent !=NULL){
		
	cout<<"****main menue****"<<endl;
	cout<<"1-show  lesson"<<endl<<"2- add new lesson"<<endl<<"3- delete lessons"<<endl<<"4- change your student number"<<endl<<"5- exit "<<endl<<endl;
	for(cin>>x;x!=5;cin>>x){
		
	if(x==1){
		showLessons(targetStudent->lessons);
	}
	if(x==2){
		lesson *targetLesson=findLesson(lessonsHead);
		addLessonForStudent(targetStudent,targetLesson);
	
	}
	

	if(x==3){
	int result=	deleteLesson(targetStudent);
	if(result==1){
		cout<<"the lesson is deleted "<<endl;
		cout<<endl;
	}
	}
	
	if(x==4){
	 targetStudent=findStudent(studentHead);
	}
	
	
	
	cout<<"****main menue****"<<endl;
	cout<<"1-show  lesson"<<endl<<"2- add new lesson"<<endl<<"3- delete lessons"<<endl<<"4- change your student number"<<endl<<"5-exit "<<endl<<endl;

}
writeToFile(studentHead,lessonsHead);
}
	
	

	
}
void addLessonAtEnd(lesson*&head,lesson*newLesson){
	 lesson *temp2;
	if(head==NULL){
	head=newLesson;
}	
	else{
	temp2=head;
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	temp2->next=newLesson;
	}
}


void readFile(student *&studentHead,lesson*&lessonHead){


fstream file;
file.open("student.txt",ios::in);
 int length;
	file>>length;
	
for(int i=0;i<length;i++){

	student *newStudent=new student;
	student *temp2;
	file>>newStudent->studentNumber;
	file>>newStudent->studentName;
	file>>newStudent->studentLastName;
	file>>newStudent->salary;
	file>>newStudent->numberOfLessons;
	newStudent->next=NULL;
	newStudent->lessons=NULL;
	for(int j=0;j<newStudent->numberOfLessons;j++){
		
	lesson *temp=new lesson;
	file>>temp->name;
	file>>temp->number;
	file>>temp->unit;
	file>>temp->numberOfStudent;
	temp->next=NULL;
addLessonAtEnd(newStudent->lessons,temp);

	  }
		 
	if(studentHead==NULL){
	studentHead=newStudent;
}	
	else{
	temp2=studentHead;
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	temp2->next=newStudent;
	}

}



   int lessonsLength;
    file >> lessonsLength;
    for (int i = 0; i < lessonsLength; i++)
    {
        lesson *newLesson = new lesson;
       
        file >> newLesson->name;
        file >> newLesson->number;    
		file >> newLesson->unit;
        file >> newLesson->numberOfStudent;
        newLesson->next = NULL;

	addLessonAtEnd(lessonHead,newLesson);


}
	file.close();

}




void writeToFile(student*studentHead,lesson*lessonsHead){
	
	student*temp=studentHead;
	int studentLength=0;
	while(temp!=NULL){
		studentLength++;
		temp=temp->next;	}
		
		temp=studentHead;
	
fstream file;
file.open("student.txt",ios::out);
	file<<studentLength<<endl;
for(int i=0;i<studentLength;i++){

int lessonsLength=0;
lesson*temp2=temp->lessons;
	
		while(temp2!=NULL){
		lessonsLength++;
		temp2=temp2->next;	}
	
		file<<temp->studentNumber<<"\t"<<temp->studentName<<" "<<temp->studentLastName<<"\t"<<temp->salary<<"\t"<<lessonsLength<<endl;
	temp2=temp->lessons;
	for(int j=0;j<lessonsLength;j++){
		
		file<<temp2->name<<"\t"<<temp2->number<<"\t"<<temp2->unit<<"\t"<<temp2->numberOfStudent<<endl;
		
		temp2=temp2->next;
	}
	
	temp=temp->next;
	
	
}
	


lesson*lessonsTemp=lessonsHead;
int length=0;
while(lessonsTemp!=NULL){
	length++;
	lessonsTemp=lessonsTemp->next;
}
	
	file<<length<<endl;
	lessonsTemp=lessonsHead;
	for(int a=0;a<length;a++){
		file<<lessonsTemp->name<<"\t"<<lessonsTemp->number<<"\t"<<lessonsTemp->unit<<"\t"<<lessonsTemp->numberOfStudent<<endl;
		lessonsTemp=lessonsTemp->next;
		
	}
	
	file.close();
	
}



void showLessons(lesson*head){
	
	lesson *temp;
	temp=head;
	if(temp==NULL){
		cout<<"there is no  lesson!"<<endl;
		cout<<endl;
	}else{
	
	while(temp!=NULL){
		cout<<temp->name<<"\t"<<temp->number<<"\t"<<temp->unit<<"\t"<<temp->numberOfStudent<<endl;
	temp=temp->next;
	}}
	cout<<endl;
}

void showStudent(student*head){
	student*temp;
	temp=head;
	while(temp!=NULL){
		
		
		cout<<temp->studentName<<" "<<temp->studentLastName<<"\t"<<temp->studentNumber<<"\t"<<temp->numberOfLessons<<"\t"<<temp->salary<<endl;
	temp=temp->next;
	}
}

student* findStudent(student *&head){
	int count=0;
	string number;
	cout<<"please enter your student number:";
	cin>>number;
	cout<<endl;
	student *temp;
	temp=head;
	if(temp==NULL){
cout<<	"there is no student in this list!"<<endl;
cout<<endl;
	return NULL;
}
else{

	while(temp!=NULL){
		if(number==temp->studentNumber){
			count++;
			cout<<temp->studentName<<" "<<temp->studentLastName<<"\t"<<temp->studentNumber<<"\t"<<temp->numberOfLessons<<"\t"<<temp->salary<<endl;	
			 lesson *temp2=temp->lessons;
showLessons(temp2);
			return temp;
		
		}
		temp=temp->next;
	}
if(count==0){
	cout<<"the student nuber is wrong! please try again"<<endl;
	cout<<endl;
	return findStudent(head);
}}
}

lesson *findLesson(lesson *&head){
	int count=0;
		string number;
	cout<<"please enter the lesson number :";
	cin>>number;
	cout<<endl;
	lesson*temp;
	temp=head;
	
if(temp==NULL){
cout<<	"there is no lesson!"<<endl;
cout<<endl;
	return NULL;
}
else{

	while(temp!=NULL){
		if(number==temp->number){
			count++;
return temp;
}
		
temp=temp->next;}
if(count==0){
	cout<<"number of lesson is wrong! please try again"<<endl;
	cout<<endl;
return 	findLesson(head);

}
}
}
void addLessonForStudent(student *& targetStudent,lesson*newLesson){
int count=0;
lesson *temp1=targetStudent->lessons;
		while(temp1!=NULL){
		if(temp1->number==newLesson->number){
cout<<"you have this lesson!"<<endl;
cout<<endl;
count++;
	}

	temp1=temp1->next;}
	
	if(count==0){
	
	
     lesson *temp = targetStudent->lessons;
     lesson *targetLesson=new lesson;
   targetLesson->name=newLesson->name;
   targetLesson->number=newLesson->number;
   targetLesson->unit=newLesson->unit;
   targetLesson->numberOfStudent=newLesson->numberOfStudent;
   targetLesson->next=NULL;
   
   
   if(temp==NULL){
   	targetStudent->lessons= targetLesson;
   		cout<<"the lesson is added"<<endl;
		cout<<endl;
   }
   else{
   
         while (temp->next){
		 
             temp = temp->next;
        
     } temp->next = targetLesson;
    	cout<<"the lesson is added"<<endl;
		cout<<endl;
 
}	
}	
}


int deleteLesson(student *& targetStudent){
	int count=0;
showLessons(targetStudent->lessons);
lesson* temp=targetStudent->lessons;
lesson* head=targetStudent->lessons;
lesson*previous=head;
if(temp==NULL){
	cout<<"there is no lesson!"<<endl;
	return 0;
}
else{
	string number;
	cout<<"enter number of lesson you want to delete :";
	cin>>number;
	while(temp!=NULL){
		if(temp->number==number){
	
		count++;	
		break;
		}
	temp=temp->next;}
	
	if(count==0){
cout<<endl<<"number of lesson is wrong! try again"<<endl;

return deleteLesson(targetStudent);		
		
	}
	

if(temp==head && head->next==NULL){

	targetStudent->lessons=NULL;
	return 1;
}
	else if(temp==head){
		targetStudent->lessons=head->next;
	return 1;
	}
			
	
	else if(temp->next==NULL){	
		while(previous->next!=temp){
				previous=previous->next;
			}
		previous->next=NULL;
		return 1;
	}
else{
			while(previous->next!=temp){
				previous=previous->next;
			}
	previous->next=temp->next;
	return 1;
}	
	
}	
}
