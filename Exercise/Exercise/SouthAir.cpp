
#include"southair.h"



using namespace std;
//������
/*
��������������� 1 �������� x �� y��x ���˱������������֮�͵��� y��y ���˱��������
����֮�͵��� x����� x �� y ��һ����������
���� 220 ���˱������������֮�� 110+55+44+22+20+11+10+5+4+2+1=284���� 284 ����
�������������֮�� 142+71+4+2+1=220���� 220 �� 284 ����һ����������
�����дһ��������� x �� y �ֱ���˱������������֮�ͣ����ж� x �� y �ǲ���һ������
����x �� y Ϊ���� 1 �� int ��Χ�ڵ�������
�롿x �� y���ո������
�������
��һ����� x��һ�����ţ�x �ĳ��˱������������֮�͵ļ�����̣������⣬Ҫ�������
ÿ�����ӣ� ����Ҫ�ж���Ŀո�
�ڶ������ y��һ�����ţ�y �ĳ��˱������������֮�͵ļ�����̣������⣬Ҫ�������
ÿ�����ӣ� ����Ҫ�ж���Ŀո�
�����У���� x �� y ��һ����������� 1��������� 0����ĩ���п��п��ޡ�
*/
void KinsfolkNumber(int num, int num1)
{
	int a = num / 2;
	int num_re = 0;
	int num1_re = 0;
	while (a>0)
	{
		if ((num%a) == 0)
		{
			printf("%d+", a);
			num_re += a;
		}
		--a;
	}

	printf("\n");

	a = num1 / 2;
	while (a>0)
	{
		if ((num1%a) == 0)
		{
			printf("%d+", a);
			num1_re += a;
		}
		--a;
	}

	printf("\n");


	if (num == num1_re&&num1 == num_re)
	{
		printf("��������\n");
	}



}
//����λ��
struct _coord {
	unsigned int x;//x��λ��
	unsigned int y;//y��λ��
};
typedef struct _coord Coord;
//����
struct _form {
	Coord LCoord;//���½�����
	Coord RCoord;//���Ͻ�����
	int OrderId;//���ڱ��
	int Rank;
};
typedef struct _form MyForm;

//ģ�ⴰ�ڵ��
/*
�������ڵ��ģ��
�����⡿
�ڼ������Ļ�ϣ��� N �����ڡ����ڵı߽��ϵĵ�Ҳ���ڸô��ڡ�����֮���в�ε�����
�ڶ���һ�������ص��������ֻ����ʾλ�ڶ���Ĵ���������ݡ������������ĳ����
��ʱ�������ڴ����ڣ����ѡ���˴��ڱ����λ����������㴰�ڣ�����������ھͻ�
���Ƶ����д��ڵĶ��㣬��ʣ��Ĵ��ڵĲ��˳�򲻱䣬���������λ�ò������κδ���
������ͻ��������ε������дһ������ģ�������ڵĹ��̣��ȴӱ�׼������봰�ڵ�
���������ڱ�ź�λ�ã��Դ��ڵ����ϽǺ����½ǵ������ʾ��������Ĵ��ڲ�θߣ� ��Ȼ��
3
�������Ĵ�����λ�� ���Ե���������ʾ�� �� ��д������þ������������Ĵ��ڵ��Ŵ���
�����衿 ��
1����Ļ���½���Ϊ X ��� Y ������ԭ�㣬������Ϊ��0��0�� ���������������
��ֵ�������������Ҷ����ڵ��� 0��С�ڵ��� 1000��
2�����ڵĵ��Ŵ���ʱ������������Ĵ��ڱ�ſ�ʼ��������������
3������Ĵ��ڸ������� 0 ����С�ڵ��� 10������������� 0 ����С�ڵ��� 20��
�����롿
��һ�д��ڸ��� n�������� n ��ÿ��һ�����ڵı�š����½����ꡢ���Ͻ����ꡣ
������һ�е������ k�������� k ��ÿ��һ��������ꡣ
�������
һ�� n �����֣���ʾ K �ε���󰴲�����еĴ�
*/
void SumulateFormsClick()
{
	int FormCount = 0;
	int i = 0;
	printf("���ڸ���\n");
	scanf("%d", &FormCount);
	printf("ÿ�����ڵı��,���½�����(x,y)�����Ͻ�����(x,y)�����Կո����֣�\n");
	MyForm* p_Forms = (MyForm*)calloc(FormCount, sizeof(MyForm));
	if (NULL == p_Forms)
	{
		return;
	}
	
#if 1 
	/*
	for ( i = 0; i < FormCount; ++i)
	{
		scanf("%d%d%d%d%d", &(p_Forms[i].OrderId), &(p_Forms[i].LCoord.x), &(p_Forms[i].LCoord.y), &(p_Forms[i].RCoord.x), &(p_Forms[i].RCoord.y));
		p_Forms[i].Rank=i;//Ȩ��
	}
	*/
	p_Forms[0].OrderId = 1, (p_Forms[0].LCoord.x = 4), p_Forms[0].LCoord.y = 7, p_Forms[0].RCoord.x = 19, p_Forms[0].RCoord.y = 17, p_Forms[0].Rank = 1;
	p_Forms[1].OrderId = 2, (p_Forms[2].LCoord.x = 9), p_Forms[2].LCoord.y = 1, p_Forms[2].RCoord.x = 20, p_Forms[2].RCoord.y = 10, p_Forms[2].Rank = 2;
	p_Forms[2].OrderId = 3, (p_Forms[1].LCoord.x = 12), p_Forms[1].LCoord.y = 4, p_Forms[1].RCoord.x = 13, p_Forms[1].RCoord.y = 3, p_Forms[1].Rank = 3;
	vector<MyForm> myforms;
	myforms.push_back(p_Forms[0]);
	myforms.push_back(p_Forms[1]);
	myforms.push_back(p_Forms[2]);
	/*
	for (i = 0; i < FormCount; ++i)
	{
		//int id= 0, lx = 0, ly = 0;
		printf("���%d ���½����꣺%d��%d ���½����꣺%d��%d\n", (p_Forms[i].OrderId), (p_Forms[i].LCoord.x), (p_Forms[i].LCoord.y), (p_Forms[i].RCoord.x), (p_Forms[i].RCoord.y));
	}
	*/
#endif//���ڸ���
#if 1 
	int ClickCount = 0;
	printf("�������\n");
	scanf("%d", &ClickCount);
	Coord* p_Coords = (Coord*)calloc(ClickCount, sizeof(Coord));

	for (i = 0; i < ClickCount; ++i)
	{
		printf("�����ˣ���ʣ%d��\n", ClickCount - i - 1);
		scanf("%d%d", &(p_Coords[i].x), &(p_Coords[i].y));
	}

#endif //�������
#if 1 

	MyForm top = p_Forms[FormCount - 1];

	vector<MyForm> vec;
	for (i = 0; i < ClickCount; ++i)
	{
		int formindex = 0;
		for (formindex; formindex < FormCount; ++formindex)
		{
			if (p_Coords[i].x >= p_Forms[formindex].LCoord.x&&p_Coords[i].y <= p_Forms[formindex].RCoord.y)
			{
				if (top.Rank == p_Forms[formindex].Rank)
				{
					printf("��%d����\n", top);
					return;
				}
				else
				{
					vec.push_back(p_Forms[formindex]);
				}
			}
		}
	}
	if (!vec.empty())
	{
		MyForm Backup = top;
		for (vector<MyForm>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			if (top.Rank < it->Rank)
			{
				top = *it;
			}
		}
		printf("��%d����\n", top.OrderId);
		

	}
	


#endif // 1 �жϵ����λ�ô����ĸ�����












	if (NULL != p_Forms)
	{
		free(p_Forms);
	}if (NULL != p_Coords)
	{
		free(p_Coords);
	}
}


