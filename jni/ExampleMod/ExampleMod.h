#pragma once
class Block;

class ExampleMod {
public:
	static Block* simpleBlock;
	
	static void initBlocks();
	static void registerBlock(Block*);
	static int getNextBlockID();
	
	static void initCreativeItems();
};