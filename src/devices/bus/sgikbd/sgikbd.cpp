// license:BSD-3-Clause
// copyright-holders:Ryan Holtz

#include "emu.h"
#include "sgikbd.h"


DEFINE_DEVICE_TYPE(SGIKBD_PORT, sgi_keyboard_port_device, "sgikbd", "SGI Keyboard Port")


sgi_keyboard_port_device::sgi_keyboard_port_device(machine_config const &mconfig, char const *tag, device_t *owner, uint32_t clock)
	: sgi_keyboard_port_device(mconfig, SGIKBD_PORT, tag, owner, clock)
{
}

sgi_keyboard_port_device::sgi_keyboard_port_device(machine_config const &mconfig, device_type type, char const *tag, device_t *owner, uint32_t clock)
	: device_t(mconfig, type, tag, owner, clock)
	, device_single_card_slot_interface<device_sgi_keyboard_port_interface>(mconfig, *this)
	, m_rxd(0)
	, m_rxd_handler(*this)
	, m_dev(nullptr)
{
}

sgi_keyboard_port_device::~sgi_keyboard_port_device()
{
}

void sgi_keyboard_port_device::device_config_complete()
{
	m_dev = get_card_device();
}

void sgi_keyboard_port_device::device_resolve_objects()
{
	m_rxd_handler.resolve_safe();
}

void sgi_keyboard_port_device::device_start()
{
	save_item(NAME(m_rxd));

	m_rxd = 1;
	m_rxd_handler(m_rxd);
}

WRITE_LINE_MEMBER(sgi_keyboard_port_device::write_txd)
{
	if (m_dev)
		m_dev->input_txd(state);
}

device_sgi_keyboard_port_interface::device_sgi_keyboard_port_interface(machine_config const &mconfig, device_t &device)
	: device_interface(device, "sgikbd")
	, m_port(dynamic_cast<sgi_keyboard_port_device *>(device.owner()))
{
}

device_sgi_keyboard_port_interface::~device_sgi_keyboard_port_interface()
{
}


#include "hlekbd.h"

void default_sgi_keyboard_devices(device_slot_interface &device)
{
	device.option_add("hlekbd",   SGI_HLE_KEYBOARD);
}
