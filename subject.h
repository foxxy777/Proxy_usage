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
		printf("调用业务方法\n");
	}
};

class Log
{
public:
	Log() {}
	string getTime() {
		time_t t = time(NULL);
		char ch[64] = { 0 };
		//年-月-日 时:分:秒
		//strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%M:%S", localtime(&t));
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%m:%S", localtime(&t));
		//strftime(ch, sizeof(ch) - 1, "%Y-%m-%d %H:%m:%S", localtime(&t));
		return ch;
	}
};

// 代理类
class Proxy :public Subject
{
public:
	Proxy() {
		realSubject = new RealSubject();
		log = new Log();
	}
	void preCallMethod() {
		printf("方法method()被调用，调用时间为%s\n", log->getTime().c_str());
	}
	void method() {
		preCallMethod();
		realSubject->method();
		postCallMethod();
	}
	void postCallMethod() {
		printf("方法method()调用调用成功!\n");
	}
private:
	RealSubject* realSubject;
	Log* log;
};
