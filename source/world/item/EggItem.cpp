#include "EggItem.hpp"

#include "world/level/Level.hpp"
#include "world/entity/ThrownEgg.hpp"


EggItem::EggItem(int itemID) : Item(itemID)
{
	m_maxStackSize = 16;
}

bool EggItem::use(ItemStack& inst, Level* level, Mob& mob) const 
{
	--inst.m_count;
	level->playSound(&mob, "random.bow", 0.5f, 0.4f / (level->m_random.nextFloat() * 0.4f + 0.8f));
	if (!level->m_bIsClientSide)
		level->addEntity(new ThrownEgg(level, &mob));
	return true;
}
