/**************************************************************

<<<<<<< HEAD
	resync_windows.h - Windows device change notifying helper

	---------------------------------------------------------

	Switchres	Modeline generation engine for emulation

	License     GPL-2.0+
	Copyright   2010-2020 Chris Kennedy, Antonio Giner,
	                     Alexandre Wodarczyk, Gil Delescluse
=======
    resync_windows.h - Windows device change notifying helper

    ---------------------------------------------------------

    Switchres   Modeline generation engine for emulation

    License     GPL-2.0+
    Copyright   2010-2020 Chris Kennedy, Antonio Giner,
                         Alexandre Wodarczyk, Gil Delescluse
>>>>>>> b2e5eb43538de049926f6ee679574b1af9ca2809

 **************************************************************/

#ifndef __RESYNC_WINDOWS__
#define __RESYNC_WINDOWS__

#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <windows.h>
#include <dbt.h>

class resync_handler
{
	public:
		resync_handler();
		~resync_handler();

		void wait();

	private:
		static LRESULT CALLBACK resync_wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		LRESULT CALLBACK my_wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		void handler_thread();

		HWND m_hwnd;
<<<<<<< HEAD
		std::thread	my_thread;
=======
		std::thread my_thread;
>>>>>>> b2e5eb43538de049926f6ee679574b1af9ca2809
		bool m_is_notified_1;
		bool m_is_notified_2;
		std::mutex m_mutex;
		std::condition_variable m_event;
};

#endif
