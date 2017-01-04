#pragma once
#include <stdint.h>

typedef uint8_t DataID;
typedef uint8_t FacingID;

class BlockProperty;

class BlockID {
public:
	static BlockID AIR;

	unsigned char id;	// 0

	BlockID() : id(0) {}
	BlockID(unsigned char id) : id(id) {}
	BlockID(const BlockID &other) {id = other.id;}
	bool hasProperty(BlockProperty) const;
};

class FullBlock {
public:
	static FullBlock AIR;

	BlockID id;
	unsigned char aux;

	FullBlock() : id(0), aux(0) {};
	FullBlock(BlockID tileId, unsigned char aux_) : id(tileId), aux(aux_) {}
};