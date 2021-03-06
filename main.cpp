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
		cout<<"-----------------------------请输入你要选择的操作-------------------------------"<<endl;
		cout<<"                    |-------------------------------------|                     "<<endl;
		cout<<"                    ||-----------------------------------||                     "<<endl;
		cout<<"                    ||     1       创建二叉排序树        ||                     "<<endl;
		cout<<"                    ||     2          插入数据           ||                     "<<endl;
		cout<<"                    ||     3          删除数据           ||                     "<<endl;
		cout<<"                    ||     4       打印二叉排序树        ||                     "<<endl;
		cout<<"                    ||     5       注销二叉排序树        ||                     "<<endl;
		cout<<"                    ||     6  对二叉排序树进行非递归遍历 ||                     "<<endl;
		cout<<"                    ||     7 进行数组和二叉树查找效率实验||                     "<<endl;
		cout<<"                    ||     0            退出             ||                     "<<endl;
		cout<<"                    ||-----------------------------------||                     "<<endl;
		cout<<"                    |-------------------------------------|                     "<<endl;
		cout<<endl;
		cout<<"需要选择的操作为：";
		int number;
		while(true)
		{
			cin>>number;
			if(number==0||number==1 || number==7) break;
			cout<<"不存在二叉排序树，请先创建：";
		}
		
		int Flag1=0;                      //用于标记是否已经生成二叉排序树
		int Flag2=0;                      //标记结点数据的类型

		if(number==0)
		{
			goto End;
		}

		else if(number==1)
		{
			cout<<"请选择结点数据类型（整型(1),字符型(2)）:";
			while(true)
			{
			    cin>>Flag2;
				if(Flag2==1||Flag2==2) break;
				cout<<"输入错误！请重新输入：";
			}
		}

		else if(number==7)
		{
			for(int i=0;i<5;i++)
			    CompareEfficency();
		}

		//数据类型为整型
		if(Flag2==1)
		{
			SortBTree<int> BT;
			int amount;                      //输入数据的个数
			int p[50];                        //储存输入的数据
			memset(p,'\0',sizeof(p));
			while(true)
			{
				switch(number)
				{
					//创建二叉排序树
				case 1:
					if(Flag1==1)
					{
						cout<<"已存在二叉排序树！"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
						break;
					}
					cout<<"请输入创建二叉排序树的数据个数：";
					cin>>amount;
					cout<<"请输入"<<amount<<"个数据(整型):";
					for(int i=0;i<amount;i++)
						cin>>p[i];
					if(BT.CreateSBT(p,amount))
					{
						cout<<"创建成功！"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
					    Flag1=1;                      //已生成二叉排序树   
					}
					else cout<<"创建失败！请重新创建！"<<endl;
					break;

					//插入数据
				case 2:
					if(Flag1==1)
					{
						int Count;
					    cout<<"请输入需要插入的数据：";
					    cin>>Count;
					    if(BT.InputSBT(Count))
						{
							cout<<"插入成功！"<<endl;
							BT.PrintSBTree2();
							cout<<endl;
						}
					    else cout<<"插入失败！"<<endl;
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;


					//删除数据
				case 3:
					if(Flag1==1)
					{
						int Count;
						cout<<"请输入要删除的数据：";
						cin>>Count;
						if(BT.RemoveSBT(Count))
						{
							cout<<"删除成功！"<<endl;
							BT.PrintSBTree2();
							cout<<endl;
						}
						else cout<<"删除失败！"<<endl;
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;

					//打印二叉排序树
				case 4:
					if(Flag1==1)
					{
						cout<<"二叉排序树（竖着）："<<endl;
						BT.PrintSBTree();
						cout<<endl;
						cout<<endl;
						cout<<"二叉排序树（横着）："<<endl;
						BT.PrintSBTree2();
						cout<<endl;
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;

					//注销二叉排序树
				case 5:
					if(Flag1==1)
					{
						if(BT.DeleteAll())
						{
							cout<<"注销成功！"<<endl;
							Flag1=0;            //二叉排序树已注销,故不存在二叉排序树
						}
						else cout<<"注销失败！"<<endl;
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;


					//对二叉排序树进行非递归遍历
				case 6:
					if(Flag1==1)
					{
						int Count;
						cout<<"请选择遍历类型（前序(1),中序(2),后序(3)）:";
						while(true)
						{
							cin>>Count;
							if(Count==1 || Count==2 || Count==3) break;
							else cout<<"输入错误，请重新输入：";
						}
						if(1==Count) BT.preOrder(putnum);
						else if(2==Count) BT.inOrder(putnum);
						else BT.postOrder(putnum);
						cout<<endl;
						BT.PrintSBTree2();
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;


					//进行数组和二叉树查找效率实验
				case 7:
					for(int i=0;i<5;i++)
					    CompareEfficency();
					cout<<endl;
					break;

				case 0:
					cout<<"已退出！"<<endl;
					goto End;
					break;
				}
				cout<<"需要选择的操作为：";
				cin>>number;
			}
		}


		//数据类型为字符型
		else if(Flag2=2)
		{
			SortBTree<char> BT;
			int amount;                      //输入数据的个数
			char p[50];                        //储存输入的数据
			memset(p,'\0',sizeof(p));
			while(true)
			{
				switch(number)
				{
					//创建二叉排序树
				case 1:
					if(Flag1==1)
					{
						cout<<"已存在二叉排序树！"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
						break;
					}
					cout<<"请输入创建二叉排序树的数据个数：";
					cin>>amount;
					cout<<"请输入"<<amount<<"个数据(整型):";
					for(int i=0;i<amount;i++)
						cin>>p[i];
					if(BT.CreateSBT(p,amount))
					{
						cout<<"创建成功！"<<endl;
						BT.PrintSBTree2();
						cout<<endl;
					    Flag1=1;                      //已生成二叉排序树   
					}
					else cout<<"创建失败！请重新创建！"<<endl;
					break;

					//插入数据
				case 2:
					if(Flag1==1)
					{
						char Count;
					    cout<<"请输入需要插入的数据：";
					    cin>>Count;
					    if(BT.InputSBT(Count))
						{
							cout<<"插入成功！"<<endl;
							BT.PrintSBTree2();
							cout<<endl;
						}
					    else cout<<"插入失败！"<<endl;
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;


					//删除数据
				case 3:
					if(Flag1==1)
					{
						char Count;
						cout<<"请输入要删除的数据：";
						cin>>Count;
						if(BT.RemoveSBT(Count))
						{
							cout<<"删除成功！"<<endl;
							BT.PrintSBTree2();
							cout<<endl;
						}
						else cout<<"删除失败！"<<endl;
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;

					//打印二叉排序树
				case 4:
					if(Flag1==1)
					{
						cout<<"二叉排序树（竖着）："<<endl;
						BT.PrintSBTree();
						cout<<endl;
						cout<<endl;
						cout<<"二叉排序树（横着）："<<endl;
						BT.PrintSBTree2();
						cout<<endl;
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;

					//注销二叉排序树
				case 5:
					if(Flag1==1)
					{
						if(BT.DeleteAll())
						{
							cout<<"注销成功！"<<endl;
							Flag1=0;
						}
						else cout<<"注销失败！"<<endl;
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;


					//对二叉排序树进行非递归遍历
				case 6:
					if(Flag1==1)
					{
						int Count;
						cout<<"请选择遍历类型（前序(1),中序(2),后序(3)）:";
						while(true)
						{
							cin>>Count;
							if(Count==1 || Count==2 || Count==3) break;
							else cout<<"输入错误，请重新输入：";
						}
						if(1==Count) BT.preOrder(putnum);
						else if(2==Count) BT.inOrder(putnum);
						else BT.postOrder(putnum);
						cout<<endl;
						BT.PrintSBTree2();
					}
					else cout<<"不存在二叉排序树或已注销！请重新创建！"<<endl;
					break;


					//进行数组和二叉树查找效率实验
				case 7:
					for(int i=0;i<5;i++)
					    CompareEfficency();
					cout<<endl;
					break;

				case 0:
					cout<<"已退出！"<<endl;
					goto End;
					break;
				}
				cout<<"需要选择的操作为：";
				cin>>number;
			}
		}
     End:
		{
			char ch;
			cout<<"是否继续程序（是(y),否(n)）：";
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