#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QFrame>
#include <QObject>
#include <QWidget>

/**
 * @brief The CardWidget class
 *
 * Кардвиджет - серый прямоугольник с тенью.
 *
 * (все уже по дизайну, берешь и используешь)
 */
class CardWidget : public QFrame {
    Q_OBJECT
public:
    explicit CardWidget(QWidget *parent = nullptr);


};

#endif // CARDWIDGET_H
