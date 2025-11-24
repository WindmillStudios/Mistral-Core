#include "Matrix.h"

#include <cassert>
#include <cmath>

#include "Quaternion.h"
#include "Vector.h"

const Matrix4x4 Matrix4x4::Identity = {1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f};

// Parametrized constructors
Matrix4x4::Matrix4x4(const float m0, const float m1, const float m2, const float m3, const float m4, const float m5, const float m6, const float m7,
					 const float m8, const float m9, const float m10, const float m11, const float m12, const float m13, const float m14,
					 const float m15):
	m0(m0),
	m1(m1),
	m2(m2),
	m3(m3),
	m4(m4),
	m5(m5),
	m6(m6),
	m7(m7),
	m8(m8),
	m9(m9),
	m10(m10),
	m11(m11),
	m12(m12),
	m13(m13),
	m14(m14),
	m15(m15)
{
}

Matrix4x4::Matrix4x4(const float value):
	m0(value),
	m1(value),
	m2(value),
	m3(value),
	m4(value),
	m5(value),
	m6(value),
	m7(value),
	m8(value),
	m9(value),
	m10(value),
	m11(value),
	m12(value),
	m13(value),
	m14(value),
	m15(value)
{
}

// Copy constructors
Matrix4x4::Matrix4x4(const Matrix& matrix):
	m0(matrix.m0),
	m1(matrix.m1),
	m2(matrix.m2),
	m3(matrix.m3),
	m4(matrix.m4),
	m5(matrix.m5),
	m6(matrix.m6),
	m7(matrix.m7),
	m8(matrix.m8),
	m9(matrix.m9),
	m10(matrix.m10),
	m11(matrix.m11),
	m12(matrix.m12),
	m13(matrix.m13),
	m14(matrix.m14),
	m15(matrix.m15)
{
}

// Conversion operators
Matrix4x4::operator Matrix() const
{
	return {m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15};
}

// Access operators
float& Matrix4x4::operator[](const std::size_t index)
{
	assert(index <= 15);
	switch (index)
	{
		case 0:
			return m0;
		case 1:
			return m1;
		case 2:
			return m2;
		case 3:
			return m3;
		case 4:
			return m4;
		case 5:
			return m5;
		case 6:
			return m6;
		case 7:
			return m7;
		case 8:
			return m8;
		case 9:
			return m9;
		case 10:
			return m10;
		case 11:
			return m11;
		case 12:
			return m12;
		case 13:
			return m13;
		case 14:
			return m14;
		case 15:
			return m15;
		default:
			break;
	}
	return m0;
}

float Matrix4x4::operator[](const std::size_t index) const
{
	assert(index <= 15);
	switch (index)
	{
		case 0:
			return m0;
		case 1:
			return m1;
		case 2:
			return m2;
		case 3:
			return m3;
		case 4:
			return m4;
		case 5:
			return m5;
		case 6:
			return m6;
		case 7:
			return m7;
		case 8:
			return m8;
		case 9:
			return m9;
		case 10:
			return m10;
		case 11:
			return m11;
		case 12:
			return m12;
		case 13:
			return m13;
		case 14:
			return m14;
		case 15:
			return m15;
		default:
			break;
	}
	return m0;
}

// Compound assignment operators
Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& matrix) noexcept
{
	m0 += matrix.m0;
	m1 += matrix.m1;
	m2 += matrix.m2;
	m3 += matrix.m3;
	m4 += matrix.m4;
	m5 += matrix.m5;
	m6 += matrix.m6;
	m7 += matrix.m7;
	m8 += matrix.m8;
	m9 += matrix.m9;
	m10 += matrix.m10;
	m11 += matrix.m11;
	m12 += matrix.m12;
	m13 += matrix.m13;
	m14 += matrix.m14;
	m15 += matrix.m15;
	return *this;
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& matrix) noexcept
{
	m0 -= matrix.m0;
	m1 -= matrix.m1;
	m2 -= matrix.m2;
	m3 -= matrix.m3;
	m4 -= matrix.m4;
	m5 -= matrix.m5;
	m6 -= matrix.m6;
	m7 -= matrix.m7;
	m8 -= matrix.m8;
	m9 -= matrix.m9;
	m10 -= matrix.m10;
	m11 -= matrix.m11;
	m12 -= matrix.m12;
	m13 -= matrix.m13;
	m14 -= matrix.m14;
	m15 -= matrix.m15;
	return *this;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& matrix) noexcept
{
	*this = *this * matrix;
	return *this;
}

