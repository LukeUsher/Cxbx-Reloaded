#include "Xbox.h"
#include "I8254.h"
#include <chrono>

I8254::I8254(Xbox *pXbox)
{
	m_pXbox = pXbox;
}

void I8254::Reset()
{
	m_Active = false;
}

uint32_t I8254::IORead(uint32_t addr)
{
	return 0;
}

void I8254::IOWrite(uint32_t addr, uint32_t value)
{
	// HACK: The xbox always inits the PIT to the same value
	// Timer 0, Mode 2, 1ms interrupt interval
	// Rather than fully implement the PIC, we just wait for the command
	// to start operating, and then simply issue IRQ 0 in a timer thread
	if (value == 0x34) {
		m_Active = true;
		m_TimerThread = std::thread(TimerThread, this);
	}
}

void I8254::TimerThread(I8254* pPIT)
{
	auto nextInterruptTime = pPIT->GetNextInterruptTime();

	while (pPIT->m_Active && pPIT->m_pXbox->GetPIC() != nullptr) {
		if (std::chrono::steady_clock::now() > nextInterruptTime) {
			pPIT->m_pXbox->GetPIC()->RaiseIRQ(0);
			Sleep(1000);
			pPIT->m_pXbox->GetPIC()->LowerIRQ(0);
			nextInterruptTime = pPIT->GetNextInterruptTime();
		}
	}

	pPIT->m_Active = false;
}

std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double, std::nano>> I8254::GetNextInterruptTime()
{
	using namespace std::literals::chrono_literals;
	return std::chrono::steady_clock::now() + 1ms;
}