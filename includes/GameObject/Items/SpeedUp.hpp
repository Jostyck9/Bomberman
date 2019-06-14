#ifndef SPEEDUP_HPP
#define SPEEDUP_HPP

#include "AItem.hpp"

class SpeedUp : public AItem
{
public:
    SpeedUp(irr::IrrlichtDevice* device, irr::u16 pos_x, irr::u16 pos_y);
    ~SpeedUp() = default;
    bool applyEffect(ACharacter& player) override;
    GameObject::objecType_t getType() override;
};

#endif
