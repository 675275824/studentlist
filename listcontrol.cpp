#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
struct Student
{
	string name;
	string password;
	string schoolID;
	string grade;
	int  student_class[5] = { 0 };
	int classes;
	Student *next;
}*student_head, *s_wordhead;
struct Teacher
{
	string name;
	string password;
	string teachclass;
	int classspace;
	string place;
	Teacher *next;
}*teacher_head, *t_wordhead;
int Student_number = 0, Teacher_number = 0;

void regis();
void Login();
void Student_Login();
void Teacher_Login();
void Student_Menu();
void Teacher_Menu();
void Student_Select();
void Student_Show();
void Student_Delete();
void Student_Change();
void Teacher_Show();
void Teacher_Add();
void Teacher_Delete();
void Teacher_Change();

void regis()
{
	//从文件中恢复数据
	int i = 0, j = 0, m = 0, n = 0;
	ifstream file1("student.txt", ios::in);
	ifstream file2("teacher.txt", ios::in);
	string s_id[100], s_pass[100],s_name[100],s_grade[100];
	int s_class[5], t_clasespace[100];
	string t_place[100],t_class[100],t_name[100];
	while (file1 >> s_name[j]>> s_grade[j]>> s_id[i] >>s_class[0] >> s_class[1] >> s_class[2] >> s_class[3] >> s_class[4])
	{
		i++;
	}
	while (file2 >>t_name[j]>> t_class[j] >> t_clasespace[j] >> t_place[0] ) 
	{
		j++;
	}
	file1.close();
	file2.close();
	Student_number = i;
	Teacher_number = j;
	student_head = NULL;
	teacher_head = NULL;
	int f = 1;
	Student *q;
	while (n<i)
	{
		Student *p = new Student;
		p->next = NULL;
		p->schoolID = s_id[n];
		p->name = s_name[n];
		p->grade = s_grade[n];
		for (int i = 0; i < 5; i++)
		{
			p->student_class[i] = s_class[i];
		}
		if (student_head == NULL)
			student_head = p;
		else
			q->next = p;
		q = p;
		n++;
	}
	Teacher *t;
	while (m<j)
	{
		Teacher *p = new Teacher;
		p->next = NULL;
		p->name = t_name[m];
		p->classspace = t_clasespace[m];
		p->teachclass = t_class[m];
		p->place = t_place[m];
		if (t_wordhead== NULL)
			t_wordhead = p;
		else
			t->next = p;
		t = p;
		m++;
	}
	string s;
	string identity;
	cout << "*******【欢迎进入学生选课系统】*******" << endl;
	cout << "      注册：                          " << endl;
	cout << "            学生（student）           " << endl;
	cout << "            教师（teacher）           " << endl;
	cout << "      登录:                           " << endl;
	cout << "            Login                     " << endl;
	cout << "**************************************" << endl;
	cout << "选择您要进行的方式：";
	ofstream file3("student.txt", ios::app);
	ofstream file4("teacher.txt", ios::app);
	ofstream file5("studentpassword.txt", ios::app);
	ofstream file6("teacherpassword.txt", ios::app);
	if (!file3)
	{
		cout << "file could not be open" << endl;
		abort();
	}
	while (cin >> identity)
	{
		if (identity == "student")
		{
			Student_number++;
			Student *student = new Student;
			student->next = NULL;
			q = student;
			cout << "               学生注册：             " << endl;
			cout << "**************************************" << endl;
			cout << "姓名："; cin >> student->name; cout << endl;
			file3 << student->name << " ";
			cout << "年级："; cin >> student->grade; cout << endl;
			file3 << student->grade << " ";
			cout << "学号："; cin >> student->schoolID; cout << endl;
			file3 << student->schoolID;
			file5 << student->schoolID << " ";
			cout << "密码：";
			char ch;
			while ((ch = _getch()) != 13)
			{
				student->password += ch;
				cout << "*";
			}
			for (int k = 0; k < 5; k++)
				file3 << " " << student->student_class[k];
			file3 << endl;
			cout << endl;
			file5 << student->password << endl;
			file3.close();
			file5.close();
			system("Cls");
			Login();
		}
		else if (identity == "teacher")
		{
			Teacher_number++;
			Teacher *teacher = new Teacher;
			teacher->next = NULL;
			t = teacher;
			cout << "               老师注册：             " << endl;
			cout << "**************************************" << endl;
			cout << "姓名："; cin >> teacher->name; cout << endl;
			file4 << teacher->name << " ";
			file6 << teacher->name << " ";
			cout << "授课："; cin >> teacher->teachclass; cout << endl;
			file4 << teacher->teachclass << " ";
			cout << "授课地点："; cin >> teacher->place; cout << endl;
			file4 << teacher->place << " ";
			cout << "课程容量："; cin >> teacher->classspace; cout << endl;
			file4 << teacher->classspace << endl;
			cout << "密码：";
			char ch;
			while ((ch = _getch()) != 13)
			{
				teacher->password += ch;
				cout << "*";
			}
			cout << endl;
			file6 << teacher->password << endl;
			file4.close();
			file6.close();
			system("Cls");
			Login();
		}
		else if (identity == "Login")
		{
			system("Cls");
			Login();
		}
		else
		{
			cout << "身份识别错误" << endl;
			continue;
		}
	}

}

