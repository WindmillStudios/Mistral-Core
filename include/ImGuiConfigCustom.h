#pragma once

#include "Color.h"
#include "Vector.h"

// Imgui implementation for our vectors
#define IM_VEC2_CLASS_EXTRA          \
	constexpr ImVec2(const Vec2& f): \
		x(f.x),                      \
		y(f.y)                       \
	{                                \
	}                                \
	operator Vec2() const            \
	{                                \
		return Vec2(x, y);           \
	}

#define IM_VEC4_CLASS_EXTRA            \
	constexpr ImVec4(const Vec4& f):   \
		x(f.x),                        \
		y(f.y),                        \
		z(f.z),                        \
		w(f.w)                         \
	{                                  \
	}                                  \
	operator Vec4() const              \
	{                                  \
		return Vec4(x, y, z, w);       \
	}                                  \
	constexpr ImVec4(const Color4& f): \
		x(f.r),                        \
		y(f.g),                        \
		z(f.b),                        \
		w(f.a)                         \
	{                                  \
	}                                  \
	operator Color4() const            \
	{                                  \
		return Color4(x, y, z, w);     \
	}
