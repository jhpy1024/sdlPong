#include "Game.h"
#include "Paddle.h"
#include "Wall.h"
#include "Ball.h"
#include "AIPaddle.h"

int Game::Width = 640;
int Game::Height = 480;

Game::Game(int width, int height, const std::string& title)
: title_(title), playerScore_(0), aiScore_(0),
lastPlayerScore_(0), lastAiScore_(0),
window_(WindowPtr(nullptr, SDL_DestroyWindow)),
renderer_(RendererPtr(nullptr, SDL_DestroyRenderer)),
playerScoreText_(renderer_), aiScoreText_(renderer_)
{
	Game::Width = width;
	Game::Height = height;

	initSDL();
	loadTextures();
	createEntities();

	//audioManager_.loadSound("testSound", "assets/sound.wav");
	//audioManager_.playSound("testSound");

	running_ = true;
}

void Game::loadTextures()
{
	textureManager_.addTexture("assets/paddle.png", "paddle", renderer_);
	textureManager_.addTexture("assets/wallHorizontal.png", "wallHorizontal", renderer_);
	textureManager_.addTexture("assets/wallVertical.png", "wallVertical", renderer_);
	textureManager_.addTexture("assets/ball.png", "ball", renderer_);
}

void Game::createEntities()
{
	// Top wall
	entities_.push_back(std::make_unique<Wall>(
		Wall("wallHorizontal", { 0, 0 }, { static_cast<float>(Width), Wall::WallSize }, EntityType::Wall)));

	// Bottom wall
	entities_.push_back(std::make_unique<Wall>(
		Wall("wallHorizontal", { 0, Height - Wall::WallSize }, { static_cast<float>(Width), Wall::WallSize }, EntityType::Wall)));

	// Left wall
	entities_.push_back(std::make_unique<Wall>(
		Wall("wallVertical", { 0, 0 }, { Wall::WallSize, static_cast<float>(Height) }, EntityType::Wall)));

	// Right wall
	entities_.push_back(std::make_unique<Wall>(
		Wall("wallVertical", { Width - Wall::WallSize, 0 }, { Wall::WallSize, static_cast<float>(Height) }, EntityType::Wall)));

	// Center wall
	entities_.push_back(std::make_unique<Wall>(
		Wall("wallVertical", { Width / 2 - Wall::WallSize / 2, 0 }, { Wall::WallSize, static_cast<float>(Height) }, EntityType::Wall)));

	entities_.push_back(std::make_unique<Paddle>(
		Paddle("paddle", { Wall::WallSize, static_cast<float>(Height) / 2 - 150 / 2 }, { 15, 150 }, EntityType::Paddle)));

	entities_.push_back(std::make_unique<Ball>(
		Ball("ball", { Width / 2.f, Height / 2.f }, { 16, 16 }, EntityType::Ball)));

	entities_.push_back(std::make_unique<AIPaddle>(
		AIPaddle("paddle", { Width - Wall::WallSize - 15, static_cast<float>(Height) / 2 - 150 / 2 }, { 15, 150 }, EntityType::Paddle,
		entities_[6])));

	playerScoreText_
		.setPosition({ Game::Width / 2.f - 50, 50})
		.setColor({ 255, 255, 255 })
		.setSize(35)
		.setFont("assets/consola.ttf")
		.setContents(std::to_string(playerScore_))
		.create();

	aiScoreText_
		.setPosition({ Game::Width / 2.f + 30, 50 })
		.setColor({ 255, 255, 255 })
		.setSize(35)
		.setFont("assets/consola.ttf")
		.setContents(std::to_string(aiScore_))
		.create();
}

void Game::initSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window_.reset(SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		Width, Height, SDL_WINDOW_SHOWN));
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
	{
		if (entity->getType() == EntityType::Ball)
		{
			playerScore_ = ((Ball*)entity.get())->getHitRightCount();
			aiScore_ = ((Ball*)entity.get())->getHitLeftCount();
		}

		entity->checkCollisions(entities_);
		entity->update();
	}

	if (playerScore_ != lastPlayerScore_)
	{
		playerScoreText_.changeContents(std::to_string(playerScore_));
		lastPlayerScore_ = playerScore_;
	}

	if (aiScore_ != lastAiScore_)
	{
		aiScoreText_.changeContents(std::to_string(aiScore_));
		lastAiScore_ = aiScore_;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer_.get());

	for (auto& entity : entities_)
		entity->render(renderer_, textureManager_);

	playerScoreText_.render();
	aiScoreText_.render();

	SDL_RenderPresent(renderer_.get());
}

bool Game::isRunning() const
{
	return running_;
}