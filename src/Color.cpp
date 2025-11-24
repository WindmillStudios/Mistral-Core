#include "Color.h"

#include <algorithm>
#include <cassert>
#include <cmath>

#include "Vector.h"

const Color4 Color4::White = {1.f, 1.f, 1.f, 1.f};
const Color4 Color4::Black = {0.f, 0.f, 0.f, 1.f};
const Color4 Color4::Transparent = {0.f, 0.f, 0.f, 0.f};

const Color4 Color4::Red = {1.f, 0.f, 0.f, 1.f};
const Color4 Color4::Green = {0.f, 1.f, 0.f, 1.f};
const Color4 Color4::Blue = {0.f, 0.f, 1.f, 1.f};

const Color4 Color4::Yellow = {1.f, 1.f, 0.f, 1.f};
const Color4 Color4::Magenta = {1.f, 0.f, 1.f, 1.f};
const Color4 Color4::Cyan = {0.f, 1.f, 1.f, 1.f};

const Color4 Color4::Gray = {.5f, .5f, .5f, 1.f};
const Color4 Color4::LightGray = {.75f, .75f, .75f, 1.f};
const Color4 Color4::DarkGray = {.25f, .25f, .25f, 1.f};

const Color4 Color4::Orange = {1.f, .5f, 0.f, 1.f};
const Color4 Color4::Purple = {.5f, 0.f, .5f, 1.f};
const Color4 Color4::Brown = {.6f, .4f, .2f, 1.f};
const Color4 Color4::Pink = {1.f, .75f, .8f, 1.f};
const Color4 Color4::Lime = {.75f, 1.0f, 0.f, 1.f};
const Color4 Color4::SkyBlue = {.53f, .81f, .92f, 1.f};

// Parametrized constructors
Color3::Color3(const float r, const float g, const float b):
	r(r),
	g(g),
	b(b)
{
}

Color3::Color3(const uint32_t r, const uint32_t g, const uint32_t b):
	r(r / 255.0f),
	g(g / 255.0f),
	b(b / 255.0f)
{
}

Color3::Color3(const float value):
	r(value),
	g(value),
	b(value)
{
}

// Copy constructors
Color3::Color3(const Color4& color):
	r(color.r),
	g(color.g),
	b(color.b)
{
}

Color3::Color3(const Vec3& vector):
	r(vector.x),
	g(vector.y),
	b(vector.z)
{
}

Color3::Color3(const Color& color):
	r(color.r / 255.f),
	g(color.g / 255.f),
	b(color.b / 255.f)
{
}

// Conversion operators
Color3::operator Color() const
{
	return Color {static_cast<unsigned char>(std::clamp(r, 0.0f, 1.0f) * 255.f),
				  static_cast<unsigned char>(std::clamp(g, 0.0f, 1.0f) * 255.f),
				  static_cast<unsigned char>(std::clamp(b, 0.0f, 1.0f) * 255.f), 255};
}

// Access operators
float& Color3::operator[](const std::size_t index)
{
	assert(index <= 2);
	switch (index)
	{
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		default:
			break;
	}
	return r;
}

float Color3::operator[](const std::size_t index) const
{
	assert(index <= 2);
	switch (index)
	{
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		default:
			break;
	}
	return r;
}

// Compound assignment operators
Color3& Color3::operator+=(const Color3& color) noexcept
{
	r += color.r;
	g += color.g;
	b += color.b;
	return *this;
}

Color3& Color3::operator-=(const Color3& color) noexcept
{
	r -= color.r;
	g -= color.g;
	b -= color.b;
	return *this;
}

Color3& Color3::operator*=(const Color3& color) noexcept
{
	r *= color.r;
	g *= color.g;
	b *= color.b;
	return *this;
}

Color3& Color3::operator/=(const Color3& color)
{
	r /= color.r;
	g /= color.g;
	b /= color.b;
	return *this;
}

Color3& Color3::operator^=(const Color3& color) noexcept
{
	r = std::pow(r, color.r);
	g = std::pow(g, color.g);
	b = std::pow(b, color.b);
	return *this;
}

Color3& Color3::operator+=(const float color) noexcept
{
	r += color;
	g += color;
	b += color;
	return *this;
}

Color3& Color3::operator-=(const float color) noexcept
{
	r -= color;
	g -= color;
	b -= color;
	return *this;
}

Color3& Color3::operator*=(const float color) noexcept
{
	r *= color;
	g *= color;
	b *= color;
	return *this;
}

Color3& Color3::operator/=(const float color)
{
	r /= color;
	g /= color;
	b /= color;
	return *this;
}

Color3& Color3::operator^=(const float color) noexcept
{
	r = std::pow(r, color);
	g = std::pow(g, color);
	b = std::pow(b, color);
	return *this;
}

