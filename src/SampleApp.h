#pragma once
#include "App.h"

namespace slingshot {
	class SampleApp : App {
	public:
		SampleApp();
		void Draw();
		using App::Execute;
	private:
		unsigned int VBO, VAO, EBO;
	};
}