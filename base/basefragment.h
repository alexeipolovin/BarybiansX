#ifndef BASEFRAGMENT_H
#define BASEFRAGMENT_H

#include "basemodel.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QWidget>

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

    void navigateTo(QString tag);
    void navigateWhithData(QString tag, BaseModel* model);

    void newRootScreen(QString tag);
    void replace(QString tag);
    void replaceWhithData(QString tag, BaseModel* model);

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
};

#endif // BASEFRAGMENT_H
