#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>

#include "Substrate.h"

#include "mcpe/world/item/Item.h"
#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/recipes/Recipes.h"

void (*_Block$initBlocks)();
void Block$initBlocks() {
	_Block$initBlocks();
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();
}

static std::string (*_I18n$get)(const std::string&);
static std::string I18n$get(const std::string& key) {
	return _I18n$get(key);
};

void (*_Recipes$init)(Recipes*);
void Recipes$init(Recipes* self) {
	_Recipes$init(self);
}

Block* (*_Block$Block)(Block*, const std::string&, int, const std::string&, const Material&);
Block* Block$Block(Block* block, const std::string& name, int id, const std::string& tex, const Material& material) {
	Block* retval = _Block$Block3(block, name, id, tex, material);
	if(tex == "missing_tile")
		Block::mBlocks[id] = NULL;
	
	return retval;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
	
	void* I18n_get = dlsym(RTLD_DEFAULT, "_ZN4I18n3getERKSs");
	MSHookFunction(I18n_get, (void*) &I18n$get, (void**) &_I18n$get);
	
	void* BlockConstructor = dlsym(RTLD_DEFAULT, "_ZN5BlockC2ERKSsiS1_RK8Material");
	MSHookFunction(BlockConstructor, (void*) &Block$Block, (void**) &_Block$Block);
	return JNI_VERSION_1_2;
}
