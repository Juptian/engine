#pragma once

#include <deque>
#include "../Graphics.h"
#include "../../Maths/Math.h"
#include "Renderer2D.h"


namespace Sparky
{
	namespace Graphics
	{
		class Simple2DRenderer : public Renderer2D
		{
		private:
			std::deque<const Renderable2D&> m_RenderQueue;

		public:
			void Submit(const Renderer2D& renderable) override;
			void Flush() override;
		};
	}
}