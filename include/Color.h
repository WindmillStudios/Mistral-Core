#pragma once

#include <cstdint>
#include <ostream>

#include "raylib.h"

struct Vec3;
struct Vec4;
struct Color3;
struct Color4;

struct Color3
{
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	// Default and parametrized constructors
	Color3() = default;

	Color3(float r, float g, float b);

	Color3(uint32_t r, uint32_t g, uint32_t b);

	explicit Color3(float value);

	// Copy constructors
	Color3(const Color3& color) = default;

	Color3(const Color4& color);

	explicit Color3(const Vec3& vector);

	Color3(const Color& color);

	// Conversion operators
	[[nodiscard]] operator Color() const;

	// Access operators
	float& operator[](std::size_t index);

	float operator[](std::size_t index) const;

	// Binary operators
	[[nodiscard]] friend constexpr bool operator==(const Color3& leftOperand, const Color3& rightOperand) noexcept = default;

	friend std::ostream& operator<<(std::ostream& stream, const Color3& color)
	{
		stream << "Color3(" << color.r << ", " << color.g << ", " << color.b << ")";
		return stream;
	}

	// Compound assignment operators
	Color3& operator+=(const Color3& color) noexcept;

	Color3& operator-=(const Color3& color) noexcept;

	Color3& operator*=(const Color3& color) noexcept;

	Color3& operator/=(const Color3& color);

	Color3& operator^=(const Color3& color) noexcept;

	Color3& operator+=(float color) noexcept;

	Color3& operator-=(float color) noexcept;

	Color3& operator*=(float color) noexcept;

	Color3& operator/=(float color);

	Color3& operator^=(float color) noexcept;

	// Functionalities
	[[nodiscard]] float Length() const;

	[[nodiscard]] Color3 Normalized() const;

	[[nodiscard]] Color3 Clamp(float min, float max) const;

	[[nodiscard]] Color3 Lerp(const Color3& target, float amount) const;

	// Color functionalities
	[[nodiscard]] static Color3 HSV(float h, float s, float v);

	[[nodiscard]] static Color3 HSV(uint32_t h, uint32_t s, uint32_t v);
};

// Arithmetic operators
[[nodiscard]] Color3 operator+(const Color3& leftOperand, const Color3& rightOperand) noexcept;

[[nodiscard]] Color3 operator-(const Color3& leftOperand, const Color3& rightOperand) noexcept;

[[nodiscard]] Color3 operator*(const Color3& leftOperand, const Color3& rightOperand) noexcept;

[[nodiscard]] Color3 operator/(const Color3& leftOperand, const Color3& rightOperand);

[[nodiscard]] Color3 operator^(const Color3& leftOperand, const Color3& rightOperand) noexcept;

[[nodiscard]] Color3 operator+(const Color3& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Color3 operator-(const Color3& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Color3 operator*(const Color3& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Color3 operator/(const Color3& leftOperand, float rightOperand);

[[nodiscard]] Color3 operator^(const Color3& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Color3 operator+(float leftOperand, const Color3& rightOperand) noexcept;

[[nodiscard]] Color3 operator-(float leftOperand, const Color3& rightOperand) noexcept;

[[nodiscard]] Color3 operator*(float leftOperand, const Color3& rightOperand) noexcept;

[[nodiscard]] Color3 operator/(float leftOperand, const Color3& rightOperand);

[[nodiscard]] Color3 operator^(float leftOperand, const Color3& rightOperand) noexcept;

struct Color4
{
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	float a = 0.0f;

	static const Color4 White;
	static const Color4 Black;
	static const Color4 Transparent;

	static const Color4 Red;
	static const Color4 Green;
	static const Color4 Blue;

	static const Color4 Yellow;
	static const Color4 Magenta;
	static const Color4 Cyan;

	static const Color4 Gray;
	static const Color4 LightGray;
	static const Color4 DarkGray;

	static const Color4 Orange;
	static const Color4 Purple;
	static const Color4 Brown;
	static const Color4 Pink;
	static const Color4 Lime;
	static const Color4 SkyBlue;

	// Default and parametrized constructors
	Color4() = default;

	Color4(float r, float g, float b, float a = 1.0f);

	Color4(uint32_t r, uint32_t g, uint32_t b, uint32_t a = 255u);

	explicit Color4(float value);

	explicit Color4(float value, float alpha);

	// Copy constructors
	Color4(const Color4& color) = default;

	explicit Color4(const Color3& color, float a = 1.0f);

	explicit Color4(const Vec4& vector);

	Color4(const Color& color);

	// Conversion operators
	[[nodiscard]] operator Color() const;

	// Access operators
	float& operator[](std::size_t index);

	float operator[](std::size_t index) const;

	// Binary operators
	[[nodiscard]] friend constexpr bool operator==(const Color4& leftOperand, const Color4& rightOperand) noexcept = default;

	friend std::ostream& operator<<(std::ostream& stream, const Color4& color)
	{
		stream << "Color4(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
		return stream;
	}

	// Compound assignment operators
	Color4& operator+=(const Color4& color) noexcept;

	Color4& operator-=(const Color4& color) noexcept;

	Color4& operator*=(const Color4& color) noexcept;

	Color4& operator/=(const Color4& color);

	Color4& operator^=(const Color4& color) noexcept;

	Color4& operator+=(float value) noexcept;

	Color4& operator-=(float value) noexcept;

	Color4& operator*=(float value) noexcept;

	Color4& operator/=(float value);

	Color4& operator^=(float value) noexcept;

	// Functionalities
	[[nodiscard]] float Length() const;

	[[nodiscard]] Color4 Normalized() const;

	[[nodiscard]] Color4 Clamp(float min, float max) const;

	[[nodiscard]] Color4 Lerp(const Color4& target, float amount) const;

	[[nodiscard]] uint32_t ToUInt32() const;

	// Static constructors
	[[nodiscard]] static Color4 Grey(float value, float alpha = 1.0f);

	[[nodiscard]] static Color4 HSVA(float h, float s, float v, float a = 1.0f);

	[[nodiscard]] static Color4 HSVA(uint32_t h, uint32_t s, uint32_t v, uint32_t a = 255u);

	[[nodiscard]] Color4 WithAlpha(float alpha) const;
};

// Arithmetic operators
[[nodiscard]] Color4 operator+(const Color4& leftOperand, const Color4& rightOperand) noexcept;

[[nodiscard]] Color4 operator-(const Color4& leftOperand, const Color4& rightOperand) noexcept;

[[nodiscard]] Color4 operator*(const Color4& leftOperand, const Color4& rightOperand) noexcept;

[[nodiscard]] Color4 operator/(const Color4& leftOperand, const Color4& rightOperand);

[[nodiscard]] Color4 operator^(const Color4& leftOperand, const Color4& rightOperand) noexcept;

[[nodiscard]] Color4 operator+(const Color4& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Color4 operator-(const Color4& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Color4 operator*(const Color4& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Color4 operator/(const Color4& leftOperand, float rightOperand);

[[nodiscard]] Color4 operator^(const Color4& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Color4 operator+(float leftOperand, const Color4& rightOperand) noexcept;

[[nodiscard]] Color4 operator-(float leftOperand, const Color4& rightOperand) noexcept;

[[nodiscard]] Color4 operator*(float leftOperand, const Color4& rightOperand) noexcept;

[[nodiscard]] Color4 operator/(float leftOperand, const Color4& rightOperand);

[[nodiscard]] Color4 operator^(float leftOperand, const Color4& rightOperand) noexcept;