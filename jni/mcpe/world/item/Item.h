#pragma once

#include <string>
#include <memory>
#include <vector>

#include "../../CreativeItemCategory.h"

class TextureUVCoordinateSet;
class SeedItemComponent;
class FoodItemComponent;
class CameraItemComponent;
class Block;
class ItemInstance;
class Entity;
class Mob;
class Level;
class Player;
class Container;
class BlockSource;
class BlockShape;
class TextureAtlas;
class ResourcePackManager;
class Vec3;
class UseAnimation;
class IDataInput;
class IDataOutput;
class BlockID;
namespace Json { class Value; };

class Item {
public:
	/* constructor */
	Item(const std::string&, short);

	/* fields */
	uint8_t _maxStackSize; // 4
	std::string atlas; // 8
	int frameCount; // 12
	short idk2; // 16
	short itemId; // 18
	std::string name; // 20
	std::string name2; // 24
	bool mirroredArt; //28
	short maxDamage; // 30
	bool foil; // 32
	bool handEquipped; // 33
	bool stackedByData; // 34
	int useDuration; // 36
	char filler[2]; // 40
	char blockId; // 42
	int useAnimation; // 43
	CreativeItemCategory creativeCategory; // 44
	int filler; // 48
	void* colorFormat; // 52
	TextureUVCoordinateSet& icon; // 56
	int filler[9]; // 60
	std::unique_ptr<FoodItemComponent> _foodDetails; // 96
	std::unique_ptr<SeedItemComponent> _seedDetails; // 100
	std::unique_ptr<CameraItemComponent> _cameraDetails; // 104

	/* list */
	static Item* mItems[4096];
	static std::vector<ItemInstance> mCreativeList;

	/* vtable */
	virtual ~Item();
	virtual Item* setIcon(const std::string&, int);
	virtual Item* setIcon(const TextureUVCoordinateSet&);
	virtual void setMaxStackSize(unsigned char);
	virtual void setCategory(CreativeItemCategory);
	virtual void setStackedByData(bool);
	virtual void setMaxDamage(int);
	virtual void setHandEquipped();
	virtual void setUseAnimation(UseAnimation);
	virtual void setMaxUseDuration(int);
	virtual void setRequiresWorldBuilder(bool);
	virtual void setExplodable(bool);
	virtual void setIsGlint(bool);
	virtual void setShouldDespawn(bool);
	virtual BlockShape getBlockShape();
	virtual bool canBeDepleted();
	virtual bool canDestroySpecial(const Block*) const;
	virtual int getLevelDataForAuxValue(int) const;
	virtual bool isStackedByData() const;
	virtual int getMaxDamage();
	virtual int getAttackDamage();
	virtual bool isHandEquipped() const;
	virtual bool isArmor() const;
	virtual bool isDye() const;
	virtual bool isGlint(const ItemInstance*) const;
	virtual bool isThrowable() const;
	virtual bool canDestroyInCreative() const;
	virtual bool isLiquidClipItem(int) const;
	virtual bool requiresInteract() const;
	virtual const std::string& appendFormattedHovertext(const ItemInstance&, Level&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool isComplex() const;
	virtual bool isValidAuxValue(int) const;
	virtual int getDamageChance(int) const;
	virtual bool uniqueAuxValues() const;
	virtual int getColor(const ItemInstance&) const;
	virtual bool use(ItemInstance&, Player&);
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void interactEnemy(ItemInstance*, Mob*, Player*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual void readUserData(ItemInstance*, IDataInput&) const;
	virtual void writeUserData(const ItemInstance*, IDataOutput&) const;
	virtual int getMaxStackSize(const ItemInstance*);
	virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool);
	virtual void onCraftedBy(ItemInstance&, Level&, Player&);
	virtual int getCooldownType() const;
	virtual int getCooldownTime() const;
	virtual const std::string& getInteractText(const Player&) const;
	virtual int getAnimationFrameFor(Mob&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual bool isMirroredArt() const;

	/* member functions */
	void initClient(Json::Value&, Json::Value&);
	void initServer(Json::Value&);
	void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	void setIsMirroredArt(bool);

	/* static functions */
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static void addBlockItems();
	static void registerItems();
	static void teardownItems();
	static void initClientData();
	static void initServerData(ResourcePackManager&);
	static void addCreativeItem(Block const*, short);
	static void addCreativeItem(Item*, short);
	static void addCreativeItem(ItemInstance const&);
	static void addCreativeItem(short, short);
	static void initCreativeItems();
};
