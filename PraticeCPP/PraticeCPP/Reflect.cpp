

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<string>
#include<map>
#include<vector>

using namespace std;

typedef void * Object;
typedef Object(*CreatFunction)();

namespace Reflect
{
	class MReflect
	{

	public:
		
		~MReflect()
		{

		}
	static	void RegisterClass(string name, CreatFunction fun)//注册类
		{
			pair<string, CreatFunction> p(name, fun);

			m_creatfuns.insert(p);
		}
	static	Object GetInstanceByName(string name)//通过类名得到实例
		{
			if (m_creatfuns[name] == NULL)
			{
				return NULL;
			}
			return m_creatfuns[name]();
		}
	private:
		static	map<string, CreatFunction> m_creatfuns;
		MReflect()
		{

		}
		MReflect(const MReflect* re)
		{

		}
	};
}


int main(int argc, char* argv[])
{



	system("pause");
	return EXIT_SUCCESS;
}


