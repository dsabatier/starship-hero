#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FStarshipHeroModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to our command. */
	void AddMenuEntry(FMenuBuilder& Builder);
};
