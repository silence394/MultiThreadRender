#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
#include "Public/OpenGLProgram.h"

GLFWwindow* GWindow = nullptr;
void Test()
{
	while (!glfwWindowShouldClose(GWindow))
	{
		glfwTerminate();
		glClearColor(0.3f, 0.2f, 0.2f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(GWindow);
		glfwPollEvents();
	}
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GWindow = glfwCreateWindow(1344, 768, "MultiThreadRender", NULL, NULL);
	if (GWindow == nullptr)
		glfwTerminate();

	glfwMakeContextCurrent(GWindow);
	//glfwSetFramebufferSizeCallback(window, onResize);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		return 0;
	}

	std::thread rhiThread = std::thread(Test);

	rhiThread.join();

	return 0;
}