void Login()
{

	cout << "**********【学生选课系统】************" << endl;
	cout << "                                      " << endl;
	cout << "            1  学生端                 " << endl;
	cout << "            2  教师端                 " << endl;
	cout << "                                      " << endl;
	cout << "**************************************" << endl;
	int n;
reset:cin >> n;
	if (n == 1)
	{
		system("Cls");
		Student_Login();
	}
	else if (n == 2)
	{
		system("Cls");
		Teacher_Login();
	}
	else
	{
		cout << "您的指令输入错误，请重新输入：" << endl;
		goto reset;
	}
}

void Teacher_Login()
{
	int n = 0;
	ifstream file1("teacherpassword.txt", ios::in);
	t_wordhead = NULL;
	string t_id, t_pass;
	Teacher *q=teacher_head;
	while (file1 >> t_id >> t_pass)
	{
		Teacher *p = new Teacher;
		p->next = NULL;
		p->name = t_id;
		p->password = t_pass;
		if (t_wordhead == NULL)
			t_wordhead = p;
		else
			q->next = p;
		q = p;
	}
	string id, pass;
reint:
	cout << "****************老师登录**************" << endl;
	cout << "姓名：";
	cin >> id;
	cout << "密码：";
	char ch;
	while ((ch = _getch()) != 13)
	{
		pass += ch;
		cout << "*";
	}
	cout << endl;
	cout << "**************************************" << endl;

	Teacher *t;
	t = t_wordhead;
	int f = 0;
	while (t)
	{
		n++;
		if (t->name == id && t->password == pass)
		{
			f = 1;
			break;
		}
		else if (t->name == id && t->password == pass)
		{
			cout << "您输入的密码不对，请再次输入：" << endl;
			goto reint;
		}
		t = t->next;
	}
	if (f == 1)
	{
		file1.close();
		Teacher_number = n;
		Teacher_Menu();
	}
	if (f == 0)
	{
		cout << "您未注册，请注册。" << endl;
		file1.close();
		regis();
	}
}

void Student_Login()
{
	ifstream file1("studentpassword.txt", ios::in);
	s_wordhead = NULL;
	string s_id, s_pass;
	int i = 0;
	int n = 0;
	Student *q = s_wordhead;
	while (file1 >> s_id >> s_pass)
	{
		Student *p = new Student;
		p->next = NULL;
		p->schoolID = s_id;
		p->password = s_pass;
		if (s_wordhead == NULL)
			s_wordhead = p;
		else
			q->next = p;
		q = p;
	}
	string id, pass;
	cout << "****************学生登录**************" << endl;
	cout << "学号：";
	cin >> id;
reins:
	pass = "\0";
	cout << "密码：";
	char ch;
	while ((ch = _getch()) != 13)
	{
		pass += ch;
		cout << "*";
	}
	cout << endl;
	cout << "**************************************" << endl;
	Student *t;
	t = s_wordhead;
	int f = 0;
	while (t)
	{
		n++;
		if (t->schoolID == id && t->password == pass)
		{
			f = 1;
			break;
		}
		else if (t->schoolID == id && t->password != pass)
		{
			cout << "您输入的密码不对，请再次输入：" << endl;
			goto reins;
		}
		t = t->next;
	}
	if (f == 1)
	{
		Student_number = n;
		file1.close();
		Student_Menu();
	}
	if (f == 0)
	{
		cout << "您未注册，请注册。" << endl;
		file1.close();
		regis();
	}
}

