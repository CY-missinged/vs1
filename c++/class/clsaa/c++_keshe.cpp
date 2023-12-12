// encoding=GBK
// ��Ŀ���绰���벾����ϵͳ
// ����Ҫ�����һ���绰���벾����ϵͳ��ʵ�ֵĹ������£�
// ��1�����ӵ绰���룻
// ��2��ɾ���绰���룻
// ��3����ʾ�绰������Ϣ��
#include <direct.h>
// #include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <conio.h>
// #include <cstdio>
// #include <string>
using namespace std;

#define MAX 10

// ����Ա
class Manager
{
public:
    Manager() : m_people_total(0)
    {
        memset(password, 0, 20 * sizeof(password[0]));
        memset(m_people_a, 0, (MAX + 1) * sizeof(m_people_a[0]));
        memset(m_people_p, 0, (MAX + 1) * sizeof(m_people_p[0]));
    }
    void read_file();                                        // ��ȡ��Ϣ--����Ա���룬�û���Ϣ
    void updata_file();                                      // ������Ϣ--����Ա���룬�û���Ϣ
    int Get_total() { return m_people_total; }               // ��ȡע���û�����
    char *Get_account(const int i) { return m_people_a[i]; } // ��ȡ�û��˺�
    void new_people();                                       // ע���û��˺�
    int change_password();                                   // �޸Ĺ���Ա����
    int logon();                                             // ��¼����Աϵͳ
    int logon(char num1[], char num2[]);                     // ��¼�û�ϵͳ(�ȶ��˺�������)
    void delete_people();                                    // ɾ��ָ���û�
    void delete_people_all();                                // ɾ�������û�
    //
    void change_account_people(const int i, const char num[20]) { strcpy(m_people_a[i], num); }  // �޸�ָ���û��˺�
    void change_password_people(const int i, const char num[20]) { strcpy(m_people_p[i], num); } // �޸�ָ���û�����
private:
    int m_people_total;                                                  // �û�ע����
    char password[20], m_people_a[MAX + 1][20], m_people_p[MAX + 1][20]; // ����Ա���룬�û��˺ţ��û�����
};

// �绰��Ϣ
struct Data_people
{
    int sex, age;
    char name[20], num[30], address[30];
};

// �û�
class People : public Manager
{
public:
    People() : Data_total(0)
    {
        memset(account, 0, 20 * sizeof(account[0]));
        memset(data, 0, (MAX + 1) * sizeof(data[0]));
    }
    int logon(Manager *manager);                   // �û���¼
    char *Get_account() { return account; }        // ��ȡ�û��˺�
    char *Get_password() { return password; }      // ��ȡ�û�����
    int Get_total() { return Data_total; }         // ��ȡ�û��绰����
    void zengjia(const int i);                     // ���ӵ绰����
    void xianshi();                                // ��ʾ�绰������Ϣ
    void xianshi(const int i);                     // ��ʾĳ���绰������Ϣ
    void shanchu();                                // ɾ���绰����
    void chazhao();                                // ����
    void qingkong();                               // ��յ绰����Ϣ
    void updata_file();                                 // ���µ绰����Ϣ
    int change_account_password(Manager *manager); // �޸��˺�����
    void file_cout();                              // ������Ϣ
    void file_cin();                               // �ļ�����绰������Ϣ

private:
    char account[20], password[20]; // �û��˺�,����
    Data_people data[MAX + 1];      // �绰��Ϣ
    int Data_total;                 // �û��绰����
};

void showmenu_people();        // �û��˵�
void showmenu_zhu();           // ���˵�
void showmenu_manager();       // ����Ա�˵�
void showmenu_people_choose(); // ѡ���¼��ʽ
char *shurumima();             // ��������

