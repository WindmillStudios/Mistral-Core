#pragma once

#include <ostream>

#include "raylib.h"

struct Vec3;
struct Vec4;
struct Quat;

struct Matrix4x4
{
	float m0 = 0.f;
	float m1 = 0.f;
	float m2 = 0.f;
	float m3 = 0.f;
	float m4 = 0.f;
	float m5 = 0.f;
	float m6 = 0.f;
	float m7 = 0.f;
	float m8 = 0.f;
	float m9 = 0.f;
	float m10 = 0.f;
	float m11 = 0.f;
	float m12 = 0.f;
	float m13 = 0.f;
	float m14 = 0.f;
	float m15 = 0.f;

	static const Matrix4x4 Identity;

	// Default and parametrized constructors
	Matrix4x4() = default;

	Matrix4x4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12,
			  float m13, float m14, float m15);

	explicit Matrix4x4(float value);

	// Copy constructors
	Matrix4x4(const Matrix4x4& matrix) = default;

	explicit Matrix4x4(const Matrix& matrix); // Raylib's Matrix

	// Conversion operators
	[[nodiscard]] operator Matrix() const; // Raylib's Matrix

	// Access operators
	[[nodiscard]] float& operator[](std::size_t index);

	[[nodiscard]] float operator[](std::size_t index) const;

	// Binary operators
	[[nodiscard]] friend constexpr bool operator==(const Matrix4x4& leftOperand, const Matrix4x4& rightOperand) noexcept = default;

	friend std::ostream& operator<<(std::ostream& stream, const Matrix4x4& matrix)
	{
		stream << "Matrix4x4(\n";
		stream << "  " << matrix.m0 << ", " << matrix.m1 << ", " << matrix.m2 << ", " << matrix.m3 << ",\n";
		stream << "  " << matrix.m4 << ", " << matrix.m5 << ", " << matrix.m6 << ", " << matrix.m7 << ",\n";
		stream << "  " << matrix.m8 << ", " << matrix.m9 << ", " << matrix.m10 << ", " << matrix.m11 << ",\n";
		stream << "  " << matrix.m12 << ", " << matrix.m13 << ", " << matrix.m14 << ", " << matrix.m15 << "\n";
		stream << ")";
		return stream;
	}

	// Compound assignment operators
	Matrix4x4& operator+=(const Matrix4x4& matrix) noexcept;

	Matrix4x4& operator-=(const Matrix4x4& matrix) noexcept;

	Matrix4x4& operator*=(const Matrix4x4& matrix) noexcept;

	// Functionalities
	[[nodiscard]] Matrix4x4 Transposed() const;

	[[nodiscard]] Matrix4x4 Inverted() const;

	[[nodiscard]] float Determinant() const;

	[[nodiscard]] Vec3 GetPosition() const;

	[[nodiscard]] Quat GetRotation() const;

	[[nodiscard]] Vec3 GetScale() const;

	// Static constructors
	[[nodiscard]] static Matrix4x4 FromPosition(const Vec3& position);

	[[nodiscard]] static Matrix4x4 FromRotation(const Quat& rotation);

	[[nodiscard]] static Matrix4x4 FromScale(const Vec3& scale);

	[[nodiscard]] static Matrix4x4 FromPRS(const Vec3& position, const Quat& rotation, const Vec3& scale);

	[[nodiscard]] static Matrix4x4 Perspective(float fovY, float aspect, float nearPlane, float farPlane);

	[[nodiscard]] static Matrix4x4 Orthographic(float left, float right, float bottom, float top, float nearPlane, float farPlane);

	[[nodiscard]] static Matrix4x4 LookAt(const Vec3& eye, const Vec3& target, const Vec3& up);
};

// Arithmetic operators
[[nodiscard]] Matrix4x4 operator+(const Matrix4x4& leftOperand, const Matrix4x4& rightOperand) noexcept;

[[nodiscard]] Matrix4x4 operator-(const Matrix4x4& leftOperand, const Matrix4x4& rightOperand) noexcept;

[[nodiscard]] Matrix4x4 operator*(const Matrix4x4& leftOperand, const Matrix4x4& rightOperand) noexcept;

[[nodiscard]] Vec4 operator*(const Matrix4x4& leftOperand, const Vec4& rightOperand) noexcept;