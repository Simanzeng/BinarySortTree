#include<iostream>
#include<cctype>
#include<Windows.h>
#include"SortBinTree.h"
#include"API.h"

using namespace std;


int main()
{
	while(true)
	{
		cout<<"-----------------------------��������Ҫѡ��Ĳ���-------------------------------"<<endl;
		cout<<"                    |-------------------------------------|                     "<<endl;
		cout<<"                    ||-----------------------------------||                     "<<endl;
		cout<<"                    ||     1       ��������������        ||                     "<<endl;
		cout<<"                    ||     2          ��������           ||                     "<<endl;
		cout<<"                    ||     3          ɾ������           ||                     "<<endl;
		cout<<"                    ||     4       ��ӡ����������        ||                     "<<endl;
		cout<<"                    ||     5       ע������������        ||                     "<<endl;
		cout<<"                    ||     6  �Զ������������зǵݹ���� ||                     "<<endl;
		cout<<"                    ||     7 ��������Ͷ���������Ч��ʵ��||                     "<<endl;
		cout<<"                    ||     0            �˳�             ||                     "<<endl;
		cout<<"                    ||-----------------------------------||                     "<<endl;
		cout<<"                    |-------------------------------------|                     "<<endl;
		cout<<endl;
		cout<<"��Ҫѡ��Ĳ���Ϊ��";
		int number;
		while(true)
		{
			cin>>number;
			if(number==0||number==1 || number==7) break;
			cout<<"�����ڶ��������������ȴ�����";
		}
		
		int Flag1=0;                      //���ڱ���Ƿ��Ѿ����ɶ���������
		int Flag2=0;                      //��ǽ�����ݵ�����

		if(number==0)
		{
			goto End;
		}

		else if(number==1)
		{
			cout<<"��ѡ�����������ͣ�����(1),�ַ���(2)��:";
			while(true)
			{
			    cin>>Flag2;
				if(Flag2==1||Flag2==2) break;
				cout<<"����������������룺";
			}
		}

		else if(number==7)
		{
			for(int i=0;i<5;i++)
			    CompareEfficency();
		}

		//��������Ϊ����
		if(Flag2==1)
		{
			SortBTree<int> BT;
			int amount;                      //�������ݵĸ���
			int p[50];                        //�������������
			memset(p,'\0',sizeof(p));
			while(true)
			{
				switch(number)
				{
					//��������������
				case 1:
					if(Flag1==1)
					{
						cout<<"�Ѵ��ڶ�����������"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
						break;
					}
					cout<<"�����봴�����������������ݸ�����";
					cin>>amount;
					cout<<"������"<<amount<<"������(����):";
					for(int i=0;i<amount;i++)
						cin>>p[i];
					if(BT.CreateSBT(p,amount))
					{
						cout<<"�����ɹ���"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
					    Flag1=1;                      //�����ɶ���������   
					}
					else cout<<"����ʧ�ܣ������´�����"<<endl;
					break;

					//��������
				case 2:
					if(Flag1==1)
					{
						int Count;
					    cout<<"��������Ҫ��������ݣ�";
					    cin>>Count;
					    if(BT.InputSBT(Count))
						{
							cout<<"����ɹ���"<<endl;
							BT.PrintSBTree2();
							cout<<endl;
						}
					    else cout<<"����ʧ�ܣ�"<<endl;
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;


					//ɾ������
				case 3:
					if(Flag1==1)
					{
						int Count;
						cout<<"������Ҫɾ�������ݣ�";
						cin>>Count;
						if(BT.RemoveSBT(Count))
						{
							cout<<"ɾ���ɹ���"<<endl;
							BT.PrintSBTree2();
							cout<<endl;
						}
						else cout<<"ɾ��ʧ�ܣ�"<<endl;
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;

					//��ӡ����������
				case 4:
					if(Flag1==1)
					{
						cout<<"���������������ţ���"<<endl;
						BT.PrintSBTree();
						cout<<endl;
						cout<<endl;
						cout<<"���������������ţ���"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;

					//ע������������
				case 5:
					if(Flag1==1)
					{
						if(BT.DeleteAll())
						{
							cout<<"ע���ɹ���"<<endl;
							Flag1=0;            //������������ע��,�ʲ����ڶ���������
						}
						else cout<<"ע��ʧ�ܣ�"<<endl;
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;


					//�Զ������������зǵݹ����
				case 6:
					if(Flag1==1)
					{
						int Count;
						cout<<"��ѡ��������ͣ�ǰ��(1),����(2),����(3)��:";
						while(true)
						{
							cin>>Count;
							if(Count==1 || Count==2 || Count==3) break;
							else cout<<"����������������룺";
						}
						if(1==Count) BT.preOrder(putnum);
						else if(2==Count) BT.inOrder(putnum);
						else BT.postOrder(putnum);
						cout<<endl;
						BT.PrintSBTree2();
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;


					//��������Ͷ���������Ч��ʵ��
				case 7:
					for(int i=0;i<5;i++)
					    CompareEfficency();
					cout<<endl;
					break;

				case 0:
					cout<<"���˳���"<<endl;
					goto End;
					break;
				}
				cout<<"��Ҫѡ��Ĳ���Ϊ��";
				cin>>number;
			}
		}


		//��������Ϊ�ַ���
		else if(Flag2=2)
		{
			SortBTree<char> BT;
			int amount;                      //�������ݵĸ���
			char p[50];                        //�������������
			memset(p,'\0',sizeof(p));
			while(true)
			{
				switch(number)
				{
					//��������������
				case 1:
					if(Flag1==1)
					{
						cout<<"�Ѵ��ڶ�����������"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
						break;
					}
					cout<<"�����봴�����������������ݸ�����";
					cin>>amount;
					cout<<"������"<<amount<<"������(����):";
					for(int i=0;i<amount;i++)
						cin>>p[i];
					if(BT.CreateSBT(p,amount))
					{
						cout<<"�����ɹ���"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
					    Flag1=1;                      //�����ɶ���������   
					}
					else cout<<"����ʧ�ܣ������´�����"<<endl;
					break;

					//��������
				case 2:
					if(Flag1==1)
					{
						char Count;
					    cout<<"��������Ҫ��������ݣ�";
					    cin>>Count;
					    if(BT.InputSBT(Count))
						{
							cout<<"����ɹ���"<<endl;
							BT.PrintSBTree2();
							cout<<endl;
						}
					    else cout<<"����ʧ�ܣ�"<<endl;
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;


					//ɾ������
				case 3:
					if(Flag1==1)
					{
						char Count;
						cout<<"������Ҫɾ�������ݣ�";
						cin>>Count;
						if(BT.RemoveSBT(Count))
						{
							cout<<"ɾ���ɹ���"<<endl;
							BT.PrintSBTree2();
							cout<<endl;
						}
						else cout<<"ɾ��ʧ�ܣ�"<<endl;
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;

					//��ӡ����������
				case 4:
					if(Flag1==1)
					{
						cout<<"���������������ţ���"<<endl;
						BT.PrintSBTree();
						cout<<endl;
						cout<<endl;
						cout<<"���������������ţ���"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;

					//ע������������
				case 5:
					if(Flag1==1)
					{
						if(BT.DeleteAll())
						{
							cout<<"ע���ɹ���"<<endl;
							Flag1=0;
						}
						else cout<<"ע��ʧ�ܣ�"<<endl;
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;


					//�Զ������������зǵݹ����
				case 6:
					if(Flag1==1)
					{
						int Count;
						cout<<"��ѡ��������ͣ�ǰ��(1),����(2),����(3)��:";
						while(true)
						{
							cin>>Count;
							if(Count==1 || Count==2 || Count==3) break;
							else cout<<"����������������룺";
						}
						if(1==Count) BT.preOrder(putnum);
						else if(2==Count) BT.inOrder(putnum);
						else BT.postOrder(putnum);
						cout<<endl;
						BT.PrintSBTree2();
					}
					else cout<<"�����ڶ�������������ע���������´�����"<<endl;
					break;


					//��������Ͷ���������Ч��ʵ��
				case 7:
					for(int i=0;i<5;i++)
					    CompareEfficency();
					cout<<endl;
					break;

				case 0:
					cout<<"���˳���"<<endl;
					goto End;
					break;
				}
				cout<<"��Ҫѡ��Ĳ���Ϊ��";
				cin>>number;
			}
		}
     End:
		{
			char ch;
			cout<<"�Ƿ����������(y),��(n)����";
			cin>>ch;
			if(tolower(ch)=='n')
			{
				cout<<"Good Bye!"<<endl;
				break;
			}
			else 
			{
				system("cls");
				continue;
			}
		}
	}
	
	system("pause");
	return 0;
}