int main()
{
    Manager user_manager;
    int ch_zhu, ch_people, ch_manager;
    user_manager.read_file();
    showmenu_zhu(); // ���˵�
    cin >> ch_zhu;
    while (1)
    {
        switch (ch_zhu)
        {
        case 1: // ��¼����Աϵͳ
        {
            if (user_manager.logon())
                break;
            system("pause");
            system("cls");
            showmenu_manager();
            cin >> ch_manager;
            while (1)
            {
                int ch_manager_de = 1;
                switch (ch_manager)
                {
                case 1: // ��ʾϵͳ��Ϣ
                    cout << "��ǰ�û�ע������" << user_manager.Get_total() << endl;
                    break;
                case 2: // ɾ��ָ���û�
                    user_manager.delete_people();
                    break;
                case 3: //  ɾ�������û�
                    user_manager.delete_people_all();
                    user_manager.read_file();
                    break;
                case 4: //  �޸Ĺ���Աϵͳ����
                    ch_manager_de = user_manager.change_password();
                    user_manager.read_file();
                    break;
                case 0: // �˳�����Աϵͳ
                    cout << "���˳�����Աϵͳ��" << endl;
                    break;
                default:
                    cout << "�����������������:" << endl;
                    break;
                }
                if (ch_manager == 0 || ch_manager_de == 0)
                    break;
                system("pause");
                system("cls");
                showmenu_manager();
                cin >> ch_manager;
            }
            break;
        }
        case 2: // ��¼�û��˺�
        {
            People user_people;
            int choose, flag = 0, flag_ch_people = 1;
            system("pause");
            system("cls");
            showmenu_people_choose();
            cin >> choose;
            while (choose != 0)
            {
                switch (choose)
                {
                case 1: // ��¼
                    flag = user_people.logon(&user_manager);
                    break;
                case 2: // ע��
                    user_manager.new_people();
                    break;
                default:
                    cout << "����������������룡" << endl;
                    break;
                }
                if (flag == 1)
                    break;
                system("pause");
                system("cls");
                showmenu_people_choose();
                cin >> choose;
            }
            if (choose == 0)
                break;
            system("pause");
            system("cls");
            showmenu_people();
            cin >> ch_people;
            while (1)
            {
                switch (ch_people)
                {
                case 1: // ���ӵ绰������Ϣ
                    user_people.zengjia(user_people.Get_total() + 1);
                    break;
                case 2: // ɾ���绰������Ϣ
                    user_people.shanchu();
                    break;
                case 3: // ��ʾ�绰������Ϣ
                    user_people.xianshi();
                    break;
                case 4: // ���ҵ绰������Ϣ
                    user_people.chazhao();
                    break;
                case 5: // ��յ绰������Ϣ
                    user_people.qingkong();
                    break;
                case 6: // �޸��˺�����
                    flag_ch_people = user_people.change_account_password(&user_manager);
                    break;
                case 7: // �����绰���벾��Ϣ
                    user_people.file_cout();
                case 8: // �ļ�����绰���벾��Ϣ
                    user_people.file_cin();
                    user_manager.updata_file();
                    break;
                case 0:
                    cout << "���˳���ǰ�˺ţ�" << endl;
                    break;
                default:
                    cout << "�����������������:" << endl;
                    break;
                }
                if (ch_people == 0 || flag_ch_people == 0)
                {
                    break;
                }
                system("pause");
                system("cls");
                showmenu_people();
                cin >> ch_people;
            }
            break;
        }
        case 0:
            cout << "ллʹ�ã��ټ���" << endl;
            break;
        default:
            cout << "����������������룡" << endl;
            break;
        }
        if (ch_zhu == 0)
        {
            break;
        }
        system("pause");
        system("cls");
        showmenu_zhu();
        cin >> ch_zhu;
    }
    return 0;
}

// ���˵�
void showmenu_zhu()
{
    cout << "**********************************************" << endl;
    cout << "************  �绰���벾����ϵͳ      ********" << endl;
    cout << "************        ----���˵�        ********" << endl;
    cout << "**********************************************" << endl;
    cout << "************   1.����Աģʽϵͳ       ********" << endl;
    cout << "************   2.��¼�绰���벾ϵͳ   ********" << endl;
    cout << "************   0.�˳�ϵͳ             ********" << endl;
    cout << "**********************************************" << endl;
    cout << "���������ѡ�񣺣�0-2��" << endl;
}

// ����Ա�˵�
void showmenu_manager()
{
    cout << "**********************************************" << endl;
    cout << "************  �绰���벾����ϵͳ      ********" << endl;
    cout << "************        ----����ԱȨ��    ********" << endl;
    cout << "**********************************************" << endl;
    cout << "************   1.��ʾ�û�ע������     ********" << endl;
    cout << "************   2.ɾ��ָ���û�         ********" << endl;
    cout << "************   3.ɾ�������û�         ********" << endl;
    cout << "************   4.�޸Ĺ���Աϵͳ����   ********" << endl;
    cout << "************   0.�˳�����Աϵͳ       ********" << endl;
    cout << "**********************************************" << endl;
    cout << "���������ѡ�񣺣�0-4��" << endl;
}

