#pragma once

#include "Item.hpp"

class SnowballItem : public Item
{
public:
	SnowballItem(int);

public:
	bool use(ItemStack& inst, Level* level, Mob& mob) const override;
};
