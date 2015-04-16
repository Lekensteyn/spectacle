/*
 *  Copyright (C) 2015 Boudhayan Gupta <me@BaloneyGeek.com>
 *
 *  Includes code from ksnapshot.cpp, part of KSnapshot. Copyright notices
 *  reproduced below:
 *
 *  Copyright (C) 1997-2008 Richard J. Moore <rich@kde.org>
 *  Copyright (C) 2000 Matthias Ettrich <ettrich@troll.no>
 *  Copyright (C) 2002 Aaron J. Seigo <aseigo@kde.org>
 *  Copyright (C) 2003 Nadeem Hasan <nhasan@kde.org>
 *  Copyright (C) 2004 Bernd Brandstetter <bbrand@freenet.de>
 *  Copyright (C) 2006 Urs Wolfer <uwolfer @ kde.org>
 *  Copyright (C) 2010 Martin Gräßlin <kde@martin-graesslin.com>
 *  Copyright (C) 2010, 2011 Pau Garcia i Quiles <pgquiles@elpauer.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301, USA.
 */

#include "ImageGrabber.h"

ImageGrabber::ImageGrabber(QObject *parent) :
    QObject(parent),
    mCapturePointer(false),
    mCaptureDecorations(true),
    mGrabMode(InvalidChoice),
    mPixmap(QPixmap())
{
}

ImageGrabber::~ImageGrabber()
{
}

// Q_PROPERTY Stuff

QPixmap ImageGrabber::pixmap() const
{
    return mPixmap;
}

bool ImageGrabber::capturePointer() const
{
    return mCapturePointer;
}

bool ImageGrabber::captureDecorations() const
{
    return mCaptureDecorations;
}

ImageGrabber::GrabMode ImageGrabber::grabMode() const
{
    return mGrabMode;
}

void ImageGrabber::setCapturePointer(const bool newCapturePointer)
{
    mCapturePointer = newCapturePointer;
}

void ImageGrabber::setCaptureDecorations(const bool newCaptureDecorations)
{
    mCaptureDecorations = newCaptureDecorations;
}

void ImageGrabber::setGrabMode(const GrabMode newGrabMode)
{
    mGrabMode = newGrabMode;
}

// Slots

void ImageGrabber::doImageGrab()
{
    switch(mGrabMode) {
    case InvalidChoice:
        emit imageGrabFailed();
        return;
    case FullScreen:
        return grabFullScreen();
    case CurrentScreen:
        return grabCurrentScreen();
    case ActiveWindow:
        return grabActiveWindow();
    case RectangularRegion:
        return grabRectangularRegion();
    }
}
