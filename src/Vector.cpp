#include "Vector.h"

#include <algorithm>
#include <cassert>
#include <cmath>

#include "Color.h"
#include "imgui.h"

const Vec2 Vec2::Zero = {0.f, 0.f};
const Vec2 Vec2::One = {1.f, 1.f};
const Vec2 Vec2::Up = {0.f, 1.f};
const Vec2 Vec2::Down = {0.f, -1.f};
const Vec2 Vec2::Left = {-1.f, 0.f};
const Vec2 Vec2::Right = {1.f, 0.f};

const Vec3 Vec3::Zero = {0.f, 0.f, 0.f};
const Vec3 Vec3::One = {1.f, 1.f, 1.f};
const Vec3 Vec3::Up = {0.f, 1.f, 0.f};
const Vec3 Vec3::Down = {0.f, -1.f, 0.f};
const Vec3 Vec3::Left = {-1.f, 0.f, 0.f};
const Vec3 Vec3::Right = {1.f, 0.f, 0.f};
const Vec3 Vec3::Forward = {0.f, 0.f, 1.f};
const Vec3 Vec3::Back = {0.f, 0.f, -1.f};

const Vec4 Vec4::Zero = {0.f, 0.f, 0.f, 0.f};
const Vec4 Vec4::One = {1.f, 1.f, 1.f, 1.f};

// Parametrized constructors
Vec2::Vec2(const float x, const float y):
	x(x),
	y(y)
{
}

Vec2::Vec2(const float value):
	x(value),
	y(value)
{
}

// Copy constructors
Vec2::Vec2(const Vec3& vector):
	x(vector.x),
	y(vector.y)
{
}

Vec2::Vec2(const Vec4& vector):
	x(vector.x),
	y(vector.y)
{
}

Vec2::Vec2(const Vector2& vector):
	x(vector.x),
	y(vector.y)
{
}

Vec2::Vec2(const ImVec2& vector):
	x(vector.x),
	y(vector.y)
{
}

// Conversion operators
Vec2::operator Vector2() const
{
	return {x, y};
}

Vec2::operator ImVec2() const
{
	return {x, y};
}

// Access operators
float& Vec2::operator[](const std::size_t index)
{
	assert(index <= 1);
	switch (index)
	{
		case 0:
			return x;
		case 1:
			return y;
		default:
			break;
	}
	return x;
}

float Vec2::operator[](const std::size_t index) const
{
	assert(index <= 1);
	switch (index)
	{
		case 0:
			return x;
		case 1:
			return y;
		default:
			break;
	}
	return x;
}

// Compound assignment operators
Vec2& Vec2::operator+=(const Vec2& vector) noexcept
{
	x += vector.x;
	y += vector.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& vector) noexcept
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}

Vec2& Vec2::operator*=(const Vec2& vector) noexcept
{
	x *= vector.x;
	y *= vector.y;
	return *this;
}

Vec2& Vec2::operator/=(const Vec2& vector)
{
	x /= vector.x;
	y /= vector.y;
	return *this;
}

Vec2& Vec2::operator^=(const Vec2& vector) noexcept
{
	x = std::pow(x, vector.x);
	y = std::pow(y, vector.y);
	return *this;
}

Vec2& Vec2::operator+=(const float value) noexcept
{
	x += value;
	y += value;
	return *this;
}

Vec2& Vec2::operator-=(const float value) noexcept
{
	x -= value;
	y -= value;
	return *this;
}

Vec2& Vec2::operator*=(const float value) noexcept
{
	x *= value;
	y *= value;
	return *this;
}

Vec2& Vec2::operator/=(const float value)
{
	x /= value;
	y /= value;
	return *this;
}

Vec2& Vec2::operator^=(const float value) noexcept
{
	x = std::pow(x, value);
	y = std::pow(y, value);
	return *this;
}

// Arithmetic operators
Vec2 operator+(const Vec2& leftOperand, const Vec2& rightOperand) noexcept
{
	return {leftOperand.x + rightOperand.x, leftOperand.y + rightOperand.y};
}

Vec2 operator-(const Vec2& leftOperand, const Vec2& rightOperand) noexcept
{
	return {leftOperand.x - rightOperand.x, leftOperand.y - rightOperand.y};
}

