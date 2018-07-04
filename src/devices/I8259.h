// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   src->devices->I8259.h
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
// *  (c) 2018 Luke Usher
// *
// *  Based on QEMU 8259 interrupt controller emulation
// *  (c) 2003-2004 Fabrice Bellard
// *
// *  All rights reserved
// *
// ******************************************************************

#ifndef _PIC_H_
#define _PIC_H_

#include <cstdint>

#define PORT_PIC_MASTER_COMMAND 0x20
#define PORT_PIC_MASTER_DATA 0x21
#define PORT_PIC_SLAVE_COMMAND 0xA0
#define PORT_PIC_SLAVE_DATA 0xA1
#define PORT_PIC_MASTER_ELCR 0x4D0
#define PORT_PIC_SLAVE_ELCR 0x4D1

#define PIC_MASTER	0
#define PIC_SLAVE	1

class Xbox;

class I8259 
{
	public:
		I8259(Xbox *pXbox);
		void Reset();

		uint32_t IORead(uint32_t addr);
		void IOWrite(uint32_t addr, uint32_t value);

		void RaiseIRQ(int index);
		void LowerIRQ(int index);

		int GetCurrentIRQ();
	private:
		Xbox *m_pXbox;

		uint8_t m_PreviousIRR[2];	// used for edge-detection
		uint8_t m_IRR[2];
		uint8_t m_IMR[2];	
		uint8_t m_ISR[2];
		uint8_t m_Base[2];
		uint8_t m_ReadRegisterSelect[2];
		uint8_t m_SpecialMask[2];
		uint8_t m_InitState[2];
		uint8_t m_ELCR[2];
		uint8_t m_ELCRMask[2];
		uint8_t m_PriorityAdd[2];

		bool m_Poll[2];
		bool m_RotateOnAutoEOI[2];
		bool m_Is4ByteInit[2];
		bool m_AutoEOI[2];
		bool m_IsSpecialFullyNestedMode[2];

		void AcknowledgeIRQ(int pic, int index);
		int GetIRQ(int pic);
		void SetIRQ(int pic, int index, bool value);
		int GetPriority(int pic, uint8_t mask);
		uint8_t Poll(int pic, uint32_t addr);
		void Reset(int pic);
		void UpdateIRQ();
};

#endif