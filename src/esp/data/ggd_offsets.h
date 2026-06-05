#pragma once

#include <cstdint>

namespace ggd {

namespace modules {
    constexpr uint64_t GameAssembly_Base = 0x00007FF9875A0000;
    constexpr uint32_t GameAssembly_Size = 0x05AF0000;
    constexpr uint64_t UnityPlayer_Base  = 0x00007FF98D090000;
    constexpr uint32_t UnityPlayer_Size  = 0x02179000;
}

namespace rva {
    constexpr uint64_t LocalPlayer_Static                       = 0x0000000005081E90;
    constexpr uint64_t AllPlayers_Static                        = 0x000000000508B228;
    constexpr uint64_t PlayerController__Position               = 0x00000000003D6BE0;
    constexpr uint64_t PlayerController__Role                   = 0x00000000005E8E74;
    constexpr uint64_t PlayerController__IsDead                 = 0x0000000002E242B0;
    constexpr uint64_t PlayerController__KillCooldown           = 0x000000000045A620;
    constexpr uint64_t PlayerController__Velocity               = 0x0000000003F2EC10;
    constexpr uint64_t PlayerController__IsImpostor             = 0x0000000000C62B70;
    constexpr uint64_t PlayerController__PlayerName             = 0x00000000030A5BB4;
    constexpr uint64_t PlayerController__PlayerId               = 0x000000000127A223;
    constexpr uint64_t GameState                                = 0x000000000535A44C;
    constexpr uint64_t Camera__Main                             = 0x00000000004B1990;
    constexpr uint64_t GfxDevice                                = 0x000000000537DE40;
    constexpr uint64_t ClassSoundUIButton                       = 0x0000000000000000;
    constexpr uint64_t ClassPlayerNameTextRefs                  = 0x0000000000000000;
    constexpr uint64_t ClassMapOptionHandler                    = 0x0000000000000000;
    constexpr uint64_t ClassEGameMode                           = 0x0000000000000000;
    constexpr uint64_t ClassMainUIButtonHandler                 = 0x0000000000000000;
    constexpr uint64_t ClassValueTaskSourceAsTask               = 0x0000000000000000;
    constexpr uint64_t ClassCachedEventArgs                     = 0x0000000000000000;
    constexpr uint64_t ClassAwaitableSocketAsyncEventArgs       = 0x0000000000000000;
    constexpr uint64_t ClassGenericUIHandler                    = 0x0000000000000000;
    constexpr uint64_t ClassDifficultyOptionHandler             = 0x0000000000000000;
    constexpr uint64_t ClassTimerInfo                           = 0x0000000000000000;
    constexpr uint64_t ClassCertificateCallbackMapper           = 0x0000000000000000;
    constexpr uint64_t ClassRoleAbilityInfoHandler              = 0x0000000000000000;
    constexpr uint64_t ClassRoleType                            = 0x0000000000000000;
    constexpr uint64_t ClassBody                                = 0x0000000000000000;
    constexpr uint64_t ClassGameManager                         = 0x0000000000000000;
    constexpr uint64_t ClassFowlPlayManager                     = 0x0000000000000000;
    constexpr uint64_t ClassGooseHuntManager                    = 0x0000000000000000;
    constexpr uint64_t ClassTutorialManager                     = 0x0000000000000000;
    constexpr uint64_t ClassSandboxSettingHandler               = 0x0000000000000000;
    constexpr uint64_t ClassWheelEffectButton                   = 0x0000000000000000;
    constexpr uint64_t ClassQuickPlayHandler                    = 0x0000000000000000;
    constexpr uint64_t ClassGodzillaUIMapHandler                = 0x0000000000000000;
    constexpr uint64_t ClassUIMapHandler                        = 0x0000000000000000;
    constexpr uint64_t ClassAchievementPrefabHandler            = 0x0000000000000000;
    constexpr uint64_t ClassMessagePrefabHandler                = 0x0000000000000000;
    constexpr uint64_t ClassPetPrefabHandler                    = 0x0000000000000000;
    constexpr uint64_t ClassRecipePrefabHandler                 = 0x0000000000000000;
    constexpr uint64_t ClassUnlockableRewardPrefabHandler       = 0x0000000000000000;
    constexpr uint64_t ClassNPCChatPanelHandler                 = 0x0000000000000000;
    constexpr uint64_t ClassChatPanelHandler                    = 0x0000000000000000;
    constexpr uint64_t ClassReportCategoryInfo1                 = 0x0000000000000000;
    constexpr uint64_t ClassReportInfo                          = 0x0000000000000000;
    constexpr uint64_t ClassClientSettingsGamepadSelectors      = 0x0000000000000000;
    constexpr uint64_t ClassAudioHandler                        = 0x0000000000000000;
    constexpr uint64_t ClassMiniMapHandler                      = 0x0000000000000000;
    constexpr uint64_t ClassPassageWaysMapFeature               = 0x0000000000000000;
    constexpr uint64_t ClassPlayerCard                          = 0x0000000000000000;
    constexpr uint64_t ClassRabbitTicketSabotageTransition      = 0x0000000000000000;
    constexpr uint64_t ClassTransitionOverlayHandler            = 0x0000000000000000;
    constexpr uint64_t ClassTransitionPlayerHandler             = 0x0000000000000000;
    constexpr uint64_t ClassEReturnToLobbyTrigger               = 0x0000000000000000;
    constexpr uint64_t ClassRoleOptionHandler                   = 0x0000000000000000;
    constexpr uint64_t ClassLobbyTutorialHandler                = 0x0000000000000000;
    constexpr uint64_t ClassVentArrowHandler                    = 0x0000000000000000;
    constexpr uint64_t ClassSystemMessageHandler                = 0x0000000000000000;
    constexpr uint64_t ClassControllerBindShower                = 0x0000000000000000;
    constexpr uint64_t ClassTaskPrefabHandler                   = 0x0000000000000000;
    constexpr uint64_t ClassUICounterCooldownButton             = 0x0000000000000000;
    constexpr uint64_t ClassVotePrefabHandler                   = 0x0000000000000000;
    constexpr uint64_t ClassPlayerController                    = 0x0000000000000000;
    constexpr uint64_t ClassLobbyist                            = 0x0000000000000000;
    constexpr uint64_t ClassTLCCamoDuck                         = 0x0000000000000000;
    constexpr uint64_t ClassCounterSliderSettingValueHandler    = 0x0000000000000000;
    constexpr uint64_t ClassGameTask                            = 0x0000000000000000;
    constexpr uint64_t ClassGamepadNavHelper                    = 0x0000000000000000;
    constexpr uint64_t ClassUICooldownButton                    = 0x0000000000000000;
    constexpr uint64_t ClassGodzillaMapFeature                  = 0x0000000000000000;
    constexpr uint64_t ClassAsyncManualResetEvent               = 0x0000000000000000;
    constexpr uint64_t ClassUtf8MessageState                    = 0x0000000000000000;
    constexpr uint64_t ClassPlayerSummaryUIHandler              = 0x0000000000000000;
    constexpr uint64_t ClassTLCZoneHandler                      = 0x0000000000000000;
    constexpr uint64_t ClassPunchAndDuck_IO                     = 0x0000000000000000;
    constexpr uint64_t ClassWarlockPanelHandler                 = 0x0000000000000000;
    constexpr uint64_t ClassLocustSwarmHandler                  = 0x0000000000000000;
    constexpr uint64_t ClassLoungeGamePanelHandler              = 0x0000000000000000;
    constexpr uint64_t ClassDoNotDisturbPanelHandler            = 0x0000000000000000;
    constexpr uint64_t ClassBasementTeleportHandler             = 0x0000000000000000;
    constexpr uint64_t ClassPlayerShaderHandler                 = 0x0000000000000000;
    constexpr uint64_t ClassMainDataHandler                     = 0x0000000000000000;
    constexpr uint64_t ClassAssetBundlesHandler                 = 0x0000000000000000;
    constexpr uint64_t ClassIAPManager                          = 0x0000000000000000;
    constexpr uint64_t ClassShopConfirmationHandler             = 0x0000000000000000;
    constexpr uint64_t ClassSteamManager                        = 0x0000000000000000;
    constexpr uint64_t ClassSandboxPlayerSettingsMenu           = 0x0000000000000000;
    constexpr uint64_t ClassVoiceChatManager                    = 0x0000000000000000;
    constexpr uint64_t ClassMapManager                          = 0x0000000000000000;
    constexpr uint64_t ClassGameModeUI_Sandbox                  = 0x0000000000000000;
    constexpr uint64_t ClassGameModesManager                    = 0x0000000000000000;
    constexpr uint64_t ClassChatToastHandler                    = 0x0000000000000000;
    constexpr uint64_t ClassBaseUnlockablePrefabHandler         = 0x0000000000000000;
    constexpr uint64_t ClassTranslationManager                  = 0x0000000000000000;
    constexpr uint64_t ClassUnlockablesManager                  = 0x0000000000000000;
    constexpr uint64_t ClassPlayerRolesManager                  = 0x0000000000000000;
    constexpr uint64_t ClassSpecialEventManager                 = 0x0000000000000000;
    constexpr uint64_t ClassMainManager                         = 0x0000000000000000;
    constexpr uint64_t ClassGodzillaManager                     = 0x0000000000000000;
    constexpr uint64_t ClassFishingTaskV2_IO                    = 0x0000000000000000;
    constexpr uint64_t ClassRoomUpdater                         = 0x0000000000000000;
    constexpr uint64_t ClassLoungeAudioMixerHandler             = 0x0000000000000000;
    constexpr uint64_t ClassPointerBlockerHandler               = 0x0000000000000000;
    constexpr uint64_t ClassNewSettingsPanelHandler             = 0x0000000000000000;
    constexpr uint64_t ClassCinemachineStateDrivenCamera        = 0x0000000000000000;
    constexpr uint64_t ClassIntercomPanelHandler                = 0x0000000000000000;
    constexpr uint64_t ClassSabotagePanelHandler                = 0x0000000000000000;
    constexpr uint64_t ClassSabotageButtonHandler               = 0x0000000000000000;
    constexpr uint64_t ClassTelepathyAndClairvoyanceHandler     = 0x0000000000000000;
    constexpr uint64_t ClassDoorsHandler                        = 0x0000000000000000;
    constexpr uint64_t ClassHUDTextHandler                      = 0x0000000000000000;
    constexpr uint64_t ClassGodzillaMiniMapHandler              = 0x0000000000000000;
    constexpr uint64_t ClassCamerasPanelHandler                 = 0x0000000000000000;
    constexpr uint64_t ClassAvengerHandler                      = 0x0000000000000000;
    constexpr uint64_t ClassVentHandler                         = 0x0000000000000000;
    constexpr uint64_t ClassVotingPanelHandler                  = 0x0000000000000000;
    constexpr uint64_t ClassPlayerButtonController              = 0x0000000000000000;
    constexpr uint64_t ClassLocalPlayer                         = 0x0000000000000000;
    constexpr uint64_t ClassUIButton                            = 0x0000000000000000;
    constexpr uint64_t ClassTasksHandler                        = 0x0000000000000000;
    constexpr uint64_t ClassTaskTargetingHandler                = 0x0000000000000000;
    constexpr uint64_t ClassClawMachineSelectorHandler          = 0x0000000000000000;
    constexpr uint64_t ClassGamepadNavigationHelper             = 0x0000000000000000;
    constexpr uint64_t ClassEsperDuck                           = 0x0000000000000000;
    constexpr uint64_t ClassSerialKiller                        = 0x0000000000000000;
    constexpr uint64_t ClassCameraMetadataCacheEntry            = 0x0000000000000000;
    constexpr uint64_t ClassObscuredString                      = 0x0000000000000000;
    constexpr uint64_t ClassBodyguard                           = 0x0000000000000000;
    constexpr uint64_t ClassLoverGoose                          = 0x0000000000000000;
    constexpr uint64_t ClassModeSelectHandler                   = 0x0000000000000000;
    constexpr uint64_t ClassLoungeDoor                          = 0x0000000000000000;
    constexpr uint64_t ClassLobbyPanelHandler                   = 0x0000000000000000;
    constexpr uint64_t ClassGamepadNavigation                   = 0x0000000000000000;
    constexpr uint64_t ClassGamepadNavigationHelperCollection   = 0x0000000000000000;
    constexpr uint64_t ClassRequestState                        = 0x0000000000000000;
    constexpr uint64_t ClassDraftBanRoleHandler                 = 0x0000000000000000;
    constexpr uint64_t ClassGAEvents                            = 0x0000000000000000;
}

namespace SoundUIButton {
    constexpr uint32_t InstanceSize = 0x00000110;

    constexpr int32_t clickedSound                         = 0x00000108;
}

namespace PlayerNameTextRefs {
    constexpr uint32_t InstanceSize = 0x000000A8;

    constexpr int32_t playerNameText                       = 0x00000020;
    constexpr int32_t playerNameTextReadyIcon              = 0x00000028;
    constexpr int32_t playerNameTextHostIcon               = 0x00000030;
    constexpr int32_t playerNameIconParent                 = 0x00000038;
    constexpr int32_t playerNameIconPrefab                 = 0x00000040;
    constexpr int32_t iconAnchoredPosition                 = 0x00000048;
    constexpr int32_t iconCenteredAnchoredPosition         = 0x00000050;
    constexpr int32_t playerStatusEffectIconData           = 0x00000058;
    constexpr int32_t usingCachedEffects                   = 0x00000060;
    constexpr int32_t currentEffectIcons                   = 0x00000068;
    constexpr int32_t cachedEffectIcons                    = 0x00000070;
    constexpr int32_t playerNameRoleText                   = 0x00000078;
    constexpr int32_t playerNameTextDcIcon                 = 0x00000080;
    constexpr int32_t playerNameAbilitySlider              = 0x00000088;
    constexpr int32_t playerNameAbilitySliderFill          = 0x00000090;
    constexpr int32_t canvasGroup                          = 0x00000098;
    constexpr int32_t sandboxPlayerBind                    = 0x000000A0;
}

namespace MapOptionHandler {
    constexpr uint32_t InstanceSize = 0x000000A0;

    constexpr int32_t keyText                              = 0x00000048;
    constexpr int32_t fillImage                            = 0x00000050;
    constexpr int32_t fillSelectedColor                    = 0x00000058;
    constexpr int32_t fillDeslectedColor                   = 0x00000068;
    constexpr int32_t textSelectedColor                    = 0x00000078;
    constexpr int32_t textDeselectedColor                  = 0x00000088;
    constexpr int32_t map                                  = 0x00000098;
}

namespace EGameMode {
    constexpr uint32_t InstanceSize = 0x00000011;

    constexpr int32_t value__                              = 0x00000010;
}

namespace MainUIButtonHandler {
    constexpr uint32_t InstanceSize = 0x000000F8;

    constexpr int32_t isTilted                             = 0x00000090;
    constexpr int32_t lockInButton                         = 0x00000091;
    constexpr int32_t shadow                               = 0x00000098;
    constexpr int32_t border                               = 0x000000A0;
    constexpr int32_t feather                              = 0x000000A8;
    constexpr int32_t featherBorder                        = 0x000000B0;
    constexpr int32_t selectedBorder                       = 0x000000B8;
    constexpr int32_t normalBorder                         = 0x000000C0;
    constexpr int32_t outlineFont                          = 0x000000C8;
    constexpr int32_t normalFont                           = 0x000000D0;
    constexpr int32_t dropFont                             = 0x000000D8;
    constexpr int32_t isMainOverride                       = 0x000000E0;
    constexpr int32_t interactableWhenInactive             = 0x000000E1;
    constexpr int32_t overwriteAutoSizing                  = 0x000000E2;
    constexpr int32_t button                               = 0x000000E8;
    constexpr int32_t highlight                            = 0x000000F0;
}

namespace ValueTaskSourceAsTask {
    constexpr uint32_t InstanceSize = 0x00000068;

    constexpr int32_t s_completionAction                   = 0x00000000;
    constexpr int32_t _source                              = 0x00000058;
    constexpr int32_t _token                               = 0x00000060;
}

namespace CachedEventArgs {
    constexpr uint32_t InstanceSize = 0x00000038;

    constexpr int32_t TaskAccept                           = 0x00000010;
    constexpr int32_t TaskReceive                          = 0x00000018;
    constexpr int32_t TaskSend                             = 0x00000020;
    constexpr int32_t ValueTaskReceive                     = 0x00000028;
    constexpr int32_t ValueTaskSend                        = 0x00000030;
}

namespace AwaitableSocketAsyncEventArgs {
    constexpr uint32_t InstanceSize = 0x000000A8;

    constexpr int32_t Reserved                             = 0x00000000;
    constexpr int32_t s_completedSentinel                  = 0x00000008;
    constexpr int32_t s_availableSentinel                  = 0x00000010;
    constexpr int32_t _continuation                        = 0x00000088;
    constexpr int32_t _executionContext                    = 0x00000090;
    constexpr int32_t _scheduler                           = 0x00000098;
    constexpr int32_t _token                               = 0x000000A0;
    constexpr int32_t WrapExceptionsInIOExceptionsk__BackingField = 0x000000A2;
}

namespace GenericUIHandler {
    constexpr uint32_t InstanceSize = 0x00000028;

    constexpr int32_t isBlockingPanelOpen                  = 0x00000000;
    constexpr int32_t panelsOpened                         = 0x00000004;
    constexpr int32_t openedPanels                         = 0x00000008;
    constexpr int32_t isOpen                               = 0x00000020;
}

namespace DifficultyOptionHandler {
    constexpr uint32_t InstanceSize = 0x00000078;

    constexpr int32_t fillImage                            = 0x00000048;
    constexpr int32_t fillSelectedColor                    = 0x00000050;
    constexpr int32_t fillDeslectedColor                   = 0x00000060;
    constexpr int32_t roleValue                            = 0x00000070;
}

namespace TimerInfo {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t isRunning                            = 0x00000010;
    constexpr int32_t currentValue                         = 0x00000014;
    constexpr int32_t lastUpdateTimeInSeconds              = 0x00000018;
    constexpr int32_t serverTimeInMilliseconds             = 0x0000001C;
}

namespace CertificateCallbackMapper {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t FromHttpClientHandler                = 0x00000010;
    constexpr int32_t ForSocketsHttpHandler                = 0x00000018;
}

namespace RoleAbilityInfoHandler {
    constexpr uint32_t InstanceSize = 0x00000038;

    constexpr int32_t icon                                 = 0x00000020;
    constexpr int32_t description                          = 0x00000028;
    constexpr int32_t highlight                            = 0x00000030;
}

namespace RoleType {
    constexpr uint32_t InstanceSize = 0x00000012;

    constexpr int32_t value__                              = 0x00000010;
}

namespace Body {
    constexpr uint32_t InstanceSize = 0x00000028;

    constexpr int32_t bodyHandler                          = 0x00000010;
    constexpr int32_t collider                             = 0x00000018;
    constexpr int32_t timeCreated                          = 0x00000020;
}

namespace GameManager {
    constexpr uint32_t InstanceSize = 0x000001A0;