void Teacher_Menu()
{
	cout << "********************************" << endl;
	cout << "                                " << endl;
	cout << "          1 查看全部学生信息    " << endl;
	cout << "          2 增加学生            " << endl;
	cout << "          3 删除学生            " << endl;
	cout << "          4 修改密码            " << endl;
	cout << "          5  退出               " << endl;
	cout << "                                " << endl;
	cout << "********************************" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		Teacher_Show();
	}
	else if (n == 2)
	{
		Teacher_Add();
	}
	else if (n == 3)
	{
		Teacher_Delete();
	}
	else if (n == 4)
	{
		Teacher_Change();
	}
	else if (n == 5)
	{
		system("Cls");
		regis();
	}
	else
	{
		cout << "指令输入错误，请重新输入。" << endl;
		Teacher_Menu();
	}
}

void Teacher_Show()
{
	Student *p;
	int i;
	int time = 2;
	p= student_head;
	while (p)
	{
		cout << "姓名：";
		cout << p->name<<" ";
		cout << "年级：";
		cout << p->grade<<" ";
		cout << "学号：";
		cout << p->schoolID << endl;
		cout << "所选课程：";
		for (i = 0; i < 5; i++)
		{
			if (p->student_class[i] == 1)
				cout << "高等数学" << " ";
			else if (p->student_class[i] == 2)
				cout << "程序设计基础" << " ";
			else if (p->student_class[i] == 3)
				cout << "数字逻辑" << " ";
			else if (p->student_class[i] == 4)
				cout << "英语" << " ";
			else if (p->student_class[i] == 5)
				cout << "体育" << " ";
		}
		p = p->next;
	}
	cout << "是否返回主菜单？（yes/no）" << endl;
	string c;
	cin >> c;
	if (c == "yes")
		Teacher_Menu();
	else
	{
		Sleep(1000 * time);
		Teacher_Menu();
	}
}

void Teacher_Add()
{
	Student *p = new Student;
	cout << "            所要添加学生的信息：      " << endl;
	cout << "**************************************" << endl;
	cout << "姓名：";
	cin >> p->name;
	cout << "年级：";
	cin >> p->grade;
	cout << "学号：";
	cin >> p->schoolID;
	cout << "密码：";
	p->next = NULL;
	char ch;
	while ((ch = _getch()) != 13)
	{
		p->password += ch;
		cout << "*";
	}
	cout << endl;
	ofstream file("student.txt", ios::app);
	file << p->name << " " << p->grade << " " << p->schoolID;
	for (int i = 0; i < 5; i++)
	{
		file << " " << p->student_class[i];
	}
	file << endl;
	file.close();
	ofstream file1("studentpassword.txt", ios::app);
	file1 << p->schoolID << " " << p->password << endl;
	file1.close();
	int time = 2;
	cout << "返回主界面中。。。。。。" << endl;
	Sleep(time * 1000);
	system("Cls");
	Teacher_Menu();

}

void Teacher_Delete() 
{
	int number=0;
	string n;
	cout << "请输入你要删除的学号：";
	cin >> n;
	Student *p,*q,*t,*r;
	string s;
	p = student_head;
	q = student_head->next;
	t = s_wordhead;
	r = s_wordhead->next;
	int f = 0;
	int k = 0,m=0;
	while (q)
	{
		k++;
		if (q->schoolID == n)
		{
			number = k;
			f = 1;
			p->next = q->next;
			while (r)
			{
				m++;
				if (m == number)
				{
					t->next = r->next;
					break;
				}
				r = r->next;
				t = t->next;
			}
			break;
		}
		q = q->next;
		p = p->next;
	}
	if (f == 1)
	{
		cout << "删除成功！" << endl;
		cout << "是否继续删除?" << endl;
		cin >> s;
		if (s == "yes")
			Teacher_Delete();
		else
		{
			ofstream file1("student.txt", ios::out);
			ofstream file2("studentpassword.txt", ios::out);
			Student *student, *pass;
			student = student_head;
			pass = s_wordhead;
			while (student)
			{
				file1 << student->name << " " << student->grade << " " << student->schoolID << " " << student->student_class[0]
					<< " " << student->student_class[1] << " " << student->student_class[2] << " " << student->student_class[3]
					<< " " << student->student_class[4] << endl;
				student = student->next;
			}
			while (pass)
			{
				file2 << pass->schoolID << " " << pass->password;
				pass = pass->next;
			}
			file1.close();
			file2.close();
			Teacher_Menu();
		}
	}
}

