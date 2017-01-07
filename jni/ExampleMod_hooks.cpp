#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>

#include "Substrate.h"

#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/ItemInstance.h"
#include "mcpe/world/item/BlockItem.h"
#include "mcpe/world/item/recipes/FurnaceRecipes.h"
#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/level/block/BlockGraphics.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/locale/Localization.h"

#define  LOG_TAG	"ExampleMod"

#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

Item* myItem;
Block* myBlock;

void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();
	
	myBlock = new Block("superblock", 220, Material::getMaterial(MaterialType::STONE));
	myBlock->setCategory(CreativeItemCategory::BLOCKS);
	Block::mBlocks[220] = myBlock;
	LOGD("blocks initiated");
}

void (*_BlockGraphics$initBlocks)();
void BlockGraphics$initBlocks() {
	_BlockGraphics$initBlocks();
	
	BlockGraphics::mBlocks[220] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[220]->setTextureItem("stone");
	LOGD("block graphics initiated");
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	Item::addCreativeItem(myItem, 0);
	Item::addCreativeItem(myBlock, 0);
	LOGD("items added to creative inv");
}

void (*_Item$registerItems)();
void Item$registerItems() {
	myItem = new Item("superitem", 1500 - 256);
	myItem->foil = true;
	Item::mItems[1500] = myItem;
	
	Item::mItems[220] = new BlockItem(myBlock->getDescriptionId(), 220 - 256);
	LOGD("items registered");
	
	_Item$registerItems();
}

void (*_Item$initClientData)();
void Item$initClientData() {
	_Item$initClientData();
	
	myItem->setIcon("blaze_rod", 0);
	LOGD("item icon registered");
}

void (*_FurnaceRecipes$_init)(FurnaceRecipes*);
void FurnaceRecipes$_init(FurnaceRecipes* recipes) {
	_FurnaceRecipes$_init(recipes);
	
	recipes->addFurnaceRecipe(220, ItemInstance(1500, 1, 0));
}

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization* self, const std::string& langCode)
{	
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE")
		_Localization$_load(self, "examplemod/" + langCode);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &BlockGraphics$initBlocks, (void**) &_BlockGraphics$initBlocks);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Item::registerItems, (void*) &Item$registerItems, (void**) &_Item$registerItems);
	MSHookFunction((void*) &Item::initClientData, (void*) &Item$initClientData, (void**) &_Item$initClientData);
	MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &FurnaceRecipes$_init, (void**) &_FurnaceRecipes$_init);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	
	return JNI_VERSION_1_2;
}
