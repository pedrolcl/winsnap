/*
 *  Sticky Window Snapping Demo for Qt and WIN32
 *  Copyright (C) 2021 Pedro López-Cabanillas <plcl@users.sourceforge.net>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <QDebug>
#include <QAction>
#include <QMenuBar>
#include <QTextBrowser>

#if defined(Q_OS_WINDOWS)
#include "winsnap.h"
#endif

#include "snapwindow.h"

SnapWindow::SnapWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 200);
    QAction *actionSnap = new QAction("Snapping", this);
    actionSnap->setCheckable(true);
    actionSnap->setChecked(true);
    connect(actionSnap, &QAction::toggled, this, [=](bool checked){ m_snapper.SetEnabled(checked); });
    menuBar()->addMenu("Effect")->addAction(actionSnap);
    QTextBrowser *browser = new QTextBrowser(this);
    browser->setHtml("<html><body>"
    "<h1>Sticky Window Snapping Demo</h1>"
    "<p>Please drag this window around your monitors.</p>"
    "<p>It will snap its borders to the desktop edges and to the edges of other windows"
    " when moved or resized at a distance of 30 pixels or less.</p>"
    "<p>To temporarily move or resize the window without snapping, pulse a SHIFT key at the same time.</p>"
    "<p>To disable the snapping behavior, use the menu option Effect->Snapping.</p>"
    "</body></html>");
    setCentralWidget(browser);
}

bool SnapWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
#if defined(Q_OS_WINDOWS)
    if (m_snapper.HandleMessage(message)) {
        result = 0;
        return true;
    }
#endif
    return QWidget::nativeEvent(eventType, message, result);
}