// Arithmetic operators
Color3 operator+(const Color3& leftOperand, const Color3& rightOperand) noexcept
{
	return {leftOperand.r + rightOperand.r, leftOperand.g + rightOperand.g,
			leftOperand.b + rightOperand.b};
}

Color3 operator-(const Color3& leftOperand, const Color3& rightOperand) noexcept
{
	return {leftOperand.r - rightOperand.r, leftOperand.g - rightOperand.g,
			leftOperand.b - rightOperand.b};
}

Color3 operator*(const Color3& leftOperand, const Color3& rightOperand) noexcept
{
	return {leftOperand.r * rightOperand.r, leftOperand.g * rightOperand.g,
			leftOperand.b * rightOperand.b};
}

Color3 operator/(const Color3& leftOperand, const Color3& rightOperand)
{
	return {leftOperand.r / rightOperand.r, leftOperand.g / rightOperand.g,
			leftOperand.b / rightOperand.b};
}

Color3 operator^(const Color3& leftOperand, const Color3& rightOperand) noexcept
{
	return {std::pow(leftOperand.r, rightOperand.r),
			std::pow(leftOperand.g, rightOperand.g),
			std::pow(leftOperand.b, rightOperand.b)};
}

Color3 operator+(const Color3& leftOperand, const float rightOperand) noexcept
{
	return leftOperand + Color3(rightOperand);
}

Color3 operator-(const Color3& leftOperand, const float rightOperand) noexcept
{
	return leftOperand - Color3(rightOperand);
}

Color3 operator*(const Color3& leftOperand, const float rightOperand) noexcept
{
	return leftOperand * Color3(rightOperand);
}

Color3 operator/(const Color3& leftOperand, const float rightOperand)
{
	return leftOperand / Color3(rightOperand);
}

Color3 operator^(const Color3& leftOperand, const float rightOperand) noexcept
{
	return leftOperand ^ Color3(rightOperand);
}

Color3 operator+(const float leftOperand, const Color3& rightOperand) noexcept
{
	return Color3(leftOperand) + rightOperand;
}

Color3 operator-(const float leftOperand, const Color3& rightOperand) noexcept
{
	return Color3(leftOperand) - rightOperand;
}

Color3 operator*(const float leftOperand, const Color3& rightOperand) noexcept
{
	return Color3(leftOperand) * rightOperand;
}

Color3 operator/(const float leftOperand, const Color3& rightOperand)
{
	return Color3(leftOperand) / rightOperand;
}

Color3 operator^(const float leftOperand, const Color3& rightOperand) noexcept
{
	return Color3(leftOperand) ^ rightOperand;
}

// Functionalities
float Color3::Length() const
{
	return sqrtf(r * r + g * g + b * b);
}

Color3 Color3::Normalized() const
{
	if (const float len = Length(); len > 1e-6f)
	{
		return *this / len;
	}
	return Color3(0.f);
}

Color3 Color3::Clamp(const float min, const float max) const
{
	return {std::clamp(r, min, max), std::clamp(g, min, max), std::clamp(b, min, max)};
}

Color3 Color3::Lerp(const Color3& target, const float amount) const
{
	return {r + (target.r - r) * amount, g + (target.g - g) * amount,
			b + (target.b - b) * amount};
}

// Color functionalities
Color3 Color3::HSV(const float h, const float s, const float v)
{
	// Code by Alejandro Hitti from:
	// https://alejandrohitti.com/2015/06/29/rgb-hsv-color-conversions/
	Color3 RGB;

	// Achromatic (gray)
	if (s == 0)
	{
		RGB.r = RGB.g = RGB.b = v;
		return RGB;
	}

	// Conversion values
	const float tempH = h * 6.f;
	const float hueSection = std::floor(tempH);
	const float f = tempH - hueSection;
	const float p = v * (1 - s);
	const float q = v * (1 - s * f);
	const float t = v * (1 - s * (1 - f));

	// There are 6 cases, one for every 60 degrees
	switch (static_cast<int>(hueSection))
	{
		case 0:
			RGB.r = v;
			RGB.g = t;
			RGB.b = p;
			break;

		case 1:
			RGB.r = q;
			RGB.g = v;
			RGB.b = p;
			break;

		case 2:
			RGB.r = p;
			RGB.g = v;
			RGB.b = t;
			break;

		case 3:
			RGB.r = p;
			RGB.g = q;
			RGB.b = v;
			break;

		case 4:
			RGB.r = t;
			RGB.g = p;
			RGB.b = v;
			break;

		default:
			RGB.r = v;
			RGB.g = p;
			RGB.b = q;
			break;
	}

	return RGB;
}

