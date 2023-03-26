#include "lve_pipeline.hpp"
// std filestream header
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve {

LvePipeline::LvePipeline(LveDevice &device,
                         const std::string &vertfilePath,
                         const std::string &fragfilePath,
                         const PipelineConfigInfo& configInfo): lveDevice(device){
    createGraphicsPipeline(vertfilePath, fragfilePath, configInfo);

}

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

PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(__attribute__((unused)) uint32_t width,
                                                          __attribute__((unused)) uint32_t height) {
  PipelineConfigInfo configInfo{};
  return configInfo;
}

void LvePipeline::createGraphicsPipeline(const std::string &vertfilePath,
                                         const std::string &fragfilePath,
                                         __attribute__((unused)) const PipelineConfigInfo& configInfo) {
  auto vertCode = readFile(vertfilePath);
  auto fragCode = readFile(fragfilePath);

  std::cout << "Vertex Shader Code Size: " << vertCode.size() << std::endl;
  std::cout << "Fragment Shader Code Size: " << fragCode.size() << std::endl;
}

__attribute__((unused)) void LvePipeline::createShaderModule(const std::vector<char> &code,
                                     VkShaderModule *shaderModule) {
    VkShaderModuleCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
        throw std::runtime_error("failed to create shader module!");
    }


}



} // namespace lve