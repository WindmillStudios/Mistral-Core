#pragma once

#include <ostream>

#include "raylib.h"

struct Vec2;
struct Vec3;
struct Vec4;
struct Color3;
struct Color4;
struct ImVec2;
struct ImVec4;

struct Vec2
{
	float x = 0.0f;
	float y = 0.0f;

	static const Vec2 Zero;
	static const Vec2 One;
	static const Vec2 Up;
	static const Vec2 Down;
	static const Vec2 Left;
	static const Vec2 Right;

	// Default and parametrized constructors
	Vec2() = default;

	Vec2(float x, float y);

	explicit Vec2(float value);

	// Copy constructors
	Vec2(const Vec2& vector) = default;

	Vec2(const Vec3& vector);

	Vec2(const Vec4& vector);

	Vec2(const Vector2& vector);

	Vec2(const ImVec2& vector);

	// Conversion operators
	[[nodiscard]] operator Vector2() const;

	[[nodiscard]] operator ImVec2() const;

	// Access operators
	[[nodiscard]] float& operator[](std::size_t index);

	[[nodiscard]] float operator[](std::size_t index) const;

	// Binary operators
	[[nodiscard]] friend constexpr bool operator==(const Vec2& leftOperand, const Vec2& rightOperand) noexcept = default;

	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
	{
		stream << "Vec2(" << vector.x << ", " << vector.y << ")";
		return stream;
	}

	// Compound assignment operators
	Vec2& operator+=(const Vec2& vector) noexcept;

	Vec2& operator-=(const Vec2& vector) noexcept;

	Vec2& operator*=(const Vec2& vector) noexcept;

	Vec2& operator/=(const Vec2& vector);

	Vec2& operator^=(const Vec2& vector) noexcept;

	Vec2& operator+=(float value) noexcept;

	Vec2& operator-=(float value) noexcept;

	Vec2& operator*=(float value) noexcept;

	Vec2& operator/=(float value);

	Vec2& operator^=(float value) noexcept;

	// Functionalities
	[[nodiscard]] float Length() const;

	[[nodiscard]] Vec2 Normalized() const;

	[[nodiscard]] Vec2 Clamp(float min, float max) const;

	[[nodiscard]] Vec2 Lerp(Vec2 target, float amount) const;
};

// Arithmetic operators
[[nodiscard]] Vec2 operator+(const Vec2& leftOperand, const Vec2& rightOperand) noexcept;

[[nodiscard]] Vec2 operator-(const Vec2& leftOperand, const Vec2& rightOperand) noexcept;

[[nodiscard]] Vec2 operator*(const Vec2& leftOperand, const Vec2& rightOperand) noexcept;

[[nodiscard]] Vec2 operator/(const Vec2& leftOperand, const Vec2& rightOperand);

[[nodiscard]] Vec2 operator^(const Vec2& leftOperand, const Vec2& rightOperand) noexcept;

