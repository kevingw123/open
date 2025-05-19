#ifndef IMAGEDICTIONARY_H
#define IMAGEDICTIONARY_H

#include <string>
#include <unordered_map>
using namespace std;


class ImageDictionary {
public:
    ImageDictionary(const std::string& folder);
    bool showImage(const std::string& keyword);

private:
    unordered_map<string, string> keyword_to_path;
};

#endif
