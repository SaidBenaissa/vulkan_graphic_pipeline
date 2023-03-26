//
// Created by Saïd Benaissa on 25/03/2023.
//

#include "lve_window.hpp"

namespace lve {

    LveWindow::LveWindow(int w, int h, std::string name) : width(w), height(h), windowName(std::move(name)) {
        initWindow();
    }

    LveWindow::~LveWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void LveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    bool LveWindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *vkSurfaceKhr) {
        if (glfwCreateWindowSurface(instance, window, nullptr, vkSurfaceKhr) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface!");
        }

    }


}

