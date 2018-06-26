// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Hardware->X86->IX86CPU.h
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
// *  (c) 2018 Luke Usher <luke.usher@outlook.com>
// *  All rights reserved
// *
// ******************************************************************

#include <cstdint>

class Xbox;

// Registers
typedef enum {
	X86_REG_INVALID = 0,
	X86_REG_AH, X86_REG_AL, X86_REG_AX, X86_REG_BH, X86_REG_BL,
	X86_REG_BP, X86_REG_BPL, X86_REG_BX, X86_REG_CH, X86_REG_CL,
	X86_REG_CS, X86_REG_CX, X86_REG_DH, X86_REG_DI, X86_REG_DIL,
	X86_REG_DL, X86_REG_DS, X86_REG_DX, X86_REG_EAX, X86_REG_EBP,
	X86_REG_EBX, X86_REG_ECX, X86_REG_EDI, X86_REG_EDX, X86_REG_EFLAGS,
	X86_REG_EIP, X86_REG_EIZ, X86_REG_ES, X86_REG_ESI, X86_REG_ESP,
	X86_REG_FPSW, X86_REG_FS, X86_REG_GS, X86_REG_IP, X86_REG_RAX,
	X86_REG_RBP, X86_REG_RBX, X86_REG_RCX, X86_REG_RDI, X86_REG_RDX,
	X86_REG_RIP, X86_REG_RIZ, X86_REG_RSI, X86_REG_RSP, X86_REG_SI,
	X86_REG_SIL, X86_REG_SP, X86_REG_SPL, X86_REG_SS, X86_REG_CR0,
	X86_REG_CR1, X86_REG_CR2, X86_REG_CR3, X86_REG_CR4, X86_REG_CR5,
	X86_REG_CR6, X86_REG_CR7, X86_REG_CR8, X86_REG_CR9, X86_REG_CR10,
	X86_REG_CR11, X86_REG_CR12, X86_REG_CR13, X86_REG_CR14, X86_REG_CR15,
	X86_REG_DR0, X86_REG_DR1, X86_REG_DR2, X86_REG_DR3, X86_REG_DR4,
	X86_REG_DR5, X86_REG_DR6, X86_REG_DR7, X86_REG_DR8, X86_REG_DR9,
	X86_REG_DR10, X86_REG_DR11, X86_REG_DR12, X86_REG_DR13, X86_REG_DR14,
	X86_REG_DR15, X86_REG_FP0, X86_REG_FP1, X86_REG_FP2, X86_REG_FP3,
	X86_REG_FP4, X86_REG_FP5, X86_REG_FP6, X86_REG_FP7,
	X86_REG_K0, X86_REG_K1, X86_REG_K2, X86_REG_K3, X86_REG_K4,
	X86_REG_K5, X86_REG_K6, X86_REG_K7, X86_REG_MM0, X86_REG_MM1,
	X86_REG_MM2, X86_REG_MM3, X86_REG_MM4, X86_REG_MM5, X86_REG_MM6,
	X86_REG_MM7, X86_REG_R8, X86_REG_R9, X86_REG_R10, X86_REG_R11,
	X86_REG_R12, X86_REG_R13, X86_REG_R14, X86_REG_R15,
	X86_REG_ST0, X86_REG_ST1, X86_REG_ST2, X86_REG_ST3,
	X86_REG_ST4, X86_REG_ST5, X86_REG_ST6, X86_REG_ST7,
	X86_REG_XMM0, X86_REG_XMM1, X86_REG_XMM2, X86_REG_XMM3, X86_REG_XMM4,
	X86_REG_XMM5, X86_REG_XMM6, X86_REG_XMM7, X86_REG_XMM8, X86_REG_XMM9,
	X86_REG_XMM10, X86_REG_XMM11, X86_REG_XMM12, X86_REG_XMM13, X86_REG_XMM14,
	X86_REG_XMM15, X86_REG_XMM16, X86_REG_XMM17, X86_REG_XMM18, X86_REG_XMM19,
	X86_REG_XMM20, X86_REG_XMM21, X86_REG_XMM22, X86_REG_XMM23, X86_REG_XMM24,
	X86_REG_XMM25, X86_REG_XMM26, X86_REG_XMM27, X86_REG_XMM28, X86_REG_XMM29,
	X86_REG_XMM30, X86_REG_XMM31, X86_REG_YMM0, X86_REG_YMM1, X86_REG_YMM2,
	X86_REG_YMM3, X86_REG_YMM4, X86_REG_YMM5, X86_REG_YMM6, X86_REG_YMM7,
	X86_REG_YMM8, X86_REG_YMM9, X86_REG_YMM10, X86_REG_YMM11, X86_REG_YMM12,
	X86_REG_YMM13, X86_REG_YMM14, X86_REG_YMM15, X86_REG_YMM16, X86_REG_YMM17,
	X86_REG_YMM18, X86_REG_YMM19, X86_REG_YMM20, X86_REG_YMM21, X86_REG_YMM22,
	X86_REG_YMM23, X86_REG_YMM24, X86_REG_YMM25, X86_REG_YMM26, X86_REG_YMM27,
	X86_REG_YMM28, X86_REG_YMM29, X86_REG_YMM30, X86_REG_YMM31, X86_REG_ZMM0,
	X86_REG_ZMM1, X86_REG_ZMM2, X86_REG_ZMM3, X86_REG_ZMM4, X86_REG_ZMM5,
	X86_REG_ZMM6, X86_REG_ZMM7, X86_REG_ZMM8, X86_REG_ZMM9, X86_REG_ZMM10,
	X86_REG_ZMM11, X86_REG_ZMM12, X86_REG_ZMM13, X86_REG_ZMM14, X86_REG_ZMM15,
	X86_REG_ZMM16, X86_REG_ZMM17, X86_REG_ZMM18, X86_REG_ZMM19, X86_REG_ZMM20,
	X86_REG_ZMM21, X86_REG_ZMM22, X86_REG_ZMM23, X86_REG_ZMM24, X86_REG_ZMM25,
	X86_REG_ZMM26, X86_REG_ZMM27, X86_REG_ZMM28, X86_REG_ZMM29, X86_REG_ZMM30,
	X86_REG_ZMM31, X86_REG_R8B, X86_REG_R9B, X86_REG_R10B, X86_REG_R11B,
	X86_REG_R12B, X86_REG_R13B, X86_REG_R14B, X86_REG_R15B, X86_REG_R8D,
	X86_REG_R9D, X86_REG_R10D, X86_REG_R11D, X86_REG_R12D, X86_REG_R13D,
	X86_REG_R14D, X86_REG_R15D, X86_REG_R8W, X86_REG_R9W, X86_REG_R10W,
	X86_REG_R11W, X86_REG_R12W, X86_REG_R13W, X86_REG_R14W, X86_REG_R15W,
	X86_REG_IDTR, X86_REG_GDTR, X86_REG_LDTR, X86_REG_TR, X86_REG_FPCW,
	X86_REG_FPTAG,
	X86_REG_MSR,
	X86_REG_ENDING
} X86Reg;

