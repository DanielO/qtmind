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

#ifndef BOARD_H
#define BOARD_H

#include "constants.h"
#include <QGraphicsView>

class Peg;
class EmptyBox;
class PinBox;
class PegBox;
class Button;
class Game;
class Message;

class Board: public QGraphicsView
{
	Q_OBJECT

public:
	explicit Board(QWidget* parent = 0);
	~Board();
	void handleButtonRelease(const QString &);
	void generate();
	void play(const GameMode &mode);
	void setPinsRow(const bool &set_pins, const bool &closeRow);
	void reset(const int& peg_n, const int& color_n, const GameMode &mode_n,
			   const bool &samecolor, const Algorithm &algorithm_n, const bool &set_pins,
			   const bool &close_row, const IndicatorType& indicator_n = IndicatorType::None);
	GameState getState() const {return mState;}
	void setAlgorithm(const Algorithm& algorithm_n);


protected:
	void drawBackground(QPainter* painter, const QRectF& rect);
	void resizeEvent(QResizeEvent* event);
	void setIndicatorType(const IndicatorType& indicator_n);

signals:
	void changePegIndicator(const IndicatorType &indicator_t);

private slots:
	void onPegMouseRelease(QPoint position, int color);
	void onOkButtonPressed();
	void onDoneButtonPressed();
	void onPinBoxPressed();
	void onChangeIndicators(const IndicatorType &indicator_n);
	void onThowInTheTowel();
//	void onDoItForMe();

private:
	void playCodeMaster();
	void playCodeBreaker();
	void createBoxes();
	void createPegForBox(PegBox* box, int color, bool backPeg = false);// backPeg should only be used to put an extra peg under initial pegs,
	void codeRowFilled(bool filled);
	void setBoxStateOfList(QList<PegBox*> boxlist, const BoxState state_t);
	void setBoxStateOfList(QList<PinBox*> boxlist, const BoxState state_t);


	QList<PinBox*> mPinBoxes;
	QList<PegBox*> mPegBoxes;
	QList<PegBox*> mCodeBoxes;
	QList<PegBox*> mCurrentBoxes;	//	boxes that can be filled by player
	QList<PegBox*> mMasterBoxes;

	GameState mState;
	GameMode mMode;
	int mPegNumber;
	int mColorNumber;
	bool mSameColor;
	bool mSetPins;
	bool mCloseRow;
	bool mDone;
	Algorithm mAlgorithm;
	IndicatorType mIndicator;
	Game* mGame;
	Button* mOkButton;
	Button* mDoneButton;
	Message* mMessage;
	Message* mInformation;
	QString mMasterCode;
	QString mGuess;
};

#endif // BOARD_H
