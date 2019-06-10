#ifndef SPEEDUP_HPP
#define SPEEDUP_HPP

#include "AItem.hpp"

class SpeedUp : public AItem
{
public:
    SpeedUp(irr::IrrlichtDevice* device);
    ~SpeedUp() = default;
    bool applyEffect(ACharacter& player) override;
    GameObject::objecType_t getType() override;
};

#endif
