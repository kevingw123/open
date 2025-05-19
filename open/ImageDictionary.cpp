#include "ImageDictionary.h"
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

ImageDictionary::ImageDictionary(const string& folder) {
    for (const auto& entry : fs::directory_iterator(folder)) {
        if (entry.is_regular_file()) {
            string path = entry.path().string();
            string filename = entry.path().stem().string();  // ���t���ɦW
            keyword_to_path[filename] = path;
        }
    }
}

bool ImageDictionary::showImage(const string& keyword) {
    auto it = keyword_to_path.find(keyword);
    if (it == keyword_to_path.end()) {
        cout << "�䤣������r�G" << keyword << endl;
        return false;
    }

    string path = it->second;
    cv::Mat img = cv::imread(path);
    if (img.empty()) {
       cout << "�L�kŪ���Ϥ��G" << path << endl;
        return false;
    }

    cv::imshow("Image: " + keyword, img);
    cv::waitKey(0);  // ���ݨϥΪ̫���
    return true;
}
