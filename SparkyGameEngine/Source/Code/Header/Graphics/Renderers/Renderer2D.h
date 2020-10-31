#pragma once

#include "../Graphics.h"

namespace Sparky
{
	namespace Graphics
	{
		class Renderer2D
		{
		public:
			virtual void Submit(const Renderable2D* renderable) = 0;
			virtual void Flush() = 0;
		};
	}
}