//
// Created by Charlie Sewell on 13/05/2021.
//

#include "YourEventListener.hpp"
void YourEventListener::onContact(const CollisionCallback::CallbackData &callbackData) {
   for(size_t i = 0; i < callbackData.getNbContactPairs();++i)
   {
        std::cout << callbackData.getContactPair(i).getBody1()->getEntity().id << " " << callbackData.getContactPair(i).getBody2()->getEntity().id << std::endl;
   }
}