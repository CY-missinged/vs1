#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
#include <string.h>
#include <windows.h>
using namespace std;
int m = 0;
#define MAX 100
class people
{
private:
public:
    int flag;
    char num[10];
    char name[10];
    double score[10];
    double totalscore;
    double averagescore;
    people();
    void shuchu();
    double getmax();
    double getmin();
    ~people();
};
double people::getmax()
{
    double max = score[0];
    for (int i = 0; i < 10; i++)
    {
        if (max < score[i])
            max = score[i];
    }
    return max;
}
double people::getmin()
{
    double min = score[0];
    for (int i = 0; i < 10; i++)
    {
        if (min > score[i])
            min = score[i];
    }
    return min;
}
void people::shuchu()
{
    cout << " " << num << " " << name << "   " << totalscore << "      " << averagescore << endl;
}
people::people()
{
    totalscore = 0;
    averagescore = 0;
    flag = 0;
    for (int i = 0; i < 10; i++)
    {
        score[i] = 0;
    }
}
people::~people() {}
void shuru(people *peo)
{
    int n;
    cout << "***************************" << endl;
    cout << "******������ѡ�ָ���******" << endl;
    cout << "***************************" << endl;
    cin >> n;
    ::m = n;
    system("cls");
    for (int i = 0; i < m; i++)
    {
        cout << "***************************" << endl;
        cout << "***������ѡ�ֱ�ź�����****" << endl;
        cout << "***************************" << endl;
        cin >> peo[i].num >> peo[i].name;
        system("cls");
        for (int j = 0; j < i; j++)
        {
            if (strcmp(peo[i].num, peo[j].num) == 0)
            {
                cout << "***************************" << endl;
                cout << "***��������ͬ��ŵ�ѡ��****" << endl;
                cout << "********����������*********" << endl;
                i--;
            }
        }
    }
    system("cls");
}
void shuchu1(people *peo)
{
    if (m == 0)
    {
        cout << "***************************" << endl;
        cout << "**��Ǹ����������ѡ����Ϣ***" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "***************************" << endl;
        cout << "���"
             << " "
             << "����"
             << " "
             << "�ܳɼ�"
             << " "
             << "ƽ���ɼ�" << endl;
        cout << "***************************" << endl;
        for (int i = 0; i < m; i++)
        {
            peo[i].shuchu();
        }
        system("pause");
        system("cls");
    }
}
void dafen(people *peo)
{
    double totalscore;
    if (m == 0)
    {
        cout << "***************************" << endl;
        cout << "**��Ǹ����������ѡ����Ϣ***" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if (peo[i].flag == 0)
            {
                peo[i].flag = 1;
                cout << "***************************" << endl;
                cout << "***����ίΪ" << peo[i].name << "���****" << endl;
                cout << "***************************" << endl;
                for (int j = 0; j < 10; j++)
                {
                    cout << "***************************" << endl;
                    cout << "***�������" << j + 1 << "����ί�Ĵ��***" << endl;
                    cout << "***************************" << endl;
                    cin >> peo[i].score[j];
                    system("cls");
                    peo[i].totalscore += peo[i].score[j];
                }
                totalscore = peo[i].totalscore - peo[i].getmax() - peo[i].getmin();
                peo[i].averagescore = totalscore / 8.0;
            }
            else
            {
                cout << peo[i].name << "�Ѵ����" << endl;
            }
        }
        system("pause");
        system("cls");
    }
}
void paixu(people *peo)
{
    int a, b = 0;
    people temp;
    if (m == 0)
    {
        cout << "***************************" << endl;
        cout << "**��Ǹ����������ѡ����Ϣ***" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        for (int k = 0; k < m; k++)
        {
            if (peo[k].flag == 0)
                b++;
        }
        if (b != 0) // ��δ��ֵ�ѡ��
        {
            cout << "***************************" << endl;
            cout << "*��ѡ��û�гɼ�����������**" << endl;
            cout << "***************************" << endl;
            system("pause");
            system("cls");
        }
        else
        {
            cout << "***************************" << endl;
            cout << "***1.��ƽ���ɼ���������****" << endl;
            cout << "***2.��ƽ���ɼ���������****" << endl;
            cout << "***************************" << endl;
            cout << "******���������ѡ��*******" << endl;
            cout << "***************************" << endl;
            cin >> a;
            system("cls");
            if (a == 1)
            {
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < m; j++)
                    {
                        if (peo[j].averagescore > peo[i].averagescore)
                        {
                            temp.averagescore = peo[i].averagescore;
                            peo[i].averagescore = peo[j].averagescore;
                            peo[j].averagescore = temp.averagescore;
                            strcpy(temp.num, peo[i].num);
                            strcpy(peo[i].num, peo[j].num);
                            strcpy(peo[j].num, temp.num);
                            temp.totalscore = peo[i].totalscore;
                            peo[i].totalscore = peo[j].totalscore;
                            peo[j].totalscore = temp.totalscore;
                            strcpy(temp.name, peo[i].name);
                            strcpy(peo[i].name, peo[j].name);
                            strcpy(peo[j].name, temp.name);
                        }
                    }
                cout << "***************************" << endl;
                cout << "���"
                     << " "
                     << "����"
                     << " "
                     << "�ܳɼ�"
                     << " "
                     << "ƽ���ɼ�" << endl;
                cout << "***************************" << endl;
                for (int i = 0; i < m; i++)
                {
                    peo[i].shuchu();
                }
                system("pause");
                system("cls");
            }
            else if (a == 2)
            {
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < m; j++)
                    {
                        if (peo[j].averagescore < peo[i].averagescore)
                        {
                            temp.averagescore = peo[i].averagescore;
                            peo[i].averagescore = peo[j].averagescore;
                            peo[j].averagescore = temp.averagescore;
                            strcpy(temp.num, peo[i].num);
                            strcpy(peo[i].num, peo[j].num);
                            strcpy(peo[j].num, temp.num);
                            temp.totalscore = peo[i].totalscore;
                            peo[i].totalscore = peo[j].totalscore;
                            peo[j].totalscore = temp.totalscore;
                            strcpy(temp.name, peo[i].name);
                            strcpy(peo[i].name, peo[j].name);
                            strcpy(peo[j].name, temp.name);
                        }
                    }
                cout << "***************************" << endl;
                cout << "���"
                     << " "
                     << "����"
                     << " "
                     << "�ܳɼ�"
                     << " "
                     << "ƽ���ɼ�" << endl;
                cout << "***************************" << endl;
                for (int i = 0; i < m; i++)
                {
                    peo[i].shuchu();
                }
                system("pause");
                system("cls");
            }
            else
            {
                cout << "***************************" << endl;
                cout << "*********�������**********" << endl;
                cout << "***************************" << endl;
                system("pause");
                system("cls");
            }
        }
    }
}
void zhuijia(people *peo)
{
    int n, mm;
    mm = m;
    if (m == 0)
    {
        cout << "***************************" << endl;
        cout << "**��Ǹ����������ѡ����Ϣ***" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "***************************" << endl;
        cout << "**������Ҫ׷�ӵ�ѡ�ָ���***" << endl;
        cout << "***************************" << endl;
        cin >> n;
        system("cls");
        ::m += n;
        for (int i = mm; i < m; i++)
        {
            cout << "***************************" << endl;
            cout << "***������ѡ�ֱ�ź�����****" << endl;
            cout << "***************************" << endl;
            cin >> peo[i].num >> peo[i].name;
            system("cls");
            for (int j = 0; j < mm; j++)
            {
                if (strcmp(peo[i].num, peo[j].num) == 0)
                {
                    cout << "***************************" << endl;
                    cout << "***��������ͬ��ŵ�ѡ��****" << endl;
                    cout << "********����������*********" << endl;
                    i--;
                }
            }
        }
        system("cls");
        cout << "***************************" << endl;
        cout << "*********׷�ӳɹ�**********" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
}
void Find(people *peo)
{
    int a, b = 0, c = 0;
    char numb[10], namee[10];
    if (m == 0)
    {
        cout << "***************************" << endl;
        cout << "**��Ǹ����������ѡ����Ϣ***" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "***************************" << endl;
        cout << "*******1.����Ų���********" << endl;
        cout << "*******2.����������********" << endl;
        cout << "***************************" << endl;
        cout << "******���������ѡ��*******" << endl;
        cout << "***************************" << endl;
        cin >> a;
        system("cls");
        if (a == 1)
        {
            cout << "***************************" << endl;
            cout << "****������Ҫ���ҵı��*****" << endl;
            cout << "***************************" << endl;
            cin >> numb;
            system("cls");
            cout << "***************************" << endl;
            cout << "���"
                 << " "
                 << "����"
                 << " "
                 << "�ܳɼ�"
                 << " "
                 << "ƽ���ɼ�" << endl;
            cout << "***************************" << endl;
            for (int i = 0; i < m; i++)
            {
                if (strcmp(numb, peo[i].num) == 0)
                {
                    peo[i].shuchu();
                    b++;
                }
            }
            if (b == 0)
            {
                cout << "********δ�ҵ�����*********" << endl;
                cout << "***************************" << endl;
            }
            system("pause");
            system("cls");
        }
        else if (a == 2)
        {
            cout << "***************************" << endl;
            cout << "****������Ҫ���ҵ�����*****" << endl;
            cout << "***************************" << endl;
            cin >> namee;
            system("cls");
            cout << "***************************" << endl;
            cout << "���"
                 << " "
                 << "����"
                 << " "
                 << "�ܳɼ�"
                 << " "
                 << "ƽ���ɼ�" << endl;
            cout << "***************************" << endl;
            for (int i = 0; i < m; i++)
            {
                if (strcmp(namee, peo[i].name) == 0)
                {
                    peo[i].shuchu();
                    c++;
                }
            }
            if (c == 0)
            {
                cout << "********δ�ҵ�����*********" << endl;
                cout << "***************************" << endl;
            }
            system("pause");
            system("cls");
        }
        else
        {
            cout << "***************************" << endl;
            cout << "*********�������**********" << endl;
            cout << "***************************" << endl;
            system("pause");
            system("cls");
        }
    }
}
void out(people *peo)
{
    if (m == 0)
    {
        cout << "***************************" << endl;
        cout << "**��Ǹ����������ѡ����Ϣ***" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        ofstream out("C:\\Users\\bdd\\Desktop\\��Ϣ.txt");
        if (out)
        {
            out << "���"
                << " "
                << "����"
                << " "
                << "�ܳɼ�"
                << " "
                << "ƽ���ɼ�" << endl;
            out.close();
        }
        for (int i = 0; i < m; i++)
        {
            ofstream out("C:\\Users\\bdd\\Desktop\\��Ϣ.txt", ios::app);
            if (out)
            {
                out << " " << peo[i].num << " " << peo[i].name << "   " << peo[i].totalscore << "      " << peo[i].averagescore << endl;
                out.close();
            }
        }
        cout << "***************************" << endl;
        cout << "*****���������ļ��ɹ�******" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
}
void in()
{
    if (m == 0)
    {
        cout << "***************************" << endl;
        cout << "**��Ǹ����������ѡ����Ϣ***" << endl;
        cout << "***************************" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        ifstream in;
        in.open("C:\\Users\\bdd\\Desktop\\��Ϣ.txt", ios::in);
        if (!in.is_open())
        {
            cout << "�޷��ҵ�����ļ���" << endl;
            return;
        }
        string buff;
        while (getline(in, buff))
        {
            cout << buff << endl;
        }
        in.close();
    }
    system("pause");
    system("cls");
}
int main()
{
    int n;
    people peo[MAX];
    while (1)
    {
        cout << "***************************" << endl;
        cout << "******1.����ѡ����Ϣ*******" << endl;
        cout << "******2.���ѡ����Ϣ*******" << endl;
        cout << "******3.��ί���    *******" << endl;
        cout << "******4.�ɼ�����    *******" << endl;
        cout << "******5.׷��ѡ����Ϣ*******" << endl;
        cout << "******6.����ѡ����Ϣ*******" << endl;
        cout << "******7.���������ļ�*******" << endl;
        cout << "******8.�鿴�����ļ�*******" << endl;
        cout << "******0.�˳�ϵͳ    *******" << endl;
        cout << "***************************" << endl;
        cin >> n;
        if (n < 0 || n > 8)
        {
            system("cls");
            cout << "***************************" << endl;
            cout << "***�����������������****" << endl;
            cout << "***************************" << endl;
            system("pause");
            system("cls");
            continue;
        }
        switch (n)
        {
        case 1:
            system("cls");
            shuru(peo);
            break;
        case 2:
            system("cls");
            shuchu1(peo);
            break;
        case 3:
            system("cls");
            dafen(peo);
            break;
        case 4:
            system("cls");
            paixu(peo);
            break;
        case 5:
            system("cls");
            zhuijia(peo);
            break;
        case 6:
            system("cls");
            Find(peo);
            break;
        case 7:
            system("cls");
            out(peo);
            break;
        case 8:
            system("cls");
            in();
            break;
        case 0:
            system("cls");
            return 0;
            break;
        }
    }

    return 0;
}
