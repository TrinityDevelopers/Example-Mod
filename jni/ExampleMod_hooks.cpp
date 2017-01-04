#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>

#include "Substrate.h"

#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/BlockItem.h"


void (*_Item$initCreativeItems)();
void Item$initCreativeItems() {
	_Item$initCreativeItems();
}

void (*_Item$registerItems)();
void Item$registerItems() {
	_Item$registerItems();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Item::registerItems, (void*) &Item$registerItems, (void**) &_Item$registerItems);
	
	return JNI_VERSION_1_2;
}