    constexpr int32_t onBeforePlayerDeath                  = 0x00000020;
    constexpr int32_t onPlayerDeath                        = 0x00000028;
    constexpr int32_t onPlayerEaten                        = 0x00000030;
    constexpr int32_t onPlayerJoin                         = 0x00000038;
    constexpr int32_t onPlayerQuit                         = 0x00000040;
    constexpr int32_t onPlayerRespawn                      = 0x00000048;
    constexpr int32_t onPlayerChangedRoom                  = 0x00000050;
    constexpr int32_t onPlayerPelicanRelease               = 0x00000058;
    constexpr int32_t onPlayerVote                         = 0x00000060;
    constexpr int32_t onGameLoad                           = 0x00000068;
    constexpr int32_t onGameStart                          = 0x00000070;
    constexpr int32_t onGameEnd                            = 0x00000078;
    constexpr int32_t onGameTimer                          = 0x00000080;
    constexpr int32_t onDisconnectGame                     = 0x00000088;
    constexpr int32_t onReconnectGame                      = 0x00000090;
    constexpr int32_t onReconnectLocalPlayer               = 0x00000098;
    constexpr int32_t onReconnectOtherPlayers              = 0x000000A0;
    constexpr int32_t onSpectatorInfoReceived              = 0x000000A8;
    constexpr int32_t onRoundStart                         = 0x000000B0;
    constexpr int32_t onRoundStop                          = 0x000000B8;
    constexpr int32_t onMeetingStart                       = 0x000000C0;
    constexpr int32_t onMeetingStop                        = 0x000000C8;
    constexpr int32_t onSabotageStart                      = 0x000000D0;
    constexpr int32_t onSabotageStop                       = 0x000000D8;
    constexpr int32_t onHuntStart                          = 0x000000E0;
    constexpr int32_t onLocalTaskCompleted                 = 0x000000E8;
    constexpr int32_t onLocalTaskTargeted                  = 0x000000F0;
    constexpr int32_t onLocalInteractableEntered           = 0x000000F8;
    constexpr int32_t onLocalInteractableExited            = 0x00000100;
    constexpr int32_t onLocalVentInteractableEntered       = 0x00000108;
    constexpr int32_t onLocalVentInteractableExited        = 0x00000110;
    constexpr int32_t onLocalEnteredVent                   = 0x00000118;
    constexpr int32_t onLocalEnteredDifferentVent          = 0x00000120;
    constexpr int32_t onLocalExitedVent                    = 0x00000128;
    constexpr int32_t onGameUpdate                         = 0x00000130;
    constexpr int32_t onGameFixedUpdate                    = 0x00000138;
    constexpr int32_t onGameLateUpdate                     = 0x00000140;
    constexpr int32_t gameState                            = 0x00000148;
    constexpr int32_t gameStartData                        = 0x00000150;
    constexpr int32_t deadBodies                           = 0x00000158;
    constexpr int32_t playerCountAtInitialization          = 0x00000160;
    constexpr int32_t baseGameScore                        = 0x00000164;
    constexpr int32_t scoreForWinning                      = 0x00000168;
    constexpr int32_t pointsPerMinuteOfGamePlay            = 0x0000016C;
    constexpr int32_t scorePackage                         = 0x00000170;
    constexpr int32_t tokensEarned                         = 0x00000178;
    constexpr int32_t shortGame                            = 0x00000180;
    constexpr int32_t confirmedRolesDelay                  = 0x00000184;
    constexpr int32_t isPickingRoles                       = 0x00000188;
    constexpr int32_t rolesAreConfirmed                    = 0x00000189;
    constexpr int32_t confirmedRolesPlayers                = 0x00000190;
    constexpr int32_t hasMimic                             = 0x00000198;
}

namespace FowlPlayManager {
    constexpr uint32_t InstanceSize = 0x00000058;

    constexpr int32_t eventsModule                         = 0x00000040;
    constexpr int32_t fowlPlayers                          = 0x00000048;
    constexpr int32_t notesHandler                         = 0x00000050;
}

namespace GooseHuntManager {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t eventsModule                         = 0x00000040;
    constexpr int32_t GameModeTimer                        = 0x00000048;
    constexpr int32_t startGameModeTimer                   = 0x0000004C;
    constexpr int32_t duckSpeedBoosted                     = 0x0000004D;
    constexpr int32_t timeMultiplierPerPlayer              = 0x00000050;
    constexpr int32_t gameModeTimerCoroutine               = 0x00000058;
}

namespace TutorialManager {
    constexpr uint32_t InstanceSize = 0x00000050;

    constexpr int32_t eventsModule                         = 0x00000040;
    constexpr int32_t setup                                = 0x00000048;
}

namespace SandboxSettingHandler {
    constexpr uint32_t InstanceSize = 0x00000370;

    constexpr int32_t settingsContainer                    = 0x00000020;
    constexpr int32_t panelAnimator                        = 0x00000028;
    constexpr int32_t panelCanvasGroup                     = 0x00000030;
    constexpr int32_t categoryHandlers                     = 0x00000038;
    constexpr int32_t mapContentParent                     = 0x00000040;
    constexpr int32_t generalButtons                       = 0x00000048;
    constexpr int32_t simulateMatchConditionsCheckbox      = 0x00000050;
    constexpr int32_t mapFeatureContainer                  = 0x00000058;
    constexpr int32_t mapFeaturePrefab                     = 0x00000060;
    constexpr int32_t resetTasksButton                     = 0x00000068;
    constexpr int32_t roofVisibilityCheckbox               = 0x00000070;
    constexpr int32_t fogOfWarCheckbox                     = 0x00000078;
    constexpr int32_t sabotageUIContainer                  = 0x00000080;
    constexpr int32_t sabotageUIDisabledCover              = 0x00000088;
    constexpr int32_t sabotageUIPrefab                     = 0x00000090;
    constexpr int32_t mapScrollRect                        = 0x00000098;
    constexpr int32_t destructionPage                      = 0x000000A0;
    constexpr int32_t destructionTabFill                   = 0x000000A8;
    constexpr int32_t destructionTabStroke                 = 0x000000B0;
    constexpr int32_t destructionUIk__BackingField         = 0x000000B8;
    constexpr int32_t wheelOfEffectsUIk__BackingField      = 0x000000C0;
    constexpr int32_t wheelOfEffectsPage                   = 0x000000C8;
    constexpr int32_t wheelOfEffectsTabFill                = 0x000000D0;
    constexpr int32_t wheelOfEffectsTabStroke              = 0x000000D8;
    constexpr int32_t excludedRolePrefab                   = 0x000000E0;
    constexpr int32_t excludedRoleContainer                = 0x000000E8;
    constexpr int32_t roleContainer                        = 0x000000F0;
    constexpr int32_t roleSelectButtonPrefab               = 0x000000F8;
    constexpr int32_t roleFactionButtons                   = 0x00000100;
    constexpr int32_t roleNameText                         = 0x00000108;
    constexpr int32_t roleDescriptionText                  = 0x00000110;
    constexpr int32_t roleIcon                             = 0x00000118;
    constexpr int32_t roleFrame                            = 0x00000120;
    constexpr int32_t roleDifficultyStars                  = 0x00000128;
    constexpr int32_t selectRoleButton                     = 0x00000130;
    constexpr int32_t roleSelected                         = 0x00000138;
    constexpr int32_t roleSelectButtons                    = 0x00000140;
    constexpr int32_t roleSelectScroll                     = 0x00000148;
    constexpr int32_t cosmeticTitle                        = 0x00000150;
    constexpr int32_t cosmeticDescription                  = 0x00000158;
    constexpr int32_t cosmeticTier                         = 0x00000160;
    constexpr int32_t cosmeticTierText                     = 0x00000168;
    constexpr int32_t gooseCosmeticUIHandler               = 0x00000170;
    constexpr int32_t gooseUnlockableHolder                = 0x00000178;
    constexpr int32_t gooseBannerUnlockableHolder          = 0x00000180;
    constexpr int32_t gooseBannerUnlockableObj             = 0x00000188;
    constexpr int32_t gooseCardUnlockableHolder            = 0x00000190;
    constexpr int32_t gooseCardUnlockableObj               = 0x00000198;
    constexpr int32_t presetUnlockablePrefab               = 0x000001A0;
    constexpr int32_t presetBannerUnlockablePrefab         = 0x000001A8;
    constexpr int32_t presetCardUnlockablePrefab           = 0x000001B0;
    constexpr int32_t cosmeticTabContainer                 = 0x000001B8;
    constexpr int32_t cosmeticTabToggleGroup               = 0x000001C0;
    constexpr int32_t randomOutfitButton                   = 0x000001C8;
    constexpr int32_t bannerButton                         = 0x000001D0;
    constexpr int32_t cardButton                           = 0x000001D8;
    constexpr int32_t unlockableFilterPanel                = 0x000001E0;
    constexpr int32_t filterButton                         = 0x000001E8;
    constexpr int32_t searchInputField                     = 0x000001F0;
    constexpr int32_t searchFieldActiveSprite              = 0x000001F8;
    constexpr int32_t searchFieldInactiveSprite            = 0x00000200;
    constexpr int32_t searchIcon                           = 0x00000208;
    constexpr int32_t clearSearchIcon                      = 0x00000210;
    constexpr int32_t searchIconActiveColor                = 0x00000218;
    constexpr int32_t searchIconInactiveColor              = 0x00000228;
    constexpr int32_t searchCoroutine                      = 0x00000238;
    constexpr int32_t searchInputs                         = 0x00000240;
    constexpr int32_t localizedSearchableKeys              = 0x00000248;
    constexpr int32_t cosmeticTabs                         = 0x00000250;
    constexpr int32_t customizeUnlockables                 = 0x00000258;
    constexpr int32_t itemsInSubTab                        = 0x00000260;
    constexpr int32_t itemsGridPaging                      = 0x00000268;
    constexpr int32_t itemGrid                             = 0x00000270;
    constexpr int32_t cosmeticSelectedType                 = 0x00000278;
    constexpr int32_t selectedCosmeticTab                  = 0x00000280;
    constexpr int32_t cosmeticCurrentPage                  = 0x00000288;
    constexpr int32_t setupItemsGridCoroutine              = 0x00000290;
    constexpr int32_t pageText                             = 0x00000298;
    constexpr int32_t upButton                             = 0x000002A0;
    constexpr int32_t downButton                           = 0x000002A8;
    constexpr int32_t swipeDetection                       = 0x000002B0;
    constexpr int32_t colorPanelButton                     = 0x000002B8;
    constexpr int32_t colorMenu                            = 0x000002C0;
    constexpr int32_t colorButtons                         = 0x000002C8;
    constexpr int32_t colorButtonFills                     = 0x000002D0;
    constexpr int32_t colorButtonX                         = 0x000002D8;
    constexpr int32_t pages                                = 0x000002E0;
    constexpr int32_t nextPageButton                       = 0x000002E8;
    constexpr int32_t previousPageButton                   = 0x000002F0;
    constexpr int32_t tutorialCloseButton                  = 0x000002F8;
    constexpr int32_t closeTutorialButton                  = 0x00000300;
    constexpr int32_t firstTimeTutorialShown               = 0x00000308;
    constexpr int32_t gamepadNavHelper                     = 0x00000310;
    constexpr int32_t isSwiping                            = 0x00000318;
    constexpr int32_t hasSwiped                            = 0x00000319;
    constexpr int32_t lastInputPos                         = 0x0000031C;
    constexpr int32_t inSwipeCooldown                      = 0x00000328;
    constexpr int32_t swipeCooldown                        = 0x0000032C;
    constexpr int32_t rJoystickAction                      = 0x00000330;
    constexpr int32_t releasedAfterSelecting               = 0x00000338;
    constexpr int32_t movedGrid                            = 0x00000339;
    constexpr int32_t currentTab                           = 0x0000033C;
    constexpr int32_t currentCategoryHandler               = 0x00000340;
    constexpr int32_t selectTargetEntity                   = 0x00000350;
    constexpr int32_t mapFeatures                          = 0x00000358;
    constexpr int32_t sabotageUIs                          = 0x00000360;
    constexpr int32_t controllerSetup                      = 0x00000368;
}

namespace WheelEffectButton {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t button                               = 0x00000010;
    constexpr int32_t highlight                            = 0x00000018;
}

namespace QuickPlayHandler {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t _leftRooms                           = 0x00000028;
    constexpr int32_t _currentRoomName                     = 0x00000030;
    constexpr int32_t _currentQuery                        = 0x00000038;
    constexpr int32_t _currentRegionIndex                  = 0x00000040;
    constexpr int32_t _currentOptions                      = 0x00000044;
}

namespace GodzillaUIMapHandler {
    constexpr uint32_t InstanceSize = 0x000000E0;

    constexpr int32_t destroyedBuildings                   = 0x000000B0;
    constexpr int32_t explosionImage                       = 0x000000B8;
    constexpr int32_t specialDestroyedBuildings            = 0x000000C0;
    constexpr int32_t currentExplosionBuildingIndex        = 0x000000C8;
    constexpr int32_t explosionSpriteIndex                 = 0x000000CC;
    constexpr int32_t explosionUpdateCounter               = 0x000000D0;
    constexpr int32_t isExplosionActive                    = 0x000000D4;
    constexpr int32_t isMultiExplosion                     = 0x000000D5;
    constexpr int32_t godzillaMiniMapHandler               = 0x000000D8;
}

namespace UIMapHandler {
    constexpr uint32_t InstanceSize = 0x000000B0;

    constexpr int32_t miniMaps                             = 0x00000020;
    constexpr int32_t map                                  = 0x00000028;
    constexpr int32_t meetingIconImage                     = 0x00000030;
    constexpr int32_t myLocation                           = 0x00000038;
    constexpr int32_t miniMapHandlerObj                    = 0x00000040;
    constexpr int32_t safeZoneMaterial                     = 0x00000048;
    constexpr int32_t safeZoneOverlay                      = 0x00000050;
    constexpr int32_t sabotageImage                        = 0x00000058;
    constexpr int32_t targetImages                         = 0x00000060;
    constexpr int32_t targetImagesAnimators                = 0x00000068;
    constexpr int32_t bloodMoonImages                      = 0x00000070;
    constexpr int32_t bloodMoonParent                      = 0x00000078;
    constexpr int32_t esperImage                           = 0x00000080;
    constexpr int32_t specialBlipParent                    = 0x00000088;
    constexpr int32_t currentLayer                         = 0x00000090;
}

namespace AchievementPrefabHandler {
    constexpr uint32_t InstanceSize = 0x00000080;

    constexpr int32_t achievementInfo                      = 0x00000020;
    constexpr int32_t completedAchievementInfo             = 0x00000028;
    constexpr int32_t isCompleted                          = 0x00000030;
    constexpr int32_t achievementImage                     = 0x00000038;
    constexpr int32_t achievementToggle                    = 0x00000040;
    constexpr int32_t progress                             = 0x00000048;
    constexpr int32_t loadingAnim                          = 0x00000050;
    constexpr int32_t completedCheckmark                   = 0x00000058;
    constexpr int32_t rewardObjs                           = 0x00000060;
    constexpr int32_t rewardIcons                          = 0x00000068;
    constexpr int32_t rewardCompletedIcons                 = 0x00000070;
    constexpr int32_t highlight                            = 0x00000078;
}

namespace MessagePrefabHandler {
    constexpr uint32_t InstanceSize = 0x000000F8;

    constexpr int32_t message                              = 0x00000020;
    constexpr int32_t sender                               = 0x00000028;
    constexpr int32_t isGhost                              = 0x00000030;
    constexpr int32_t isSpectator                          = 0x00000031;
    constexpr int32_t isLocal                              = 0x00000032;
    constexpr int32_t isFriend                             = 0x00000033;
    constexpr int32_t isMeeting                            = 0x00000034;
    constexpr int32_t isSystem                             = 0x00000035;
    constexpr int32_t messageTextOverflowed                = 0x00000038;
    constexpr int32_t messageTextNormal                    = 0x00000040;
    constexpr int32_t textOverflowRect                     = 0x00000048;
    constexpr int32_t senderText                           = 0x00000050;
    constexpr int32_t deadImage                            = 0x00000058;
    constexpr int32_t spectatorImage                       = 0x00000060;
    constexpr int32_t icon                                 = 0x00000068;
    constexpr int32_t hat                                  = 0x00000070;
    constexpr int32_t eyes                                 = 0x00000078;
    constexpr int32_t clothes                              = 0x00000080;
    constexpr int32_t cardBorder                           = 0x00000088;
    constexpr int32_t card                                 = 0x00000090;
    constexpr int32_t defaultCardBorderColor               = 0x00000098;
    constexpr int32_t blockButton                          = 0x000000A8;
    constexpr int32_t background                           = 0x000000B0;
    constexpr int32_t sizeFitter                           = 0x000000B8;
    constexpr int32_t translatedImage                      = 0x000000C0;
    constexpr int32_t failedToTranslateImage               = 0x000000C8;
    constexpr int32_t IsMe                                 = 0x000000D0;
    constexpr int32_t Timestamp                            = 0x000000D8;
    constexpr int32_t timestampIntervalText                = 0x000000E0;
    constexpr int32_t padding                              = 0x000000E8;
    constexpr int32_t IsBuilt                              = 0x000000EC;
    constexpr int32_t playerInfo                           = 0x000000F0;
}

namespace PetPrefabHandler {
    constexpr uint32_t InstanceSize = 0x00000058;

    constexpr int32_t petOwner                             = 0x00000020;
    constexpr int32_t animator                             = 0x00000028;
    constexpr int32_t bodyScale                            = 0x00000030;
    constexpr int32_t petRenderers                         = 0x00000038;
    constexpr int32_t petAnimator                          = 0x00000040;
    constexpr int32_t distanceToOwner                      = 0x00000048;
    constexpr int32_t shouldMove                           = 0x0000004C;
    constexpr int32_t petId                                = 0x00000050;
}

namespace RecipePrefabHandler {
    constexpr uint32_t InstanceSize = 0x00000058;

    constexpr int32_t currencyCostPrefab                   = 0x00000020;
    constexpr int32_t buyButton                            = 0x00000028;
    constexpr int32_t orText                               = 0x00000030;
    constexpr int32_t unlockableInfo                       = 0x00000038;
    constexpr int32_t recipeIndex                          = 0x00000040;
    constexpr int32_t recipe                               = 0x00000048;
    constexpr int32_t onSale                               = 0x00000050;
    constexpr int32_t isLast                               = 0x00000051;
}

namespace UnlockableRewardPrefabHandler {
    constexpr uint32_t InstanceSize = 0x000000E0;

    constexpr int32_t bannerUI                             = 0x000000D0;
    constexpr int32_t cardUI                               = 0x000000D8;
}

namespace NPCChatPanelHandler {
    constexpr uint32_t InstanceSize = 0x00000138;

    constexpr int32_t messageFlippedPrefab                 = 0x00000028;
    constexpr int32_t systemMessagePrefab                  = 0x00000030;
    constexpr int32_t messagesHolder                       = 0x00000038;
    constexpr int32_t buttonObj                            = 0x00000040;
    constexpr int32_t endConversationButton                = 0x00000048;
    constexpr int32_t messageToSend                        = 0x00000050;
    constexpr int32_t hat                                  = 0x00000058;
    constexpr int32_t eyes                                 = 0x00000060;
    constexpr int32_t clothes                              = 0x00000068;
    constexpr int32_t icon                                 = 0x00000070;
    constexpr int32_t npcName                              = 0x00000078;
    constexpr int32_t loadingPanel                         = 0x00000080;
    constexpr int32_t blocker                              = 0x00000088;
    constexpr int32_t container                            = 0x00000090;
    constexpr int32_t nicknameInput                        = 0x00000098;
    constexpr int32_t createNicknameButton                 = 0x000000A0;
    constexpr int32_t pronounsDropdown                     = 0x000000A8;
    constexpr int32_t feedbackPanel                        = 0x000000B0;
    constexpr int32_t feedbackInput                        = 0x000000B8;
    constexpr int32_t feedbackSendButton                   = 0x000000C0;
    constexpr int32_t maxMessages                          = 0x000000C8;
    constexpr int32_t gamepadNavHelper                     = 0x000000D0;
    constexpr int32_t chatScrollRect                       = 0x000000D8;
    constexpr int32_t rStickAction                         = 0x000000E0;
    constexpr int32_t currentValue                         = 0x000000E8;
    constexpr int32_t navCooldown                          = 0x000000EC;
    constexpr int32_t navTimer                             = 0x000000F0;
    constexpr int32_t inCooldown                           = 0x000000F4;
    constexpr int32_t minNavValue                          = 0x000000F8;
    constexpr int32_t mouseClicked                         = 0x000000FC;
    constexpr int32_t mouseClickTimer                      = 0x00000108;
    constexpr int32_t npcManager                           = 0x00000120;
    constexpr int32_t npc                                  = 0x00000128;
    constexpr int32_t canSendMessage                       = 0x00000130;
    constexpr int32_t sentOpenedEvent                      = 0x00000131;
    constexpr int32_t waitingOnNickname                    = 0x00000132;
    constexpr int32_t waitingOnResponse                    = 0x00000133;
    constexpr int32_t currentTab                           = 0x00000134;
}

namespace ChatPanelHandler {
    constexpr uint32_t InstanceSize = 0x00000200;