// �û��˵�
void showmenu_people()
{
    cout << "***************************************************" << endl;
    cout << "************  �绰���벾����ϵͳ           ********" << endl;
    cout << "************        ----�û�Ȩ��           ********" << endl;
    cout << "***************************************************" << endl;
    cout << "************   1.���ӵ绰������Ϣ          ********" << endl;
    cout << "************   2.ɾ���绰������Ϣ          ********" << endl;
    cout << "************   3.��ʾ�绰������Ϣ          ********" << endl;
    cout << "************   4.���ҵ绰������Ϣ          ********" << endl;
    cout << "************   5.��յ绰������Ϣ          ********" << endl;
    cout << "************   6.�޸��˺�����              ********" << endl;
    cout << "************   7.����绰���벾��Ϣ        ********" << endl;
    cout << "************   8.���ļ�����绰���벾��Ϣ  ********" << endl;
    cout << "************   0.�˳���ǰ�˺�              ********" << endl;
    cout << "***************************************************" << endl;
    cout << "���������ѡ�񣺣�0-6��" << endl;
}

// ѡ���¼��ʽ
void showmenu_people_choose()
{
    cout << "**********************************************" << endl;
    cout << "************  �绰���벾����ϵͳ      ********" << endl;
    cout << "************        ----�û���¼ѡ��  ********" << endl;
    cout << "************   1.��¼�˺�             ********" << endl;
    cout << "************   2.ע���˺�             ********" << endl;
    cout << "************   0.������һ��           ********" << endl;
    cout << "**********************************************" << endl;
    cout << "���������ѡ�񣺣�0-3��" << endl;
}

// ��ȡ��Ϣ--����Ա���룬�û���Ϣ
void Manager::read_file()
{
    int i;
    char num2[20], people_a[20], people_p[20];
    ifstream out("Manager.txt"); // ��ȡ����Ա���뼰�û��˺���������
    if (out)
    {
        out >> m_people_total;
        out >> num2;
        strcpy(password, num2);
        for (i = 1; i <= m_people_total; i++)
        {
            out >> people_a;
            strcpy(m_people_a[i], people_a);
            out >> people_p;
            strcpy(m_people_p[i], people_p);
        }
        out.close();
    }
    else
    {
        ofstream out_manager_de("Manager.txt", ios::trunc);
        if (out_manager_de)
        {
            out_manager_de << "0 123456" << endl;
            out_manager_de.close();
        }
    }
}

// ������Ϣ--����Ա
void Manager::updata_file()
{
    int i;
    ofstream out_people("Manager.txt", ios::trunc);
    if (out_people)
    {
        out_people << m_people_total << " " << password << endl;
        for (i = 1; i <= m_people_total; i++)
        {
            out_people << m_people_a[i] << " " << m_people_p[i] << endl;
        }
    }
}

// ��¼����Աϵͳ
int Manager::logon()
{
    char user_password[20], ch;
    int i = 0;
    cout<< "����������:";
    while (true)
    {
        ch = _getch();  // �޻��Ե�����
        if (ch == '\r') // getch()������������س����ŷ���'/r'
        {
            cout << endl;
            break;
        }
        user_password[i++] = ch;
        putchar('*');
    }
    if (strcmp(user_password, password) == 0)
    {
        cout << "�ѳɹ���¼����Աϵͳ" << endl;
        return 0;
    }
    else
    {
        cout << "�������" << endl;
        return 1;
    }
}

// ɾ��ָ���û�
void Manager::delete_people()
{
    if (m_people_total == 0)
    {
        cout << "�û�ע����Ϊ0��" << endl;
        return;
    }
    int i, flag_de;
    char choose_account[20];
    cout << "��������Ҫɾ�����û���" << endl;
    cin >> choose_account;
    for (i = 1; i <= m_people_total; i++)
    {
        if (strcmp(m_people_a[i], choose_account) == 0)
        {
            cout << "ȷ��ɾ���û���������";
            cout << m_people_a[i] << "��" << endl;
            cout << "��ȷ����" << endl;
            cout << "1--ɾ��" << endl;
            cout << "2--ȡ��ɾ��" << endl;
            cin >> flag_de;
            switch (flag_de)
            {
            case 1:
            {
                remove(strcat(m_people_a[i], ".txt"));
                for (i++; i <= m_people_total; i++)
                {
                    strcpy(m_people_a[i - 1], m_people_a[i]);
                    strcpy(m_people_p[i - 1], m_people_p[i]);
                }
                m_people_total--;
                this->updata_file();
                cout << "�ѳɹ�ɾ��!" << endl;
                return;
            }
            case 2:
                cout << "��ȡ��ɾ��" << endl;
                return;
            default:
                cout << "�������" << endl;
                return;
            }
        }
    }
    cout << "δ��ѯ����Ҫɾ�����û���������ȷ�ϣ�" << endl;
}

