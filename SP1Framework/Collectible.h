#pragma once
class Collectible
{
private:
	bool isCollected;
	int CollectibleCount = 0;

public:
	Collectible();
	~Collectible();
	void PlayerCollect();
};