    constexpr int32_t messagePrefab                        = 0x00000020;
    constexpr int32_t messageFlippedPrefab                 = 0x00000028;
    constexpr int32_t systemMessagePrefab                  = 0x00000030;
    constexpr int32_t systemErrorMessagePrefab             = 0x00000038;
    constexpr int32_t messageToastPrefab                   = 0x00000040;
    constexpr int32_t roomHostText                         = 0x00000048;
    constexpr int32_t numOfPlayersText                     = 0x00000050;
    constexpr int32_t isMeetingPanel                       = 0x00000058;
    constexpr int32_t panelAnimator                        = 0x00000060;
    constexpr int32_t panelCanvasGroup                     = 0x00000068;
    constexpr int32_t containerBlocker                     = 0x00000070;
    constexpr int32_t containers                           = 0x00000078;
    constexpr int32_t yesButtons                           = 0x00000080;
    constexpr int32_t noButtons                            = 0x00000088;
    constexpr int32_t playerText                           = 0x00000090;
    constexpr int32_t reportRow                            = 0x00000098;
    constexpr int32_t reportText                           = 0x000000A0;
    constexpr int32_t blockRow                             = 0x000000A8;
    constexpr int32_t blockText                            = 0x000000B0;
    constexpr int32_t hat                                  = 0x000000B8;
    constexpr int32_t eyes                                 = 0x000000C0;
    constexpr int32_t clothes                              = 0x000000C8;
    constexpr int32_t icon                                 = 0x000000D0;
    constexpr int32_t playerName                           = 0x000000D8;
    constexpr int32_t readyButtonChatHolder                = 0x000000E0;
}

namespace ReportCategoryInfo1 {
    constexpr uint32_t InstanceSize = 0x00000000;

    constexpr int32_t categoryType                         = 0x00000000;
    constexpr int32_t translation                          = 0x00000000;
}

namespace ReportInfo {
    constexpr uint32_t InstanceSize = 0x00000038;

    constexpr int32_t mainCategory                         = 0x00000010;
    constexpr int32_t subCategories                        = 0x00000030;
}

namespace ClientSettingsGamepadSelectors {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t type                                 = 0x00000010;
    constexpr int32_t selectors                            = 0x00000018;
}

namespace AudioHandler {
    constexpr uint32_t InstanceSize = 0x00000028;

    constexpr int32_t userVol                              = 0x00000020;
}

namespace MiniMapHandler {
    constexpr uint32_t InstanceSize = 0x00000190;

    constexpr int32_t miniLayers                           = 0x00000020;
    constexpr int32_t currentLayer                         = 0x00000028;
    constexpr int32_t myLocation                           = 0x00000050;
    constexpr int32_t myTargetLocation                     = 0x00000058;
    constexpr int32_t myLastKnownLocation                  = 0x00000060;
    constexpr int32_t sabotageLocation                     = 0x00000068;
    constexpr int32_t showSabotageLocation                 = 0x00000070;
    constexpr int32_t uiAnimator                           = 0x00000078;
    constexpr int32_t mapImage                             = 0x00000080;
    constexpr int32_t meetingIconImage                     = 0x00000088;
    constexpr int32_t blipImage                            = 0x00000090;
    constexpr int32_t sabotageImage                        = 0x00000098;
    constexpr int32_t taskTargetFocus                      = 0x000000A0;
    constexpr int32_t safeZoneOverlay                      = 0x000000A8;
    constexpr int32_t targetImages                         = 0x000000B0;
    constexpr int32_t targetImagesAnimators                = 0x000000B8;
    constexpr int32_t targetTaskText                       = 0x000000C0;
    constexpr int32_t bloodMoonImages                      = 0x000000C8;
    constexpr int32_t bloodMoonParent                      = 0x000000D0;
    constexpr int32_t esperImage                           = 0x000000D8;
    constexpr int32_t specialBlipParent                    = 0x000000E0;
    constexpr int32_t specialBlips                         = 0x000000E8;
    constexpr int32_t basicBlipPrefab                      = 0x000000F0;
    constexpr int32_t showBloodMoon                        = 0x000000F8;
    constexpr int32_t showSafeZone                         = 0x000000F9;
    constexpr int32_t showTrackerDots                      = 0x000000FA;
    constexpr int32_t bloodMoonPositions                   = 0x00000100;
    constexpr int32_t randMin                              = 0x00000108;
    constexpr int32_t randMax                              = 0x0000010C;
    constexpr int32_t startSabotageTime                    = 0x00000110;
    constexpr int32_t onDuration                           = 0x00000114;
    constexpr int32_t isEsper                              = 0x00000118;
    constexpr int32_t isTracker                            = 0x00000119;
    constexpr int32_t isSafeZoneRingVisible                = 0x0000011A;
    constexpr int32_t safeZoneRadius                       = 0x0000011C;
    constexpr int32_t safeZoneNewRadius                    = 0x00000120;
    constexpr int32_t safeZonePosition                     = 0x00000124;
    constexpr int32_t safeZoneNewPosition                  = 0x0000012C;
    constexpr int32_t safeZoneMaterial                     = 0x00000138;
    constexpr int32_t trackerDotsCoroutine                 = 0x00000140;
    constexpr int32_t sandboxToolParent                    = 0x00000148;
    constexpr int32_t teleportButton                       = 0x00000150;
    constexpr int32_t teleportCrosshair                    = 0x00000158;
    constexpr int32_t teleportCrosshairHintText            = 0x00000160;
    constexpr int32_t controllerUI                         = 0x00000168;
    constexpr int32_t UIMapHandlerk__BackingField          = 0x00000170;
    constexpr int32_t canClosePanel                        = 0x00000178;
    constexpr int32_t onMiniMapOpened                      = 0x00000180;
    constexpr int32_t onMiniMapClosed                      = 0x00000188;
}

namespace PassageWaysMapFeature {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t ROOM_NAME                            = 0x00000000;
    constexpr int32_t secretPassageWays                    = 0x00000048;
    constexpr int32_t passageColliderRuleSet               = 0x00000050;
    constexpr int32_t ignoreColliderRuleSet                = 0x00000058;
}

namespace PlayerCard {
    constexpr uint32_t InstanceSize = 0x00000038;

    constexpr int32_t transform                            = 0x00000010;
    constexpr int32_t body                                 = 0x00000018;
    constexpr int32_t eyes                                 = 0x00000020;
    constexpr int32_t hat                                  = 0x00000028;
    constexpr int32_t clothes                              = 0x00000030;
}

namespace RabbitTicketSabotageTransition {
    constexpr uint32_t InstanceSize = 0x00000070;

    constexpr int32_t wheelSpin                            = 0x00000020;
    constexpr int32_t spinFunction                         = 0x00000028;
    constexpr int32_t playerCards                          = 0x00000030;
    constexpr int32_t playerNameTitle                      = 0x00000038;
    constexpr int32_t audioSource                          = 0x00000040;
    constexpr int32_t slotPull                             = 0x00000048;
    constexpr int32_t slotClick                            = 0x00000050;
    constexpr int32_t playerInfo                           = 0x00000058;
    constexpr int32_t playerIndex                          = 0x00000060;
    constexpr int32_t cardIndex                            = 0x00000064;
    constexpr int32_t spinTimer                            = 0x00000068;
    constexpr int32_t spinnerActive                        = 0x0000006C;
}

namespace TransitionOverlayHandler {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t goose                                = 0x00000020;
    constexpr int32_t name                                 = 0x00000028;
    constexpr int32_t canvasGroup                          = 0x00000030;
    constexpr int32_t rectTransform                        = 0x00000038;
    constexpr int32_t layoutRectTransform                  = 0x00000040;
    constexpr int32_t changingState                        = 0x00000048;
    constexpr int32_t _player                              = 0x00000050;
    constexpr int32_t isPlayerNull                         = 0x00000058;
}

namespace TransitionPlayerHandler {
    constexpr uint32_t InstanceSize = 0x000000E0;

    constexpr int32_t playerInfo                           = 0x00000020;
    constexpr int32_t body                                 = 0x00000028;
    constexpr int32_t bits                                 = 0x00000030;
    constexpr int32_t eyes                                 = 0x00000038;
    constexpr int32_t hat                                  = 0x00000040;
    constexpr int32_t clothes                              = 0x00000048;
    constexpr int32_t roleIcon                             = 0x00000050;
    constexpr int32_t taskAward                            = 0x00000058;
    constexpr int32_t deathAward                           = 0x00000060;
    constexpr int32_t rabbitAward                          = 0x00000068;
    constexpr int32_t nameTag                              = 0x00000070;
    constexpr int32_t roleName                             = 0x00000078;
    constexpr int32_t tasksCompletedText                   = 0x00000080;
    constexpr int32_t tasksCompletedPodiumText             = 0x00000088;
    constexpr int32_t showRole                             = 0x00000090;
    constexpr int32_t showName                             = 0x00000091;
    constexpr int32_t ghostSprite                          = 0x00000098;
    constexpr int32_t normalEyes                           = 0x000000A0;
    constexpr int32_t ghostBits                            = 0x000000A8;
    constexpr int32_t bodySprite                           = 0x000000B0;
    constexpr int32_t bitsSprite                           = 0x000000B8;
    constexpr int32_t enableTaskAward                      = 0x000000C0;
    constexpr int32_t playerAwards                         = 0x000000C8;
    constexpr int32_t facingRight                          = 0x000000D0;
    constexpr int32_t PodiumImage                          = 0x000000D8;
}

namespace EReturnToLobbyTrigger {
    constexpr uint32_t InstanceSize = 0x00000014;

    constexpr int32_t value__                              = 0x00000010;
}

namespace RoleOptionHandler {
    constexpr uint32_t InstanceSize = 0x000000A0;

    constexpr int32_t keyText                              = 0x00000048;
    constexpr int32_t fillImage                            = 0x00000050;
    constexpr int32_t fillSelectedColor                    = 0x00000058;
    constexpr int32_t fillDeslectedColor                   = 0x00000068;
    constexpr int32_t textSelectedColor                    = 0x00000078;
    constexpr int32_t textDeselectedColor                  = 0x00000088;
    constexpr int32_t roleValue                            = 0x00000098;
}

namespace LobbyTutorialHandler {
    constexpr uint32_t InstanceSize = 0x00000028;

    constexpr int32_t tutorialPanels                       = 0x00000020;
}

namespace VentArrowHandler {
    constexpr uint32_t InstanceSize = 0x00000030;

    constexpr int32_t destinationVent                      = 0x00000020;
    constexpr int32_t boxCollider                          = 0x00000028;
}

namespace SystemMessageHandler {
    constexpr uint32_t InstanceSize = 0x00000030;

    constexpr int32_t messageText                          = 0x00000020;
    constexpr int32_t lines                                = 0x00000028;
}

namespace ControllerBindShower {
    constexpr uint32_t InstanceSize = 0x00000080;

    constexpr int32_t inputActionReference                 = 0x00000020;
    constexpr int32_t staticSize                           = 0x00000028;
    constexpr int32_t runUpdate                            = 0x00000029;
    constexpr int32_t canvasGroup                          = 0x00000030;
    constexpr int32_t circleContainer                      = 0x00000038;
    constexpr int32_t circleSymbol                         = 0x00000040;
    constexpr int32_t circleText                           = 0x00000048;
    constexpr int32_t boxContainer                         = 0x00000050;
    constexpr int32_t boxText                              = 0x00000058;
    constexpr int32_t noContainer                          = 0x00000060;
    constexpr int32_t noSymbol                             = 0x00000068;
    constexpr int32_t bindData                             = 0x00000070;
    constexpr int32_t previousBinding                      = 0x00000078;
}

namespace TaskPrefabHandler {
    constexpr uint32_t InstanceSize = 0x00000078;

    constexpr int32_t taskNameText                         = 0x00000020;
    constexpr int32_t taskTarget                           = 0x00000028;
    constexpr int32_t taskTargetArrow                      = 0x00000030;
    constexpr int32_t task                                 = 0x00000038;
    constexpr int32_t isThisTaskTimedSabotage              = 0x00000040;
    constexpr int32_t IsTimedSabotage                      = 0x00000001;
    constexpr int32_t CurrentSabotagesCount                = 0x00000004;
    constexpr int32_t TimedSabotageTasks                   = 0x00000008;
    constexpr int32_t isCompleted                          = 0x00000041;
    constexpr int32_t baseText                             = 0x00000048;
    constexpr int32_t targetImage                          = 0x00000050;
    constexpr int32_t targetSelctor                        = 0x00000058;
    constexpr int32_t checkmarkSprite                      = 0x00000060;
    constexpr int32_t isWaitingTimer                       = 0x00000068;
    constexpr int32_t waitingTimer                         = 0x0000006C;
    constexpr int32_t startWaitingTime                     = 0x00000070;
    constexpr int32_t taskSabotageTime                     = 0x00000074;
}

namespace UICounterCooldownButton {
    constexpr uint32_t InstanceSize = 0x00000170;

    constexpr int32_t counterTextBackground                = 0x00000150;
    constexpr int32_t counterText                          = 0x00000158;
    constexpr int32_t counterTextMaterials                 = 0x00000160;
    constexpr int32_t currentCount                         = 0x00000168;
}

namespace VotePrefabHandler {
    constexpr uint32_t InstanceSize = 0x00000208;

    constexpr int32_t ALIVE_COLOR_OUTLINE                  = 0x00000000;
    constexpr int32_t DEAD_COLOR_OUTLINE                   = 0x00000010;
    constexpr int32_t isSkipButton                         = 0x00000020;
    constexpr int32_t skipButtonImages                     = 0x00000028;
    constexpr int32_t voteCardPlayerTextDict               = 0x00000030;
    constexpr int32_t defaultCardPlayerText                = 0x00000038;
    constexpr int32_t defaultTextColor                     = 0x00000088;
    constexpr int32_t defaultBackgroundColor               = 0x00000098;
    constexpr int32_t statusEffectIcons                    = 0x000000A8;
    constexpr int32_t bannerCoverDisplays                  = 0x000000B0;
    constexpr int32_t bannerCoverDisplayRect               = 0x000000B8;
    constexpr int32_t killAbilityAnimator                  = 0x000000C0;
    constexpr int32_t ASSASSINATED_ABILITY_ANIMATOR_PARAM  = 0x000000C8;
    constexpr int32_t HELIUMKILL_ABILITY_ANIMATOR_PARAM    = 0x000000CC;
    constexpr int32_t inAnimation                          = 0x000000D0;
    constexpr int32_t outlineBackgrounds                   = 0x000000D8;
    constexpr int32_t voteButton                           = 0x000000E0;
    constexpr int32_t playerName                           = 0x000000E8;
    constexpr int32_t playerNameBackground                 = 0x000000F0;
    constexpr int32_t roleNameText                         = 0x000000F8;
    constexpr int32_t roleIcon                             = 0x00000100;
    constexpr int32_t roleFrame                            = 0x00000108;
    constexpr int32_t roleIconObj                          = 0x00000110;
    constexpr int32_t highlight                            = 0x00000118;
    constexpr int32_t votedPanel                           = 0x00000120;
    constexpr int32_t skippedVotesText                     = 0x00000128;
    constexpr int32_t votedPrefabGridLayouts               = 0x00000130;
    constexpr int32_t speakerImage                         = 0x00000138;
    constexpr int32_t statusEffectIcon                     = 0x00000140;
    constexpr int32_t statusEffectIconGrid                 = 0x00000148;
    constexpr int32_t disconnectIcon                       = 0x00000150;
    constexpr int32_t noSpeakImage                         = 0x00000158;
    constexpr int32_t isSpeakingOuter                      = 0x00000160;
    constexpr int32_t isChattingImage                      = 0x00000168;
    constexpr int32_t hasVotedImage                        = 0x00000170;
    constexpr int32_t gooseView                            = 0x00000178;
    constexpr int32_t gooseThumbnail                       = 0x00000180;
    constexpr int32_t aliveGooseBanner                     = 0x00000188;
    constexpr int32_t deadGooseBanner                      = 0x00000190;
    constexpr int32_t hat                                  = 0x00000198;
    constexpr int32_t clothes                              = 0x000001A0;
    constexpr int32_t bits                                 = 0x000001A8;
    constexpr int32_t eyes                                 = 0x000001B0;
    constexpr int32_t banner                               = 0x000001B8;
    constexpr int32_t swapToPlayerButton                   = 0x000001C0;
    constexpr int32_t sandboxSelectedPlayerOutline         = 0x000001C8;
    constexpr int32_t tutorialArrow                        = 0x000001D0;
    constexpr int32_t masterSyncedVoteCount                = 0x000001D8;
    constexpr int32_t updateVoteDisplay                    = 0x000001DC;
    constexpr int32_t playerId                             = 0x000001E0;
    constexpr int32_t playerInfo                           = 0x000001E8;
    constexpr int32_t votes                                = 0x000001F0;
    constexpr int32_t presetStatusIcon                     = 0x000001F8;
    constexpr int32_t currentCoverType                     = 0x000001FC;
    constexpr int32_t killedThisMeeting                    = 0x000001FD;
    constexpr int32_t isReportedBody                       = 0x000001FE;
    constexpr int32_t hasVoted                             = 0x000001FF;
    constexpr int32_t hasQuit                              = 0x00000200;
    constexpr int32_t facingRight                          = 0x00000201;
}

namespace PlayerController {
    constexpr uint32_t InstanceSize = 0x000003A0;

    constexpr int32_t PlayerControllers                    = 0x00000000;
    constexpr int32_t cachedSpectatorInfo                  = 0x00000008;
    constexpr int32_t roomCollider                         = 0x00000338;
    constexpr int32_t playerTriggerCollider                = 0x00000340;
    constexpr int32_t speaker                              = 0x00000348;
    constexpr int32_t photonAudioSource                    = 0x00000350;
    constexpr int32_t interestGroup                        = 0x00000358;
    constexpr int32_t isTransmitting                       = 0x00000359;
    constexpr int32_t noMicMode                            = 0x0000035A;
    constexpr int32_t fadingVoice                          = 0x0000035B;
    constexpr int32_t disconnectedFromVoice                = 0x0000035C;
    constexpr int32_t originalVolume                       = 0x00000360;
    constexpr int32_t micBlocked                           = 0x00000364;
    constexpr int32_t micMuted                             = 0x00000365;
    constexpr int32_t mutedPlayers                         = 0x00000368;
    constexpr int32_t micBlockedPlayers                    = 0x00000370;
    constexpr int32_t isTestingMic                         = 0x00000378;
    constexpr int32_t isSuperSpeaker                       = 0x00000379;
    constexpr int32_t isSuperListener                      = 0x0000037A;
    constexpr int32_t actorNumber                          = 0x0000037C;
    constexpr int32_t readyState                           = 0x00000380;
    constexpr int32_t oldTransformPosition                 = 0x00000384;
    constexpr int32_t runTime                              = 0x00000390;
    constexpr int32_t firstStep                            = 0x00000394;
    constexpr int32_t stepCoolDown                         = 0x00000398;
    constexpr int32_t firstStepStartTime                   = 0x0000039C;
}

namespace Lobbyist {
    constexpr uint32_t InstanceSize = 0x000000D0;

    constexpr int32_t killButton                           = 0x000000B8;
    constexpr int32_t killButtonActive                     = 0x000000C0;
    constexpr int32_t currentKillButtonCount               = 0x000000C4;
    constexpr int32_t totalVotesNeeded                     = 0x000000C8;
}

namespace TLCCamoDuck {
    constexpr uint32_t InstanceSize = 0x000000D0;

    constexpr int32_t playersOnEnemyTeams                  = 0x000000A8;
    constexpr int32_t camoDuckVisibilityRangeIndicator     = 0x000000B0;
    constexpr int32_t camoDuckVisibilityRangeIndicatorMat  = 0x000000B8;
    constexpr int32_t visibilityRangeFadeCoroutine         = 0x000000C0;
    constexpr int32_t isRangeIndicatorVisible              = 0x000000C8;
    constexpr int32_t currentVisibilityRangeIndicatorAlpha = 0x000000CC;
}

namespace CounterSliderSettingValueHandler {
    constexpr uint32_t InstanceSize = 0x00000070;

    constexpr int32_t counter                              = 0x00000040;
    constexpr int32_t slider                               = 0x00000048;
    constexpr int32_t valueSet                             = 0x00000050;
    constexpr int32_t ValueChanged                         = 0x00000054;
    constexpr int32_t areValuesTexts                       = 0x00000055;
    constexpr int32_t valueTexts                           = 0x00000058;
    constexpr int32_t minimumValues                        = 0x00000060;
    constexpr int32_t maximumValues                        = 0x00000068;
}

namespace GameTask {
    constexpr uint32_t InstanceSize = 0x000000E8;