// ɾ�������û�
void Manager::delete_people_all()
{
    if (m_people_total == 0)
    {
        cout << "�û�ע����Ϊ0��" << endl;
        return;
    }
    int choose_de, i = 0;
    char user_password[20], ch;
    cout << "����������������ȷ����" << endl;
    while (true)
    {
        ch = _getch();  // �޻��Ե�����
        if (ch == '\r') // getch()������������س����ŷ���'/r'
        {
            cout << endl;
            break;
        }
        user_password[i++] = ch;
        putchar('*');
    }
    if (strncmp(user_password, password, 20) == 0)
    {
        cout << "������ȷ��" << endl;
        cout << "ȷ��ɾ�������û���" << endl;
        cout << "1.��" << endl;
        cout << "2.��" << endl;
        cin >> choose_de;
        switch (choose_de)
        {
        case 1:
        {
            int i;
            for (i = 1; i <= m_people_total; i++)
            {
                remove(strcat(m_people_a[i], ".txt"));
            }
            ofstream out_manager_de("Manager.txt", ios::trunc);
            if (out_manager_de)
            {
                out_manager_de << "0";
                out_manager_de << " " << password << endl;
                out_manager_de.close();
                cout << "��ɾ�������û���" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "��ȡ��ɾ����" << endl;
            break;
        }
        default:
            cout << "�������" << endl;
            break;
        }
    }
    else
        cout << "�������" << endl;
}

// �޸Ĺ���Ա����
int Manager::change_password()
{
    int i = 0;
    char ch, password_old[20], password_change[20], password2_change[20];
    cout << "����������������ȷ����" << endl;
    while (true)
    {
        ch = _getch();  // �޻��Ե�����
        if (ch == '\r') // getch()������������س����ŷ���'/r'
        {
            cout << endl;
            break;
        }
        password_old[i++] = ch;
        putchar('*');
    }
    if (strncmp(password_old, password, 20) == 0)
    {
        cout << "������ȷ��" << endl;
        while (1)
        {
            cout << "�������޸ĺ�����:" << endl;
            while (true)
            {
                ch = _getch();  // �޻��Ե�����
                if (ch == '\r') // getch()������������س����ŷ���'/r'
                {
                    cout << endl;
                    break;
                }
                password_change[i++] = ch;
                putchar('*');
            }
            cout << password_change << "���ٴ�ȷ������" << endl;
            while (true)
            {
                ch = _getch();  // �޻��Ե�����
                if (ch == '\r') // getch()������������س����ŷ���'/r'
                {
                    cout << endl;
                    break;
                }
                password2_change[i++] = ch;
                putchar('*');
            }
            cout << password2_change;
            if (strcmp(password_change, password) == 0)
            {
                cout << "���������������ͬ�����������롣" << endl;
            }
            else
            {
                if (strcmp(password2_change, password_change) == 0)
                {
                    cout << "�����޸ĳɹ���" << endl;
                    strcpy(password, password_change);
                    this->updata_file();
                    cout << "��¼ʧЧ�������µ�¼��" << endl;
                    return 0;
                }
                else
                {
                    cout << "�������벻��ͬ��" << endl;
                }
            }
        }
    }
    else
        cout << "�������" << endl;
    return 1;
}

// ��¼�û��˺š�����¼����Աϵͳ����
int Manager::logon(char *num1, char *num2)
{
    int i;
    for (i = 1; i <= m_people_total; i++)
    {
        if ((strncmp(num1, m_people_a[i], 20) == 0) && (strncmp(num2, m_people_p[i], 20) == 0))
            return 1;
    }
    return 0;
}

// ��¼�û��˺�
int People::logon(Manager *manager)
{
    int i = 0;
    char ch, user_account[20], user_password[20], file_name[25], user_name[20];
    cout << "�������˺�:";
    cin >> user_account;
    cout << "����������:";
    while (true)
    {
        ch = _getch();  // �޻��Ե�����
        if (ch == '\r') // getch()������������س����ŷ���'/r'
        {
            cout << endl;
            break;
        }
        user_password[i++] = ch;
        putchar('*');
    }
    strcpy(user_name, user_account);
    if (manager->logon(user_account, user_password) == 1)
    {
        cout << "�˺�" << user_account << "�ѵ�¼" << endl;
        strncpy(file_name, strcat(user_account, ".txt"), 23);
        fstream out_people(file_name);
        if (out_people)
        {
            out_people >> account >> password >> Data_total;
            for (i = 1; i <= Data_total; i++)
            {
                out_people >> data[i].name >> data[i].sex >> data[i].age;
                out_people >> data[i].num >> data[i].address;
            }
            cout << "��Դ�ļ��Ѷ�ȡ��" << endl;
            out_people.close();
        }
        else
        {
            out_people.close();
            fstream out_people2(file_name, ios::in | ios::out | ios::trunc);
            out_people2 << user_name << " " << user_password << " " << Data_total << endl;
            out_people2.close();
            cout << "��ȡ��Դ�ļ������Ѵ����µ���Դ�ļ���" << endl;
        }
        return 1;
    }
    else
    {
        cout << "�˺Ż��������" << endl;
        return 0;
    }
}

// ע���û��˺�
void Manager::new_people()
{
    int i = 0, j = 5;
    char ch, account_logon[20], password_logon[20], password2_logon[20];
    while (i <= m_people_total)
    {
        cout << "�������˺ţ�" << endl;
        cin >> account_logon;
        for (i = 1; i <= m_people_total; i++)
        {
            if (strncmp(account_logon, m_people_a[i], 20) == 0)
            {
                cout << "�˺��Ѵ��ڣ����������롣" << endl;
                break;
            }
        }
    }
    while (j--)
    {
        cout << "���������룺" << endl;
        while (true)
        {
            ch = _getch();  // �޻��Ե�����
            if (ch == '\r') // getch()������������س����ŷ���'/r'
            {
                cout << endl;
                break;
            }
            password_logon[i++] = ch;
            putchar('*');
        }
        cout << "���ٴ�ȷ������" << endl;
        while (true)
        {
            ch = _getch();  // �޻��Ե�����
            if (ch == '\r') // getch()������������س����ŷ���'/r'
            {
                cout << endl;
                break;
            }
            password2_logon[i++] = ch;
            putchar('*');
        }
        if (strcmp(password_logon, password2_logon) == 0)
        {
            cout << "�˺�ע��ɹ�����������һ�㣩" << endl;
            m_people_total++;
            strcpy(m_people_a[m_people_total], account_logon);
            strcpy(m_people_p[m_people_total], password_logon);
            ofstream out_manager("Manager.txt", ios::trunc);
            if (out_manager)
            {
                out_manager << m_people_total << " " << password << endl;
                for (int k = 1; k <= m_people_total; k++)
                    out_manager << m_people_a[k] << " " << m_people_p[k] << endl;
            }
            out_manager.close();
            return;
        }
        else
        {
            cout << "�������벻��ͬ��(ʣ��" << j << "�λ��ᣩ" << endl;
        }
    }
}

// ���ӵ绰������Ϣ
void People::zengjia(const int i)
{
    if (Data_total >= MAX)
    {
        cout << "�绰��������" << endl;
        return;
    }
    cout << "������������" << endl;
    cin >> data[i].name;
    cout << "�������Ա�" << endl;
    cout << "1--��" << endl;
    cout << "2--Ů" << endl;
    cin >> data[i].sex;
    cout << "���������䣺" << endl;
    cin >> data[i].age;
    cout << "������绰���룺" << endl;
    cin >> data[i].num;
    cout << "������סַ��" << endl;
    cin >> data[i].address;
    Data_total++;
    this->updata_file();
    cout << "����ɹ���" << endl;
}

// ɾ���绰������Ϣ
void People::shanchu()
{
    if (Data_total == 0)
    {
        cout << "�绰��Ϊ�գ�" << endl;
        return;
    }
    int i, flag;
    char num_delete[30];
    cout << "��������Ҫɾ���ĵ绰���룺" << endl;
    cin >> num_delete;
    for (i = 1; i <= Data_total; i++)
    {
        if (strncmp(num_delete, data[i].num, 20) == 0)
        {
            cout << "ȷ��ɾ���绰���롪������";
            cout << data[i].num << "��" << endl;
            cout << "��ȷ����" << endl;
            cout << "1--ɾ��" << endl;
            cout << "2--ȡ��ɾ��" << endl;
            cin >> flag;
            switch (flag)
            {
            case 1:
            {
                for (i++; i <= Data_total; i++)
                {
                    data[i - 1] = data[i];
                }
                Data_total--;
                cout << "�ѳɹ�ɾ��!" << endl;
                this->updata_file();
                return;
            }
            case 2:
            {
                cout << "��ȡ��ɾ��" << endl;
                return;
            }
            default:
                cout << "�������" << endl;
                return;
            }
        }
    }
    cout << "δ��ѯ����Ҫɾ���ĵ绰��������ȷ�ϣ�" << endl;
}

// ���ҵ绰������Ϣ
void People::chazhao()
{
    if (Data_total == 0)
    {
        cout << "�绰��Ϊ�գ�" << endl;
        return;
    }
    int i, flag, judge, sex_age_find;
    char num_name_find[30];
    judge = 0;
    cout << "��ѡ����Ҫ���ҵ���Ϣ��" << endl;
    cout << "1.�绰����" << endl;
    cout << "2.����" << endl;
    cout << "3.�Ա�" << endl;
    cout << "4.����" << endl;
    cin >> flag;
    switch (flag)
    {
    case 1:
        cout << "��������Ҫ���ҵĵ绰���룺" << endl;
        cin >> num_name_find;
        for (i = 1; i <= Data_total; i++)
        {
            if (strncmp(num_name_find, data[i].num, 20) == 0)
            {
                cout << "���ҳɹ�����Ϣ���£�" << endl;
                judge = 1;
                cout << "����\t  �Ա�\t����\t�绰\t\tסַ" << endl;
                this->xianshi(i);
            }
        }
        break;
    case 2:
        cout << "��������Ҫ���ҵ�������" << endl;
        cin >> num_name_find;
        for (i = 1; i <= Data_total; i++)
        {
            if (strncmp(num_name_find, data[i].name, 30) == 0)
            {
                cout << "���ҳɹ�����Ϣ���£�" << endl;
                judge = 1;
                cout << "����\t  �Ա�\t����\t�绰\t\tסַ" << endl;
                this->xianshi(i);
            }
        }
        break;
    case 3:
        cout << "��������Ҫ���ҵ��Ա�" << endl;
        cout << "1--��" << endl;
        cout << "2--Ů" << endl;
        cin >> sex_age_find;
        for (i = 1; i <= Data_total; i++)
        {
            if (sex_age_find == data[i].sex)
            {
                judge++;
                if (judge == 1)
                {
                    cout << "���ҳɹ�����Ϣ���£�" << endl;
                    cout << "����\t  �Ա�\t����\t�绰\t\tסַ" << endl;
                }
                this->xianshi(i);
            }
        }
        break;
    case 4:
        cout << "��������Ҫ���ҵ����䣺" << endl;
        cin >> sex_age_find;
        for (i = 1; i <= Data_total; i++)
        {
            if (sex_age_find == data[i].age)
            {
                judge++;
                if (judge == 1)
                {
                    cout << "���ҳɹ�����Ϣ���£�" << endl;
                    cout << "����\t  �Ա�\t����\t�绰\t\tסַ" << endl;
                }
                this->xianshi(i);
            }
        }
        break;
    default:
        cout << "�������" << endl;
        break;
    }
    if (judge == 0 && (flag == 1 || flag == 2 || flag == 3 || flag == 4))
        cout << "δ���ҵ�����Ϣ��" << endl;
}

// ��ʾ�绰������Ϣ
void People::xianshi()
{
    int i;
    if (Data_total == 0)
    {
        cout << "�绰��Ϊ�գ�" << endl;
        return;
    }
    cout << "�˺�" << account << "�ĵ绰����Ϣ���£�" << endl;
    cout << "����\t  �Ա�\t����\t�绰\t\tסַ" << endl;
    for (i = 1; i <= Data_total; i++)
    {
        cout << data[i].name << "\t  ";
        if (data[i].sex == 1)
            cout << "��";
        else if (data[i].sex == 2)
            cout << "Ů";
        else
            cout << "δ֪";
        cout << "\t" << data[i].age << "\t" << data[i].num;
        cout << "\t" << data[i].address << endl;
    }
}

// ��ʾĳ���绰������Ϣ
void People::xianshi(const int i)
{
    cout << data[i].name << "\t  ";
    if (data[i].sex == 1)
        cout << "��";
    else if (data[i].sex == 2)
        cout << "Ů";
    else
        cout << "δ֪";
    cout << "\t" << data[i].age << "\t" << data[i].num;
    cout << "\t" << data[i].address << endl;
}

// ��յ绰������Ϣ
void People::qingkong()
{
    if (Data_total == 0)
    {
        cout << "�绰��Ϊ�գ�" << endl;
        return;
    }
    int choose, i = 0;
    char user_password[20], ch;
    cout << "����������������ȷ����" << endl;
    while (true)
    {
        ch = _getch();  // �޻��Ե�����
        if (ch == '\r') // getch()������������س����ŷ���'/r'
        {
            cout << endl;
            break;
        }
        user_password[i++] = ch;
        putchar('*');
    }
    if (strncmp(user_password, password, 20) == 0)
    {
        cout << "������ȷ��" << endl;
        cout << "ȷ����յ绰����Ϣ��" << endl;
        cout << "1--��" << endl;
        cout << "2--��" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            Data_total = 0;
            cout << "�绰������գ�" << endl;
            this->updata_file();
            break;
        case 2:
            cout << "��ȡ����ղ�����" << endl;
            break;
        default:
            cout << "�������" << endl;
        }
    }
    else
        cout << "�������" << endl;
}

