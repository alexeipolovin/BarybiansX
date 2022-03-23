#ifndef BASEFRAGMENT_H
#define BASEFRAGMENT_H

#include "basemodel.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QWidget>
#include <base/data/constants.h>
#include <base/utils/webconnector.h>

/**
 * @brief The BaseFragment class
 *
 * Базовый фрагмент приложения.
 */
class BaseFragment: public QFrame {
    Q_OBJECT

signals:
    void back();
    void backWhithData(BaseModel* model);

    void navigateTo(SCREEN tag);
    void navigateWhithData(SCREEN tag, BaseModel* model);

    void newRootScreen(SCREEN tag);
    void replace(SCREEN tag);
    void replaceWhithData(SCREEN tag, BaseModel* model);

protected:
    void clearList(QLayout *list);
public:
    BaseFragment();
    ~BaseFragment();

    /**
     * @brief onPause
     *
     * Метод вызывается во время перехода экрана
     * в стэк.
     */
    virtual void onPause();

    /**
     * @brief onResume
     * Метод вызывается при возврашении к эерану
     * из стэка, при появлении на экран.
     */
    virtual void onResume();

    /**
     * @brief bindData
     *
     * Метод вызывается если на экран передаются
     * данные, с предыдущего экрана.
     *
     * @param model модель данных
     */
    virtual void bindData(BaseModel* model);
    void bindWebConnector(WebConnector *webConnector);
};

#endif // BASEFRAGMENT_H
