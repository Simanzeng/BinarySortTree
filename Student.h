
#ifndef __STUDENT_H__
#define __STUDENT_H__


#include<string>

#define NAMESIZE 20
using namespace std;

struct Student
{
	int num;              //ѧ��ѧ��
	char name[NAMESIZE];  //ѧ������
	int score;            //ѧ���ɼ�
	void operator =(Student &student1);
	friend bool operator >(Student &student1,Student &student2);  
	friend bool operator <(Student &student1,Student &student2);
	friend bool operator ==(Student &student1,Student &student2);
	friend ostream& operator <<(ostream &,Student &);
	friend istream& operator >>(istream &,Student &);
	
};

/*************************************
���������������'>'
���ܣ��Ƚ�ѧ��ѧ�ŵĴ�С
������Student�ṹ�������student1��student2.
����ֵ��true��false
**************************************/
bool operator >(Student &student1,Student &student2)
{
	if(student1.num > student2.num)
		return true;
	else return false;
}

/*************************************
���������������'<'
���ܣ��Ƚ�ѧ��ѧ�ŵĴ�С
������Student�ṹ�������student1��student2.
����ֵ��true��false
**************************************/
bool operator <(Student &student1,Student &student2)
{
	if(student1.num < student2.num)
		return true;
	else return false;
}

/*************************************
���������������'=='
���ܣ��ж�ѧ��ѧ���Ƿ����
������Student�ṹ�������student1��student2.
����ֵ��true��false
**************************************/
bool operator ==(Student &student1,Student &student2)
{
	if(student1.num == student2.num)
		return true;
	else return false;
}


void Student::operator =(Student &student1)
{
	num=student1.num;
	strncpy(name,student1.name,20);
	score=student1.score;
}


ostream& operator <<(ostream& out,Student& student)
{
	out<<"("<<student.num<<","<<student.name<<","<<student.score<<")";
	return out;
}


istream& operator >>(istream& in,Student& student)
{
	in>>student.num>>student.name>>student.score;
	return in;
}

#endif  /*__STUDENT_H__*/