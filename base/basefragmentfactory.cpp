#include "basefragment.h"
#include "basefragmentfactory.h"

BaseFragmentFactory::BaseFragmentFactory() {

}

BaseFragmentFactory::~BaseFragmentFactory() {

}

BaseFragment* BaseFragmentFactory::create(SCREEN tag) {return nullptr;}

SCREEN BaseFragmentFactory::createStart() {return SPLASH;}