    constexpr int32_t taskId                               = 0x00000010;
    constexpr int32_t taskDisplayName                      = 0x00000018;
    constexpr int32_t taskObject                           = 0x00000020;
    constexpr int32_t taskObjectIsNull                     = 0x00000028;
    constexpr int32_t taskPanel                            = 0x00000030;
    constexpr int32_t huntType                             = 0x00000038;
    constexpr int32_t currentContinuationIndex             = 0x0000003C;
    constexpr int32_t continuationIndex                    = 0x00000040;
    constexpr int32_t taskContinuation                     = 0x00000048;
    constexpr int32_t isRandomlyAssignable                 = 0x00000050;
    constexpr int32_t hasToBeAssigned                      = 0x00000051;
    constexpr int32_t notEligibleForFakeTask               = 0x00000052;
    constexpr int32_t isSabotage                           = 0x00000053;
    constexpr int32_t dontCountAsCompletedTask             = 0x00000054;
    constexpr int32_t dontReplenishWhenCompleted           = 0x00000055;
    constexpr int32_t taskDuplicateType                    = 0x00000058;
    constexpr int32_t sabotageTime                         = 0x00000060;
    constexpr int32_t taskCompletionCallback               = 0x00000068;
    constexpr int32_t isCallbackVisual                     = 0x00000070;
    constexpr int32_t isTaskShared                         = 0x00000071;
    constexpr int32_t globalTask                           = 0x00000072;
    constexpr int32_t isTaskCompletionCallbackAlsoRemote   = 0x00000073;
    constexpr int32_t hasSecondaryTaskObject               = 0x00000074;
    constexpr int32_t secondaryTaskObject                  = 0x00000078;
    constexpr int32_t isImpostorTask                       = 0x00000080;
    constexpr int32_t excludeFromSabotageConfigurations    = 0x00000088;
    constexpr int32_t sabotageButton                       = 0x00000090;
    constexpr int32_t destroyAfterCompletion               = 0x00000098;
    constexpr int32_t validAchievements                    = 0x000000A0;
    constexpr int32_t awardAchievementsOnCompletion        = 0x000000A8;
    constexpr int32_t isEventTask                          = 0x000000A9;
    constexpr int32_t eventTaskStartDate                   = 0x000000B0;
    constexpr int32_t eventTaskEndDate                     = 0x000000B8;
    constexpr int32_t taskDimension                        = 0x000000C0;
    constexpr int32_t alternateObjects                     = 0x000000C8;
    constexpr int32_t useCircleAsTaskPointOnMap            = 0x000000D0;
    constexpr int32_t isFakeTask                           = 0x000000D1;
    constexpr int32_t taskUIInList                         = 0x000000D8;
    constexpr int32_t connectedPlayers                     = 0x000000E0;
    constexpr int32_t hasLocalTimer                        = 0x000000E4;
}

namespace GamepadNavHelper {
    constexpr uint32_t InstanceSize = 0x00000180;

    constexpr int32_t OpenedPanels                         = 0x00000000;
    constexpr int32_t blocker                              = 0x00000020;
    constexpr int32_t ignorePopupCheck                     = 0x00000028;
    constexpr int32_t unhighlightedColor                   = 0x0000002C;
    constexpr int32_t highlightedColor                     = 0x0000003C;
    constexpr int32_t keepLastCurrentIndex                 = 0x0000004C;
    constexpr int32_t gamepadHelpers                       = 0x00000050;
    constexpr int32_t needsVertical                        = 0x00000058;
    constexpr int32_t needsHorizontal                      = 0x00000059;
    constexpr int32_t isVerticalIncreaseReversed           = 0x0000005A;
    constexpr int32_t isHorizontalIncreaseReversed         = 0x0000005B;
    constexpr int32_t isScrollRect                         = 0x0000005C;
    constexpr int32_t scrollRect                           = 0x00000060;
    constexpr int32_t scrollOffset                         = 0x00000068;
    constexpr int32_t numOfIgnoredRows                     = 0x0000006C;
    constexpr int32_t isScrollingReversed                  = 0x00000070;
    constexpr int32_t canSwitchTabs                        = 0x00000071;
    constexpr int32_t usesTwoButtons                       = 0x00000072;
    constexpr int32_t tabClicked                           = 0x00000078;
    constexpr int32_t needsLeftTrigger                     = 0x00000080;
    constexpr int32_t needsRightTrigger                    = 0x00000081;
    constexpr int32_t needsSlider                          = 0x00000082;
    constexpr int32_t needsButtonWest                      = 0x00000083;
    constexpr int32_t enableCoroutine                      = 0x00000088;
    constexpr int32_t playerInput                          = 0x00000090;
    constexpr int32_t dpad                                 = 0x00000098;
    constexpr int32_t lStick                               = 0x000000A0;
    constexpr int32_t use                                  = 0x000000A8;
    constexpr int32_t rStick                               = 0x000000B0;
    constexpr int32_t close                                = 0x000000B8;
    constexpr int32_t lTrigger                             = 0x000000C0;
    constexpr int32_t rTrigger                             = 0x000000C8;
    constexpr int32_t lShoulder                            = 0x000000D0;
    constexpr int32_t rShoulder                            = 0x000000D8;
    constexpr int32_t buttonNorth                          = 0x000000E0;
    constexpr int32_t buttonWest                           = 0x000000E8;
    constexpr int32_t closeClicked                         = 0x000000F0;
    constexpr int32_t leftTriggerCallback                  = 0x000000F8;
    constexpr int32_t rightTriggerCallback                 = 0x00000100;
    constexpr int32_t buttonWestCallback                   = 0x00000108;
    constexpr int32_t uiCancelCallback                     = 0x00000110;
    constexpr int32_t currentIndex                         = 0x00000118;
    constexpr int32_t currentTab                           = 0x0000011C;
    constexpr int32_t canNavigate                          = 0x00000120;
    constexpr int32_t canClick                             = 0x00000121;
    constexpr int32_t canClickInfo                         = 0x00000122;
    constexpr int32_t canUseTriggers                       = 0x00000123;
    constexpr int32_t closeAssigned                        = 0x00000124;
    constexpr int32_t removeCloseIfClicked                 = 0x00000125;
    constexpr int32_t removeUICloseIfClicked               = 0x00000126;
    constexpr int32_t canUseSlider                         = 0x00000127;
    constexpr int32_t isSliding                            = 0x00000128;
    constexpr int32_t canUseButtonWest                     = 0x00000129;
    constexpr int32_t canUseClose                          = 0x0000012A;
    constexpr int32_t freezeScroll                         = 0x0000012B;
    constexpr int32_t tryCountLimit                        = 0x0000012C;
    constexpr int32_t minNavValue                          = 0x00000130;
    constexpr int32_t navCooldown                          = 0x00000134;
    constexpr int32_t lastNavTime                          = 0x00000138;
    constexpr int32_t startNavCount                        = 0x0000013C;
    constexpr int32_t useButtonCooldown                    = 0x00000140;
    constexpr int32_t lastUseTime                          = 0x00000144;
    constexpr int32_t startUseCount                        = 0x00000148;
    constexpr int32_t maxCloseTime                         = 0x0000014C;
    constexpr int32_t lastCloseTime                        = 0x00000150;
    constexpr int32_t startCloseCount                      = 0x00000154;
    constexpr int32_t sliderCooldown                       = 0x00000158;
    constexpr int32_t lastSliderTime                       = 0x0000015C;
    constexpr int32_t startSliderCount                     = 0x00000160;
    constexpr int32_t minMoveValue                         = 0x00000164;
    constexpr int32_t maxEnableTime                        = 0x00000168;
    constexpr int32_t enableTime                           = 0x0000016C;
    constexpr int32_t startEnableTime                      = 0x00000170;
    constexpr int32_t gamepadBeingUsed                     = 0x00000171;
    constexpr int32_t gamepadDetected                      = 0x00000172;
    constexpr int32_t inPopup                              = 0x00000173;
    constexpr int32_t currentSelectedObject                = 0x00000178;
}

namespace UICooldownButton {
    constexpr uint32_t InstanceSize = 0x00000150;

    constexpr int32_t cooldownText                         = 0x000000A8;
    constexpr int32_t DefaultCooldown                      = 0x000000B0;
    constexpr int32_t Paused                               = 0x000000C8;
    constexpr int32_t ShowCooldown                         = 0x000000C9;
    constexpr int32_t triggeredOnReady                     = 0x000000CA;
    constexpr int32_t InternalCooldown                     = 0x000000CC;
    constexpr int32_t topLayerImage                        = 0x000000E8;
    constexpr int32_t cooldownTextBackground               = 0x000000F0;
    constexpr int32_t onReady                              = 0x000000F8;
    constexpr int32_t overrideCooldown                     = 0x00000100;
    constexpr int32_t doubleCooldown                       = 0x0000010C;
    constexpr int32_t hp1                                  = 0x00000118;
    constexpr int32_t hp2                                  = 0x00000124;
    constexpr int32_t AllowClick                           = 0x0000013C;
    constexpr int32_t interactableOverride                 = 0x00000148;
    constexpr int32_t interactableOverrideEvenInCooldown   = 0x00000149;
}

namespace GodzillaMapFeature {
    constexpr uint32_t InstanceSize = 0x00000078;

    constexpr int32_t godzillaSpawnLocations               = 0x00000048;
    constexpr int32_t plasmaBeams                          = 0x00000050;
    constexpr int32_t godzillaAudioSource                  = 0x00000058;
    constexpr int32_t roarAudioClips                       = 0x00000060;
    constexpr int32_t heatRayClip                          = 0x00000068;
    constexpr int32_t isAttacking                          = 0x00000070;
    constexpr int32_t currentPlasmaBeamIndex               = 0x00000074;
}

namespace AsyncManualResetEvent {
    constexpr uint32_t InstanceSize = 0x00000018;

    constexpr int32_t m_tcs                                = 0x00000010;
}

namespace Utf8MessageState {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t SequenceInProgress                   = 0x00000010;
    constexpr int32_t AdditionalBytesExpected              = 0x00000014;
    constexpr int32_t ExpectedValueMin                     = 0x00000018;
    constexpr int32_t CurrentDecodeBits                    = 0x0000001C;
}

namespace PlayerSummaryUIHandler {
    constexpr uint32_t InstanceSize = 0x00000070;

    constexpr int32_t playerName                           = 0x00000020;
    constexpr int32_t playerRole                           = 0x00000028;
    constexpr int32_t deadBodyImage                        = 0x00000030;
    constexpr int32_t dcBodyImage                          = 0x00000038;
    constexpr int32_t awards                               = 0x00000040;
    constexpr int32_t hat                                  = 0x00000048;
    constexpr int32_t clothes                              = 0x00000050;
    constexpr int32_t bits                                 = 0x00000058;
    constexpr int32_t eyes                                 = 0x00000060;
    constexpr int32_t body                                 = 0x00000068;
}

namespace TLCZoneHandler {
    constexpr uint32_t InstanceSize = 0x00000078;

    constexpr int32_t zoneMeshRenderer                     = 0x00000020;
    constexpr int32_t zoneChangeDuration                   = 0x00000028;
    constexpr int32_t miniMapHandler                       = 0x00000030;
    constexpr int32_t zoneSpawnArea                        = 0x00000038;
    constexpr int32_t firstRadius                          = 0x00000040;
    constexpr int32_t initialZoneRadius                    = 0x00000044;
    constexpr int32_t zoneMeshMaterial                     = 0x00000048;
    constexpr int32_t timeSinceRingChange                  = 0x00000050;
    constexpr int32_t ringShowing                          = 0x00000054;
    constexpr int32_t currentZoneCenter                    = 0x00000058;
    constexpr int32_t currentZoneRadius                    = 0x00000060;
    constexpr int32_t targetZoneCenter                     = 0x00000064;
    constexpr int32_t targetZoneRadius                     = 0x0000006C;
    constexpr int32_t timeUntilTextDisable                 = 0x00000070;
}

namespace PunchAndDuck_IO {
    constexpr uint32_t InstanceSize = 0x00000140;

    constexpr int32_t punchEffectAnimationCurve            = 0x00000050;
    constexpr int32_t redDuckAnimator                      = 0x00000058;
    constexpr int32_t blueDuckAnimator                     = 0x00000060;
    constexpr int32_t redDuckKnockHeadOffPivot             = 0x00000068;
    constexpr int32_t redDuckKnockHeadOffEndPoint          = 0x00000070;
    constexpr int32_t redDuckKnockHeadOffEffect            = 0x00000078;
    constexpr int32_t blueDuckKnockHeadOffPivot            = 0x00000080;
    constexpr int32_t blueDuckKnockHeadOffEndPoint         = 0x00000088;
    constexpr int32_t blueDuckKnockHeadOffEffect           = 0x00000090;
    constexpr int32_t knockHeadOffDelay                    = 0x00000098;
    constexpr int32_t knockHeadOffDuration                 = 0x0000009C;
    constexpr int32_t knockHeadOffAnimationCurve           = 0x000000A0;
    constexpr int32_t knockHeadOffCurveFactor              = 0x000000A8;
    constexpr int32_t currentPhotographsMoodPlaying        = 0x000000AC;
    constexpr int32_t transition                           = 0x000000B0;
    constexpr int32_t targetHitCount                       = 0x000000B8;
    constexpr int32_t minDelayBetweenPunches               = 0x000000C0;
    constexpr int32_t delayBetweenHurt                     = 0x000000C4;
    constexpr int32_t shaker                               = 0x000000C8;
    constexpr int32_t photographs                          = 0x000000D0;
    constexpr int32_t redDuckPunch                         = 0x000000D8;
    constexpr int32_t redDuckSteam                         = 0x000000E0;
    constexpr int32_t redDuckImpact                        = 0x000000E8;
    constexpr int32_t blueDuckPunch                        = 0x000000F0;
    constexpr int32_t blueDuckSteam                        = 0x000000F8;
    constexpr int32_t blueDuckImpact                       = 0x00000100;
    constexpr int32_t redDuckAudio                         = 0x00000108;
    constexpr int32_t blueDuckAudio                        = 0x00000110;
    constexpr int32_t sfx                                  = 0x00000118;
    constexpr int32_t lastPunchTime                        = 0x00000120;
    constexpr int32_t currentHitCount                      = 0x00000124;
    constexpr int32_t lastHurtTime                         = 0x00000128;
    constexpr int32_t currentHurtCount                     = 0x0000012C;
    constexpr int32_t currentTargetHitCount                = 0x00000130;
    constexpr int32_t isPaused                             = 0x00000134;
    constexpr int32_t isInTransition                       = 0x00000135;
    constexpr int32_t endAnimationCoroutine                = 0x00000138;
}

namespace WarlockPanelHandler {
    constexpr uint32_t InstanceSize = 0x00000038;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t locustButtons                        = 0x00000020;
    constexpr int32_t locustData                           = 0x00000028;
    constexpr int32_t locustRooms                          = 0x00000030;
}

namespace LocustSwarmHandler {
    constexpr uint32_t InstanceSize = 0x00000040;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t swarms                               = 0x00000020;
    constexpr int32_t timeSinceRoomStart                   = 0x00000028;
    constexpr int32_t maxTime                              = 0x0000002C;
    constexpr int32_t targetRoom                           = 0x00000030;
    constexpr int32_t locustStarted                        = 0x00000038;
}

namespace LoungeGamePanelHandler {
    constexpr uint32_t InstanceSize = 0x00000070;

    constexpr int32_t targetPanel                          = 0x00000020;
    constexpr int32_t blockingObjects                      = 0x00000028;
    constexpr int32_t openPanel                            = 0x00000030;
    constexpr int32_t closePanel                           = 0x00000038;
    constexpr int32_t backdrop                             = 0x00000040;
    constexpr int32_t isOpen                               = 0x00000048;
    constexpr int32_t parentRect                           = 0x00000050;
    constexpr int32_t myRect                               = 0x00000058;
    constexpr int32_t parentCanvasSize                     = 0x00000060;
    constexpr int32_t canClose                             = 0x00000068;
}

namespace DoNotDisturbPanelHandler {
    constexpr uint32_t InstanceSize = 0x00000040;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t targetDoor                           = 0x00000020;
    constexpr int32_t signText                             = 0x00000028;
    constexpr int32_t source                               = 0x00000030;
    constexpr int32_t flipClip                             = 0x00000038;
}

namespace BasementTeleportHandler {
    constexpr uint32_t InstanceSize = 0x00000048;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t effectAnimPrefab                     = 0x00000020;
    constexpr int32_t effectContainer                      = 0x00000028;
    constexpr int32_t teleporterPosition                   = 0x00000030;
    constexpr int32_t audioSource                          = 0x00000038;
    constexpr int32_t teleportClip                         = 0x00000040;
}

namespace PlayerShaderHandler {
    constexpr uint32_t InstanceSize = 0x00000040;

    constexpr int32_t renderers                            = 0x00000020;
    constexpr int32_t materialEffect                       = 0x00000028;
    constexpr int32_t materialInstance                     = 0x00000030;
    constexpr int32_t eShaderState                         = 0x00000038;
}

namespace MainDataHandler {
    constexpr uint32_t InstanceSize = 0x00000140;

    constexpr int32_t RefreshInit                          = 0x00000000;
    constexpr int32_t currentRefreshTime                   = 0x00000008;
    constexpr int32_t prePackages                          = 0x00000020;
    constexpr int32_t postPackages                         = 0x00000028;
    constexpr int32_t maxGGDProcessAttempts                = 0x00000030;
    constexpr int32_t startingDownload                     = 0x00000034;
    constexpr int32_t globalSilverRateModifier             = 0x00000038;
    constexpr int32_t ownedUnlockables                     = 0x00000040;
    constexpr int32_t userUnlockables                      = 0x00000048;
    constexpr int32_t petsProperties                       = 0x00000050;
    constexpr int32_t petUsage                             = 0x00000058;
    constexpr int32_t petOfTheWeek                         = 0x00000060;
    constexpr int32_t announcements                        = 0x00000068;
    constexpr int32_t bannerData                           = 0x00000070;
    constexpr int32_t earlyAccess                          = 0x00000078;
    constexpr int32_t enableGifting                        = 0x00000080;
    constexpr int32_t minFriendshipPeriodInMs              = 0x00000088;
    constexpr int32_t remainingTime                        = 0x00000090;
    constexpr int32_t rewardIndex                          = 0x00000094;
    constexpr int32_t serverRollbackTimeLeft               = 0x00000098;
    constexpr int32_t rollbackAsSoonAsPossible             = 0x000000A0;
    constexpr int32_t xpBoostRate                          = 0x000000A4;
    constexpr int32_t xpBoostRemainingTime                 = 0x000000A8;
    constexpr int32_t availableOffers                      = 0x000000B0;
    constexpr int32_t unopenedOffers                       = 0x000000B8;
    constexpr int32_t unopenedGifts                        = 0x000000C0;
    constexpr int32_t offerSpriteDictionary                = 0x000000C8;
    constexpr int32_t currentOffers                        = 0x000000D0;
    constexpr int32_t hasNewOffers                         = 0x000000D8;
    constexpr int32_t dustShopConfig                       = 0x000000E0;
    constexpr int32_t playerFlights                        = 0x000000E8;
    constexpr int32_t reportedPlayers                      = 0x000000F0;
    constexpr int32_t playerBlockList                      = 0x000000F8;
    constexpr int32_t menuThemesScriptable                 = 0x00000100;
    constexpr int32_t menuThemeData                        = 0x00000108;
    constexpr int32_t currentMenuTheme                     = 0x00000110;
    constexpr int32_t mapsData                             = 0x00000118;
    constexpr int32_t gameModesData                        = 0x00000120;
    constexpr int32_t isLoadingGGDData                     = 0x00000128;
    constexpr int32_t unlockablesManager                   = 0x00000130;
    constexpr int32_t codeRedemptionVersion                = 0x00000138;
}

namespace AssetBundlesHandler {
    constexpr uint32_t InstanceSize = 0x00000058;

