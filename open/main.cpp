#include "ImageDictionary.h"
#include <iostream>

int main() {
    ImageDictionary dict("C:\\Users\\kevin\\Source\\Repos\\open\\photo");  // �������A���Ϥ���Ƨ�

   string input;
    cout << "��J����r����ܹϤ��]�Ҧp cat�Bdog�^�A��J q ���}�G" << endl;

    while (true) {
        cout << "> ";
        cin >> input;
        if (input == "q") break;

        dict.showImage(input);
    }

    return 0;
}