Vec2 operator*(const Vec2& leftOperand, const Vec2& rightOperand) noexcept
{
	return {leftOperand.x * rightOperand.x, leftOperand.y * rightOperand.y};
}

Vec2 operator/(const Vec2& leftOperand, const Vec2& rightOperand)
{
	return {leftOperand.x / rightOperand.x, leftOperand.y / rightOperand.y};
}

Vec2 operator^(const Vec2& leftOperand, const Vec2& rightOperand) noexcept
{
	return {std::pow(leftOperand.x, rightOperand.x), std::pow(leftOperand.y, rightOperand.y)};
}

Vec2 operator+(const Vec2& leftOperand, float rightOperand) noexcept
{
	return {leftOperand.x + rightOperand, leftOperand.y + rightOperand};
}

Vec2 operator-(const Vec2& leftOperand, float rightOperand) noexcept
{
	return {leftOperand.x - rightOperand, leftOperand.y - rightOperand};
}

Vec2 operator*(const Vec2& leftOperand, float rightOperand) noexcept
{
	return {leftOperand.x * rightOperand, leftOperand.y * rightOperand};
}

Vec2 operator/(const Vec2& leftOperand, float rightOperand)
{
	return {leftOperand.x / rightOperand, leftOperand.y / rightOperand};
}

Vec2 operator^(const Vec2& leftOperand, float rightOperand) noexcept
{
	return {
		std::pow(leftOperand.x, rightOperand),
		std::pow(leftOperand.y, rightOperand),
	};
}

Vec2 operator+(const float leftOperand, const Vec2& rightOperand) noexcept
{
	return {leftOperand + rightOperand.x, leftOperand + rightOperand.y};
}

Vec2 operator-(const float leftOperand, const Vec2& rightOperand) noexcept
{
	return {leftOperand - rightOperand.x, leftOperand - rightOperand.y};
}

Vec2 operator*(const float leftOperand, const Vec2& rightOperand) noexcept
{
	return {leftOperand * rightOperand.x, leftOperand * rightOperand.y};
}

Vec2 operator/(const float leftOperand, const Vec2& rightOperand)
{
	return {leftOperand / rightOperand.x, leftOperand / rightOperand.y};
}

Vec2 operator^(const float leftOperand, const Vec2& rightOperand) noexcept
{
	return {
		std::pow(leftOperand, rightOperand.x),
		std::pow(leftOperand, rightOperand.y),
	};
}

// Functionalities
float Vec2::Length() const
{
	return sqrtf(x * x + y * y);
}

Vec2 Vec2::Normalized() const
{
	if (const float len = Length(); len > 1e-6f)
	{
		return *this / len;
	}
	return {};
}

Vec2 Vec2::Clamp(const float min, const float max) const
{
	return {std::clamp(x, min, max), std::clamp(y, min, max)};
}

Vec2 Vec2::Lerp(const Vec2 target, const float amount) const
{
	return *this + (target - *this) * amount;
}

// Parametrized constructors
Vec3::Vec3(const float x, const float y, const float z):
	x(x),
	y(y),
	z(z)
{
}

Vec3::Vec3(const float value):
	x(value),
	y(value),
	z(value)
{
}

// Copy constructors
Vec3::Vec3(const Vec2& vector, const float z):
	x(vector.x),
	y(vector.y),
	z(z)
{
}

Vec3::Vec3(const Vec4& vector):
	x(vector.x),
	y(vector.y),
	z(vector.z)
{
}

Vec3::Vec3(const Color3& color):
	x(color.r),
	y(color.g),
	z(color.b)
{
}

Vec3::Vec3(const Vector3& vector):
	x(vector.x),
	y(vector.y),
	z(vector.z)
{
}

// Conversion operators
Vec3::operator Vector3() const
{
	return {x, y, z};
}

// Access operators
float& Vec3::operator[](const std::size_t index)
{
	assert(index <= 2);
	switch (index)
	{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			break;
	}
	return x;
}

float Vec3::operator[](const std::size_t index) const
{
	assert(index <= 2);
	switch (index)
	{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			break;
	}
	return x;
}

// Compound assignment operators
Vec3& Vec3::operator+=(const Vec3& vector) noexcept
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& vector) noexcept
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

Vec3& Vec3::operator*=(const Vec3& vector) noexcept
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
	return *this;
}

