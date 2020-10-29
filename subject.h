#pragma once
#include <time.h>
using namespace std;

class Subject
{
public:
	Subject() {}
	virtual void method() = 0;
};

class RealSubject :public Subject
{
public:
	RealSubject() {}
	void method() {
		printf("����ҵ�񷽷�\n");
	}
};

class Log
{
public:
	Log() {}
	string getTime() {
		time_t t = time(NULL);
		char ch[64] = { 0 };
		//��-��-�� ʱ:��:��
		//strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%m:%S", localtime(&t));
		//strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%m:%S", localtime(&t));
		return ch;
	}
};

// ������
class Proxy :public Subject
{
public:
	Proxy() {
		realSubject = new RealSubject();
		log = new Log();
	}
	void preCallMethod() {
		printf("����method()�����ã�����ʱ��Ϊ%s\n", log->getTime().c_str());
	}
	void method() {
		preCallMethod();
		realSubject->method();
		postCallMethod();
	}
	void postCallMethod() {
		printf("����method()���õ��óɹ�!\n");
	}
private:
	RealSubject* realSubject;
	Log* log;
};
