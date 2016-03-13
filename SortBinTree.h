/******************************************************************************

                                  2015

 ******************************************************************************
  �� �� ��   : SortBinTree.h
  �� �� ��   : v1.0
  ��������   : ����ģ�弼�������������������SBTreeNode�Ķ���Ͷ�����������SortBTree��
               �����Լ�������ģ��Ķ����ʵ��
  �����б�   :
               **** ������������SortBTree�Ĺ�����Ա������****
                bool CreateSBT(T *str,int n);                        //���ɶ���������,
	            bool InputSBT(T &current);                           //�������������
	            bool RemoveSBT(const T current)��                    //ɾ��current���
	            bool DeleteAll();                                    //ɾ����������������
	            void Traverse(ostream& out)��                        //ǰ��������
	            void LevelOrderPut(void (*visit)(SBTreeNode<T> *p)); //�����������
	            void preOrder(void (*visit)(SBTreeNode<T> *p));      //ǰ��ǵݹ����
	            void inOrder(void (*visit)(SBTreeNode<T> *p));       //����ǵݹ����
	            void postOrder(void (*visit)(SBTreeNode<T> *p));     //����ǵݹ����
	            int GetSBTreeDepth()��                               //�õ��������������
	            void PrintSBTree()��                                 //������������״�������������
	            void PrintSBTree2();                                 //������������״�������������
				bool Search(T x);                                    //����������x��Ԫ��

                *****������������SortBTree��˽�г�Ա������****
                bool RemoveSBT(const T current,SBTreeNode<T> *&ptr); //ɾ��current���
                void Traverse(SBTreeNode<T> *subTree,ostream& out);  //ǰ��������
	            int GetSBTreeDepth(SBTreeNode<T> *ptr);              //�õ��������������
	            void PrintSBTree(SBTreeNode<T> *ptr,int depth);      //������������״�������������
				bool Search(T x);                                    //����������x��Ԫ��
******************************************************************************/


#ifndef __SORTBINTREE_H__
#define __SORTBINTREE_H__


#include"Student.h"
#include<cstdlib>
#include<queue>
#include<stack>
#include<iomanip>

#define ArraySize 2048


//����ඨ��
template<class T>
class SBTreeNode
{
public:
	T data;                  //������
	SBTreeNode<T> *left;     //����Ů
	SBTreeNode<T> *right;    //����Ů
};



//�����������ඨ��
template<class T>
class SortBTree
{
public:
	SortBTree():root(NULL){}                             //���캯��
	~SortBTree(){ DeleteAll();}                          //��������

	bool CreateSBT(T *str,int n);                        //���ɶ���������,
	bool InputSBT(T &current);                           //�������������
	bool RemoveSBT(const T current)                      //ɾ��current���
	{
		if(root==NULL)
		{
			cout<<"����������Ϊ�գ�"<<endl;
			return false ;
		}
		if(RemoveSBT(current,root))
			return true;
		
		else return false;
	}
	bool DeleteAll();                                    //ɾ����������������
	void Traverse(ostream& out)                          //ǰ��������
	{
		if(root==NULL)
		{
			cout<<"����������Ϊ�գ�"<<endl;
			return ;
		}
		Traverse(root,out);
	}
	void LevelOrderPut(void (*visit)(SBTreeNode<T> *p)); //�����������
	void preOrder(void (*visit)(SBTreeNode<T> *p));      //ǰ��ǵݹ����
	void inOrder(void (*visit)(SBTreeNode<T> *p));       //����ǵݹ����
	void postOrder(void (*visit)(SBTreeNode<T> *p));     //����ǵݹ����
	int GetSBTreeDepth()                                 //�õ��������������
	{
		return GetSBTreeDepth(root);
	}
	void PrintSBTree()                                   //������������״�������������
	{
		if(root==NULL)
		{
			cout<<"������������Ϊ�գ�"<<endl;
			return ;
		}
		int depth=GetSBTreeDepth();
		PrintSBTree(root,depth);
	}
	void PrintSBTree2();                                 //������������״�������������
	bool Search(T x);                                    //����������x��Ԫ��
private:
	SBTreeNode<T> * root;                                //ָ����ڵ�
	bool RemoveSBT(const T current,SBTreeNode<T> *&ptr); //ɾ��current���
    void Traverse(SBTreeNode<T> *subTree,ostream& out);  //ǰ��������
	int GetSBTreeDepth(SBTreeNode<T> *ptr);              //�õ��������������
	void PrintSBTree(SBTreeNode<T> *ptr,int depth);      //������������״�������������
};



