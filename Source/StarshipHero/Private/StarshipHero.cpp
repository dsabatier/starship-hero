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
		FMenuExtensionDelegate::CreateRaw(this, &FStarshipHeroModule::AddMenuEntry)
	);

	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
}

void FStarshipHeroModule::ShutdownModule()
{
}

void FStarshipHeroModule::AddMenuEntry(FMenuBuilder& Builder)
{
	
	FUIAction OpenStarshipSuiteAction;
	OpenStarshipSuiteAction.ExecuteAction = FExecuteAction::CreateLambda([this]()
		{
			RestoreStarshipSuite();
		});

	Builder.AddMenuEntry(
		LOCTEXT("OpenStarshipSuite", "Starship Test Suite"),
		LOCTEXT("OpenStarshipSuiteDesc", "Opens the Starship UX test suite."),
		FSlateIcon(),
		OpenStarshipSuiteAction,
		NAME_None,
		EUserInterfaceActionType::Button);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FStarshipHeroModule, StarshipHero)