int JieCheng(int n)
{
	int result = 1;
	while (n > 1)
	{
		result *= n;
		n--;
	}
	
	return result;
}


void JieChengNum(int num)
{
	int result = 0;
	if (num < 0)
	{
		return;
	}
	if(num % 10 != 0)
	{
		JieChengNum(num / 10);
	}
	if (num>0)
	{
		printf("%d! =%d  ", num%10, JieCheng(num%10));
	}
	
}


//�������
void PrintMatrix(size_t length, size_t width,char c)
{
	for (int i = 0; i < width; ++i)
	{
		int tmp = length;
		while (tmp)
		{
			printf("%c ", c);
			--tmp;
		}
		printf("\n");
	}



}




void BestLenSubString(char str[], char substr[])
{

}

//LCS��������������ַ���������Ӵ�������
char* LCS(char left[], char right[])
{
	//��ȡ���Ӵ��ĳ���,��ȡ���Ӵ��ĳ���
	int lenLeft = strlen(left), lenRight = strlen(right), k;
	//ע������Ҫд��char��,������int��,����������������ʱ���������
	//����c��¼������ƥ�����
	char*c = (char*)calloc(lenRight,sizeof(char)), *p;
	//int c[M][M]={0};//����c����Ϊһ����ά����ʱ
	int start, end, len, i, j;//start����������Ӵ�����ʼ�㣬end����������Ӵ�����ֹ��
	end = len = 0;//len��ʾ������Ӵ��ĳ���

	for (i = 0; i<lenLeft; i++) //��1��ǰ���Ƚ�
	{
		//��2�Ӻ���ǰ�Ƚ�,ΪʲôҪ�Ӻ���ǰ��?�ǰ�һά����c[ ]����ά��������,
		//���Ҫ��ǰ���,���Խ�c����Ϊһ����ά����c[M][M].������Ҫ����Ӧ����.
		// for(j=0;j<lenRight;j++)//��c����Ϊһ����ά����ʱ
		for (j = lenRight - 1; j >= 0; j--)
		{
			if (left[i] == right[j])//Ԫ�����ʱ
			{
				if (i == 0 || j == 0)
					c[j] = 1;//c[i][j]=1;
				else
				{
					c[j] = c[j - 1] + 1;//c[i][j]=c[i-1][j-1]+1;
				}
			}
			else
			{
				c[j] = 0;    //c[i][j]=0;
			}
				
			if (c[j] > len)   //if (c[i][j]>len)
			{
				len = c[j];   //len=c[i][j];
				end = j;
			}
		}
	}
	start = end - len + 1;

	//����p��¼������Ӵ�
	p = (char*)malloc(len + 1);
	for (i = start; i <= end; i++)
	{
		p[i - start] = right[i];
	}
	p[len] = '\0';
	return p;
}






void CompareStr(char str1[], char str2[])
{
	size_t s1len = strlen(str1);
	size_t s2len = strlen(str2);
	for (int i = 0; i < s1len; i++)
	{
		char* p = str2;
		while (*p)
		{
			if (*p == str1[i])
			{
				//std::cout << 1<<" ";
				printf("1 ");
			}
			else
			{
				printf("0 ");
			}
			++p;
		}
		std::cout << std::endl;
	}
	
}
































































































