#pragma once

#include "Renderable2D.h"

namespace Sparly {
	namespace Graphics {
		class Renderer2D
		{
		public:
			virtual void Submit(const Renderer2D& renderable)= 0;
			virtual void Flush() = 0;
		};
	}
}