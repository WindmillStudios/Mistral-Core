#pragma once

#include <cmath>
#include <ostream>

#include "raylib.h"

struct Vec3;
struct Vec4;

struct Quat
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 1.0f;

	static const Quat Identity;

	// Default and parametrized constructors
	Quat() = default;

	Quat(float x, float y, float z, float w);

	explicit Quat(float value);

	// Copy constructors
	Quat(const Quat& quat) = default;

	explicit Quat(const Vec4& vector);

	explicit Quat(const Quaternion& quat);

	// Conversion operators
	[[nodiscard]] operator Quaternion() const; // Raylib's Quaternion

	// Access operators
	[[nodiscard]] float& operator[](std::size_t index);

	[[nodiscard]] float operator[](std::size_t index) const;

	// Binary operators
	[[nodiscard]] friend constexpr bool operator==(const Quat& leftOperand, const Quat& rightOperand) noexcept = default;

	friend std::ostream& operator<<(std::ostream& stream, const Quat& quat)
	{
		stream << "Quat(" << quat.x << ", " << quat.y << ", " << quat.z << ", " << quat.w << ")";
		return stream;
	}

	// Compound assignment operators
	Quat& operator+=(const Quat& quat) noexcept;

	Quat& operator-=(const Quat& quat) noexcept;

	Quat& operator*=(const Quat& quat) noexcept;

	Quat& operator+=(float value) noexcept;

	Quat& operator-=(float value) noexcept;

	Quat& operator*=(float value) noexcept;

	Quat& operator/=(float value);

	Quat& operator^=(float value) noexcept;

	// Functionalities
	[[nodiscard]] float Length() const;

	[[nodiscard]] Quat Normalized() const;

	[[nodiscard]] Quat Conjugate() const;

	[[nodiscard]] Quat Inverse() const;

	[[nodiscard]] float Dot(const Quat& other) const;

	[[nodiscard]] Vec3 ToEuler() const;

	[[nodiscard]] Quat Slerp(const Quat& target, float amount) const;

	// Static constructors
	[[nodiscard]] static Quat FromAxisAngle(const Vec3& axis, float angle);

	[[nodiscard]] static Quat FromEuler(const Vec3& eulerAngles);
};

// Arithmetic operators
[[nodiscard]] Quat operator+(const Quat& leftOperand, const Quat& rightOperand) noexcept;

[[nodiscard]] Quat operator-(const Quat& leftOperand, const Quat& rightOperand) noexcept;

[[nodiscard]] Quat operator*(const Quat& leftOperand, const Quat& rightOperand) noexcept;

[[nodiscard]] Vec3 operator*(const Quat& leftOperand, const Vec3& rightOperand) noexcept;

[[nodiscard]] Quat operator+(const Quat& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Quat operator-(const Quat& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Quat operator*(const Quat& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Quat operator/(const Quat& leftOperand, float rightOperand);

[[nodiscard]] Quat operator^(const Quat& leftOperand, float rightOperand) noexcept;

[[nodiscard]] Quat operator+(float leftOperand, const Quat& rightOperand) noexcept;

[[nodiscard]] Quat operator-(float leftOperand, const Quat& rightOperand) noexcept;

[[nodiscard]] Quat operator*(float leftOperand, const Quat& rightOperand) noexcept;

[[nodiscard]] Quat operator/(float leftOperand, const Quat& rightOperand);

[[nodiscard]] Quat operator^(float leftOperand, const Quat& rightOperand) noexcept;