// ���µ绰����Ϣ
void People::updata_file()
{
    int i;
    char account_updata[20];
    strncpy(account_updata, account, 20);
    ofstream out_people(strcat(account_updata, ".txt"), ios::trunc);
    if (out_people)
    {
        out_people << account << " " << password << " " << Data_total << endl;
        for (i = 1; i <= Data_total; i++)
        {
            out_people << data[i].name << " " << data[i].sex << " " << data[i].age;
            out_people << " " << data[i].num << " " << data[i].address << endl;
        }
    }
}

// �޸��˺�����
int People::change_account_password(Manager *manager)
{
    char ch, password_old[20], password_change[20], password2_change[20], account_change[20], account_old[20];
    int choose_change, i = 0, flag = 0;
    strncpy(account_old, account, 20);
    cout << "����������������ȷ����" << endl;
    cin >> password_old;
    while (true)
    {
        ch = _getch();  // �޻��Ե�����
        if (ch == '\r') // getch()������������س����ŷ���'/r'
        {
            cout << endl;
            break;
        }
        password_old[i++] = ch;
        putchar('*');
    }
    i = 0;
    if (strncmp(password_old, password, 20) == 0)
    {
        cout << "������ȷ��" << endl;
        cout << "��������Ҫ�޸ĵ���Ϣ��" << endl;
        cout << "1--�˺�" << endl;
        cout << "2--����" << endl;
        cout << "3--�˺�������" << endl;
        cin >> choose_change;
        switch (choose_change)
        {
        case 1: // �޸��˺�
        {
            while (i <= manager->Get_total())
            {
                cout << "�������޸ĺ��˺�:" << endl;
                cin >> account_change;
                for (i = 1; i <= manager->Get_total(); i++)
                {
                    if (strncmp(account_change, manager->Get_account(i), 20) == 0)
                    {
                        cout << "���˺��Ѵ��ڣ����������롣" << endl;
                        break;
                    }
                }
            }
            for (i = 1; i <= manager->Get_total(); i++)
            {
                if (strncmp(account, manager->Get_account(i), 20) == 0)
                {
                    manager->change_account_people(i, account_change);
                    break;
                }
            }
            strcpy(account, account_change);
            this->updata_file();
            remove(strcat(account_old, ".txt"));
            manager->updata_file();
            cout << "��¼ʧЧ�������µ�¼��" << endl;
            return 1;
        }
        case 2: // �޸�����
        {
            while (1)
            {
                cout << "�������޸ĺ�����:" << endl;
                while (true)
                {
                    ch = _getch();  // �޻��Ե�����
                    if (ch == '\r') // getch()������������س����ŷ���'/r'
                    {
                        cout << endl;
                        break;
                    }
                    password_change[i++] = ch;
                    putchar('*');
                }
                cout << "���ٴ�ȷ������" << endl;
                while (true)
                {
                    ch = _getch();  // �޻��Ե�����
                    if (ch == '\r') // getch()������������س����ŷ���'/r'
                    {
                        cout << endl;
                        break;
                    }
                    password2_change[i++] = ch;
                    putchar('*');
                }
                if (strncmp(password_change, password, 20) == 0)
                {
                    cout << "���������������ͬ�����������롣" << endl;
                }
                else
                {
                    if (strcmp(password_change, password_change) == 0)
                    {
                        cout << "�����޸ĳɹ���" << endl;
                        cout << "��¼ʧЧ�������µ�¼��" << endl;
                        break;
                    }
                    else
                    {
                        cout << "���������������ͬ�����������롣" << endl;
                    }
                }
            }
            for (i = 1; i <= manager->Get_total(); i++)
            {
                if (strncmp(account, manager->Get_account(i), 20) == 0)
                {
                    manager->change_password_people(i, password_change);
                    break;
                }
            }
            strcpy(password, password_change);
            this->updata_file();
            manager->updata_file();
            return 0;
        }
        case 3: // �޸��˺�������
        {
            while (i <= manager->Get_total())
            {
                cout << "�������޸ĺ��˺�:" << endl;
                cin >> account_change;
                for (i = 1; i <= manager->Get_total(); i++)
                {
                    if (strncmp(account_change, manager->Get_account(i), 20) == 0)
                    {
                        cout << "���˺��Ѵ��ڣ����������롣" << endl;
                        break;
                    }
                }
            }
            for (i = 1; i <= manager->Get_total(); i++)
            {
                if (strncmp(account, manager->Get_account(i), 20) == 0)
                {
                    manager->change_account_people(i, account_change);
                    break;
                }
            }
            strcpy(account, account_change);
            remove(strcat(account_old, ".txt"));
            while (1)
            {
                cout << "�������޸ĺ�����:" << endl;
                while (true)
                {
                    ch = _getch();  // �޻��Ե�����
                    if (ch == '\r') // getch()������������س����ŷ���'/r'
                    {
                        cout << endl;
                        break;
                    }
                    password_change[i++] = ch;
                    putchar('*');
                }
                if (strncmp(password_change, password, 20) == 0)
                {
                    cout << "���������������ͬ�����������롣" << endl;
                }
                else
                {
                    cout << "�����޸ĳɹ���" << endl;
                    cout << "��¼ʧЧ�������µ�¼��" << endl;
                    break;
                }
            }
            for (i = 1; i <= manager->Get_total(); i++)
            {
                if (strncmp(account, manager->Get_account(i), 20) == 0)
                {
                    manager->change_password_people(i, password_change);
                    break;
                }
            }
            strcpy(password, password_change);
            this->updata_file();
            manager->updata_file();
            return 0;
        }
        default:
        {
            cout << "�������" << endl;
            return 1;
        }
        }
    }
    else
        cout << "�������" << endl;
    return 1;
}

