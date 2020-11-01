#include "../../../Header/Graphics/Sprites/Static_Sprite.h"
namespace Sparky
{
	namespace Graphics
	{
		StaticSprite::StaticSprite(float x, float y, float width, float height, Vector4& colour, Shader& shader)
			: Renderable2D(Vec3(x, y, 0), Vec2(width, height), color), m_Shader(shader);
		{
			m_VertexArray = new VertexArray();

			GLfloat vertices[] =
			{
				0,		0,		0,
				0,		height,	0,
				width,  height, 0,
				width,  0,		0
			};

			GLfloat colors[] =
			{
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};

			m_VertexArray->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->AddBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indicies[] =
			{
				0, 1, 2,
				2, 3, 0
			};

			m_IndexBuffer = new IndexBuffer(indicies, 6);
		}
		StaticSprite::~StaticSprite()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
	}
}