    constexpr int32_t skipManifestCheck                    = 0x00000020;
    constexpr int32_t swapToBetaLink                       = 0x00000021;
    constexpr int32_t loadAssetQueue                       = 0x00000028;
    constexpr int32_t isLoadingAsset                       = 0x00000030;
    constexpr int32_t loadingAssetCoroutine                = 0x00000038;
    constexpr int32_t bundlesToLoad                        = 0x00000040;
    constexpr int32_t AssetBundleManifest                  = 0x00000008;
    constexpr int32_t PreloadedAssets                      = 0x00000010;
    constexpr int32_t S3_LINK                              = 0x00000018;
    constexpr int32_t AssetCache                           = 0x00000048;
    constexpr int32_t AssetCacheOrder                      = 0x00000050;
}

namespace IAPManager {
    constexpr uint32_t InstanceSize = 0x000000C8;

    constexpr int32_t runReloadCoroutine                   = 0x00000020;
    constexpr int32_t gooseShop                            = 0x00000028;
    constexpr int32_t battlePass                           = 0x00000030;
    constexpr int32_t cachedCatalog                        = 0x00000038;
    constexpr int32_t itemsAvailableInShop                 = 0x00000040;
    constexpr int32_t builder                              = 0x00000048;
    constexpr int32_t m_StoreController                    = 0x00000050;
    constexpr int32_t m_StoreExtensionProvider             = 0x00000058;
    constexpr int32_t m_AppleExtensions                    = 0x00000060;
    constexpr int32_t m_GoogleExtensions                   = 0x00000068;
    constexpr int32_t SamsungInit                          = 0x00000070;
    constexpr int32_t maxRefreshTime                       = 0x00000074;
    constexpr int32_t refreshTime                          = 0x00000078;
    constexpr int32_t refreshTimerStarted                  = 0x0000007C;
    constexpr int32_t Target                               = 0x00000080;
    constexpr int32_t isUserPurchaseBanned                 = 0x000000A0;
    constexpr int32_t mobileMode                           = 0x00000001;
    constexpr int32_t onIAPInitialized                     = 0x000000A8;
    constexpr int32_t onPurchasedItem                      = 0x000000B0;
    constexpr int32_t onPurchaseItemFailed                 = 0x000000B8;
    constexpr int32_t onFetchedAdditionalIAPs              = 0x000000C0;
}

namespace ShopConfirmationHandler {
    constexpr uint32_t InstanceSize = 0x00000110;

    constexpr int32_t MAX_OFFERS_TO_SHOW                   = 0x00000000;
    constexpr int32_t cardLayouts                          = 0x00000020;
    constexpr int32_t twoLineGridLayout                    = 0x00000028;
    constexpr int32_t twoLineGridRect                      = 0x00000030;
    constexpr int32_t allLayoutOfferCards                  = 0x00000038;
    constexpr int32_t selectedCard                         = 0x00000040;
    constexpr int32_t selectedCardRect                     = 0x00000048;
    constexpr int32_t equipButton                          = 0x00000050;
    constexpr int32_t equipButtonText                      = 0x00000058;
    constexpr int32_t oneItemEquipButton                   = 0x00000060;
    constexpr int32_t oneItemEquipButtonText               = 0x00000068;
    constexpr int32_t buttonSprites                        = 0x00000070;
    constexpr int32_t buttonColors                         = 0x00000078;
    constexpr int32_t headerRect                           = 0x00000080;
    constexpr int32_t headerTexts                          = 0x00000088;
    constexpr int32_t isTestingOfferConfirmation           = 0x00000090;
    constexpr int32_t testOffer                            = 0x00000098;
    constexpr int32_t closeOfferButton                     = 0x000000A0;
    constexpr int32_t eachCardDelay                        = 0x000000A8;
    constexpr int32_t bigCardDelay                         = 0x000000AC;
    constexpr int32_t beforeDuplicateDelay                 = 0x000000B0;
    constexpr int32_t eachDuplicateDelay                   = 0x000000B4;
    constexpr int32_t flightPassDisclaimer                 = 0x000000B8;
    constexpr int32_t audioSource                          = 0x000000C0;
    constexpr int32_t cardClick                            = 0x000000C8;
    constexpr int32_t openOffer                            = 0x000000D0;
    constexpr int32_t gamepadNavHelper                     = 0x000000D8;
    constexpr int32_t offerConfirmationCoroutine           = 0x000000E0;
    constexpr int32_t cachedOfferCard                      = 0x000000E8;
    constexpr int32_t cachedOfferStyle                     = 0x000000F0;
    constexpr int32_t cachedOfferUnlockables               = 0x000000F8;
    constexpr int32_t selectedUnlockable                   = 0x00000100;
    constexpr int32_t onClose                              = 0x00000108;
}

namespace SteamManager {
    constexpr uint32_t InstanceSize = 0x00000030;

    constexpr int32_t s_EverInitialized                    = 0x00000000;
    constexpr int32_t s_instance                           = 0x00000008;
    constexpr int32_t m_bInitialized                       = 0x00000020;
    constexpr int32_t m_SteamAPIWarningMessageHook         = 0x00000028;
}

namespace SandboxPlayerSettingsMenu {
    constexpr uint32_t InstanceSize = 0x00000080;

    constexpr int32_t entity                               = 0x00000020;
    constexpr int32_t settingsMenu                         = 0x00000028;
    constexpr int32_t mainFrame                            = 0x00000030;
    constexpr int32_t titleText                            = 0x00000038;
    constexpr int32_t allButtons                           = 0x00000040;
    constexpr int32_t changeRoleFrame                      = 0x00000048;
    constexpr int32_t changeRoleIcon                       = 0x00000050;
    constexpr int32_t lifeStateIcon                        = 0x00000058;
    constexpr int32_t lifeStateText                        = 0x00000060;
    constexpr int32_t reviveSprite                         = 0x00000068;
    constexpr int32_t killSprite                           = 0x00000070;
    constexpr int32_t gamepadNavHelper                     = 0x00000078;
}

namespace VoiceChatManager {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t isInitialized                        = 0x00000020;
    constexpr int32_t voiceChatHandlers                    = 0x00000028;
    constexpr int32_t defaultType                          = 0x00000030;
    constexpr int32_t enableLogs                           = 0x00000034;
    constexpr int32_t enableDebug                          = 0x00000035;
    constexpr int32_t debugContainer                       = 0x00000038;
    constexpr int32_t enableDebugContainer                 = 0x00000040;
    constexpr int32_t pauseDebugShortcut                   = 0x00000041;
    constexpr int32_t joiningChannels                      = 0x00000042;
    constexpr int32_t joiningChannelInProgress             = 0x00000043;
    constexpr int32_t leavingAllChannelsInProgress         = 0x00000044;
    constexpr int32_t joinedChannel                        = 0x00000045;
    constexpr int32_t retryStarted                         = 0x00000046;
    constexpr int32_t MAX_RETRIES_TIME                     = 0x00000048;
    constexpr int32_t retryTimer                           = 0x0000004C;
    constexpr int32_t currentChatType                      = 0x00000050;
    constexpr int32_t currentChatHandler                   = 0x00000058;
}

namespace MapManager {
    constexpr uint32_t InstanceSize = 0x000002C0;

    constexpr int32_t InGameScene                          = 0x00000000;
    constexpr int32_t ExploreMode                          = 0x00000001;
    constexpr int32_t CurrentMap                           = 0x00000002;
    constexpr int32_t IsPublicGame                         = 0x00000003;
    constexpr int32_t IsMicEnabled                         = 0x00000004;
    constexpr int32_t TutorialIndex                        = 0x00000008;
    constexpr int32_t IsCaution                            = 0x0000000C;
    constexpr int32_t IsSabotaged                          = 0x00000010;
    constexpr int32_t BannedInfo                           = 0x00000018;
    constexpr int32_t ventsList                            = 0x00000020;
    constexpr int32_t globalVolumeLevels                   = 0x00000028;
    constexpr int32_t micBlockedPlayers                    = 0x00000030;
    constexpr int32_t killSwitches                         = 0x00000038;
    constexpr int32_t initialized                          = 0x00000040;
    constexpr int32_t gameStarted                          = 0x00000041;
    constexpr int32_t hasEnvironmentKills                  = 0x00000042;
    constexpr int32_t hasSuffocatedShuttle                 = 0x00000043;
    constexpr int32_t mapTheme                             = 0x00000048;
    constexpr int32_t timeInRoom                           = 0x00000050;
    constexpr int32_t mainCamera                           = 0x00000058;
    constexpr int32_t mainCanvas                           = 0x00000060;
    constexpr int32_t mainCanvasGroup                      = 0x00000068;
    constexpr int32_t loadingPanel                         = 0x00000070;
    constexpr int32_t blockingPanel                        = 0x00000078;
    constexpr int32_t gamePanel                            = 0x00000080;
    constexpr int32_t blackGameObject                      = 0x00000088;
    constexpr int32_t tealOverride                         = 0x00000090;
    constexpr int32_t allOverlayCanvases                   = 0x000000A0;
    constexpr int32_t globallyMicBlockedPlayers            = 0x000000A8;
    constexpr int32_t isMainCanvasDisabled                 = 0x000000B0;
    constexpr int32_t LocalAuthorityLevel                  = 0x000000B1;
    constexpr int32_t isCreator                            = 0x000000B2;
    constexpr int32_t AchievementId                        = 0x000000B4;
    constexpr int32_t WinAchievementId                     = 0x000000B8;
    constexpr int32_t raycastBlockHandler                  = 0x000000C0;
    constexpr int32_t doorsHandler                         = 0x000000C8;
    constexpr int32_t effects                              = 0x000000D0;
    constexpr int32_t settingsPanelHandler                 = 0x000000D8;
    constexpr int32_t helpPanelHandler                     = 0x000000E0;
    constexpr int32_t chatPanelHandler                     = 0x000000E8;
    constexpr int32_t miniMapHandler                       = 0x000000F0;
    constexpr int32_t materialsHandler                     = 0x000000F8;
    constexpr int32_t spectateHandler                      = 0x00000100;
    constexpr int32_t roomSoundRulesList                   = 0x00000108;
    constexpr int32_t deathStingerSplash                   = 0x00000110;
    constexpr int32_t micButtons                           = 0x00000118;
    constexpr int32_t playerSpawner                        = 0x00000120;
    constexpr int32_t mapSoundHandler                      = 0x00000128;
    constexpr int32_t miniMapTrackingDotPrefab             = 0x00000130;
    constexpr int32_t miniMapPanel                         = 0x00000138;
    constexpr int32_t roomTriggers                         = 0x00000140;
    constexpr int32_t roomName                             = 0x00000148;
    constexpr int32_t currentRoomText                      = 0x00000150;
    constexpr int32_t missingRoomText                      = 0x00000158;
    constexpr int32_t roomIdString                         = 0x00000160;
    constexpr int32_t roomLanguage                         = 0x00000168;
    constexpr int32_t roomRegionString                     = 0x00000170;
    constexpr int32_t roomPlayersNumber                    = 0x00000178;
    constexpr int32_t roomMap                              = 0x00000180;
    constexpr int32_t currentRoomRef                       = 0x00000188;
    constexpr int32_t soundRoomRef                         = 0x00000190;
    constexpr int32_t spawnPosition                        = 0x00000198;
    constexpr int32_t startingLocationName                 = 0x000001A0;
    constexpr int32_t startGameSpawnPositions              = 0x000001A8;
    constexpr int32_t startGameRandomSpawnPositions        = 0x000001B0;
    constexpr int32_t LobbySpawnPoints                     = 0x000001B8;
    constexpr int32_t petAndFartParent                     = 0x000001C0;
    constexpr int32_t safeSpaceParents                     = 0x000001C8;
    constexpr int32_t outsideRooms                         = 0x000001D0;
    constexpr int32_t twoFloorRooms                        = 0x000001D8;
    constexpr int32_t lobbyParent                          = 0x000001E0;
    constexpr int32_t lobbyPanel                           = 0x000001E8;
    constexpr int32_t lobbyFrameHostSprite                 = 0x000001F0;
    constexpr int32_t lobbyFrameNonHostSprite              = 0x000001F8;
    constexpr int32_t lobbyFrameMobileSprite               = 0x00000200;
    constexpr int32_t startGameReadyButtonFrameMobile      = 0x00000208;
    constexpr int32_t settingsObject                       = 0x00000210;
    constexpr int32_t newChatMessage                       = 0x00000218;
    constexpr int32_t newChatMessageCard                   = 0x00000220;
    constexpr int32_t hideRoomCode                         = 0x00000228;
    constexpr int32_t canStartGame                         = 0x0000022C;
    constexpr int32_t mapAndmasksHolder                    = 0x00000230;
    constexpr int32_t currentSkin                          = 0x00000238;
    constexpr int32_t inactivityScreen                     = 0x00000240;
    constexpr int32_t inactiveTimeThreshold                = 0x00000248;
    constexpr int32_t privateInactiveTimeThreshold         = 0x0000024C;
    constexpr int32_t inactiveTimeThresholdBumpTime        = 0x00000250;
    constexpr int32_t inactivityTimer                      = 0x00000254;
    constexpr int32_t inactiveLeft                         = 0x00000258;
    constexpr int32_t mouseClicked                         = 0x0000025C;
    constexpr int32_t mouseClickTimer                      = 0x00000268;
    constexpr int32_t KCodeActive                          = 0x00000280;
    constexpr int32_t EnableKCode                          = 0x00000281;
    constexpr int32_t KHistory                             = 0x00000288;
    constexpr int32_t KCode                                = 0x00000290;
    constexpr int32_t tasksAnimator                        = 0x00000298;
    constexpr int32_t currentTaskPanel                     = 0x000002A0;
    constexpr int32_t _isTaskPanelOpen                     = 0x000002A8;
    constexpr int32_t cameraRotatingStart                  = 0x000002AC;
    constexpr int32_t rotDelta                             = 0x000002B0;
    constexpr int32_t trackingSystem                       = 0x000002B8;
}

namespace GameModeUI_Sandbox {
    constexpr uint32_t InstanceSize = 0x000000E8;

    constexpr int32_t frame                                = 0x00000030;
    constexpr int32_t bottomButtonsCanvasGroup             = 0x00000038;
    constexpr int32_t bottomButtonBindShower               = 0x00000040;
    constexpr int32_t toggleGhostVisibilityButton          = 0x00000048;
    constexpr int32_t ghostsCountText                      = 0x00000050;
    constexpr int32_t ghostsVisibleIcon                    = 0x00000058;
    constexpr int32_t ghostsHiddenIcon                     = 0x00000060;
    constexpr int32_t spawnDummyButton                     = 0x00000068;
    constexpr int32_t swapToEntityButton                   = 0x00000070;
    constexpr int32_t dummyCountText                       = 0x00000078;
    constexpr int32_t controlEntityCrosshairPrefab         = 0x00000080;
    constexpr int32_t zoomInButtonIcon                     = 0x00000088;
    constexpr int32_t zoomInButton                         = 0x00000090;
    constexpr int32_t zoomOutButtonIcon                    = 0x00000098;
    constexpr int32_t zoomOutButton                        = 0x000000A0;
    constexpr int32_t gamepadNavHelper                     = 0x000000A8;
    constexpr int32_t gamepadNavigationCollection          = 0x000000B0;
    constexpr int32_t gamepadBlocker                       = 0x000000B8;
    constexpr int32_t gamepadNavEnabled                    = 0x000000C0;
    constexpr int32_t controlEntityCrosshair               = 0x000000C8;
    constexpr int32_t controlEntityCrosshairHintText       = 0x000000D0;
    constexpr int32_t isHoldingZoomIn                      = 0x000000D8;
    constexpr int32_t isHoldingZoomOut                     = 0x000000D9;
    constexpr int32_t isZooming                            = 0x000000DA;
    constexpr int32_t isControllingEntity                  = 0x000000DB;
    constexpr int32_t spawnEntityCooldown                  = 0x000000DC;
    constexpr int32_t swapToEntityCooldown                 = 0x000000E0;
    constexpr int32_t bottomButtonsInteractable            = 0x000000E4;
}

namespace GameModesManager {
    constexpr uint32_t InstanceSize = 0x000000A8;

    constexpr int32_t definedGameMode                      = 0x00000000;
    constexpr int32_t gameModesData                        = 0x00000020;
    constexpr int32_t gameModeAudioSource                  = 0x00000028;
    constexpr int32_t m_classic                            = 0x00000030;
    constexpr int32_t m_gooseHunt                          = 0x00000038;
    constexpr int32_t m_dineAndDash                        = 0x00000040;
    constexpr int32_t m_trickOrTreat                       = 0x00000048;
    constexpr int32_t m_hangingOut                         = 0x00000050;
    constexpr int32_t m_draft                              = 0x00000058;
    constexpr int32_t m_corruption                         = 0x00000060;
    constexpr int32_t m_taskFarming                        = 0x00000068;
    constexpr int32_t m_tastesLikeChicken                  = 0x00000070;
    constexpr int32_t m_fowlPlay                           = 0x00000078;
    constexpr int32_t m_hootAndSeek                        = 0x00000080;
    constexpr int32_t m_sandbox                            = 0x00000088;
    constexpr int32_t m_tutorial                           = 0x00000090;
    constexpr int32_t gameModes                            = 0x00000098;
    constexpr int32_t previousGamemode                     = 0x000000A0;
    constexpr int32_t currentGameMode                      = 0x000000A1;
    constexpr int32_t isInitialized                        = 0x000000A2;
}

namespace ChatToastHandler {
    constexpr uint32_t InstanceSize = 0x000000A8;

    constexpr int32_t playerNameText                       = 0x00000020;
    constexpr int32_t bits                                 = 0x00000028;
    constexpr int32_t clothes                              = 0x00000030;
    constexpr int32_t hat                                  = 0x00000038;
    constexpr int32_t eyes                                 = 0x00000040;
    constexpr int32_t cardBorder                           = 0x00000048;
    constexpr int32_t card                                 = 0x00000050;
    constexpr int32_t defaultCardBorderColor               = 0x00000058;
    constexpr int32_t messageText                          = 0x00000068;
    constexpr int32_t fillTransform                        = 0x00000070;
    constexpr int32_t messageTransform                     = 0x00000078;
    constexpr int32_t canvasGroup                          = 0x00000080;
    constexpr int32_t translatedImage                      = 0x00000088;
    constexpr int32_t failedToTranslateImage               = 0x00000090;
    constexpr int32_t playerInfo                           = 0x00000098;
    constexpr int32_t destroyCoroutine                     = 0x000000A0;
}

namespace BaseUnlockablePrefabHandler {
    constexpr uint32_t InstanceSize = 0x000000D0;

    constexpr int32_t UnlockablePositions                  = 0x00000000;
    constexpr int32_t UnlockableSizes                      = 0x00000008;
    constexpr int32_t UnlockableScales                     = 0x00000010;
    constexpr int32_t UnlockableOffsets                    = 0x00000018;
    constexpr int32_t unlockableInfo                       = 0x00000020;
    constexpr int32_t currentTab                           = 0x00000028;
    constexpr int32_t image                                = 0x00000030;
    constexpr int32_t loadingAnim                          = 0x00000038;
    constexpr int32_t unlockNotification                   = 0x00000040;
    constexpr int32_t selectedToggle                       = 0x00000048;
    constexpr int32_t onSaleBanner                         = 0x00000050;
    constexpr int32_t genericBanner                        = 0x00000058;
    constexpr int32_t genericBannerText                    = 0x00000060;
    constexpr int32_t singularBotBanner                    = 0x00000068;
    constexpr int32_t singularCostText                     = 0x00000070;
    constexpr int32_t dustBotBanner                        = 0x00000078;
    constexpr int32_t dustCostText                         = 0x00000080;
    constexpr int32_t craftBotBanner                       = 0x00000088;
    constexpr int32_t border                               = 0x00000090;
    constexpr int32_t lockObject                           = 0x00000098;
    constexpr int32_t unlockedObject                       = 0x000000A0;
    constexpr int32_t favouriteButton                      = 0x000000A8;
    constexpr int32_t favouriteIcon                        = 0x000000B0;
    constexpr int32_t unlockableUIData                     = 0x000000B8;
    constexpr int32_t ownedObject                          = 0x000000C0;
    constexpr int32_t highlight                            = 0x000000C8;
}

namespace TranslationManager {
    constexpr uint32_t InstanceSize = 0x00000080;

