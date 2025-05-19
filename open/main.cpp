#include "ImageDictionary.h"
#include <iostream>

int main() {
    ImageDictionary dict("C:\\Users\\kevin\\Source\\Repos\\open\\photo");  // 替換成你的圖片資料夾

   string input;
    cout << "輸入關鍵字來顯示圖片（例如 cat、dog），輸入 q 離開：" << endl;

    while (true) {
        cout << "> ";
        cin >> input;
        if (input == "q") break;

        dict.showImage(input);
    }

    return 0;
}
