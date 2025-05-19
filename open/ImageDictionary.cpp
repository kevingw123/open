#include "ImageDictionary.h"
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

ImageDictionary::ImageDictionary(const string& folder) {
    for (const auto& entry : fs::directory_iterator(folder)) {
        if (entry.is_regular_file()) {
            string path = entry.path().string();
            string filename = entry.path().stem().string();  // 不含副檔名
            keyword_to_path[filename] = path;
        }
    }
}

bool ImageDictionary::showImage(const string& keyword) {
    auto it = keyword_to_path.find(keyword);
    if (it == keyword_to_path.end()) {
        cout << "找不到關鍵字：" << keyword << endl;
        return false;
    }

    string path = it->second;
    cv::Mat img = cv::imread(path);
    if (img.empty()) {
       cout << "無法讀取圖片：" << path << endl;
        return false;
    }

    cv::imshow("Image: " + keyword, img);
    cv::waitKey(0);  // 等待使用者按鍵
    return true;
}