Vec3& Vec3::operator/=(const Vec3& vector)
{
	x /= vector.x;
	y /= vector.y;
	z /= vector.z;
	return *this;
}

Vec3& Vec3::operator^=(const Vec3& vector) noexcept
{
	x = std::pow(x, vector.x);
	y = std::pow(y, vector.y);
	z = std::pow(z, vector.z);
	return *this;
}

Vec3& Vec3::operator+=(const float value) noexcept
{
	x += value;
	y += value;
	z += value;
	return *this;
}

Vec3& Vec3::operator-=(const float value) noexcept
{
	x -= value;
	y -= value;
	z -= value;
	return *this;
}

Vec3& Vec3::operator*=(const float value) noexcept
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vec3& Vec3::operator/=(const float value)
{
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

Vec3& Vec3::operator^=(const float value) noexcept
{
	x = std::pow(x, value);
	y = std::pow(y, value);
	z = std::pow(z, value);
	return *this;
}

// Arithmetic operators
Vec3 operator+(const Vec3& leftOperand, const Vec3& rightOperand) noexcept
{
	return {leftOperand.x + rightOperand.x, leftOperand.y + rightOperand.y, leftOperand.z + rightOperand.z};
}

Vec3 operator-(const Vec3& leftOperand, const Vec3& rightOperand) noexcept
{
	return {leftOperand.x - rightOperand.x, leftOperand.y - rightOperand.y, leftOperand.z - rightOperand.z};
}

Vec3 operator*(const Vec3& leftOperand, const Vec3& rightOperand) noexcept
{
	return {leftOperand.x * rightOperand.x, leftOperand.y * rightOperand.y, leftOperand.z * rightOperand.z};
}

Vec3 operator/(const Vec3& leftOperand, const Vec3& rightOperand)
{
	return {leftOperand.x / rightOperand.x, leftOperand.y / rightOperand.y, leftOperand.z / rightOperand.z};
}

Vec3 operator^(const Vec3& leftOperand, const Vec3& rightOperand) noexcept
{
	return {std::pow(leftOperand.x, rightOperand.x), std::pow(leftOperand.y, rightOperand.y), std::pow(leftOperand.z, rightOperand.z)};
}

Vec3 operator+(const Vec3& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x + rightOperand, leftOperand.y + rightOperand, leftOperand.z + rightOperand};
}

Vec3 operator-(const Vec3& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x - rightOperand, leftOperand.y - rightOperand, leftOperand.z - rightOperand};
}

Vec3 operator*(const Vec3& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x * rightOperand, leftOperand.y * rightOperand, leftOperand.z * rightOperand};
}

Vec3 operator/(const Vec3& leftOperand, const float rightOperand)
{
	return {leftOperand.x / rightOperand, leftOperand.y / rightOperand, leftOperand.z / rightOperand};
}

Vec3 operator^(const Vec3& leftOperand, const float rightOperand) noexcept
{
	return {std::pow(leftOperand.x, rightOperand), std::pow(leftOperand.y, rightOperand), std::pow(leftOperand.z, rightOperand)};
}

Vec3 operator+(const float leftOperand, const Vec3& rightOperand) noexcept
{
	return {leftOperand + rightOperand.x, leftOperand + rightOperand.y, leftOperand + rightOperand.z};
}

Vec3 operator-(const float leftOperand, const Vec3& rightOperand) noexcept
{
	return {leftOperand - rightOperand.x, leftOperand - rightOperand.y, leftOperand - rightOperand.z};
}

Vec3 operator*(const float leftOperand, const Vec3& rightOperand) noexcept
{
	return {leftOperand * rightOperand.x, leftOperand * rightOperand.y, leftOperand * rightOperand.z};
}

Vec3 operator/(const float leftOperand, const Vec3& rightOperand)
{
	return {leftOperand / rightOperand.x, leftOperand / rightOperand.y, leftOperand / rightOperand.z};
}

Vec3 operator^(const float leftOperand, const Vec3& rightOperand) noexcept
{
	return {std::pow(leftOperand, rightOperand.x), std::pow(leftOperand, rightOperand.y), std::pow(leftOperand, rightOperand.z)};
}

// Functionalities
float Vec3::Length() const
{
	return sqrtf(x * x + y * y + z * z);
}

float Vec3::LengthSqr() const
{
	return x * x + y * y + z * z;
}

