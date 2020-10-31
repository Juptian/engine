#include "../../../Header/Graphics/Renderers/2DRenderer_S.h"

namespace Sparky
{
	namespace Graphics
	{
		void Simple2DRenderer::Submit(const Renderable2D* renderable)
		{
			m_RenderQueue.push_back(renderable);
		}
		void Simple2DRenderer::Flush()
		{
			while (!m_RenderQueue.empty())
			{
				const Renderable2D* renderable = m_RenderQueue.front();

				renderable->GetVAO()->Bind();
				renderable->GetIBO()->Bind();

				renderable->GetShader().SetUniformMat4("ml_matrix", Mat4::Translation(renderable->GetPosition()));
				glDrawElements(GL_TRIANGLES, renderable->GetIBO()->GetCount(), GL_UNSIGNED_SHORT, 0);

				renderable->GetIBO()->Unbind();
				renderable->GetVAO()->Unbind();

				m_RenderQueue.pop_front();
			}
		}
	}
}