// Arithmetic operators
Matrix4x4 operator+(const Matrix4x4& leftOperand, const Matrix4x4& rightOperand) noexcept
{
	return {leftOperand.m0 + rightOperand.m0,	leftOperand.m1 + rightOperand.m1,	leftOperand.m2 + rightOperand.m2,
			leftOperand.m3 + rightOperand.m3,	leftOperand.m4 + rightOperand.m4,	leftOperand.m5 + rightOperand.m5,
			leftOperand.m6 + rightOperand.m6,	leftOperand.m7 + rightOperand.m7,	leftOperand.m8 + rightOperand.m8,
			leftOperand.m9 + rightOperand.m9,	leftOperand.m10 + rightOperand.m10, leftOperand.m11 + rightOperand.m11,
			leftOperand.m12 + rightOperand.m12, leftOperand.m13 + rightOperand.m13, leftOperand.m14 + rightOperand.m14,
			leftOperand.m15 + rightOperand.m15};
}

Matrix4x4 operator-(const Matrix4x4& leftOperand, const Matrix4x4& rightOperand) noexcept
{
	return {leftOperand.m0 - rightOperand.m0,	leftOperand.m1 - rightOperand.m1,	leftOperand.m2 - rightOperand.m2,
			leftOperand.m3 - rightOperand.m3,	leftOperand.m4 - rightOperand.m4,	leftOperand.m5 - rightOperand.m5,
			leftOperand.m6 - rightOperand.m6,	leftOperand.m7 - rightOperand.m7,	leftOperand.m8 - rightOperand.m8,
			leftOperand.m9 - rightOperand.m9,	leftOperand.m10 - rightOperand.m10, leftOperand.m11 - rightOperand.m11,
			leftOperand.m12 - rightOperand.m12, leftOperand.m13 - rightOperand.m13, leftOperand.m14 - rightOperand.m14,
			leftOperand.m15 - rightOperand.m15};
}

Matrix4x4 operator*(const Matrix4x4& leftOperand, const Matrix4x4& rightOperand) noexcept
{
	Matrix4x4 result(0.f);

	result.m0 =
		leftOperand.m0 * rightOperand.m0 + leftOperand.m4 * rightOperand.m1 + leftOperand.m8 * rightOperand.m2 + leftOperand.m12 * rightOperand.m3;
	result.m1 =
		leftOperand.m1 * rightOperand.m0 + leftOperand.m5 * rightOperand.m1 + leftOperand.m9 * rightOperand.m2 + leftOperand.m13 * rightOperand.m3;
	result.m2 =
		leftOperand.m2 * rightOperand.m0 + leftOperand.m6 * rightOperand.m1 + leftOperand.m10 * rightOperand.m2 + leftOperand.m14 * rightOperand.m3;
	result.m3 =
		leftOperand.m3 * rightOperand.m0 + leftOperand.m7 * rightOperand.m1 + leftOperand.m11 * rightOperand.m2 + leftOperand.m15 * rightOperand.m3;
	result.m4 =
		leftOperand.m0 * rightOperand.m4 + leftOperand.m4 * rightOperand.m5 + leftOperand.m8 * rightOperand.m6 + leftOperand.m12 * rightOperand.m7;
	result.m5 =
		leftOperand.m1 * rightOperand.m4 + leftOperand.m5 * rightOperand.m5 + leftOperand.m9 * rightOperand.m6 + leftOperand.m13 * rightOperand.m7;
	result.m6 =
		leftOperand.m2 * rightOperand.m4 + leftOperand.m6 * rightOperand.m5 + leftOperand.m10 * rightOperand.m6 + leftOperand.m14 * rightOperand.m7;
	result.m7 =
		leftOperand.m3 * rightOperand.m4 + leftOperand.m7 * rightOperand.m5 + leftOperand.m11 * rightOperand.m6 + leftOperand.m15 * rightOperand.m7;
	result.m8 =
		leftOperand.m0 * rightOperand.m8 + leftOperand.m4 * rightOperand.m9 + leftOperand.m8 * rightOperand.m10 + leftOperand.m12 * rightOperand.m11;
	result.m9 =
		leftOperand.m1 * rightOperand.m8 + leftOperand.m5 * rightOperand.m9 + leftOperand.m9 * rightOperand.m10 + leftOperand.m13 * rightOperand.m11;
	result.m10 =
		leftOperand.m2 * rightOperand.m8 + leftOperand.m6 * rightOperand.m9 + leftOperand.m10 * rightOperand.m10 + leftOperand.m14 * rightOperand.m11;
	result.m11 =
		leftOperand.m3 * rightOperand.m8 + leftOperand.m7 * rightOperand.m9 + leftOperand.m11 * rightOperand.m10 + leftOperand.m15 * rightOperand.m11;
	result.m12 = leftOperand.m0 * rightOperand.m12 + leftOperand.m4 * rightOperand.m13 + leftOperand.m8 * rightOperand.m14 +
				 leftOperand.m12 * rightOperand.m15;
	result.m13 = leftOperand.m1 * rightOperand.m12 + leftOperand.m5 * rightOperand.m13 + leftOperand.m9 * rightOperand.m14 +
				 leftOperand.m13 * rightOperand.m15;
	result.m14 = leftOperand.m2 * rightOperand.m12 + leftOperand.m6 * rightOperand.m13 + leftOperand.m10 * rightOperand.m14 +
				 leftOperand.m14 * rightOperand.m15;
	result.m15 = leftOperand.m3 * rightOperand.m12 + leftOperand.m7 * rightOperand.m13 + leftOperand.m11 * rightOperand.m14 +
				 leftOperand.m15 * rightOperand.m15;

	return result;
}

