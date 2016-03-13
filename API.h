/******************************************************************************

                                  2015

 ******************************************************************************
  �� �� ��   : API.h
  �� �� ��   : v1.0
  ��������   : ���ڲ��ݶ����������ĺ���
  �����б�   : void putnum(SBTreeNode<T>* p)   //������p������
               void CompareEfficency()         //�Ƚ϶���������������Ĳ���Ч��

******************************************************************************/



#ifndef __API_H__
#define __API_H__

#include<vector>
#include<time.h>
#include<cstdlib>
#include"SortBinTree.h"
#include"Student.h"


#define _API_MAXSIZE_ 50


//������p������
template<class T>
void putnum(SBTreeNode<T>* p)
{
	cout<<p->data<<" ";
}


/*****************************************************************************
 �� �� ��  : CompareEfficency
 ��������  : �Ƚ϶���������������Ĳ���Ч��
 �������  : ��
 �������  : ��������ʱ��
 �� �� ֵ  : ��
*****************************************************************************/
void CompareEfficency()
{
	Student stu[_API_MAXSIZE_];             //����һ����СΪ_API_MAXSIZE_����ΪStudent������stu
	char a[20]="zeng";
	int Score=90;
	vector<int> vec;                        //����һ��Ԫ������Ϊint������
	for(int i=1;i<=_API_MAXSIZE_;i++)       //��������1~50
		vec.push_back(i);
	srand((unsigned)time(NULL));            //��ʱ��Ϊ���ӣ�����һ�������
	for(int i=_API_MAXSIZE_;i>=1;i--)       //������vec�����ȡ��һ��������������stu��
	{
		int j=rand()%i;                     //�õ�һ����0~i֮�������
		int k=vec[j];                       //ȡ������vec�ĵ�j+1����
		for(vector<int>::iterator Iter=vec.begin();Iter!=vec.end();Iter++)
		{
			if(*Iter==k)
			{
				Iter=vec.erase(Iter);       //ɾ������vec�ĵ�j+1����
				break;
			}
		}
		stu[_API_MAXSIZE_ - i].num=k;       //����vec�ĵ�j+1������Ϊ����stu��Ԫ�ص�ѧ��
		strncpy(stu[_API_MAXSIZE_ -i].name,a,20); 
		stu[_API_MAXSIZE_ - i].score=Score;
	}

	SortBTree<Student> BST2;                //����һ����������������
	BST2.CreateSBT(stu,_API_MAXSIZE_);      //������stu��������������BST2
	
	clock_t start1,finish1;                 //start1��finish1�ֱ����ڼ�¼�Ӷ���������������ǰ���ʱ��
	clock_t start2,finish2;                 //start2��finish2�ֱ����ڼ�¼������������ǰ���ʱ��
	clock_t sum1=0,sum2=0;                  //�ֱ����ڼ�¼�����������õ�ʱ���
	for(int i=0;i<1000000;i++)              //ִ��1000000�Σ�ʹsum1��sum2������
	{
		int Rand=rand()%50;                 //�������һ��Ҫ������Ԫ��
		Student stu2=stu[Rand];             //stu2Ϊ����Ԫ��

		start1=clock();
		BST2.Search(stu2);                  //�Ӷ���������������Ԫ��stu2
		finish1=clock();

		start2=clock();
		for(int i=0;i<_API_MAXSIZE_;i++)    //������������Ԫ��stu2
		{
			if(stu[i]==stu2)
				break;
		}
		finish2=clock();
		sum1+=(finish1-start1);             //�ۼӴӶ�����������������ʱ���
		sum2+=(finish2-start2);             //�ۼӴ�������������ʱ���
	}
	cout<<"����1000000��"<<endl;
	cout<<"�������������õ�ʱ��Ϊ��"<<sum1<<endl;
	cout<<"�������õ�ʱ��Ϊ��      "<<sum2<<endl;
	
}




#endif /*__API_H__*/
