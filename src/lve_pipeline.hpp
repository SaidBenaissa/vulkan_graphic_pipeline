#pragma once
#include <string>
#include <vector>


namespace lve {
    class LvePipeline {
    public:
        LvePipeline(const std::string& vertfilePath, const std::string& fragfilePath);

    private:
        static std::vector<char> readFile(const std::string& filePath);

        void createGraphicsPipeline(const std::string& vertfilePath, const std::string& fragfilePath);

    };
} // namespace lve