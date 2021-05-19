//
// Created by Charlie Sewell on 13/05/2021.
//

#include "CollisionEventHandler.hpp"
#include <map>
void CollisionEventHandler::onContact(const CollisionCallback::CallbackData &callbackData) {
    collisions.clear();
    for (std::size_t p = 0; p < callbackData.getNbContactPairs(); ++p) {
        collisions.push_back(std::pair<int,int>(callbackData.getContactPair(p).getBody1()->getEntity().id,callbackData.getContactPair(p).getBody2()->getEntity().id));
    }
}
