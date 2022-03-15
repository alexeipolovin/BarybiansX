#include "cardview.h"

CardView::CardView() : QFrame(this)
{
    this->setStyleSheet(
        "background-color:#343434;"
        "border:none;"
        "padding:0px;"
    );
}
