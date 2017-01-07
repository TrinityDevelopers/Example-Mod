#pragma once

#include <string>

class LevelSettings {
public:
    unsigned int seed;  
	int gameType;  
	int difficulty;
	int filler;
	int generator;  
	bool achievementsDisabled;
	//incomplete
public:
    LevelSettings();
	
    void* getDefaultSpawn() const;
	int getGameType() const;
	int getGenerator() const;
	unsigned int getSeed() const;
};
