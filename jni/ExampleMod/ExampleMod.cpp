#include "ExampleMod.h"

#include "mcpe/world/level/block/Block.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/BlockItem.h"

#include "blocks/SimpleBlock.h"

Block* ExampleMod::simpleBlock;

void ExampleMod::initBlocks() {
	simpleBlock = new SimpleBlock("stone", 210);
}

void ExampleMod::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<Block>(block));
	Item::mItems[block->blockId] = new BlockItem(block->getDescriptionId(), block->blockId - 0x100);
}

int ExampleMod::getNextBlockID() {
	for(int id = 0; id < 256; id++) {
		if(Block::mBlocks[id] == NULL) {
			return id;
		}
	}
	return 255;
}

void ExampleMod::initCreativeItems() {
	Item::addCreativeItem(simpleBlock, 0);
}