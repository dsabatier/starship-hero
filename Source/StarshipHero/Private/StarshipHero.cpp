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
		"Tools", // Extension hook in the Main Tools menu
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateRaw(this, &FStarshipHeroModule::FillToolsMenu)
	);

	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
}

void FStarshipHeroModule::ShutdownModule()
{
}

void FStarshipHeroModule::FillToolsMenu(FMenuBuilder& Builder)
{
	Builder.AddSubMenu(
		LOCTEXT("ToolsSubmenu", "Tools"),
		LOCTEXT("ToolsSubmenuDescription", "External tools and helpers"),
		FNewMenuDelegate::CreateRaw(this, &FStarshipHeroModule::AddMenuEntry)
	);
}

void FStarshipHeroModule::AddMenuEntry(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(
		LOCTEXT("OpenStarshipSuite", "Open StarshipSuite"),
		LOCTEXT("OpenStarshipSuiteDescription", "Launches the built-in Starship Test Suite"),
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
