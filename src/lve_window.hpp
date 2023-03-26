//
// Created by Saïd Benaissa on 25/03/2023.
//

#ifndef VULKAN_SAMPLE_1_LVE_WINDOW_H
#define VULKAN_SAMPLE_1_LVE_WINDOW_H
#pragma once

#define GLFW_INCLUDE_VULKAN

#include<GLFW/glfw3.h>
#include <string>

namespace lve {
    class LveWindow {
    public:
        LveWindow(int w, int h, std::string name);
        LveWindow(const LveWindow &) = delete;
        LveWindow &operator=(const LveWindow &) = delete;
        ~LveWindow();


        GLFWwindow *getWindow();

        bool shouldClose();

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *vkSurfaceKhr);

    private:
        void initWindow();

        const int width;
        const int height;
        std::string windowName;
        GLFWwindow *window;
    };
}


#endif //VULKAN_SAMPLE_1_LVE_WINDOW_H
