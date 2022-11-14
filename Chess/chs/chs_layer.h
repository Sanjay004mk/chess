#pragma once
#include <Entropy/Entropy.h>
#include "game/tile_manager.h"
#include "game/board.h"

namespace chs
{
	class ChessLayer : public et::Layer 
	{
	public:
		ChessLayer() = default;
		~ChessLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(et::TimeStep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(et::Event& e) override;

	private:
		void StartNewGame();
		bool StartGame(std::string_view fen_string);
		void Resize(uint32_t newWidth, uint32_t newHeight);
		void DisplayBoardUI();
		void DisplayMainMenu();
		void DisplayVsPlayerMenu();
		void DisplayVsCompMenu();
		void DisplayLevelSelectMenu();
		void DisplayHomeButton();
		void PlayEngineMove();

		uint32_t width = 0, height = 0;

		enum class MenuState { MainMenu, VsComputer, VsPlayer, LevelSelect, InGame };
		MenuState menuState = MenuState::MainMenu;
		BoardSpecification boardCreateSpecs;

		TileManager tileManager;
		et::Ref<Board> board;

		et::Ref<et::Texture> screen;
		et::Ref<et::Shader> defaultShader;
		et::Ref<et::Pipeline> pipeline;
		et::Ref<et::Renderpass> renderpass;
		et::Ref<et::Framebuffer> framebuffer;

		std::vector<et::Ref<et::Texture>> textures;
	};
}