#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Observer.h"
#include "PetterPepperComponent.h"

class HealthDisplay : public dae::Observer
{
public:
	virtual ~HealthDisplay() = default;
	void OnNotify(dae::GameObject* pGo, dae::Event event)
	{
		switch (event)
		{
		case dae::Event::Died:
			auto pp = pGo->GetComponent<dae::PetterPepperComponent>();
			const std::string liveTemplate = "Lives: ";
			if (pp)
			{
				m_pTextComp->SetText(liveTemplate + std::to_string(pp->GetLives()));
			}

		}
	}


	HealthDisplay(const std::shared_ptr<dae::TextComponent>& pTextComponent)
		:m_pTextComp(pTextComponent)
	{
	};

private:
	std::shared_ptr<dae::TextComponent> m_pTextComp;
};

class PointDisplay : public dae::Observer
{
public:
	virtual ~PointDisplay() = default;
	void OnNotify(dae::GameObject* pGo, dae::Event event)
	{
		switch (event)
		{
		case dae::Event::GotPoints:
			auto pp = pGo->GetComponent<dae::PetterPepperComponent>();
			const std::string liveTemplate = "Points: ";
			if (pp)
			{
				m_pTextComponent->SetText(liveTemplate + std::to_string(pp->GetPoints()));
			}

		}
	}


	PointDisplay(const std::shared_ptr<dae::TextComponent>& pTextComponent)
		:m_pTextComponent(pTextComponent)
	{
	};
private:
	std::shared_ptr<dae::TextComponent> m_pTextComponent;
};