Color3 Color3::HSV(const uint32_t h, const uint32_t s, const uint32_t v)
{
	return HSV(h / 255.f, s / 255.f, v / 255.f);
}

// Parametrized constructors
Color4::Color4(const float r, const float g, const float b, const float a):
	r(r),
	g(g),
	b(b),
	a(a)
{
}

Color4::Color4(const uint32_t r, const uint32_t g, const uint32_t b, const uint32_t a):
	r(r / 255.0f),
	g(g / 255.0f),
	b(b / 255.0f),
	a(a / 255.0f)
{
}

Color4::Color4(const float value):
	r(value),
	g(value),
	b(value),
	a(1.f)
{
}

Color4::Color4(const float value, const float alpha):
	r(value),
	g(value),
	b(value),
	a(alpha)
{
}

// Copy constructors
Color4::Color4(const Color3& color, const float a):
	r(color.r),
	g(color.g),
	b(color.b),
	a(a)
{
}

Color4::Color4(const Vec4& vector):
	r(vector.x),
	g(vector.y),
	b(vector.z),
	a(vector.w)
{
}

Color4::Color4(const Color& color):
	r(color.r / 255.f),
	g(color.g / 255.f),
	b(color.b / 255.f),
	a(color.a / 255.f)
{
}

// Conversion operators
Color4::operator Color() const
{
	return Color {static_cast<unsigned char>(std::clamp(r, 0.0f, 1.0f) * 255.f),
				  static_cast<unsigned char>(std::clamp(g, 0.0f, 1.0f) * 255.f),
				  static_cast<unsigned char>(std::clamp(b, 0.0f, 1.0f) * 255.f),
				  static_cast<unsigned char>(std::clamp(a, 0.0f, 1.0f) * 255.f)};
}

// Access operators
float& Color4::operator[](const std::size_t index)
{
	assert(index <= 3);
	switch (index)
	{
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		case 3:
			return a;
		default:
			break;
	}
	return r;
}

float Color4::operator[](const std::size_t index) const
{
	assert(index <= 3);
	switch (index)
	{
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		case 3:
			return a;
		default:
			break;
	}
	return r;
}

// Compound assignment operators
Color4& Color4::operator+=(const Color4& color) noexcept
{
	r += color.r;
	g += color.g;
	b += color.b;
	a += color.a;
	return *this;
}

Color4& Color4::operator-=(const Color4& color) noexcept
{
	r -= color.r;
	g -= color.g;
	b -= color.b;
	a -= color.a;
	return *this;
}

Color4& Color4::operator*=(const Color4& color) noexcept
{
	r *= color.r;
	g *= color.g;
	b *= color.b;
	a *= color.a;
	return *this;
}

Color4& Color4::operator/=(const Color4& color)
{
	r /= color.r;
	g /= color.g;
	b /= color.b;
	a /= color.a;
	return *this;
}

Color4& Color4::operator^=(const Color4& color) noexcept
{
	r = std::pow(r, color.r);
	g = std::pow(g, color.g);
	b = std::pow(b, color.b);
	a = std::pow(a, color.a);
	return *this;
}

Color4& Color4::operator+=(const float value) noexcept
{
	r += value;
	g += value;
	b += value;
	return *this;
}

Color4& Color4::operator-=(const float value) noexcept
{
	r -= value;
	g -= value;
	b -= value;
	return *this;
}

Color4& Color4::operator*=(const float value) noexcept
{
	r *= value;
	g *= value;
	b *= value;
	return *this;
}

Color4& Color4::operator/=(const float value)
{
	r /= value;
	g /= value;
	b /= value;
	return *this;
}

Color4& Color4::operator^=(const float value) noexcept
{
	r = std::pow(r, value);
	g = std::pow(g, value);
	b = std::pow(b, value);
	return *this;
}

// Arithmetic operators
Color4 operator+(const Color4& leftOperand, const Color4& rightOperand) noexcept
{
	return {leftOperand.r + rightOperand.r, leftOperand.g + rightOperand.g,
			leftOperand.b + rightOperand.b, leftOperand.a + rightOperand.a};
}

Color4 operator-(const Color4& leftOperand, const Color4& rightOperand) noexcept
{
	return {leftOperand.r - rightOperand.r, leftOperand.g - rightOperand.g,
			leftOperand.b - rightOperand.b, leftOperand.a - rightOperand.a};
}

Color4 operator*(const Color4& leftOperand, const Color4& rightOperand) noexcept
{
	return {leftOperand.r * rightOperand.r, leftOperand.g * rightOperand.g,
			leftOperand.b * rightOperand.b, leftOperand.a * rightOperand.a};
}