Vec4 operator*(const Matrix4x4& leftOperand, const Vec4& rightOperand) noexcept
{
	return {leftOperand.m0 * rightOperand.x + leftOperand.m4 * rightOperand.y + leftOperand.m8 * rightOperand.z + leftOperand.m12 * rightOperand.w,
			leftOperand.m1 * rightOperand.x + leftOperand.m5 * rightOperand.y + leftOperand.m9 * rightOperand.z + leftOperand.m13 * rightOperand.w,
			leftOperand.m2 * rightOperand.x + leftOperand.m6 * rightOperand.y + leftOperand.m10 * rightOperand.z + leftOperand.m14 * rightOperand.w,
			leftOperand.m3 * rightOperand.x + leftOperand.m7 * rightOperand.y + leftOperand.m11 * rightOperand.z + leftOperand.m15 * rightOperand.w};
}

// Functionalities
Matrix4x4 Matrix4x4::Transposed() const
{
	return {m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15};
}

Matrix4x4 Matrix4x4::Inverted() const
{
	Matrix4x4 result(0.f);

	const float det = Determinant();

	if (fabsf(det) < 1e-6f)
	{
		return Matrix4x4::Identity;
	}

	result.m0 = (m5 * (m10 * m15 - m14 * m11) - m9 * (m6 * m15 - m14 * m7) + m13 * (m6 * m11 - m10 * m7));
	result.m1 = -(m1 * (m10 * m15 - m14 * m11) - m9 * (m2 * m15 - m14 * m3) + m13 * (m2 * m11 - m10 * m3));
	result.m2 = (m1 * (m6 * m15 - m14 * m7) - m5 * (m2 * m15 - m14 * m3) + m13 * (m2 * m7 - m6 * m3));
	result.m3 = -(m1 * (m6 * m11 - m10 * m7) - m5 * (m2 * m11 - m10 * m3) + m9 * (m2 * m7 - m6 * m3));
	result.m4 = -(m4 * (m10 * m15 - m14 * m11) - m8 * (m6 * m15 - m14 * m7) + m12 * (m6 * m11 - m10 * m7));
	result.m5 = (m0 * (m10 * m15 - m14 * m11) - m8 * (m2 * m15 - m14 * m3) + m12 * (m2 * m11 - m10 * m3));
	result.m6 = -(m0 * (m6 * m15 - m14 * m7) - m4 * (m2 * m15 - m14 * m3) + m12 * (m2 * m7 - m6 * m3));
	result.m7 = (m0 * (m6 * m11 - m10 * m7) - m4 * (m2 * m11 - m10 * m3) + m8 * (m2 * m7 - m6 * m3));
	result.m8 = (m4 * (m9 * m15 - m13 * m11) - m8 * (m5 * m15 - m13 * m7) + m12 * (m5 * m11 - m9 * m7));
	result.m9 = -(m0 * (m9 * m15 - m13 * m11) - m8 * (m1 * m15 - m13 * m3) + m12 * (m1 * m11 - m9 * m3));
	result.m10 = (m0 * (m5 * m15 - m13 * m7) - m4 * (m1 * m15 - m13 * m3) + m12 * (m1 * m7 - m5 * m3));
	result.m11 = -(m0 * (m5 * m11 - m9 * m7) - m4 * (m1 * m11 - m9 * m3) + m8 * (m1 * m7 - m5 * m3));
	result.m12 = -(m4 * (m9 * m14 - m13 * m10) - m8 * (m5 * m14 - m13 * m6) + m12 * (m5 * m10 - m9 * m6));
	result.m13 = (m0 * (m9 * m14 - m13 * m10) - m8 * (m1 * m14 - m13 * m2) + m12 * (m1 * m10 - m9 * m2));
	result.m14 = -(m0 * (m5 * m14 - m13 * m6) - m4 * (m1 * m14 - m13 * m2) + m12 * (m1 * m6 - m5 * m2));
	result.m15 = (m0 * (m5 * m10 - m9 * m6) - m4 * (m1 * m10 - m9 * m2) + m8 * (m1 * m6 - m5 * m2));

	const float invDet = 1.0f / det;
	result.m0 *= invDet;
	result.m1 *= invDet;
	result.m2 *= invDet;
	result.m3 *= invDet;
	result.m4 *= invDet;
	result.m5 *= invDet;
	result.m6 *= invDet;
	result.m7 *= invDet;
	result.m8 *= invDet;
	result.m9 *= invDet;
	result.m10 *= invDet;
	result.m11 *= invDet;
	result.m12 *= invDet;
	result.m13 *= invDet;
	result.m14 *= invDet;
	result.m15 *= invDet;

	return result;
}