[[nodiscard]] Vec2 operator+(const Vec2& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec2 operator-(const Vec2& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec2 operator*(const Vec2& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec2 operator/(const Vec2& leftOperand, float rightOperand);

[[nodiscard]] Vec2 operator^(const Vec2& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec2 operator+(float leftOperand, const Vec2& rightOperand) noexcept;

[[nodiscard]] Vec2 operator-(float leftOperand, const Vec2& rightOperand) noexcept;

[[nodiscard]] Vec2 operator*(float leftOperand, const Vec2& rightOperand) noexcept;

[[nodiscard]] Vec2 operator/(float leftOperand, const Vec2& rightOperand);

[[nodiscard]] Vec2 operator^(float leftOperand, const Vec2& rightOperand) noexcept;

struct Vec3
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	static const Vec3 Zero;
	static const Vec3 One;
	static const Vec3 Up;
	static const Vec3 Down;
	static const Vec3 Left;
	static const Vec3 Right;
	static const Vec3 Forward;
	static const Vec3 Back;

	// Default and parametrized constructors
	Vec3() = default;

	Vec3(float x, float y, float z);

	explicit Vec3(float value);

	// Copy constructors
	explicit Vec3(const Vec2& vector, float z = 0.0f);

	Vec3(const Vec3& vector) = default;

	Vec3(const Vec4& vector);

	explicit Vec3(const Color3& color);

	Vec3(const Vector3& vector);

	// Conversion operators
	[[nodiscard]] operator Vector3() const;

	// Access operators
	float& operator[](std::size_t index);

	float operator[](std::size_t index) const;

	// Binary operators
	[[nodiscard]] friend constexpr bool operator==(const Vec3& leftOperand, const Vec3& rightOperand) noexcept = default;

	friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector)
	{
		stream << "Vec3(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

	// Compound assignment operators
	Vec3& operator+=(const Vec3& vector) noexcept;

	Vec3& operator-=(const Vec3& vector) noexcept;

	Vec3& operator*=(const Vec3& vector) noexcept;

	Vec3& operator/=(const Vec3& vector);

	Vec3& operator^=(const Vec3& vector) noexcept;

	Vec3& operator+=(float value) noexcept;

	Vec3& operator-=(float value) noexcept;

	Vec3& operator*=(float value) noexcept;

	Vec3& operator/=(float value);

	Vec3& operator^=(float value) noexcept;

	// Functionalities
	[[nodiscard]] float Length() const;

	[[nodiscard]] float LengthSqr() const;

	[[nodiscard]] Vec3 Normalized() const;

	[[nodiscard]] Vec3 Lerp(const Vec3& target, float amount) const;

	[[nodiscard]] Vec3 Clamp(float min, float max) const;

	[[nodiscard]] float Dot(const Vec3& vector) const;

	[[nodiscard]] Vec3 Cross(const Vec3& vector) const;

	[[nodiscard]] float Angle(const Vec3& vector) const;

	[[nodiscard]] float Distance(const Vec3& vector) const;

	[[nodiscard]] float DistanceSqr(const Vec3& vector) const;

	[[nodiscard]] Vec3 Reflect(const Vec3& normal) const;
};

// Arithmetic operators
[[nodiscard]] Vec3 operator+(const Vec3& leftOperand, const Vec3& rightOperand) noexcept;

[[nodiscard]] Vec3 operator-(const Vec3& leftOperand, const Vec3& rightOperand) noexcept;

[[nodiscard]] Vec3 operator*(const Vec3& leftOperand, const Vec3& rightOperand) noexcept;

[[nodiscard]] Vec3 operator/(const Vec3& leftOperand, const Vec3& rightOperand);

[[nodiscard]] Vec3 operator^(const Vec3& leftOperand, const Vec3& rightOperand) noexcept;

[[nodiscard]] Vec3 operator+(const Vec3& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec3 operator-(const Vec3& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec3 operator*(const Vec3& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec3 operator/(const Vec3& leftOperand, float rightOperand);

[[nodiscard]] Vec3 operator^(const Vec3& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec3 operator+(float leftOperand, const Vec3& rightOperand) noexcept;

[[nodiscard]] Vec3 operator-(float leftOperand, const Vec3& rightOperand) noexcept;

[[nodiscard]] Vec3 operator*(float leftOperand, const Vec3& rightOperand) noexcept;

[[nodiscard]] Vec3 operator/(float leftOperand, const Vec3& rightOperand);

[[nodiscard]] Vec3 operator^(float leftOperand, const Vec3& rightOperand) noexcept;

struct Vec4
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;

	static const Vec4 Zero;
	static const Vec4 One;

	// Default and parametrized constructors
	Vec4() = default;

	Vec4(float x, float y, float z, float w);

	explicit Vec4(float value);

	// Copy constructors
	explicit Vec4(const Vec2& vector, float z = 0.0f, float w = 0.0f);

	explicit Vec4(const Vec3& vector, float w = 0.0f);

	Vec4(const Vec4& vector) = default;

	explicit Vec4(const Color4& color);

	Vec4(const Vector4& vector);

	// Conversion operators
	[[nodiscard]] operator Vector4() const;

	[[nodiscard]] operator ImVec4() const;

	// Access operators
	float& operator[](std::size_t index);

	float operator[](std::size_t index) const;

	// Binary operators
	[[nodiscard]] friend constexpr bool operator==(const Vec4& leftOperand, const Vec4& rightOperand) noexcept = default;

	friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector)
	{
		stream << "Vec4(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}

	// Compound assignment operators
	Vec4& operator+=(const Vec4& vector) noexcept;

	Vec4& operator-=(const Vec4& vector) noexcept;

	Vec4& operator*=(const Vec4& vector) noexcept;

	Vec4& operator/=(const Vec4& vector);

	Vec4& operator^=(const Vec4& vector) noexcept;

	Vec4& operator+=(float value) noexcept;

	Vec4& operator-=(float value) noexcept;

	Vec4& operator*=(float value) noexcept;

	Vec4& operator/=(float value);

	Vec4& operator^=(float value) noexcept;

	// Functionalities
	[[nodiscard]] float Length() const;

	[[nodiscard]] Vec4 Normalized() const;

	[[nodiscard]] Vec4 Clamp(float min, float max) const;
};

// Arithmetic operators
[[nodiscard]] Vec4 operator+(const Vec4& leftOperand, const Vec4& rightOperand) noexcept;

[[nodiscard]] Vec4 operator-(const Vec4& leftOperand, const Vec4& rightOperand) noexcept;

[[nodiscard]] Vec4 operator*(const Vec4& leftOperand, const Vec4& rightOperand) noexcept;

[[nodiscard]] Vec4 operator/(const Vec4& leftOperand, const Vec4& rightOperand);

[[nodiscard]] Vec4 operator^(const Vec4& leftOperand, const Vec4& rightOperand) noexcept;

[[nodiscard]] Vec4 operator+(const Vec4& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec4 operator-(const Vec4& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec4 operator*(const Vec4& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec4 operator/(const Vec4& leftOperand, float rightOperand);

[[nodiscard]] Vec4 operator^(const Vec4& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Vec4 operator+(float leftOperand, const Vec4& rightOperand) noexcept;

[[nodiscard]] Vec4 operator-(float leftOperand, const Vec4& rightOperand) noexcept;

[[nodiscard]] Vec4 operator*(float leftOperand, const Vec4& rightOperand) noexcept;

[[nodiscard]] Vec4 operator/(float leftOperand, const Vec4& rightOperand);

[[nodiscard]] Vec4 operator^(float leftOperand, const Vec4& rightOperand) noexcept;