// �����绰���벾��Ϣ
void People::file_cout()
{
    int i;
    char *path;
    path = _getcwd(NULL, 0);
    cout << "�ļ��ѱ�����" << path << endl;
    char account_updata[20];
    strncpy(account_updata, account, 20);
    ofstream out_people(strcat(account_updata, "_�绰��.txt"), ios::trunc);
    if (out_people)
    {
        out_people << "�˺�" << account << "�ĵ绰����Ϣ���£�" << endl;
        out_people << "�绰������ " << Data_total << endl;
        out_people << "����\t�Ա�\t����\t�绰\t\t\tסַ" << endl;
        for (i = 1; i <= Data_total; i++)
        {
            out_people << data[i].name << "\t";
            if (data[i].sex == 1)
                out_people << "��";
            else
                out_people << "Ů";
            out_people << "\t\t" << data[i].age;
            out_people << "\t\t" << data[i].num << "\t\t" << data[i].address << endl;
        }
        out_people.close();
    }
}

// �ļ�����绰������Ϣ
void People::file_cin()
{
    char path[100], total_cin[10][20], somethings[10][20], sex_cin[5];
    int i = 3, j, Data_total_cin;
    cout << "��������Ҫ�����ļ��ľ���·����" << endl;
    cin >> path;
    fstream out_people(path);
    if (out_people)
    {
        for (i = 1; i <= 3; i++)
        {
            if (i == 3)
                out_people >> Data_total_cin;
            else
                out_people >> total_cin[i];
        }
        for (i = 1; i <= 5; i++)
        {
            out_people >> somethings[i];
        }
        for (j = Data_total + 1; j <= Data_total + Data_total_cin; j++)
        {
            out_people >> data[j].name;
            out_people >> sex_cin;
            if (strcmp(sex_cin, "��") == 0)
                data[j].sex = 1;
            else
            {
                if (strcmp(sex_cin, "Ů") == 0)
                    data[j].sex = 2;
                else
                    data[j].sex = 3;
            }
            out_people >> data[j].age >> data[j].num >> data[j].address;
        }
        Data_total = Data_total + Data_total_cin;
        cout << "����ɹ���" << endl;
        out_people.close();
    }
    else
    {
        cout << "�ļ���ʧ�ܣ�" << endl;
    }
    this->updata_file();
}
