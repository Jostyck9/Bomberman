#ifndef WALLPASS_HPP
#define WALLPASS_HPP

#include "AItem.hpp"

class WallPass : public AItem
{
public:
    WallPass(irr::IrrlichtDevice* device);
    ~WallPass() = default;
    bool applyEffect(ACharacter& player) override;
    GameObject::objecType_t getType() override;
};

#endif
