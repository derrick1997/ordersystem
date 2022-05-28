//ordersystem
//author:babysen
//date:2022/01/05-07

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

const int strsize = 30;
const string flavor[8] = {"����", "��", "΢΢��", "΢��", "����", "����", "����", "����"}; //��ζ

//������ʾ������
void display_menu();       //��ʾ�˵�
void display_name();       //����
void display_preference(); //��ʾ�̵���ζ

//void display_sex();        //ͳ����Ů������
//�����ṹ��,����s���Ա����һ�ֱ�s=0,1;0ΪŮ�ԣ�1Ϊ����

struct order
{
    char fullname[strsize]; //��ȫ��
    int b;                  //�˱��
    int price;              //�۸�
};

//����ṹ�����������

//�����Ƽ��˵�
order hsr[6] =
    {
        {"���", 1, 15},
        {"�����", 2, 7},
        {"��������", 3, 24},
        {"�������", 4, 7},
        {"ɰ������", 5, 7},
        {"����ӵ�", 6, 6}};

//���Ӳ˵�
order dump[8] =
    {
        {"��ݴ�������", 7, 10},
        {"С�ݴ�������", 8, 8},
        {"��ݾ²˼���", 9, 10},
        {"С�ݾ²˼���", 10, 8},
        {"��ݴ��ţ��", 11, 12},
        {"С�ݴ��ţ��", 12, 10},
        {"��ݴ������", 13, 12},
        {"С�ݴ������", 14, 10}};

//��ʳ�˵�
order noodle[10] =
    {
        {"��������һ��", 15, 11},
        {"С������һ��", 16, 10},
        {"�������һ��", 17, 10},
        {"С�����һ��", 18, 9},
        {"����������", 19, 9},
        {"С��������", 20, 8},
        {"������������", 21, 9},
        {"С����������", 22, 8},
        {"���������", 23, 9},
        {"С�������", 24, 8}};

//�׷��˵�
order rice[7] =
    {
        {"��������", 25, 8},
        {"һ������", 26, 8},
        {"һ������", 27, 7},
        {"�����ز�", 28, 6},
        {"С����ǽ���", 29, 11},
        {"���Ӹǽ���", 30, 9},
        {"���Ѽ����ǽ���", 31, 9}};

//��ɫС�Բ˵�
order spes[4] =
    {
        {"һ������", 32, 4},
        {"������Ƥ", 33, 6},
        {"������", 34, 2},
        {"��«ͷ����", 35, 13}};

//����˵�����
void display_menu()
{
    cout << "-----------------------------------------" << endl;
    cout << "|             ��������˵���             |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               a.�����Ƽ�               |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               b.����                   |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               c.����                   |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               d.�׷�                   |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               e.��ɫС��               |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               q.�˳���ͳ��             |" << endl;
    cout << "-----------------------------------------" << endl;
}

//�����������
void display_name()
{
    cout << "a.�����Ƽ��˵�����: " << endl;
    for (int i = 0; i < 6; i++)
        cout << "����: " << hsr[i].fullname << ","
             << "���: " << hsr[i].b << ","
             << "����: " << hsr[i].price << "Ԫ" << endl;

    cout << "b.����: " << endl;
    for (int i = 0; i < 8; i++)
        cout << "����: " << dump[i].fullname << ","
             << "���: " << dump[i].b << ","
             << "����: " << dump[i].price << "Ԫ" << endl;

    cout << "c.����: " << endl;
    for (int i = 0; i < 10; i++)
        cout << "����: " << noodle[i].fullname << ","
             << "���: " << noodle[i].b << ","
             << "����: " << noodle[i].price << "Ԫ" << endl;

    cout << "d.�׷�: " << endl;
    for (int i = 0; i < 7; i++)
        cout << "����: " << rice[i].fullname << ","
             << "���: " << rice[i].b << ","
             << "����: " << rice[i].price << "Ԫ" << endl;

    cout << "e.��ɫС��: " << endl;
    for (int i = 0; i < 4; i++)
        cout << "����: " << spes[i].fullname << ","
             << "���: " << spes[i].b << ","
             << "����: " << spes[i].price << "Ԫ" << endl;
}