Vec3 Vec3::Normalized() const
{
	if (const float len = Length(); len > 1e-6f)
	{
		return *this / len;
	}
	return {};
}

Vec3 Vec3::Lerp(const Vec3& target, const float amount) const
{
	return *this + (target - *this) * amount;
}

Vec3 Vec3::Clamp(const float min, const float max) const
{
	return {std::clamp(x, min, max), std::clamp(y, min, max), std::clamp(z, min, max)};
}

float Vec3::Dot(const Vec3& vector) const
{
	return x * vector.x + y * vector.y + z * vector.z;
}

Vec3 Vec3::Cross(const Vec3& vector) const
{
	return {y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x};
}

float Vec3::Angle(const Vec3& vector) const
{
	const float len1 = this->Length();
	const float len2 = vector.Length();

	if (len1 < 1e-6f || len2 < 1e-6f)
	{
		return 0.0f;
	}

	const float cosTheta = Dot(vector) / (len1 * len2);
	const float clampedCos = std::clamp(cosTheta, -1.0f, 1.0f);

	return acosf(clampedCos);
}

float Vec3::Distance(const Vec3& vector) const
{
	return (*this - vector).Length();
}

float Vec3::DistanceSqr(const Vec3& vector) const
{
	return (*this - vector).LengthSqr();
}

Vec3 Vec3::Reflect(const Vec3& normal) const
{
	return *this - 2.0f * Dot(normal) * normal;
}

// Parametrized constructors
Vec4::Vec4(const float x, const float y, const float z, const float w):
	x(x),
	y(y),
	z(z),
	w(w)
{
}

Vec4::Vec4(const float value):
	x(value),
	y(value),
	z(value),
	w(value)
{
}

// Copy constructors
Vec4::Vec4(const Vec2& vector, const float z, const float w):
	x(vector.x),
	y(vector.y),
	z(z),
	w(w)
{
}

Vec4::Vec4(const Vec3& vector, const float w):
	x(vector.x),
	y(vector.y),
	z(vector.z),
	w(w)
{
}

Vec4::Vec4(const Color4& color):
	x(color.r),
	y(color.g),
	z(color.b),
	w(color.a)
{
}

Vec4::Vec4(const Vector4& vector):
	x(vector.x),
	y(vector.y),
	z(vector.z),
	w(vector.w)
{
}

// Conversion operators
Vec4::operator Vector4() const
{
	return {x, y, z, w};
}

Vec4::operator ImVec4() const
{
	return {x, y, z, w};
}

// Access operators
float& Vec4::operator[](const std::size_t index)
{
	assert(index <= 3);
	switch (index)
	{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			break;
	}
	return x;
}

float Vec4::operator[](const std::size_t index) const
{
	assert(index <= 3);
	switch (index)
	{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			break;
	}
	return x;
}

// Compound assignment operators
Vec4& Vec4::operator+=(const Vec4& vector) noexcept
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	w += vector.w;
	return *this;
}

Vec4& Vec4::operator-=(const Vec4& vector) noexcept
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	w -= vector.w;
	return *this;
}

Vec4& Vec4::operator*=(const Vec4& vector) noexcept
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
	w *= vector.w;
	return *this;
}

Vec4& Vec4::operator/=(const Vec4& vector)
{
	x /= vector.x;
	y /= vector.y;
	z /= vector.z;
	w /= vector.w;
	return *this;
}

Vec4& Vec4::operator^=(const Vec4& vector) noexcept
{
	x = std::pow(x, vector.x);
	y = std::pow(y, vector.y);
	z = std::pow(z, vector.z);
	w = std::pow(w, vector.w);
	return *this;
}

Vec4& Vec4::operator+=(const float value) noexcept
{
	x += value;
	y += value;
	z += value;
	w += value;
	return *this;
}

Vec4& Vec4::operator-=(const float value) noexcept
{
	x -= value;
	y -= value;
	z -= value;
	w -= value;
	return *this;
}

Vec4& Vec4::operator*=(const float value) noexcept
{
	x *= value;
	y *= value;
	z *= value;
	w *= value;
	return *this;
}

Vec4& Vec4::operator/=(const float value)
{
	x /= value;
	y /= value;
	z /= value;
	w /= value;
	return *this;
}

