#include "SlateReferenceHero.h"
#include "LevelEditor.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Docking/TabManager.h"

#define LOCTEXT_NAMESPACE "FSlateReferenceHeroModule"

void FSlateReferenceHeroModule::StartupModule()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());

	MenuExtender->AddMenuExtension(
		"WindowLayout", // Extension hook
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateRaw(this, &FSlateReferenceHeroModule::AddMenuEntry)
	);

	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
}

void FSlateReferenceHeroModule::ShutdownModule()
{
}

void FSlateReferenceHeroModule::AddMenuEntry(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(
		LOCTEXT("OpenSlateDemo", "Open Slate Demo"),
		LOCTEXT("OpenSlateDemoDescription", "Launches the built-in Slate Widget Gallery"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateLambda([]() {
			FGlobalTabmanager::Get()->TryInvokeTab(FTabId("SlateSurveyor")); 
		}))
	);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlateReferenceHeroModule, SlateReferenceHero)
