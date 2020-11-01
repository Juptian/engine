#include "../../../Header/Graphics/Renderers/Renderable2D.h"


namespace Sparky 
{
	namespace Graphics 
	{
		Renderable2D::Renderable2D(Vector3 position, Vector2 size, Vector4 color)
			: m_Position(position), m_Size(size), m_Colour(color)
		{
			
		}

		Renderable2D::~Renderable2D()
		{
			
		}
	}
}