/*****************************************************************************
 �� �� ��  : CreateSBT(��������)
 ��������  : ���ɶ���������
 �������  : ����ΪT���ַ��������ַ����Ĵ�С
 �������  : ��
 �� �� ֵ  : true��false
*****************************************************************************/

template<class T>
bool SortBTree<T>::CreateSBT(T* str,int n)
{
	if(root!=NULL)                                                    //��δ��ڶ�����������ʧ��
	{
		cout<<"�Ѵ��ڶ�����������"<<endl;
		PrintSBTree2();                                               //������������״�������������
		cout<<endl;
		return false;
	}
	SBTreeNode<T> *s=(SBTreeNode<T>*)malloc(sizeof(SBTreeNode<T>));   //����洢�ռ�
	if(s==NULL)                                                       //�洢�ռ����ʧ��
	{
		cerr<<"�洢�ռ�������"<<endl;
		exit(1);
	}
	s->data=str[0];                                                   //���ַ���str�ĵ�һ��������Ϊ�����
	s->left=NULL;
	s->right=NULL;
	root=s;
	for(int i=1;i<n;i++)                                              //�����������β���
	{
		if(!InputSBT(str[i]))                                         //���ݲ���ʧ��
		{
			cout<<"���ɶ���������ʧ�ܣ�"<<endl;
			if(!DeleteAll()) cout<<"ɾ���������������ʧ�ܣ�"<<endl;  //��������������ʧ�ܣ�ɾ����ǰ���������
			return false;
		}
	}
	return true;
}


/*****************************************************************************
 �� �� ��  : InputSBT(��������)
 ��������  : �ѹؼ���Ϊcurrent�Ľ�㰴�ն�������������
            �����������������Ǵ��ڸ��������������ݣ��������������
 �������  : current  Ҫ����Ľ����Ĺؼ���
 �������  : ��
 �� �� ֵ  : true��false
*****************************************************************************/

template<class T>
bool SortBTree<T>::InputSBT(T &current)  //�������������
{
	SBTreeNode<T> *s=(SBTreeNode<T>*)malloc(sizeof(SBTreeNode<T>)); //����洢�ռ�
	if(s==NULL)                                                     //�洢�ռ����ʧ��
	{
		cerr<<"�洢�ռ�������"<<endl;
		exit(1);
	}
	s->data=current;
	s->left=NULL;
	s->right=NULL;

	if(root==NULL)
	{
		root=s;
		return true;
	}
	SBTreeNode<T> *p=root;                                          //�Ѹ���㸳��ָ��p
	while(p!=NULL)                                                  //����������������Ѱ�Һ��ʵ�
	{
		if(p->data>current)                                         //������������currentС��ָ��pָʾ�Ľ�������ʱ������p������Ů
		{
			if(p->left==NULL)                                       //p������Ů������
			{
				p->left=s;
				return true;
			}
			else p=p->left;                                         //������Ů������
		}
		else if(p->data<current)                                    //������������current����ָ��pָʾ�Ľ�������ʱ������p������Ů
		{
			if(p->right==NULL)                                      //p������Ů������
			{
				p->right=s;
				return true;
			}
			else p=p->right;                                        //������Ů������
		}
		else                                                        //�����Ѵ���
		{
			cout<<"�����Ѵ��ڣ�����ʧ��"<<endl;
			return false;
		}
	}
	return false;
}


