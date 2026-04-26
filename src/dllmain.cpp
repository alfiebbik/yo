#include <amethyst/runtime/AmethystRuntime.h>
#include <amethyst/ui/NinesliceHelper.h>

void OnStartJoinServer(Amethyst::EventContext& ctx) {
    ctx.player.displayClientMessage("§bBikBotClient §7successfully loaded!");
}

extern "C" __declspec(dllexport) void Initialize(Amethyst::Context& ctx) {
    ctx.events.onStartJoinServer.add(&OnStartJoinServer);
}
