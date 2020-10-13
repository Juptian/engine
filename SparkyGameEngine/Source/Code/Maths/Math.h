#pragma once

//Vectors
#include "Vectors\Vec2.h"
#include "Vectors\Vec3.h"
#include "Vectors\Vec4.h"

//Matrixes
#include "Mat4\Mat4.h"

//General defines
namespace sparky {
	namespace Math {
		inline float ToRadians(float degrees) { return degrees * float(M_PI / 180.f); }
	}
}

