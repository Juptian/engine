#include "../../../Header/Graphics/Renderers/2DRenderer_S.h"

namespace Sparky
{
	namespace Graphics
	{
		void Simple2DRenderer::Submit(const Renderer2D & renderable)
		{
			m_RenderQueue.push_back(renderable);
		}
		void Simple2DRenderer::Flush()
		{
			while (!m_RenderQueue.empty())
			{
				const Renderable2D& renderable = m_RenderQueue.front();

				renderable.GetVAO()->bind();
				renderable.GetIBO()->bind();

				renderable.GetShader()->SetUniform4f("ml_matrix", Mat4::Translation(renderable.GetPosition))
				glDrawElements(GL_TRIANGLES, renderable.GetIBO()->GetCount(), GL_UNSIGNED_SHORT, nullptr);

				renderable.GetIBO()->Unbind;
				renderable.GetVAO()->Unbind();
			}
		}
	}
}