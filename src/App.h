#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <memory>

namespace slingshot {
	class App {
	public:
		App();
		~App();
		virtual void Draw();
		void Execute();
	private:
		GLFWwindow* window;
	};
}