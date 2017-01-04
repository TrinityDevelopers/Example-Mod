#pragma once

#include "Item.h"
#include "ItemInstance.h"

enum class ArmorSlot : int {
	HELMET,
	CHESTPLATE,
	LEGGINGS,
	BOOTS
};

class ArmorItem : public Item {
public:
	class ArmorMaterial {
	public:
		int maxDamageFactor; // 0
		int damageReductionAmountArray[4]; // 4
		int enchantability;	// 20

		ArmorMaterial(int, int, int, int, int, int);
		int getDefenseForSlot(ArmorSlot);
		int getEnchantValue();
		int getHealthForSlot(ArmorSlot);
	};

	static ArmorMaterial CHAIN;
	static ArmorMaterial CLOTH;
	static ArmorMaterial DIAMOND;
	static ArmorMaterial GOLD;
	static ArmorMaterial IRON;
	static ArmorMaterial ELYTRA;
	static int mHealthPerSlot[5];

	ArmorSlot armorType;			// 108
	int defence;					// 112
	int renderIndex;				// 116
	ArmorMaterial& armorMaterial;	// 120

	ArmorItem(const std::string&, int, const ArmorMaterial&, int, ArmorSlot);
	virtual ~ArmorItem();
	virtual bool isArmor() const;
	virtual const std::string& appendFormattedHovertext(const ItemInstance&, Level&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual int getDamageChance(int) const;
	virtual int getColor(const ItemInstance&) const;
	virtual bool use(ItemInstance&, Player&);
    virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	bool isElytra() const;
	bool hasCustomColor(const ItemInstance&) const;
	bool isDamageable(const ItemInstance&);
	bool isFlyEnabled(const ItemInstance&);
	void clearColor(ItemInstance&);
	ItemInstance getTierItem();
	
	void clearColor(ItemInstance&);
	static bool isElytraBroken(int);
	static bool isElytra(const ItemInstance&);
};
