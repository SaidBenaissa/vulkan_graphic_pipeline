#include "lve_pipeline.hpp"
// std filestream header
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve {
    std::vector<char> LvePipeline::readFile(const std::string &filePath) {

        std::ifstream file(filePath, std::ios::ate | std::ios::binary);

        if (!file.is_open()) {
            throw std::runtime_error("failed to open file!" + filePath);
        }
        size_t fileSize = (size_t) file.tellg();
        std::vector<char> buffer(fileSize);
        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    LvePipeline::LvePipeline(const std::string &vertfilePath, const std::string &fragfilePath) {
        createGraphicsPipeline(vertfilePath, fragfilePath);
    }

    void LvePipeline::createGraphicsPipeline(const std::string &vertfilePath, const std::string &fragfilePath) {
        auto vertCode = readFile(vertfilePath);
        auto fragCode = readFile(fragfilePath);

        std::cout << "Vertex Shader Code Size: " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader Code Size: " << fragCode.size() << std::endl;
    }

} // namespace lve