/*****************************************************************************
 �� �� ��  : RemoveSBT(˽�к���)
 ��������  : ����ptrΪ���Ķ�����������ɾ����current�Ľ�㣬��ɾ���ɹ����¸�ͨ��ptr����
 �������  : current  Ҫɾ���Ľ����Ĺؼ���
             ptr  ��������
 �������  : �¸�
 �� �� ֵ  : true��false
*****************************************************************************/

template<class T>
bool SortBTree<T>::RemoveSBT(const T current,SBTreeNode<T> *&ptr)
{

	if(ptr!=NULL)
	{
	 
	    SBTreeNode<T> *temp;
		if(current<ptr->data)
		{
			if(RemoveSBT(current,ptr->left))                         //����������ִ��ɾ��
				return true;
			else return false;
		}
		else if(current>ptr->data) 
		{
			if(RemoveSBT(current,ptr->right))                        //����������ִ��ɾ��
				return true;
			else return false;
		}
		else if(ptr->left!=NULL && ptr->right!=NULL)              //ptrָʾ�Ĺؼ���Ϊcurrent�Ľ�㣬������������
		{
			temp=ptr->right;                                      //�����������������µĵ�һ����㣬�������ptrָʾ�Ľ��
			while(temp->left!=NULL) temp=temp->left;
			ptr->data=temp->data;                                 //�øý�����ptrָʾ�Ľ��
			if(RemoveSBT(ptr->data,ptr->right))                      //����ΪRemoveSBT(ptr->data,temp);  ɾ���ý��
				return true;
			else return false;
		}
		else                                                      // ptrָʾ�Ĺؼ���Ϊcurrent�Ľ�㣬��ֻ��һ�����������
		{
			temp=ptr;
			if(ptr->left==NULL) ptr=ptr->right;
			else ptr=ptr->left;
			delete temp;
			return true;
		}
	}
	else return false;
}


/*****************************************************************************
 �� �� ��  : DeleteAll(��������)
 ��������  : �ò�α����㷨ɾ���������������н��
 �������  : ��
 �������  : ��
 �� �� ֵ  : true��false
*****************************************************************************/
template<class T>
bool SortBTree<T>::DeleteAll()
{
	if(root==NULL) return false;
	queue<SBTreeNode<T>*> Q;                      //����һ������ΪSBTreeNode<T>* �Ķ���Q
	SBTreeNode<T> *ptr=root;                      //�����
	Q.push(ptr);                                  //����������� 
	while(!Q.empty())                             //���в���
	{
		ptr=Q.front();                            //���ض��е�һ��Ԫ��
		Q.pop();                                  //ɾ�����е�һ��Ԫ��
		if(ptr->left!=NULL) Q.push(ptr->left);    //��������Ϊ�գ�����
		if(ptr->right!=NULL) Q.push(ptr->right);  //��������Ϊ�գ�����
		delete ptr;
		ptr=NULL;
	}
	root=NULL;                                    //��NULL���������ĸ�ָ��root
	return true;
}




/*****************************************************************************
 �� �� ��  : LevelOrderPut(��������)
 ��������  : �Ӷ����������ĸ���㿪ʼ���������£��������ҷֲ����η������еĸ������,����α���
 �������  : visit������ָ��
 �������  : ��
 �� �� ֵ  : ��
*****************************************************************************/
template<class T>
void SortBTree<T>::LevelOrderPut(void (*visit)(SBTreeNode<T> *p))
{
	if(root==NULL)
	{
		cout<<"����������Ϊ�գ�"<<endl;
		return ;
	}
	queue<SBTreeNode<T>*> Q;                      //����һ������ΪSBTreeNode<T>* �Ķ���Q
	SBTreeNode<T> *ptr=root;                      //�����
	Q.push(ptr);                                  //����������� 
	while(!Q.empty())                             //���в���
	{
		ptr=Q.front();                            //���ض��е�һ��Ԫ��
		Q.pop();                                  //ɾ�����е�һ��Ԫ��
		visit(ptr);                               //���ú���visit
		if(ptr->left!=NULL) Q.push(ptr->left);    //��������Ϊ�գ�����
		if(ptr->right!=NULL) Q.push(ptr->right);  //��������Ϊ�գ�����
	}
}


