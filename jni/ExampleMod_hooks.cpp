#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>

#include "Substrate.h"

#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/BlockItem.h"

Item* myItem;

void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	Item::addCreativeItem(myItem, 0);
}

void (*_Item$registerItems)();
void Item$registerItems() {
	myItem = new Item("superitem", 1500 - 256);
	Item::mItems[1500] = myItem;
	
	_Item$registerItems();
}

void (*_Item$initClientData)();
void Item$initClientData() {
	_Item$initClientData();
	
	myItem->setIcon("blaze_rod", 0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Item::registerItems, (void*) &Item$registerItems, (void**) &_Item$registerItems);
	MSHookFunction((void*) &Item::initClientData, (void*) &Item$initClientData, (void**) &_Item$initClientData);
	
	return JNI_VERSION_1_2;
}
