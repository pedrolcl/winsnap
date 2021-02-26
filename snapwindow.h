#ifndef SNAPWINDOW_H
#define SNAPWINDOW_H

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

#include <QMainWindow>

#if defined(Q_OS_WINDOWS)
#include "winsnap.h"
#endif

class SnapWindow : public QMainWindow
{
    Q_OBJECT
public:
    SnapWindow(QWidget *parent = nullptr);

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;

private:
#if defined(Q_OS_WINDOWS)
    WinSnap m_snapper;
#endif
};

#endif // SNAPWINDOW_H
