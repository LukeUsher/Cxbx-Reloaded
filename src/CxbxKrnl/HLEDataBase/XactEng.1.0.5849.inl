// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->XactEng.1.0.5849.inl
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2017 Luke Usher <luke.usher@outlook.com>
// *
// *  All rights reserved
// *
// ******************************************************************

// *****************************************************************
// * XACTEngineCreate
// ******************************************************************
OOVPA_NO_XREF(XACTEngineCreate, 5849, 11)
		// XACTEngineCreate+0x09 : movzx ebx, al
		{ 0x09, 0x0F },
		{ 0x0A, 0xB6 },
		{ 0x0B, 0xD8 },

        // XACTEngineCreate+0x2B : push edi
		{ 0x2B, 0x57 },

		// XACTEngineCreate+0x31 : push 0x168
		{ 0x31, 0x68 },
		{ 0x32, 0x68 },
		{ 0x33, 0x01 },
		{ 0x34, 0x00 },
		{ 0x35, 0x00 },

		// XACTEngineCreate+0xA2 : retn 0x8
		{ 0xA2, 0xC2 },
		{ 0xA3, 0x08 },
OOVPA_END;

// ******************************************************************
// * XACT::CEngine::CreateSoundSource
// ******************************************************************
// Created from $0030420C in "Kingdom Under Fire: The Crusaders"
OOVPA_XREF(XACT_CEngine_CreateSoundSource, 5849, 8,
		XREF_XACT_CEngine_CreateSoundSource,
		XRefZero)
		//XACT::CEngine::CreateSoundSource+0x09 : push eax
		{ 0x09, 0x50 },
		//XACT::CEngine::CreateSoundSource+0x0F : or eax, 20000000h
		{ 0x0F, 0x0D },
		{ 0x10, 0x00 },
		{ 0x11, 0x00 },
		{ 0x12, 0x00 },
		{ 0x13, 0x20 },
		//XACT::CEngine::CreateSoundSource+0x0F : mov [ecx], esi
		{ 0x30, 0x89 },
		{ 0x31, 0x31 }
OOVPA_END;

// ******************************************************************
// * XactEng_5849
// ******************************************************************
OOVPATable XactEng_5849[] = {
	REGISTER_OOVPA(XACTEngineCreate, 5849, PATCH),
	REGISTER_OOVPA(XACTEngineDoWork, 4627, PATCH),
	REGISTER_OOVPA(XACT_CEngine_CreateSoundSource, 5849, XREF)
};

// ******************************************************************
// * XACTENG_5849_SIZE
// ******************************************************************
uint32 XactEng_5849_SIZE = sizeof(XactEng_5849);