void Teacher_Change()
{
	Teacher *p = new Teacher;
	int number = 0;
	p = t_wordhead;
	string newpass1, newpass2;
	while (p)
	{
		number++;
		if (number == Teacher_number)
		{
			cout << "新密码：";
			char ch;
			while ((ch = _getch()) != 13)
			{
				newpass1 += ch;
				cout << "*";
			}
			cout << endl;
			cout << "再次输入：";
			while ((ch = _getch()) != 13)
			{
				newpass2 += ch;
				cout << "*";
			}
			cout << endl;
			if (newpass1 == newpass2)
			{
				p->password = newpass1;
				cout << "修改成功！" << endl;
				break;
			}
			else
			{
				cout << "两次输入不一致！" << endl;
				Teacher_Change();
			}
		}
		p = p->next;
	}
	Teacher *t;
	t = t_wordhead;
	ofstream file("studentpassword.txt", ios::out);
	while (t)
	{
		file << t->name << " " << t->password << endl;
		t = t->next;
	}
	Teacher_Menu();

}

void Student_Menu()
{
	cout << "********************************" << endl;
	cout << "                                " << endl;
	cout << "            1 开始选课          " << endl;
	cout << "            2 查看选课情况      " << endl;
	cout << "            3 退课              " << endl;
	cout << "            4 修改密码          " << endl;
	cout << "            5 退出系统          " << endl;
	cout << "                                " << endl;
	cout << "********************************" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		Student_Select();
	}
	else if (n == 2)
	{
		Student_Show();
	}
	else if (n == 3)
	{
		Student_Delete();
	}
	else if (n == 4)
	{
		Student_Change();
	}
	else if (n == 5)
	{
		regis();
	}
	else
	{
		cout << "指令输入错误！重新输入：" << endl;
		system("Cls");
		Student_Menu();
	}
}

void Student_Select()
{
	string name, id, grade;
	int time = 2;
	int n, number = 0;
	int i;
	int classes[5];
	ifstream file1("student.txt", ios::in);
	student_head = NULL;
	Student *q;
	while (file1 >> name >> grade >> id >> classes[0] >> classes[1] >> classes[2] >> classes[3] >> classes[4])
	{
		Student *p = new Student;
		p->next = NULL;
		p->name = name;
		p->grade = grade;
		p->schoolID = id;
		for (int k = 0; k < 5; k++)
			p->student_class[k] = classes[k];
		if (student_head == NULL)
			student_head = p;
		else
			q->next = p;
		q = p;
	}
	file1.close();
	cout << "**************************************" << endl;
	cout << "             1.高等数学               " << endl;;
	cout << "             2.程序设计基础           " << endl;
	cout << "             3.数字逻辑               " << endl;
	cout << "             4.英语                   " << endl;
	cout << "             5.体育                   " << endl;
	cout << "**************************************" << endl;
	cout << "请输入你要选的课程：" << endl;
select:
	number = 0;
	cin >> n;
	Student *cla;
	cla = student_head;
	while (cla)
	{
		number++;
		if (number == Student_number)
		{
			for (i = 0; i < 5; i++)
			{
				if (cla->student_class[i] == 0)
				{
					cla->student_class[i] = n;
					break;
				}
				else if (cla->student_class[i] == n)
				{
					cout << "您已选择过这门课程，请重新选择。" << endl;
					goto select;
				}
			}
			if (i == 5)
			{
				cout << "您的课程已选满，不能再选。" << endl;
				Sleep(time * 1000);
			}
			break;
		}
		cla = cla->next;
	}
	cout << "是否继续选课？(yes/no)" << endl;
	string c;
	cin >> c;
	if (c == "yes")
		goto select;
	else if (c == "no")
	{
		ofstream file2("student.txt", ios::out);
		cla = student_head;
		while (cla)
		{
			file2 << cla->name << " " << cla->grade << " " << cla->schoolID << " " << cla->student_class[0] <<
				" " << cla->student_class[1] << " " << cla->student_class[2] << " " << cla->student_class[3]
				<< " " << cla->student_class[4] << endl;
			cla = cla->next;
		}
		file2.close();
		Student_Menu();
	}
	else
	{
		ofstream file3("student.txt", ios::out);
		cla = student_head;
		while (cla)
		{
			file3 << cla->name << " " << cla->grade << " " << cla->schoolID << " " << cla->student_class[0] <<
				" " << cla->student_class[1] << " " << cla->student_class[2] << " " << cla->student_class[3]
				<< " " << cla->student_class[4] << endl;
			cla = cla->next;
		}
		Sleep(time * 1000);
		file3.close();
		Student_Menu();
	}

}