/*****************************************************************************
 �� �� ��  : Traverse(˽�к���)
 ��������  : �����������ΪsubTree�Ķ���������
 �������  : subTree�������������Ľ��
             out�������
 �������  : ��
 �� �� ֵ  : ��
*****************************************************************************/
template<class T>
void SortBTree<T>::Traverse(SBTreeNode<T> *subTree,ostream& out)
{
	if(subTree!=NULL)                     //subTreeΪ���򷵻أ�����
	{
		out<<subTree->data<<" ";          //������subTree������ֵ
		Traverse(subTree->left,out);      //�ݹ����������subTree��������
		Traverse(subTree->right,out);     //�ݹ����������subTree��������
	}
}


/*****************************************************************************
 �� �� ��  : preOrder(��������)
 ��������  : ����������ǰ������ķǵݹ��㷨
 �������  : visit������ָ��
 �������  : ��
 �� �� ֵ  : ��
*****************************************************************************/
template<class T>
void SortBTree<T>::preOrder(void (*visit)(SBTreeNode<T> *p))
{
	if(root!=NULL)
	{
		stack<SBTreeNode<T>*> S;                       //ջS���ڼ�¼·��
		SBTreeNode<T> *ptr=root;                       //ptr������ָ�룬�Ӹ���㿪ʼ
		S.push(ptr);                                   //������ջ
	    while(!S.empty())                              //ջ����
	    {
			ptr=S.top();                               //����ջ��Ԫ��
		    S.pop();                                   //�Ƴ�ջ��Ԫ��
		    visit(ptr);                                //����ջ��Ԫ��
		    if(ptr->right!=NULL) S.push(ptr->right);   //��������ջ
		    if(ptr->left!=NULL) S.push(ptr->left);     //��������ջ
	    }
	}
	else cout<<"����������Ϊ�գ�"<<endl;
}


/*****************************************************************************
 �� �� ��  : inOrder(��������)
 ��������  : ������������������ķǵݹ��㷨
 �������  : visit������ָ��
 �������  : ��
 �� �� ֵ  : ��
*****************************************************************************/
template<class T>
void SortBTree<T>::inOrder(void (*visit)(SBTreeNode<T> *p))
{
	if(root!=NULL)
	{
		stack<SBTreeNode<T> *> S;              //ջS���ڼ�¼·��
	    SBTreeNode<T> *ptr=root;               //ptr������ָ�룬�Ӹ���㿪ʼ
		do
		{
			while(ptr!=NULL)                   //����ָ��ĩ�������µĽ�㣬����
			{
				S.push(ptr);                   //��������;����ջ
				ptr=ptr->left;                 //����ָ��������������
			}
			if(!S.empty())                     //ջ��Ϊ��ʱ��ջ
			{
				ptr=S.top();                   //����ջ��Ԫ��
				S.pop();                       //ɾ��ջ��Ԫ��
				visit(ptr);                    //����ջ��Ԫ��
				ptr=ptr->right;                //����ָ����뵽���������
			}
		}while(ptr!=NULL || !S.empty());
	}
	else cout<<"����������Ϊ�գ�"<<endl;
}


