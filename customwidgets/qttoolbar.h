/**
* @file  qttoolbar.h
* @brief Header implementing a class for an advanced toolbar.
*
*
* @section License
*
* Copyright (C) 2013 Robert B. Colton
* This file is a part of the LateralGM IDE.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
**/

#ifndef QTTOOLBAR_H
#define QTTOOLBAR_H

#include <QToolBar>

class QtToolBar : public QToolBar
{
    Q_OBJECT
    
public:
    explicit QtToolBar(QWidget *parent = 0);
    ~QtToolBar();

    void addActionSized(QAction *action);
    void setActionWidgetSize(QSize size);
    void setDefaultActionSize(QSize size);
private:
    QSize defActionSize;
};

#endif // QTTOOLBAR_H
