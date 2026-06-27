#include "EggItem.hpp"

#include "world/level/Level.hpp"
#include "world/entity/ThrownEgg.hpp"


EggItem::EggItem(int itemID) : Item(itemID)
{
	m_maxStackSize = 16;
}

bool EggItem::use(ItemStack& inst, Level* level, Player* user) const 
{
	--inst.m_count;
	level->playSound(user, "random.bow", 0.5f, 0.4F / (level->m_random.nextFloat() * 0.4F + 0.8F));
	if (!level->m_bIsClientSide)
		level->addEntity(new ThrownEgg(level, user));
	return true;
}
