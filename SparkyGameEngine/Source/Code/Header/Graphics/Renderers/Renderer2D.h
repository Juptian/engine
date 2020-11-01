#pragma once

#include "../Graphics.h"

namespace Sparky
{
	namespace Graphics
	{
		struct VertexData
		{
			Vector3 vertex;
			Vector4 colours;
		}; //28 bytes of memory

		class Renderer2D
		{
		public:
			virtual void Submit(const Renderable2D* renderable) = 0;
			virtual void Flush() = 0;
		};
	}
}