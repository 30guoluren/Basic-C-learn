#pragma once
#include <string>

inline std ::string project_path(const std::string &relative_path){
    return std::string(PROJECT_ROOT_DIR) + "/" + relative_path;
}