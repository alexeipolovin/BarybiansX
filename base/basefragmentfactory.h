#ifndef BASESCREENSFACTORY_H
#define BASESCREENSFACTORY_H

#include "basefragment.h"

#include <QString>
#include "data/constants.h"


/**
 * @brief The BaseScreensFactory class
 *
 * Абстрактная фабрика экранов.
 */
class BaseFragmentFactory {
public:
    BaseFragmentFactory();
    ~BaseFragmentFactory();

    /**
     * @brief create
     * @param tag идентификатор экрана.
     *
     * Создание экрана по его
     * идентификатору для навигатора.
     * (фабрика инициализируетя при создании навигатора)
     *
     * @return BaseFragmnt.
     */
    virtual BaseFragment* create(SCREEN tag);

    /**
     * @brief createStart
     *
     * Создание стартового окна прпиложения
     * для навигатора.
     *
     * @return стартовое окно приложения.
     */
    virtual SCREEN createStart();

    //MainWindow *window;
};

#endif // BASESCREENSFACTORY_H
