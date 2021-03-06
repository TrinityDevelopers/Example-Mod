#pragma once

#include <string>
#include <vector>

#include "AddEntityPacket.h"
#include "../phys/AABB.h"

class Inventory;
class Vec3;
class Vec2;
class Player;
class EntityDamageSource;
class BlockPos;
class FullBlock;
class ItemInstance;
class CompoundTag;
class SetEntityDataPacket;
class ChangeDimensionPacket;
class Block;
class EntityPos;
class EntityType;
class LootTables.h;
class MaterialType.h;
class EntityUniqueID.h;
class EntityEvent.h;
class EntityLink.h;
class DimensionId.h;
class LevelSoundEvent.h;

enum class ArmorSlot : int {
	HELMET,
	CHESTPLATE,
	LEGGINGS,
	BOOTS
};

class Entity {
public:

	char bigdaddy[3242];

	Entity(BlockSource&, const std::string&);
	Entity(Level&);
	Entity(EntityDefinitionGroup&, const EntityDefinitionIdentifier&);
	
	virtual void reloadHardcoded(Entity::InitializationMethod, const VariantParameterList&);
	virtual void reloadHardcodedClient(Entity::InitializationMethod, const VariantParameterList&);
	virtual void initializeComponents(Entity::InitializationMethod, const VariantParameterList&);
	virtual void reloadcComponents(Entity::InitializationMethod, const VariantParameterList&);
	virtual bool hasComponent(const std::string&) const;
	virtual bool hasInventory() const;
	virtual Inventory& getInventory();
	
	virtual ~Entity();
	virtual void reset();
	virtual int getOwnerEntityType();
	virtual void remove();
	virtual void setPos(const Vec3&);
	virtual Vec3& getPos() const;
	virtual Vec3& getPosOld() const;
	virtual Vec3& getPosExtrapolated(float) const;
	virtual float getVelocity() const;
	virtual void setRot(const Vec2&);
	virtual void move(const Vec2&);
	virtual void checkBlockCollisions(const AABB&);
	virtual void checkBlockCollisions();
	virtual bool canFly();
	virtual void moveRelative(float, float, float);
	virtual void teleportTo(const Vec3&, int, int);
	virtual void tryTeleportTo(const Vec3&, bool, bool, int, int);
	virtual void lerpTo(const Vec3&, const Vec2&, int);
	virtual void lerpMotion(const Vec3&);
	virtual void turn(const Vec2&, bool);
	virtual void interpolateTurn(const Vec2&);
	virtual AddEntityPacket getAddPacket();
	virtual int normalTick();
	virtual int baseTick();
	virtual int rideTick();
	virtual void positionRider(Entity&) const;
	virtual int getRidingHeight();
	virtual void startRiding(Entity&);
	virtual void addRider(Entity&);
	virtual void flagRiderToRemove(Entity&);
	virtual void intersects(const Vec3&, const Vec3&);
	virtual bool isFree(const Vec3&, float);
	virtual bool isFree(const Vec3&);
	virtual bool isInWall() const;
	virtual bool isInvisible() const;
	virtual bool canShowNameTag();
	virtual bool canExistInPeaceful() const;
	virtual void setNameTagVisible(bool);
	virtual const std::string& getNameTag() const;
	virtual const std::string& getFormattedNameTag() const;
	virtual void setNameTag(const std::string&);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(MaterialType) const;
	virtual void onLadder(bool);
	virtual void makeStuckInWeb();
	virtual int getHeadHeight() const;
	virtual int getCameraOffset() const;
	virtual int getShadowHeightOffs();
	virtual int getShadowRadius() const;
	virtual bool isSwimmer();
	virtual bool canSeeInvisible();
	virtual bool isSkyLit(float);
	virtual float getBrightness(float) const;
	virtual void interactPreventDefault();
	virtual void playerTouch(Player&);
	virtual void push(Entity&, bool);
	virtual void push(const Vec3&);
	virtual bool isImmobile() const;
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isFishable() const;
	virtual bool isPushable() const;
	virtual bool isPushableByPiston() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive() const;
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual void setTarget(Entity*);
	virtual void setOwner(EntityUniqueID);
	virtual void setSitting(bool);
	virtual void onTame();
	virtual void onFailedTame();
	virtual void onMate(Mob&);
	virtual bool shouldRender() const;
	virtual bool isInvulnerableTO(const EntityDamageSource&) const;
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void onBounceStarted(const BlockPos&, const FullBlock&);
	virtual void feed(int);
	virtual void handleEntityEvent(EntityEvent, int);
	virtual int getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(FullBlock, int);
	virtual void spawnAtLocation(FullBlock, int, float);
	virtual void spawnAtLocation(const ItemInstance&, float);
	virtual void killed(Entity*);
	virtual void awardKillScore(Entity&, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, const ItemInstance&);
	virtual void save(CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(const CompoundTag&);
	virtual void loadLinks(const CompoundTag&, std::vector<EntityLink>&);
	virtual EntityType getEntityTypeId() const = 0;
	virtual void acceptClientsideEntityData(Player&, const SetEntityDataPacket&);
	virtual void queryEntityRenderer();
	virtual int getSourceUniqueID() const;
	virtual void setOnFire(int);
	virtual AABB getHandleWaterAABB() const;
	virtual void handleInsidePortal(const BlockPos&);
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual int getDimentsionId() const;
	virtual bool canChangeDimensions() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(const ChangeDimensionPacket&) ;
	virtual Player* getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void playSynchronizedSound(LevelSoundEvent, const Vec3&, int, bool);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity&) const;
	virtual bool canBePulledIntoVehicle() const;
	virtual bool canBeLeashed();
	virtual bool isLeashableType();
	virtual void tickLeash();
	virtual int getEyeHeight() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool, bool);
	virtual void buildDebugInfo(std::string&) const;
	virtual void openContainerComponent(Player&);
	virtual void useItem(ItemInstance&) const;
	virtual bool hasOutputSignal(signed char) const;
	virtual int getOutputSignal() const;
	virtual std::string getDebugText(std::vector<std::string>&);
	virtual void startSeenByPlayer(Player&);
	virtual void stopSeenByPlayer(Player&);
	virtual int getMapDecorationRotation();
	virtual int getRiderDecorationRotation(Player&);
	virtual int getYHeadRot() const;
	virtual bool isWorldBuilder();
	virtual bool isCreative() const;
	virtual void add(ItemInstance&);
	virtual void drop(const ItemInstance&, bool);
	virtual bool canDestroyBlock(const Block&) const;
	virtual void setAuxValue(int);
	virtual void setSize(float, float);
	virtual void setPos(const EntityPos&);
	virtual bool outOfWorld();
	virtual void _hurt(const EntityDamageSource&, int, bool, bool);
	virtual void markHurt();
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(const CompoundTag&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(const BlockPos&, int);
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(const Vec3&);
	virtual void updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void updateInsideBlock();
	virtual void onBlockCollision(int);
	virtual LootTables getLootTable() const;
	virtual LootTables getDefaultLootTable() const;
	virtual void _removeRider(Entity&, bool);

};