float Matrix4x4::Determinant() const
{
	const float cofactor0 = m5 * (m10 * m15 - m14 * m11) - m9 * (m6 * m15 - m14 * m7) + m13 * (m6 * m11 - m10 * m7);
	const float cofactor1 = m1 * (m10 * m15 - m14 * m11) - m9 * (m2 * m15 - m14 * m3) + m13 * (m2 * m11 - m10 * m3);
	const float cofactor2 = m1 * (m6 * m15 - m14 * m7) - m5 * (m2 * m15 - m14 * m3) + m13 * (m2 * m7 - m6 * m3);
	const float cofactor3 = m1 * (m6 * m11 - m10 * m7) - m5 * (m2 * m11 - m10 * m3) + m9 * (m2 * m7 - m6 * m3);

	return m0 * cofactor0 - m4 * cofactor1 + m8 * cofactor2 - m12 * cofactor3;
}

Vec3 Matrix4x4::GetPosition() const
{
	return {m12, m13, m14};
}

Quat Matrix4x4::GetRotation() const
{
	Quat q = {};
	const Vec3 scale = GetScale();

	const float trace = m0 / scale.x + m5 / scale.y + m10 / scale.z;

	if (trace > 0.f)
	{
		float s = .5f / sqrtf(trace + 1.f);
		q.w = .25f / s;
		q.x = (m6 / scale.y - m9 / scale.z) * s;
		q.y = (m8 / scale.z - m2 / scale.x) * s;
		q.z = (m1 / scale.x - m4 / scale.y) * s;
	}
	else
	{
		if (m0 > m5 && m0 > m10)
		{
			float s = 2.f * sqrtf(1.f + m0 / scale.x - m5 / scale.y - m10 / scale.z);
			q.x = .25f * s;
			q.y = (m4 / scale.y + m1 / scale.x) / s;
			q.z = (m8 / scale.z + m2 / scale.x) / s;
			q.w = (m6 / scale.y - m9 / scale.z) / s;
		}
		else if (m5 > m10)
		{
			float s = 2.f * sqrtf(1.f + m5 / scale.y - m0 / scale.x - m10 / scale.z);
			q.x = (m4 / scale.y + m1 / scale.x) / s;
			q.y = .25f * s;
			q.z = (m9 / scale.z + m6 / scale.y) / s;
			q.w = (m8 / scale.z - m2 / scale.x) / s;
		}
		else
		{
			float s = 2.f * sqrtf(1.f + m10 / scale.z - m0 / scale.x - m5 / scale.y);
			q.x = (m8 / scale.z + m2 / scale.x) / s;
			q.y = (m9 / scale.z + m6 / scale.y) / s;
			q.z = .25f * s;
			q.w = (m1 / scale.x - m4 / scale.y) / s;
		}
	}
	return q.Normalized();
}