// Memory-Management Register for instructions IDTR, GDTR, LDTR, TR.
// Borrow from SegmentCache in qemu/target-i386/cpu.h
typedef struct {
    uint16_t selector;  /* not used by GDTR and IDTR */
    uint64_t base;      /* handle 32 or 64 bit CPUs */
    uint32_t limit;
    uint32_t flags;     /* not used by GDTR and IDTR */
} X86Mmr;

// Model-Specific Register structure, use this with X86_REG_MSR (as the register ID)
typedef struct {
    uint32_t rid;   // MSR id
    uint64_t value; // MSR value
} X86Msr;

// List of supported execution modes for the current CPU backend
typedef struct {
	bool Step = false;
	bool ExecuteBlock = false;
	bool Execute = false;
} X86ExecutionModes;

class IX86CPU
{
public:
	// State Control
	virtual bool Init(Xbox xbox) = 0;
	virtual void Reset() = 0;
	virtual void Shutdown() = 0;

	// Register Get/Set
	virtual bool ReadRegister(const X86Reg reg, uint32_t& value) = 0;
	virtual bool WriteRegister(const X86Reg reg, const uint32_t value) = 0;
	 
	// Execution
	virtual X86ExecutionModes GetSupportedExecutionModes() = 0;
	virtual bool Step() = 0;					// Step for a single instruction (optional)
	virtual bool ExecuteBlock() = 0;			// Execute a single code block (usually, this means until a branch is hit)
	virtual bool Execute() = 0;					// Execute indefinitely (Until an interrupt is encountered)
	virtual bool Interrupt(uint8_t vector) = 0; // Trigger an interrupt

	// IO
	virtual bool IORead(const unsigned port, uint32_t& value, const size_t size) = 0;
	virtual bool IOWrite(const unsigned port, const uint32_t value, const size_t size) = 0;

	// Memory Access (Physical Address Space)
	virtual bool ReadPhysicalMemory(const uint32_t addr, uint32_t& value, const size_t size) = 0;
	virtual bool WritePhysicalMemory(const uint32_t addr, const uint32_t value, const size_t size) = 0;
	virtual void* GetPhysicalMemoryPtr(const uint32_t addr) = 0;

	// Memory Access (Virtual Address Space: Parses page tables)
	virtual bool GetPhysicicalAddress(const uint32_t virtaddr, uint32_t& physaddr) = 0; // Returns the Physical Address for a given virtual address
	virtual bool ReadVirtualMemory(const uint32_t addr, uint32_t& value, const size_t size) = 0;
	virtual bool WriteVirtualMemory(const uint32_t addr, const uint32_t value, const size_t size) = 0;
}; 