    constexpr int32_t TranslationUrl                       = 0x00000020;
    constexpr int32_t IsBetaTranslation                    = 0x00000028;
    constexpr int32_t Translations                         = 0x00000030;
    constexpr int32_t Searchables                          = 0x00000038;
    constexpr int32_t LanguagesAvailable                   = 0x00000040;
    constexpr int32_t CurrentLanguage                      = 0x00000048;
    constexpr int32_t Settings                             = 0x00000050;
    constexpr int32_t IsSubmodule                          = 0x00000058;
    constexpr int32_t DebugTranslation                     = 0x00000059;
    constexpr int32_t localTranslateDirectory              = 0x00000060;
    constexpr int32_t localSearchableDirectory             = 0x00000068;
    constexpr int32_t remoteTranslateDirectory             = 0x00000070;
    constexpr int32_t remoteSearchableDirectory            = 0x00000078;
}

namespace UnlockablesManager {
    constexpr uint32_t InstanceSize = 0x00000048;

    constexpr int32_t ValidUnlockables                     = 0x00000000;
    constexpr int32_t offerSpriteData                      = 0x00000020;
    constexpr int32_t cardBannerColors                     = 0x00000028;
    constexpr int32_t emptyCosmeticSprite                  = 0x00000030;
    constexpr int32_t emptyEyesSprite                      = 0x00000038;
    constexpr int32_t emptyCardsBannerSprite               = 0x00000040;
    constexpr int32_t Unlockables                          = 0x00000008;
}

namespace PlayerRolesManager {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t RoleMap                              = 0x00000000;
    constexpr int32_t abortStartGame                       = 0x00000008;
    constexpr int32_t abortStartGameMessage                = 0x00000010;
}

namespace SpecialEventManager {
    constexpr uint32_t InstanceSize = 0x00000048;

    constexpr int32_t MachineList                          = 0x00000020;
    constexpr int32_t MachineAssets                        = 0x00000028;
    constexpr int32_t maxDownloadAttempts                  = 0x00000030;
    constexpr int32_t firstPlayGacha                       = 0x00000034;
    constexpr int32_t isTesting                            = 0x00000035;
    constexpr int32_t skipCount                            = 0x00000038;
    constexpr int32_t emptyClawList                        = 0x0000003C;
    constexpr int32_t skins                                = 0x00000040;
    constexpr int32_t MACHINE_SEASONAL_KEY                 = 0x00000008;
    constexpr int32_t MACHINE_TUTORIAL_KEY                 = 0x00000010;
}

namespace MainManager {
    constexpr uint32_t InstanceSize = 0x000002E8;

    constexpr int32_t GameId                               = 0x00000000;
    constexpr int32_t RoomIdLink                           = 0x00000000;
    constexpr int32_t cachedGameId                         = 0x00000020;
    constexpr int32_t Version                              = 0x00000028;
    constexpr int32_t QuickPlayData                        = 0x00000030;
    constexpr int32_t isPhotonOnline                       = 0x00000038;
    constexpr int32_t isFirebaseOnline                     = 0x00000039;
    constexpr int32_t RetryTime                            = 0x0000003C;
    constexpr int32_t ButtonWasOn                          = 0x00000040;
    constexpr int32_t Disabled                             = 0x00000041;
    constexpr int32_t devPlugin                            = 0x00000048;
    constexpr int32_t debugSettings                        = 0x00000050;
    constexpr int32_t Graphy                               = 0x00000058;
    constexpr int32_t SROptionsHookup                      = 0x00000060;
    constexpr int32_t useQuickSwapAccountFeature           = 0x00000068;
    constexpr int32_t showSuperSpeaker                     = 0x00000069;
    constexpr int32_t useSuperSpeaker                      = 0x0000006A;
    constexpr int32_t OnSuperSpeakerChange                 = 0x00000070;
    constexpr int32_t showSuperListener                    = 0x00000078;
    constexpr int32_t useSuperListener                     = 0x00000079;
    constexpr int32_t OnSuperListenerChange                = 0x00000080;
    constexpr int32_t showRoleReveal                       = 0x00000088;
    constexpr int32_t enableVoiceInPublicGames             = 0x00000089;
    constexpr int32_t disableVoice                         = 0x0000008A;
    constexpr int32_t useRandomNickname                    = 0x0000008B;
    constexpr int32_t randomizeUserIds                     = 0x0000008C;
    constexpr int32_t disableSpriteHashCheck               = 0x0000008D;
    constexpr int32_t spriteDownloadMaxAttempts            = 0x00000090;
    constexpr int32_t disableFullscreen                    = 0x00000094;
    constexpr int32_t displayLagSimulationUI               = 0x00000095;
    constexpr int32_t disableVolumeProximity               = 0x00000096;
    constexpr int32_t noCooldownsOnClient                  = 0x00000097;
    constexpr int32_t baseMovementSpeed                    = 0x00000098;
    constexpr int32_t masterTransferTrigger                = 0x0000009C;
    constexpr int32_t masterTransferCooldown               = 0x000000A0;
    constexpr int32_t globalVolumesStorageLimit            = 0x000000A4;
    constexpr int32_t globalMicBlockThreshold              = 0x000000A8;
    constexpr int32_t maxChatMessages                      = 0x000000AC;
    constexpr int32_t roomCountLimit                       = 0x000000B0;
    constexpr int32_t Languages                            = 0x000000B8;
    constexpr int32_t AdditionalFilterLanguages            = 0x000000C0;
    constexpr int32_t photonSignatureString                = 0x000000C8;
    constexpr int32_t bestRegion                           = 0x000000D0;
    constexpr int32_t regionsSortedByPing                  = 0x000000D8;
    constexpr int32_t regionsPing                          = 0x000000E0;
    constexpr int32_t photonRegionsLookup                  = 0x000000E8;
    constexpr int32_t PhotonRegionCodeToReadable           = 0x000000F0;
    constexpr int32_t balanceManager                       = 0x000000F8;
    constexpr int32_t micInputManager                      = 0x00000100;
    constexpr int32_t friendManager                        = 0x00000108;
    constexpr int32_t uiSoundHandler                       = 0x00000110;
    constexpr int32_t qpHandler                            = 0x00000118;
    constexpr int32_t clippyHandler                        = 0x00000120;
    constexpr int32_t chatManager                          = 0x00000128;
    constexpr int32_t unlockablesManager                   = 0x00000130;
    constexpr int32_t roomManager                          = 0x00000138;
    constexpr int32_t userInfoManager                      = 0x00000140;
    constexpr int32_t gameManager                          = 0x00000148;
    constexpr int32_t playerEventsManager                  = 0x00000150;
    constexpr int32_t pluginEvents                         = 0x00000158;
    constexpr int32_t playerPropertiesManager              = 0x00000160;
    constexpr int32_t playerRolesManager                   = 0x00000168;
    constexpr int32_t spawnedPlayersManager                = 0x00000170;
    constexpr int32_t votesManager                         = 0x00000178;
    constexpr int32_t timerManager                         = 0x00000180;
    constexpr int32_t globalTimerManager                   = 0x00000188;
    constexpr int32_t geeseLostManager                     = 0x00000190;
    constexpr int32_t reportPlayerManager                  = 0x00000198;
    constexpr int32_t ackManager                           = 0x000001A0;
    constexpr int32_t playerPrefsSetManager                = 0x000001A8;
    constexpr int32_t autoKickManager                      = 0x000001B0;
    constexpr int32_t photonMasterManager                  = 0x000001B8;
    constexpr int32_t dataGenerator                        = 0x000001C0;
    constexpr int32_t giftsManager                         = 0x000001C8;
    constexpr int32_t adManager                            = 0x000001D0;
    constexpr int32_t overwolfManager                      = 0x000001D8;
    constexpr int32_t petIdList                            = 0x000001E0;
    constexpr int32_t stingerLookUp                        = 0x000001E8;
    constexpr int32_t mapNameLookup                        = 0x000001F0;
    constexpr int32_t gamemodeNameLookup                   = 0x000001F8;
    constexpr int32_t levelsInBuild                        = 0x00000200;
    constexpr int32_t hasLoadedUnlockables                 = 0x00000208;
    constexpr int32_t placeHolderNormalColor               = 0x0000020C;
    constexpr int32_t placeHolderSpecialNicknameNormalColor = 0x0000021C;
    constexpr int32_t placeHolderErrorColor                = 0x0000022C;
    constexpr int32_t winCount                             = 0x0000023C;
    constexpr int32_t gameCount                            = 0x00000240;
    constexpr int32_t lastGameWasWin                       = 0x00000244;
    constexpr int32_t yellowDot                            = 0x00000248;
    constexpr int32_t redDot                               = 0x00000250;
    constexpr int32_t yellowCircle                         = 0x00000258;
    constexpr int32_t roleIconData                         = 0x00000260;
    constexpr int32_t refreshButtonCoroutine               = 0x00000268;
    constexpr int32_t isFocused                            = 0x00000270;
    constexpr int32_t pressedRefreshButton                 = 0x00000271;
    constexpr int32_t tempHat                              = 0x00000278;
    constexpr int32_t tempClothes                          = 0x00000280;
    constexpr int32_t tempEyes                             = 0x00000288;
    constexpr int32_t tempFart                             = 0x00000290;
    constexpr int32_t tempPet                              = 0x00000298;
    constexpr int32_t tempStinger                          = 0x000002A0;
    constexpr int32_t tempBanner                           = 0x000002A8;
    constexpr int32_t tempCard                             = 0x000002B0;
    constexpr int32_t supportLogger                        = 0x000002B8;
    constexpr int32_t chDe                                 = 0x000002C0;
    constexpr int32_t Scene                                = 0x000002D0;
    constexpr int32_t OnLoadingComplete                    = 0x000002D8;
    constexpr int32_t LoadingSprite                        = 0x000002E0;
}

namespace GodzillaManager {
    constexpr uint32_t InstanceSize = 0x00000508;

    constexpr int32_t RUBBLE_TASK_ID                       = 0x00000000;
    constexpr int32_t DESTROYED_BUILDING_FOOTSTEP_RANGE    = 0x00000410;
    constexpr int32_t connectedRooms                       = 0x00000418;
    constexpr int32_t fireRoomNames                        = 0x00000420;
    constexpr int32_t eventsModule                         = 0x00000428;
    constexpr int32_t corpseSplatterPrefab                 = 0x00000430;
    constexpr int32_t roofHandler                          = 0x00000438;
    constexpr int32_t simpleRoofHandler                    = 0x00000440;
    constexpr int32_t godzillaMapFeature                   = 0x00000448;
    constexpr int32_t litterPrefabs                        = 0x00000450;
    constexpr int32_t litterSpawns                         = 0x00000458;
    constexpr int32_t buildingDestructionAnimator          = 0x00000460;
    constexpr int32_t explosionAudioSource                 = 0x00000468;
    constexpr int32_t explosionAudioClips                  = 0x00000470;
    constexpr int32_t targetBuildings                      = 0x00000478;
    constexpr int32_t rubblePrefabs                        = 0x00000480;
    constexpr int32_t rubbleInteractableIcons              = 0x00000488;
    constexpr int32_t rubbleInteractableOffsets            = 0x00000490;
    constexpr int32_t carHeadLightAnimators                = 0x00000498;
    constexpr int32_t godzillaWarningActive                = 0x000004A0;
    constexpr int32_t godzillaWarningTime                  = 0x000004A4;
    constexpr int32_t areCarHeadLightsOn                   = 0x000004A8;
    constexpr int32_t carHeadLightTimer                    = 0x000004AC;
    constexpr int32_t warningIO                            = 0x000004B0;
    constexpr int32_t warningTaskPanelIO                   = 0x000004B8;
    constexpr int32_t warningInteractable                  = 0x000004C0;
    constexpr int32_t telescopeIO                          = 0x000004C8;
    constexpr int32_t telescopeInteractable                = 0x000004D0;
    constexpr int32_t hawkAtomicBreathEffectPrefab         = 0x000004D8;
    constexpr int32_t atomicBreathSound                    = 0x000004E0;
    constexpr int32_t atomicBreathPlayer                   = 0x000004E8;
    constexpr int32_t atomicBreathEffect                   = 0x000004F0;
    constexpr int32_t atomicBreathRotation                 = 0x000004F8;
    constexpr int32_t isAtomicFacingRight                  = 0x000004FC;
    constexpr int32_t atomicBreathTargetScale              = 0x00000500;
    constexpr int32_t updateAtomicBreath                   = 0x00000504;
}

namespace FishingTaskV2_IO {
    constexpr uint32_t InstanceSize = 0x00000160;

    constexpr int32_t powerBarTargetZone                   = 0x00000050;
    constexpr int32_t powerBarInZone                       = 0x00000058;
    constexpr int32_t powerBarOutZone                      = 0x00000068;
    constexpr int32_t powerBarSlider                       = 0x00000078;
    constexpr int32_t powerBar                             = 0x00000080;
    constexpr int32_t animator                             = 0x00000088;
    constexpr int32_t hook                                 = 0x00000090;
    constexpr int32_t waterSplash                          = 0x00000098;
    constexpr int32_t lineImage                            = 0x000000A0;
    constexpr int32_t fishImage                            = 0x000000A8;
    constexpr int32_t rodImage                             = 0x000000B0;
    constexpr int32_t pulledRod                            = 0x000000B8;
    constexpr int32_t secondaryRodLine                     = 0x000000C0;
    constexpr int32_t goose                                = 0x000000C8;
    constexpr int32_t gooseEyes                            = 0x000000D0;
    constexpr int32_t gooseHat                             = 0x000000D8;
    constexpr int32_t fishSprites                          = 0x000000E0;
    constexpr int32_t itemPivots                           = 0x000000E8;
    constexpr int32_t useCustomPivots                      = 0x000000F0;
    constexpr int32_t reelLoop                             = 0x000000F8;
    constexpr int32_t splash                               = 0x00000100;
    constexpr int32_t reelRod                              = 0x00000108;
    constexpr int32_t pullItemFromWater                    = 0x00000110;
    constexpr int32_t powerBarTargetStartHeight            = 0x00000118;
    constexpr int32_t powerBarTargetTargetHeight           = 0x0000011C;
    constexpr int32_t powerBarTargetLerp                   = 0x00000120;
    constexpr int32_t powerBarTargetHalfHeight             = 0x00000124;
    constexpr int32_t reelInTarget                         = 0x00000128;
    constexpr int32_t reelInSpeed                          = 0x0000012C;
    constexpr int32_t reelInCompleteCounter                = 0x00000130;
    constexpr int32_t reelInFailCounter                    = 0x00000132;
    constexpr int32_t isReelingIn                          = 0x00000134;
    constexpr int32_t startBobTime                         = 0x00000138;
    constexpr int32_t lineTargetY                          = 0x0000013C;
    constexpr int32_t targetX                              = 0x00000140;
    constexpr int32_t pullingItemUp                        = 0x00000144;
    constexpr int32_t hookPos                              = 0x00000148;
    constexpr int32_t linePos                              = 0x00000150;
    constexpr int32_t useButtonAction                      = 0x00000158;
}

namespace RoomUpdater {
    constexpr uint32_t InstanceSize = 0x00000038;

    constexpr int32_t blockRoomUpdate                      = 0x00000000;
    constexpr int32_t blockRoomSoundUpdate                 = 0x00000001;
    constexpr int32_t prevRoom                             = 0x00000020;
    constexpr int32_t prevRoomRulesObj                     = 0x00000028;
    constexpr int32_t onLocalRoomChange                    = 0x00000030;
}

namespace LoungeAudioMixerHandler {
    constexpr uint32_t InstanceSize = 0x00000088;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t audioLowPassFilter                   = 0x00000020;
    constexpr int32_t isLerping                            = 0x00000028;
    constexpr int32_t lerpTime                             = 0x0000002C;
    constexpr int32_t baseVipRoom                          = 0x00000030;
    constexpr int32_t doorCloseReduction                   = 0x00000034;
    constexpr int32_t roomList                             = 0x00000038;
    constexpr int32_t floatlist                            = 0x00000040;
    constexpr int32_t sfxAudioSource                       = 0x00000048;
    constexpr int32_t targetFreq                           = 0x00000050;
    constexpr int32_t currentFreq                          = 0x00000054;
    constexpr int32_t isDoorClosed                         = 0x00000058;
    constexpr int32_t startLerpTime                        = 0x0000005C;
    constexpr int32_t audioSource                          = 0x00000060;
    constexpr int32_t isAudioSynced                        = 0x00000068;
    constexpr int32_t currentTrack                         = 0x0000006C;
    constexpr int32_t startUpDelayTime                     = 0x00000070;
    constexpr int32_t tracklist                            = 0x00000078;
}

namespace PointerBlockerHandler {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t isMouseOnUI                          = 0x00000000;
}

namespace NewSettingsPanelHandler {
    constexpr uint32_t InstanceSize = 0x00000240;

    constexpr int32_t gameModesData                        = 0x00000020;
    constexpr int32_t oldGmeSettings                       = 0x00000028;
    constexpr int32_t gameSettings                         = 0x00000030;
    constexpr int32_t recommendedSettings                  = 0x00000038;
    constexpr int32_t isLoaded                             = 0x00000039;
    constexpr int32_t mapSettings                          = 0x00000040;
    constexpr int32_t allSettingsObjectHandlers            = 0x00000048;
    constexpr int32_t allCategoryHandlers                  = 0x00000050;
    constexpr int32_t panelAnimator                        = 0x00000058;
    constexpr int32_t titleText                            = 0x00000060;
    constexpr int32_t descriptionText                      = 0x00000068;
    constexpr int32_t notHostBlocker                       = 0x00000070;
    constexpr int32_t enableClickySound                    = 0x00000078;
    constexpr int32_t roleDesc                             = 0x00000080;
    constexpr int32_t rolesCategory                        = 0x00000088;
    constexpr int32_t specialRoleSprites                   = 0x00000090;
    constexpr int32_t starSprites                          = 0x00000098;
    constexpr int32_t rolesContent                         = 0x000000A0;
    constexpr int32_t rolesContentParent                   = 0x000000A8;
    constexpr int32_t rolesScroll                          = 0x000000B0;
    constexpr int32_t rolesGroup                           = 0x000000B8;
    constexpr int32_t roleSettingPrefab                    = 0x000000C0;
    constexpr int32_t allRoles                             = 0x000000C8;
    constexpr int32_t bannedDraftRolesHandler              = 0x000000D0;
    constexpr int32_t bannedRolesParent                    = 0x000000D8;
    constexpr int32_t bannedRolesScroll                    = 0x000000E0;
    constexpr int32_t topFilterBar                         = 0x000000E8;
    constexpr int32_t roleSortingHandler                   = 0x000000F0;
    constexpr int32_t roleSearchInput                      = 0x000000F8;
    constexpr int32_t roleSearchInputHighlight             = 0x00000100;
    constexpr int32_t clearSearchIcon                      = 0x00000108;
    constexpr int32_t roleSort                             = 0x00000110;
    constexpr int32_t manageTeamsContentPanel              = 0x00000118;
    constexpr int32_t manageTeamsParent                    = 0x00000120;
    constexpr int32_t manageTeamsScroll                    = 0x00000128;
    constexpr int32_t PresetsPanelHandler                  = 0x00000130;
    constexpr int32_t numberOfDucksSlider                  = 0x00000138;
    constexpr int32_t numberOfNeutralsSlider               = 0x00000140;
    constexpr int32_t proximityChatToggle                  = 0x00000148;
    constexpr int32_t proximityChatTranslation             = 0x00000150;
    constexpr int32_t roleRevealSetting                    = 0x00000158;
    constexpr int32_t roleRevealToggle                     = 0x00000160;
    constexpr int32_t roleRevealTranslation                = 0x00000168;
    constexpr int32_t disableSpectatorsSetting             = 0x00000170;
    constexpr int32_t disableSpectatorsToggle              = 0x00000178;
    constexpr int32_t disableSpectatorsTranslation         = 0x00000180;
    constexpr int32_t autoKickSetting                      = 0x00000188;
    constexpr int32_t autoKickToggle                       = 0x00000190;
    constexpr int32_t autoKickTranslation                  = 0x00000198;
    constexpr int32_t maxPlayerSetting                     = 0x000001A0;
    constexpr int32_t openingStatementsToggle              = 0x000001A8;
    constexpr int32_t openingStatementsTranslation         = 0x000001B0;
    constexpr int32_t draftTimerSetting                    = 0x000001B8;
    constexpr int32_t draftTimerSettingDescription         = 0x000001C0;
    constexpr int32_t gamepadNavHelper                     = 0x000001C8;
    constexpr int32_t extraObjects                         = 0x000001D0;
    constexpr int32_t controllerUIs                        = 0x000001D8;
    constexpr int32_t currentTab                           = 0x000001E0;
    constexpr int32_t transparentColor                     = 0x000001E4;
    constexpr int32_t allGameModeHandlers                  = 0x000001E8;
    constexpr int32_t currentGameModeHandler               = 0x000001F0;
    constexpr int32_t currentGameMapHandler                = 0x000001F8;
    constexpr int32_t currentCategoryHandler               = 0x00000200;
    constexpr int32_t onGamemodeChanged                    = 0x00000208;
    constexpr int32_t currentGameModeChanged               = 0x00000210;
    constexpr int32_t ViewDistanceArray                    = 0x00000218;
}

namespace CinemachineStateDrivenCamera {
    constexpr uint32_t InstanceSize = 0x00000258;

