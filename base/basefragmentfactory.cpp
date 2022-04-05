#include "basefragment.h"
#include "basefragmentfactory.h"

BaseFragmentFactory::BaseFragmentFactory() = default;

BaseFragmentFactory::~BaseFragmentFactory() = default;

BaseFragment* BaseFragmentFactory::create(SCREEN tag) {return nullptr;}

SCREEN BaseFragmentFactory::createStart() {return SPLASH;}
