#ifndef ROUTER_H
#define ROUTER_H




#include "basefragmentfactory.h"

#include <QStackedWidget>

#include <cwidgets/slidingstackedwidget.h>
#include <base/utils/webconnector.h>


/**
 * @brief The Navigator class
 *
 * Навигация в риложении и логика замены экранов.
 *
 * <p>Экраны лежат в списке и мы можем выполнить
 * переход дальше по цепочке, заменить текущий экран
 * или перейти назад по цепочке.</p>
 */
class Router: public QObject {
    Q_OBJECT
private:
    SlidingStackedWidget *currentContainer;
    BaseFragmentFactory *screensFactory;
    QList<BaseFragment*> stack;

    /**
     * @brief createAndConnect
     * @param tag тэг создаваемого фрагмента.
     *
     * Создание фрагмента по тегу и его
     * прикрепление к навигатору.
     *
     * @return фрагмент приконекченный к слотам навигатора.
     */
    BaseFragment* createAndConnect(SCREEN tag);

    /**
     * @brief connectFragment
     * @param fragment фрагмент который переходит
     *        в активное состояние.
     *
     * Прикрепление текущего фрагмента
     * к слотам навигатора для быстрого
     * и удобного перехода между экранами.
     *
     */
    void connectFragment(BaseFragment *fragment) const;

    /**
     * @brief disconnectFragment
     * @param fragment
     *
     * Отключение сигналов от фрагмента.
     */
    void disconnectFragment(BaseFragment *fragment) const;
public:
    Router(
            SlidingStackedWidget *container,
            BaseFragmentFactory *screensFactory
    );
    ~Router();
    BaseFragment* getStartScreen();

public slots:
    /**
     * @brief navigateTo
     * @param tag имя следующего экрана.
     *
     * Переход к следующему экрану.
     */
    void navigateTo(SCREEN tag);

    /**
     * @brief back
     *
     * Переход назад по цепочке.
     */
    void back();

    /**
     * @brief replace
     * @param tag имя экрана на который
     *        произойдет замена.
     *
     * Замена текущего экрана с сохранением
     * предыдущей цепочки.
     */
    void replace(SCREEN tag);

    /**
     * @brief newRootScreen
     * @param tag имя экрана на который
     *        произойдет замена.
     *
     * Замена текущего экрана на новый и сброс
     * всей цепочки экранов.
     */
    void newRootScreen(SCREEN tag);

    /**
     * @brief backWhithData
     * @param model
     *
     * Тот же бэк но с данными.
     */
    void backWhithData(BaseModel* model);

    /**
     * @brief navigateWhithData
     * @param model
     *
     * Тот же navigateTo но с данными.
     */
    void navigateWhithData(SCREEN tag, BaseModel* model);


    /**
     * @brief removeOnFinishLast
     *
     * Удаление последнего элемента после анимации.
     */
    void removeOnFinishLast();

    /**
     * @brief removeOnReplace
     *
     * Удаление после замены текущего экрана
     */
    void removeOnReplace();

    /**
     * @brief removeOnReplace
     *
     * Удаление после создания новой цепочки
     */
    void removeOnRoot();

    /**
     * @brief navigateWhithData
     * @param model
     *
     * Тот же replace но с данными.
     */
    void replaceWhithData(SCREEN tag, BaseModel* model);
    void replaceWithDataAndWebConnector(SCREEN tag, BaseModel *model, WebConnector *webConnector);
};

#endif // ROUTER_H
