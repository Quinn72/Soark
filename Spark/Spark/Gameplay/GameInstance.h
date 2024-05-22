#pragma once

class Config;
class Screen;
class LevelManager;

class GameInstance
{
	friend class Application;
	friend class LevelManager;

public:
	GameInstance(const GameInstance&) = delete;
	GameInstance(GameInstance&&) = delete;
public:
	GameInstance& operator=(const GameInstance&) = delete;
	GameInstance& operator=(GameInstance&&) = delete;
protected:
	GameInstance();
	virtual  ~GameInstance();
protected:
	virtual void BeginPlay();
	virtual void EndPlay();

	Config* GetConfig() const;
	Screen* GetScreen() const;
	LevelManager* GetLevelManager() const;

private:
	Config* m_config;  // owned and controlled by the Application
	Screen* m_screen; // owned and controlled by the Application
	LevelManager* m_levelManager;

private:
	void Init();
	void Tick(float _dt) const;
	void Render() const;
};

