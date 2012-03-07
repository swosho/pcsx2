/*
 *	Copyright (C) 2007-2009 Gabest
 *	http://www.gabest.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#pragma once

#include "GSDialog.h"
#include "GSSetting.h"

class GSShadeBostDlg : public GSDialog
{
	int saturation;
	int brightness;
	int contrast;

	void UpdateControls();

protected:
	void OnInit();
	bool OnMessage(UINT message, WPARAM wParam, LPARAM lParam);	

public:
	GSShadeBostDlg();
};

class GSHacksDlg : public GSDialog
{
	unsigned short cb2msaa[17];
	unsigned short msaa2cb[17];
	
	bool isdx9;

    enum
    {
        HK_MSAA,
        HK_SKIPDRAW,
        HK_ALPHA,
        HK_OFFSET,
        HK_SPRITE,
        HK_WILD,
        HK_SIZE
    };

    struct
    {
        bool isHovered;
        char description[1024];
    } Hack[HK_SIZE];

	void UpdateControls();
    void SetNotHover(int i);

protected:
	void OnInit();
	bool OnMessage(UINT message, WPARAM wParam, LPARAM lParam);

public:
	GSHacksDlg();
};

class GSSettingsDlg : public GSDialog
{
	list<D3DDISPLAYMODE> m_modes;
	bool m_IsOpen2;

	void UpdateControls();

protected:
	void OnInit();
	bool OnCommand(HWND hWnd, UINT id, UINT code);

	uint32 m_lastValidMsaa; // used to revert to previous dialog value if the user changed to invalid one, or lesser one and canceled

	// Shade Boost
	GSShadeBostDlg ShadeBoostDlg;
	GSHacksDlg HacksDlg;

public:
	GSSettingsDlg(bool isOpen2);
};
