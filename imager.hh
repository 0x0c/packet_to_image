#ifndef CLICK_IMAGER_HH
#define CLICK_IMAGER_HH
#include <click/element.hh>
CLICK_DECLS

class Imager : public Element
{
public:
	Imager();
	~Imager();

	const char *class_name() const	{ return "Imager"; }
	const char *port_count() const	{ return PORTS_1_1; }
	const char *processing() const	{ return PUSH; }

	void push(int, Packet *);
};

CLICK_ENDDECLS
#endif
