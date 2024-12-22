// #include Project 0.0.2
// buildTime: 2024/08/16
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

void simpleCalculator() {
    char operatorChar;
    double num1, num2;
    int quitNum;

    do {
        cout << "欢迎使用简易计算器!目前只支持加,减,乘,除四种运算。" << endl;
        cout << "1.开始计算" << endl;
        cout << "按其他键及回车退出" << endl;
        cin >> quitNum;
        if (quitNum != 1) {
            return;
        }

        cout << "请输入第一个数字: ";
        while (!(cin >> num1)) {
            cout << "输入错误，请输入一个数字: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "请输入运算符 (+, -, *, /): ";
        cin >> operatorChar;

        cout << "请输入第二个数字: ";
        while (!(cin >> num2)) {
            cout << "输入错误，请输入一个数字: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        double result;
        switch (operatorChar) {
            case '+':
                result = num1 + num2;
                cout << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "错误:除数不能为零" << endl;
                }
                break;
            default:
                cout << "错误:不支持的运算符" << endl;
                break;
        }
    } while (quitNum == 1);
}

int main() {
    int optchar;
    SetConsoleOutputCP(CP_UTF8);
    do {
        cout << "欢迎来到#include Project!" << endl;
        auto now = chrono::system_clock::now();
        time_t now_c = chrono::system_clock::to_time_t(now);
        cout << "现在时间:" << put_time(localtime(&now_c), "%Y-%m-%d %X") << endl;

        cout << "请选择应用:" << endl;
        cout << "1.简易计算器" << endl;
        cout << "2.返回桌面" << endl;
        cout << "3.退出程序" << endl;
        cin >> optchar;

        switch (optchar) {
            case 1:
                simpleCalculator();
                break;
            case 2:
                // 返回桌面，这里可以添加返回桌面的逻辑
                break;
            case 3:
                // 退出程序
                return 0;
            default:
                cout << "您输入的不是一个本程序可识别的操作,请重新输入:" << endl;
                break;
        } 
    } while (optchar != 3);
    return 0;
}