/*****************************************************************************
 �� �� ��  : postOrder(��������)
 ��������  : ������������������ķǵݹ��㷨
 �������  : visit������ָ��
 �������  : ��
 �� �� ֵ  : ��
*****************************************************************************/
template<class T>
void SortBTree<T>::postOrder(void (*visit)(SBTreeNode<T> *p))
{
	if(root!=NULL)
	{
		stack<SBTreeNode<T>*> S;
		SBTreeNode<T> *ptr=root;
		SBTreeNode<T> *q;                      //qָ��ǰ����ǰһ���ѷ��ʵĽ��
		int flag;
		do
		{
			while(ptr!=NULL)                     //��ptr�����������ջ
			{
				S.push(ptr);
				ptr=ptr->left;
			}
			q=NULL;
			flag=1;
			while(!S.empty() && flag)
			{
				ptr=S.top();                     //ȡ����ǰ��ջ��Ԫ��
				if(ptr->right==q)                //�����������ڻ��ѱ����ʣ�����֮
				{
					visit(ptr);                  //���ʽ��p
					S.pop();                   //ɾ��ջ��Ԫ��
					q=ptr;                       //qָ�򱻷��ʵĽ��
				}
				else
				{
					ptr=ptr->right;                //��ptrָ��������
					flag=0;
				}
			}
		}while(!S.empty());
	}
	else cout<<"����������Ϊ�գ�"<<endl;
}


/*****************************************************************************
 �� �� ��  : GetSBTreeDepth(˽�к���)
 ��������  : ������������������
 �������  : 
 �������  : ��
 �� �� ֵ  : ���������������
*****************************************************************************/
template<class T>
int SortBTree<T>::GetSBTreeDepth(SBTreeNode<T> *ptr)
{
	if(ptr==NULL) return 0;              //ptrָʾ�Ľ��Ϊ�㣬����0
	int left,right,max;                  
	left=GetSBTreeDepth(ptr->left)+1;    //left����ptr�����������+1
	right=GetSBTreeDepth(ptr->right)+1;  //right����ptr�����������+1
	max=(left>right)?left:right;         //max�������ߵ����ֵ
	return max;                          //���ص�ǰ�������
}



/*****************************************************************************
 �� �� ��  : PrintSBTree(˽�к���)
 ��������  : ������������״�������������
 �������  : ptr: �����ָ��
             depth: ���������������
 �������  : ��������������
 �� �� ֵ  : ��
*****************************************************************************/
template<class T>
void SortBTree<T>::PrintSBTree(SBTreeNode<T> *ptr,int depth)
{
	if(ptr==NULL) 
	{
		return ;
	}
	int k;
	PrintSBTree(ptr->right,depth+1);         //�Ƚ�����������������ҽ��
	for(k=0;k<depth;k++)                     //����ո�
		cout<<"    ";
	cout<<ptr->data<<endl;                   //����������
	PrintSBTree(ptr->left,depth+1);          //�ٽ�������Ů
}