Vec4& Vec4::operator^=(const float value) noexcept
{
	x = std::pow(x, value);
	y = std::pow(y, value);
	z = std::pow(z, value);
	w = std::pow(w, value);
	return *this;
}

// Arithmetic operators
Vec4 operator+(const Vec4& leftOperand, const Vec4& rightOperand) noexcept
{
	return {leftOperand.x + rightOperand.x, leftOperand.y + rightOperand.y, leftOperand.z + rightOperand.z, leftOperand.w + rightOperand.w};
}

Vec4 operator-(const Vec4& leftOperand, const Vec4& rightOperand) noexcept
{
	return {leftOperand.x - rightOperand.x, leftOperand.y - rightOperand.y, leftOperand.z - rightOperand.z, leftOperand.w - rightOperand.w};
}

Vec4 operator*(const Vec4& leftOperand, const Vec4& rightOperand) noexcept
{
	return {leftOperand.x * rightOperand.x, leftOperand.y * rightOperand.y, leftOperand.z * rightOperand.z, leftOperand.w * rightOperand.w};
}

Vec4 operator/(const Vec4& leftOperand, const Vec4& rightOperand)
{
	return {leftOperand.x / rightOperand.x, leftOperand.y / rightOperand.y, leftOperand.z / rightOperand.z, leftOperand.w / rightOperand.w};
}

Vec4 operator^(const Vec4& leftOperand, const Vec4& rightOperand) noexcept
{
	return {std::pow(leftOperand.x, rightOperand.x), std::pow(leftOperand.y, rightOperand.y), std::pow(leftOperand.z, rightOperand.z),
			std::pow(leftOperand.w, rightOperand.w)};
}

Vec4 operator+(const Vec4& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x + rightOperand, leftOperand.y + rightOperand, leftOperand.z + rightOperand, leftOperand.w + rightOperand};
}

Vec4 operator-(const Vec4& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x - rightOperand, leftOperand.y - rightOperand, leftOperand.z - rightOperand, leftOperand.w - rightOperand};
}

Vec4 operator*(const Vec4& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x * rightOperand, leftOperand.y * rightOperand, leftOperand.z * rightOperand, leftOperand.w * rightOperand};
}

Vec4 operator/(const Vec4& leftOperand, const float rightOperand)
{
	return {leftOperand.x / rightOperand, leftOperand.y / rightOperand, leftOperand.z / rightOperand, leftOperand.w / rightOperand};
}

Vec4 operator^(const Vec4& leftOperand, const float rightOperand) noexcept
{
	return {std::pow(leftOperand.x, rightOperand), std::pow(leftOperand.y, rightOperand), std::pow(leftOperand.z, rightOperand),
			std::pow(leftOperand.w, rightOperand)};
}

Vec4 operator+(const float leftOperand, const Vec4& rightOperand) noexcept
{
	return {leftOperand + rightOperand.x, leftOperand + rightOperand.y, leftOperand + rightOperand.z, leftOperand + rightOperand.w};
}

Vec4 operator-(const float leftOperand, const Vec4& rightOperand) noexcept
{
	return {leftOperand - rightOperand.x, leftOperand - rightOperand.y, leftOperand - rightOperand.z, leftOperand - rightOperand.w};
}

Vec4 operator*(const float leftOperand, const Vec4& rightOperand) noexcept
{
	return {leftOperand * rightOperand.x, leftOperand * rightOperand.y, leftOperand * rightOperand.z, leftOperand * rightOperand.w};
}

Vec4 operator/(const float leftOperand, const Vec4& rightOperand)
{
	return {leftOperand / rightOperand.x, leftOperand / rightOperand.y, leftOperand / rightOperand.z, leftOperand / rightOperand.w};
}

Vec4 operator^(const float leftOperand, const Vec4& rightOperand) noexcept
{
	return {std::pow(leftOperand, rightOperand.x), std::pow(leftOperand, rightOperand.y), std::pow(leftOperand, rightOperand.z),
			std::pow(leftOperand, rightOperand.w)};
}

// Functionalities
float Vec4::Length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

Vec4 Vec4::Normalized() const
{
	if (const float len = Length(); len > 1e-6f)
	{
		return *this / len;
	}
	return {};
}

Vec4 Vec4::Clamp(const float min, const float max) const
{
	return {std::clamp(x, min, max), std::clamp(y, min, max), std::clamp(z, min, max), std::clamp(w, min, max)};
}