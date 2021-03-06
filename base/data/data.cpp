#include <QWidget>
#include <QNetworkAccessManager>
#include "data.h"

const QString END_LINE = "\n";

/**
  * @brief User::User
  *
  * @author Polovin Alexei (alexeipolovin@gmail.com)
  *
  * Класс, который служит чтобы обработать приходящий запрос в json
  *
*/

User::User(): BaseModel() {

}

QString User::getPhotoName() {
    return this->photoName;
}

void User::printUserData() {
    qDebug() << "name" << this->name << END_LINE << "lastName" << this->lastName << END_LINE << "id" << this->id
             << END_LINE << "status" << this->status;
}

User::~User() = default;


/**
 * @brief Post::Post
 *
 * @author Polovin Alexei (alexeipolovin@gmail.com)
 *
 * Класс, который служит чтобы обработать приходящий запрос в json
 *
 */
Post::Post() {

}

void Post::printData() {
    qDebug() << "Title" << this->title << END_LINE << "Text" << this->text << END_LINE << "Date" << this->date
             << "Edited" << this->edited;
}

Post::~Post() = default;
