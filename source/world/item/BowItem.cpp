#include "BowItem.hpp"
#include "world/entity/Player.hpp"
#include "world/level/Level.hpp"
#include "world/entity/Arrow.hpp"

BowItem::BowItem(int id) : Item(id)
{
	m_maxStackSize = 1;
}

bool BowItem::use(ItemStack& item, Level* level, Mob& mob) const
{
    if (!mob.isPlayer() || static_cast<Player&>(mob).isCreative() || static_cast<Player&>(mob).m_pInventory->removeResource(Item::arrow->m_itemID))
    {
        level->playSound(&mob, "random.bow", 1.0f, 1.0f / (level->m_random.nextFloat() * 0.4f + 0.8f));
        if (!level->m_bIsClientSide)
            level->addEntity(new Arrow(level, &mob));
    }

    return false;
}
