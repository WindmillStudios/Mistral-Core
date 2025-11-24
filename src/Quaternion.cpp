#include "Quaternion.h"

#include <cassert>
#include <cmath>

#include "Vector.h"

const Quat Quat::Identity = {0.0f, 0.0f, 0.0f, 1.0f};

// Parametrized constructors
Quat::Quat(const float x, const float y, const float z, const float w):
	x(x),
	y(y),
	z(z),
	w(w)
{
}

Quat::Quat(const float value):
	x(value),
	y(value),
	z(value),
	w(value)
{
}

// Copy constructors
Quat::Quat(const Vec4& vector):
	x(vector.x),
	y(vector.y),
	z(vector.z),
	w(vector.w)
{
}

Quat::Quat(const Quaternion& quat):
	x(quat.x),
	y(quat.y),
	z(quat.z),
	w(quat.w)
{
}

// Conversion operators
Quat::operator Quaternion() const
{
	return {x, y, z, w};
}

// Access operators
float& Quat::operator[](const std::size_t index)
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

float Quat::operator[](const std::size_t index) const
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
Quat& Quat::operator+=(const Quat& quat) noexcept
{
	x += quat.x;
	y += quat.y;
	z += quat.z;
	w += quat.w;
	return *this;
}

Quat& Quat::operator-=(const Quat& quat) noexcept
{
	x -= quat.x;
	y -= quat.y;
	z -= quat.z;
	w -= quat.w;
	return *this;
}

Quat& Quat::operator*=(const Quat& quat) noexcept
{
	const float newX = w * quat.x + x * quat.w + y * quat.z - z * quat.y;
	const float newY = w * quat.y - x * quat.z + y * quat.w + z * quat.x;
	const float newZ = w * quat.z + x * quat.y - y * quat.x + z * quat.w;
	const float newW = w * quat.w - x * quat.x - y * quat.y - z * quat.z;
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
	return *this;
}

Quat& Quat::operator+=(const float value) noexcept
{
	x += value;
	y += value;
	z += value;
	w += value;
	return *this;
}

Quat& Quat::operator-=(const float value) noexcept
{
	x -= value;
	y -= value;
	z -= value;
	w -= value;
	return *this;
}

Quat& Quat::operator*=(const float value) noexcept
{
	x *= value;
	y *= value;
	z *= value;
	w *= value;
	return *this;
}

Quat& Quat::operator/=(const float value)
{
	x /= value;
	y /= value;
	z /= value;
	w /= value;
	return *this;
}

Quat& Quat::operator^=(const float value) noexcept
{
	x = std::pow(x, value);
	y = std::pow(y, value);
	z = std::pow(z, value);
	w = std::pow(w, value);
	return *this;
}

// Functionalities
float Quat::Length() const
{
	return std::sqrt(x * x + y * y + z * z + w * w);
}

Quat Quat::Normalized() const
{
	if (const float len = Length(); len > 1e-6f)
	{
		return *this / len;
	}
	return Quat::Identity;
}

Quat Quat::Conjugate() const
{
	return {-x, -y, -z, w};
}

Quat Quat::Inverse() const
{
	if (const float lenSq = x * x + y * y + z * z + w * w; lenSq > 1e-6f)
	{
		return Conjugate() / lenSq;
	}
	return Quat::Identity;
}

