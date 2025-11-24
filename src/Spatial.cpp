#include "Spatial.h"

#include <algorithm>

#include "Color.h"

Spatial::Spatial():
	mPosition(Vec3::Zero),
	mRotation(Quat::Identity),
	mScale(Vec3::One)
{
}

Spatial::Spatial(const Vec3& position, const Quat& rotation, const Vec3& scale):
	mPosition(position),
	mRotation(rotation),
	mScale(scale)
{
	UpdateMatrices();
}

Spatial::~Spatial()
{
}

// Setters
void Spatial::SetPosition(const Vec3& position)
{
	mPosition = position;
	MarkDirty();
}

void Spatial::SetRotation(const Quat& rotation)
{
	mRotation = rotation;
	MarkDirty();
}

void Spatial::SetScale(const Vec3& scale)
{
	mScale = scale;
	MarkDirty();
}

void Spatial::SetParent(Spatial* parent)
{
	if (mParent == parent)
	{
		return;
	}

	if (mParent)
	{
		mParent->RemoveChildInternal(this);
	}

	SetParentInternal(parent);

	if (mParent)
	{
		mParent->AddChildInternal(this);
	}

	MarkDirty();
}

void Spatial::AddChild(Spatial* child)
{
	if (!child)
	{
		return;
	}

	AddChildInternal(child);
	child->SetParentInternal(this);
}

void Spatial::RemoveChild(Spatial* child)
{
	if (!child)
	{
		return;
	}

	RemoveChildInternal(child);
	child->SetParentInternal(nullptr);
}

// Getters
const Vec3& Spatial::GetLocalPosition() const
{
	UpdateMatrices();
	return mPosition;
}

const Quat& Spatial::GetLocalRotation() const
{
	UpdateMatrices();
	return mRotation;
}

const Vec3& Spatial::GetLocalScale() const
{
	UpdateMatrices();
	return mScale;
}

Vec3 Spatial::GetPosition() const
{
	UpdateMatrices();
	return mWorldMatrix.GetPosition();
}

Quat Spatial::GetRotation() const
{
	UpdateMatrices();
	return mWorldMatrix.GetRotation();
}

Vec3 Spatial::GetScale() const
{
	UpdateMatrices();
	return mWorldMatrix.GetScale();
}

Spatial* Spatial::GetParent()
{
	UpdateMatrices();
	return mParent;
}

const Spatial* Spatial::GetParent() const
{
	UpdateMatrices();
	return mParent;
}

Spatial* Spatial::GetChild(const size_t index) const
{
	if (index >= mChildren.size())
	{
		return nullptr;
	}

	return mChildren[index];
}

size_t Spatial::GetChildrenCount() const
{
	return mChildren.size();
}

// Modifiers
void Spatial::Move(const Vec3& offset)
{
	mPosition += offset;
	MarkDirty();
}

void Spatial::Rotate(const Quat& offset)
{
	mRotation *= offset;
	MarkDirty();
}

void Spatial::Scale(const Vec3& amount)
{
	mScale *= amount;
	MarkDirty();
}

// Functionalities
const Matrix4x4& Spatial::GetMatrix() const
{
	UpdateMatrices();
	return mWorldMatrix;
}

const Matrix4x4& Spatial::GetLocalMatrix() const
{
	UpdateMatrices();
	return mLocalMatrix;
}

Vec3 Spatial::Forward() const
{
	return GetRotation() * Vec3::Forward;
}

Vec3 Spatial::Right() const
{
	return GetRotation() * Vec3::Right;
}

Vec3 Spatial::Up() const
{
	return GetRotation() * Vec3::Up;
}

Vec3 Spatial::Back() const
{
	return GetRotation() * Vec3::Back;
}

Vec3 Spatial::Left() const
{
	return GetRotation() * Vec3::Left;
}

Vec3 Spatial::Down() const
{
	return GetRotation() * Vec3::Down;
}

// Internal
void Spatial::MarkDirty() const
{
	if (mIsDirty)
	{
		return;
	}

	mIsDirty = true;
	std::ranges::for_each(mChildren, [](const auto& child) { child->MarkDirty(); });
}

void Spatial::UpdateMatrices() const
{
	if (!mIsDirty)
	{
		return;
	}

	mLocalMatrix = Matrix4x4::FromPRS(mPosition, mRotation, mScale);
	mWorldMatrix = mParent ? mParent->GetMatrix() * mLocalMatrix : mLocalMatrix;
	mIsDirty = false;
}

void Spatial::SetParentInternal(Spatial* parent)
{
	mParent = parent;
}

void Spatial::AddChildInternal(Spatial* child)
{

	if (std::ranges::find(mChildren, child) == mChildren.cend())
	{
		mChildren.push_back(child);
	}
}

void Spatial::RemoveChildInternal(Spatial* child)
{
	std::erase(mChildren, child);
}

void DrawSpatial(const Spatial& spatial, const float size)
{
	static constexpr int sides = 12;
	const float lineSize = .05f * size;
	const float coneSize = .1f * size;
	const float lineLength = 1.f * size;
	const float coneLength = .2f * size;
	const auto& pos = spatial.GetPosition();
	const auto& scale = spatial.GetLocalScale();
	DrawSphere(pos, .1f, Color4::Black);

	DrawCylinderEx(pos, pos + spatial.Right() * lineLength * scale.x, lineSize, lineSize, sides, Color4::Red);
	DrawCylinderEx(pos, pos + spatial.Up() * lineLength * scale.y, lineSize, lineSize, sides, Color4::Green);
	DrawCylinderEx(pos, pos + spatial.Forward() * lineLength * scale.z, lineSize, lineSize, sides, Color4::Blue);

	DrawCylinderEx(pos + spatial.Right() * lineLength * scale.x, pos + spatial.Right() * (lineLength * scale.x + coneLength), coneSize, 0.f, sides,
				   Color4::Red);
	DrawCylinderEx(pos + spatial.Up() * lineLength * scale.y, pos + spatial.Up() * (lineLength * scale.y + coneLength), coneSize, 0.f, sides,
				   Color4::Green);
	DrawCylinderEx(pos + spatial.Forward() * lineLength * scale.z, pos + spatial.Forward() * (lineLength * scale.z + coneLength), coneSize, 0.f,
				   sides, Color4::Blue);
}