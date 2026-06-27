#include "FoodItem.hpp"
#include "world/entity/Player.hpp"

FoodItem::FoodItem(int id, int nutrition) : Item(id), m_nutrition(nutrition)
{
	m_maxStackSize = 1;
}

bool FoodItem::use(ItemStack& inst, Level* level, Player* player) const
{
    if (player->m_health < player->getMaxHealth())
    {
        --inst.m_count;
        player->heal(m_nutrition);
        return true;
    }
    return false;
}