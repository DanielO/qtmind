/***********************************************************************
 *
 * Copyright (C) 2013 Omid Nikta <omidnikta@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#include "boardsounds.h"
#include "QSettings"

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtMultimedia/QSoundEffect>
#endif

BoardSounds::BoardSounds()
{
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
	pegDropSound = new QSoundEffect;
	pegDropRefuseSound = new QSoundEffect;
	buttonPressSound = new QSoundEffect;
	pegDropSound->setSource(QUrl::fromLocalFile("://sounds/resources/sounds/pegdrop.wav"));
	pegDropRefuseSound->setSource(QUrl::fromLocalFile("://sounds/resources/sounds/pegrefuse.wav"));
	buttonPressSound->setSource(QUrl::fromLocalFile("://sounds/resources/sounds/pin.wav"));
#endif
	setVolume(static_cast<Volume>(QSettings().value("Volume", 3).toInt()));
}

BoardSounds::~BoardSounds()
{
	QSettings().setValue("Volume", static_cast<int>(volume));
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
	delete pegDropSound;
	delete pegDropRefuseSound;
	delete buttonPressSound;
#endif
}

void BoardSounds::playPegDropSound()
{
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
	pegDropSound->play();
#endif
}

void BoardSounds::playPegDropRefuseSound()
{
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
	pegDropRefuseSound->play();
#endif
}

void BoardSounds::playButtonPressSound()
{
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
	buttonPressSound->play();
#endif
}

void BoardSounds::setVolume(const int &vol)
{
	volume = static_cast<Volume>(vol);

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
	qreal real_volume = static_cast<qreal>(volume)/3;

	pegDropSound->setVolume(real_volume);
	pegDropRefuseSound->setVolume(real_volume);
	buttonPressSound->setVolume(real_volume);
#endif
}
