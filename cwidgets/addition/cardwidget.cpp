#include "cardwidget.h"

#include <QGraphicsDropShadowEffect>

CardWidget::CardWidget(QWidget *parent) : QFrame(parent) {
    // новый цвет

    this->setStyleSheet(
        "background-color:#343434;"
        "border:none;"
        "padding:0px;"
    );

    // Добавление тени
    //QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    //effect->setXOffset(4);
    //effect->setYOffset(4);
    //effect->setBlurRadius(20);
    //effect->setColor(QColor(0, 0, 0, 60));
    //this->setGraphicsEffect(effect);
}