//������˿�ζ����
void display_preference()
{
    cout << "--------------------------------------" << endl;
    cout << "|    1.����, 2.��, 3.΢΢��, 4.΢��    |" << endl;
    cout << "|    5.����, 6.����, 7.����, 8.����    |" << endl;
    cout << "--------------------------------------" << endl;
}

//ͳ����Ů����������
/* void display_sex()
{
    for (int i = 0; i < NUM; i++)
        cout << people[i].fullname << " 's sex is: " << people[i].sex << endl;
} */

//������
int main()
{
    //����д���ļ�
    ofstream outfile("statis.xls", ios::trunc); //�������洢��statis�ļ���
    if (!outfile)
    {
        cerr << "�򿪴���!" << endl;
        exit(1);
    }
    //1.��ʼ�����趨�˺ź����롣
    long int ID = 20220106;
    int num = 6; //�����������
    //2.�����洢��Ϣ�ı�����
    long int id;
    //3.���do-whileѭ���ṹ�����������
    cout << "�������˺�: ";
    cin >> id;
    int i = 0;
    //��ʼ��һ�����ַ���,s�������ַ���
    string pwd = "", s = "666666";
    cout << "����������: ";
    char c;
    while (true)
    {
        c = getch();
        if (c != 13) //������ǻس����Ͳ�����string���͵�pwd�����c
        {
            pwd = pwd + c;
            cout << "*";
        }
        else
        {
            if (pwd == s && id == ID)
            {
                cout << endl;
                cout << "                 ��½�ɹ�                " << endl;
                cout << "-----------------------------------------" << endl;
                char ch;       //������ѡ�����
                int nn;        //��ζѡ�����
                double p0[6];  //a��˵ļ�Ǯ
                double p1[8];  //b��˵ļ�Ǯ
                double p2[10]; //c��˵ļ�Ǯ
                double p3[7];  //d��˵ļ�Ǯ
                double p4[4];  //e��˵ļ�Ǯ
                long int total[35] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //���˳�ʼ������� 
                //long int total[]={};
                cout << "��ӭ���ٳ�����ѧʳ�þͲͣ��˵�����: " << endl;
                display_menu();
                cout << endl;
                display_name();
                cout << endl;
                display_preference();
                cout << "______________________________" << endl;
                cout << "______________________________" << endl;
                cout << "������ĸ����������ĸ�����Ĳ�Ʒ: " << endl;
                while (cin >> ch && ch != 'q' && ch != 'Q')
                {
                    cout << "����������" << endl;
                    int bi;     //�˱��
                    switch (ch) //case��֧�����ſ��Բ�Ҫ������Ϊ�˷���ۿ�������
                    {
                    case 'a':
                    case 'A':
                    {
                        cin >> bi;
                        if (bi == 1)
                            total[0]++;
                        else if (bi == 2)
                            total[1]++;
                        else if (bi == 3)
                            total[2]++;
                        else if (bi == 4)
                            total[3]++;
                        else if (bi == 5)
                            total[4]++;
                        else if (bi == 6)
                            total[5]++;
                    }
                    break;

                    case 'b':
                    case 'B':
                    {
                        cin >> bi;
                        if (bi == 7)
                            total[6]++;
                        else if (bi == 8)
                            total[7]++;
                        else if (bi == 9)
                            total[8]++;
                        else if (bi == 10)
                            total[9]++;
                        else if (bi == 11)
                            total[10]++;
                        else if (bi == 12)
                            total[11]++;
                        else if (bi == 13)
                            total[12]++;
                        else if (bi == 14)
                            total[13]++;
                    }
                    break;

                    case 'c':
                    case 'C':
                    {
                        cin >> bi;
                        if (bi == 15)
                            total[14]++;
                        else if (bi == 16)
                            total[15]++;
                        else if (bi == 17)
                            total[16]++;
                        else if (bi == 18)
                            total[17]++;
                        else if (bi == 19)
                            total[18]++;
                        else if (bi == 20)
                            total[19]++;
                        else if (bi == 21)
                            total[20]++;
                        else if (bi == 22)
                            total[21]++;
                        else if (bi == 23)
                            total[22]++;
                        else if (bi == 24)
                            total[23]++;
                    }
                    break;

                    case 'd':
                    case 'D':
                    {
                        cin >> bi;
                        if (bi == 25)
                            total[24]++;
                        else if (bi == 26)
                            total[25]++;
                        else if (bi == 27)
                            total[26]++;
                        else if (bi == 28)
                            total[27]++;
                        else if (bi == 29)
                            total[28]++;
                        else if (bi == 30)
                            total[29]++;
                        else if (bi == 31)
                            total[30]++;
                    }
                    break;

                    case 'e':
                    case 'E':
                    {
                        cin >> bi;
                        if (bi == 32)
                            total[31]++;
                        else if (bi == 33)
                            total[32]++;
                        else if (bi == 34)
                            total[33]++;
                        else if (bi == 35)
                            total[34]++;
                    }
                    break;
                    }

                    cout << "�����ζѡ��:" << endl;
                    cin >> nn;
                    while (nn != 0)
                    {
                        switch (nn)
                        {
                        case 1:
                            cout << flavor[0] << endl;
                            break;
                        case 2:
                            cout << flavor[1] << endl;
                            break;
                        case 3:
                            cout << flavor[2] << endl;
                            break;
                        case 4:
                            cout << flavor[3] << endl;
                            break;
                        case 5:
                            cout << flavor[4] << endl;
                            break;
                        case 6:
                            cout << flavor[5] << endl;
                            break;
                        case 7:
                            cout << flavor[6] << endl;
                            break;
                        case 8:
                            cout << flavor[7] << endl;
                            break;
                        default:
                            cout << "ѡ�����" << endl;
                        }
                        break;
                    }
                    cout << "���������ĸ����������ĸ�����Ĳ�Ʒ: " << endl;
                }

                for (int i = 0; i < 6; i++)
                {
                    p0[i] = total[i] * hsr[i].price;
                    outfile << "a�����Ʒ���������: " << endl;
                    outfile << hsr[i].fullname << " " << total[i] << " ��" << endl;
                    outfile << "a�����Ʒ���۶�����: " << endl;
                    p0[i] = total[i] * hsr[i].price;
                    outfile << hsr[i].fullname << " " << p0[i] << " Ԫ" << endl;
                }

                for (int i = 0; i < 8; i++)
                {
                    outfile << "b�����Ʒ���������: " << endl;
                    outfile << dump[i].fullname << " " << total[i + 5] << " ��" << endl;
                    outfile << "b�����Ʒ���۶�����: " << endl;
                    p1[i] = total[i + 5] * dump[i].price;
                    outfile << dump[i].fullname << " " << p1[i] << " Ԫ" << endl;
                }

                for (int i = 0; i < 10; i++)
                {
                    outfile << "c�����Ʒ���������: " << endl;
                    outfile << noodle[i].fullname << " " << total[i + 13] << " ��" << endl;
                    outfile << "c�����Ʒ���۶�����: " << endl;
                    p2[i] = total[i + 13] * noodle[i].price;
                    outfile << noodle[i].fullname << " " << p2[i] << " Ԫ" << endl;
                }

                for (int i = 0; i < 7; i++)
                {
                    outfile << "d�����Ʒ���������: " << endl;
                    outfile << rice[i].fullname << " " << total[i + 23] << " ��" << endl;
                    outfile << "d�����Ʒ���۶�����: " << endl;
                    p3[i] = total[i + 23] * rice[i].price;
                    outfile << rice[i].fullname << " " << p3[i] << " Ԫ" << endl;
                }

                for (int i = 0; i < 4; i++)
                {
                    outfile << "e�����Ʒ���������: " << endl;
                    outfile << spes[i].fullname << " " << total[i + 30] << " ��" << endl;
                    outfile << "e�����Ʒ���۶�����: " << endl;
                    p4[i] = total[i + 30] * spes[i].price;
                    outfile << spes[i].fullname << " " << p4[i] << " Ԫ" << endl;
                }
                break;
            }
            else
            {
                if (num == 1)
                {
                    cout << "���մ���������!";
                    break;
                }
                else
                {
                    cout << endl;
                    cout << "�˻���������󣬻�ʣ��" << --num << "�λ���" << endl;
                    cout << "�������˺�: ";
                    cin >> id;
                    cout << "����������: ";
                    pwd = "";
                }
            }
        }
    }
    outfile.close();
    cout << "������ϣ�����ļ��鿴���!" << endl;

    void free();
    system("pause");
    return 0;
}