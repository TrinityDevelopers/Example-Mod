#pragma once
#include <memory>
#include "../material/Material.h"
#include "BlockSourceListener.h"
class AABB;
class Entity;
class Player;
class Random;
class EntityDamageSource;
class Difficulty;
class LightLayer;
class LevelChunk;
class EntityUniqueID;
class ResourcePackManager;

class Level : public BlockSourceListener {
public:
	virtual ~Level();
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void addEntity(BlockSource&, std::unique_ptr<Entity>);
	virtual void addGlobalEntity(BlockSource&, std::unique_ptr<Entity>);
	virtual void addAutonomousEntity(BlockSource&, std::unique_ptr<Entity>);
	virtual void addPlayer(std::unique_ptr<Player>);
	virtual void takeEntity(EntityUniqueID);
	virtual void borrowEntity(EntityUniqueID, LevelChunk*);
	virtual void onPlayerDeath(Player&, const EntityDamageSource&);
	virtual void tick();
	virtual void directTickEntities(BlockSource&);
	virtual void updateSleepingPlayerList();
	virtual void setDefficulty(Difficulty);
	virtual void setCommandsEnabled(bool);
	virtual void runLightUpdates(BlockSource&, const LightLayer&, const BlockPos&, const BlockPos&);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void onChunkLoaded(LevelChunk&);
	virtual void queueEntityRemoval(std::unique_ptr<Entity>&&, bool);
	virtual void removeEntityReferences(Entity&, bool);
	virtual void onAppSuspended();
	virtual ResourcePackManager& getClientResourcePackManager() const;
	virtual ResourcePackManager& getServerResourcePackManager() const;
	
	bool checkAndHandleMaterial(const AABB&, MaterialType, Entity*);
	Random* getRandom();
	void setTime(int);
};

