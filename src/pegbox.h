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

#ifndef PEGBOX_H
#define PEGBOX_H

#include "emptybox.h"
#include "peg.h"
#include <QGraphicsItem>

class QGraphicsEllipseItem;
class PegBox : public EmptyBox
{
public:
	explicit PegBox(const QPoint &position, QGraphicsItem *parent = 0);
	bool hasPeg() const {return mPeg != 0;}
	void setPeg(Peg *peg) {mPeg = peg;}
	void setPegState(const PegState &state);
	void setPegColor(const int &color_number);
	int getPegColor() const;
	void setBoxState(const BoxState &state);
	bool isPegVisible();
	PegState getPegState() const;

private:
	Peg *mPeg;
};

#endif // PEGBOX_H