Vec3 Matrix4x4::GetScale() const
{
	return {Vec3(m0, m1, m2).Length(), Vec3(m4, m5, m6).Length(), Vec3(m8, m9, m10).Length()};
}

// Static constructors
Matrix4x4 Matrix4x4::FromPosition(const Vec3& position)
{
	return {1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, position.x, position.y, position.z, 1.f};
}

Matrix4x4 Matrix4x4::FromRotation(const Quat& rotation)
{
	Matrix4x4 result = Matrix4x4::Identity;
	const Quat q = rotation.Normalized();

	const float xx = q.x * q.x;
	const float yy = q.y * q.y;
	const float zz = q.z * q.z;
	const float xy = q.x * q.y;
	const float xz = q.x * q.z;
	const float yz = q.y * q.z;
	const float wx = q.w * q.x;
	const float wy = q.w * q.y;
	const float wz = q.w * q.z;

	result.m0 = 1.f - 2.f * (yy + zz);
	result.m1 = 2.f * (xy + wz);
	result.m2 = 2.f * (xz - wy);

	result.m4 = 2.f * (xy - wz);
	result.m5 = 1.f - 2.0f * (xx + zz);
	result.m6 = 2.f * (yz + wx);

	result.m8 = 2.f * (xz + wy);
	result.m9 = 2.f * (yz - wx);
	result.m10 = 1.f - 2.f * (xx + yy);

	return result;
}

Matrix4x4 Matrix4x4::FromScale(const Vec3& scale)
{
	return {scale.x, 0.f, 0.f, 0.f, 0.f, scale.y, 0.f, 0.f, 0.f, 0.f, scale.z, 0.f, 0.f, 0.f, 0.f, 1.f};
}

Matrix4x4 Matrix4x4::FromPRS(const Vec3& position, const Quat& rotation, const Vec3& scale)
{
	const Matrix4x4 matS = Matrix4x4::FromScale(scale);
	const Matrix4x4 matR = Matrix4x4::FromRotation(rotation);
	const Matrix4x4 matT = Matrix4x4::FromPosition(position);

	return matT * matR * matS;
}

Matrix4x4 Matrix4x4::Perspective(const float fovY, const float aspect, const float nearPlane, const float farPlane)
{
	Matrix4x4 result(0.f);
	const float tanHalfFov = tanf((fovY * DEG2RAD) * .5f);

	result.m0 = 1.f / (aspect * tanHalfFov);
	result.m5 = 1.f / tanHalfFov;
	result.m10 = -(farPlane + nearPlane) / (farPlane - nearPlane);
	result.m11 = -1.f;
	result.m14 = -(2.f * farPlane * nearPlane) / (farPlane - nearPlane);

	return result;
}

Matrix4x4 Matrix4x4::Orthographic(const float left, const float right, const float bottom, const float top, const float nearPlane,
								  const float farPlane)
{
	Matrix4x4 result(0.f);

	const float rl = right - left;
	const float tb = top - bottom;
	const float fn = farPlane - nearPlane;

	result.m0 = 2.f / rl;
	result.m5 = 2.f / tb;
	result.m10 = -2.f / fn;
	result.m12 = -(left + right) / rl;
	result.m13 = -(top + bottom) / tb;
	result.m14 = -(farPlane + nearPlane) / fn;
	result.m15 = 1.f;

	return result;
}

Matrix4x4 Matrix4x4::LookAt(const Vec3& eye, const Vec3& target, const Vec3& up)
{
	const Vec3 zaxis = (target - eye).Normalized();
	const Vec3 xaxis = zaxis.Cross(up).Normalized();
	const Vec3 yaxis = xaxis.Cross(zaxis);

	return {xaxis.x, yaxis.x, -zaxis.x, 0.f, xaxis.y,		  yaxis.y,		   -zaxis.y,	   0.f,
			xaxis.z, yaxis.z, -zaxis.z, 0.f, -xaxis.Dot(eye), -yaxis.Dot(eye), zaxis.Dot(eye), 1.f};
}