    constexpr int32_t m_LookAt                             = 0x000000A8;
    constexpr int32_t m_Follow                             = 0x000000B0;
    constexpr int32_t m_AnimatedTarget                     = 0x000000B8;
    constexpr int32_t m_LayerIndex                         = 0x000000C0;
    constexpr int32_t m_ShowDebugText                      = 0x000000C4;
    constexpr int32_t m_ChildCameras                       = 0x000000C8;
    constexpr int32_t m_Instructions                       = 0x000000D0;
    constexpr int32_t m_DefaultBlend                       = 0x000000D8;
    constexpr int32_t m_CustomBlends                       = 0x000000E8;
    constexpr int32_t m_ParentHash                         = 0x000000F0;
    constexpr int32_t LiveChildk__BackingField             = 0x000000F8;
    constexpr int32_t m_TransitioningFrom                  = 0x00000100;
    constexpr int32_t m_State                              = 0x00000108;
    constexpr int32_t mHashCache                           = 0x000001F0;
    constexpr int32_t mActivationTime                      = 0x000001F8;
    constexpr int32_t mActiveInstruction                   = 0x00000200;
    constexpr int32_t mPendingActivationTime               = 0x00000218;
    constexpr int32_t mPendingInstruction                  = 0x00000220;
    constexpr int32_t mActiveBlend                         = 0x00000238;
    constexpr int32_t mInstructionDictionary               = 0x00000240;
    constexpr int32_t mStateParentLookup                   = 0x00000248;
    constexpr int32_t m_clipInfoList                       = 0x00000250;
}

namespace IntercomPanelHandler {
    constexpr uint32_t InstanceSize = 0x00000038;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t taskPanel                            = 0x00000020;
    constexpr int32_t interactable                         = 0x00000028;
    constexpr int32_t broadcastInteractable                = 0x00000030;
}

namespace SabotagePanelHandler {
    constexpr uint32_t InstanceSize = 0x000000A0;

    constexpr int32_t buttons                              = 0x00000020;
    constexpr int32_t data                                 = 0x00000028;
    constexpr int32_t tasksHandler                         = 0x00000030;
    constexpr int32_t uiAnimator                           = 0x00000038;
    constexpr int32_t panelImage                           = 0x00000040;
    constexpr int32_t additionalPanelImage                 = 0x00000048;
    constexpr int32_t tutorialArrow                        = 0x00000050;
    constexpr int32_t gamepadTaskHelper                    = 0x00000058;
    constexpr int32_t navSetupCor                          = 0x00000060;
    constexpr int32_t availableButtons                     = 0x00000068;
    constexpr int32_t enabledSabotages                     = 0x00000070;
    constexpr int32_t lastTimeSinceOpened                  = 0x00000078;
    constexpr int32_t lastUsedButton                       = 0x00000080;
    constexpr int32_t onInitialised                        = 0x00000008;
    constexpr int32_t onPanelOpened                        = 0x00000088;
    constexpr int32_t onPanelClosed                        = 0x00000090;
    constexpr int32_t canClosePanel                        = 0x00000098;
}

namespace SabotageButtonHandler {
    constexpr uint32_t InstanceSize = 0x00000080;

    constexpr int32_t rect                                 = 0x00000020;
    constexpr int32_t sabotageButton                       = 0x00000028;
    constexpr int32_t sabotageButtonImage                  = 0x00000030;
    constexpr int32_t sabotageFrameHighlight               = 0x00000038;
    constexpr int32_t sabotageFrame                        = 0x00000040;
    constexpr int32_t sabotageText                         = 0x00000048;
    constexpr int32_t sabotageCooldownText                 = 0x00000050;
    constexpr int32_t extraIcons                           = 0x00000058;
    constexpr int32_t buttonType                           = 0x00000060;
    constexpr int32_t buttonData                           = 0x00000068;
    constexpr int32_t locked                               = 0x00000070;
    constexpr int32_t saboEnabled                          = 0x00000071;
    constexpr int32_t taskIsActive                         = 0x00000072;
    constexpr int32_t nextPossibleSabotageTime             = 0x00000074;
    constexpr int32_t isInitialized                        = 0x00000078;
    constexpr int32_t activeInGame                         = 0x00000079;
}

namespace TelepathyAndClairvoyanceHandler {
    constexpr uint32_t InstanceSize = 0x00000028;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t timer                                = 0x00000020;
    constexpr int32_t clairvoyance                         = 0x00000024;
    constexpr int32_t telepathy                            = 0x00000025;
}

namespace DoorsHandler {
    constexpr uint32_t InstanceSize = 0x00000068;

    constexpr int32_t IsDoorSabotageBlockedk__BackingField = 0x00000000;
    constexpr int32_t doorAnimators                        = 0x00000020;
    constexpr int32_t doorsLocked                          = 0x00000028;
    constexpr int32_t doorsLockedSpecial                   = 0x00000030;
    constexpr int32_t doorTasks                            = 0x00000038;
    constexpr int32_t aiDoorColliders                      = 0x00000040;
    constexpr int32_t doorGroups                           = 0x00000048;
    constexpr int32_t doorsClosingTime                     = 0x00000050;
    constexpr int32_t currentDoorsClosingTime              = 0x00000054;
    constexpr int32_t doorsClosed                          = 0x00000058;
    constexpr int32_t DoorClosed                           = 0x00000004;
    constexpr int32_t doorsLockedRound                     = 0x00000060;
}

namespace HUDTextHandler {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t HUDTextMesh                          = 0x00000020;
    constexpr int32_t spawnedObjectsParent                 = 0x00000028;
    constexpr int32_t ravenTargetIcon                      = 0x00000030;
    constexpr int32_t hudTexts                             = 0x00000038;
    constexpr int32_t highestPriorityText                  = 0x00000040;
    constexpr int32_t targetColor                          = 0x00000050;
}

namespace GodzillaMiniMapHandler {
    constexpr uint32_t InstanceSize = 0x000001B0;

    constexpr int32_t destroyedBuildings                   = 0x00000190;
    constexpr int32_t destroyedBuildingSprites             = 0x00000198;
    constexpr int32_t explosionImage                       = 0x000001A0;
    constexpr int32_t explosionSprites                     = 0x000001A8;
}

namespace CamerasPanelHandler {
    constexpr uint32_t InstanceSize = 0x00000048;

    constexpr int32_t camerasPanel                         = 0x00000020;
    constexpr int32_t enabledAnimator                      = 0x00000028;
    constexpr int32_t usageAnimator                        = 0x00000030;
    constexpr int32_t interactable                         = 0x00000038;
    constexpr int32_t BeingUsed                            = 0x00000004;
    constexpr int32_t isLooking                            = 0x00000040;
}

namespace AvengerHandler {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t _rend                                = 0x00000020;
    constexpr int32_t _source                              = 0x00000028;
    constexpr int32_t _clip                                = 0x00000030;
    constexpr int32_t isFadingIn                           = 0x00000038;
    constexpr int32_t isFadingOut                          = 0x00000039;
    constexpr int32_t time                                 = 0x0000003C;
    constexpr int32_t transparent                          = 0x00000040;
    constexpr int32_t red                                  = 0x00000050;
}

namespace VentHandler {
    constexpr uint32_t InstanceSize = 0x00000068;

    constexpr int32_t ventIdCounter                        = 0x00000000;
    constexpr int32_t ventId                               = 0x00000020;
    constexpr int32_t connectedVents                       = 0x00000028;
    constexpr int32_t ventArrows                           = 0x00000030;
    constexpr int32_t animator                             = 0x00000038;
    constexpr int32_t OpenVent                             = 0x00000004;
    constexpr int32_t ventLocation                         = 0x00000040;
    constexpr int32_t forceRoomUpdateOnExit                = 0x00000048;
    constexpr int32_t ventOffsetX                          = 0x0000004C;
    constexpr int32_t ventOffsetY                          = 0x00000050;
    constexpr int32_t selectedVent                         = 0x00000058;
    constexpr int32_t rotateAction                         = 0x00000060;
}

namespace VotingPanelHandler {
    constexpr uint32_t InstanceSize = 0x000001E8;

    constexpr int32_t Instance                             = 0x00000000;
    constexpr int32_t BLANK_VOTER_ID                       = 0x00000000;
    constexpr int32_t VOTING_VIEW_KEY                      = 0x00000000;
    constexpr int32_t debugMode                            = 0x00000020;
    constexpr int32_t show16Players                        = 0x00000021;
    constexpr int32_t votePrefab                           = 0x00000028;
    constexpr int32_t votedPrefab                          = 0x00000030;
    constexpr int32_t emptyVotePrefab                      = 0x00000038;
    constexpr int32_t backgroundImage                      = 0x00000040;
    constexpr int32_t meetingCanvas                        = 0x00000048;
    constexpr int32_t blockingPanel                        = 0x00000050;
    constexpr int32_t sandboxVotingHandler                 = 0x00000058;
    constexpr int32_t votesContainer                       = 0x00000060;
    constexpr int32_t votesGridLayoutGroup                 = 0x00000068;
    constexpr int32_t timeLeft                             = 0x00000070;
    constexpr int32_t finalCountdown                       = 0x00000078;
    constexpr int32_t timerSlider                          = 0x00000080;
    constexpr int32_t timerSliderFill                      = 0x00000088;
    constexpr int32_t openingStatementsDivider             = 0x00000090;
    constexpr int32_t discussionTimeDivider                = 0x00000098;
    constexpr int32_t skipVotePanel                        = 0x000000A0;
    constexpr int32_t skipVote                             = 0x000000A8;
    constexpr int32_t skipVoteButton                       = 0x000000B0;
    constexpr int32_t chatButton                           = 0x000000B8;
    constexpr int32_t chatButtonFill                       = 0x000000C0;
    constexpr int32_t helpButton                           = 0x000000C8;
    constexpr int32_t assassinButton                       = 0x000000D0;
    constexpr int32_t mapButtonShowing                     = 0x000000D8;
    constexpr int32_t mapButton                            = 0x000000E0;
    constexpr int32_t dreamButton                          = 0x000000E8;
    constexpr int32_t votingCheckmarkDisplay               = 0x000000F0;
    constexpr int32_t skipButtonColors                     = 0x00000120;
    constexpr int32_t keybindsToDisable                    = 0x00000128;
    constexpr int32_t assassinPanelHandler                 = 0x00000130;
    constexpr int32_t meetingChatPanelHandler              = 0x00000138;
    constexpr int32_t meetingChatPanelRect                 = 0x00000140;
    constexpr int32_t showingChatPanel                     = 0x00000148;
    constexpr int32_t gamepadNavHelper                     = 0x00000150;
    constexpr int32_t helpHighlight                        = 0x00000158;
    constexpr int32_t chatSendButton                       = 0x00000160;
    constexpr int32_t chatSendHighlight                    = 0x00000168;
    constexpr int32_t chatInputField                       = 0x00000170;
    constexpr int32_t assassinHighlight                    = 0x00000178;
    constexpr int32_t dreamHighlight                       = 0x00000180;
    constexpr int32_t votesObjects                         = 0x00000188;
    constexpr int32_t emptyVotes                           = 0x00000190;
    constexpr int32_t isVotingPanelOpen                    = 0x00000198;
    constexpr int32_t reportedBodyId                       = 0x000001A0;
    constexpr int32_t currentReporter                      = 0x000001A8;
    constexpr int32_t votePanelColor                       = 0x000001B0;
    constexpr int32_t emptyVotePanelColor                  = 0x000001C0;
    constexpr int32_t votePanelRed                         = 0x00000008;
    constexpr int32_t emptyPanelRed                        = 0x00000018;
    constexpr int32_t sliderGreen                          = 0x00000028;
    constexpr int32_t sliderYellow                         = 0x00000038;
    constexpr int32_t sliderRed                            = 0x00000048;
    constexpr int32_t baseContainerColor                   = 0x000001D0;
    constexpr int32_t onOpenPanel                          = 0x000001E0;
}

namespace PlayerButtonController {
    constexpr uint32_t InstanceSize = 0x00000410;

    constexpr int32_t USE_BUTTON_NAME                      = 0x00000000;
    constexpr int32_t MINIMAP_BUTTON_NAME                  = 0x00000000;
    constexpr int32_t playerNamesParent                    = 0x00000020;
    constexpr int32_t _minimapAnchor                       = 0x00000028;
    constexpr int32_t _primaryRoleActionAnchor             = 0x00000030;
    constexpr int32_t _secondaryRoleActionAnchor           = 0x00000038;
    constexpr int32_t _tertiaryRoleActionAnchor            = 0x00000040;
    constexpr int32_t _useAnchor                           = 0x00000048;
    constexpr int32_t _reportAnchor                        = 0x00000050;
    constexpr int32_t _joystickAnchor                      = 0x00000058;
    constexpr int32_t _fartAnchor                          = 0x00000060;
    constexpr int32_t _gameModeOverlayParent               = 0x00000068;
    constexpr int32_t _primaryRoleActionMobileAnchor       = 0x00000070;
    constexpr int32_t _secondaryRoleActionMobileAnchor     = 0x00000078;
    constexpr int32_t _tertiaryRoleActionMobileAnchor      = 0x00000080;
    constexpr int32_t _useMobileAnchor                     = 0x00000088;
    constexpr int32_t _reportMobileAnchor                  = 0x00000090;
    constexpr int32_t _joystickMobileAnchor                = 0x00000098;
    constexpr int32_t _fartMobileAnchor                    = 0x000000A0;
    constexpr int32_t _minimapMobileAnchor                 = 0x000000A8;
    constexpr int32_t counterCanvas                        = 0x000000B0;
    constexpr int32_t counterText                          = 0x000000B8;
    constexpr int32_t counterEffect_bounceValueStart       = 0x000000C0;
    constexpr int32_t counterEffect_bounceDuration         = 0x000000C4;
    constexpr int32_t counterEffect_bounceScale            = 0x000000C8;
    constexpr int32_t counterEffect_bounceCurve            = 0x000000D0;
    constexpr int32_t enterVentSprite                      = 0x000000D8;
    constexpr int32_t exitVentSprite                       = 0x000000E0;
    constexpr int32_t killSprite                           = 0x000000E8;
    constexpr int32_t sabotageSprite                       = 0x000000F0;
    constexpr int32_t useSprite                            = 0x000000F8;
    constexpr int32_t reportSprite                         = 0x00000100;
    constexpr int32_t sampleSprite                         = 0x00000108;
    constexpr int32_t morphSprite                          = 0x00000110;
    constexpr int32_t eatSprite                            = 0x00000118;
    constexpr int32_t silenceSprite                        = 0x00000120;
    constexpr int32_t mediateSprite                        = 0x00000128;
    constexpr int32_t mediatingSprite                      = 0x00000130;
    constexpr int32_t investigateSprite                    = 0x00000138;
    constexpr int32_t infectSprite                         = 0x00000140;
    constexpr int32_t zoomSprite                           = 0x00000148;
    constexpr int32_t zoomOutSprite                        = 0x00000150;
    constexpr int32_t scanSprite                           = 0x00000158;
    constexpr int32_t notesSprite                          = 0x00000160;
    constexpr int32_t vampireSprite                        = 0x00000168;
    constexpr int32_t pitchforkSprite                      = 0x00000170;
    constexpr int32_t forensicsSprite                      = 0x00000178;
    constexpr int32_t spectateInSprite                     = 0x00000180;
    constexpr int32_t spectateOutSprite                    = 0x00000188;
    constexpr int32_t spectateNextSprite                   = 0x00000190;
    constexpr int32_t openDoorSprite                       = 0x00000198;
    constexpr int32_t closeDoorSprite                      = 0x000001A0;
    constexpr int32_t knockSprite                          = 0x000001A8;
    constexpr int32_t heliumSprite                         = 0x000001B0;
    constexpr int32_t bombSprite                           = 0x000001B8;
    constexpr int32_t fogInSprite                          = 0x000001C0;
    constexpr int32_t fogOutSprite                         = 0x000001C8;
    constexpr int32_t ninjaSprite                          = 0x000001D0;
    constexpr int32_t dragSprite                           = 0x000001D8;
    constexpr int32_t dropSprite                           = 0x000001E0;
    constexpr int32_t invisibilitySprite                   = 0x000001E8;
    constexpr int32_t astralSprite                         = 0x000001F0;
    constexpr int32_t pelicanSprite                        = 0x000001F8;
    constexpr int32_t mummyTransformSprite                 = 0x00000200;
    constexpr int32_t mummyTransformBackSprite             = 0x00000208;
    constexpr int32_t thrallGrabSprite                     = 0x00000210;
    constexpr int32_t thrallLetGoSprite                    = 0x00000218;
    constexpr int32_t esperPsychicAttack                   = 0x00000220;
    constexpr int32_t esperDeathCount                      = 0x00000228;
    constexpr int32_t stalkSprite                          = 0x00000230;
    constexpr int32_t whisperSprite                        = 0x00000238;
    constexpr int32_t detectCorruptionSprite               = 0x00000240;
    constexpr int32_t sameCorruptionSprite                 = 0x00000248;
    constexpr int32_t differentCorruptionSprite            = 0x00000250;
    constexpr int32_t compareCorruptionSprite              = 0x00000258;
    constexpr int32_t ritualSprite                         = 0x00000260;
    constexpr int32_t corruptSprite                        = 0x00000268;
    constexpr int32_t detectCrowTargetsSprite              = 0x00000270;
    constexpr int32_t expelSoulsSprite                     = 0x00000278;
    constexpr int32_t markHauntSprite                      = 0x00000280;
    constexpr int32_t chickenFinishSprite                  = 0x00000288;
    constexpr int32_t chickenReviveSprite                  = 0x00000290;
    constexpr int32_t cupidMarkSprite                      = 0x00000298;
    constexpr int32_t cupidRemoveMarkSprite                = 0x000002A0;
    constexpr int32_t implantSprite                        = 0x000002A8;
    constexpr int32_t collectSprite                        = 0x000002B0;
    constexpr int32_t implantKillSprite                    = 0x000002B8;
    constexpr int32_t parasiteSprite                       = 0x000002C0;
    constexpr int32_t droneTransformSprite                 = 0x000002C8;
    constexpr int32_t owlPickPocket                        = 0x000002D0;
    constexpr int32_t owlMoveSpeed                         = 0x000002D8;
    constexpr int32_t owlReroll                            = 0x000002E0;
    constexpr int32_t sniperAimSprite                      = 0x000002E8;
    constexpr int32_t sniperAimOffSprite                   = 0x000002F0;
    constexpr int32_t sniperShootSprite                    = 0x000002F8;
    constexpr int32_t survivalistHideSprite                = 0x00000300;
    constexpr int32_t killInactiveSprite                   = 0x00000308;
    constexpr int32_t scanOffSprite                        = 0x00000310;
    constexpr int32_t mimeMarkSprite                       = 0x00000318;
    constexpr int32_t mimeSprite                           = 0x00000320;
    constexpr int32_t exitDreamSprite                      = 0x00000328;
    constexpr int32_t ravenKill                            = 0x00000330;
    constexpr int32_t lucidDreamerTeleport                 = 0x00000338;
    constexpr int32_t hawkAtomicBreath                     = 0x00000340;
    constexpr int32_t sensorSprite                         = 0x00000348;
    constexpr int32_t monsterScent                         = 0x00000350;
    constexpr int32_t monsterSpeedBoost                    = 0x00000358;
    constexpr int32_t witchDoctorEyeClosed                 = 0x00000360;
    constexpr int32_t witchDoctorEyeOpen                   = 0x00000368;
    constexpr int32_t cuckooLayEgg                         = 0x00000370;
    constexpr int32_t cuckooEggCounter                     = 0x00000378;
    constexpr int32_t buttonPrefab                         = 0x00000380;
    constexpr int32_t miniMapButtonPrefab                  = 0x00000388;
    constexpr int32_t cooldownButtonPrefab                 = 0x00000390;
    constexpr int32_t cooldownCounterButtonPrefab          = 0x00000398;
    constexpr int32_t gaugeButtonPrefab                    = 0x000003A0;
    constexpr int32_t counterButtonPrefab                  = 0x000003A8;
    constexpr int32_t chargeButtonPrefab                   = 0x000003B0;
    constexpr int32_t HUDTextPrefab                        = 0x000003B8;
    constexpr int32_t joystickPrefab                       = 0x000003C0;
    constexpr int32_t joystick                             = 0x000003C8;
    constexpr int32_t fartMobileButtonPrefab               = 0x000003D0;
    constexpr int32_t fartMobileButton                     = 0x000003D8;
    constexpr int32_t RegisteredButtons                    = 0x000003E0;
    constexpr int32_t disableButtons                       = 0x000003E8;
    constexpr int32_t registeredHUDText                    = 0x000003F0;
    constexpr int32_t lastCounterValue                     = 0x000003F8;
    constexpr int32_t counterCoroutine                     = 0x00000400;
    constexpr int32_t counterEffectCoroutine               = 0x00000408;
}

namespace LocalPlayer {
    constexpr uint32_t InstanceSize = 0x00000180;

