#include "gambatte.h"
#include "gambatte-c.h"
#include <cstdio>

extern "C" {

gambatte_c* gambatte_init() {
	return new gambatte_c;
}

void gambatte_destroy(gambatte_c* gb) {
	delete gb;
}

int gambatte_load(gambatte_c* gb, const char* romfile) {
	gambatte::LoadRes res = gb->load(std::string(romfile));
	return res;
}

ptrdiff_t gambatte_run(gambatte_c* gb, void* video, ptrdiff_t pitch, void* audio, size_t *samples) {
	return gb->runFor((gambatte::uint_least32_t*) video, pitch, (gambatte::uint_least32_t*) audio, *samples);
}

unsigned gambatte_get_input(gambatte_c* gb) {
	return gb->getInput();
}

void gambatte_set_input(gambatte_c* gb, unsigned input) {
	gb->setInput(input);
}

bool gambatte_save_state(gambatte_c *gb, int n) {
	gb->selectState(n);
	return gb->saveState(NULL, 0);
}

bool gambatte_load_state(gambatte_c *gb, int n) {
	gb->selectState(n);
	return gb->loadState();
}

}
