#include <amethyst/ui/ImGui.hpp>

bool showMenu = false;

// This runs every time a frame is drawn on your screen
void OnRenderUI() {
    // Listen for the 'P' key (Virtual Key 0x50)
    if (ImGui::IsKeyPressed(ImGuiKey_P)) {
        showMenu = !showMenu; 
    }

    if (showMenu) {
        // Start the Meteor-style Window
        ImGui::Begin("Meteor Bedrock Edition", &showMenu);
        ImGui::Text("Version 1.0 - Built by You");
        ImGui::Separator();

        // Checkboxes for your hacks
        ImGui::Checkbox("Flight", &flyEnabled);
        ImGui::Checkbox("Speed", &speedEnabled);
        ImGui::Checkbox("Killaura", &killauraEnabled);
        ImGui::Checkbox("Auto-Walk", &autoWalkEnabled);
        ImGui::Checkbox("Auto-Mine", &autoMineEnabled);
        ImGui::Checkbox("Stash Finder", &stashFinderEnabled);
        
        if (ImGui::Button("Disable All")) {
            flyEnabled = speedEnabled = killauraEnabled = false;
        }

        ImGui::End();
    }
}

// Update your Initialize function to include the UI
void Initialize(AmethystContext* ctx) {
    ctx->events.beforeTick.AddListener(&OnTick);
    ctx->events.onFrameUpdate.AddListener(&OnUpdate);
    
    // This line tells Amethyst to start drawing your menu
    ctx->events.onRenderUI.AddListener(&OnRenderUI);
}