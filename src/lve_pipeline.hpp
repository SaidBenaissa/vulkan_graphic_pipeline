#pragma once
#include <string>
#include <vector>
#include "lve_device.hpp"

namespace lve {

struct PipelineConfigInfo {};

class LvePipeline {
 public:
  LvePipeline(LveDevice &device,
              const std::string &vertfilePath,
              const std::string &fragfilePath,
              const PipelineConfigInfo &configInfo);

  ~LvePipeline() {};

  LvePipeline(const LvePipeline &) = delete;

  LvePipeline operator=(const LvePipeline &) = delete;

  static PipelineConfigInfo defaultPipelineConfigInfo(__attribute__((unused)) uint32_t width,
                                                      __attribute__((unused)) uint32_t height);

 private:
  static std::vector<char> readFile(const std::string &filePath);

  static void createGraphicsPipeline(const std::string &vertfilePath,
                              const std::string &fragfilePath,
                                     __attribute__((unused)) const PipelineConfigInfo &configInfo);

  __attribute__((unused)) void createShaderModule(const std::vector<char> &code,
                          VkShaderModule *shaderModule);

  LveDevice &
      lveDevice; // Agregation. reference to the device that will be used to create the pipeline
  VkPipeline graphicsPipeline{};
  VkShaderModule vertShaderModule{};
  VkShaderModule fragShaderModule{};
  void createGraphicsPipeline(const std::string &vertfilePath,
                              const std::string &fragfilePath);
};
} // namespace lve