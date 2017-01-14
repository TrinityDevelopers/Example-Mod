#pragma once

#include <string>

class Entity;
class BinaryStream;
class NetworkIdentifier;
class NetEventCallback;

class AddEntityPacket {
public:
	
	AddEntityPacket(Entity&);
	
	virtual ~AddEntityPacket();
	virtual int getId() const;
	virtual std::string getName() const;
	virtual void write(BinaryStream&) const;
	virtual void read(BinaryStream&);
	virtual void handle(const NetworkIdentifier&, NetEventCallback&) const;
	virtual void disallowBatching() const;
	
}