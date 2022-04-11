#ifndef CONSTANTS_H
#define CONSTANTS_H
const QString HEADER_OPEN = "<h1>";
const QString HEADER_CLOSE = "</h1>";
const QString CENTER_OPEN = "<center>";
const QString CENTER_CLOSE = "</center>";
const QString IMG_OPEN = "<img src = ";
const QString IMG_CLOSE = "</img>";
const QString PARAGRAPH_OPEN = "<p>";
const QString PARAGRAPH_CLOSE = "</p>";
const QString CURS_OPEN = "<i>";
const QString CURS_CLOSE = "</i>";
const QString BOLD_OPEN = "<b>";
const QString BOLD_CLOSE = "<b>";
const QString UNDERLINE_OPEN = "<hr>";
const QString UNDERLINE_CLOSE = "</hr>";
const QString TAG_OPEN = "<";
const QString TAG_CLOSE = ">";
const QString STRIKE_OPEN ="<s>";
const QString STRIKE_CLOSE = "</s>";

enum SCREEN {
    SPLASH,
    LOGIN,
    USER_PAGE,
    DIALOG_WITH,
    EDITOR_SPLASH,
    EDITOR_WINDOW
};

enum REQUEST_TYPE {
    AUTH,

};

#endif // CONSTANTS_H
