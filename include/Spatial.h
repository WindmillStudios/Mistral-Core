#pragma once

#include <Matrix.h>
#include <Quaternion.h>
#include <Vector.h>

#include <vector>

class Spatial
{
  public:

	Spatial();

	explicit Spatial(const Vec3& position, const Quat& rotation = Quat::Identity, const Vec3& scale = Vec3::One);

	~Spatial();

	// Copy constructors deleted
	Spatial(const Spatial&) = delete;

	Spatial& operator=(const Spatial&) = delete;

	// Setters
	void SetPosition(const Vec3& position);

	void SetRotation(const Quat& rotation);

	void SetScale(const Vec3& scale);

	void SetParent(Spatial* parent);

	void AddChild(Spatial* child);

	void RemoveChild(Spatial* child);

	// Getters
	[[nodiscard]] const Vec3& GetLocalPosition() const;

	[[nodiscard]] const Quat& GetLocalRotation() const;

	[[nodiscard]] const Vec3& GetLocalScale() const;

	[[nodiscard]] Vec3 GetPosition() const;

	[[nodiscard]] Quat GetRotation() const;

	[[nodiscard]] Vec3 GetScale() const;

	[[nodiscard]] Spatial* GetParent();

	[[nodiscard]] const Spatial* GetParent() const;

	Spatial* GetChild(size_t index) const;

	[[nodiscard]] size_t GetChildrenCount() const;

	// Modifiers
	void Move(const Vec3& offset);

	void Rotate(const Quat& offset);

	void Scale(const Vec3& amount);

	// Functionalities
	[[nodiscard]] const Matrix4x4& GetLocalMatrix() const;

	[[nodiscard]] const Matrix4x4& GetMatrix() const;

	[[nodiscard]] Vec3 Forward() const;

	[[nodiscard]] Vec3 Right() const;

	[[nodiscard]] Vec3 Up() const;

	[[nodiscard]] Vec3 Back() const;

	[[nodiscard]] Vec3 Left() const;

	[[nodiscard]] Vec3 Down() const;

  private:

	void MarkDirty() const;

	void UpdateMatrices() const;

	void SetParentInternal(Spatial* parent);

	void AddChildInternal(Spatial* child);

	void RemoveChildInternal(Spatial* child);

	Vec3 mPosition;
	Quat mRotation;
	Vec3 mScale;

	Spatial* mParent = nullptr;
	std::vector<Spatial*> mChildren;

	mutable Matrix4x4 mWorldMatrix = Matrix4x4::Identity;
	mutable Matrix4x4 mLocalMatrix = Matrix4x4::Identity;
	mutable bool mIsDirty = true;
};

void DrawSpatial(const Spatial& spatial, float size = 1.f);
