/*
 * Copyright 2016-2017 Kacper Kasper <kacperkasper@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#ifndef FINDWINDOW_H
#define FINDWINDOW_H


#include <string>

#include <String.h>
#include <Window.h>


class BBox;
class BButton;
class BCheckBox;
class BMessage;
class BRadioButton;
class BStringView;
class BScintillaView;


enum {
	FINDWINDOW_FIND			= 'fwfd',
	FINDWINDOW_REPLACE		= 'fwrp',
	FINDWINDOW_REPLACEFIND	= 'fwrf',
	FINDWINDOW_REPLACEALL	= 'fwra',
	FINDWINDOW_QUITTING		= 'FWQU'
};


class FindWindow : public BWindow {
public:
					FindWindow(BMessage *state);
					~FindWindow();

	void			MessageReceived(BMessage* message);
	void			WindowActivated(bool active);
	void			Quit();

	void			SetFindText(const std::string text);

private:
	enum Actions {
		MATCH_CASE		= 'mtcs',
		MATCH_WORD		= 'mtwd',
		WRAP_AROUND		= 'wrar',
		BACKWARDS		= 'back',
		IN_SELECTION	= 'insl',
		REGEX			= 'rege'
	};
	void			_InitInterface();

	BStringView*	fFindString;
	BScintillaView*	fFindTC;
	BStringView*	fReplaceString;
	BScintillaView*	fReplaceTC;

	BButton*		fFindButton;
	BButton*		fReplaceButton;
	BButton*		fReplaceFindButton;
	BButton*		fReplaceAllButton;

	BCheckBox*		fMatchCaseCB;
	BCheckBox*		fMatchWordCB;
	BCheckBox*		fWrapAroundCB;
	BCheckBox*		fBackwardsCB;
	BCheckBox*		fInSelectionCB;
	BCheckBox*		fRegexCB;

	bool			fFlagsChanged;
	std::string		fOldFindText;
	std::string		fOldReplaceText;
};


#endif // FINDWINDOW_H
