#pragma once

#include "Item.hpp"

class FoodItem : public Item
{
public:
	FoodItem(int id, int nutrition);
	
	bool use(ItemStack&, Level*, Mob& mob) const override;

protected:
	int m_nutrition;
};