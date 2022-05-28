//ordersystem
//author:babysen
//date:2022/01/05-07

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

const int strsize = 30;
const string flavor[8] = {"三鲜", "甜", "微微辣", "微辣", "麻辣", "中辣", "超辣", "番茄"}; //口味

//构造显示函数：
void display_menu();       //显示菜单
void display_name();       //菜名
void display_preference(); //显示咸淡口味

//void display_sex();        //统计男女生人数
//构建结构体,其中s是性别的另一种表达，s=0,1;0为女性，1为男性

struct order
{
    char fullname[strsize]; //菜全名
    int b;                  //菜编号
    int price;              //价格
};

//输入结构体数组的内容

//热卖推荐菜单
order hsr[6] =
    {
        {"香锅", 1, 15},
        {"肉夹馍", 2, 7},
        {"羊肉泡馍", 3, 24},
        {"洛阳烩菜", 4, 7},
        {"砂锅米线", 5, 7},
        {"泡面加蛋", 6, 6}};

//饺子菜单
order dump[8] =
    {
        {"大份大肉莲菜", 7, 10},
        {"小份大肉莲菜", 8, 8},
        {"大份韭菜鸡蛋", 9, 10},
        {"小份韭菜鸡蛋", 10, 8},
        {"大份大葱牛肉", 11, 12},
        {"小份大葱牛肉", 12, 10},
        {"大份大葱羊肉", 13, 12},
        {"小份大葱羊肉", 14, 10}};

//面食菜单
order noodle[10] =
    {
        {"大碗三合一面", 15, 11},
        {"小碗三合一面", 16, 10},
        {"大碗二合一面", 17, 10},
        {"小碗二合一面", 18, 9},
        {"大碗油泼面", 19, 9},
        {"小碗油泼面", 20, 8},
        {"大碗拉条子面", 21, 9},
        {"小碗拉条子面", 22, 8},
        {"大碗棍棍面", 23, 9},
        {"小碗棍棍面", 24, 8}};

//米饭菜单
order rice[7] =
    {
        {"两荤两素", 25, 8},
        {"一荤三素", 26, 8},
        {"一荤两素", 27, 7},
        {"三样素菜", 28, 6},
        {"小炒肉盖浇饭", 29, 11},
        {"茄子盖浇饭", 30, 9},
        {"番茄鸡蛋盖浇饭", 31, 9}};

//特色小吃菜单
order spes[4] =
    {
        {"一份油条", 32, 4},
        {"陕西凉皮", 33, 6},
        {"豆腐脑", 34, 2},
        {"葫芦头泡馍", 35, 13}};

//定义菜单函数
void display_menu()
{
    cout << "-----------------------------------------" << endl;
    cout << "|             长大餐厅菜单表             |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               a.热卖推荐               |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               b.饺子                   |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               c.面条                   |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               d.米饭                   |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               e.特色小吃               |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|               q.退出并统计             |" << endl;
    cout << "-----------------------------------------" << endl;
}

//定义菜名函数
void display_name()
{
    cout << "a.热卖推荐菜单如下: " << endl;
    for (int i = 0; i < 6; i++)
        cout << "菜名: " << hsr[i].fullname << ","
             << "编号: " << hsr[i].b << ","
             << "单价: " << hsr[i].price << "元" << endl;

    cout << "b.饺子: " << endl;
    for (int i = 0; i < 8; i++)
        cout << "菜名: " << dump[i].fullname << ","
             << "编号: " << dump[i].b << ","
             << "单价: " << dump[i].price << "元" << endl;

    cout << "c.面条: " << endl;
    for (int i = 0; i < 10; i++)
        cout << "菜名: " << noodle[i].fullname << ","
             << "编号: " << noodle[i].b << ","
             << "单价: " << noodle[i].price << "元" << endl;

    cout << "d.米饭: " << endl;
    for (int i = 0; i < 7; i++)
        cout << "菜名: " << rice[i].fullname << ","
             << "编号: " << rice[i].b << ","
             << "单价: " << rice[i].price << "元" << endl;

    cout << "e.特色小吃: " << endl;
    for (int i = 0; i < 4; i++)
        cout << "菜名: " << spes[i].fullname << ","
             << "编号: " << spes[i].b << ","
             << "单价: " << spes[i].price << "元" << endl;
}

//定义个人口味函数
void display_preference()
{
    cout << "--------------------------------------" << endl;
    cout << "|    1.三鲜, 2.甜, 3.微微辣, 4.微辣    |" << endl;
    cout << "|    5.麻辣, 6.中辣, 7.超辣, 8.番茄    |" << endl;
    cout << "--------------------------------------" << endl;
}

//统计男女生人数函数
/* void display_sex()
{
    for (int i = 0; i < NUM; i++)
        cout << people[i].fullname << " 's sex is: " << people[i].sex << endl;
} */

