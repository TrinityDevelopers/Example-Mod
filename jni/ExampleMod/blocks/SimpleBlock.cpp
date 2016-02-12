#include "SimpleBlock.h"

#include "mcpe/leveledit.h"

#include "../ExampleMod.h"

SimpleBlock::SimpleBlock(std::string asset, int id) : 
	Block("simpleBlock", id, asset, Material::getMaterial(MaterialType::DECORATION)) {
		
	//creativeCategory = 3;
	setDestroyTime(0.5F);
	setSoundType(SOUND_GRASS);
	
	ExampleMod::registerBlock(this);
}

int SimpleBlock::getResourceCount(Random& rand, int i1, int i2) {
	return 3;
}