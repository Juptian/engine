#pragma once

#include "../Graphics.h"
namespace Sparky
{
	namespace Graphics
	{
		class Sprite : public Renderable2D
		{
		private:

		public:
			Sprite(float x, float y, float width, float height, Vector4& colour);
		};
	}
}
