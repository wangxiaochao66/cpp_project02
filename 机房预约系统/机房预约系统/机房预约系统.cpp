#include<iostream>
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

//����ѧ���Ӳ˵�����
/*        
1.����ԤԼ 
2.�鿴�ҵ�ԤԼ 
3.�鿴����ԤԼ
4.ȡ��ԤԼ 
0.ע����¼ 
*/
//����LoginIn()�� person Ϊ����Identity *  �������������Identity *������
void studentMenu(Identity*  &student)   //&��ȡ��
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Student * stu = (Student *)student;

		int select = 0;
		cin >> select;//�����û�ѡ��

		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			//ע����¼ 
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�����
/*
1.�鿴����ԤԼ
2.���ԤԼ
0.ע����¼
*/
void teacherMenu(Identity * &teacher)//&��ȡ��
{
	while (true)
	{
		//���ý�ʦ�Ӳ˵�
		teacher->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Teacher *tea = (Teacher *)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			tea->showAllOrder();//��ʾ����ԤԼ
		}
		else if (select == 2)
		{
			tea->validOrder();//���ԤԼ
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//�������Ա�Ӳ˵�����
/*
1.����˺�
2.�鿴�˺�
3.�鿴����
4.���ԤԼ
0.ע����¼
*/
void managerMenu(Identity * &manager)//&��ȡ��
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		//manager�Ǹ����µ�  ��תΪManager���µ�
		Manager * man =(Manager*) manager;//

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1)//����˻�
		{
			man->addPerson();
		}
		else if (select == 2)//�鿴�˻�
		{
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			man->cleanFile();
		}
		else 
		{
			//ע��
			delete manager;//���ٶ�������
			cout << "ע���ɹ�"<< endl;
			system("pause");
			system("cls");
			return;
		}

	}
}


//��¼����  ����1 �����ļ��� ����2 �����������
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ���������
	Identity *person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������"<< endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;	//����
	string pwd;		//����

	//�ж���� �Ƿ�Ϊѧ��������ʦ  ����Աû��id
	if (type == 1)//ѧ��
	{
		cout << "���������ѧ�ţ�"<< endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;      //���ļ��ж�ȡ��ID��
		string fName; //���ļ��ж�ȡ������
		string fPwd;  //���ļ��ж�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)//һ��һ�еĶ�ȡÿ������
		{
			//cout << fId << "  " << fName << "  " << fPwd << "  " << endl;
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);//person Ϊѧ����
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//��ʦѧ����֤
		int fId; //���ļ��л�ȡ��id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);//person Ϊ��ʦ��
				//�����ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName; //���ļ��л�ȡ����
		string fPwd; //���ļ��л�ȡ����

		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);//person Ϊ����Ա��

				//�������Ա�Ӳ˵�����
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;

}


int main()
{
	int select = 0;//�����û���ѡ��

	while (true)
	{
		cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�����û�ѡ��

		switch(select)
		{
			case 1:	//ѧ�����
				LoginIn(STUDENT_FILE,1);
				break;
			case 2:	//��ʦ���
				LoginIn(TEACHER_FILE, 2);
				break;
			case 3:	//����Ա���
				LoginIn(ADMIN_FILE, 3);
				break;
			case 0: //�˳�ϵͳ
				cout << "��ӭ��һ��ʹ��" << endl;
				system("pause");
				return 0;//�˳�
			default:
				cout << "��������������ѡ��" << endl;
				system("pause");
				system("cls");
				break;
		}
	}

	system("pause");
	return 0;
}