    constexpr int32_t DEFAULT_LENS_ORTHOGRAPHIC_SIZE       = 0x00000000;
    constexpr int32_t MINIMUM_LENS_ORTHOGRAPHIC_SIZE       = 0x00000004;
    constexpr int32_t MAXIMUM_LENS_ORTHOGRAPHIC_SIZE       = 0x00000008;
    constexpr int32_t Instance                             = 0x00000010;
    constexpr int32_t Player                               = 0x00000018;
    constexpr int32_t fogOfWar                             = 0x00000020;
    constexpr int32_t playerUI                             = 0x00000028;
    constexpr int32_t roomUpdater                          = 0x00000030;
    constexpr int32_t fartOnCooldown                       = 0x00000038;
    constexpr int32_t fartStartTime                        = 0x0000003C;
    constexpr int32_t moveWASD                             = 0x00000040;
    constexpr int32_t movementTargetPosition               = 0x0000005C;
    constexpr int32_t mainCamera                           = 0x00000078;
    constexpr int32_t stateCamera                          = 0x00000080;
    constexpr int32_t scriptableState                      = 0x00000088;
    constexpr int32_t cameraShakeCoroutine                 = 0x00000090;
    constexpr int32_t disableMovement                      = 0x00000098;
    constexpr int32_t fpFrozen                             = 0x00000099;
    constexpr int32_t roleFrozen                           = 0x0000009A;
    constexpr int32_t isDebuffFrozen                       = 0x0000009B;
    constexpr int32_t firstRejoin                          = 0x0000009C;
    constexpr int32_t currentFrozenTime                    = 0x000000A0;
    constexpr int32_t movementType                         = 0x00000020;
    constexpr int32_t BaseMovementSpeed                    = 0x00000024;
    constexpr int32_t movementSpeed                        = 0x00000028;
    constexpr int32_t pickupSpeedMultiplier                = 0x00000040;
    constexpr int32_t isDyingBySpace                       = 0x000000A4;
    constexpr int32_t isDyingByCrush                       = 0x000000A5;
    constexpr int32_t originSpaceDeathPosition             = 0x000000A8;
    constexpr int32_t dyingBySpaceTime                     = 0x000000B4;
    constexpr int32_t isInDarkk__BackingField              = 0x000000B8;
    constexpr int32_t isInSandstormk__BackingField         = 0x000000B9;
    constexpr int32_t CurrentHunt                          = 0x000000BA;
    constexpr int32_t inVotingScreen                       = 0x000000BB;
    constexpr int32_t inVotingScreenIncludingTransition    = 0x000000BC;
    constexpr int32_t inGameStartSpotlightScreen           = 0x000000BD;
    constexpr int32_t inGameEndSpotlightScreen             = 0x000000BE;
    constexpr int32_t useButton                            = 0x000000C0;
    constexpr int32_t doorButton                           = 0x000000C8;
    constexpr int32_t bombExplosionServerTimestamp         = 0x000000D0;
    constexpr int32_t cupidLinkedPlayer                    = 0x000000D8;
    constexpr int32_t knownTeammates                       = 0x000000E0;
    constexpr int32_t otherTeamsAreKnown                   = 0x000000E8;
    constexpr int32_t walletAtStart                        = 0x000000F0;
    constexpr int32_t spectateEntity                       = 0x000000F8;
    constexpr int32_t isMoving                             = 0x00000100;
    constexpr int32_t markServerTimestamp                  = 0x00000104;
    constexpr int32_t timeUntilDownDeath                   = 0x00000108;
    constexpr int32_t timeUntilZoneDeath                   = 0x0000010C;
    constexpr int32_t timeUntilRespawn                     = 0x00000110;
    constexpr int32_t willRespawn                          = 0x00000114;
    constexpr int32_t dragFilter                           = 0x00000118;
    constexpr int32_t isInsideWall                         = 0x00000134;
    constexpr int32_t refreshingRoomAfterDelayCoroutine    = 0x00000138;
    constexpr int32_t isMimed                              = 0x00000140;
    constexpr int32_t mimeKillInteractableEventCooldown    = 0x00000144;
    constexpr int32_t canSeeGhosts                         = 0x00000148;
    constexpr int32_t heldItemIndex                        = 0x0000014C;
    constexpr int32_t kCodeFlip                            = 0x00000150;
    constexpr int32_t closestEntitiesBuffer                = 0x00000158;
    constexpr int32_t confinerCheckBuffer                  = 0x00000168;
    constexpr int32_t TargetsInRange                       = 0x00000178;
    constexpr int32_t IsGhost                              = 0x00000058;
}

namespace UIButton {
    constexpr uint32_t InstanceSize = 0x000000A8;

    constexpr int32_t keyOverlay                           = 0x00000020;
    constexpr int32_t leftTutorialArrow                    = 0x00000028;
    constexpr int32_t rightTutorialArrow                   = 0x00000030;
    constexpr int32_t keyOverlayImage                      = 0x00000038;
    constexpr int32_t button                               = 0x00000040;
    constexpr int32_t keybindText                          = 0x00000048;
    constexpr int32_t onClick                              = 0x00000050;
    constexpr int32_t onPressed                            = 0x00000058;
    constexpr int32_t onHeld                               = 0x00000060;
    constexpr int32_t onReleased                           = 0x00000068;
    constexpr int32_t holdGaugeImage                       = 0x00000070;
    constexpr int32_t maxHoldTime                          = 0x00000078;
    constexpr int32_t isHeld                               = 0x0000007C;
    constexpr int32_t isButtonPressed                      = 0x0000007D;
    constexpr int32_t holdTimer                            = 0x00000080;
    constexpr int32_t targetUpdater                        = 0x00000088;
    constexpr int32_t keybind                              = 0x00000090;
    constexpr int32_t controllerBindShower                 = 0x00000098;
    constexpr int32_t onInteractableChanged                = 0x000000A0;
}

namespace TasksHandler {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t CanTargetTasks                       = 0x00000000;
    constexpr int32_t tasks                                = 0x00000020;
    constexpr int32_t tasksDictionary                      = 0x00000028;
    constexpr int32_t assignedTasks                        = 0x00000030;
    constexpr int32_t sortedAssignedTasks                  = 0x00000038;
    constexpr int32_t taskUIPrefab                         = 0x00000040;
    constexpr int32_t taskList                             = 0x00000048;
    constexpr int32_t timesReplenished                     = 0x00000050;
    constexpr int32_t mapHandler                           = 0x00000058;
}

namespace TaskTargetingHandler {
    constexpr uint32_t InstanceSize = 0x00000060;

    constexpr int32_t targetArrowPrefab                    = 0x00000020;
    constexpr int32_t targetedTask                         = 0x00000028;
    constexpr int32_t targetedTaskRectTransform            = 0x00000030;
    constexpr int32_t targetedTaskArrow                    = 0x00000038;
    constexpr int32_t targetedTaskText                     = 0x00000040;
    constexpr int32_t activeArrows                         = 0x00000048;
    constexpr int32_t CurrentTargetingTask                 = 0x00000050;
    constexpr int32_t isTargetingTask                      = 0x00000058;
    constexpr int32_t currentTaskIndex                     = 0x0000005C;
}

namespace ClawMachineSelectorHandler {
    constexpr uint32_t InstanceSize = 0x000000D0;

    constexpr int32_t rectTransform                        = 0x00000020;
    constexpr int32_t selectedToggle                       = 0x00000028;
    constexpr int32_t machineName                          = 0x00000030;
    constexpr int32_t machineBorder                        = 0x00000038;
    constexpr int32_t lastPullImage                        = 0x00000040;
    constexpr int32_t highlight                            = 0x00000048;
    constexpr int32_t selectedArrow                        = 0x00000050;
    constexpr int32_t outOfOrderObj                        = 0x00000058;
    constexpr int32_t seasonalOutOfOrderObj                = 0x00000060;
    constexpr int32_t seasonalOutOfOrder                   = 0x00000068;
    constexpr int32_t activeColor                          = 0x00000070;
    constexpr int32_t unActiveColor                        = 0x00000080;
    constexpr int32_t notficationObj                       = 0x00000090;
    constexpr int32_t notificationText                     = 0x00000098;
    constexpr int32_t tierObjs                             = 0x000000A0;
    constexpr int32_t gachaMachine                         = 0x000000A8;
    constexpr int32_t panelHandler                         = 0x000000B0;
    constexpr int32_t clawMachineSprites                   = 0x000000B8;
    constexpr int32_t timerStarted                         = 0x000000C0;
    constexpr int32_t countdownTime                        = 0x000000C8;
}

namespace GamepadNavigationHelper {
    constexpr uint32_t InstanceSize = 0x000000D8;

    constexpr int32_t textHighlight                        = 0x00000010;
    constexpr int32_t highlight                            = 0x00000018;
    constexpr int32_t highlightImage                       = 0x00000020;
    constexpr int32_t highlightedColor                     = 0x00000024;
    constexpr int32_t unhighlightedColor                   = 0x00000034;
    constexpr int32_t onButtonClick                        = 0x00000048;
    constexpr int32_t onEventTriggered                     = 0x00000050;
    constexpr int32_t onToggleSelected                     = 0x00000058;
    constexpr int32_t spriteButtonTriggered                = 0x00000060;
    constexpr int32_t clickAction                          = 0x00000068;
    constexpr int32_t hasInfo                              = 0x00000070;
    constexpr int32_t infoButton                           = 0x00000078;
    constexpr int32_t infoEventTriggered                   = 0x00000080;
    constexpr int32_t slider                               = 0x00000088;
    constexpr int32_t canOnlyMoveWhenSelected              = 0x00000090;
    constexpr int32_t increaseValue                        = 0x00000094;
    constexpr int32_t minValue                             = 0x00000098;
    constexpr int32_t maxValue                             = 0x0000009C;
    constexpr int32_t hasInputField                        = 0x000000A0;
    constexpr int32_t inputField                           = 0x000000A8;
    constexpr int32_t canPaste                             = 0x000000B0;
    constexpr int32_t maxPasteValue                        = 0x000000B4;
    constexpr int32_t hasDropdown                          = 0x000000B8;
    constexpr int32_t dropdown                             = 0x000000C0;
    constexpr int32_t selectItemOnNavigation               = 0x000000C8;
    constexpr int32_t explicitNavigations                  = 0x000000D0;
}

namespace EsperDuck {
    constexpr uint32_t InstanceSize = 0x000000D8;

    constexpr int32_t telepathicButton                     = 0x000000C0;
    constexpr int32_t telepathicCooldown                   = 0x000000C8;
    constexpr int32_t hasTarget                            = 0x000000CC;
    constexpr int32_t previousRoom                         = 0x000000D0;
}

namespace SerialKiller {
    constexpr uint32_t InstanceSize = 0x000000D0;

    constexpr int32_t cooldown                             = 0x000000C0;
    constexpr int32_t target                               = 0x000000C8;
}

namespace CameraMetadataCacheEntry {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t name                                 = 0x00000010;
    constexpr int32_t sampler                              = 0x00000018;
}

namespace ObscuredString {
    constexpr uint32_t InstanceSize = 0x00000048;

    constexpr int32_t currentCryptoKey                     = 0x00000010;
    constexpr int32_t hiddenValue                          = 0x00000018;
    constexpr int32_t cryptoKey                            = 0x00000020;
    constexpr int32_t hiddenChars                          = 0x00000028;
    constexpr int32_t inited                               = 0x00000030;
    constexpr int32_t fakeValue                            = 0x00000038;
    constexpr int32_t fakeValueActive                      = 0x00000040;
}

namespace Bodyguard {
    constexpr uint32_t InstanceSize = 0x000000C8;

    constexpr int32_t VIPAliveAtEnd                        = 0x000000B8;
    constexpr int32_t VIP                                  = 0x000000C0;
}

namespace LoverGoose {
    constexpr uint32_t InstanceSize = 0x000000C0;

    constexpr int32_t otherLover                           = 0x000000B8;
}

namespace ModeSelectHandler {
    constexpr uint32_t InstanceSize = 0x00000098;

    constexpr int32_t LANGUAGE_KEY                         = 0x00000000;
    constexpr int32_t OnModeSelected                       = 0x00000008;
    constexpr int32_t title                                = 0x00000020;
    constexpr int32_t description                          = 0x00000028;
    constexpr int32_t selectedColor                        = 0x00000030;
    constexpr int32_t buttonSound                          = 0x00000040;
    constexpr int32_t bubblesPool                          = 0x00000048;
    constexpr int32_t menuScreenHandler                    = 0x00000050;
    constexpr int32_t modesData                            = 0x00000058;
    constexpr int32_t playButton                           = 0x00000060;
    constexpr int32_t gamepadNavHelper                     = 0x00000068;
    constexpr int32_t LearnMoreGameModeButton              = 0x00000070;
    constexpr int32_t LearnMoreGameModeUIButton            = 0x00000078;
    constexpr int32_t MapModeTutPanel                      = 0x00000080;
    constexpr int32_t _selectedBubble                      = 0x00000088;
    constexpr int32_t bubbleObjects                        = 0x00000090;
}

namespace LoungeDoor {
    constexpr uint32_t InstanceSize = 0x00000080;

    constexpr int32_t interactable                         = 0x00000020;
    constexpr int32_t roomCollider                         = 0x00000028;
    constexpr int32_t animator                             = 0x00000030;
    constexpr int32_t state                                = 0x00000038;
    constexpr int32_t someoneLeaving                       = 0x0000003C;
    constexpr int32_t insideToOutsideDirection             = 0x00000040;
    constexpr int32_t walkAnimDist                         = 0x00000044;
    constexpr int32_t start                                = 0x00000048;
    constexpr int32_t dest                                 = 0x00000050;
    constexpr int32_t doorIndex                            = 0x00000058;
    constexpr int32_t _startMovingThroughTimer             = 0x0000005C;
    constexpr int32_t _updateShadowTimer                   = 0x00000060;
    constexpr int32_t _enableMovementTimer                 = 0x00000064;
    constexpr int32_t _movingThroughTarget                 = 0x00000068;
    constexpr int32_t _initialPosition                     = 0x00000070;
    constexpr int32_t stateStarted                         = 0x0000007C;
    constexpr int32_t CloseDoorT                           = 0x00000004;
    constexpr int32_t OpenDoorT                            = 0x00000008;
}

namespace LobbyPanelHandler {
    constexpr uint32_t InstanceSize = 0x00000130;

    constexpr int32_t HOLD_TO_START_GAME_FILL_SPEED        = 0x00000000;
    constexpr int32_t settingsButton                       = 0x00000020;
    constexpr int32_t muteButton                           = 0x00000028;
    constexpr int32_t deafenButton                         = 0x00000030;
    constexpr int32_t helpButton                           = 0x00000038;
    constexpr int32_t leaveButton                          = 0x00000040;
    constexpr int32_t friendButton                         = 0x00000048;
    constexpr int32_t summaryButton                        = 0x00000050;
    constexpr int32_t contentCreatorButton                 = 0x00000058;
    constexpr int32_t chatButton                           = 0x00000060;
    constexpr int32_t chatButtonImage                      = 0x00000068;
    constexpr int32_t chatButtonDefaultColor               = 0x00000070;
    constexpr int32_t startButtonRect                      = 0x00000080;
    constexpr int32_t startButton                          = 0x00000088;
    constexpr int32_t startUIButton                        = 0x00000090;
    constexpr int32_t startButtonBlocker                   = 0x00000098;
    constexpr int32_t startButtonText                      = 0x000000A0;
    constexpr int32_t readyButtonRect                      = 0x000000A8;
    constexpr int32_t readyButton                          = 0x000000B0;
    constexpr int32_t roomCodeShow                         = 0x000000B8;
    constexpr int32_t roomCodeHide                         = 0x000000C0;
    constexpr int32_t gamemodeLabeltext                    = 0x000000C8;
    constexpr int32_t playerCountText                      = 0x000000D0;
    constexpr int32_t roomCodeText                         = 0x000000D8;
    constexpr int32_t chatToastParentRect                  = 0x000000E0;
    constexpr int32_t chatToastParentRectDefaultSize       = 0x000000E8;
    constexpr int32_t chatToastParentRectJoystickSize      = 0x000000F0;
    constexpr int32_t chatToastHolder                      = 0x000000F8;
    constexpr int32_t readyButtonLobbyHolder               = 0x00000100;
    constexpr int32_t lobbyTextBox                         = 0x00000108;
    constexpr int32_t lobbyText                            = 0x00000110;
    constexpr int32_t lobbyTextBoxClosing                  = 0x00000118;
    constexpr int32_t holdToForceStartSlider               = 0x00000120;
    constexpr int32_t canHoldToForceStart                  = 0x00000128;
    constexpr int32_t isHoldingToStart                     = 0x00000129;
    constexpr int32_t triggeredForceStart                  = 0x0000012A;
    constexpr int32_t forceStartTimer                      = 0x0000012C;
}

namespace GamepadNavigation {
    constexpr uint32_t InstanceSize = 0x00000028;

    constexpr int32_t direction                            = 0x00000010;
    constexpr int32_t nextIndex                            = 0x00000014;
    constexpr int32_t onBeforeNavigate                     = 0x00000018;
    constexpr int32_t onNavigate                           = 0x00000020;
}

namespace GamepadNavigationHelperCollection {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t gamepadNavigationHelpers             = 0x00000010;
    constexpr int32_t columnLength                         = 0x00000018;
}

namespace RequestState {
    constexpr uint32_t InstanceSize = 0x00000020;

    constexpr int32_t isFaulted                            = 0x00000010;
    constexpr int32_t error                                = 0x00000018;
}

namespace DraftBanRoleHandler {
    constexpr uint32_t InstanceSize = 0x00000080;

    constexpr int32_t roleSquareHandler                    = 0x00000020;
    constexpr int32_t roleSquareSettingsHandler            = 0x00000028;
    constexpr int32_t noObj                                = 0x00000030;
    constexpr int32_t buttonImage                          = 0x00000038;
    constexpr int32_t disabledColor                        = 0x00000040;
    constexpr int32_t enabledColor                         = 0x00000050;
    constexpr int32_t button                               = 0x00000060;
    constexpr int32_t isBanned                             = 0x00000068;
    constexpr int32_t initialized                          = 0x00000069;
    constexpr int32_t handler                              = 0x00000070;
    constexpr int32_t OnStateChanged                       = 0x00000078;
}

namespace GAEvents {
    constexpr uint32_t InstanceSize = 0x00000018;

    constexpr int32_t _instance                            = 0x00000000;
    constexpr int32_t isRunning                            = 0x00000010;
    constexpr int32_t keepRunning                          = 0x00000011;
}

}
