#pragma once
/* Ϊ֮ǰ�����String���еĿ������캯���Ϳ�����ֵ���������һ�����
	��ÿ�κ���ִ��ʱ��ӡһ����Ϣ��
*/
#include<memory>

class String {
public:
	String() : String("") {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }

	const char* c_str() const { return elements; }

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const  char*);
	void range_initialize(const char*, const char*);
	void free();


private:
	char* elements;
	char* end;
	std::allocator<char> alloc;
};