Color4 operator/(const Color4& leftOperand, const Color4& rightOperand)
{
	return {leftOperand.r / rightOperand.r, leftOperand.g / rightOperand.g,
			leftOperand.b / rightOperand.b, leftOperand.a / rightOperand.a};
}

Color4 operator^(const Color4& leftOperand, const Color4& rightOperand) noexcept
{
	return {
		std::pow(leftOperand.r, rightOperand.r), std::pow(leftOperand.g, rightOperand.g),
		std::pow(leftOperand.b, rightOperand.b), std::pow(leftOperand.a, rightOperand.a)};
}

Color4 operator+(const Color4& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.r + rightOperand, leftOperand.g + rightOperand,
			leftOperand.b + rightOperand, leftOperand.a};
}

Color4 operator-(const Color4& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.r - rightOperand, leftOperand.g - rightOperand,
			leftOperand.b - rightOperand, leftOperand.a};
}

Color4 operator*(const Color4& leftOperand, const float rightOperand) noexcept
{
	return {leftOperand.r * rightOperand, leftOperand.g * rightOperand,
			leftOperand.b * rightOperand, leftOperand.a};
}

Color4 operator/(const Color4& leftOperand, const float rightOperand)
{
	return {leftOperand.r / rightOperand, leftOperand.g / rightOperand,
			leftOperand.b / rightOperand, leftOperand.a};
}

Color4 operator^(const Color4& leftOperand, const float rightOperand) noexcept
{
	return {std::pow(leftOperand.r, rightOperand), std::pow(leftOperand.g, rightOperand),
			std::pow(leftOperand.b, rightOperand), leftOperand.a};
}

Color4 operator+(const float leftOperand, const Color4& rightOperand) noexcept
{
	return {leftOperand + rightOperand.r, leftOperand + rightOperand.g,
			leftOperand + rightOperand.b, rightOperand.a};
}

Color4 operator-(const float leftOperand, const Color4& rightOperand) noexcept
{
	return {leftOperand - rightOperand.r, leftOperand - rightOperand.g,
			leftOperand - rightOperand.b, rightOperand.a};
}

Color4 operator*(const float leftOperand, const Color4& rightOperand) noexcept
{
	return {leftOperand * rightOperand.r, leftOperand * rightOperand.g,
			leftOperand * rightOperand.b, rightOperand.a};
}

Color4 operator/(const float leftOperand, const Color4& rightOperand)
{
	return {leftOperand / rightOperand.r, leftOperand / rightOperand.g,
			leftOperand / rightOperand.b, rightOperand.a};
}

Color4 operator^(const float leftOperand, const Color4& rightOperand) noexcept
{
	return {std::pow(leftOperand, rightOperand.r), std::pow(leftOperand, rightOperand.g),
			std::pow(leftOperand, rightOperand.b), rightOperand.a};
}

// Functionalities
float Color4::Length() const
{
	return sqrtf(r * r + g * g + b * b + a * a);
}

Color4 Color4::Normalized() const
{
	if (const float len = Length(); len > 1e-6f)
	{
		return *this / len;
	}
	return Color4(0.f);
}

Color4 Color4::Clamp(const float min, const float max) const
{
	return {std::clamp(r, min, max), std::clamp(g, min, max), std::clamp(b, min, max),
			std::clamp(a, min, max)};
}

Color4 Color4::Lerp(const Color4& target, const float amount) const
{
	return {r + (target.r - r) * amount, g + (target.g - g) * amount,
			b + (target.b - b) * amount, a + (target.a - a) * amount};
}

uint32_t Color4::ToUInt32() const
{
	auto R = static_cast<uint32_t>(std::clamp(r, 0.0f, 1.0f) * 255.f);
	auto G = static_cast<uint32_t>(std::clamp(g, 0.0f, 1.0f) * 255.f);
	auto B = static_cast<uint32_t>(std::clamp(b, 0.0f, 1.0f) * 255.f);
	auto A = static_cast<uint32_t>(std::clamp(a, 0.0f, 1.0f) * 255.f);
	return R | (G << 8) | (B << 16) | (A << 24);
}

// Color functionalities
Color4 Color4::Grey(float value, float alpha)
{
	return {value, value, value, alpha};
}

Color4 Color4::HSVA(const float h, const float s, const float v, const float a)
{
	return Color4(Color3::HSV(h, s, v), a);
}

Color4 Color4::HSVA(const uint32_t h, const uint32_t s, const uint32_t v,
					const uint32_t a)
{
	return HSVA(h / 255.0f, s / 255.0f, v / 255.0f, a / 255.0f);
}

Color4 Color4::WithAlpha(float alpha) const
{
	return {r, g, b, alpha};
}