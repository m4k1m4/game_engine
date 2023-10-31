#include <iostream>
#include <memory>
#include <imgui/imgui.h>

#include <EngineCore/Input.hpp>
#include <EngineCore/Application.hpp>

class EngineEditor : public Engine::Application
{
    virtual void on_update() override
    {
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_W))
        {
            camera_position[2] -= 0.01f;
        }
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_S))
        {
            camera_position[2] += 0.01f;
        }
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_A))
        {
            camera_position[0] -= 0.01f;
        }
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_D))
        {
            camera_position[0] += 0.01f;
        }
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_E))
        {
            camera_position[1] += 0.01f;
        }
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_Q))
        {
            camera_position[1] -= 0.01f;
        }

        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_UP))
        {
            camera_rotation[0] += 0.5f;
        }
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_DOWN))
        {
            camera_rotation[0] -= 0.5f;
        }
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_RIGHT))
        {
            camera_rotation[1] -= 0.5f;
        }
        if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_LEFT))
        {
            camera_rotation[1] += 0.5f;
        }
    }

    virtual void on_ui_draw() override
    {
        ImGui::Begin("Editor");
        ImGui::SliderFloat3("camera position", camera_position, -10.f, 10.f);
        ImGui::SliderFloat3("camera rotation", camera_rotation, 0, 360.f);
        ImGui::Checkbox("Perspective camera", &perspective_camera);
        ImGui::End();
    }

    int frame = 0;
};

int main() 
{
    auto pEngineEditor = std::make_unique<EngineEditor>();

    int returnCode = pEngineEditor->start(1024, 768, "Engine Editor");

	//std::cin.get();

    return returnCode;
}