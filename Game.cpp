#include "Game.h"

Game::Game(int width, int height, const std::string& title)
: width_(width), height_(height), title_(title),
window_(WindowPtr(nullptr, SDL_DestroyWindow)),
renderer_(RendererPtr(nullptr, SDL_DestroyRenderer))
{
	initSDL();

	running_ = true;
}

void Game::initSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window_.reset(SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width_, height_, SDL_WINDOW_SHOWN));
	renderer_.reset(SDL_CreateRenderer(window_.get(), -1, 0));
	
	SDL_SetRenderDrawColor(renderer_.get(), 0, 0, 0, 255);
}

void Game::handleInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			SDL_Quit();
			running_ = false;
		}

		for (auto& entity : entities_)
			entity->handleInput(event);
	}

}

void Game::update()
{
	for (auto& entity : entities_)
		entity->update();
}

void Game::render()
{
	SDL_RenderClear(renderer_.get());

	for (auto& entity : entities_)
		entity->render(renderer_, textureManager_);

	SDL_RenderPresent(renderer_.get());
}

bool Game::isRunning() const
{
	return running_;
}

int Game::getWidth() const
{
	return width_;
}

int Game::getHeight() const
{
	return height_;
}