#include "StarshipHero.h"
#include "LevelEditor.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Docking/TabManager.h"
#include "Widgets/Testing/SStarshipSuite.h"
#include "Widgets/Testing/STestSuite.h"

#define LOCTEXT_NAMESPACE "FStarshipHeroModule"

void FStarshipHeroModule::StartupModule()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());

	MenuExtender->AddMenuExtension(
		"WindowLayout", // Extension hook
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateRaw(this, &FStarshipHeroModule::AddMenuEntry)
	);

	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
}

void FStarshipHeroModule::ShutdownModule()
{
}

void FStarshipHeroModule::AddMenuEntry(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(
		LOCTEXT("OpenSlateDemo", "Open Slate Demo"),
		LOCTEXT("OpenSlateDemoDescription", "Launches the built-in Starship Test Suite (Slate Widget Gallery)"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateLambda([]() {
#if !UE_BUILD_SHIPPING
			RestoreStarshipSuite();
#endif
		}))
	);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FStarshipHeroModule, StarshipHero)