void Student_Show()
{
	int number=0,i;
	int time = 2;
	Student *p = new Student;
	p = student_head;
	while (p)
	{
		number++;
		if (number == Student_number)
		{
			for (i = 0; i < 5; i++)
			{
				if (p->student_class[i] == 1)
					cout << "高等数学" << endl;
				else if (p->student_class[i] == 2)
					cout << "程序设计基础" << endl;
				else if (p->student_class[i] == 3)
					cout << "数字逻辑" << endl;
				else if (p->student_class[i] == 4)
					cout << "英语" << endl;
				else if (p->student_class[i] == 5)
					cout << "体育" << endl;
			}
		}
		p = p->next;
	}
	cout << "是否返回主菜单？（yes/no）" << endl;
	string c;
	cin >> c;
	if (c == "yes")
		Student_Menu();
	else
	{
		Sleep(1000 * time);
		Student_Menu();
	}
}

void Student_Delete()
{
	Student *p = new Student;
	p = student_head;
	int number = 0,n,i;
	int time = 2;
	string c;
	while (p)
	{
		number++;
		if (number == Student_number)
		{
			cout << "已选的课程有：" << endl;
			for (i = 0; i < 5; i++)
			{
				if (p->student_class[i] == 1)
					cout << "高等数学" << endl;
				else if (p->student_class[i] == 2)
					cout << "程序设计基础" << endl;
				else if (p->student_class[i] == 3)
					cout << "数字逻辑" << endl;
				else if (p->student_class[i] == 4)
					cout << "英语" << endl;
				else if (p->student_class[i] == 5)
					cout << "体育" << endl;
			}
			cout << "请选择要退的课程：" << endl;
			cout << "**************************************" << endl;
			cout << "             1.高等数学               " << endl;;
			cout << "             2.程序设计基础           " << endl;
			cout << "             3.数字逻辑               " << endl;
			cout << "             4.英语                   " << endl;
			cout << "             5.体育                   " << endl;
			cout << "**************************************" << endl;
		deletec:
			cin >> n;
			for (i = 0; i < 5; i++)
			{
				if (p->student_class[i] == n)
				{
					p->student_class[i] = 0;
					break;
				}
			}
			if (i == 5)
			{
				cout << "您没有要退的课，请先选课。" << endl;
				Student_Menu();
			}
			cout << "是否继续退课？" << endl;
				if (c == "yes")
				{
					goto deletec;
				}
				else if(c=="no")
				{
					Sleep(time * 1000);
					system("Cls");
					Student_Menu();
				}
				else
				{
					Sleep(time * 1000);
					system("Cls");
					Student_Menu();
				}
		}
		p = p->next;
	}
}

void  Student_Change()
{
	Student *p = new Student;
	int number=0;
	p = s_wordhead;
	string newpass1,newpass2;
	while (p)
	{
		number++;
		if (number == Student_number)
		{
			cout << "新密码：";
			char ch;
			while ((ch = _getch()) != 13)
			{
				newpass1 += ch;
				cout << "*";
			}
			cout << endl;
			cout << "再次输入：";
			while ((ch = _getch()) != 13)
			{
				newpass2 += ch;
				cout << "*";
			}
			cout << endl;
			if (newpass1 == newpass2)
			{
				p->password = newpass1;
				cout << "修改成功！" << endl;
				break;
			}
			else
			{
				cout << "两次输入不一致！" << endl;
				Student_Change();
			}
		}
		p = p->next;
	}
	Student *t;
	t = s_wordhead;
	ofstream file("studentpassword.txt", ios::out); 
	while (t)
	{
		file << t->schoolID << " " << t->password << endl;
		t = t->next;
	}
	Student_Menu();
}
int main()
{
	regis();
}