/*****************************************************************************
 �� �� ��  : PrintSBTree2
 ��������  : ������ʾ���ζ���������
 �������  : ��
 �������  : ��������������
 �� �� ֵ  : ��
*****************************************************************************/
template<class T>
void SortBTree<T>::PrintSBTree2()
{
	if(root!=NULL)
	{
		int depth=GetSBTreeDepth();                  //�������������
		int h=depth;

		int a[ArraySize];                            //ÿһ�����һ�������ÿ��������ǰһ�����ľ���
	    int c[ArraySize];                            //�洢�����ͶӰ��X���ϵ�����
	    memset(a,0,sizeof(a));
	    for(int i=0;i<depth;i++)                     //���ö�������i(��0��ʼ)������Ľ�������Ϊ2^(depth-i-1)
	    {                                            //����depthΪ�����������(��1��ʼ)
			a[(1L<<i)-1]=(1L<<(depth-i-1));
			c[(1L<<i)-1]=(1L<<(depth-i-1));
		    for(int j=(1L<<i);j<((1L<<(i+1))-1);j++) 
		    {
				a[j]=2*a[(1L<<i)-1];                 //ÿһ�����һ�������ÿ��������ǰһ�����ľ���Ϊ��һ����������
				c[j]=c[j-1]+a[j];
		    }
		}
		

	    int b[ArraySize];                         //����������Ϊ��׼���Ƚ϶����������ڶ�Ӧ��λ���Ƿ���ڽ��,����ʱ��Ϊ1��������ʱ��Ϊ-1
		memset(b,0,sizeof(b));
		queue<SBTreeNode<T>*> Q;                      //����һ������ΪSBTreeNode<T>* �Ķ���Q
	    SBTreeNode<T> *ptr=root;                      //�����
	    Q.push(ptr);                                  //�����������
		b[0]=1;                                       
		for(int i=1;i<((1L<<depth)-1);)
		{
			if(b[i]==-1)
			{
				if((2*i+1)<((1L<<depth)-1))  b[2*i+1]=-1;
				if((2*i+2)<((1L<<depth)-1))  b[2*i+2]=-1;
			}
			else if(b[i]==0)
			{
				if(!Q.empty())
				{
					ptr=Q.front();
					Q.pop();
					if(ptr->left!=NULL) 
					{
						Q.push(ptr->left);
						b[i]=1;
					}
					else
					{
						b[i]=-1;
						if((2*i+1)<((1L<<depth)-1))  b[2*i+1]=-1;
				        if((2*i+2)<((1L<<depth)-1))  b[2*i+2]=-1;
					}
					if(ptr->right!=NULL)
					{
						Q.push(ptr->right);
						b[i+1]=1;
					}
					else
					{
						b[i+1]=-1;
						if((2*i+3)<((1L<<depth)-1))  b[2*i+3]=-1;
				        if((2*i+4)<((1L<<depth)-1))  b[2*i+4]=-1;
					}
				}
			}
			i=i+2;
		}
		

		queue<SBTreeNode<T>*> S;                      //����һ������ΪSBTreeNode<T>* �Ķ���S
	    SBTreeNode<T> *q=root;                      //�����
	    S.push(q);                                  //����������� 
		for(int i=0;i<((1L<<depth)-1);i++)
		{
			if(b[i]==1)
			{
				if(!S.empty())
				{
					q=S.front();
					S.pop();
					cout<<setfill(' ')<<setw(a[i]*2)<<q->data;
					if(q->left!=NULL) S.push(q->left);
					if(q->right!=NULL) S.push(q->right);
				}
			}
			else if(b[i]==-1)
			{
				cout<<setfill(' ')<<setw(a[i]*2)<<' ';
			}
			if(a[i]>a[i+1])                                  //��a[i]>a[i+1]ʱ������
			{
				
				/*int flag2=2;
				for(int n=depth-h;n<(depth-1);n++)
				{
					int flag1=0;
					cout<<endl;
					for(int j=i/2;j<i+1;j++)
					{
						if( b[j]==1)
						{
							//flag1=0;                
							if(b[2*j+1]==1)
							{
								cout<<setfill(' ')<<setw(2*c[j]-flag2-flag1)<<'/';
								if(b[2*j+2]==1) 
								{
										cout<<setfill(' ')<<setw(2*flag2)<<'\\';
										flag1=2*c[j]+2;
								}
								else flag1=2*c[j]-flag2;
								
								
							}
						}
					}
					flag2=flag2+2;
				}
				h--;*/
				cout<<endl;
			}
		}
		cout<<endl;
	}
	else
	{
		cout<<"����������Ϊ�գ�"<<endl;
		return ;
	}

}


/*****************************************************************************
 �� �� ��  : Search
 ��������  : ����������x��Ԫ��
 �������  : x������������
 �������  : ��
 �� �� ֵ  : true��false
*****************************************************************************/
template<class T>
bool SortBTree<T>::Search(T x)
{
	if(root!=NULL)
	{
		SBTreeNode<T> *p=root;
		while(p!=NULL)
		{
			if(x==p->data) return true;     //�ҵ�������x�Ľ��
			else if(p->data>x) p=p->left;   //����x�Ƚ�����������С��p�������������
			else p=p->right;                 //����x�Ƚ����������ݴ�p�������������
		}
	}
	return false;
}

#endif /* __SORTBINTREE_H__ */