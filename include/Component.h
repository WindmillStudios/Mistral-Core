#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <ranges>
#include <string>
#include <vector>

#include "Spatial.h"

namespace Mistral
{
	class Component;

	// Entities management
	template <typename T, typename... Args>
	T* CreateComponent(Args&&... args)
	{
		std::shared_ptr<T> component = std::make_shared<T>(std::forward<Args>(args)...);
		component->SetName(component->GetTypeName());
		auto ptr = component.get();
		RegisterComponent(component);
		return ptr;
	}

	void RegisterComponent(std::shared_ptr<Component> component);

	void DestroyComponent(const std::shared_ptr<const Component>& component);

	void DestroyComponent(const std::string& component);

	[[nodiscard]] Component& GetComponent(const std::string& component);

	std::ranges::values_view<std::ranges::ref_view<
		std::map<std::string, std::shared_ptr<Component>, std::less<>>>>
	GetComponentsView();

	[[nodiscard]] uint32_t GetComponentsCount();

	// Event callbacks
	void ComponentCreateEventCallback();

	void ComponentDestroyEventCallback();

	void ComponentUpdateEventCallback();

	void ComponentFixedUpdateEventCallback();

	void ComponentRender3DEventCallback();

	void ComponentRender2DEventCallback();

	void ComponentRenderGUIEventCallback();

	class Component
	{
	  public:

		Component();

		virtual ~Component() = default;

		// Getters
		[[nodiscard]] virtual const char* GetTypeName() const = 0;

		[[nodiscard]] std::string GetId() const;

		[[nodiscard]] std::string GetName() const;

		[[nodiscard]] Component* GetParent() const;

		[[nodiscard]] const std::vector<Component*>& GetChildren();

		[[nodiscard]] Component* GetChild(const std::string& childId) const;

		[[nodiscard]] Spatial& GetSpatial();

		[[nodiscard]] uint32_t GetChildCount() const;

		[[nodiscard]] bool HasChildren() const;

		// Setters
		void SetName(const std::string& name);

		void SetParent(Component* parent);

		template <typename T, typename... Args>
		T* CreateChild(Args&&... args)
		{
			auto child = CreateComponent<T>(std::forward<Args>(args)...);
			AddChild(child);
			return child;
		}

		void AddChild(Component* child);

		void RemoveChild(Component* child);

		// Events
		virtual void CreateEvent()
		{
		}

		virtual void DestroyEvent()
		{
		}

		virtual void UpdateEvent()
		{
		}

		virtual void FixedUpdateEvent()
		{
		}

		virtual void Render3DEvent()
		{
		}

		virtual void Render2DEvent()
		{
		}

		virtual void RenderGUIEvent()
		{
		}

	  private:

		void SetParentInternal(Component* parent);

		void AddChildInternal(Component* child);

		void RemoveChildInternal(Component* child);

		std::string mId;
		std::string mName;
		Component* mParent;
		std::vector<Component*> mChildren;
		Spatial mSpatial;
	};
} // namespace Mistral