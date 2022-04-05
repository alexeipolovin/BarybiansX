#ifndef SPLASHFRAGMENT_H
#define SPLASHFRAGMENT_H

#include <base/basefragment.h>
#include <cwidgets/implfragmentfactory.h>



class SplashFragment: public BaseFragment {
    Q_OBJECT

public:
    SplashFragment();
    ~SplashFragment() override;
public slots:

    /**
     * @brief openStartScreen
     *
     * Переходим к меню после небольшой
     * задержки, чтобы юзверь успел увидеть
     * лого игры.
     */
    void openStartScreen();
};
#endif // SPLASHFRAGMENT_H