//主函数
int main()
{
    //数据写入文件
    ofstream outfile("statis.xls", ios::trunc); //输出结果存储在statis文件中
    if (!outfile)
    {
        cerr << "打开错误!" << endl;
        exit(1);
    }
    //1.初始化，设定账号和密码。
    long int ID = 20220106;
    int num = 6; //输入密码次数
    //2.建立存储信息的变量。
    long int id;
    //3.完成do-while循环结构中输入的内容
    cout << "请输入账号: ";
    cin >> id;
    int i = 0;
    //初始化一个空字符串,s是密码字符串
    string pwd = "", s = "666666";
    cout << "请输入密码: ";
    char c;
    while (true)
    {
        c = getch();
        if (c != 13) //如果不是回车，就不断往string类型的pwd内添加c
        {
            pwd = pwd + c;
            cout << "*";
        }
        else
        {
            if (pwd == s && id == ID)
            {
                cout << endl;
                cout << "                 登陆成功                " << endl;
                cout << "-----------------------------------------" << endl;
                char ch;       //菜种类选择序号
                int nn;        //口味选择序号
                double p0[6];  //a类菜的价钱
                double p1[8];  //b类菜的价钱
                double p2[10]; //c类菜的价钱
                double p3[7];  //d类菜的价钱
                double p4[4];  //e类菜的价钱
                long int total[35] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //各菜初始点餐数量 
                //long int total[]={};
                cout << "欢迎光临长安大学食堂就餐，菜单如下: " << endl;
                display_menu();
                cout << endl;
                display_name();
                cout << endl;
                display_preference();
                cout << "______________________________" << endl;
                cout << "______________________________" << endl;
                cout << "请用字母输入您想吃哪个种类的菜品: " << endl;
                while (cin >> ch && ch != 'q' && ch != 'Q')
                {
                    cout << "输入菜名简称" << endl;
                    int bi;     //菜编号
                    switch (ch) //case分支大括号可以不要，这里为了方便观看加上了
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

                    cout << "输入口味选项:" << endl;
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
                            cout << "选择错误" << endl;
                        }
                        break;
                    }
                    cout << "请继续用字母输入您想吃哪个种类的菜品: " << endl;
                }

                for (int i = 0; i < 6; i++)
                {
                    p0[i] = total[i] * hsr[i].price;
                    outfile << "a类各菜品点餐数如下: " << endl;
                    outfile << hsr[i].fullname << " " << total[i] << " 份" << endl;
                    outfile << "a类各菜品销售额如下: " << endl;
                    p0[i] = total[i] * hsr[i].price;
                    outfile << hsr[i].fullname << " " << p0[i] << " 元" << endl;
                }

                for (int i = 0; i < 8; i++)
                {
                    outfile << "b类各菜品点餐数如下: " << endl;
                    outfile << dump[i].fullname << " " << total[i + 5] << " 份" << endl;
                    outfile << "b类各菜品销售额如下: " << endl;
                    p1[i] = total[i + 5] * dump[i].price;
                    outfile << dump[i].fullname << " " << p1[i] << " 元" << endl;
                }

                for (int i = 0; i < 10; i++)
                {
                    outfile << "c类各菜品点餐数如下: " << endl;
                    outfile << noodle[i].fullname << " " << total[i + 13] << " 份" << endl;
                    outfile << "c类各菜品销售额如下: " << endl;
                    p2[i] = total[i + 13] * noodle[i].price;
                    outfile << noodle[i].fullname << " " << p2[i] << " 元" << endl;
                }

                for (int i = 0; i < 7; i++)
                {
                    outfile << "d类各菜品点餐数如下: " << endl;
                    outfile << rice[i].fullname << " " << total[i + 23] << " 份" << endl;
                    outfile << "d类各菜品销售额如下: " << endl;
                    p3[i] = total[i + 23] * rice[i].price;
                    outfile << rice[i].fullname << " " << p3[i] << " 元" << endl;
                }

                for (int i = 0; i < 4; i++)
                {
                    outfile << "e类各菜品点餐数如下: " << endl;
                    outfile << spes[i].fullname << " " << total[i + 30] << " 份" << endl;
                    outfile << "e类各菜品销售额如下: " << endl;
                    p4[i] = total[i + 30] * spes[i].price;
                    outfile << spes[i].fullname << " " << p4[i] << " 元" << endl;
                }
                break;
            }
            else
            {
                if (num == 1)
                {
                    cout << "今日次数已用完!";
                    break;
                }
                else
                {
                    cout << endl;
                    cout << "账户或密码错误，还剩余" << --num << "次机会" << endl;
                    cout << "请输入账号: ";
                    cin >> id;
                    cout << "请输入密码: ";
                    pwd = "";
                }
            }
        }
    }
    outfile.close();
    cout << "处理完毕，请打开文件查看结果!" << endl;

    void free();
    system("pause");
    return 0;
}