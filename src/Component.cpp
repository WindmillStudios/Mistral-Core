#include "Component.h"

#include <ranges>
#include <vector>

#include "Random.h"

static std::map<std::string, std::shared_ptr<Mistral::Component>, std::less<>> components;
static std::vector<std::string> createList;
static std::vector<std::string> destroyList;

Mistral::Component::Component():
	mId(GenerateUUID()),
	mParent(nullptr)
{
}

std::string Mistral::Component::GetId() const
{
	return mId;
}

std::string Mistral::Component::GetName() const
{
	return mName;
}

Mistral::Component* Mistral::Component::GetParent() const
{
	return mParent;
}

const std::vector<Mistral::Component*>& Mistral::Component::GetChildren()
{
	return mChildren;
}

Mistral::Component* Mistral::Component::GetChild(const std::string& childId) const
{
	for (const auto child : mChildren)
	{
		if (child->GetId() == childId)
		{
			return child;
		}
	}
	return nullptr;
}

Spatial& Mistral::Component::GetSpatial()
{
	return mSpatial;
}

uint32_t Mistral::Component::GetChildCount() const
{
	return mChildren.size();
}

bool Mistral::Component::HasChildren() const
{
	return !mChildren.empty();
}

void Mistral::Component::SetName(const std::string& name)
{
	mName = name;
}

void Mistral::Component::SetParent(Component* parent)
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

	mSpatial.SetParent(parent ? &parent->GetSpatial() : nullptr);
}

void Mistral::Component:: AddChild(Component* child)
{
	if (!child)
	{
		return;
	}

	AddChildInternal(child);
	child->SetParentInternal(this);

	mSpatial.AddChild(&child->GetSpatial());
}

void Mistral::Component::RemoveChild(Component* child)
{
	if (!child)
	{
		return;
	}

	RemoveChildInternal(child);
	child->SetParentInternal(nullptr);

	mSpatial.RemoveChild(&child->GetSpatial());
}

void Mistral::Component::SetParentInternal(Component* parent)
{
	mParent = parent;
}

void Mistral::Component::AddChildInternal(Component* child)
{
	if (std::ranges::find(mChildren, child) == mChildren.cend())
	{
		mChildren.push_back(child);
	}
}

void Mistral::Component::RemoveChildInternal(Component* child)
{
	std::erase(mChildren, child);
}

void Mistral::RegisterComponent(std::shared_ptr<Component> component)
{
	createList.emplace_back(component->GetId());
	components.try_emplace(component->GetId(), std::move(component));
}

void Mistral::DestroyComponent(const std::shared_ptr<const Component>& component)
{
	destroyList.emplace_back(component->GetId());
}

void Mistral::DestroyComponent(const std::string& component)
{
	destroyList.emplace_back(component);
}

Mistral::Component& Mistral::GetComponent(const std::string& component)
{
	if (!components.contains(component))
	{
		throw std::runtime_error("Component not found");
	}
	return *components[component];
}

std::ranges::values_view<std::ranges::ref_view<std::map<std::string, std::shared_ptr<Mistral::Component>, std::less<>>>> Mistral::GetComponentsView()
{
	return components | std::views::values;
}

uint32_t Mistral::GetComponentsCount()
{
	return components.size();
}

void Mistral::ComponentCreateEventCallback()
{
	for (const auto& componentId : createList)
	{
		components[componentId]->CreateEvent();
	}
	createList.clear();
}

void Mistral::ComponentDestroyEventCallback()
{
	for (const auto& componentId : destroyList)
	{
		components[componentId]->DestroyEvent();
		components.erase(componentId);
	}
	destroyList.clear();
}

void Mistral::ComponentUpdateEventCallback()
{
	for (const auto& component : components | std::views::values)
	{
		component->UpdateEvent();
	}
}

void Mistral::ComponentFixedUpdateEventCallback()
{
	for (const auto& component : components | std::views::values)
	{
		component->FixedUpdateEvent();
	}
}

void Mistral::ComponentRender3DEventCallback()
{
	for (const auto& component : components | std::views::values)
	{
		component->Render3DEvent();
	}
}

void Mistral::ComponentRender2DEventCallback()
{
	for (const auto& component : components | std::views::values)
	{
		component->Render2DEvent();
	}
}

void Mistral::ComponentRenderGUIEventCallback()
{
	for (const auto& component : components | std::views::values)
	{
		component->RenderGUIEvent();
	}
}