float Quat::Dot(const Quat& other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vec3 Quat::ToEuler() const
{
	Vec3 euler;

	// Roll (eje x)
	const float sinRollCosPitch = 2.f * (w * x + y * z);
	const float cosRCosPitch = 1.f - 2.f * (x * x + y * y);
	euler.x = std::atan2(sinRollCosPitch, cosRCosPitch);

	// Pitch (eje y)
	if (const float sinPitch = 2.f * (w * y - z * x); std::abs(sinPitch) >= 1)
	{
		euler.y = std::copysign(PI / 2, sinPitch); // Gimbal lock
	}
	else
	{
		euler.y = std::asin(sinPitch);
	}

	// Yaw (z-axis)
	const float sinYawCosPitch = 2.f * (w * z + x * y);
	const float cosYawCosPitch = 1.f - 2.f * (y * y + z * z);
	euler.z = std::atan2(sinYawCosPitch, cosYawCosPitch);

	return euler;
}

Quat Quat::Slerp(const Quat& target, const float amount) const
{
	Quat q2 = target;
	float cosTheta = this->Dot(target);

	// If quaternions are on opposite hemispheres, rotate one
	if (cosTheta < 0.f)
	{
		q2 = q2 * -1.f;
		cosTheta = -cosTheta;
	}

	// Use linear interpolation if too close (Lerp)
	if (cosTheta > .9995f)
	{
		return (*this + (q2 - *this) * amount).Normalized();
	}

	// Spherical interpolation (Slerp)
	const float theta = std::acos(cosTheta);
	const float sinTheta = std::sqrt(1.f - cosTheta * cosTheta);

	if (std::abs(sinTheta) < .001f)
	{
		return (*this * .5f + q2 * .5f).Normalized();
	}

	const float ratioA = std::sin((1.f - amount) * theta) / sinTheta;
	const float ratioB = std::sin(amount * theta) / sinTheta;

	return (*this * ratioA + q2 * ratioB).Normalized();
}

// Static constructors
Quat Quat::FromAxisAngle(const Vec3& axis, const float angle)
{
	const float halfAngle = angle * .5f;
	const float sinHalfAngle = std::sin(halfAngle);
	const Vec3 normalizedAxis = axis.Normalized();

	return {normalizedAxis.x * sinHalfAngle, normalizedAxis.y * sinHalfAngle, normalizedAxis.z * sinHalfAngle, std::cos(halfAngle)};
}

Quat Quat::FromEuler(const Vec3& eulerAngles)
{
	const float cy = std::cos(eulerAngles.z * .5f);
	const float sy = std::sin(eulerAngles.z * .5f);
	const float cp = std::cos(eulerAngles.y * .5f);
	const float sp = std::sin(eulerAngles.y * .5f);
	const float cr = std::cos(eulerAngles.x * .5f);
	const float sr = std::sin(eulerAngles.x * .5f);

	return {sr * cp * cy - cr * sp * sy, cr * sp * cy + sr * cp * sy, cr * cp * sy - sr * sp * cy, cr * cp * cy + sr * sp * sy};
}

// Arithmetic operators
Quat operator+(const Quat& leftOperand, const Quat& rightOperand) noexcept
{
	return {leftOperand.x + rightOperand.x, leftOperand.y + rightOperand.y, leftOperand.z + rightOperand.z, leftOperand.w + rightOperand.w};
}

Quat operator-(const Quat& leftOperand, const Quat& rightOperand) noexcept
{
	return {leftOperand.x - rightOperand.x, leftOperand.y - rightOperand.y, leftOperand.z - rightOperand.z, leftOperand.w - rightOperand.w};
}

Quat operator*(const Quat& leftOperand, const Quat& rightOperand) noexcept
{
	return Quat(leftOperand) *= rightOperand;
}

Vec3 operator*(const Quat& leftOperand, const Vec3& rightOperand) noexcept
{
	const Quat vQuat = {rightOperand.x, rightOperand.y, rightOperand.z, 0.f};
	const Quat resultQuat = leftOperand * vQuat * leftOperand.Conjugate();
	return {resultQuat.x, resultQuat.y, resultQuat.z};
}

Quat operator+(const Quat& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x + rightOperand, leftOperand.y + rightOperand, leftOperand.z + rightOperand, leftOperand.w + rightOperand};
}

Quat operator-(const Quat& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x - rightOperand, leftOperand.y - rightOperand, leftOperand.z - rightOperand, leftOperand.w - rightOperand};
}

Quat operator*(const Quat& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.x * rightOperand, leftOperand.y * rightOperand, leftOperand.z * rightOperand, leftOperand.w * rightOperand};
}

Quat operator/(const Quat& leftOperand, const float rightOperand)
{
	return {leftOperand.x / rightOperand, leftOperand.y / rightOperand, leftOperand.z / rightOperand, leftOperand.w / rightOperand};
}

Quat operator^(const Quat& leftOperand, const float rightOperand) noexcept
{
	return {std::pow(leftOperand.x, rightOperand), std::pow(leftOperand.y, rightOperand), std::pow(leftOperand.z, rightOperand),
			std::pow(leftOperand.w, rightOperand)};
}

Quat operator+(const float leftOperand, const Quat& rightOperand) noexcept
{
	return rightOperand + leftOperand;
}

Quat operator-(const float leftOperand, const Quat& rightOperand) noexcept
{
	return {leftOperand - rightOperand.x, leftOperand - rightOperand.y, leftOperand - rightOperand.z, leftOperand - rightOperand.w};
}

Quat operator*(const float leftOperand, const Quat& rightOperand) noexcept
{
	return rightOperand * leftOperand;
}

Quat operator/(const float leftOperand, const Quat& rightOperand)
{
	return {leftOperand / rightOperand.x, leftOperand / rightOperand.y, leftOperand / rightOperand.z, leftOperand / rightOperand.w};
}

Quat operator^(const float leftOperand, const Quat& rightOperand) noexcept
{
	return {std::pow(leftOperand, rightOperand.x), std::pow(leftOperand, rightOperand.y), std::pow(leftOperand, rightOperand.z),
			std::pow(leftOperand, rightOperand.w)};
}